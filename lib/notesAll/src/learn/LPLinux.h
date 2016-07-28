#ifndef LPLINUX_H
#define LPLINUX_H

#include <QString>
#include <command.h>

class LPLinux
{
public:
    /**
     \brief     关于linux的一些常用知识
     */
    LPLinux();
    /************底层库***************************************/
    void aboutLib();
    void linuxCodes();
    void linuxMakefile();

    /**
     \brief     关于环境变量
     */
    void    enviroment();
    /**
     \brief     安装软件
     */
    void    installSoftware();
    /**
     \brief     字符编码转换
     */
    void    transformEncoding();
    /**
     \brief     用lftp下载文件夹
    */
    void    ftpLoadFile();
    /**
     \brief 查看主机服务状态  mount挂载
     **/
    void    serviceStatus();
    /**
     \brief     svn 添加文件
     */
    void    aboutSVN(QString svn);
    /**
     \brief     结束进程
     */
    void    killProgress();
    /**
     \brief     linux查找文件.
     */
    void    findFile();
    /**
     \brief     压缩命令
     */
    void    CompressCommand();
    /**
     \brief     修改文件和合并代码
     */
    void    modifyFile();
     /**
      \brief     像素和厘米、毫米的转换
     */
    void    pixelAndCentimeter();
    /**
     \brief     平时算法
     */
    void    algorithm();
    /**
     \brief     linux command
     */
    void    linuxCommand();
    /**
     \brief 相关公司的类似软件－有机会找来参考。
     */
    void    softwareCompany();

private:
    command m_cmd;
};

#endif // LPLINUX_H
