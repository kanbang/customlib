#include "GlodonLearn.h"
#include "GlodonBusiness.h"
#include <QDebug>

GlodonLearn::GlodonLearn()
{
    m_pBuisness = new GlodonBusiness();
    /**
    @   如果打开两个qtcreator，那么编译的时候就不能编译库，也就是说，库不能更新，
        同时，还会出现 \brief 无法获取调试输出 的错误提示

    @   全工程搜索的时候，如果public xxx 没有搜到，试试 public virtual xxx 或者
        virtual xxx 搜索

      */
}

void GlodonLearn::glodon_GLDFrame()
{
    glodon_workspaceFrame();
    glodon_moduleGroupFrame();
    glodon_moduleFrame();
    glodon_slaveGroupFrame();
    glodon_gridFrame();

    glodon_buildingProj();
    glodon_proj();

    /**
    \brief  基类

    @ QWidget->QLDBaseFrame
                IGLDFrame                   ->GLDFrame
                IGLDNavigatorChangePlugin
    registerFrameFactory() 注册工厂函数式在 GLDFrame 的构造函数里调用的

    ********************************************************
    ********************************************************

    @   GLDFrame
        IGBQMatchDataUpdateProgressPlugin -> GBQUpdateOwnerEbiddingForm

    @   GLDFrame
        IGLDUIService ->GLDWorkSpaceFrame

    @   GLDFrame
        GNoRefInterfaceObject
        IGEPTransTokenEvent     -> GBQConFormulaForm

    @   GLDFrame
        GSPDataSourceObserver
        IGBQQueryHasChildren    -> GBQBQInfoTreeFrame

    @   GLDFrame
        IGBQQueryHasChildren    -> GBQNormInfoTreeFrame

    @   GLDFrame -> GBQCostRatiosSettingFrame

    @   GLDFrame -> GBQBatchReplaceFrame

    @   GLDFrame -> GBQBidAppendJobForm

    @   GLDFrame -> GBQBidResQueryConditionFrame

    @   GLDFrame -> GBQBidResourceFinderForm

    @   GLDFrame -> GBQBinResourceInfoTreeFrame

    @   GLDFrame -> GBQBidResourceQueryBaseFrame

    @   GLDFrame -> GBQExportAllJobForm

    @   GLDFrame -> GBQEBiddingMatchBidStructureFrame

    @   GLDFrame -> GBQEBiddingMatchDataFrame

    @   GLDFrame -> GBQFeeWatchFrame

    @   GLDFrame -> GBQQueryCostCodeFrame

    @   GLDFrame -> GBQQueryCostRatioFrame

    @   GLDFrame -> GBQQueryInfoPriceFrame

    @   GLDFrame -> GBQSpecEditGroupFrame(编辑查询项目特征方案)

    @   GLDFrame -> GBQReuseHistoricalDataForm


    *******************************************
    *******************************************
    窗口管理：
        GBQSpecGroupFrame 管理了 (分部分项-特征与内容)

      */
}

void GlodonLearn::glodon_navigator()
{
    /**
    \brief 这个派生类的用作:
    @   这个类是设置页签的，通过点击页签(页签其实也是一个窗口),切换窗口，这里切换的窗口有
        Master/Slave 两个窗口，

    @   QWidget
        IGLDFrameNavigator -> GLDAbstractNavigator

    @   GLDAbstractNavigator -> GLDTabBarNavigator

    @   GLDAbstractNavigator -> GLDToolBarNavigator

    @   GLDAbstractNavigator -> GLDButtonNavigator -> GLDQssButtonNavigator

    @   GLDAbstractNavigator -> GLDTreeNavigator

    @   GLDAbstractNavigator -> GLDOutLookBarNavigator

    @
      */
}

void GlodonLearn::glodon_mdichild()
{
    /**
    @   QWidget
        IGLDMIChild -> GLDMDIChild

    @   IGLDMDIChild -> IGCCPMDIChild

    @   GLDMDIChild
        IGCCPMDIChild -> GCCPMDIChild

    @   GCCPMDIChild
        IGBQFileNameChangedPlugin
        IGBQProjectNameChangePlugin  -> GBQMDIChild

    @   GBQMDIChild
        IGBQComponentJobFileEditor -> GBQBidMDIChild

    @   GBQMDIChild
        IGBQComponentJobFileEditor -> GBQBidMDIChild
      */
}

void GlodonLearn::glodon_mainform()
{
    /**
    @   IGLDMainForm -> IGCCPMainForm -> IGBQMainForm

    @   GLDMainForm -> GCCPMainForm

    @   GCCPMainForm
        IGBQComponentMainForm
        IGBQUserStateController
        IGBQUserCallBackController
        IGBQMainForm                    -> GBQMainForm





    ******************************************
    ******************************************
    // GBQNewJobWizardFrame.h

    @   QDialog -> GBQNewWizardTemplateFrame
                -> GBQNewJobTemplateFrame
                -> GBQNewJobWizardGroupFrame

    @   QWidget
        GBQAfterSaveAsTemplatePlugin
        GBQAfterSaveAsBidTemplatePlugin
        GBQAfterDeleteAsTemplatePlugin
        GBQNewProjWizardClearWidgetPlugin -> GBQNewProjWizardFrame

    @   QFrame -> GBQNewWizardTemplateButton
      */
}

void GlodonLearn::glodon_code_standard()
{
    /**
    @ 所有的类以 "G"、 "CG"、"QG"、开头，如 CGTFControl， GSPRecord，QGTableView
        VC 和 MFC 使用CG
        Qt        使用QG

    @ 所有的接口都以 "I" 开头


      */
}

void GlodonLearn::glodon_UIFacade()
{
    /**
    @   IGLDUIFacade -> IGCCPUIFacade
        IGCCPUIFacade -> IGBQUIFacade

        // 只有GBQUIFacade 实现了接口
        IGBQUIFacade -> GBQUIFacade (GBQUIFacade.h)

        //每个地区有自己的特性，有自己的GBQUIPluginFacade
    @   IGLDUIPluginFacade -> GBQUIPluginFacade
      */
}

void GlodonLearn::glodon_UIPlugin()
{
    /**
    @ IGLDUIPlugin -> GLDUIPlugin(部分实现) -> GBQUIPlugin

    @ IGLDUIPlugin -> GLDUIPluginList

    @

      */
}

void GlodonLearn::glodon_frameLayout()
{
    /**
    @   IGLDFrameLayout -> GLDFrameLayout

    @   GLDFrameLayout -> GLDBoxFrameLayout

    @   GLDBoxFrameLayout -> GLDHBoxFrameLayout

    @   GLDBoxFrameLayout -> GLDVBoxFrameLayout

    @   GLDBoxFrameLayout -> GLDMasterSlaveFrameLayout

    @   GLDFrameLayout -> GLDNormalFrameLayout
        typedef GLDNormalFrameLayout GLDStackFrameLayout;

    @   GLDFrameLayout -> GLDDefaultFrameLayout

    @   GLDFrameLayout -> GLDFloatNaviFrameLayout

    @   QObject -> QLDNormalFrameLayoutAnimate

    @
      */
}

void GlodonLearn::glodon_extension()
{
    /**
    @   QObject
        IGLDFrameExtension(GLDUIIntf.h) -> GLDFrameExtension(GLDFrameExtension.h)

    @   GLDFrameExtension
        IGLDGridFrameExtension -> GBQGridFrameExtension(GBQUIPlugin.h)

    @   GLDFrameExtension -> GBQGuangDongUnifiedNavWorkSpaceFrameExtension

    @   GLDFrameExtension -> GBQUnifiedNavWorkSpaceFrameExtension

      */
}

void GlodonLearn::glodon_workspaceFrame()
{
    glodon_moduleGroupFrame();
    glodon_moduleFrame();
    glodon_slaveGroupFrame();
    glodon_gridFrame();
    /**

    \brief GLDWorkSpaceFrame
        GLDWorkSpaceFrame 表示工程的主工作区，用来实现一个文件的打开显示界面，其会放置在一个MDIChild 窗体上，
        实现MDI的窗体效果

        GLDWorkSpaceFrame 由于位于页面的最底层，因此通过WorkSpaceFrame可以找到其子子孙孙页面，
        WorkSpaceFrame 的 Name (URL) 需要在初始化时指定

    @   GLDFrame
        IGLDUIService -> GLDWorkSpaceFrame -> GCCPWorkSpaceFrame -> GBQWorkSpaceFrame

    @   GBQWorkSpaceFrame
        IGBQEBiddingMatchFrame -> GBQEBiddingMatchCompleteWorkSpaceFrame

    @   GBQWorkSpaceFrame
        IGBQEBiddingMatchFrame  -> GBQEBiddingMatchWorkSpaceFrame

    @   GBQWorkSpaceFrame -> GBQBDSWorkspaceFrame

    @   GBQWorkSpaceFrame
        IGBQBidSumUIService -> GBQBidSumWorkspaceFrame

    @   GBQWorkSpaceFrame -> GBQBuildingSumWorkSpaceFrame

    @   GBQWorkSpaceFrame -> GBQUnifiedNavWorkSpaceFrame

    @   GBQWorkSpaceFrame -> GBQJobWorkSpaceFrame

    @   GBQWorkSpaceFrame -> GBQReportWorkSpaceFrame

      */
}

void GlodonLearn::glodon_moduleGroupFrame()
{
    glodon_workspaceFrame();
    glodon_moduleFrame();
    glodon_slaveGroupFrame();
    glodon_gridFrame();

    glodon_buildingProj();
    glodon_proj();

    /**

    \brief GLDModuleGroupFrame 表示一组模块用来描述一组相关或者相似的页面模块

    @   GLDModuleGroupFrame -> GCCPModuleGroupFrame -> GBQModuleGroupFrame

    @   GBQModuleGroupFrame
        IGBQEBiddingMatchFrame -> GBQEBiddingMatchEditorGroupFrame

    @   GBQModuleGroupFrame
        IGBQEBiddingMatchFrame -> GBQEBiddingMatchGroupFrame

    @   GBQModuleGroupFrame -> GBQBidCostAnalysisGroupFrame

    @   GBQModuleGroupFrame -> GBQBidCostRatiosSettingGroupFrame

    @   GBQModuleGroupFrame -> GBQProjectInfoGroupGrame

    @   GBQModuleGroupFrame -> GBQUnitProjectInfoGroupFrame

    @   GBQModuleGroupFrame -> GBQBidResSumGroupFrame

    @   GBQModuleGroupFrame -> GBQBQGroupFrame (....)分部分项

    @   GBQModuleGroupFrame -> GBQJobCostRatiosSettingGroupFrame

    @   GBQModuleGroupFrame -> GBQMeasureGroupFrame

    @   GBQModuleGroupFrame -> GBQExtraGroupFrame

    @   GBQModuleGroupFrame -> GBQOtherGroupFrame

    @   GBQModuleGroupFrame -> GBQProjProfileGroupFrame

    @   GBQModuleGroupFrame -> GBQResSumGroupFrame

    @   GBQModuleGroupFrame
        IGBQViewObserverContext -> GBQSummaryGroupFrame

    @   GBQModuleGroupFrame -> GBQReportGroupFrame

      */
}

void GlodonLearn::glodon_moduleFrame()
{
    glodon_workspaceFrame();
    glodon_moduleGroupFrame();
    glodon_slaveGroupFrame();
    glodon_gridFrame();

    glodon_buildingProj();
    glodon_proj();

    /**

    \brief ModuleFrame, 管理了Master/Slave窗口，在 GBQModuleFrame::initialize() 里面定义了Master窗口和Slave窗口的调用，
        以及信号槽的链接。

    @   GLDFrame
        IGLDModuleFrame ->GLDModuleFrame

    @   GLDFrame
        IGLDModuleGroupFrame ->GLDModuleGroupFrame

    @   GLDFrame -> GLDModuleFrame -> GCCPModuleFrame -> GBQModuleFrame

    @   GBQModuleFrame -> GBQProjectIdxInfoModuleFrame

    @   GBQModuleFrame -> GBQBidCostAnalysisModuleFrame

    @   GBQModuleFrame -> GBQBidCostRatioAndFileAdjustGroupFrame

    @   GBQModuleFrame -> GBQBuildingSummaryModuleFrame

    @   GBQModuleFrame -> GBQProjectInfoBidCostListModuleFrame

    @   GBQModuleFrame -> GBQProjectInfoModuleFrame

    @   GBQModuleFrame -> GBQBidMainMaterialFrame

    @   GBQModuleFrame -> GBQBidMaterialForEvaluationFrame

    @   GBQModuleFrame -> GBQBidNOT12OAMFrame

    @   GBQModuleFrame -> GBQBidNOT12OSMFrame

    @   GBQModuleFrame -> GBQBidOAMFrame

    @   GBQModuleFrame -> GBQBidOSMFrame

    @   GBQModuleFrame -> GBQBidProvisionalMaterialFrame

    @   GBQModuleFrame -> GBQBidResSumFrame

    @   GBQModuleFrame -> GBQPrimaryResourceFrame

    @   GBQModuleFrame -> GBQBQFrame (....)分部分项

    @   GBQModuleFrame -> GBQJobCostRatioAndFileAdjustGroupFrame

    @   GBQModuleFrame -> GBQUnPriceableResModuleFrame

    @   GBQModuleFrame -> GBQMeasureFrame

    @   GBQModuleFrame -> GBQDayWorkFrame

    @   GBQModuleFrame -> GBQNormExtraExpenseFrame

    @   GBQModuleFrame -> GBQOtherFrame

    @   GBQModuleFrame -> GBQOverallServiceCostFrame

    @   GBQModuleFrame -> GBQProjectProvisionalResFrame

    @   GBQModuleFrame -> GBQProvisionalAmountFrame

    @   GBQModuleFrame -> GBQVisaAndCompensationSummaryFrame

    @   GBQModuleFrame -> GBQEditPrefaceModuleFrame

    @   GBQModuleFrame -> GBQProjCharacterModuleFrame

    @   GBQModuleFrame -> GBQProjInfoModuleFrame

    @   GBQModuleFrame -> GBQMainMaterialFrame

    @   GBQModuleFrame -> GBQMaterialForEvaluationFrame

    @   GBQModuleFrame -> GBQOSMFrame

    @   GBQModuleFrame -> GBQProvisionalMaterialFrame

    @   GBQModuleFrame -> GBQResSumFrame

    @   GBQModuleFrame -> GBQSWCModuleFrame

    @   GBQModuleFrame -> GBQSummaryFrame

      */
}

void GlodonLearn::glodon_slaveGroupFrame()
{
    glodon_workspaceFrame();
    glodon_moduleGroupFrame();
    glodon_moduleFrame();
    glodon_gridFrame();

    glodon_buildingProj();
    glodon_proj();

    /**

    \brief GLDSlaveFrame
        SlaveFrame 是 Slave 的一个窗口， SlaveGroupFrame 是所有的SlaveFrame组合起来

    @   GLDFrame -> GLDSlaveFrame -> GCCPSlaveFrame -> GBQSlaveFrame
        ->GBQJobSlaveFrame -> GBQSpecAndWorkScopeFrame -> GBQBQSpecAndWorkScopeFrame

    @   GBQJobSlaveFrame -> GBQResourceConvertFrame (分部分项 Slave 工料机显示)

    @   GBQJobSlaveFrame -> GBQViewRateDetailFrame (分部分项 Slave 查看单价构成)

    @   GBQJobSlaveFrame -> GBQSpecAndWorkScopeFrame -> GBQBQSpecAndWorkScopeFrame (分部分项 特征与内容)

    **************************************
    **************************************

    \brief GLDSlaveGroupFrame

    @   IGCCPSlaveFrame
        GLDFrame -> GLDSlaveGroupFrame -> GCCPSlaveGroupFrame - >GBQSlaveGroupFrame -> GBQBQSlaveGroupFrame

    @   GBQSlaveGroupFrame -> GBQSpecGroupFrame

    @   GBQSlaveGroupFrame -> GBQBQSlaveGroupFrame (分部分项的 Slave， 特征与内容是在这里注册的)

    @   GBQSLaveGroupFrame -> GBQSpecGroupFrame (分部分项的Slave， 特征与内容)

    @

      */
}

void GlodonLearn::glodon_gridFrame()
{
    glodon_workspaceFrame();
    glodon_moduleGroupFrame();
    glodon_moduleFrame();
    glodon_slaveGroupFrame();

    glodon_buildingProj();
    glodon_proj();

    /**

    \brief GridFrame 这个类集成了 GSP 及 Grid 控件，目的是为了派生类实现表格的操作和表格的扩展
    这个GridFrame 还有一个对应的 QItemDelegate 类来操作这个表格。
    @   GLDFrame
        IGLDGridFrame -> GLDGridFrame -> GCCPGridFrame -> GBQGridFrame

    @   GLDFrame
        IGLDGridFrame ->GLDGridFrame -> GBQSpecSchemeGridFrame (项目特征方案)

    @   GLDGridFrame -> GBQNewEBiddingStructureGridFrame

    @   GLDGridFrame -> GBQOldEBiddingStructureGridFrame

    @   GLDGridFrame -> GBQAccordanceCheckFilterInnerForm

    @   GLDGridFrame -> GBQAdjustCostSelectTitleGridFrame

    @   GLDGridFrame -> GBQGlobalLockResItemFrame

    @   GLDGridFrame -> GBQHideAdjustInfoFrame

    @   GLDGridFrame -> GBQReverseAdjustStructureGridFrame

    @   GLDGridFrame -> GBQReverseAdjustPreviewGridFrame

    @   GLDGridFrame -> GBQBidReverseAdjustStructureGridFrame

    @   GLDGridFrame -> GBQBidReverseAdjustPreviewGridFrame

        (1111)
    @   GLDGridFrame -> GBQJobGridFrame
                        IGBQEditDropDownFormExecutor -> GBQProjInfoGridFrame

    @   GBQJobGridFrame -> GBQBQGridFrame (分部分项的 Master::GLDGridFrame);

    @   GBQJobGridFrame -> GBQResourceConvertGridFrame (分部分项 Slave::GLDGridFrame 工料机显示)

    @   GBQGridFrame -> GBQViewRateDetailGridFrame (分部分项 Slave::GLDGridFrame 查看单价构成)

    @   GBQGridFrame
        GSPAfterUpdateFieldImpl -> GBQWorkScopeGridFrame (分部分项 Slave::GLDGridFrame 特征与内容)

    @   GBQGridFrame
        GSPAfterUpdateFieldImpl
        GSPAfterInsertRecordImpl
        GSPAfterDeleteRecordImpl
        GSPAfterMoveRecordImpl          -> GBQSpecGridFrame (分部分项 Slave::GLDGridFrame 特征与内容)

    @   GBQGridFrame -> GBQSpecSchemeGridFrame (分部分项 Slave::GLDGridFrame 特征与内容)

      */
}

void GlodonLearn::glodon_use_function()
{
    glodon_buildingProj();
    /**
     GBQNewProjWizardFrame 这个类中 showEvent 事件中创建 GBQNewWizardTemplateFrame
                            GBQNewProjWizardFrame 管理着 GBQNewWizardTemplateFrame

     GBQNewWizardTemplateFrame 程序启动后界面上的功能导航窗口，可以选择 计价，计量，建筑工程，
                                园林建设等等

     * @brief GBQNewWizardTemplateFrame::eventFilter
     * @param object
     * @param event
     *
    GBQNewWizardTemplateFrame::eventFilter(QObject* object, QEvent* event);
    {   QTimer::singleShot(250, this, SLOT(onTimer());}

    单击调用单击函数，双击调用双击函数。在这个函数里面有判断。 m_nClickCount个数来判断，双击相当于两次单击
    调用完了归零； m_nClickCount = 0;
    GBQNewWizardTemplateFrame::onTimer()
    {
        (GBQNewProjWizardFrame)m_pNewProjWFrame->onBtnDoubleClicked
            ( (RibbonBackstageButton)m_pBtnPreClicked->defaultAction());
    }

    GBQNewProjWizardFrame::onBtnDoubleClicked(QAction* action)
    {
        GBQNewJobWizardFrame* jobWizardFrame(this,m_piUIFacade);
        jobWizardFrame.onTempLabelDoubleClicked();
    }

    GBQNewJobWizardFrame::onTempLabelDoubleClicked()
    {
        onOkBtnClicked();
    }
    GBQNewJobWizardFrame::onOkBtnClicked()
    {
        (IGBQUIFacade)m_piUIFacade->openJob(m_piJobService);
    }

    GBGUIFacade::openJob(IGBQJobService* jobService)
    {
        QWidget* widget = createJobMDIChild(); // new GBQJobMDIChild(m_piMainForm,& m_uiPluginFacadeList);
         dynamic_cast<GBQMDIChild*>(widget)->bind(jobService, this);
        m_piMainForm->addMDIChild(widget);
    }

    GBQJobMDIChild::bind(IGLDService* service, IGLDUIFacade* uiFacade)
    {
        GBQMDIChild::bind(...);
    }

    GBQMDIChild::bind(...)
    {
        GCCPMDIChild::bind(...);
    }

    GLDMDIChild::bind(....)
    {
        m_pWorkspaceFrame = createWorkSpaceFrame();
        m_pWorkspaceFrame->bind(service); // GBQJobWorkSpaceFrame
        GBQJobWorkSpaceFrame::bind(IGLDService* service)
        {
            GLDWorkSpaceFrame::bind(service)
            {
                init(NULL, this, "");
                GLDFrame::init(...)
                {
                    GLDFrame::changeCurrent(...);
                }
            }

            ....
        }
        // m_pWorkspaceFrame 是工作空间窗口，把它放在布局管理器中，
        然后在布局管理器放在MDIChild中。

        (QBoxLayout)m_pBoxLayout->addWidget(m_pWorkspaceFrame);
    }

    GBQJobWorkSpaceFrame::registerFrameFactory()
    {
        往工作空间中注册GroupFrame的工厂类
        造价分析页 -> GBQProjectIdxInfoModuleFrameFactory(...);
    }
    GLDWorkSpaceFrame* GBQJobMDIChild::createWorkSpaceFrame()
    {
        m_pJobWorkSpaceFrame = new GBQJobWorkSpaceFrame();
        return m_pJobWorkSpaceFrame;
    }



    **************************************
    **************************************
    函数调用模块：
        切换到分部分项页签，此时会创建 特征与内容的窗口，调用过程是这样调用的：
        先调用 GLDAbstractNavigator 这个类的槽函数 doCurrentChanged(int index);
        GLDFrame::doNavigatorChange(const GString &curFrameName, const GString& params);
        GLDFrame::changeCurrent(const GString& name);
        GBQSlaveGroupFrame::doChangeCurrent(const GString& name);
        GLDFrame::doChangeCurrent(const GString& name);
        GBQSlaveGroupFrame::createItem(const GString& name) { GLDFrame::createItem(name); };

        GLDFrame* GLDFrame::createItem(const GString& name)
        {
            IGLDFrameFactory* pFrameFactory = m_pFrameFactories->find(name);
            GLDFrame* pFrame = dynamic_cast<GLDFrame*>( pFrameFactory->createFrame());
            return pFrame;
        }
      */
}

void GlodonLearn::glodon_svn()
{
    /**
    @ 如果文件被其他用户锁定了，那么文件的属性就会变成只读，不允许写，解决方法：
        @a 选中文件，右键属性，去掉只读。

      */
}
/**
 *********************************************************************************************************************
 *********************************************************************************************************************
 *********************************************************************************************************************
 *********************************************************************************************************************
 */
void GlodonLearn::glodon_ts_GPS()
{
    /**
    @   GSP_Report                              新建报表

    @   GSP_Report_SelectNewReportType          选择新建报表方式

    @   GPS_CostAnalysis                        造价分析(GPS_UnitProjectCostAnalysisFrame)

    @   GPS_ProjectOverview                     工程概况(ProjProfileGroupFrame)

    @   GPS_SetCalcCost                         取费设置

    @   BQGroup                                 分部分项

    @   MeasGroup                               措施项目

    @   OtherItemGroup                          其他项目

    @   GPS_ResSumGroupFrame                    人材机汇总

    @   GPS_SummaryGroupFrame                   费用汇总

    @   GPS_StyValLblText                       取材料价值前
      */
}

void GlodonLearn::glodon_GSP_Database()
{
    glodon_operator_table();
    /**
    GSPModel 保存 GSPDatabase 列表，
    GSPDatabase 保存 GSPTable

    GSPTableView 通过GSPDataSourceModel 操作 GSPDataSource

    GSPDataSource 挂了很多的GSPView
    找到GSPView后，通过 GSPView.table() 得到GSPTable


    在 GSPDataSource 里面定义了一个 GSPViews* m_subjects;
    typedef GLDVector<GSPView> GSPViewVector;
    typedef GSPViewVector GSPViews;

      */
}

void GlodonLearn::glodon_work()
{
    /**

    替换其他数据 4位编码 ： GBQBatchReplaceBQItemFrame.cpp  212

    GBQAutoSetMainMatForm           主要材料与设备对话框

    GBQResSumGridFrame::m_pActBatchModifyResource 人材机汇总 -> 子菜单 -> 批量修改

    GBQMainMaterialGridFrame(Job|ResSumGroupFrame|MainMaterialFrame|MainMaterialGridFrame)
        主要材料表

      */
}

void GlodonLearn::glodon_translation()
{
    /**
    1 在QtCreator的pro文件中添加如下一行：

    TRANSLATIONS = tran_CN.ts

    后面的内容是要翻译的文件的名字；

    2 在QtCreator的Tools -> extern tools -> linguist -> lrelease （注意：大致是这个菜单，不对请找到Linguist菜单即可^-^），此时会生成一个 tran_CN.ts 文件；

    如果后续又对工程中的文件进行了更新，此时使用 lupdate 即可对该文件进行重写；

    3 打开Linguist程序（在Qt的bin目录中），然后使用 打开 命令即可打开该文件，会询问你要翻译的文件的

    源文件（是何种语言、用在什么地方）—— 一般都是需要根据你开发时所使用的语言来确定的，这里为英语；
    目标文件（是何种语言、用在什么地方）—— 也就是你翻译后的文件时什么形式，这里为 中文；

    4 然后，即可以开始翻译逐个了：翻译后，按下Ctrl+Enter可以自动到下一个需要翻译的地方；
    全部结束后，会在每个翻译的类的前面的灰色的 对号 全部变为 绿色 的对号。

    5 使用保存命令保存未见，再使用 发布 命令即可发布翻译后的翻译文件；

    6 在main函数中，添加如下代码即可使用翻译文件：

        QTranslator translator;
        translator.load("../MyProj/cn_CN.qm");
        app.installTranslator(&translator);

    app为应用程序的主进程；

    这里的路径是：生成应用程序时，QtCreator所创建的那个文件夹为当前目录。请自行试验自己的目录地址。

      */
}

void GlodonLearn::glodon_thought()
{
    /**
    在Q5中，有通性和特性之分，通性时在Frame里面直接设置的，特性是通过extension设置的

    不能在通性里面做GVariant的值判断，应该是返回什么值，就把Frame设置为什么值，这就要求在
    Extension里面做判断，判断返回值，在根据返回值设置Frame

      */
}

void GlodonLearn::glodon_create_GUI()
{
    /**
     GBQMainForm -> GBQNewWizardForm -> GBQNewWizardFrame(放在GBQNewWizardForm上)
     */




    glodon_operator_table();
    /**
    @                                                             _ Master(GridFrame)  这里的URL名字必须是 Master
                                                                 |
                                                                 |
    GLDWorkSpaceFrame -> GBQModuleGroupFrame -> GBQModuleFrame ->
                                                                 | (这里的URL名字必须是SlaveGroup)
                                                                 |_ SlaveGroup-> GBQSlaveFrame-> GridFrame


    @ 表如果不能再窗口中显示，一般有一下几种情况：

        @a ModuleFrame 下注册的窗口的URL名字不是 Master 和 SlaveGroup

        @b GSP 和 GSF 不匹配

        @c GSF 要显示的表名和 CreateViews()函数中的创建的 Views的表明不一致。
           \brief
           GSF 要显示的是 otherItem  表， 而CreateViews 确实根据 OSMaterialForEvaluation (评标甲供表）创建Views
           createViews()创建的views可以有过滤添加，可以让界面不显示一些记录。

    */
}

void GlodonLearn::glodon_operator_gsf()
{
    /**
    @ GSF 文件是如何显示在窗口上的：
        @a 获得GSF文件的路径。 GString getGridSettingFileName();

        @b 创建views， 这里创建views的时候要注意，这个views 是根据你要显示
            表，也就是GSPModel里的表是创建的，如果GSF要显示的字段，GSPModel
            里对应的表里没有这个字段，那么程序会崩溃的。要显示几个表就创建几个views

            GSPViews  createViews();

        @c 想GSF里面添加列
            GBQGridSettingUtils::addColSetting(
                m_pGridSetting(GSF对象), c_sCidQuantity(列标识),
                "True"(是否显示), c_sCidQuantity(列名称),
                GStrings()<< ptnFBFXBQItemTitle << ptnFBFXItem (GSF 要显示的表，此时GSF 显示两个表),
                GStrings()<< pfnQuantity << pfnQuantity (鼠标点击编辑时显示的内容)
                GStrings()<< pfnQuantity << pfnQuantity (不编辑的时候显示的内容),
                gcstSuitColWidth(设置列宽),
                nIndex (这一列要放在GSF里的第几列)
                )
                DisplayRole, EditRole 的功能

        @d  设置列名称
            m_pGridSetting->titleRows()->items(0)->cells(nIndex)->setCaption(c_sCidQuantity);

        @e  移动GSF列的位置
            m_pGridSetting->colSettings()->move(fromIndex, toIndex);


      */
}

void GlodonLearn::glodon_foreignKey()
{
    /**
    @ 在GSP中，表的主键默认是 integer， 这就导致子表如果引用父表的
        其他的字段的时候，需要特殊设置。

        D:\KuaiPan\learn\glodon\GSPFile\test.GSP
        有两个表 分数(Score)、 学生(Student)
        分数(Score)表中有一个外键 名字(Name),这个外键引用的是Student主表的主键。
        如果要想获得Student表的其他字段。

        @a 把外键字段的 查询类型 -> 表、 查询表名->Student、 查询名称 ->Name、 查询结果 -> StudentID

        查询结果必须选主键，如果不是主键，那么非法。因为要通过这个主键找到与主键相对应的名字

    @ 主表和外表，由于外边的外键引用了主表的主键，当删除主键的记录的时候，有两种情况：
        @a 提示错误，不给删除

        @b 删除主表的记录，同时把外表中有引用主表的这条记录的外表记录都删除掉。 这个功能要想实现，
            要设置外键的属性： 聚合(一对多)的上面，把聚合属性勾上就行了。
      */
}

void GlodonLearn::glodon_professionals_call()
{
    /**
    \brief 甲方评标材料表 和 评标甲供材料表 @a 区别

    @ 甲方评标材料表 = 甲方评标主要材料表 = 甲评 = 发包人主要材料表

    @ 暂定材料表 = 暂估材料



      */
}

void GlodonLearn::glodon_jira_wiki()
{
    /**
    @ 每次晨会结束了后要把记录录入wiki里面


      */
}

void GlodonLearn::glodon_Service_Table()
{
    /**
    D:\GBQPLATFORM\V3\Trunk\ProductPlatform\GBQ\Release\Regions\GuangDong\Model\招投标项目.GSP
    BidNode表的 NodeType 字段(枚举字段)，
    0=标段
    1=单项工程
    2=单位工程
    3=标段整体部分
    4=单项整体部分

    @ 在项目工程中，有一个标段表(BidNode),通过这个表的NodeType值得到对应的BidNode ID(主键)
        通过bidService获得对应的Service。 例如：

        获得标段表
        GSPTable bidNode = m_piBidService->getProjModel().findTable(dbnBusinessDB, ptnBidNode);

        GSPRecord record = bidNode.locate(pfnNodeType,2);
        IGBQJobService* pJobService = m_piBidService->openJob(record.id());

        可以通过查找这个函数的用法来了解
        GBQBidService::findJobService(int bidNodeID);

      */
}

void GlodonLearn::glodon_question()
{
    glodon_operator_table();
}

void GlodonLearn::glodon_business()
{
    /**
    @ 补充清单是自己自定义的清单，比如在分部分项中添加库里没有的清单，这些就是补充清单
      \brief 借别的库的叫借项

    @


      */
}

void GlodonLearn::glodon_operator_table()
{
    glodon_GSP_Database();
    glodon_question();
    glodon_create_GUI();

    /**
      从 oMainMaterialTable这个表中得到表结构，然后从表结构中得到这个表的列的列表
      从列的列表中查找是否存在有 pfnAutoMainMaterial 字段

    @ oMainMaterialTable.tableSchema().fieldSchemas().find(pfnAutoMainMaterial)

      判断这个记录是否有这个字段
    @ oMainMaterialTable[i].findField(pfnAutoMainMaterial) != NULL

    @ 在项目工程中，有一个BidInfo的表，现在 BidInfo已经改成 projInfo

    @ 如果配的GSF文件没有显示出来，先把GSF文件打开，运行，如果没有提示错误，那么有可能是选择的模型不对。
      如果GSF提示错误，就把错误解决了。

    @ 如果操作表的时候，出现报错，这时有几种情况要考虑：
        @a 如果提示 @brief 字段值 重复，那么可能是因为Model在操作的时候先设为 @brief 加载期，
            然后修改后设置为 @brief 运行期 ,这个时候就会检查字段，所以才报错。

        @b 如果提示 @brief 当前操作只能在装载期执行 ，那么可能是代码里面直接修改了 @brief 计算字段，
           计算字段只能在装载期被修改，不能再运行期被修改。

    @ 处理表达式字段时，有两种情况要考虑， 比如，有一个表达式字段 A + B ，其中 A = 1， B = 2。
        @a 表达式的结果，当你要把这个字段赋值给另一个表的字段的时候， 是直接 asVariant()把结果赋值过去。

        @b 表达式， 直接把 A + B 的表达式赋值给另一个表的字段

    @ 导入标书的时候，Summary 什么时候生成，处理Summary的时候，要记住处理一下两个表。
        @a BasicSummary(计价程序)

        @b LevyFeeTaxItem(规费税金表)
       费用汇总是由这两个表合成的。
       
    @ 属性表是不能修改的，也不能删除，但是可以修改值。因为它里面只有一条记录。
        @a 判断属性表if(dst.tableKind() == tkPropTable)

    @ 查找表是通过table.fullName() 来查找的
    */
}

void GlodonLearn::glodon_model()
{
    glodon_table();
    glodon_field();
    glodon_record();
    /**
    添加功能
    void batchInsertRecord(const GSPRecordList & records, const GSPIntegerList & nextRecordIDs);

    把records 从model中删除，他会找到records里的每一条记录对应的表，然后从表中删除这条记录
    void batchRemoveRecord(const GSPRecordList & records);


      */
}

void GlodonLearn::glodon_table()
{
    glodon_model();
    glodon_field();
    glodon_record();

    /**
     * @brief locate
     * @param keyFields  表里面的字段
     * @param keyValues  字段的值
     * @return  返回表中字段 keyFields = keyValues 的记录
     *
    GSPRecord locate(const GString & keyFields, const GVariant & keyValues);

    **
     * @brief locateEx
     * @param condition 过滤条件 类似 SQL 语句的过滤条件
     * @param fromIndex 从那天记录开始查找
     * @return  返回符合添加的第一条记录
     *
    GSPRecord locateEx(const GString & condition, long fromIndex = 0);
      */
}

void GlodonLearn::glodon_field()
{
    glodon_model();
    glodon_table();
    glodon_record();

    /**


      */
}

void GlodonLearn::glodon_record()
{
    glodon_model();
    glodon_table();
    glodon_field();

    /**
    找到这条记录下的子记录，这些子记录有个通性，都是有一个外键，引用这个记录的主键
    GSPRecordList detailRecords(const GString & detailTableName, const GString & refPath = GString(), bool recur = false);

    @brief 如果想通过记录的外键字段找的主表记录，需要注意几点：
        @a  模型的状态
            如果模型不是运行期，那么就得不到主表的记录


      */
}

void GlodonLearn::glodon_eventHandler()
{
    /**
    @ 鼠标操作调用接口，所有的接口都在 GLDGridEventHandler 里定义了接口。
      只要定义 @brief GLDGridFrame 的虚函数

      virtual GLDGridEventHandler *createGridEventHandler();
      这个接口在 void GLDGridFrame::initialize() 函数里被调用，这样可以为
      每个 @brief GLDGridFrame 初始化一个 GLDGridEventHandler 对象处理事件。

    @ virtual void GLDGridEventHandler::onDrop(
            QVector<GSPCustomRowNode *> fromRowNodes,
            GSPCustomRowNode *toRowNode, bool &handled);
      这个函数是处理鼠标拖拽事件时鼠标松开的事件。

    @ virtual void GLDGridEventHandler::onDragMove(
            QVector<GSPCustomRowNode *> fromRowNodes,
            GSPCustomRowNode *toRowNode, bool &handled);
      */
}

void GlodonLearn::glodon_buildingProj()
{
    glodon_workspaceFrame();
    glodon_moduleGroupFrame();
    glodon_moduleFrame();
    glodon_slaveGroupFrame();
    glodon_gridFrame();

    glodon_use_function();

    /**
    @   创建建筑工程 创建的 GBQJobWorkSpaceFrame 这个工作空间
        创建 GBQProjProfileGroupFrame 的GBQModuleGroupFrame 的派生类 （创建一次）
        创建 GBQProjInfoModuleFrame 的 GBQModuleFrame 的派生类
        (创建两个，一个管理 Master，另一个管理 Slave, 这里没有创建 SlaveGroupFrame，和 SlaveFrame)

        创建 GBQProjInfoGridFrame 的 GLDGridFrame 派生类

        到此结束
      */
}

void GlodonLearn::glodon_proj()
{
    glodon_workspaceFrame();
    glodon_moduleGroupFrame();
    glodon_moduleFrame();
    glodon_slaveGroupFrame();
    glodon_gridFrame();

    glodon_use_function();

    /**
    @   创建 GBQBQGroupFrame 的GBQModuleGroupFrame 的派生类 （创建一次）
        创建 GBQBQFrame 的 GBQModuleFrame 的派生类 ( 创建一次)
        创建 GBQBQGridFrame 的 GLDGridFrame 的派生类 (创建一次 用于 Master 的表格显示 )
        创建 GBQBQSlaveGroupFrame 的 GLDSlaveGroupFrame 的派生类 (创建一次)

        \brief 工料机显示
        创建 GBQResourceConvertFrame 的 GLDSlaveFrame 的派生类 ( 工料机显示 )
        创建 GBQResourceConvertGridFrame 的GLDGridFrame 的派生类 (工料机显示 )

        \brief 查看单价构成
        创建 GBQViewRateDetailFrame 的 GLDSlaveFrame 的派生类
        创建 GBQViewRateDetailGridFrame 的 GLDGridFrame 的派生类

        \brief 特征与内容
        创建 GBQSpecGroupFrame 的 GBQSLaveGroupFrame 的派生类
        创建 GBQBQSpecAndWorkScopeFrame 的 GLDSlaveFrame 的派生类
        
    @   GBQGridFrame
        GSPAfterUpdateFieldImpl -> GBQWorkScopeGridFrame (分部分项 Slave::GLDGridFrame 特征与内容)

    @   GBQGridFrame
        GSPAfterUpdateFieldImpl
        GSPAfterInsertRecordImpl
        GSPAfterDeleteRecordImpl
        GSPAfterMoveRecordImpl          -> GBQSpecGridFrame (分部分项 Slave::GLDGridFrame 特征与内容)

    @   GBQGridFrame -> GBQSpecSchemeGridFrame (分部分项 Slave::GLDGridFrame 特征与内容)

    */
}
