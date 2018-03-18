//////////////////////////////////////////////////////////////////////////
/// @brief    ����API
///           ʵ�ֲ�ͬ��ʽ�Ķ��ĺ�ȡ�����ļ����ղ�ѯ
//////////////////////////////////////////////////////////////////////////
#include "GTAQTSInterfaceBase.h"
#include "CallBackBase.h"
#include <stdio.h>
#include <boost/property_tree/json_parser.hpp>
#include "../Common/IoService.h"
#include "../Common/TinyThread.h"
#ifdef _WIN32
#include <windows.h>
#define  SLEEP(t)  Sleep((t)*1000)
#else
#include <unistd.h>
#define  SLEEP(t)  sleep(t)
#endif

#include <sys/time.h>

#include "../VecStockCode/VectorStockCodeSH.h"
#include "../VecStockCode/VectorStockCodeSZ.h"

#include "mktdata.pb.h"

#include "../GTA2TDF/GTA2TDF.h"

#include "MessageQueue.h"

int iPreCnt=0,iCurCnt=0;
struct timeval tvPre,tvCur;

void TDF_MARKET_DATA2MktData(MktData &output, const TDF_MARKET_DATA &src) {
	output.set_szcode(strtoul(src.szCode,nullptr,10));	//600001.SH 
	output.set_ntime(src.nTime);			//ʱ��(HHMMSSmmm)
	output.set_nstatus(src.nStatus);		//״̬
	output.set_npreclose(uint32_t(src.nPreClose));	//ǰ���̼�
	output.set_nopen(uint32_t(src.nOpen));			//���̼�
	output.set_nhigh(uint32_t(src.nHigh));			//��߼�
	output.set_nlow(uint32_t(src.nLow));				//��ͼ�
	output.set_nmatch(uint32_t(src.nMatch));			//���¼�
	for (unsigned char i = 0; i < 10; ++i) {
		output.add_naskprice(uint32_t(src.nAskPrice[i]));//������
		output.add_naskvol(src.nAskVol[i]);	//������
		output.add_nbidprice(uint32_t(src.nBidPrice[i]));//�����
		output.add_nbidvol(src.nBidVol[i]);	//������
	}
	output.set_nnumtrades(src.nNumTrades);	//�ɽ�����
	output.set_ivolume(src.iVolume);		//�ɽ�����
	output.set_iturnover(src.iTurnover);	//�ɽ��ܽ��
	output.set_ntotalbidvol(src.nTotalBidVol);//ί����������
	output.set_ntotalaskvol(src.nTotalAskVol);//ί����������
	output.set_nweightedavgbidprice(uint32_t(src.nWeightedAvgBidPrice));//��Ȩƽ��ί��۸�
	output.set_nweightedavgaskprice(uint32_t(src.nWeightedAvgAskPrice));//��Ȩƽ��ί���۸�
	output.set_niopv(src.nIOPV);		//IOPV��ֵ��ֵ
	output.set_nyieldtomaturity(src.nYieldToMaturity);//����������
	output.set_nhighlimited(uint32_t(src.nHighLimited));//��ͣ��
	output.set_nlowlimited(uint32_t(src.nLowLimited));//��ͣ��
	output.set_nsyl1(src.nSyl1);			//��ӯ��1
	output.set_nsyl2(src.nSyl2);			//��ӯ��2
	output.set_nsd2(src.nSD2);				//����2���Ա���һ�ʣ�
}

void TDF_TRANSACTION2Transaction(Transaction &output, const TDF_TRANSACTION &src) {
	output.set_szcode(strtoul(src.szCode, nullptr, 10));	//600001.SH
	output.set_ntime(src.nTime);			//�ɽ�ʱ��(HHMMSSmmm)
	output.set_nindex(src.nIndex);			//�ɽ����
	output.set_nprice(uint32_t(src.nPrice));//�ɽ��۸�
	output.set_nvolume(src.nVolume);		//�ɽ�����
	output.set_nturnover(src.nTurnover);	//�ɽ����
	output.set_nbsflag(src.nBSFlag);		//��������(��'B', ����'S', ������' ')
	output.set_chorderkind(src.chOrderKind);//�ɽ����
	output.set_chfunctioncode(src.chFunctionCode);//�ɽ�����
	output.set_naskorder(src.nAskOrder);	//������ί�����
	output.set_nbidorder(src.nBidOrder);
}

void TDF_ORDER2Order(Order &output, const TDF_ORDER&src) {
	output.set_szcode(strtoul(src.szCode, nullptr, 10));	//600001.SH
	output.set_ntime(src.nTime);			//ʱ��(HHMMSSmmm)
	output.set_norder(src.nOrder);		//ί�к�
	output.set_nprice(uint32_t(src.nPrice));//ί�м۸�
	output.set_nvolume(src.nVolume);		//ί������
	output.set_chorderkind(src.chOrderKind);//ί�����
	output.set_chfunctioncode(src.chFunctionCode);//ί�д���('B','S','C')
	output.set_nbroker(src.nBroker);		//�����̱���
	output.set_chstatus(src.chStatus);		//ί��״̬
	output.set_chflag(src.chFlag);
}

void TDF_ORDER_QUEUE2Order_queue(Order_queue &output, const TDF_ORDER_QUEUE&src) {
	output.set_szcode(strtoul(src.szCode, nullptr, 10));	//600001.SH
	output.set_ntime(src.nTime);			//ʱ��(HHMMSSmmm)
	output.set_nside(src.nSide=='B'||src.nSide=='b');//��������('B':Bid 'A':Ask)
	output.set_nprice(uint32_t(src.nPrice));//ί�м۸�
	output.set_norders(src.nOrders);		//��������
	output.set_nabitems(src.nABItems);		//��ϸ����
	for (int i = 0; i < src.nABItems; ++i) {
		output.add_nabvolume(src.nABVolume[i]);
	}
}

#define MAX_USER_NAME_LEN 64
#define MAX_MQID_LEN	64
#define MAX_STOCK_CODE	1000000

struct UserStruct
{
	struct UserStruct *pNext;
	char sUserName[MAX_USER_NAME_LEN];
	int iMqId;
};

struct UserStruct *AMUSER[MAX_STOCK_CODE],*ATUSER[MAX_STOCK_CODE],*AQUSER[MAX_STOCK_CODE],*AOUSER[MAX_STOCK_CODE];
struct UserStruct *PMALL,*PTALL,*PQALL,*POALL;


void InitUserArray()
{
	int i=0,iSubscribed,iStockCode;
	
	struct UserStruct **AUSER,*pTemp,**PPALL;

	boost::property_tree::ptree tRoot,t,t1,t2;


/*��ӳ������*/
	for(i=0;i<MAX_STOCK_CODE;i++){
		AMUSER[i]=NULL;
		ATUSER[i]=NULL;
		AQUSER[i]=NULL;
		AOUSER[i]=NULL;
	}
	PMALL=PTALL=PQALL=POALL=NULL;

/*��ȡdisp.json�ļ�*/
	boost::property_tree::read_json("./disp.json",tRoot);

	string user,mqid;

	for (auto it = tRoot.begin(); it != tRoot.end(); ++it) {

		auto each = it->second;

		user = each.get<string>("user");
		mqid = each.get<string>("mqid");

		t1 = each.get_child("subscribed");
		t2 = each.get_child("subcodes");


                
                iStockCode=-1;

		for (auto it2 = t2.begin(); it2 != t2.end(); ++it2) {

			iStockCode=it2->second.get_value<int>();
			
			/*������Ч�Ĵ���*/
			if(iStockCode<=0||iStockCode>MAX_STOCK_CODE) continue;

			for (auto it1 = t1.begin(); it1 != t1.end(); ++it1) {

				iSubscribed=it1->second.get_value<int>();
				
				switch(iSubscribed){
				case 12:AUSER=&AMUSER[0];break;
				case 13:AUSER=&ATUSER[0];break;
				case 14:AUSER=&AQUSER[0];break;
				case 15:AUSER=&AOUSER[0];break;
				default:AUSER=NULL;
				break;	
				}
				if(AUSER==NULL)break;

				pTemp=new (struct UserStruct);
				
				if(pTemp==NULL){
					printf("error new struct UserStruct.\n");
					exit(1);
				}
				
				pTemp->pNext=NULL;
				strncpy(pTemp->sUserName,user.c_str(),sizeof(pTemp->sUserName)-1);
				pTemp->sUserName[sizeof(pTemp->sUserName)-1]=0;
				
				pTemp->iMqId=	atoi(mqid.c_str());
				
				/*���뵽����*/
				pTemp->pNext=AUSER[iStockCode];
				AUSER[iStockCode]=pTemp;
                	}
                }
                
                if(iStockCode==-1){
                	
			for (auto it1 = t1.begin(); it1 != t1.end(); ++it1) {

				iSubscribed=it1->second.get_value<int>();
				
				switch(iSubscribed){
				case 12:PPALL=&PMALL;break;
				case 13:PPALL=&PTALL;break;
				case 14:PPALL=&PQALL;break;
				case 15:PPALL=&POALL;break;
				default:PPALL=NULL;
				}					
				if(PPALL==NULL)break;

				pTemp=new (struct UserStruct);
				
				if(pTemp==NULL){
					printf("error new struct UserStruct.\n");
					exit(1);
				}
				
				pTemp->pNext=NULL;
				strncpy(pTemp->sUserName,user.c_str(),sizeof(pTemp->sUserName)-1);
				pTemp->sUserName[sizeof(pTemp->sUserName)-1]=0;
				
				pTemp->iMqId=	atoi(mqid.c_str());
				
				/*���뵽����*/
				pTemp->pNext=*PPALL;
				*PPALL=pTemp;
			}
                }

	}
}

int SendMsg2Mq(string &str,int iMqId)
{
for(int i=0;i<1;i++){
	MessageQueue *mq=new MessageQueue(iMqId);
	
	if(mq==NULL) return -1;
	
//	open(bool ifblock, bool ifcreate, int maxlen, int maxnum);

	mq->open(false,false,4096,1);


	if((mq->send(str,0))==(int)(str.size()))
		iCurCnt++;

	
	delete mq;
}
	return 0;
}
void SendMsg2Cli(int iStockCode,char cType,string& str)
{
	char sBuffer[4];
	unsigned int len,l0,l1;
	struct UserStruct *pAll,*pUser;
	
	string str1;

	/*ȡ�ֽڳ��ȣ����ж������ֵ*/
	len=str.length()+1; if(len>10230) len=10230;

	l0=len%256;
	l1=len/256;

	((unsigned char*)sBuffer)[0]=l1;
	((unsigned char*)sBuffer)[1]=l0;

	switch (cType){
	case 'M': pUser=AMUSER[iStockCode];pAll=PMALL;sBuffer[2]=12;break;
	case 'T': pUser=ATUSER[iStockCode];pAll=PTALL;sBuffer[2]=13;break;
	case 'Q': pUser=AQUSER[iStockCode];pAll=PQALL;sBuffer[2]=14;break;
	case 'O': pUser=AOUSER[iStockCode];pAll=POALL;sBuffer[2]=15;break;
	default:  pUser=AQUSER[iStockCode];pAll=PQALL;sBuffer[2]=14;break;
	break;
	}

	str1=string(sBuffer,3)+str;
	
//	strncpy(sBuffer+3,str.c_str(),str.length());

	while(pUser!=NULL){
		SendMsg2Mq(str1,pUser->iMqId);
		pUser=pUser->pNext;
	}

	while(pAll!=NULL){
		SendMsg2Mq(str1,pAll->iMqId);
		pAll=pAll->pNext;
	}
}


int main()
{
	IoService							ios;

	//������Ϣ�ص���
	CallBackBase CallbackBase;
	CallbackBase.SetIoService(&ios);

	//�����������ݷ���
	ios.Start();

	//��������API����
	//�������̩��ʵʱ����ϵͳV2.X �û��ֲᡷ4.2.1.1 ����ʵ��CreateInstance �½�
	IGTAQTSApiBase* pApiBase = IGTAQTSApiBase::CreateInstance(CallbackBase);
	// ע��FENS��ַ
	//***** ���棺ʵ����������ʹ��ʱ���ӹ�̩����˾��ȡ����FENS��ַ���˴���Ҫȫ��ͨ����RegisterService�������ӿ�ע�ᣬ
	//*****       ���������ݸ߿��÷��棬�����ۿۡ�
	//***** ����4��FENS ip��ַ����Ҫ���µ��ã�
	//       pApiBase->RegisterService("ip1", port1);
	//       pApiBase->RegisterService("ip2", port2);
	//       pApiBase->RegisterService("ip3", port3);
	//       pApiBase->RegisterService("ip4", port4);
	//�������̩��ʵʱ����ϵͳV2.X �û��ֲᡷ4.2.1.4 ע�����RegisterService �½�
	//pApiBase->RegisterService("113.108.73.138", 8866);
	//pApiBase->RegisterService("180.153.102.99", 8888);


	boost::property_tree::ptree tRoot,t;
	boost::property_tree::read_json("./gta_ints.json",tRoot);

	t = tRoot.get_child("gta_server");

	uint16_t port;
	string host,id,passwd,workroot;

	for (auto it = t.begin(); it != t.end(); ++it) {
		try {
			host = it->second.get<string>("host");
			port = it->second.get<uint16_t>("port");

			pApiBase->RegisterService(host.c_str(), port);
		}
		catch (...) {
			break;
		}
	}
	//���ó�ʱʱ��
	pApiBase->SetTimeout(30);

	id 	= tRoot.get<string>("id");
	passwd 	= tRoot.get<string>("passwd");
	workroot= tRoot.get<string>("workroot");

	string gtaqhName,gtaqzName,tdfmktName,tdfqueName;
	FILE *fpGtaQh,*fpGtaQz,*fpTdfMkt,*fpTdfQue;

	gtaqhName=	workroot+"/gta_qh.dat";
	gtaqzName=	workroot+"/gta_qz.dat";
	tdfmktName=	workroot+"/tdf_mkt.dat";
	tdfqueName=	workroot+"/tdf_que.dat";

	fpGtaQh=	fopen(gtaqhName.c_str(),"ab+");
	fpGtaQz=	fopen(gtaqzName.c_str(),"ab+");

	fpTdfMkt=	fopen(tdfmktName.c_str(),"ab+");
	fpTdfQue=	fopen(tdfqueName.c_str(),"ab+");

	do{
		//ͨ���û������������������½
		//�������̩��ʵʱ����ϵͳV2.X �û��ֲᡷ4.2.1.5 �û���֤Login �½�
		RetCode  ret = pApiBase->LoginX(id.c_str(), passwd.c_str(), "NetType=0");
		if (Ret_Success != ret)
		{
			printf("Login error:%d\n", ret);
			break;
		}

		//****************************** ��ȡ֤ȯ�����б�Ȩ���б�****************************************
		CDataBuffer<StockSymbol> StockList1;

		// ��ȡ�Ͻ�������������б�����SSE��ʾ�Ͻ�����SZSE��ʾ�����CFFEX��ʾ�н���
		//�������̩��ʵʱ����ϵͳV2.X �û��ֲᡷ4.2.1.11 ��ȡ�����б�GetStockList �½�
		ret = pApiBase->GetStockList((char*)"sse,szse", StockList1);
		if (Ret_Success != ret)
		{
			printf("GetStockList(sse,szse) error:%d\n", ret);
			break;
		}

		//��ʼ��ȫ�ֲ�������
		InitUserArray();

		StockSymbol* pStock = StockList1;
		const int sz = StockList1.Size();
		VectorStockCodeSH vSH;
		VectorStockCodeSZ vSZ;

		for (int i = 0; i < sz; ++i) {
			if (!(vSH.push(pStock[i].Symbol))) {
				vSZ.push(pStock[i].Symbol);
			}
		}
		printf("\n");

		CDataBuffer<MsgType> DataTypeList;
		// ��ȡȨ���б�
		//�������̩��ʵʱ����ϵͳV2.X �û��ֲᡷ4.1.1.7 ��ȡȨ���б�GetDataTypeList �½�
		ret = pApiBase->GetDataTypeList(DataTypeList);
		if (Ret_Success != ret)
		{
			printf("GetDataTypeList(sse) error:%d\n", ret);
			break;
		}

		MsgType* pMsg = DataTypeList;
		int Count = DataTypeList.Size();
		printf("MsgType Count = %d, List:", Count);
		for (int i = 0; i < Count; ++i)
		{
			printf("Ox%08x, ", pMsg[i]);
		}
		printf("\n");


		//************************************������������***********************************************

		// �����붩�����ʵʱ��������
		//�������̩��ʵʱ����ϵͳV2.X �û��ֲᡷ4.1.1.8 ����ʵʱ����Subscribe �½�
		string strCodesSH;
		vSH.strForSub(strCodesSH);
		string strCodesSZ;
		vSZ.strForSub(strCodesSZ);

		ret = pApiBase->Subscribe(Msg_SZSEL2_Transaction,(char*)"000001");
		if (Ret_Success != ret)
		{
			printf("Subscribe by code error:%d\n", ret);
			break;
		}

//��ӡ���ṹ��С
printf("%ld\t%ld\t%ld\t%ld\t%ld\t%ld\t\n%ld\t%ld\t%ld\t%ld\t\n%ld\t%ld\t%ld\t%ld\t%ld\n",
	sizeof(SSEL2_Quotation),sizeof(SSEL2_Transaction),sizeof(SSEL2_Auction),
	sizeof(SZSEL2_Quotation),sizeof(SZSEL2_Transaction),sizeof(SZSEL2_Order),
	sizeof(TDF_MARKET_DATA),sizeof(TDF_TRANSACTION),sizeof(TDF_ORDER_QUEUE),sizeof(TDF_ORDER),
	sizeof(MktData),sizeof(Transaction),sizeof(Order_queue),sizeof(Order),
	sizeof(struct timeval));

		printf("press any key to continue...(Unsubscribe all data)\n");
		getchar();

		// ������ȡ�����ʵʱ��������
		//�������̩��ʵʱ����ϵͳV2.X �û��ֲᡷ4.1.1.9 ȡ������Unsubscribe �½�
		ret = pApiBase->Unsubscribe(Msg_SZSEL2_Quotation,(char*)"000001,000651,000039");
		if (Ret_Success != ret)
		{
			printf("Unsubscribe by code error:%d\n", ret);
		}
		// ȡ�����ʵʱ���д���
		ret = pApiBase->Unsubscribe(Msg_SZSEL2_Quotation, NULL);
		if (Ret_Success != ret)
		{
			printf("Unsubscribe by market error:%d\n", ret);
		}

while(1){

		// ���ʵʱ������ղ�ѯ����������ͨ��Snap_Quotation�ṹ����
		CDataBuffer<SZSEL2_Quotation> szSnap_Quotation;
		ret = pApiBase->QuerySnap_SZSEL2_Quotation(NULL, szSnap_Quotation);
		if (Ret_Success != ret)
		{
			printf("Login error:%d\n", ret);
			break;
		}

		SZSEL2_Quotation* pSse = szSnap_Quotation;
		if (pSse != NULL)
		{
			printf("QuerySnap_Base:Count = %d, LocalTimeStamp = %d, Symbol = %s, OpenPrice = %f, TotalAmount = %f\n",
				szSnap_Quotation.Size(), pSse->LocalTimeStamp, pSse->Symbol, pSse->OpenPrice, pSse->TotalAmount);
		}

		gettimeofday(&tvPre,NULL);
		
		// ��ȡȫ������
		for (int i = 0; i < szSnap_Quotation.Size(); ++i){

			SZSEL2_Quotation& SSEQuot = szSnap_Quotation[i];
/*			printf("LocalTimeStamp(%ld) = %d, Symbol = %s, OpenPrice = %f, TotalAmount = %f\n",
				sizeof(SZSEL2_Quotation),
				SSEQuot.LocalTimeStamp, SSEQuot.Symbol, SSEQuot.OpenPrice, SSEQuot.TotalAmount);
*/
			fwrite((const void*)&szSnap_Quotation[i],sizeof(SZSEL2_Quotation),1,fpGtaQz);

			TDF_MARKET_DATA m;
			TDF_ORDER_QUEUE q[2];

			GTA2TDF_SZSEL2(szSnap_Quotation[i],m, q[0],q[1]);
			fwrite((const void*)&m,sizeof(TDF_MARKET_DATA),1,fpTdfMkt);
			fwrite((const void*)&q[0],sizeof(TDF_ORDER_QUEUE),2,fpTdfQue);
			
			MktData 	md;

			Order_queue 	oq0,oq1;
                	
			string strMd,strOq0,strOq1;
                	
			TDF_MARKET_DATA2MktData(md,m);
                	
			TDF_ORDER_QUEUE2Order_queue(oq0,q[0]);
			TDF_ORDER_QUEUE2Order_queue(oq1,q[1]);
                	
                	
			md.SerializeToString(&strMd);
			oq0.SerializeToString(&strOq0);
			oq1.SerializeToString(&strOq1);
                	
			int iStockCode=atoi(szSnap_Quotation[i].Symbol);
			//У�����Ϸ���
			if(iStockCode<=0||iStockCode>=MAX_STOCK_CODE) break;
                	
			SendMsg2Cli(iStockCode,'M',strMd);
			SendMsg2Cli(iStockCode,'Q',strOq0);
			SendMsg2Cli(iStockCode,'Q',strOq1);

		}

		gettimeofday(&tvCur,NULL);

		fflush(fpGtaQz);
		fflush(fpTdfMkt);
		fflush(fpTdfQue);

		// �Ͻ���ʵʱ������ղ�ѯ����������ͨ��Snap_Quotation�ṹ����
		CDataBuffer<SSEL2_Quotation> shSnap_Quotation;
		ret = pApiBase->QuerySnap_SSEL2_Quotation(NULL, shSnap_Quotation);
		if (Ret_Success != ret)
		{
			printf("Login error:%d\n", ret);
			break;
		}

		SSEL2_Quotation* pSse1 = shSnap_Quotation;
		if (pSse1 != NULL)
		{
			printf("QuerySnap_Base:Count = %d, LocalTimeStamp = %d, Symbol = %s, OpenPrice = %f, TotalAmount = %f\n",
				shSnap_Quotation.Size(), pSse1->LocalTimeStamp, pSse1->Symbol, pSse1->OpenPrice, pSse1->TotalAmount);
		}

		// ��ȡȫ������
		for (int i = 0; i < shSnap_Quotation.Size(); ++i){
			SSEL2_Quotation& SSEQuot = shSnap_Quotation[i];
/*			printf("LocalTimeStamp1(%ld) = %d, Symbol = %s, OpenPrice = %f, TotalAmount = %f\n",
				sizeof(SSEL2_Quotation),
				SSEQuot.LocalTimeStamp, SSEQuot.Symbol, SSEQuot.OpenPrice, SSEQuot.TotalAmount);
*/
			fwrite((const void*)&shSnap_Quotation[i],sizeof(SSEL2_Quotation),1,fpGtaQh);

			TDF_MARKET_DATA m;
			TDF_ORDER_QUEUE q[2];

			GTA2TDF_SSEL2(shSnap_Quotation[i],m, q[0],q[1]);
			fwrite((const void*)&m,sizeof(TDF_MARKET_DATA),1,fpTdfMkt);
			fwrite((const void*)&q[0],sizeof(TDF_ORDER_QUEUE),2,fpTdfQue);

		}

		fflush(fpGtaQh);
		fflush(fpTdfMkt);
		fflush(fpTdfQue);

		printf("--------------------------------- send cnt =%d -------%ld---------.\n",iCurCnt-iPreCnt,
			tvCur.tv_sec*1000000+tvCur.tv_usec-tvPre.tv_sec*1000000-tvPre.tv_usec);

		iPreCnt=iCurCnt;

		printf("press any key to continue...(query snap data)\n");
		getchar();
}

		//�Ϻ�L2���Ͼ���
		ret = pApiBase->Subscribe(Msg_SSEL2_Auction, (char*)(strCodesSH.c_str()));
		if (Ret_Success != ret) {
			printf("Subscribe Msg_SSEL2_Auction code=%d\n",ret);
			break;
		}

		//�Ϻ�L2ʵʱ����
		ret = pApiBase->Subscribe(Msg_SSEL2_Quotation, (char*)(strCodesSH.c_str()));
		if (Ret_Success != ret) {
			printf("Subscribe Msg_SSEL2_Quotation code=%d\n",ret);
			break;
		}
		//�Ϻ�L2ʵʱ����
		ret = pApiBase->Subscribe(Msg_SSEL2_Transaction, (char*)(strCodesSH.c_str()));
		if (Ret_Success != ret) {
			printf("Subscribe Msg_SSEL2_Transaction code=%d\n",ret);
			break;
		}

		//����L2ʵʱ����
		ret = pApiBase->Subscribe(Msg_SZSEL2_Quotation, (char*)(strCodesSZ.c_str()));
		if (Ret_Success != ret) {
			printf("Subscribe Msg_SZSEL2_Quotation code=%d\n",ret);
			break;
		}
		//����L2ʵʱ����
		ret = pApiBase->Subscribe(Msg_SZSEL2_Transaction, (char*)(strCodesSZ.c_str()));
		if (Ret_Success != ret) {
			printf("Subscribe Msg_SZSEL2_Transaction code=%d\n",ret);
			break;
		}
		//����L2���ί��
		ret = pApiBase->Subscribe(Msg_SZSEL2_Order, (char*)(strCodesSZ.c_str()));
		if (Ret_Success != ret) {
			printf("Subscribe Msg_SZSEL2_Order code=%d\n",ret);
			break;
		}

	} while (false);

	//�˳������߳�
	ios.Stop();

	getchar();

	// ������ʹ��APIʱ����Ҫ���ô˽ӿ��ͷ��ڲ���Դ������������ڴ�й©������Ԥ֪����
	//�������̩��ʵʱ����ϵͳV2.X �û��ֲᡷ4.2.1.2 �ͷ�ʵ��ReleaseInstance �½�
	IGTAQTSApiBase::ReleaseInstance(pApiBase);
	return 0;
}
