#ifndef GLODONWIN_H
#define GLODONWIN_H

#include "glodonlearn_global.h"

class GLODONLEARNSHARED_EXPORT GlodonWin
{
public:
    GlodonWin();


    //win32的链接库基础知识
    void win32_Library();
    void win32_Delphi_Library();

    /**
     * @brief 一些编译错误的解决方法
     */
    void win32_error();
};

#endif // GLODONWIN_H
