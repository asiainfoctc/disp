#include "QTSStruct.h"
#include "GtaQz2csv.h"

GtaQz2csv::GtaQz2csv(const string &c)
	:Gta2csv(c) {}

void GtaQz2csv::getFileName(string &strFileName)/*override*/ {
	strFileName = "Quotation.csv";
}

void GtaQz2csv::getHeaders(string &strHeaders)/*override*/ {
	strHeaders = "����,����Դ,����,֤ȯ,����Դ,����,����,�ּ�,���,���,��ͣ,��ͣ,����1,����2,�ɽ�����,�ɽ�����,����,����״̬,��ӯ��1,����ֵ,��ӯ��2,IOPV,Ȩ֤�����\
,ί������,��Ȩί����,������λ��,������1,������1,����ί�б���1,������2,������2,����ί�б���2,��һ��ʾί�б���,��1������\
,ί������,��Ȩί���,����λ��,�����1,������1,����ί�б���1,�����2,������2,����ί�б���2,��һ��ʾί�б���,��1������\
,ʵʱ��Ȩƽ������,��Ȩƽ�������ǵ�BP,�����̼�Ȩƽ������,";
}

void GtaQz2csv::writeLine(const void *gtaStruct)/*override*/ {
	const SZSEL2_Quotation *q = (const SZSEL2_Quotation *)gtaStruct;
	m_ofs << q->LocalTimeStamp << ','		//< ���ݽ���ʱ��HHMMSSMMM
		<< q->QuotationFlag << ','			//< 1=�Ϻ��ϻ��������Դ��2=���ڸ�����������Դ
		<< q->Time << ','					//< ��������ʱ��, ���¶���ʱ�䣨���룩;143025001 ��ʾ 14:30:25.001
		<< q->Symbol << ','					//< ֤ȯ����,
		<< q->SymbolSource << ','			//< ֤ȯ����Դ
		<< q->PreClosePrice << ','			//< ���ռ�, 
		<< q->OpenPrice << ','				//< ���̼�,
		<< q->LastPrice << ','				//< �ּ�,
		<< q->HighPrice << ','				//< ��߼�, 
		<< q->LowPrice << ','				//< ��ͼ�, 
		<< q->PriceUpLimit << ','			//< ��ͣ��,6λС��
		<< q->PriceDownLimit << ','			//< ��ͣ��,6λС��
		<< q->PriceUpdown1 << ','			//< ����һ,6λС��
		<< q->PriceUpdown2 << ','			//< ������,6λС��
		<< q->TotalNo << ','				//< �ɽ�����, 
		<< q->TotalVolume << ','			//< �ɽ�����, ��Ʊ����;Ȩ֤����;ծȯ����
		<< q->TotalAmount << ','			//< �ɽ��ܶ�, ��Ԫ��
		<< q->ClosePrice << ','				//< �����̼�, 
		<< q->SecurityPhaseTag[6] << ','	//< ��ǰƷ�ֽ���״̬,
		<< q->PERatio1 << ','				//< ��ӯ�� 1,6λС��
		<< q->NAV << ','					//< ���� T-1 �վ�ֵ,6λС��
		<< q->PERatio2 << ','				//< ��ӯ�� 2,6λС��
		<< q->IOPV << ','					//< ETF ��ֵ��ֵ,
		<< q->PremiumRate					//< Ȩ֤�����,6λС��
		<< q->TotalSellOrderVolume << ','	//< ί����������, 
		<< q->WtAvgSellPrice << ','			//< ��Ȩƽ��ί����, ��Ԫ��
		<< q->SellLevelNo << ','			//< ������λ�����۸��ɵ����ߣ�
		<< q->SellPrice01 << ','			//< ������, 
		<< q->SellVolume01 << ','			//< ������, 
		<< q->TotalSellOrderNo01 << ','		//< ������ί�б���, 
		<< q->SellPrice02 << ','			//< ������, 
		<< q->SellVolume02 << ','			//< ������, 
		<< q->TotalSellOrderNo02 << ','		//< ������ί�б���,
		<< q->SellLevelQueueNo01 << ',';	//< ��һ����ʾί�б���, Ϊ 0 ��ʾ����ʾ
	double lq;
	//< ��1������, ��Ƶ���ݱ��棬�ȴ涩������,ֻ��һ���д����ݣ�50��������ʱ����
	for (unsigned i = 0; i < ORDER_LEVEL_FIFTY; ++i) {
		lq = (q->SellLevelQueue)[i];
		if (lq > 0)
			m_ofs << lq << ';';
		else
			break;
	}
	m_ofs << ',' << q->TotalBuyOrderVolume << ','//< ί����������, ��Ʊ����;Ȩ֤����;ծȯ����
		<< q->WtAvgBuyPrice << ','			//< ��Ȩƽ��ί���, ��Ԫ��
		<< q->BuyLevelNo << ','				//< ����λ�����۸��ɸ����ͣ�
		<< q->BuyPrice01 << ','				//< �����, 
		<< q->BuyVolume01 << ','			//< ������, ��Ʊ����;Ȩ֤����;ծȯ����
		<< q->TotalBuyOrderNo01 << ','		//< ������ί�б���, 
		<< q->BuyPrice02 << ','				//< �����, 
		<< q->BuyVolume02 << ','			//< ������, 
		<< q->TotalBuyOrderNo02 << ','		//< ������ί�б���,
		<< q->BuyLevelQueueNo01 << ',';		//< ��һ����ʾί�б���, Ϊ 0 ��ʾ����ʾ
	for (unsigned i = 0; i < ORDER_LEVEL_FIFTY; ++i) {
		lq = (q->BuyLevelQueue)[i];
		if (lq > 0)
			m_ofs << lq << ';';
		else
			break;
	}
	m_ofs << ',' << q->WtAvgRate << ','			//< ʵʱ��Ȩƽ������    ��Ѻʽ�ع���Ʒʵʱ�������������ֶ�
		<< q->WtAvgRateUpdown << ','		//< ��Ȩƽ�������ǵ�BP
		<< q->PreWtAvgRate << ',';		//< �����̼�Ȩƽ������
	m_ofs << endl;
}
