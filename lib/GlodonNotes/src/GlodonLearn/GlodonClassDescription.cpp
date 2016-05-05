#include "GlodonClassDescription.h"
#include "GlodonBusiness.h"

GlodonClassDescription::GlodonClassDescription()
{
    m_pBusiness = new GlodonBusiness();
}

void GlodonClassDescription::buildBDSData()
{
    m_pBusiness->glodon_updateEbidding();

    /**
    GBQBidBDSBuildService::buildBDSData(
                        const GString &bdsFile, bool needEstiData)
    ************************************************************************************
    IGBQBDSData *piBDSData = new GBQBDSData;
    GSPModel oModel = GBQGSPUtils::cloneModel(m_piBidService->getProjModel(), false);
    oModel.findTable(dbnBusinessDB, ptnResource).clear();
    oModel.findTable(dbnBusinessDB, ptnBidNode).clear();

    piBDSData->setBidModel(oModel);

    // delphi FAfterLoadBidTplFile(Result);
    doBeforeBuildBDSData(piBDSData);

    // delphi FOnImportBDSData(...)
    if (m_oCustomBuildBDSDataPlugin.count() > 0)
    {
        doCustomBuildBDSData(
                    bdsFile, piBDSData, m_piBidService->getConfigInfo(),
                    m_piBidService->getBidDataProvider(), m_piBidService->getProjModel(), needEstiData);
    }
    else
    {
        // ASelectDocumentPath有可能是文件，也有可能是文件夹
        GBQXML2BidBDSTransfer oTransfer(m_piBidService->getConfigInfo());
        try
        {
            oTransfer.setJpbBDSTplFile(m_piBidService->getConfigInfo()->getSpecialFile(identBDSCache));
            oTransfer.getAfterImportJobPluginContainer()->attachPlugin(this);

            oTransfer.execute(bdsFile, piBDSData, needEstiData, NULL);
        }
        catch (...)
        {
            throw;
        }

    }

    return piBDSData;
    ***********************************************************************


      */
}

void GlodonClassDescription::workspace()
{
    /**
    switch (workSpaceType)
    {
    case GBQWorkSpaceFrame::MergedBidEditor:
        return new GBQMergedBidEditorWorkSpaceFrame();
    case GBQWorkSpaceFrame::MergedBuildingEditor:
        return new GBQMergedBuildingEditorWorkSpaceFrame();
    case GBQWorkSpaceFrame::BidSum:
        return getBidSumWorkspaceFrame(projPageType, unifiedNavWorkSpaceFram);
    case GBQWorkSpaceFrame::BidEditor:
        return new GBQBidEditorWorkspaceFrame();
    case GBQWorkSpaceFrame::BuildingSum:
        return new GBQBuildingSumWorkSpaceFrame();    //单项的workspace
    case GBQWorkSpaceFrame::BuildingEditor:
        return new GBQBuildingEditorWorkSpaceFrame();
    case GBQWorkSpaceFrame::BDS:
        return new GBQBDSWorkspaceFrame();
    case GBQWorkSpaceFrame::Job:
        return getJobWorkspaceFrame(projPageType);
    default:
        return NULL;


    switch (projPageType) {
    case PageEdit:
        return new GBQJobWorkSpaceFrame();          //单位工程 workspace
    case PageAdjust:
        return new GBQAdjustJobWorkSpaceFrame();
    default:
        return NULL;
      */
}
