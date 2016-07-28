#ifndef EPSYBEROS_H
#define EPSYBEROS_H

class EPSyberos
{
public:
    EPSyberos();

    void qdbus();

    /**
      场景：打电话中
      */
    void cmos_voicecall_component();

    void cmos_voicecall_translate();

    /**
     * 拨号限制 20 位以内可以拨出
     */
    void cmos_voicecall_limit();

    void cmos_root();

    void cmos_obs();

    void cmos_gerrit();

    void cmos_spec();

    void cmos_git();

    void cmos_qmake();
    /**
    @brief  每一个对象或者组件需要注意的地方
      */
    void cmos_object();

    void cmos_work_error();

    void cmos_wiki();

    void cmos_gdb();

    void cmos_dbus();
    /**
     * @brief voicecall里面的 main.qml 的函数说明
     *
     */
    void cmos_ui_main();

    void cmos_ui_activeCallDialog();

    void cmos_signal_order();

    void cmos_ui_activeCallDialog_addBlacklist();

    /**
      关于dbus接口调用不成功,有可能是权限问题的修改
     */
    void cmos_permission();

    /**
     voicecall.spec 文件和 src.pro 文件的联系
     */
    void cmos_spec_pro();

    /**
     手机Home, Menu, Back
     */
    void cmos_key();

    void need_to_do();

    void google();

    /**
     sb2 的搭配文件
     */
    void sb2_env();

    void andriod_env();
    void android_compile();
    void kernel_compile();
    void ios_env();

    void syberos_sdk();

    void years();

    void forget();

    void voicecall_Tp();

    /**
      diff  xuanwu from millet and main_dev
      */
    void git_push_id();

    void contact_rebuild();

    /**
      bochs
      */
    void bochs_configure();

    /**
      qml error
      */
    void qmlError();

    /**
     * @brief install_sublime
     */
    void install_sublime();
};

#endif // EPSYBEROS_H
