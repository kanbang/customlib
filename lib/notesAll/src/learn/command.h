#ifndef COMMAND_H
#define COMMAND_H

/**
 * @brief The command class
 这个类主要是用来记录linux的命令说明的

 */
class command
{
public:
    command();

    void ACL();
    void alias();
    void anacron();
    void apropos();
    void array();
    void at();
    void atq();
    void atrm();
    void auditd();
    void audit2why();
    void awk();

    void badblocks();
    void basename();
    void bash();
    void bashrc();
    void batch();
    void bg();
    void BIOS_vs_CMOS();
    void bc();
    void block();
    void boot_loader();
    void bzip2();
    void bzcat();

    void cal();
    void _case();
    void cat();
    void cd();
    void cdrecord();
    void chage();
    void chattr();
    void chcon();
    void chfn();
    void chgrp();
    void chkconfig();
    void chkconfig_example();
    void chkfontpath();
    void chmod();
    void chown();
    void chpasswd();
    void chroot();
    void chsh();
    void cksum();
    void cmp();
    void col();
    void colrm();
    void comm();
    void compress();
    void cp();
    void cpio();
    void crontab();
    void csplit();
    void cups();
    void cut();

    void date();
    void dbus();
    void dd();
    void dd_example();
    void declare();
    void depmod();
    void device();
    void dmesg();  //查看网卡是否被核心识别
    void df();
    void diff();
    void diffstat();
    void dirs();
    void du();

    void echo();
    void ed();
    void edquota();
    void egrep();
    void eject();
    void env();
    void ex();

    void fdisk();
    void fgrep();
    void file();
    void find();
    void find_example();
    void fmt();
    void fold();
    void ftp();
    void ftp_example();

    void getfacl();
    void git();
    void git_example();
    void gitview();
    void grep();
    void grep_example();
    void groupadd();
    void groupadd_example();
    void groupdel();
    void groupdel_example();
    void gzip();
    void gzip_example();
    void gdb();
    void gdb_example();

    void iconv();
    void iconv_example();
    void in();
    void insmod();
    void indent();
    void ispell();

    void jed();
    void joe();
    void join();

    void kill();

    void less();
    void ln();
    void local();
    void locate();
    void look();
    void ls();
    void lsattr();
    void lsmod();
    void lftp();

    void mattrib();
    void mc();
    void mcd();
    void mcopy();
    void mdel();
    void mdir();
    void mktemp();
    void mmove();
    void modinfo();
    void modprobe();
    void more();
    void mount();
    void mount_example();
    void mread();
    void mv();

    void nautilus();
    void nm();

    void od();

    void passwd();
    void passwd_example();
    void paste();
    void patch();
    void ps();
    void ps_example();
    void pgrep();

    void qdebug();
    void qdebug_example();

    void rcp();
    void rhmask();
    void route();
    void rm();
    void rpm();
    void rpm_example();
    void rpmbuild();
    void rpmbuild_example();

    void scp();
    void sed();
    void sed_example();
    void service();
    void setfacl();
    void setup();
    void slocate();
    void split();
    void ssh();
    void strings();
    void strings_example();
    void su();
    void su_example();
    void sudo();
    void sudo_example();

    void tar();
    void tar_example();
    void tar_install();
    void tee();
    void tmpwatch();
    void top();
    void touch();
    void type();

    void umask();
    void uname();
    void unrar();
    void useradd();
    void useradd_example();
    void userconf();
    void userdel();
    void usermod();

    void whereis();
    void which();

    void xhost();
    void xhost_example();

    void yum();

    void zip();
private:
    void insmod_modprobe();

    void installBase();

};

class bashCommand
{
public:
    bashCommand();
};

#endif // COMMAND_H
