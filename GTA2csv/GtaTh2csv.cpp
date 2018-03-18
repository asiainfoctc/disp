#include "QTSStruct.h"
#include "GtaTh2csv.h"

GtaTh2csv::GtaTh2csv(const string &c)
	:Gta2csv(c) {}

void GtaTh2csv::writeLine(const void *gtaStruct)/*override*/ {
	const SSEL2_Transaction *t = (const SSEL2_Transaction *)gtaStruct;
	m_ofs << t->LocalTimeStamp << ','		//< ���ݽ���ʱ��HHMMSSMMM
		<< t->QuotationFlag << ','			//< 1=�Ϻ��ϻ��������Դ��2=���ڸ�����������Դ
		<< t->PacketTimeStamp << ','		//< ���ݰ�ͷʱ��YYYYMMDDHHMMSSMMM
		<< t->TradeTime << ','				//< �ɽ�ʱ��(����), 14302506 ��ʾ14:30:25.06
		<< t->RecID << ','					//< ҵ������, �� 1 ��ʼ���� TradeChannel����
		<< t->TradeChannel << ','			//< �ɽ�ͨ��, 
		<< t->Symbol << ','					//< ֤ȯ����, 
		<< t->TradePrice << ','				//< �ɽ��۸�, 
		<< t->TradeVolume << ','			//< �ɽ�����, ��Ʊ����;Ȩ֤����;ծȯ����
		<< t->TradeAmount << ','			//< �ɽ����, 
		<< t->BuyRecID << ','				//< �򷽶�����, 
		<< t->SellRecID << ','				//< ����������,
		<< t->BuySellFlag << ',' << endl;	//< �����̱�־, B �C ����,������;S �C ����,������;N �C δ֪
}

void GtaTh2csv::getFileName(string &strFileName)/*override*/ {
	strFileName = "��ʳɽ�.csv";
}

void GtaTh2csv::getHeaders(string &strHeaders)/*override*/ {
	strHeaders = "����,����Դ,��ͷ,ʱ��,����,�ɽ�ͨ��,֤ȯ,�۸�,����,�ɽ����,�򶩵���,��������,������,";
}
