#include "GlodonWorkUseClass.h"

GlodonWorkUseClass::GlodonWorkUseClass()
{
}

void GlodonWorkUseClass::glodon_updateEbidding()
{
    /**
    GBQUpdateOwnerEBiddingForm

    更新招标书的第一个窗口，匹配标段
    GBQEBiddingMatchBidStructureFrame.h { GBQEBiddingMatchBidStructureFrame }

    GBQUpdateOwnerEBiddingFileService { GBQUpdateBDSStructureMatchBuilder }

    GBQUpdateEBiddingMatchResult.h
    GBQUpdateEBiddingMatchResult { IGBQUpdateEBiddingMatchResult }
    GBQUpdateEBiddingMatchList { IGBQUpdateEBiddingMatchList（里面有个 handlers 列表，专门存放Handler }

    GBQUpdateEBiddingMatchBuilder.h
    { 	GBQUpdateEBiddingDataMatchBuilder <m_pBidMatchList, m_pBidEditorMatchList, m_pBuidingEditorList,m_pJobMatchList>

        GBQUpdateEBiddingBidInfoMatchHandler                    标段信息         (bid)
        GBQUpdateEBiddingBidAddInfoMatchHandler                 标段附件信息      (bid)


        GBQUpdateEBiddingBQMatchHandler                         清单          (Job)
        GBQUpdateEbiddingQuantifiableBillMatchHandler           可计量措施清单  (Job, bidEditor)
        GBQUpdateEBiddingMeasMatchHandler                       不可计量措施    (Job, bidEditor)
        GBQUpdateEBiddingOtherMatchHandler                      其他项目       (Job, bidEditor)
        GBQUpdateEBiddingDayWorkMatchHandler                    计日工         (Job, bidEditor)
        GBQUpdateEBiddingProvisionalAmountMatchHandler          暂列金额       (Job, bidEditor)
        GBQUpdateEBiddingProjectProvisionalResMatchHandler      专业工程暂估价  (Job)
        GBQUpdateEBiddingOverallServiceCostMatchHandler         总承包服务费    (Job, bidEditor)
        GBQUpdateEBiddingSummaryServiceCostMatchHandler         费用汇总       (Job)
    }


    GBQBidService.h
    m_piBidService->getEBiddingService()->getUpdateEBiddingService()

    IGBQEBiddingService *GBQBidService::getEBiddingService()
    {
        if (NULL == m_piEBiddingService)
        {
            m_piEBiddingService = new GBQEBiddingService(this);
        }
        return m_piEBiddingService;
    }


    GBQBiddingService.h
    IGBQUpdateOwnerEBiddingFileService *GBQEBiddingService::getUpdateEBiddingService()
    {
        if (NULL == m_piUpdateEBiddingService)
        {
            m_piUpdateEBiddingService = new GBQUpdateOwnerEBiddingFileService(m_piBidService);
        }
        return m_piUpdateEBiddingService;
    }

    GBQUpdateEBiddingExcutor.h
    {	GBQUpdateEBiddingExcutor::update( *bdsData, *matchResult, *bidService )
        GBQUpdateEBiddingExcutor::GLDList<GBQUpdateEBiddingDataHandler*>m_oUpdateBDSDataHandlers
        GBQUpdateEBiddingBidInfoDataHandler                 标段信息
        GBQUpdateEBiddingBidAddiInofDataHandler             标段附加信息
        GBQUpdateEBiddingBQDataHandler                      分部分项清单
        GBQUpdateEBiddingMeasDataHandler                    措施项目
        GBQUdpateEBiddingOverallServiceCostDataHandler		总承包服务费
        GBQUpdateEBiddingProvisionalAmountDataHandler		暂列金额
        GBQUpdateEBiddingOtherDataHandler                   其他项目
        GBQUpdateEBiddingDayWorkDataHandler                 计日工
        GBQUpdateEBiddingSummaryDataHandler                 费用汇总
    }

    GBQUpdateEBiddingClasses.h  {	GBQUpdateEBiddingDataHandler }

      */
}
