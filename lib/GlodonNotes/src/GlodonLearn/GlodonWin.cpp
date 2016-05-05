#include "GlodonWin.h"
#include <QDebug>

GlodonWin::GlodonWin()
{
}

void GlodonWin::win32_Library()
{
    /**

      */
}

void GlodonWin::win32_Delphi_Library()
{
    /**
    @ 动态链接库 (DLL)
      动态链接库是程序模块，它包括代码‘数据和资源，能够被其他windows应用程序共享。

      @ 特点
        应用程序可以在运行时调入代码执行，而不是编译时链接代码，因此，多个程序可以
        共享同一个DLL代码。
      */
}

void GlodonWin::win32_error()
{
    /**
    @ 早上更新的windows—— update 后，发现qtcreator编译不过，
        总是提醒  LNK1123: 转换到 COFF 期间失败: 文件无效或损坏

    C:\Program Files\Microsoft Visual Studio
    10.0\VC\bin

    C:\Windows\winsxs\x86_netfx-cvtres_for_vc_and_vb_b03f5f7f11d50a3a_6.1.7600.16385_none_ba476986f05abc65

    C:\Windows\Microsoft.NET\Framework\v4.0.30319

    这三个路径里面都有cvtres.exe文件，尝试使用第二个路径里面的文件替换第一个路径的文件，问题解决。

    （这个问题是windows自动更新造成编译器cvtres.exe的版本过低，
    如果windows再次更新，则还可能出现这样的问题，届时再重复一下上述步骤即可。）


    ************************
    ************************

    @brief 当编译程序，发现有的文件没有权限。 解决方法：
    文件夹属性 -> 安全 -> 编辑（选择用户，修改读写权限，保存）



  */
}

