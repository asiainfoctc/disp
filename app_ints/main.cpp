//////////////////////////////////////////////////////////////////////////
/// @brief    基础API
///           实现不同方式的定阅和取消订阅及快照查询
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

			//如果不是WRITE_CLOSE事件则继续
			if((event->mask & 0x8)==0) continue;
			
			printf("catch WRITE-ON-CLOSE EVENT.\n");

			//锁定变量
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

	//初始化刷新数组，以及刷新文件名的全局变量
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
	//订阅消息回调类
	CallBackBase CallbackBase(iWriteFlag,strWork);
	CallbackBase.SetIoService(&ios);

	//启动处理数据服务
	ios.Start();

	//创建基础API对象
	//详见《国泰安实时行情系统V2.X 用户手册》4.2.1.1 创建实例CreateInstance 章节
	IGTAQTSApiBase* pApiBase = IGTAQTSApiBase::CreateInstance(CallbackBase);
	// 注册FENS地址,如果不注册会在数据高可用方面，会大打折扣。
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
	//设置超时时间
	pApiBase->SetTimeout(30);

	do{
		//通过用户名与密码向服务器登陆
		//详见《国泰安实时行情系统V2.X 用户手册》4.2.1.5 用户认证Login 章节
		RetCode  ret = pApiBase->LoginX(id.c_str(), passwd.c_str(), "NetType=0");
		if (Ret_Success != ret){
			printf("Login error:%d\n", ret);
			break;
		}

		//****************************** 获取证券代码列表及权限列表****************************************
		CDataBuffer<StockSymbol> StockList1;

		// 获取上交所和深交所代码列表，其中SSE表示上交所，SZSE表示深交所，CFFEX表示中金所
		//详见《国泰安实时行情系统V2.X 用户手册》4.2.1.11 获取代码列表GetStockList 章节
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
		// 获取权限列表
		//详见《国泰安实时行情系统V2.X 用户手册》4.1.1.7 获取权限列表GetDataTypeList 章节
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

		//************************************订阅行情数据***********************************************

		// 按代码订阅深交所实时行情数据
		//详见《国泰安实时行情系统V2.X 用户手册》4.1.1.8 订阅实时数据Subscribe 章节
		string strCodesSH,strCodesSZ;
		vSH.strForSub(strCodesSH);
		vSZ.strForSub(strCodesSZ);

		//上海L2集合竞价
		ret = pApiBase->Subscribe(Msg_SSEL2_Auction, (char*)(strCodesSH.c_str()));
		if (Ret_Success != ret) {
			printf("Subscribe Msg_SSEL2_Auction code=%d\n",ret);
			break;
		}
		
		//上海L2实时行情
		ret = pApiBase->Subscribe(Msg_SSEL2_Quotation, (char*)(strCodesSH.c_str()));
		if (Ret_Success != ret) {
			printf("Subscribe Msg_SSEL2_Quotation code=%d\n",ret);
			break;
		}
		//上海L2实时交易
		ret = pApiBase->Subscribe(Msg_SSEL2_Transaction, (char*)(strCodesSH.c_str()));
		if (Ret_Success != ret) {
			printf("Subscribe Msg_SSEL2_Transaction code=%d\n",ret);
			break;
		}
		
		//深圳L2实时行情
		ret = pApiBase->Subscribe(Msg_SZSEL2_Quotation, (char*)(strCodesSZ.c_str()));
		if (Ret_Success != ret) {
			printf("Subscribe Msg_SZSEL2_Quotation code=%d\n",ret);
			break;
		}
		//深圳L2实时交易
		ret = pApiBase->Subscribe(Msg_SZSEL2_Transaction, (char*)(strCodesSZ.c_str()));
		if (Ret_Success != ret) {
			printf("Subscribe Msg_SZSEL2_Transaction code=%d\n",ret);
			break;
		}
		//深圳L2逐笔委托
		ret = pApiBase->Subscribe(Msg_SZSEL2_Order, (char*)(strCodesSZ.c_str()));
		if (Ret_Success != ret) {
			printf("Subscribe Msg_SZSEL2_Order code=%d\n",ret);
			break;
		}

	} 
	while (false);
	
//	printf("-----------------------------1.\n");
	
	//循环监视disp规则变化，如果变化则通知刷新
	WatchFileCloseWriteAndLock(sDispName);
	
//	printf("-----------------------------2.\n");

	//正常代码不会运行到这里
	while(1){//主线程不能退出
		sleep(1);
	}

	//退出工作线程
	ios.Stop();

	getchar();

	// 当不再使用API时，需要调用此接口释放内部资源，否则会引起内存泄漏及不可预知问题
	//详见《国泰安实时行情系统V2.X 用户手册》4.2.1.2 释放实例ReleaseInstance 章节
	IGTAQTSApiBase::ReleaseInstance(pApiBase);

	return 0;
}
