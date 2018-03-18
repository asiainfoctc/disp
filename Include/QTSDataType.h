//////////////////////////////////////////////////////////////////////////////
/// @file       QTSDataType.h
/// @brief      QTS���ݸ�ʽ����
/// @copyright  Copyright (C), 2008-2014, GTA Information Tech. Co., Ltd.
/// @version    2.0
/// @date       2014.7.18
//////////////////////////////////////////////////////////////////////////////
#ifndef GTA_QTS_DATA_TYPE_H_
#define GTA_QTS_DATA_TYPE_H_

// ������궨��
#ifdef _WIN32
#define _CDECL         __cdecl
#ifdef GTA_QTS_API_EXPORTS
#define GTA_API_EXPORT __declspec(dllexport)
#else
#define GTA_API_EXPORT __declspec(dllimport)
#endif
#else
#define _CDECL
#define GTA_API_EXPORT
#ifndef __stdcall
#define __stdcall
#endif
#endif

#ifndef NULL
#ifdef __cplusplus
#define NULL    0
#else
#define NULL    ((void *)0)
#endif
#endif

/// ��Ϣ���Ͷ��壬ֵΪunsigned intֵ
enum MsgType
{
    Msg_Unknown                 = 0x00000000,       ///< �������Ϣ����
    Msg_SSEL1_Static            = 0x00101000,       ///< �Ͻ���L1��̬����
    Msg_SSEL1_Quotation         = 0x00101001,       ///< �Ͻ���L1ʵʱ����
    Msg_SSE_IndexPress          = 0x0010100D,       ///< �Ͻ���ָ��ͨ����
    Msg_SSEL2_Static            = 0x00102000,       ///< �Ͻ���L2��̬���� 
    Msg_SSEL2_Quotation         = 0x00102001,       ///< �Ͻ���L2ʵʱ���� UA3202
    Msg_SSEL2_Transaction       = 0x00102002,       ///< �Ͻ���L2��ʳɽ� UA3201
    Msg_SSEL2_Index             = 0x00102003,       ///< �Ͻ���L2ָ������ UA3113
    Msg_SSEL2_Auction           = 0x00102004,       ///< �Ͻ���L2���⼯�Ͼ��� UA3107
    Msg_SSEL2_Overview          = 0x00102005,       ///< �Ͻ���L2�г����� UA3115
    Msg_SSEIOL1_Static          = 0x00103000,       ///< �Ͻ���������Ȩ��̬����
    Msg_SSEIOL1_Quotation       = 0x00103001,       ///< �Ͻ���������Ȩʵʱ���� UA9002
    Msg_SZSEL1_Static           = 0x00201000,       ///< ���L1��̬����
    Msg_SZSEL1_Quotation        = 0x00201001,       ///< ���L1ʵʱ����
    Msg_SZSEL1_Bulletin         = 0x0020100C,       ///< ���L1����
    Msg_SZSEL2_Static           = 0x00202000,       ///< ���L2��̬���� UA101
    Msg_SZSEL2_Quotation        = 0x00202001,       ///< ���L2ʵʱ���� UA103
    Msg_SZSEL2_Transaction      = 0x00202002,       ///< ���L2��ʳɽ� UA202
    Msg_SZSEL2_Index            = 0x00202003,       ///< ���L2ָ������ UA104
    Msg_SZSEL2_Order            = 0x00202006,       ///< ���L2���ί�� UA201
    Msg_SZSEL2_Status           = 0x00202007,       ///< ���L2֤ȯ״̬ UA102
    Msg_CFFEXL2_Static          = 0x00302000,       ///< �н���L2��̬����
    Msg_CFFEXL2_Quotation       = 0x00302001,       ///< �н���L2ʵʱ����
    Msg_SHFEL1_Static           = 0x00401000,       ///< ��������̬����
    Msg_SHFEL1_Quotation        = 0x00401001,       ///< ������ʵʱ����
    Msg_CZCEL1_Static           = 0x00501000,       ///< ֣������̬����
    Msg_CZCEL1_Quotation        = 0x00501001,       ///< ֣����ʵʱ����
    Msg_ESUNNY_Index            = 0x00501003,       ///< ��ʢָ������
    Msg_DCEL1_Static            = 0x00601000,       ///< ������L1��̬����
    Msg_DCEL1_Quotation         = 0x00601001,       ///< ������L1�������
    Msg_DCEL1_ArbiQuotation     = 0x00601008,       ///< ������L1�����������
    Msg_DCEL2_Static            = 0x00602000,       ///< ������L2��̬����
    Msg_DCEL2_Quotation         = 0x00602001,       ///< ������L2�����������
    Msg_DCEL2_ArbiQuotation     = 0x00602008,       ///< ������L2���������������
    Msg_DCEL2_RealTimePrice     = 0x00602009,       ///< ������L2ʵʱ�����
    Msg_DCEL2_OrderStatistic    = 0x0060200A,       ///< ������L2ί��ͳ������
    Msg_DCEL2_MarchPriceQty     = 0x0060200B,       ///< ������L2�ּ۳ɽ�������
    Msg_HKEXL2_Static           = 0x00702000,       ///< �۽���L2��̬����
    Msg_HKEXL2_Quotation        = 0x00702001,       ///< �۽���L2ʵʱ����
    Msg_HKEXL2_Index            = 0x00702003,       ///< �۽���L2ָ������
    Msg_HKEXL2_Overview         = 0x00702005,       ///< �۽���L2�г�����
    Msg_HKEXL2_BrokerQueue      = 0x0070200E,       ///< �۽���L2�����˶���
};
/// ���ݷ��࣬����г����ܺ�ķ���
enum DataCategory
{
    Category_Unknown            =   -1,             ///< ������Ϣ����
    Category_Static             = 0x00,             ///< ��̬����
    Category_Quotation          = 0x01,             ///< ʵʱ����
    Category_Transaction        = 0x02,             ///< ��ʳɽ�
    Category_Index              = 0x03,             ///< ָ������
    Category_Auction            = 0x04,             ///< ���⼯�Ͼ���
    Category_Overview           = 0x05,             ///< �г�����
    Category_Order              = 0x06,             ///< ���ί��
    Category_Status             = 0x07,             ///< ֤ȯ״̬
    Category_ArbiQuotation      = 0x08,             ///< �����������
    Category_RealTimePrice      = 0x09,             ///< ʵʱ�����
    Category_OrderStatistic     = 0x0A,             ///< ί��ͳ������
    Category_MarchPriceQty      = 0x0B,             ///< �ּ۳ɽ�������
};
/// �г����Ͷ���
enum MarketTag
{
    Market_Unknown         = 0,     ///< �����г�
    Market_SSE             = 1,     ///< �Ͻ���
    Market_SZSE            = 2,     ///< ���
    Market_CFFEX           = 3,     ///< �н���
    Market_SHFE            = 4,     ///< ������
    Market_CZCE            = 5,     ///< ֣����
    Market_DCE             = 6,     ///< ������
    Market_HKEX            = 7,     ///< �۽���
};
/// ����״̬����.
enum ConnectState
{
    Connecting                  = 0,    ///< ��������
    Connected                   = 1,    ///< ������
    ConnectClosing              = 2,    ///< ���ڹر�
    ConnectClosed               = 3,    ///< �ѹر�
};
/// ����ֵ�����б�
enum RetCode
{
    Ret_Error                   = -1,   ///< ʧ��
    Ret_Success                 = 0,    ///< �ɹ�
    Ret_NoAddress               = 1,    ///< �������������������ַ
    Ret_NoPermission            = 2,    ///< û��Ȩ�ޣ�����ϵ�ͷ�
    Ret_ParamInvalid            = 3,    ///< ������Ч
    Ret_AccountError            = 4,    ///< �ʺŻ��������
    Ret_AccountOutDate          = 5,    ///< �ʺŲ�����Ч����
    Ret_ConnectFail             = 6,    ///< ����ʧ��
    Ret_LoginRepeat             = 7,    ///< �ʺ��ظ���¼
    Ret_OutTime                 = 8,    ///< ��ʱ
    Ret_CloseConnect            = 9,    ///< ���ӶϿ�
    Ret_OutLimit                = 10,   ///< ���붩������������
    Ret_LowVersion              = 11,   ///< �汾����
};

/// �ֶ�ID����
enum FieldID
{
    FID_ERROR                   = 0,            ///< �����ֶζ��壬�ֶ��ѵ���β
    FID_AuctionOpenPrice        = 1007,         ///< ���⿪�̲ο���. 
    FID_AuctionVolume           = 1009,         ///< ����ƥ����. 
    FID_BondWtAvgBuyPrice       = 1013,         ///< ծȯ��Ȩƽ��ί���. ��Ԫ��
    FID_BondWtAvgSellPrice      = 1014,         ///< ծȯ��Ȩƽ��ί����. 
    FID_BuyLevelNo              = 1015,         ///< ���̼�λ��. "����L2ʵʱ���飺10�����飬����ʱ���գ��Ͻ���������Ȩʵʱ���飺�嵵:����5���յ�λ��0��䡣"
    FID_BuyLevelQueue           = 1016,         ///< ��1������. ��Ƶ���ݱ��棬�ȴ涩������,ֻ��һ���д����ݣ�50��������ʱ����
    FID_BuyOrderID              = 1017,         ///< ��ί������. �� 1 ��ʼ������0 ��ʾ�޶�Ӧί��
    FID_BuyOrderNo              = 1018,         ///< ��ί�м�λ��. 
    FID_BuyPrice01              = 1019,         ///< �����. 3 λС��
    FID_BuyPrice02              = 1020,         ///< �����. 3 λС��
    FID_BuyPrice03              = 1021,         ///< �����. 3 λС��
    FID_BuyPrice04              = 1022,         ///< �����. 3 λС��
    FID_BuyPrice05              = 1023,         ///< �����. 3 λС��
    FID_BuyPrice06              = 1024,         ///< �����. 3 λС��
    FID_BuyPrice07              = 1025,         ///< �����. 3 λС��
    FID_BuyPrice08              = 1026,         ///< �����. 3 λС��
    FID_BuyPrice09              = 1027,         ///< �����. 3 λС��
    FID_BuyPrice10              = 1028,         ///< �����. 3 λС��
    FID_BuyRecID                = 1029,         ///< �򷽶�����. 
    FID_BuySellFlag             = 1030,         ///< �����̱�־. B �C ����,������;S �C ����,������;N �C δ֪
    FID_BuyVolume01             = 1031,         ///< ������. 
    FID_BuyVolume02             = 1032,         ///< ������. 
    FID_BuyVolume03             = 1033,         ///< ������. 
    FID_BuyVolume04             = 1034,         ///< ������. 
    FID_BuyVolume05             = 1035,         ///< ������. 
    FID_BuyVolume06             = 1036,         ///< ������. 
    FID_BuyVolume07             = 1037,         ///< ������. 
    FID_BuyVolume08             = 1038,         ///< ������. 
    FID_BuyVolume09             = 1039,         ///< ������. 
    FID_BuyVolume10             = 1040,         ///< ������. 
    FID_BuyVolumeUnit           = 1041,         ///< ��������λ. �򶩵����걨���������Ǹ��ֶε���������
    FID_CallOrPut               = 1042,         ///< �Ϲ��Ϲ�. C = Call��P = Put
    FID_CFICode                 = 1043,         ///< ֤ȯ���. "�Ͻ�������E'��ʾ��Ʊ����EU����ʾ���𣻡�D����ʾծȯ����RWS����ʾȨ֤����FF����ʾ�ڻ���
                                                ///< �����CFICode��SecuritySubType�����ֶ�ȷ���˲�ͬ��֤ȯ���CFICode��ȡֵΪMRI��EU��ES��D��DC��"
    FID_OutstandingShare        = 1044,         ///< ��ͨ����. 
    FID_ClosePrice              = 1046,         ///< �����̼�. 
    FID_ContractID              = 1047,         ///< ��Լ���״��� . ��Լ���״���17λ��������˳���д��1����1����6λΪ���֣�ȡ���֤ȯ���룬�繤������601398��ȡ��601398����2����7λΪC(Call)����P(Put)���ֱ��ʾ�Ϲ���Ȩ�����Ϲ���Ȩ��3����8��9λ��ʾ������ݣ�4����10��11λ��ʾ�����·ݣ�5����12λ�ڳ���Ϊ��M������ʾ�·ݺ�Լ������Լ�״ε����󣬡�M���޸�Ϊ ��A�����Ա�ʾ�ú�Լ��������һ�Σ��緢���ڶ��ε�������A���޸�Ϊ��B������M���޸�Ϊ ��A�����Դ����ƣ�6����13��17λ��ʾ��Ȩ��Ȩ�۸�.����λ����
    FID_ContractMultiplier      = 1048,         ///< ծȯ�ۺϻع���׼ȯ����. 2 λС��
    FID_ContractMultiplierUnit  = 1049,         ///< ��Լ��λ . ������Ȩ��Ϣ������ĺ�Լ��λ, һ�������� 
    FID_ConversionBeginDate     = 1051,         ///< ��Ȩ��ʼ��. 
    FID_ConversionEndDate       = 1052,         ///< ��Ȩ������. 
    FID_ConversionPrice         = 1053,         ///< ��Ȩ�۸�. 3 λС��
    FID_ConversionRatio         = 1054,         ///< ��Ȩ����. 4 λС��
    FID_CouponRate              = 1055,         ///< Ʊ������. 6 λС��
    FID_CrdBuyStatus            = 1056,         ///< ��ǰ���ʿ���״̬. Y = ����,N = ��ͣ
    FID_CrdBuyUnderlying        = 1057,         ///< ���ʱ�ı�־. "�Ͻ�������T����ʾ�����ʱ��֤ȯ����F����ʾ�������ʱ��֤ȯ��
                                                ///< �����Y= �ǣ�N= ��"
    FID_CrdPriceCheckType       = 1058,         ///< ��ۼ�鷽ʽ. 0=����飬1=����������ɽ��ۣ�2=���������ռۣ�3=��������߽���4=��������ͽ���
    FID_CrdSellStatus           = 1059,         ///< ��ǰ��ȯ����״̬. Y = ����,N = ��ͣ
    FID_CrdSellUnderlying       = 1060,         ///< ��ȯ��ı�־. "�Ͻ�������T����ʾ����ȯ���֤ȯ����F����ʾ������ȯ���֤ȯ��
                                                ///< �����Y= �ǣ�N= ��"
    FID_Currency                = 1061,         ///< ����. HKD����Ԫ USD����Ԫ EUR��ŷԪ JPY����Ԫ GBP��Ӣ�� CAD�����ô�Ԫ SGD���¼���Ԫ CNY������� ��ֵ����ϡ��ɽ���ʹ�á���
    FID_DeliveryDate            = 1062,         ///< ��Ȩ������. ��Ȩ�����գ�Ĭ��Ϊ��Ȩ�յ���һ�������գ�YYYYMMDD
    FID_EndDate                 = 1063,         ///< ������� . ��Ȩ�������/��Ȩ�գ�YYYYMMDD 
    FID_ETFBuyAmount            = 1064,         ///< ETF �깺���. 
    FID_ETFBuyNo                = 1065,         ///< ETF �깺����. 
    FID_ETFBuyVolume            = 1066,         ///< ETF �깺����. 
    FID_ETFSellAmount           = 1067,         ///< ETF ��ؽ��. 
    FID_ETFSellNo               = 1068,         ///< ETF ��ر���. 
    FID_ETFSellVolume           = 1069,         ///< ETF �������. 
    FID_ExerciseDate            = 1070,         ///< ��Ȩ��Ȩ�� . ��Ȩ��Ȩ�գ�YYYYMMDD 
    FID_ExercisePrice           = 1071,         ///< ��Ȩ��Ȩ�� . ������Ȩ��Ϣ���������Ȩ��Ȩ�ۣ��Ҷ��룬��ȷ����;��Ȩ�۸������ȡ�������뷽ʽ����Ʊ������λС����ETF������λС����
    FID_ExpireDate              = 1072,         ///< ��Ȩ������ . ��Ȩ�����գ�YYYYMMDD 
    FID_GageRate                = 1073,         ///< ����Ʒ������. 2 λС��
    FID_HighPrice               = 1074,         ///< ��߼�. 4λС��
    FID_IndustryType            = 1075,         ///< ��ҵ����. 
    FID_InterestAccrualDate     = 1076,         ///< ��Ϣ��. 
    FID_InterruptAuctionPrice   = 1077,         ///< �������жϲο���. 4 decimal places
    FID_InterruptAuctionVolume  = 1078,         ///< �������ж�����ƥ����. ���⼯�Ͼ��۹����У�����Ȩ�ڻ��ļ۸񲨶���̫������Ҫ�ж�һ��ʱ�䣬�жϽ����󣬼���ʹ����һ������Ϊ����ƥ����
    FID_IOPV                    = 1079,         ///< ETF ��ֵ��ֵ. 
    FID_ISINCode                = 1080,         ///< ISIN����. 
    FID_IssuedVolume            = 1082,         ///< �ܷ�����. 
    FID_LastPrice               = 1083,         ///< �ּ�. 4λС��
    FID_LeaveVolume             = 1084,         ///< ����δƥ����. 
    FID_ListingDate             = 1085,         ///< ��������. ���Ͻ������ս������ڣ�YYYYMMDD
    FID_LmtOrdCeiling           = 1086,         ///< �޼��걨���� . �����޼��걨���걨�������ޡ� 
    FID_LmtOrdFloor             = 1087,         ///< �޼��걨���� . �����޼��걨���걨�������ޡ� 
    FID_LowPrice                = 1088,         ///< ��ͼ�. 4λС��
    FID_MarginRatioParam1       = 1089,         ///< ��֤��������һ . ��֤������������λ��% 
    FID_MarginRatioParam2       = 1090,         ///< ��֤���������� . ��֤������������λ��% 
    FID_MarginUnit              = 1091,         ///< ��λ��֤�� . ���ճ���һ�ź�Լ����Ҫ�ı�֤���� ������ȷ���� 
    FID_MarketMakerFlag         = 1095,         ///< �����̱�־. Y = �������̣�N = ��������
    FID_MarketTime              = 1099,         ///< �г�ʱ��. �ٷ�֮һ��
    FID_MarketType              = 1100,         ///< �г�����. ��ASHR����ʾA���г�����BSHR����ʾB���г�����CSHR����ʾ���ʰ��г���
    FID_MaturityDate            = 1101,         ///< ���ڽ�����. 
    FID_MaxBuyDuration          = 1102,         ///< ����ɽ����ȴ�ʱ��. 
    FID_DeclareVolumeCeiling    = 1103,         ///< �걨������. �걨��������
    FID_MaxSellDuration         = 1104,         ///< �����ɽ����ȴ�ʱ��. 
    FID_MessageID               = 1105,         ///< ��Ϣ���. 
    FID_DeclareVolumeFloor      = 1106,         ///< �걨������. �걨��������
    FID_MktOrdCeiling           = 1111,         ///< �м��걨���� . �����м��걨���걨�������ޡ� 
    FID_MktOrdFloor             = 1112,         ///< �м��걨���� . �����м��걨���걨�������ޡ� 
    FID_NameUnderlying          = 1113,         ///< ����֤ȯ���� . 
    FID_NAV                     = 1114,         ///< ����T-1���ۼƾ�ֵ. 4 λС��
    FID_NonTradableNo           = 1116,         ///< ����ͨ����. Ԥ��
    FID_OfferingFlag            = 1117,         ///< ��Ʊ��ҪԼ�չ�;ծȯ�����ȹɣ�ת�ɻ���;Y=��,N=��,��ֵ��ʾ������
    FID_OpenPrice               = 1118,         ///< ���̼�. 4λС��
    FID_OptionType              = 1119,         ///< ��Ȩ����. A= ��ʽ��E = ŷʽ��B = ��Ľ��ʽ
    FID_LocalTimeStamp          = 1120,         ///< �ɼ�ʱ��. ��̩���ڲ��ӵĲɼ�ʱ�䣬���ڲ���ʱ����ȷ������
    FID_OrderCode               = 1121,         ///< ί������������������ ��1=�� 2=�� G=���� F=���� 
    FID_OrderPrice              = 1122,         ///< ί�м۸�. 3λС��
    FID_OrderType               = 1123,         ///< �������.1=�м� 2=�޼� U=��������
    FID_OrderVolume             = 1124,         ///< ί������. 
    FID_PacketTimeStamp         = 1125,         ///< ��ͷʱ��. ��̩���ڲ��ӵİ�ͷʱ�䣬���ڲ���ʱ����ȷ������
    FID_ParValue                = 1128,         ///< ÿ����ֵ. 3 λС��
    FID_PERatio1                = 1129,         ///< ��ӯ�� 1.
    FID_PERatio2                = 1130,         ///< ��ӯ�� 2.
    FID_PreClosePrice           = 1131,         ///< ���ռ�.
    FID_PreClosePriceUnderlying = 1132,         ///< ������ռ� . ��Ȩ���֤ȯ��Ȩ��Ϣ�������ǰ���̼۸��Ҷ��룬��λ��Ԫ 
    FID_PreSettlePrice          = 1133,         ///< �����. ���ս���ۣ��Ҷ��룬��λ��Ԫ ��4 decimal places
    FID_PreYearEPS              = 1134,         ///< ����ÿ������. 4 λС��
    FID_PriceDownLimit          = 1135,         ///< �����۸�. 3 λС��
    FID_TickSize                = 1136,         ///< ��С���۵�λ. "�걨�۸����С�䶯��λ
                                                ///< �Ͻ���������Ȩ����λԪ����ȷ��0.1��"
    FID_UpDownLimitType         = 1138,         ///< �ǵ�����������. ��N����ʾ���׹���3.4.13�涨�����ǵ����������ͻ���Ȩ֤�����취��22���涨����R'��ʾ���׹���3.4.15��3.4.16�涨�����ǵ����������ͣ���S����ʾ�ع��ǵ����������͡�
    FID_PriceUpLimit            = 1139,         ///< �Ƿ��۸�. ����N�����ǵ������ƵĲ�Ʒ�����ֶε��ղ�����ģ�����ǰ���̼ۣ����������н��ײ�ƷΪ���мۣ����㣻����R�������ǵ������ƵĲ�Ʒ�����ֶ�ȡ����ʱ���ڲο��۸��������޼۸�3 λС��
    FID_RecID                   = 1140,         ///< ��Ϣ��¼��.�� 1 ��ʼ������ͬһƵ������
    FID_RedemptionStatus        = 1141,         ///< ��ر�־.������ ETF,LOF �ȿ���ʽ���𣬶��ڻƽ� ETF ��ָ�ֽ���ؿ��ء�Y= ��,N= �񣬿ո�������
    FID_RoundLot                = 1142,         ///< ������ . ���׵�λ��һ�ֵ��ڼ��ź�Լ��
    FID_SecurityEN              = 1143,         ///< Ӣ��֤ȯ����. 
    FID_SecurityName            = 1145,         ///< ֤ȯ����. 
    FID_SecurityPhaseTag        = 1147,         ///< ����״̬.
    FID_SecurityStatus          = 1148,         ///< ��Ʒ״̬��ʶ. ��0λ��Ӧ����N����ʾ�������У���1λ��Ӧ����D����ʾ��Ȩ����2λ��Ӧ����R'��ʾ��Ϣ����3λ��Ӧ����D����ʾ���������������ײ�Ʒ����S����ʾ���վ�ʾ��Ʒ����P����ʾ����������Ʒ��
    FID_SecurityStatusFlag      = 1149,         ///< ��Ȩ��Լ״̬. ���ֶ�Ϊ8λ�ַ���������ÿλ��ʾ�ض��ĺ��壬�޶�������ո񡣵�1λ����0����ʾ�ɿ��֣���1����ʾ�����������֣��������ҿ��֣������뿪�֡���2λ����0����ʾδ����ͣ�ƣ���1����ʾ����ͣ�ơ���3λ����0����ʾδ�ٽ������գ���1����ʾ���뵽���ղ���10�������ա���4λ����0����ʾ����δ����������1����ʾ���10���������ں�Լ��������������5λ����A����ʾ�����¹��Ƶĺ�Լ����E����ʾ�����ĺ�Լ����D����ʾ����ժ�Ƶĺ�Լ��
    FID_SecuritySubType         = 1150,         ///< ֤ȯ�����. "�Ͻ������Զ�����ϸ֤ȯ���
                                                ///< �����SecuritySubType��CFICodeȷ���˲�ͬ��֤ȯ���ȡֵ��ΧΪ��N/A����ֵ��������A��B,AR��BR��G��O��R��AN��AS��"
    FID_SellLevelNo             = 1153,         ///< ���̼�λ��. "�Ͻ���������Ȩʵʱ���飺�嵵:����5���յ�λ��0��䣻
                                                ///< ���L2ʵʱ���顢�Ͻ���L2ʵʱ���飺10�����飬����ʱ����"
    FID_SellLevelQueue          = 1154,         ///< ��1������. ��Ƶ���ݱ��棬�ȴ涩������,ֻ��һ���д����ݣ�50��������ʱ����
    FID_SellOrderID             = 1155,         ///< ����ί������. �� 1 ��ʼ������0 ��ʾ�޶�Ӧί��
    FID_SellOrderNo             = 1156,         ///< ����ί�м�λ��. 
    FID_SellPrice01             = 1157,         ///< ������. 3 λС��
    FID_SellPrice02             = 1158,         ///< ������. 3 λС��
    FID_SellPrice03             = 1159,         ///< ������. 3 λС��
    FID_SellPrice04             = 1160,         ///< ������. 3 λС��
    FID_SellPrice05             = 1161,         ///< ������. 3 λС��
    FID_SellPrice06             = 1162,         ///< ������. 3 λС��
    FID_SellPrice07             = 1163,         ///< ������. 3 λС��
    FID_SellPrice08             = 1164,         ///< ������. 3 λС��
    FID_SellPrice09             = 1165,         ///< ������. 3 λС��
    FID_SellPrice10             = 1166,         ///< ������. 3 λС��
    FID_SellRecID               = 1167,         ///< ����������. 
    FID_SellVolume01            = 1168,         ///< ������. 
    FID_SellVolume02            = 1169,         ///< ������. 
    FID_SellVolume03            = 1170,         ///< ������. 
    FID_SellVolume04            = 1171,         ///< ������. 
    FID_SellVolume05            = 1172,         ///< ������. 
    FID_SellVolume06            = 1173,         ///< ������. 
    FID_SellVolume07            = 1174,         ///< ������. 
    FID_SellVolume08            = 1175,         ///< ������. 
    FID_SellVolume09            = 1176,         ///< ������. 
    FID_SellVolume10            = 1177,         ///< ������. 
    FID_SellVolumeUnit          = 1178,         ///< ��������λ. ��������λ
    FID_SetID                   = 1179,         ///< Ƶ������. 
    FID_SetNo                   = 1180,         ///< ��Ʒ�����. ȡֵ��Χ��1��999,������������Ʒ��һ�ַ��鷽ʽ�������ڶ���������Ը��ؾ�����䡣��ֵ��һ���������ڲ���仯��
    FID_SettlePrice             = 1181,         ///< �����. 4 decimal places
    FID_Side                    = 1183,         ///< ��������. 0=��δƥ�������������ߵ�δƥ������Ϊ 0;1=����δƥ����������δƥ����=0;2=������δƥ��������δƥ����=0
    FID_StartDate               = 1184,         ///< �׸������� . ��Ȩ�׸�������,YYYYMMDD (��*10000+��*100+��)
    FID_StatusID                = 1185,          ///< ֤ȯ����״̬��0�����ֶ������壬���Դ�ֵ  2������ͣ��  3������  ���ֶ������п��ܻ��·���
    FID_SubscribeStatus         = 1186,         ///< �Ϲ���־.���������Ϸ����Ϲ���Y= ��,N= �񣬿ո�������
    FID_Symbol                  = 1187,         ///< ֤ȯ����. 
    FID_SymbolSource            = 1188,         ///< ֤ȯ����Դ. 102=����֤ȯ��������103=��۽�����
    FID_SymbolUnderlying        = 1189,         ///< ����֤ȯ����. 
    FID_TradeAmount             = 1190,         ///< �ɽ����. �ɽ����
    FID_Time                    = 1191,         ///< ��������ʱ��(����)����������TradeCancelFlag=Y
    FID_TotalAmount             = 1192,         ///< �ɽ��ܶ�. Ԫ
    FID_TotalBuyNo              = 1193,         ///< �����ܱ���. 
    FID_TotalBuyOrderVolume     = 1195,         ///< ί����������. ��Ʊ����;Ȩ֤����;ծȯ����
    FID_TotalLongPosition       = 1196,         ///< ��Լδƽ���� . ��λ�� ���ţ� 
    FID_TotalNo                 = 1197,         ///< �ɽ�����. 
    FID_TotalPosition           = 1198,         ///< �ֲ���. 
    FID_TotalSellNo             = 1199,         ///< �����ܱ���. 
    FID_TotalSellOrderVolume    = 1201,         ///< ί����������. 
    FID_TotalVolume             = 1202,         ///< �ɽ�����. "�Ͻ���L2ʵʱ���飺��Ʊ����;Ȩ֤����;ծȯ���֣�
                                                ///< �Ͻ���������Ȩ��Trade volume of this security.�����Ȩ��Լ�Ĳ�Ʒ����Ϊ��00000000�������ʾ�������ڣ���ʽΪYYYYMMDD"
    FID_TotalWarrantExecVol     = 1203,         ///< Ȩִ֤������. 
    FID_TradableMarketNo        = 1204,         ///< ����ͨ����������. Ԥ��
    FID_TradableNo              = 1205,         ///< ����ͨδ��������. Ԥ��
    FID_TradeChannel            = 1206,         ///< �ɽ�ͨ��. 
    FID_TradeCode               = 1207,         ///< �ɽ�����. 
    FID_TradeDate               = 1208,         ///< �г�����. 
    FID_TradePrice              = 1210,         ///< �ɽ��۸�. 3 λС��
                                                ///< 0 = ����ǰ,
                                                ///< 1 = ���̼��Ͼ���,
                                                ///< 2 = �������۽׶�,
                                                ///< 3 = ������ʱͣ��,
                                                ///< 4 = ���̼��Ͼ���,
                                                ///< 5 = ���о��۱���,
                                                ///< 6 = Э��ת�ý���,
                                                ///< 7 = ����
    FID_TradeStatus             = 1212,         ///< ��ǰƷ�ֽ���״̬. 
    FID_TradeTime               = 1213,         ///< �ɽ�ʱ��. 143025006 ��ʾ14:30:25.006
    FID_TradeType               = 1214,         ///< �ɽ�����.4=�������������Զ�����ִ�б��棻F=�ɽ����ɽ�ִ�б���. 
                                                ///< ������Ը۹ɣ������ɽ�����
                                                ///< 0���Զ����̵ķ�˫�߿ͳɽ� (AMS<space>)
                                                ///< 4������ǰ�ɽ�(Off-exchange previous day) (AMS ��P��)
                                                ///< 22�����Զ����̻����ر�������λ�ķ�˫�߿ͳɽ�(AMS ��M��)
                                                ///< 100���Զ����̵�˫�߿ͳɽ�(AMS��Y��)
                                                ///< 101�����Զ����̻����ر�������λ��˫�߿ͳɽ�(AMS ��X��)
                                                ///< 102����ɳɽ�(AMS ��D��)
                                                ///< 103�����۳ɽ� (AMS ��U��)
                                                ///< 104�����⽻��
                                                ///< ��TradeCancelFlag = Yʱ������
    FID_TradeVolume             = 1215,         ///< �ɽ�����. ��Ʊ����;Ȩ֤����;ծȯ���ţ����TradeCancelFlag=Y����ʾδ�ɽ���ʣ����
    FID_UnderlyingType          = 1217,         ///< ���֤ȯ���� . EBS �C ETF�� ASH �C A�� 
    FID_Version                 = 1218,         ///< ��Լ�汾�� . ��Ȩ��Լ�İ汾�š��¹Һ�Լ�ǡ�1�� 
    FID_WarrantClearingType     = 1219,         ///< Ȩ֤���㷽ʽ. S = ֤ȯ���㣬C = �ֽ����
    FID_WarrantDownLimit        = 1221,         ///< Ȩ֤��ͣ��. ��Ԫ��
    FID_WarrantUpLimit          = 1223,         ///< Ȩ֤��ͣ��. ��Ԫ��
    FID_WithdrawBuyAmount       = 1224,         ///< ���볷����. 
    FID_WithdrawBuyNo           = 1225,         ///< ���볷������. 
    FID_WithdrawBuyVolume       = 1226,         ///< ���볷����. 
    FID_WithdrawSellAmount      = 1227,         ///< ����������. 
    FID_WithdrawSellNo          = 1228,         ///< ������������. 
    FID_WithdrawSellVolume      = 1229,         ///< ����������. 
    FID_WtAvgBuyPrice           = 1230,         ///< ��Ȩƽ��ί���. 3 λС����Ԫ��
    FID_WtAvgSellPrice          = 1231,         ///< ��Ȩƽ��ί����. 3 λС����Ԫ��
    FID_XDAmount                = 1232,         ///< ��Ϣ���. ÿ�ɷֺ���
    FID_XRRatio                 = 1233,         ///< ��Ȩ����. ÿ���͹ɱ��������ڹ�ծԤ���в�Ʒ��Ϊ��֤�������
    FID_YearEPS                 = 1235,         ///< ����ÿ������. 4 λС��
    FID_YTM                     = 1236,         ///< ծȯ����������. 
    FID_TotalBuyOrderNo01       = 1251,         ///< ��һ����ί�б���. ���L2������գ�Ϊ 0 ��ʾ����ʾ
    FID_TotalBuyOrderNo02       = 1252,         ///< �������ί�б���. ���L2������գ�Ϊ 0 ��ʾ����ʾ
    FID_TotalBuyOrderNo03       = 1253,         ///< ��������ί�б���. ���L2������գ�Ϊ 0 ��ʾ����ʾ
    FID_TotalBuyOrderNo04       = 1254,         ///< ���ĵ���ί�б���. ���L2������գ�Ϊ 0 ��ʾ����ʾ
    FID_TotalBuyOrderNo05       = 1255,         ///< ���嵵��ί�б���. ���L2������գ�Ϊ 0 ��ʾ����ʾ
    FID_TotalBuyOrderNo06       = 1256,         ///< ��������ί�б���. ���L2������գ�Ϊ 0 ��ʾ����ʾ
    FID_TotalBuyOrderNo07       = 1257,         ///< ���ߵ���ί�б���. ���L2������գ�Ϊ 0 ��ʾ����ʾ
    FID_TotalBuyOrderNo08       = 1258,         ///< ��˵���ί�б���. ���L2������գ�Ϊ 0 ��ʾ����ʾ
    FID_TotalBuyOrderNo09       = 1259,         ///< ��ŵ���ί�б���. ���L2������գ�Ϊ 0 ��ʾ����ʾ
    FID_TotalBuyOrderNo10       = 1260,         ///< ��ʮ����ί�б���. ���L2������գ�Ϊ 0 ��ʾ����ʾ
    FID_TotalSellOrderNo01      = 1261,         ///< ��һ����ί�б���. Ϊ 0 ��ʾ����ʾ
    FID_TotalSellOrderNo02      = 1262,         ///< ��������ί�б���. Ϊ 0 ��ʾ����ʾ
    FID_TotalSellOrderNo03      = 1263,         ///< ��������ί�б���. Ϊ 0 ��ʾ����ʾ
    FID_TotalSellOrderNo04      = 1264,         ///< ���ĵ���ί�б���. Ϊ 0 ��ʾ����ʾ
    FID_TotalSellOrderNo05      = 1265,         ///< ���嵵��ί�б���. Ϊ 0 ��ʾ����ʾ
    FID_TotalSellOrderNo06      = 1266,         ///< ��������ί�б���. Ϊ 0 ��ʾ����ʾ
    FID_TotalSellOrderNo07      = 1267,         ///< ���ߵ���ί�б���. Ϊ 0 ��ʾ����ʾ
    FID_TotalSellOrderNo08      = 1268,         ///< ���˵���ί�б���. Ϊ 0 ��ʾ����ʾ
    FID_TotalSellOrderNo09      = 1269,         ///< ���ŵ���ί�б���. Ϊ 0 ��ʾ����ʾ
    FID_TotalSellOrderNo10      = 1270,         ///< ��ʮ����ί�б���. Ϊ 0 ��ʾ����ʾ
    FID_SellLevelQueueNo01      = 1271,         ///< ��һ����ʾί�б���. Ϊ 0 ��ʾ����ʾ
    FID_BuyLevelQueueNo01       = 1272,         ///< ��һ����ʾί�б���. Ϊ 0 ��ʾ����ʾ
    FID_PreTotalPosition        = 1092,         ///< ��ֲ���
    FID_PreDelta                = 1093,         ///< ����ʵ��
    FID_Delta                   = 1094,         ///< ����ʵ��
    FID_SettleGroupID           = 1096,         ///< ���������
    FID_SettleID                = 1097,         ///< ������
    /// QTS2.2���Ӳ��֣�����L1�����ֶ�
    FID_PriceUpdown1            = 1282,         ///< �ǵ�1. LastPrice-PreClosePrice
    FID_PriceUpdown2            = 1200,         ///< �ǵ�2. LastPrice-��һ��LastPrice,���ڵ���ĵ�һ�ʳɽ������ֶ�=LastPrice-PreClosePrice
    /// QTS2.2���Ӳ��֣��Ϻ�L2��̬���ݲ����ֶ�
    FID_SampleNo                = 1273,         ///< ��������.UINT32.ָ����ǰ����������
    FID_SampleAvgPrice          = 1274,         ///< ��������.int64.ָ����ǰ�����ľ���,�м���ֵ/���йɱ�,����ָ�겻ͳ������� N/A
    FID_AvgCapital              = 1275,         ///< ƽ���ɱ�.UINT64.ָ����ǰ������ƽ���ɱ�,������ƽ������λ���ڹɣ�,����ָ�겻ͳ������� N/A
    FID_TotalMarketValue        = 1276,         ///< ����ֵ.UINT64.ָ����ǰ����������ֵ���� �������ͣ� ��λ�� ����Ԫ��,����ָ�겻ͳ������� N/A
    FID_MarketValueRatio        = 1277,         ///< ռ��%.int64.ָ����ǰ����������ֵռ��֤��ָȫ����������ֵ,�ٷֱ�,����ָ�겻ͳ������� N/A
    FID_StaticPERatio           = 1278,         ///< ��̬��ӯ��.UINT64.ָ����ǰ�����ľ�̬��ӯ�ʡ���ʽ���ϼƣ���������̼�*�������� /�ϼƣ�ÿ������*��������,����ָ��δͳ������� N/A
    FID_IndexLevelStatus        = 1279,         ///< ָ�������ʶ.string(20).ǰ 5 λΪָ��������ֵ�����һλ��ָ��������Ϣ��,1 Ϊ�ص�ָ��;2 Ϊȫòָ��;�����ɸ�����Ҫ��չ��
    FID_QuotationFlag           = 1280,         ///< ����Դ��־�����ֶ�Ϊ4λ�ַ�����ÿλ��ʾ�ض��ĺ��壬�޶�������ո� ��1λ��Ӧ����1����ʾ���Ϻ���������Դ����2����ʾ���ڻ�������Դ
    FID_AutoSplitDate           = 1283,         ///< ��ֱ�۲���ϲ��Ե��ڽ������.�����ڱ�ʾ��ֱ�۲���ϲ��Ե��ڽ�������ڣ�YYYYMMDD��   ����E-2�󲨶��ӹҵĺ�Լ�����ֶ���ΪE-2�ա������յ���ʱ�����ֶ���Ϣ�Զ�ͬ��������
    FID_ParseFileFlag           = 1284,         ///< �ڲ�ʹ�á��Ͻ���L2��̬�����ļ�������־�����SSEL2StaticFilter����
    /// QTS2.3���Ӳ��֣����L2������Ϣ���Ͳ����ֶ�
    FID_ExerciseStatus          = 1343,         ///< Ȩ֤��־�������ڴ�����Ȩ�ڵ�Ȩ֤��1= ��,0=�񣬿ո�������
    FID_FinancialStatus         = 1345,         ///< ֤ȯ״̬��Ϣ��A=���й�˾�����¶��ʾ��B=���й�˾�����¶��ʾ��ÿ���ֽڽ�ʾһ��״̬������ͬʱ��ʾ����״̬
    FID_PurchasingStatus        = 1348,         ///< �Ϲ���־�����������Ϸ����Ϲ�����1= ��,0= �񣬿ո�������
    FID_StockDiviStatus         = 1349,         ///< ת�ɱ�־�������ڴ���ת�ɻ����ڵĿ�תծ��1= ��,0= �񣬿ո�������
    FID_PutableStatus           = 1350,         ///< ���۱�־�������ڴ���ת�ɻ����ڵĿ�תծ��1= ��,0= �񣬿ո�������
    FID_AcceptedStatus          = 1351,         ///< Ԥ��ҪԼ��־�������ڴ���ҪԼ�չ��ڵĹ�Ʊ��1= ��,0= �񣬿ո�������
    FID_ReleaseStatus           = 1352,         ///< ���ҪԼ��־ �������ڴ���ҪԼ�չ��ڵĹ�Ʊ��1= ��,0= �񣬿ո�������
    FID_CancStockDiviStatus     = 1353,         ///< ת�ɳ�����־�������ڴ���ת�ɻ����ڵĿ�תծ��1= ��,0= �񣬿ո�������
    FID_CancPutableStatus       = 1354,         ///< ���۳�����־ �������ڴ���ת�ɻ����ڵĿ�תծ��1= ��,0= �񣬿ո�������
    FID_PledgeStatus            = 1355,         ///< ��Ѻ��־����������Ѻʽ�ع�����Ѻ���֤ȯ��1= ��,0= �񣬿ո�������
    FID_RemovePledge            = 1356,         ///< ��Ѻ��־����������Ѻʽ�ع�����Ѻ���֤ȯ��1= ��,0= �񣬿ո�������
    FID_VoteStatus              = 1357,         ///< ����Ȩ��־�����������ȹɡ�1= ��,0= �񣬿ո�������
    FID_StockPledgeRepo         = 1358,         ///< ��Ʊ��Ѻʽ�ع���־�������ڿɿ�չ��Ʊ��Ѻʽ�ع�ҵ���֤ȯ��1= ��,0= �񣬿ո�������
    FID_DivideStatus            = 1359,         ///< ʵʱ�ֲ��־�������ڷּ�����1= ��,0= �񣬿ո�������
    FID_MergerStatus            = 1360,         ///< ʵʱ�ϲ���־�������ڷּ�����1= ��,0= �񣬿ո�������
    FID_UnderlyingSecurityIDSource = 1361,      ///< ����֤ȯ����Դ��102 = ����֤ȯ������
    FID_SecurityType            = 1362,         ///< ֤ȯ�����롣1���� A�ɣ� 2��С���Ʊ��3��ҵ���Ʊ��4���� B�ɣ�5��ծ �����ط�ծ����6��ҵծ��7��˾ծ��8��תծ��9˽ļծ��10�ɽ���˽ļծ��11֤ȯ��˾�μ�ծ��12��Ѻʽ�ع���13�ʲ�֧��֤ȯ��14���г���ƱETF��15���г�ETF��16�羳ETF��17���г�ʵ��ծȯETF��18�ֽ�ծȯETF��19�ƽ�ETF��20����ETF��21��Ԥ�����ܸ�ETF;22(Ԥ��)��Ʒ�ڻ�ETF��23��׼LOF;24�ּ��ӻ���25���ʽ����26���������28Ȩ֤��29������Ȩ��30ETF��Ȩ��33���ȹɣ�34֤ȯ��˾����ծ��35�ɽ�����˾ծ
    FID_DayTrading              = 1363,         ///< ��ת���ױ�־���Ƿ�֧�ֵ��ջ�ת���ף�Y=֧�֣�N=��֧��
    FID_SecurityStatusTag       = 1364,         ///< ֤ȯ״̬��ʶ�����ֶ�Ϊ14λ�ַ�������ÿλ��ʾ�ض��ĺ��壬�޶�������ո񡣵�1λ��Ӧ����1����ʾͣ�ƣ���2λ��Ӧ����1����ʾ��Ȩ����3λ��Ӧ����1����ʾ��Ϣ����4λ��Ӧ����1����ʾST;��5λ��Ӧ����1����ʾ*ST;��6λ��Ӧ����1����ʾ�������գ���7λ��Ӧ����1����ʾ��˾�����ʣ���8λ��Ӧ����1����ʾ�ָ��������գ���9λ��Ӧ����1����ʾ����ͶƱ����10λ��Ӧ����1����ʾ���������ڣ���12λ��Ӧ����1����ʾ�����ɷ����У���13λ��Ӧ����1����ʾ��Լ��������14λ��Ӧ����1����ʾ��ͣ���к�Э��ת�á�          
    FID_GageFlag                = 1365,         ///< ��֤��֤ȯ��־���Ƿ����Ϊ������ȯ�ɳ�ֱ�֤��֤ȯ��Y=�ǣ�N=��
    FID_PledgeFlag              = 1366,         ///< ��Ѻ����־���Ƿ����Ѻ���:Y=�ǣ�N=��
    FID_RegularShare            = 1367,         ///< ��Ӧ�ع���׼ȯ��
    FID_QualificationFlag       = 1368,         ///< Ͷ�����ʵ��Թ�����־���Ƿ���Ҫ�Ը�֤ȯ��Ͷ�����ʵ��Թ�����Y=�ǣ�N=��
    FID_IssuePrice              = 1369,         ///< ���ַ��мۡ���4λС��
    FID_Interest                = 1370,         ///< ÿ��ԪӦ����Ϣ��8λС�������ȹɣ�0.0000 ��ʾ������Ϣ��
    FID_ExpirationDays          = 1371,         ///< �������ޡ�
    FID_LimitUpRateO            = 1372,         ///< ���̼��Ͼ������Ƿ��ȣ�3λС��
    FID_LimitDownRateO          = 1373,         ///< ���̼��Ͼ����µ����ȣ�3λС��
    FID_LimitUpAbsoluteO        = 1374,         ///< ���̼��Ͼ��������޼ۣ�4λС��
    FID_LimitDownAbsoluteO      = 1375,         ///< ���̼��Ͼ����µ��޼ۣ�4λС��
    FID_AuctionUpDownRateO      = 1376,         ///< ���̼��Ͼ�����Ч��Χ�ǵ����ȣ�3λС��
    FID_AuctionUpDownAbsoluteO  = 1377,         ///< ���̼��Ͼ�����Ч��Χ�ǵ��۸�4λС��
    FID_LimitUpRateT            = 1378,         ///< �����������Ƿ��ȣ�3λС��
    FID_LimitDownRateT          = 1379,         ///< ���������µ����ȣ�3λС��
    FID_LimitUpAbsoluteT        = 1394,         ///< �������������޼ۣ�4λС��
    FID_LimitDownAbsoluteT      = 1395,         ///< ���������µ��޼ۣ�4λС��
    FID_AuctionUpDownRateT      = 1380,         ///< ����������Ч��Χ�ǵ����ȣ�3λС��
    FID_AuctionUpDownAbsoluteT  = 1381,         ///< ����������Ч��Χ�ǵ��۸�4λС��
    FID_LimitUpRateC            = 1382,         ///< ���̼��Ͼ������Ƿ��ȣ�3λС��
    FID_LimitDownRateC          = 1383,         ///< ���̼��Ͼ����µ����ȣ�3λС��
    FID_LimitUpAbsoluteC        = 1384,         ///< ���̼��Ͼ��������޼ۣ�4λС��
    FID_LimitDownAbsoluteC      = 1385,         ///< ���̼��Ͼ����µ��޼ۣ�4λС��
    FID_AuctionUpDownRateC      = 1386,         ///< ���̼��Ͼ�����Ч��Χ�ǵ����ȣ�3λС��
    FID_AuctionUpDownAbsoluteC  = 1387,         ///< ���̼��Ͼ�����Ч��Χ�ǵ��۸�4λС��
    FID_BuyQtyUpperLimit        = 1388,         ///< ���������ޡ���ί�����������ޣ�2λС��
    FID_SellQtyUpperLimit       = 1389,         ///< ���������ޡ���ί�����������ޣ�2λС��
    FID_PremiumRate             = 1391,         ///< Ȩ֤����ʡ�6λС��
    FID_GoldPurchase            = 1392,         ///< �ƽ�ETFʵ���깺��־�������ڻƽ�ETFʵ���깺��Y= ��,N= �񣬿ո�������
    FID_GoldRedemption          = 1393,         ///< �ƽ�ETFʵ����ر�־�������ڻƽ�ETFʵ����ء�Y= ��,N= �񣬿ո�������
    FID_ClearingPrice           = 1396,         ///< ����۸�������Ȩ֤��4λС��
    /// QTS2.5���Ӳ���,�Ͻ���ָ��ͨ
    FID_ActionDay               = 1285,         ///< ҵ������,�����ļ�����������Ȼ���ڣ�����ʱ�䣩������Ϊ�����ڼ�����������Ȼ���ڣ�����ʱ�䣩
    FID_UpDownRate              = 1286,         ///< �ǵ���
    FID_ExchangeRate            = 1329,         ///< ���ʣ��û���������ʱΪ0.00000000�����̺󣬸û���ֵΪ��ָ������ʱ����ָ����ʹ�õĻ���
    FID_DisplayNum              = 1344,         ///< ָ��չʾ���,չʾָ����˳��ָ��չʾ��Ž������С�
    FID_ClosePrice2             = 1346,         ///< ��������ֵ2������ָ��Ϊȫ��ָ����������ֵΪ������̫������ֵ����ʼֵΪ0.0000����ֵ��Ϊ0.0000ʱ��˵��ָ����̫��������
    FID_ClosePrice3             = 1347,         ///< ��������ֵ3������ָ��Ϊȫ��ָ����������ֵΪ����ŷ��������ֵ����ʼֵΪ0.0000����ֵ��Ϊ0.0000ʱ��˵��ָ��ŷ����������

    /// QTS2.6���Ӳ���,��������֣��������ʢָ��
    FID_InterestChg             = 1287,         ///< �ֲ����仯
    FID_LifeHigh                = 1288,         ///< ��ʷ��߳ɽ��۸�
    FID_LifeLow                 = 1289,         ///< ��ʷ��ͳɽ��۸�
    FID_ClearPrice              = 1290,         ///< ���ս�������
    FID_AveragePrice            = 1291,         ///< ����
    FID_Gamma                   = 1293,         ///< Gamma
    FID_Rho                     = 1294,         ///< Rho
    FID_Theta                   = 1295,         ///< Theta
    FID_Vega                    = 1296,         ///< Vega
    FID_DeriveBidPrice          = 1297,         ///< ��������
    FID_DeriveAskPrice          = 1298,         ///< ���������
    FID_DeriveBidLot            = 1299,         ///< �����������
    FID_DeriveAskLot            = 1300,         ///< �����������
    FID_LastLot                 = 1398,         ///< ���һ�ʳɽ�����
                                  
    FID_MBLQuotBuyNum           = 1301,         ///< �������������
    FID_MBLQuotSellNum          = 1302,         ///< �������������
    FID_Price01                 = 1303,         ///< �۸�1
    FID_PriceBOQty01            = 1304,         ///< ������01
    FID_PriceBEQty01            = 1305,         ///< ��ƽ����01
    FID_PriceSOQty01            = 1306,         ///< ��������01
    FID_PriceSEQty01            = 1307,         ///< ��ƽ����01
    FID_Price02                 = 1308,         ///< �۸�2
    FID_PriceBOQty02            = 1309,         ///< ������02
    FID_PriceBEQty02            = 1310,         ///< ��ƽ����02
    FID_PriceSOQty02            = 1311,         ///< ��������02
    FID_PriceSEQty02            = 1312,         ///< ��ƽ����02
    FID_Price03                 = 1313,         ///< �۸�3
    FID_PriceBOQty03            = 1314,         ///< ������03
    FID_PriceBEQty03            = 1315,         ///< ��ƽ����03
    FID_PriceSOQty03            = 1316,         ///< ��������03
    FID_PriceSEQty03            = 1317,         ///< ��ƽ����03
    FID_Price04                 = 1318,         ///< �۸�4
    FID_PriceBOQty04            = 1319,         ///< ������04
    FID_PriceBEQty04            = 1320,         ///< ��ƽ����04
    FID_PriceSOQty04            = 1321,         ///< ��������04
    FID_PriceSEQty04            = 1322,         ///< ��ƽ����04
    FID_Price05                 = 1323,         ///< �۸�5
    FID_PriceBOQty05            = 1324,         ///< ������05
    FID_PriceBEQty05            = 1325,         ///< ��ƽ����05
    FID_PriceSOQty05            = 1326,         ///< ��������05
    FID_PriceSEQty05            = 1327,         ///< ��ƽ����05
    FID_RoutineNo               = 1328,         ///< ������
                                  
    FID_BidImplyQty01           = 1330,         ///< �����Ƶ���һ
    FID_BidImplyQty02           = 1331,         ///< �����Ƶ�����
    FID_BidImplyQty03           = 1332,         ///< �����Ƶ�����
    FID_BidImplyQty04           = 1333,         ///< �����Ƶ�����
    FID_BidImplyQty05           = 1334,         ///< �����Ƶ�����
    FID_AskImplyQty01           = 1335,         ///< �����Ƶ���һ
    FID_AskImplyQty02           = 1336,         ///< �����Ƶ�����
    FID_AskImplyQty03           = 1337,         ///< �����Ƶ�����
    FID_AskImplyQty04           = 1338,         ///< �����Ƶ�����
    FID_AskImplyQty05           = 1339,         ///< �����Ƶ�����
                                  
    FID_LastMatchQty            = 1341,         ///< ���³ɽ���
                                  
    // 2.6.4 ���������ֶ�         
    FID_WtAvgRate               = 1399,         ///< ʵʱ��Ȩƽ������
    FID_WtAvgRateUpdown         = 1400,         ///< ��Ȩƽ�������ǵ�BP
    FID_PreWtAvgRate            = 1401,         ///< �����̼�Ȩƽ������
    FID_QualificationClass      = 1402,         ///< Ͷ�����ʵ��Թ�������

    // 2.7 �۹���Ҫ���ӵ��ֶ�
    FID_ChannelID               = 1453,         ///< �ŵ�ID
    FID_SpreadTableCode         = 1413,         ///< ֤ȯ�۲��,'01'��Part A  '02'��Part B
    FID_SecurityNameGCCS        = 1414,         ///< ֤ȯ���Ƶķ������ı��룬UTF8����
    FID_SecurityNameGB          = 1415,         ///< ֤ȯ���Ƶļ������ı��룬UTF8����
    FID_VCMFlag                 = 1416,         ///< VCM���֤ȯ��־��Y��������VCM  N����������VCM
    FID_ShortSellFlag           = 1417,         ///< ������Ȩ��־��Y����������  N������������
    FID_CASFlag                 = 1418,         ///< CAS���֤ȯ��Y��������CAS  N����������CAS
    FID_CCASSFlag               = 1419,         ///< �������֤ȯ��Y���������֤ȯ  N�����������֤ȯ
    FID_DummySecurityFlag       = 1420,         ///< ����֤ȯ��־��Y������֤ȯ  N������֤ȯ
    FID_TestSecurityFlag        = 1421,         ///< ����֤ȯ��־��Y������֤ȯ  N������֤ȯ
    FID_StampDutyFlag           = 1422,         ///< ӡ��˰��־��Y����Ҫӡ��˰  N������Ҫӡ��˰
    FID_FreeText                = 1423,         ///< �����ı����̶����ȵ�����. ��û�������ĵ�ʱ�ɿո����
    FID_EFNFlag                 = 1424,         ///< ������ծȯ��־��Y����������ծȯ  N������������ծȯ
    FID_AccruedInterest         = 1425,         ///< Ӧ����Ϣ��3λС��
    FID_StrikePrice             = 1426,         ///< ִ�м۸�3λС��
    FID_BasicCurrency           = 1431,         ///< HKD����Ԫ USD����Ԫ EUR��ŷԪ JPY����Ԫ GBP��Ӣ�� CAD�����ô�Ԫ SGD���¼���Ԫ CNY�������
    //FID_CallOrPut               = 1042,         ///< �Ϲ��Ϲ���־����������Ȩ֤�Լ�һ����Ȩ֤��C �Ϲ���P�Ϲ���O���������ڹ�Ʊ�ҹ�Ʊ�ݡ�ţ��֤��C ���ǣ�P���� 
    FID_NoUnderlyingSecurities  = 1428,         ///< ���֤ȯ��Ŀ��0-20��һ�����Ϲ�Ȩ֤��0-1����Ȩ֤�ͽṹ�Բ�Ʒ
    FID_UnderlyingSecurityCode01 = 1541,        ///< ���֤ȯ����
    FID_UnderlyingSecurityCode02 = 1542,        ///< ���֤ȯ����
    FID_UnderlyingSecurityCode03 = 1543,        ///< ���֤ȯ����
    FID_UnderlyingSecurityCode04 = 1544,        ///< ���֤ȯ����
    FID_UnderlyingSecurityCode05 = 1545,        ///< ���֤ȯ����
    FID_UnderlyingSecurityCode06 = 1546,        ///< ���֤ȯ����
    FID_UnderlyingSecurityCode07 = 1547,        ///< ���֤ȯ����
    FID_UnderlyingSecurityCode08 = 1548,        ///< ���֤ȯ����
    FID_UnderlyingSecurityCode09 = 1549,        ///< ���֤ȯ����
    FID_UnderlyingSecurityCode10 = 1550,        ///< ���֤ȯ����
    FID_UnderlyingSecurityCode11 = 1551,        ///< ���֤ȯ����
    FID_UnderlyingSecurityCode12 = 1552,        ///< ���֤ȯ����
    FID_UnderlyingSecurityCode13 = 1553,        ///< ���֤ȯ����
    FID_UnderlyingSecurityCode14 = 1554,        ///< ���֤ȯ����
    FID_UnderlyingSecurityCode15 = 1555,        ///< ���֤ȯ����
    FID_UnderlyingSecurityCode16 = 1556,        ///< ���֤ȯ����
    FID_UnderlyingSecurityCode17 = 1557,        ///< ���֤ȯ����
    FID_UnderlyingSecurityCode18 = 1558,        ///< ���֤ȯ����
    FID_UnderlyingSecurityCode19 = 1559,        ///< ���֤ȯ����
    FID_UnderlyingSecurityCode20 = 1560,        ///< ���֤ȯ����
    FID_UnderlyingSecurityWeight01 = 1561,        ///< ���֤ȯ����Ȩ��
    FID_UnderlyingSecurityWeight02 = 1562,        ///< ���֤ȯ����Ȩ��
    FID_UnderlyingSecurityWeight03 = 1563,        ///< ���֤ȯ����Ȩ��
    FID_UnderlyingSecurityWeight04 = 1564,        ///< ���֤ȯ����Ȩ��
    FID_UnderlyingSecurityWeight05 = 1565,        ///< ���֤ȯ����Ȩ��
    FID_UnderlyingSecurityWeight06 = 1566,        ///< ���֤ȯ����Ȩ��
    FID_UnderlyingSecurityWeight07 = 1567,        ///< ���֤ȯ����Ȩ��
    FID_UnderlyingSecurityWeight08 = 1568,        ///< ���֤ȯ����Ȩ��
    FID_UnderlyingSecurityWeight09 = 1569,        ///< ���֤ȯ����Ȩ��
    FID_UnderlyingSecurityWeight10 = 1570,        ///< ���֤ȯ����Ȩ��
    FID_UnderlyingSecurityWeight11 = 1571,        ///< ���֤ȯ����Ȩ��
    FID_UnderlyingSecurityWeight12 = 1572,        ///< ���֤ȯ����Ȩ��
    FID_UnderlyingSecurityWeight13 = 1573,        ///< ���֤ȯ����Ȩ��
    FID_UnderlyingSecurityWeight14 = 1574,        ///< ���֤ȯ����Ȩ��
    FID_UnderlyingSecurityWeight15 = 1575,        ///< ���֤ȯ����Ȩ��
    FID_UnderlyingSecurityWeight16 = 1576,        ///< ���֤ȯ����Ȩ��
    FID_UnderlyingSecurityWeight17 = 1577,        ///< ���֤ȯ����Ȩ��
    FID_UnderlyingSecurityWeight18 = 1578,        ///< ���֤ȯ����Ȩ��
    FID_UnderlyingSecurityWeight19 = 1579,        ///< ���֤ȯ����Ȩ��
    FID_UnderlyingSecurityWeight20 = 1580,        ///< ���֤ȯ����Ȩ��
    FID_NoLiquidityProviders    = 1430,         ///< ��������Ŀ��1-50
    FID_LPBrokerNumber01        = 1581,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber02        = 1582,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber03        = 1583,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber04        = 1584,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber05        = 1585,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber06        = 1586,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber07        = 1587,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber08        = 1588,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber09        = 1589,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber10        = 1590,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber11        = 1591,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber12        = 1592,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber13        = 1593,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber14        = 1594,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber15        = 1595,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber16        = 1596,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber17        = 1597,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber18        = 1598,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber19        = 1599,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber20        = 1600,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber21        = 1601,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber22        = 1602,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber23        = 1603,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber24        = 1604,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber25        = 1605,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber26        = 1606,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber27        = 1607,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber28        = 1608,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber29        = 1609,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber30        = 1610,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber31        = 1611,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber32        = 1612,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber33        = 1613,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber34        = 1614,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber35        = 1615,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber36        = 1616,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber37        = 1617,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber38        = 1618,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber39        = 1619,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber40        = 1620,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber41        = 1621,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber42        = 1622,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber43        = 1623,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber44        = 1624,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber45        = 1625,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber46        = 1626,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber47        = 1627,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber48        = 1628,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber49        = 1629,         ///< �����̾�������Ŀ
    FID_LPBrokerNumber50        = 1630,         ///< �����̾�������Ŀ
    FID_Yield                   = 1432,         ///< ծȯ���������ʣ�����ϢƱ�ʺ�����۸�3λС��
    FID_NominalPrice            = 1434,         ///< ���̼ۣ�3λС��
    FID_VWAP                    = 1435,         ///< �ɽ�����Ȩƽ���۸�3λС��
    FID_ShortSellSharesTraded   = 1436,         ///< ���ճɽ�����
    FID_ShortSellTurnover       = 1437,         ///< ���ճɽ���3λС��
    FID_TradeCancelFlag         = 1433,         ///< �����Ƿ�ȡ����־��Y��ȡ��  N��û��ȡ��  ָʾ��ԭ��������¼���еĽ����Ѿ���ȡ����
    FID_AggregatePrice          = 1438,         ///< �ο�ƽ��۸�3λС����IEP������ʱȡֵΪ0
    FID_AggregateQuantity       = 1439,         ///< �ο�ƽ��ɽ���
    FID_CASReferencePrice       = 1440,         ///< ί�ж����ο��۸�CAS�׶Σ���3λС��������ο��۲����ã�ȡֵΪ0
    FID_CASLowerPrice           = 1441,         ///< ί�ж����ο��۸�CAS�׶Σ���3λС����ȡֵ0��ʾN/A
    FID_CASUpperPrice           = 1442,         ///< ί�ж������޼۸�CAS�׶Σ���3λС����ȡֵ0��ʾN/A
    FID_OrderImbalanceDirection = 1443,         ///< ����������ƽ�ⷽ��N��������� B����ʣ�� S������ʣ�� �ո񣺲����ã����ο�ƽ��۲�����
    FID_OrderImbalanceQuantity  = 1444,         ///< ������ƽ������������ƽ�ⷽ��OrderImbalanceDirectionΪ�ո񣬴�ֵ������
    FID_CoolingOffStartTime     = 1445,         ///< �侲�ڿ�ʼʱ�䣬����������ʱ��ΪUTC��ʽ��ת����datetime��ʽ��YYYYMMDDHHMMSSsss
    FID_CoolingOffEndTime       = 1446,         ///< �侲�ڽ���ʱ�䣬����������ʱ��ΪUTC��ʽ��ת����datetime��ʽ��YYYYMMDDHHMMSSsss
    FID_VCMReferencePrice       = 1447,         ///< �侲�ڲο��ۣ�3λС��
    FID_VCMLowerPrice           = 1448,         ///< �侲�ڿɽ��׼۸����ޣ�3λС��
    FID_VCMUpperPrice           = 1449,         ///< �侲�ڿɽ��׼۸����ޣ�3λС��
    FID_BuyBQMoreFlag           = 1452,         ///< �򷽾����˶��б�־��Y�������л��о����� N����������û�о�����
    FID_BuyBQItemCount          = 1450,         ///< �򷽾����˶�����0-40
    FID_BuyBrokerID01           = 1454,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID02           = 1455,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID03           = 1456,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID04           = 1457,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID05           = 1458,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID06           = 1459,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID07           = 1460,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID08           = 1461,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID09           = 1462,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID10           = 1463,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID11           = 1464,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID12           = 1465,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID13           = 1466,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID14           = 1467,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID15           = 1468,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID16           = 1469,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID17           = 1470,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID18           = 1471,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID19           = 1472,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID20           = 1473,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID21           = 1474,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID22           = 1475,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID23           = 1476,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID24           = 1477,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID25           = 1478,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID26           = 1479,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID27           = 1480,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID28           = 1481,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID29           = 1482,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID30           = 1483,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID31           = 1484,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID32           = 1485,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID33           = 1486,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID34           = 1487,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID35           = 1488,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID36           = 1489,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID37           = 1490,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID38           = 1491,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID39           = 1492,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBrokerID40           = 1493,         ///< �򷽾����˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_BuyBQPriceLevel01       = 1494,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel02       = 1495,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel03       = 1496,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel04       = 1497,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel05       = 1498,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel06       = 1499,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel07       = 1500,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel08       = 1501,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel09       = 1502,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel10       = 1503,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel11       = 1504,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel12       = 1505,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel13       = 1506,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel14       = 1507,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel15       = 1508,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel16       = 1509,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel17       = 1510,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel18       = 1511,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel19       = 1512,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel20       = 1513,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel21       = 1514,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel22       = 1515,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel23       = 1516,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel24       = 1517,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel25       = 1518,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel26       = 1519,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel27       = 1520,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel28       = 1521,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel29       = 1522,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel30       = 1523,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel31       = 1524,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel32       = 1525,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel33       = 1526,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel34       = 1527,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel35       = 1528,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel36       = 1529,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel37       = 1530,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel38       = 1531,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel39       = 1532,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_BuyBQPriceLevel40       = 1533,         ///< �ñ�־�����򷽾�����ID����Ӧ�ļ۸�λ
    FID_MarketName              = 1534,         ///< �г�����
    FID_PreviousSesClose        = 1404,         ///< ǰ���׽׶�����ֵ��4λ��ЧС����CSI��S&PΪǰһ�����������̼ۣ�HIS��TRΪ��һ���׽׶ε�����ֵ��
    FID_EASValue                = 1405,         ///< �����ƽ������ֵ��2λ��ЧС��
    FID_Exception               = 1406,         ///< �쳣ָʾ��
    FID_CurrencyFactor          = 1403,         ///< ����ת������,����ֵ n ��ζ�������������м۸��ֶ�Ӧ����˱�ʾ����ֵ= �ü۸� * 10^n
    FID_TradingSessionID        = 1409,         ///< 1������
    FID_TradingSessionSubID     = 1410,         ///< ���׽׶��ӱ�ʶ��
                                                ///< 0���չر�(DC)
                                                ///< 1������ǰ (Order Input OI)
                                                ///< 2�����̻򾺼ۿ���(Matching MA)
                                                ///< 3����������(Continuous CT)   
                                                ///< 4�����л����о��۽׶Σ�Matching (MA)��
                                                ///< 5�����׺�[CAS]�������루OI��
                                                ///< 7����ͣ (Blocking BL)
                                                ///< 100: ��δ���� (NO)
                                                ///< 101������ȡ��/�޸� (NC)
                                                ///< 102����������Ԥ(EI)
                                                ///< 103������ (CL)
                                                ///< 104��ȡ��ί��(OC)
                                                ///< 105���ο��۶���[CAS]��RP��
                                                ///< 106������ȡ��[CAS]��NW��
                                                ///< 107���������[CAS] (RC)
    FID_TradingSesStatus        = 1411,         ///< ��ǰ���׽׶�״̬
                                                ///< 0��δ֪��ΪNO��
                                                ///< 1��ͣ�ƣ�����BL��EI��
                                                ///< 2�����̣�����[POS] OI��[POS] NC��[POS] MA��CT��OC��
                                                ///< 3���رգ����CL��
                                                ///< 5��Ԥ�رգ�����[CAS] RP��[CAS] NW��[CAS] RC��[CAS] MA��[CAS] OI��
                                                ///< 100���չر�(����DC)
    FID_TradingSesControlFlag   = 1412,         ///< ��ͬʱ���л���ʽ��־����0�����Զ��� (Ĭ��)����1�����ֶ��� (���������������Ч)
    FID_StartDateTime           = 1407,         ///< ����״̬��ʼʱ�䣬����������ʱ��ΪUTC��ʽ��ת����datetime��ʽ��YYYYMMDDHHMMSSsss
    FID_EndDateTime             = 1408,         ///< ����״̬����ʱ�䣬����������ʱ��ΪUTC��ʽ��ת����datetime��ʽ��YYYYMMDDHHMMSSsss


    FID_SellBQMoreFlag          = 1451,         ///< ���������˶��б�־��Y�������л��о����� N����������û�о�����
    FID_SellBQItemCount         = 1535,         ///< ���������˶�����0-40
    FID_SellBrokerID01          = 1631,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID02          = 1632,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID03          = 1633,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID04          = 1634,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID05          = 1635,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID06          = 1636,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID07          = 1637,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID08          = 1638,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID09          = 1639,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID10          = 1640,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID11          = 1641,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID12          = 1642,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID13          = 1643,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID14          = 1644,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID15          = 1645,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID16          = 1646,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID17          = 1647,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID18          = 1648,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID19          = 1649,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID20          = 1650,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID21          = 1651,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID22          = 1652,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID23          = 1653,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID24          = 1654,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID25          = 1655,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID26          = 1656,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID27          = 1657,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID28          = 1658,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID29          = 1659,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID30          = 1660,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID31          = 1661,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID32          = 1662,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID33          = 1663,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID34          = 1664,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID35          = 1665,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID36          = 1666,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID37          = 1667,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID38          = 1668,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID39          = 1669,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBrokerID40          = 1670,         ///< ���������˶����о�����ID��ֵ����ʾ�������м۸�ļ۲�
    FID_SellBQPriceLevel01      = 1671,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel02      = 1672,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel03      = 1673,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel04      = 1674,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel05      = 1675,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel06      = 1676,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel07      = 1677,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel08      = 1678,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel09      = 1679,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel10      = 1680,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel11      = 1681,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel12      = 1682,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel13      = 1683,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel14      = 1684,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel15      = 1685,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel16      = 1686,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel17      = 1687,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel18      = 1688,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel19      = 1689,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel20      = 1690,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel21      = 1691,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel22      = 1692,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel23      = 1693,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel24      = 1694,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel25      = 1695,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel26      = 1696,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel27      = 1697,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel28      = 1698,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel29      = 1699,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel30      = 1700,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel31      = 1701,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel32      = 1702,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel33      = 1703,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel34      = 1704,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel35      = 1705,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel36      = 1706,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel37      = 1707,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel38      = 1708,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel39      = 1709,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
    FID_SellBQPriceLevel40      = 1710,         ///< �ñ�־��������������ID����Ӧ�ļ۸�λ
};

///��Ϣ�ṹ����ֶ�����
enum FIELD_TYPE{    
   Type_ERROR       = 0,           ///< δ֪����
   Type_Char        = 1,           ///< char
   Type_Short       = 2,           ///< short
   Type_Int         = 3,           ///< int
   Type_UInt        = 4,           ///< unsigned int
   Type_Longlong    = 5,           ///< long long 
   Type_ULonglong   = 6,           ///< unsigned long long 
   Type_String      = 7,           ///< string �ַ���
   Type_Double      = 8,           ///< double
   Type_Sequence    = 9,           ///< queue ����
};

/// ���ݽṹ�ֶγ��ȶ���
#define SYMBOL_LEN          40      ///< ���볤��
#define SECURITY_NAME_LEN   20      ///< ֤ȯ���Ƴ���
#define SECURITY_EN_LEN     24      ///< Ӣ��֤ȯ���
#define MARKET_TAG_LEN      10      ///< �г���־����
#define TIMEOUT_DEFAULT     3       ///< Ĭ�����ó�ʱʱ��
#define QUOTATION_FLAG_LEN  4       ///< �����־����
#define SYMBOLSOURCE_LEN    5       ///< ����Դ����
#define PHRASE_TAG_LEN      8       ///< ��ǰƷ�ֽ���״̬����
#define SETTLE_GROUP_ID_LEN 10      ///< ��������볤��
#define USER_NAME_LEN       50      ///< �û�������
#define USER_PWD_LEN        16      ///< ���볤��
#define BROKERQUEUE_LEN     40      ///< �������鳤��
#define UNDERLYINGSECURITYES_LEN  20  ///< ���֤ȯ��Ŀ������
#define LPBROKERNUMBER_LEN  50      ///< �����̾�����ID������

/// ��������
enum NetType{
    Net_Type_A   = 0,   ///< ��ʾ������Ĭ��ֵ
    Net_Type_B   = 1,   ///< ��ʾ�������磬��������ר�ߵ�
};

#endif // GTA_QTS_DATA_TYPE_H_