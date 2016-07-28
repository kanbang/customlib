#ifndef LPUBUNTU_H
#define LPUBUNTU_H

class LPUbuntu
{
public:
    LPUbuntu();
    //禁用更新软件，支持(apport)
    void apport();

    /**
      \brief ubuntu 64位系统运行32位
      */
    void x64_run_x32();

    /**
      ubuntu 更新后进不了图形界面
      */
    void update_unenter();
    void vim();

    void Terminal_changePage();

    void ubuntu_fcitx();
    void ubuntu_workspace();
};

class ubuntuCommand
{
public:
    ubuntuCommand();

    void apt_get();
    void apt_file();

    void syberos_process();
    void syberos_install_lib();
    void syberos_work();

    void git();
    void git_example();
    void git_error();

};

#endif // LPUBUNTU_H
