#pragma once
#include <arpa/inet.h>
#include <string>
#include <google/protobuf/message.h>
#include "mktdata.pb.h"
using namespace std;
class BufAddBizcode
{
public:
	//��bizCode��pbmsg��Ϣ�����Ϊ�� ��ʽ��2�ֽڳ���+1�ֽ�bizCode+pb->SerializeToString���������Ϊ 1�ֽ�+���л���
	static void addBizcode(string &output, const google::protobuf::Message &pbmsg, BizCode bizCode);
	//��msgInput�ĵ�һ���ֶ�ȡ������ΪbizCode����Ĵ���Ϊpbmsg
	static void getBizcode(BizCode &bizCode, string &pbmsg, const string &msgInput);
};

