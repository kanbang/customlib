#ifndef GLODONBUSINESS_H
#define GLODONBUSINESS_H

#include "glodonlearn_global.h"

class GlodonLearn;
class GlodonClassDescription;

class GLODONLEARNSHARED_EXPORT GlodonBusiness
{
public:
    GlodonBusiness();

    /**
     * 更新招标书的业务逻辑，如何更新，更新步骤
     */
    void glodon_updateEbidding();
    /**
     * @brief glodon_encrypt
     Q5的工程加密
     */
    void glodon_encrypt();

private:
    GlodonLearn *m_pLearn;
    GlodonClassDescription *m_pClass;
};

#endif // GLODONBUSINESS_H
