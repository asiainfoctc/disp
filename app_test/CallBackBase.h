#ifndef _CALLBACK_BASE_H
#define _CALLBACK_BASE_H
#include "GTAQTSInterfaceBase.h"
#include "../Common/IoService.h"
#include "../GTA2csv/Gta2csvMgr.h"
#include "../Common/SubData.h"
#if 0
typedef struct _sub_data_
{
    MsgType     msgType;    ///< ��Ϣ����
    long long	cur_time;	///< ���յ�����ʱ�䣬��ȷ�����룬��ʽΪ��DDHHMMSSmmm
    std::string	data;		///< ��������
}SubData;
#endif
//�û�ͨ�����Ľӿڶ�����Ӧ��Ϣ���ݺ����ݽ�ͨ�����ӿڷ���
//�������̩��ʵʱ����ϵͳV2.X �û��ֲᡷ4.1.2 �ص��ӿ���IGTAQTSCallbackBase �½� 
class CallBackBase :public IGTAQTSCallbackBase
{
public:
    CallBackBase(void);
    virtual ~CallBackBase(void);

    void SetIoService(IoService *ios);

public:
	virtual void OnLoginState(RetCode errCode) override;
    /// ����״̬���أ����ӳɹ�/ʧ��
    /// @param  msgType     -- ��Ϣ����
    /// @param  errCode     -- ʧ��ԭ�򣬳ɹ�ʱ����0 
    ///                     �������̩��ʵʱ����ϵͳV2.X �û��ֲᡷ5.5�����뺬���б�RetCode �½� 
    virtual void OnConnectionState(MsgType msgType, RetCode errCode);

    /// �Ͻ���L2ʵʱ������ն�������ʵʱ�ص��ӿ�
    /// @param  RealSSEL2Quotation  -- ʵʱ����
    virtual void OnSubscribe_SSEL2_Quotation(const SSEL2_Quotation& RealSSEL2Quotation);

    /// �Ͻ���L2��ʳɽ���������ʵʱ�ص��ӿ�
    /// @param  RealSSEL2Transaction    -- ʵʱ����
    virtual void OnSubscribe_SSEL2_Transaction(const SSEL2_Transaction& RealSSEL2Transaction);

    /// ���L1ʵʱ���鶩������ʵʱ�ص��ӿ�
    /// @param  RealSZSEL1Quotation -- ʵʱ����
    virtual void OnSubscribe_SZSEL1_Quotation(const SZSEL1_Quotation& RealSZSEL1Quotation);

    /// ���L2ʵʱ���鶩������ʵʱ�ص��ӿ�
    /// @param  RealSZSEL2Quotation -- ʵʱ����
    virtual void OnSubscribe_SZSEL2_Quotation(const SZSEL2_Quotation& RealSZSEL2Quotation);

    /**
        ��Ҫ����������Ϣ����ʱ����ͨ��ͷ�ļ�GTAQTSInterfaceBase.h�ڵ�IGTAQTSCallbackBase�࣬
        ������Ӧ��OnSubscribe_xxx�ӿڵ��˴�����������ķ�����ʵ�ָú�������
        �������̩��ʵʱ����ϵͳV2.X �û��ֲᡷ4.1.2.3 ʵʱ���ݻص�OnSubscribe �½� 
    */
	virtual void OnSubscribe_SZSEL2_Order(const SZSEL2_Order& RealSZSEL2Order) override;
	virtual void OnSubscribe_SZSEL2_Transaction(const SZSEL2_Transaction& RealSZSEL2Transaction) override;
    /// ����������
    void Deal_Message(SubData *subdata);
	
	Gta2csvMgr m_gta2csvMgr;
private:
    IoService	*m_ios;
};
#endif  //_CALLBACK_BASE_H
