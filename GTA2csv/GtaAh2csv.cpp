#include "QTSStruct.h"
#include "GtaAh2csv.h"

GtaAh2csv::GtaAh2csv(const string &c)
	:Gta2csv(c) {}

void GtaAh2csv::getFileName(string &strFileName) {
	strFileName = "Auction.csv";
}

void GtaAh2csv::getHeaders(string &strHeaders) {
	strHeaders = "�ɼ�,����Դ,��ͷ,����,֤ȯ,��ο�,��ƥ��,��δƥ��,����,";
}

void GtaAh2csv::writeLine(const void *gtaStruct) {
	const SSEL2_Auction *a = (const SSEL2_Auction *)gtaStruct;
	m_ofs << a->LocalTimeStamp << ','		//< ���ݽ���ʱ��HHMMSSMMM
		<< a->QuotationFlag << ','			//< 1=�Ϻ��ϻ��������Դ��2=���ڸ�����������Դ
		<< a->PacketTimeStamp << ','		//< ���ݰ�ͷʱ��YYYYMMDDHHMMSSMMM
		<< a->Time << ','					//< ��������ʱ��, ���¶���ʱ�䣨���룩;143025001 ��ʾ 14:30:25.001
		<< a->Symbol << ','					//< ֤ȯ����, 
		<< a->OpenPrice << ','				//< ���⿪�̼�, 
		<< a->AuctionVolume << ','			//< ����ƥ������ 
		<< a->LeaveVolume << ','			//< ����δƥ����, 
		<< a->Side << ',' << endl;			//< ��������
}
