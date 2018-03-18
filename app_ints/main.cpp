//////////////////////////////////////////////////////////////////////////
/// @brief    ����API
///           ʵ�ֲ�ͬ��ʽ�Ķ��ĺ�ȡ�����ļ����ղ�ѯ
//////////////////////////////////////////////////////////////////////////
#include "GTAQTSInterfaceBase.h"
#include "CallBackBase.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/inotify.h>
#include <unistd.h>
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
#include "../VecStockCode/VectorStockCodeSH.h"
#include "../VecStockCode/VectorStockCodeSZ.h"

#include "../GTA2TDF/GTA2TDF.h"

int iDebugFlag=0,iWriteFlag=0;
char sCfgJsonName[1024],sDispName[1024],sPrivilegeFile[1024];

/****
#define EVENT_NUM 12

char *event_str[EVENT_NUM] =
{
    "IN_ACCESS",
    "IN_MODIFY",
    "IN_ATTRIB",
    "IN_CLOSE_WRITE",
    "IN_CLOSE_NOWRITE",
    "IN_OPEN",
    "IN_MOVED_FROM",
    "IN_MOVED_TO",
    "IN_CREATE",
    "IN_DELETE",
    "IN_DELETE_SELF",
    "IN_MOVE_SELF"
};
***/

int WatchFileCloseWriteAndLock(char sFileName[])
{
	int fd,len,i;
	char buf[BUFSIZ];
	struct inotify_event *event;

	if((fd = inotify_init())<0){
		fprintf(stderr, "inotify_init failed\n");
		return -1;
	}

	if(inotify_add_watch(fd, sFileName, IN_ALL_EVENTS)<0){
		fprintf(stderr, "inotify_add_watch %s failed\n", sFileName);
		return -1;
	}

	buf[sizeof(buf) - 1] = 0;
	while( (len = read(fd, buf, sizeof(buf) - 1)) > 0 ){

		//printf("-----------------------------3 l=%d.\n",len);
		
		for(i=0;i<len;i+=sizeof(struct inotify_event)){
			
			event = (struct inotify_event *)&buf[i];
			
			//fprintf(stdout, "%s --- %s\ti=%d,m=%d,l=%d\n"," ", "",i,event->mask,len);

			//�������WRITE_CLOSE�¼������
			if((event->mask & 0x8)==0) continue;
			
			printf("catch WRITE-ON-CLOSE EVENT.\n");

			//��������
			LockWorkThread();
		}
	}
	return 0;
}
int main(int argc, char *argv[])
{

	strcpy(sCfgJsonName,	"./gta_ints.json");
	strcpy(sDispName,	"./disp.json");
	strcpy(sPrivilegeFile,	"./user_privilege.json");

	for (int c; (c = getopt(argc, argv, "d:c:r:p:w:h:")) != EOF;){

		switch (c){
		case 'd':
			iDebugFlag = atoi(optarg);
			break;
		case 'c':
			strcpy(sCfgJsonName, optarg);
			break;
		case 'r':
			strcpy(sDispName, optarg);
			break;
		case 'p':
			strcpy(sPrivilegeFile, optarg);
			break;
		case 'w':
			iWriteFlag=atoi(optarg);
			if(iWriteFlag!=1&&iWriteFlag!=2) iWriteFlag=0;
			break;
		case '?':
		default:
			printf("Usage: %s \n", argv[0]);
			printf("   [-c cfg-name ]\n");
			printf("   [-r disp-name ]\n");
			printf("   [-p privilege-name ]\n");
			printf("   [-d DebugFlag ]\n");
			printf("   [-w (1,writegta,2 writetdf,other nowrite) ]\n");
			exit(1);
			break;
		}
	}

	//��ʼ��ˢ�����飬�Լ�ˢ���ļ�����ȫ�ֱ���
	InitUserArray(sDispName);

	uint16_t port;
	string host,id,passwd,strWork;
	boost::property_tree::ptree tRoot,t;
	boost::property_tree::read_json(sCfgJsonName,tRoot);

	t 	= tRoot.get_child("gta_server");
	strWork	= tRoot.get<string>("workroot");	
	id 	= tRoot.get<string>("id");
	passwd 	= tRoot.get<string>("passwd");

	IoService	ios;
	//������Ϣ�ص���
	CallBackBase CallbackBase(iWriteFlag,strWork);
	CallbackBase.SetIoService(&ios);

	//�����������ݷ���
	ios.Start();

	//��������API����
	//�������̩��ʵʱ����ϵͳV2.X �û��ֲᡷ4.2.1.1 ����ʵ��CreateInstance �½�
	IGTAQTSApiBase* pApiBase = IGTAQTSApiBase::CreateInstance(CallbackBase);
	// ע��FENS��ַ,�����ע��������ݸ߿��÷��棬�����ۿۡ�
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

	do{
		//ͨ���û������������������½
		//�������̩��ʵʱ����ϵͳV2.X �û��ֲᡷ4.2.1.5 �û���֤Login �½�
		RetCode  ret = pApiBase->LoginX(id.c_str(), passwd.c_str(), "NetType=0");
		if (Ret_Success != ret){
			printf("Login error:%d\n", ret);
			break;
		}

		//****************************** ��ȡ֤ȯ�����б���Ȩ���б�****************************************
		CDataBuffer<StockSymbol> StockList1;

		// ��ȡ�Ͻ�������������б�������SSE��ʾ�Ͻ�����SZSE��ʾ�����CFFEX��ʾ�н���
		//�������̩��ʵʱ����ϵͳV2.X �û��ֲᡷ4.2.1.11 ��ȡ�����б�GetStockList �½�
		ret = pApiBase->GetStockList((char*)"sse,szse", StockList1);
		if (Ret_Success != ret){
			printf("GetStockList(sse,szse) error:%d\n", ret);
			break;
		}

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
		if (Ret_Success != ret){
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
		string strCodesSH,strCodesSZ;
		vSH.strForSub(strCodesSH);
		vSZ.strForSub(strCodesSZ);

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

	} 
	while (false);
	
//	printf("-----------------------------1.\n");
	
	//ѭ������disp����仯������仯��֪ͨˢ��
	WatchFileCloseWriteAndLock(sDispName);
	
//	printf("-----------------------------2.\n");

	//�������벻�����е�����
	while(1){//���̲߳����˳�
		sleep(1);
	}

	//�˳������߳�
	ios.Stop();

	getchar();

	// ������ʹ��APIʱ����Ҫ���ô˽ӿ��ͷ��ڲ���Դ������������ڴ�й©������Ԥ֪����
	//�������̩��ʵʱ����ϵͳV2.X �û��ֲᡷ4.2.1.2 �ͷ�ʵ��ReleaseInstance �½�
	IGTAQTSApiBase::ReleaseInstance(pApiBase);

	return 0;
}