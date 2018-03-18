#include "QTSStruct.h"
#include "GtaQh2csv.h"

GtaQh2csv::GtaQh2csv(const string &c)
	:Gta2csv(c) {}

void GtaQh2csv::getFileName(string &strFileName)/*override*/ {
	strFileName = "Quotation.csv";
}

void GtaQh2csv::getHeaders(string &strHeaders)/*override*/ {
	strHeaders = "����,����Դ,��ͷ,����,֤ȯ,����,����,���,���,�ּ�,����,����״̬,Ʒ��״̬,�ɽ�����,�ɽ�����,�ɽ��ܶ�,ί������,��Ȩί���,ծȯ��Ȩί���,ί������,��Ȩί����,ծȯ��Ȩƽ��ί����\
,IOPV,ETF�깺����,ETF�깺��,ETF�깺��,ETF��ر���,ETF�����,ETF��ض�,YTM,Ȩִ֤�е�������,Ȩ֤��ͣ��,Ȩ֤��ͣ��\
,���볷����,���볷����,���볷����,������������,����������,����������,�����ܱ���,�����ܱ���,����ɽ����ȴ�ʱ��,�����ɽ����ȴ�ʱ��,��ί�м�λ��,����ί�м�λ��\
,���̼�λ��,������1,������1,������ί�б���1,������2,������2,������ί�б���2,��һ��ʾί�б���,��1������\
,���̼�λ��,�����1,������1,������ί�б���1, �����2, ������2, ������ί�б���2,��һ����ʾί�б���,��1������,";
}

void GtaQh2csv::writeLine(const void *gtaStruct)/*override*/ {
	const SSEL2_Quotation *q = (const SSEL2_Quotation *)gtaStruct;
	m_ofs << q->LocalTimeStamp << ','		//< ���ݽ���ʱ��HHMMSSMMM
		<< q->QuotationFlag << ','			//< 1=�Ϻ��ϻ��������Դ��2=���ڸ�����������Դ
		<< q->PacketTimeStamp << ','		//< ���ݰ�ͷʱ��YYYYMMDDHHMMSSMMM
		<< q->Time << ','					//< ��������ʱ��, ���¶���ʱ�䣨���룩;143025001 ��ʾ 14:30:25.001
		<< q->Symbol << ','					//< ֤ȯ����, 
		<< q->PreClosePrice << ','			//< ���ռ�, 
		<< q->OpenPrice << ','				//< ���̼�, 
		<< q->HighPrice << ','				//< ��߼�, 
		<< q->LowPrice << ','				//< ��ͼ�, 
		<< q->LastPrice << ','				//< �ּ�, 
		<< q->ClosePrice << ','				//< �����̼�, 
		<< q->TradeStatus[6] << ','			//< ��ǰƷ�ֽ���״̬,
		<< q->SecurityPhaseTag << ','		//< ��ǰƷ��״̬
		<< q->TotalNo << ','				//< �ɽ�����, 
		<< q->TotalVolume << ','			//< �ɽ�����, ��Ʊ����;Ȩ֤����;ծȯ����
		<< q->TotalAmount << ','			//< �ɽ��ܶ�, ��Ԫ��
		<< q->TotalBuyOrderVolume << ','	//< ί����������, ��Ʊ����;Ȩ֤����;ծȯ����
		<< q->WtAvgBuyPrice << ','			//< ��Ȩƽ��ί���, ��Ԫ��
		<< q->BondWtAvgBuyPrice << ','		//< ծȯ��Ȩƽ��ί���, ��Ԫ��
		<< q->TotalSellOrderVolume << ','	//< ί����������, 
		<< q->WtAvgSellPrice << ','			//< ��Ȩƽ��ί����, ��Ԫ��
		<< q->BondWtAvgSellPrice << ','		//< ծȯ��Ȩƽ��ί����, 
		<< q->IOPV << ','					//< ETF ��ֵ��ֵ, 
		<< q->ETFBuyNo << ','				//< ETF �깺����, 
		<< q->ETFBuyVolume << ','			//< ETF �깺��, 
		<< q->ETFBuyAmount << ','			//< ETF �깺��, 
		<< q->ETFSellNo << ','				//< ETF ��ر���, 
		<< q->ETFSellVolume << ','			//< ETF �����, 
		<< q->ETFSellAmount << ','			//< ETF ��ض�, 
		<< q->YTM << ','					//< ծȯ����������, 
		<< q->TotalWarrantExecVol << ','	//< Ȩִ֤�е�������, 
		<< q->WarrantDownLimit << ','		//< Ȩ֤��ͣ�۸�, ��Ԫ��
		<< q->WarrantUpLimit << ','			//< Ȩ֤��ͣ�۸�, ��Ԫ��
		<< q->WithdrawBuyNo << ','			//< ���볷������, 
		<< q->WithdrawBuyVolume << ','		//< ���볷����, 
		<< q->WithdrawBuyAmount << ','		//< ���볷����, 
		<< q->WithdrawSellNo << ','			//< ������������, 
		<< q->WithdrawSellVolume << ','		//< ����������, 
		<< q->WithdrawSellAmount << ','		//< ����������, 
		<< q->TotalBuyNo << ','				//< �����ܱ���, 
		<< q->TotalSellNo << ','			//< �����ܱ���, 
		<< q->MaxBuyDuration << ','			//< ����ɽ����ȴ�ʱ��, 
		<< q->MaxSellDuration << ','		//< �����ɽ����ȴ�ʱ��, 
		<< q->BuyOrderNo << ','				//< ��ί�м�λ��, 
		<< q->SellOrderNo << ','			//< ����ί�м�λ��, 
		<< q->SellLevelNo << ','			//< ���̼�λ����, 10�����飬����ʱ����
		<< q->SellPrice01 << ','			//< ������, 
		<< q->SellVolume01 << ','			//< ������, 
		<< q->TotalSellOrderNo01 << ','		//< ������ί�б���, 
		<< q->SellPrice02 << ','			//< ������, 
		<< q->SellVolume02 << ','			//< ������, 
		<< q->TotalSellOrderNo02 << ','		//< ������ί�б���,
		<< q->SellLevelQueueNo01 << ',';	//< ��һ����ʾί�б���, Ϊ 0 ��ʾ����ʾ
	unsigned lq;
	//< ��1������, ��Ƶ���ݱ��棬�ȴ涩������,ֻ��һ���д����ݣ�50��������ʱ����
	for (unsigned i = 0; i < ORDER_LEVEL_FIFTY; ++i) {
		lq = (q->SellLevelQueue)[i];
		if ( lq > 0)
			m_ofs << lq << ';';
		else
			break;
	}
	m_ofs << ',' <<q->BuyLevelNo << ','		//< ���̼�λ����, 10�����飬����ʱ����
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
	m_ofs << ',' << endl;
}
