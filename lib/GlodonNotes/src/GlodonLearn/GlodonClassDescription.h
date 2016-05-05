#ifndef GLODONCLASSDESCRIPTION_H
#define GLODONCLASSDESCRIPTION_H

#include "glodonlearn_global.h"

/**
    这个类主要是为了Business服务的，Business是业务的逻辑，
    这个类是业务逻辑的代码实现
 */

class GlodonBusiness;

class GLODONLEARNSHARED_EXPORT GlodonClassDescription
{
public:
    GlodonClassDescription();

    /**
    GBQBidBDSBuildService::buildBDSData(
                        const GString &bdsFile, bool needEstiData)
     */
    void buildBDSData();

    void workspace();
private:
    GlodonBusiness* m_pBusiness;
};

#endif // GLODONCLASSDESCRIPTION_H
