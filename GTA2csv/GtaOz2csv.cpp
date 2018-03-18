#include "QTSStruct.h"
#include "GtaOz2csv.h"

GtaOz2csv::GtaOz2csv(const string &c)
	:Gta2csv(c) {}

void GtaOz2csv::getFileName(string &strFileName) {
	strFileName = "���ί��.csv";
}

void GtaOz2csv::getHeaders(string &strHeaders) {
	strHeaders = "����,����Դ,Ƶ��,��¼,֤ȯ,����Դ,ʱ��,�۸�,����,����,�������,";
}

void GtaOz2csv::writeLine(const void *gtaStruct) {
	const SZSEL2_Order *o = (const SZSEL2_Order *)gtaStruct;
	m_ofs << o->LocalTimeStamp << ','	//< ���ݽ���ʱ��HHMMSSMMM
		<< o->QuotationFlag << ','		//< 1=�Ϻ��ϻ��������Դ��2=���ڸ�����������Դ
		<< o->SetID << ','				//< Ƶ������
		<< o->RecID << ','				//< ��Ϣ��¼��:�� 1 ��ʼ������ͬһƵ������
		<< o->Symbol << ','				//< ֤ȯ����
		<< o->SymbolSource << ','		//< ֤ȯ����Դ
		<< o->Time << ','				//< ί��ʱ��YYYYMMDDHHMMSSMMM
		<< o->OrderPrice << ','			//< ί�м۸�,4λС��
		<< o->OrderVolume << ','		//< ί������,2λС��
		<< o->OrderCode << ','			//< ��������1=�� 2=�� G=���� F=����
		<< o->OrderType << ',' << endl;	//< �������1=�м� 2=�޼� U=��������
}
