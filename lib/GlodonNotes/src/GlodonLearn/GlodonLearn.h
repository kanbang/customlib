#ifndef GLODONLEARN_H
#define GLODONLEARN_H

#include "glodonlearn_global.h"

class GlodonBusiness;
class GLODONLEARNSHARED_EXPORT GlodonLearn
{

public:
    GlodonLearn();

    /**
      \brief 广联达系统架构 - 类继承关系

      */
    void glodon_GLDFrame();
    void glodon_navigator();
    void glodon_mdichild();
    void glodon_mainform();

    void glodon_code_standard();
    void glodon_UIFacade();
    void glodon_UIPlugin();
    void glodon_frameLayout();
    void glodon_extension();
    void glodon_UIService();

    /**
      \brief 函数调用过程
      */
    void glodon_use_function();

    /**
     * @brief glodon_svn
     */
    void glodon_svn();

    /**
      \brief 系统翻译
      */
    void glodon_ts_GPS();

    /**
      \brief 广联达GSP(数据库)框架
      */
    void glodon_GSP_Database();

    /**
      \brief 工作函数使用类
      */
    void glodon_work();

    /**
      \brief qtcreator 的语言翻译流程
      */
    void glodon_translation();

    /**
      \brief 表操作
      */
    void glodon_operator_table();

    /**
      \brief 编程思想
      */
    void glodon_thought();

    /**
     * @brief 创建界面顺序
     */
    void glodon_create_GUI();

    /**
     * @brief 操作GSF
     */
    void glodon_operator_gsf();
    /**
     * @brief 创建GSP时， 引用主表的非主键字段的设置方法
     */
    void glodon_foreignKey();

    /**
     * @brief 专业名词
     */
    void glodon_professionals_call();

    /**
     * @brief 晨会流程
     */
    void glodon_jira_wiki();

    /**
     * @brief 通过Service 操作得到对应的Model和对应的Table
     *
     */
    void glodon_Service_Table();

    /**
     * @brief 疑难问题，比如有些函数不懂是什么意思，
     *
     */
    void glodon_question();

    /**
     业务操作，
     */
    void glodon_business();
private:
    void glodon_workspaceFrame();
    void glodon_moduleGroupFrame();
    void glodon_moduleFrame();
    void glodon_slaveGroupFrame();
    void glodon_gridFrame();

    /**
     * @brief 关于model函数的说明
     */
    void glodon_model();
    /**
     * @brief 关于Table函数的说明
     */
    void glodon_table();
    /**
     * @brief 关于field函数的说明
     */
    void glodon_field();

    /**
     * @brief 关于record函数的说明
     */
    void glodon_record();

    /**
     * @brief 关于鼠标操作的时间调用
     */
    void glodon_eventHandler();
    /**
      \brief 创建建筑工程
      */
    //  切换到 工程概况 页签 Master
    void glodon_buildingProj();
    //  切换到分部分项 Slave
    void glodon_proj();
    //

private:
    GlodonBusiness *m_pBuisness;
};

#endif // GLODONLEARN_H
