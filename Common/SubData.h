#pragma once
#include <string>
#include "QTSDataType.h"
using namespace std;

typedef struct _sub_data_
{
	MsgType     msgType;    ///< ��Ϣ����
	long long	cur_time;	///< ���յ�����ʱ�䣬��ȷ�����룬��ʽΪ��DDHHMMSSmmm
	std::string	data;		///< ��������
}SubData;
