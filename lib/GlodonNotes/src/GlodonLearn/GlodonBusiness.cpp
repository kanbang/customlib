#include "GlodonBusiness.h"
#include "GlodonLearn.h"
#include "GlodonClassDescription.h"

GlodonBusiness::GlodonBusiness()
{
    m_pLearn = new GlodonLearn();
    m_pClass = new GlodonClassDescription();
}

void GlodonBusiness::glodon_updateEbidding()
{
    m_pClass->buildBDSData();
    /**
    @ 电子招标书的形成。
      @brief 招标方填写自己的清单组价，然后生成XML文件，生成XML文件的时候，是要根据
             各个地区定义的接口来导出电子招标书的。

      @brief 投标方把XML文件导入到投标工程中，这里有两个步骤：
        @a 把XML文件导入生成BDS，BDS也是个GSP文件，BDS里面说明了导入的规则。
        @b 把BDS生成GBQ文件，把XML里的内容根据BDS导入到GBQ的对应的表的。

        @note 函数实现在：

      @brief

      */
}

void GlodonBusiness::glodon_encrypt()
{
    /**
    在Q5保存的压缩文件中，在Bid.GSP的模型中，有一个Option表，表里有ProjGUID字段，这个字段要和
    bid对应的Config.GSP里面的 sProjGUID 对应才能打开。这是为了盗版

    GSPTable oOptionTbl = srcBidModel.findTable(dbnBusinessDB, ptnOption);
    GString sProjGUID = oOptionTbl[0].asString(pfnProjGUID);
    GSPTable odstOptionTbl = dstBidModel.findTable(dbnBusinessDB, ptnOption);
    odstOptionTbl[0].findField(pfnProjGUID).setAsString(sProjGUID);
      */
}
