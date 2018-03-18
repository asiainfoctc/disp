#include "QTSStruct.h"
#include "GtaTz2csv.h"

GtaTz2csv::GtaTz2csv(const string &c)
	:Gta2csv(c) {}

void GtaTz2csv::writeLine(const void *gtaStruct) {
	const SZSEL2_Transaction *t = (const SZSEL2_Transaction *)gtaStruct;
	m_ofs << t->LocalTimeStamp << ','		//< ���ݽ���ʱ��HHMMSSMMM
		<< t->QuotationFlag << ','			//< 1=�Ϻ��ϻ��������Դ��2=���ڸ�����������Դ
		<< t->SetID << ','					//< ֤ȯ������
		<< t->RecID << ','					//< ��Ϣ��¼�� �� 1 ��ʼ������ͬһƵ������
		<< t->BuyOrderID << ','				//< ��ί������
		<< t->SellOrderID << ','			//< ����ί������
		<< t->Symbol << ','					//< ֤ȯ����
		<< t->SymbolSource << ','			//< ֤ȯ����Դ
		<< t->TradeTime << ','				//< �ɽ�ʱ��YYYYMMDDHHMMSSMMM
		<< t->TradePrice << ','				//< �ɽ��۸�,4λС��
		<< t->TradeVolume << ','			//< �ɽ�����,2λС��
		<< t->TradeType << ',' << endl;		//< �ɽ����4=�������������Զ�����ִ�б��棻F=�ɽ����ɽ�ִ�б���
}

void GtaTz2csv::getFileName(string &strFileName) {
	strFileName = "��ʳɽ�.csv";
}

void GtaTz2csv::getHeaders(string &strHeaders) {
	strHeaders = "����,����Դ,֤ȯ��,��¼��,��ί��,��ί��,֤ȯ,����Դ,ʱ��,�۸�,����,�ɽ����,";
}
