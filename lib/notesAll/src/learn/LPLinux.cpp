#include <LPLinux.h>

LPLinux::LPLinux()
{
    /**
     @ 但凡跟网络有关的东西，先查看防火墙

     @ linux 网络连接 代理
       192.168.20.254 808

     @ ftp 192.168.17.20 报bug
       anonymous

     @ ades的ip 地址
       192.168.17.23

     @ root密码
       root1234

     @ 关于环境变量的问题
       如在路径 /usr/local/bin/下有一执行文件，exe;如果不添加环境变量，那么，要想执行exe，则需要输入：
       /usr/local/bin/exe,如果有个路径的环境变量，则输入exe就行。
       PATH1=/usr
       PATH = $(PATH1)/local/bin/
       PATH = $PATH:/usr/local/Trollecth/Qt/designer/...

     @ ldd 是用来查看程序需要那些链接库的。 ldd dataManager(执行文件);

     @ 虚拟机和系统文件的共享设置，先在虚拟机vm选项中找到settings->Options->shared folders设置，然后到虚拟机我的电脑映射下添加。
    */

    m_cmd.xhost();
    m_cmd.xhost_example();
    /**
     @ 关于如何xmanager,xhost +,rsh(ssh) ip地址 -l 用户名  输入密码  export DISPLAY=ip地址(本台机器):0.0,(echo $DISPLAY)
       setenv（设置可见）
       192.100.101.6
       用户名 test   test123

     @ 查看电脑配置
       windows
       一、 我的电脑->属性
       二、 cmd->dxdiag

     @ 查看电脑系统
       linux
       1、 uname -a
       2、 cat /proc/version
       3、 cat /etc/issue   cat  /proc/cpuinfo
       4、 lsb_release -a

     @ /sbin/ifconfig   查看ip地址

     @ env 查看环境变量

     @ 程序后台，前台
       后台 ： 在输入命令后面加&
       前台 ： ctrl+z 或者bg

     @ 查看版本
       $ cat /etc/issue 或者 cat /etc/redhat-release

     @ 查看文件的大小
       du -h --max-depth=1 /home/xkd/software/qtcreator-2.5.2
       df 统计数据块使用情况

     @ 用命令进入U盘的路径
       在linux中，U盘的路径在 /media/disk-1/

     @ 上google
       https://www.out1000.com/
       http://www.gfsoso.com/
       http://216.58.210.78/
       http://74.125.133.138/
    */
}

void LPLinux::aboutLib()
{
    /**
     *误删除libc.so.6后的修复  /lib/libc.so.6 -> libc-2.3.6.so（系统中本来的样子）
    然后
    libc-2.3.6.so 被误改名成了 libc-2.3.6.so.bak
    这时，系统中ls, mv ,ln 等等命令已经不能使用了

    # LD_PRELOAD=<real libc> ln ......
    相当于直接调用 ln命令，
    所以，
    先删除连接 ：
    # cd /lib
    # LD_PRELOAD=/lib/libc-2.3.6.so.bak rm libc.so.6
    再建立新连接 ：
    # LD_PRELOAD=/lib/libc-2.3.6.so.bak ln -s /lib/libc-2.3.6.so.bak libc.so.6

    搞定，
    运气好的是，出问题后，我没有关机，这个库也是被改名的，不是被删除的，
    这个故事教导我们，一定不要乱搞系统的库，有什么比较危险的动作时，一定做好备份

    如果用qtcreator编译好的程序在终端中运行不了，那就可能是LD_LIBRARY_PATH这个库没有添加，
    在qtcreator中可以运行，那是因为qtcrator会自动去找到这些库，但是在终端中不行，终端运行要
    依赖PATH和LD_LIBRARY_PATH这个两个环境变量。

    ./qt-linux-opensource-5.2.0-x86-offline.run: /usr/lib/libstdc++.so.6: version `GLIBCXX_3.4.9' not found
        (required by ./qt-linux-opensource-5.2.0-x86-offline.run)
    安装程序(发现问题是在安装qtcreator的时候发现的)如果出现某些库没有。提醒类似上面的，可以用下面的命令查查有没有。

    @brief strings /usr/lib/libstdc++.so.6 |grep GLIBC

    如果没有，解决问题的方法：
    @ 从网上下载libstdc++.so.6链接的新库： libstdc++.so.6.0.13
    同时把 libstdc++.so 删除掉。 重新创建链接。

    rm /usr/lib/libstdc++.so.6
    ln -s /usr/lib/libstdc++.so.6.0.13 /usr/lib/libstdc++.so.6
    这样就好了。

    */
}

void LPLinux::linuxCodes()
{
    /**
     @ linux编程
     g++ 生成 .o 文件不需要库，但需要 .h 文件。
     生成执行文件的时候需要库和头文件

     举例说明：
     环境说明： 在当前文件中有 两个文件夹 color test 。 里面分别有 color.h 和 test.h 。同时，当前文件中还有 color.cpp test.cpp main.c文件

     ///color.h
    class color
    {
    public:
        color();
        void showColor();
    };

    ///color.cpp
    #include"color.h"
    #include<iostream>
    using namespace std;

    color::color()
    {
        cout<<"color constructed:"<<endl;
    }

    void color::showColor()
    {
        cout<<"the dog's color is white"<<endl;
    }

    ///test.h
    #include"color.h"
    class Dog
    {
    public:
      Dog (int age);
      void show ();
    private:
      int m_age;
      color col;
    };

    ///test.cpp
    #include"test.h"
    #include<iostream>
    using namespace std;

    Dog::Dog (int age):
    m_age (age)
    {
        col = color();
    }

    void
    Dog::show ()
    {
      cout << "Dog's Age is " << m_age << endl;
      col.showColor();
    }

    ///main.c
    #include"test.h"

    int
    main ()
    {
      Dog dog (4);
      dog.show ();
      return 0;
    }

    //因为color.h 在 ./color 里面，所以这里需要头文件
    //在执行g++或者gcc时不会自动从VPATH 或者vpath中自动搜索要包含的头文件等信息文件
    g++ -fpic -c color.cpp  -I ./color（默认是在当前找）

    //这里的test需要引用color这个对象，因此除了需要test里的头文件外，还需要color里的头文件
    g++ -fpic -c test.cpp   -I ./color -I ./test

    //生成 .o 文件后，要利用 .o 文件生成库
    g++ -shared -o ../libtest.so color.o test.o

    @ g++ -shared -o ../libcolor.so color.o
    @ g++ -shared -o ../libtest.so test.o(此处如果是这样就结束，那么后期链接库的时候就找不到color的接口),因此要改为：
      g++ -shared -o ../libtest.so test.o -L ../ -lcolor (由于是动态库链接，所以最后编译main.c的时候，还要把这个库链接上）
      g++ main.c -o main.exe -L ../ -ltest -lcolor -I ./color -I ./test

    @a g++ -shared -o ../libtest.so test.o color.o
       g++ main.c -o main.exe -L ../ -ltest -I ./color -I ./test

     */
}

void LPLinux::linuxMakefile()
{
    /**
     @a   gcc -c main.c   这是编译
     @b  gcc main.o -o exe   这是链接

     @ Makefile 文件的写法
     @a Makefile有三个非常有用的变量  $@, $^, $< 分别代表 目标文件  所有的依赖文件  $< 第一个依赖文件

     //下面这句话的意思是，如果所有的依赖文件中有一个比 main.exe 新，那么就重新执行command的命令
        main.exe: color.cpp test.cpp main.c
        g++ -fpic -c $< -I ./color
        g++ -fpic -c test.cpp -I ./test -I ./color
        g++ -shared -o ../libtest.so color.o test.o
        // 如果把main.exe 改成 main.exe11或者其他不是main.exe的字符，也就是和目标不同的字符，那么每次都会编译
        // 因为依赖文件和目标文件始终不再一个时间上
        g++ main.c -o main.exe -L ../ -ltest -I ./color -I ./test

        color  = ./color
        test   = ./Test
        vpath %.h color

        main: main.o test.o color.o
            g++ -o main main.o test.o color.o
            echo "execute main.exe:"

        color.o:$(color)/color.h
            g++ -c color.cpp -I ./color
            echo "execute color"
        test.o:$(color)/color.h
            g++ -c test.cpp -I ./color -I ./Test
            echo "execute test"
        main.o:$(test)/test.h $(color)/color.h
            g++ -c main.c -I ./color -I ./Test
            echo "execute main"

        clean:
            rm *.o main

      @brief
      main:main.o thanks.o hello.o
        gcc main.o thanks.o hello.o -o main

      .c.o:  //把所有的.c文件都编译成 .o文件
        gcc -c -o "$@" "$<"

     */
}

void LPLinux::enviroment()
{
    /**
    @ LD_LIBRARY_PATH 这个环境变量是程序运行的时候搜索库用的

    @ VPATH 这个环境变量是程序编译的时候找头文件的依赖路径。如果不写，那么就在当前路径下找。如果写了。
      那么在当前路径下找不到的情况下，会往VPATH这个路径下找。如果定义了多个路径，那么要用冒号隔开。

    一、Linux的变量种类

    按变量的生存周期来划分，Linux变量可分为两类：

    1. 永久的：需要修改配置文件，变量永久生效。

    2. 临时的：使用export命令行声明即可，变量在关闭shell时失效。

    二、设置变量的三种方法

    1. 在/etc/profile文件中添加变量【对所有用户生效（永久的）】

    用VI在文件/etc/profile文件中增加变量，该变量将会对Linux下所有用户有效，并且是“永久的”。

    例如：编辑/etc/profile文件，添加CLASSPATH变量

    # vi /etc/profile

    export CLASSPATH=./JAVA_HOME/lib;$JAVA_HOME/jre/lib

    注：修改文件后要想马上生效还要运行# source /etc/profile不然只能在下次重进此用户时生效。

    2. 在用户目录下的.bash_profile文件中增加变量【对单一用户生效（永久的）】

    用VI在用户目录下的.bash_profile文件中增加变量，改变量仅会对当前用户有效，并且是“永久的”。

    例如：编辑guok用户目录（/home/guok）下的.bash_profile

    $ vi /home/guok/.bash.profile

    添加如下内容：

    export CLASSPATH=./JAVA_HOME/lib;$JAVA_HOME/jre/lib

    注：修改文件后要想马上生效还要运行$ source /home/guok/.bash_profile不然只能在下次重进此用户时生效。

    3. 直接运行export命令定义变量【只对当前shell（BASH）有效（临时的）】

    在shell的命令行下直接使用[export变量名=变量值]定义变量，该变量只在当前的shell（BASH）或其子shell（BASH）下是有效的，shell关闭了，变量也就失效了，再打开新shell时就没有这个变量，需要使用的话还需要重新定义。
    三、另外

    1.使用readonly命令设置只读变量，如果使用了readonly命令的话，变量就不可以被修改或清除了。

    2.使用unset命令来清除环境变量 $ unset TEMP_KEVIN #删除环境变量TEMP_KEVIN

    /usr/local/qtcreator-2.0.0/lib:/usr/local/qtcreator-2.0.0/lib/qtcreator:/usr/local/OpenInventor/arch-Linux-x86_64-gcc41-release/lib:/usr/local/Trolltech/Qt-4.6.4/lib
    */
}

void LPLinux::installSoftware()
{
    m_cmd.tar();
    m_cmd.tar_install();
    m_cmd.rpm();
    m_cmd.rpm_example();
}

void LPLinux::transformEncoding()
{
    m_cmd.iconv();
    m_cmd.iconv_example();
}

void LPLinux::ftpLoadFile()
{
    /**
      @ 用下载文件夹
      $ lftp
      $ open ftp://192.100.100.8
      $ mirror  -vn 要下载的路径  放在本地的路径

      ftp配置
      @ http://www.cnblogs.com/allenblogs/archive/2011/05/24/2055019.html

      @ 如果是在/home/xkd这个目录下打开ftp的，那么如果要在打开的机器(如 192.100.100.8)上传文件,用mput，
        如：
        $ mput xxx.tgz  (这个xxx.tgz文件要在打开ftp的目录下(也就是/home/xkd这个目录)。
        $ mget 是把文件下载都打开ftp的目录下。

      @ ssh下载文件
        scp [-pr] [-l 速率] file  [账号@]主机:目录名 <==上
        scp [-pr] [-l 速率] [账号@]主机:file  目录名 <==下载
        选项与参数：
        -p ：保留原本档案的权限数据；
        -r ：复制来源为目录时，可以复制整个目录 (含子目录)
        -l ：可以限制传输的速度，单位为 Kbits/s ，例如 [-l 800] 代表传输速限 100Kbytes/s

        OpenSSH是SSH连接工具的免费版本。telnet，rlogin和ftp用户可能还没意识到他们在互联网上传输的密码是未加密的，
        但SSH是加密的，OpenSSH加密所有通信（包括密码），有效消除了窃听，连接劫持和其它攻击。
        此外，OpenSSH提供了安全隧道功能和多种身份验证方法，支持SSH协议的所有版本。

        SSH是一个非常伟大的工具，如果你要在互联网上远程连接到服务器，那么SSH无疑是最佳的候选。
        下面是通过网络投票选出的25个最佳SSH命令，你必须牢记于心。

       （注：有些内容较长的命令，在本文中会显示为截断的状态。如果你需要阅读完整的命令，可以把整行复制到您的记事本当中阅读。）

        1、复制SSH密钥到目标主机，开启无密码SSH登录

        ssh-copy-id user@host如果还没有密钥，请使用ssh-keygen命令生成。

        2、从某主机的80端口开启到本地主机2001端口的隧道

        ssh -N -L2001:localhost:80 somemachine现在你可以直接在浏览器中输入http://localhost:2001访问这个网站。

        3、将你的麦克风输出到远程计算机的扬声器

        dd if=/dev/dsp | ssh -c arcfour -C username@host dd of=/dev/dsp这样来自你麦克风端口的声音
        将在SSH目标计算机的扬声器端口输出，但遗憾的是，声音质量很差，你会听到很多嘶嘶声。

        4、比较远程和本地文件

        ssh user@host cat /path/to/remotefile | diff /path/to/localfile
        –在比较本地文件和远程文件是否有差异时这个命令很管用。

        5、通过SSH挂载目录/文件系统

        sshfs name@server:/path/to/folder /path/to/mount/point
        从http://fuse.sourceforge.net/sshfs.html下载sshfs，它允许你跨网络安全挂载一个目录。

        6、通过中间主机建立SSH连接

        ssh -t reachable_host ssh unreachable_hostUnreachable_host表示从本地网络无法直接访问的主机，
        但可以从reachable_host所在网络访问，这个命令通过到reachable_host的“隐藏”连接，创建起到unreachable_host的连接。

        7、将你的SSH公钥复制到远程主机，开启无密码登录 – 简单的方法

        ssh-copy-id username@hostname8、直接连接到只能通过主机B连接的主机A

        ssh -t hostA ssh hostB当然，你要能访问主机A才行。

        9、创建到目标主机的持久化连接

        ssh -MNf <user>@<host>在后台创建到目标主机的持久化连接，将这个命令和你~/.ssh/config中的配置结合使用：

        Host host
        ControlPath ~/.ssh/master-%r@%h:%p
        ControlMaster no所有到目标主机的SSH连接都将使用持久化SSH套接字，如果你使用SSH定期同步文件
        （使用rsync/sftp/cvs/svn），这个命令将非常有用，因为每次打开一个SSH连接时不会创建新的套接字。

        10、通过SSH连接屏幕

        ssh -t remote_host screen –r直接连接到远程屏幕会话（节省了无用的父bash进程）。

        11、端口检测（敲门）

        knock <host> 3000 4000 5000 && ssh -p <port> user@host && knock <host> 5000 4000 3000
        在一个端口上敲一下打开某个服务的端口（如SSH），再敲一下关闭该端口，需要先安装knockd，下面是一个配置文件示例。

        [options]
        logfile = /var/log/knockd.log
        [openSSH]
        sequence = 3000,4000,5000
        seq_timeout = 5
        command = /sbin/iptables -A INPUT -i eth0 -s %IP% -p tcp –dport 22 -j ACCEPT
        tcpflags = syn
        [closeSSH]
        sequence = 5000,4000,3000
        seq_timeout = 5
        command = /sbin/iptables -D INPUT -i eth0 -s %IP% -p tcp –dport 22 -j ACCEPT
        tcpflags = syn12、删除文本文件中的一行内容，有用的修复

        ssh-keygen -R <the_offending_host>在这种情况下，最好使用专业的工具。

        13、通过SSH运行复杂的远程shell命令

        ssh host -l user $(<cmd.txt)更具移植性的版本：

        ssh host -l user “`cat cmd.txt`”14、通过SSH将MySQL数据库复制到新服务器

        mysqldump –add-drop-table –extended-insert –force –log-error=error.log \
        -uUSER -pPASS OLD_DB_NAME | ssh -C user@newhost “mysql -uUSER -pPASS NEW_DB_NAME”
        通过压缩的SSH隧道Dump一个MySQL数据库，将其作为输入传递给mysql命令，我认为这是迁移数据库到新服务器最快最好的方法。

        15、删除文本文件中的一行，修复“SSH主机密钥更改”的警告

        sed -i 8d ~/.ssh/known_hosts16、从一台没有SSH-COPY-ID命令的主机将你的SSH公钥复制到服务器

        cat ~/.ssh/id_rsa.pub | ssh user@machine “mkdir ~/.ssh; cat >> ~/.ssh/authorized_keys”
        如果你使用Mac OS X或其它没有ssh-copy-id命令的*nix变种，这个命令可以将你的公钥复制到远程主机，
        因此你照样可以实现无密码SSH登录。

        17、实时SSH网络吞吐量测试

        yes | pv | ssh $host “cat > /dev/null”通过SSH连接到主机，显示实时的传输速度，
        将所有传输数据指向/dev/null，需要先安装pv。

        如果是Debian：

        apt-get install pv如果是Fedora：

        yum install pv（可能需要启用额外的软件仓库）。

        18、如果建立一个可以重新连接的远程GNU screen

        ssh -t user@some.domain.com /usr/bin/screen –xRR人们总是喜欢在一个文本终端中打开许多shell，
        如果会话突然中断，或你按下了“Ctrl-a d”，远程主机上的shell不会受到丝毫影响，你可以重新连接，
        其它有用的screen命令有“Ctrl-a c”（打开新的shell）和“Ctrl-a a”（在shell之间来回切换），
        请访问http://aperiodic.net/screen/quick_reference阅读更多关于screen命令的快速参考。

        19、继续SCP大文件

        rsync –partial –progress –rsh=ssh $file_source $user@$host:$destination_file
        它可以恢复失败的rsync命令，当你通过VPN传输大文件，如备份的数据库时这个命令非常有用，需要在两边的主机上安装rsync。

        rsync –partial –progress –rsh=ssh $file_source $user@$host:$destination_file local -> remote
        或

        rsync –partial –progress –rsh=ssh $user@$host:$remote_file $destination_file remote ->\
         local20、通过SSH W/ WIRESHARK分析流量

        ssh root@server.com ‘tshark -f “port !22″ -w -' | wireshark -k -i
        –使用tshark捕捉远程主机上的网络通信，通过SSH连接发送原始pcap数据，并在wireshark中显示，
        按下Ctrl+C将停止捕捉，但也会关闭wireshark窗口，可以传递一个“-c #”参数给tshark，
        让它只捕捉“#”指定的数据包类型，或通过命名管道重定向数据，而不是直接通过SSH传输给wireshark，
        我建议你过滤数据包，以节约带宽，tshark可以使用tcpdump替代：

        ssh root@example.com tcpdump -w – ‘port !22′ | wireshark -k -i –21、保持SSH会话永久打开

        autossh -M50000 -t server.example.com ‘screen -raAd mysession’打开一个SSH会话后，
        让其保持永久打开，对于使用笔记本电脑的用户，如果需要在Wi-Fi热点之间切换，可以保证切换后不会丢失连接。

        22、更稳定，更快，更强的SSH客户端

        ssh -4 -C -c blowfish-cbc强制使用IPv4，压缩数据流，使用Blowfish加密。

        23、使用cstream控制带宽

        tar -cj /backup | cstream -t 777k | ssh host ‘tar -xj -C /backup’使用bzip压缩文件夹，
        然后以777k bit/s速率向远程主机传输。Cstream还有更多的功能，
        请访问http://www.cons.org/cracauer/cstream.html#usage了解详情，例如：

        echo w00t, i’m 733+ | cstream -b1 -t224、一步将SSH公钥传输到另一台机器

        ssh-keygen; ssh-copy-id user@host; ssh user@host这个命令组合允许你无密码SSH登录，
        注意，如果在本地机器的~/.ssh目录下已经有一个SSH密钥对，ssh-keygen命令生成的新密钥可能会覆盖它们，
        ssh-copy-id将密钥复制到远程主机，并追加到远程账号的~/.ssh/authorized_keys文件中，使用SSH连接时，
        如果你没有使用密钥口令，调用ssh user@host后不久就会显示远程shell。

        25、将标准输入（stdin）复制到你的X11缓冲区

        ssh user@host cat /path/to/some/file | xclip你是否使用scp将文件复制到工作用电脑上，
        以便复制其内容到电子邮件中？xclip可以帮到你，它可以将标准输入复制到X11缓冲区，
        你需要做的就是点击鼠标中键粘贴缓冲区中的内容。
      **/
}

void LPLinux::serviceStatus()
{
    m_cmd.service();
}

void LPLinux::aboutSVN(QString svn)
{
    svn = "svn: warning: 'icons' is already under version control";
    /**
      @ svn 添加icons的时候，由于目录已经存在了，所以，不能添加了。但是可以把想要添加的文件添加到该目录下。
      @ 不用 svn add icons，而是用svn add icons/Common/App/epoffic.png;
      @ 这是因为每个文件里面都有一个.svn （用命令 l.查看)控制。

      @ svn ci 文件名  有的文件名要求要添加说明  svn ci 文件名 -m ""

      svn 下载文件
      @ svn co(checkout) svn://192.100.100.86/epo/trunk xkd

      当在Qt中使用svn更新时，如果要求输入密码，这时候说明Qt中的svn没有保存密码，这时可以在终端中设置一下
      svn update --usename xkd(用户名）
      输入密码
      这样就记录下来了。（svn中每个命令都可以接usename这个参数）

      @ svn st 查看文件，如果是冲突的，那么就先自己写的文件备份，然后重新更新一次，最后对比两个文件修改。
        以 EPlogCurve.h为例
        cp  ./EPlogCurve.h    ../EPlogCurve.h.bak
        rm ./EPlogCurve.h
        svn update
        diff  ......
        但更新文件了后，Qt要把被更新的文件的内容加载进来，这时候应该选择yes to all，要不然文件会有改变。
        如果文件的一些内容删除了。可以用 svn查看

        svn log EPlogCurve.cpp|more  这里log是svn的目录
        这个命令是用来查看EPlogCurve.cpp 这个文件的修改情况的，比如谁修改了，以及修改的版本。如果想要提取那个版本
        这用下面这个命令
        svn export svn://192.100.100.86/epo/trunk/src/log/EPlogCurve.cpp -r 5548(版本号)
        得到的文件放下执行这个命令的目录下。所有不要在log这个文件下，要不然会把原来的文件覆盖掉

        U:表示从服务器收到文件更新了
        G:表示本地文件以及服务器文件都已更新,而且成功的合并了
        其他的如下:
        A:表示有文件或者目录添加到工作目录
        R:表示文件或者目录被替换了.
        C:表示文件的本地修改和服务器修改发生冲突
      ****/
}


void LPLinux::killProgress()
{
    m_cmd.ps();
    /**
      @ ps 命令用于查看当前正在运行的进程
        -e 显示所有进程,环境变量
        -f 全格式
        -h 不显示标题
        -l 长格式
        -w 宽输出

      @ ps -ef |grep qtcreator  知道qt的进程号.
        表示查看所有进程里 CMD 是 qtcreator 的进程信息

        kill 进程号
      @ ps -ef |grep gdb
        查看Qt Debug的进程
   **/
}

void LPLinux::findFile()
{
    m_cmd.find();
    /**
      @ find . -name "liblog.*"
      @ ls -l ./epoffice/lib/liblog.so 查看liblog.so的文件。

      @ 从根目录开始查找所有扩展名为.log的文本文件，并找出包含”ERROR”的行
        find / -type f -name "*.log" | xargs grep "ERROR"

      @ cat <文件名> | grep <关键字> 或者 用vi打开文件后，在命令行下输入“/关键字”  或者 grep "被查找的字符串" 文件名

        名称 : find
        用法 : find path -option [ -print ] [ -exec -ok command ] {} \;
        使用说明 :
        将档案系统内符合 expression 的档案列出来。你可以指要档案的名称、类别、时间、大小、权限等不同资讯的组合，只有完全相符的才会被列出来。
        find 根据下列规则判断 path 和 expression，在命令列上第一个 - ( ) , ! 之前的部份为 path，之后的是 expression。如果 path 是空字串则使用目前路径，如果 expression 是空字串则使用 -print 为预设 expression。

        expression 中可使用的选项有二三十个之多，在此只介绍最常用的部份。
        -mount, -xdev : 只检查和指定目录在同一个档案系统下的档案，避免列出其它档案系统中的档案
        -amin n : 在过去 n 分钟内被读取过
        -anewer file : 比档案 file 更晚被读取过的档案
        -atime n : 在过去 n 天过读取过的档案
        -cmin n : 在过去 n 分钟内被修改过
        -cnewer file :比档案 file 更新的档案
        -ctime n : 在过去 n 天过修改过的档案
        -empty : 空的档案-gid n or -group name : gid 是 n 或是 group 名称是 name
        -ipath p, -path p : 路径名称符合 p 的档案，ipath 会忽略大小写
        -name name, -iname name : 档案名称符合 name 的档案。iname 会忽略大小写
        -size n : 档案大小 是 n 单位，b 代表 512 位元组的区块，c 表示字元数，k 表示 kilo bytes，w 是二个位元组。-type c : 档案类型是 c 的档案。

        d: 目录
        c: 字型装置档案
        b: 区块装置档案
        p: 具名贮列
        f: 一般档案
        l: 符号连结
        s: socket
        -pid n : process id 是 n 的档案
        你可以使用 ( ) 将运算式分隔，并使用下列运算。
        exp1 -and exp2
        ! expr
        　-not expr
        exp1 -or exp2
        exp1, exp2

        　范例:
        将目前目录及其子目录下所有延伸档名是 c 的档案列出来。
        # find . -name "*.c"
        　将目前目录其其下子目录中所有一般档案列出
        # find . -ftype f
        将目前目录及其子目录下所有最近 20 分钟内更新过的档案列出
        # find . -ctime -20

        find . -name "*" -exec grep xxx {} \; -print |morexxx为你想要找的字符串
        -exec 空格 命令 空格 {} 空格\;

      @note 功能： 删除文件夹以及其子文件夹下所有名字为file的文件
        find . -name "file" |xargs rm -rf
        find . -name file -type f | xargs rm
        find . -name "*冲突*"  -exec rm -rf {} \;
      *******************/
}

void LPLinux::CompressCommand()
{
    /**

    @ http://blog.sina.com.cn/s/blog_7479f7990100zwkp.html
    tar -zcvf /home/xahot.tar.gz /xahot
    tar -zcvf 打包后生成的文件名全路径 要打包的目录
    例子：把/xahot文件夹打包后生成一个/home/xahot.tar.gz的文件。
    zip 压缩方法：

    压缩当前的文件夹 zip -r ./xahot.zip ./* -r表示递归
    zip [参数] [打包后的文件名] [打包的目录路径]
    解压 unzip xahot.zip 不解释


    linux zip命令

    zip -r myfile.zip ./*
    将当前目录下的所有文件和文件夹全部压缩成myfile.zip文件,－r表示递归压缩子目录下所有文件.

    2.unzip
    unzip -o -d /home/sunny myfile.zip
    把myfile.zip文件解压到 /home/sunny/
    -o:不提示的情况下覆盖文件；
    -d:-d /home/sunny 指明将文件解压缩到/home/sunny目录下；

    3.其他
    zip -d myfile.zip smart.txt
    删除压缩文件中smart.txt文件
    zip -m myfile.zip ./rpm_info.txt
    向压缩文件中myfile.zip中添加rpm_info.txt文件
-------------------------------------------------------------------------------

    要使用 zip 来压缩文件，在 shell 提示下键入下面的命令：

    zip -r filename.zip filesdir


    在这个例子里，filename.zip 代表你创建的文件，filesdir 代表你想放置新 zip 文件的目录。
    -r 选项指定你想递归地（recursively）包括所有包括在 filesdir 目录中的文件。

    要抽取 zip 文件的内容，键入以下命令：

    unzip filename.zip


    你可以使用 zip 命令同时处理多个文件和目录，方法是将它们逐一列出，并用空格间隔：

    zip -r filename.zip file1 file2 file3 /usr/work/school


    上面的命令把 file1、file2、 file3、以及 /usr/work/school 目录的内容（假设这个目录存在）压缩起来，
    然后放入 filename.zip 文件中。



    tar 命令详解

　　-c: 建立压缩档案

　　-x：解压

　　-t：查看内容

　　-r：向压缩归档文件末尾追加文件

　　-u：更新原压缩包中的文件

　　这五个是独立的命令，压缩解压都要用到其中一个，可以和别的命令连用但只能用其中一个。下面的参数是根据需要在压缩或解压档案时可选的。

　　-c: 建立压缩档案

　　-x：解压

　　-t：查看内容

　　-r：向压缩归档文件末尾追加文件

　　-u：更新原压缩包中的文件

　　下面的参数-f是必须的

　　-f: 使用档案名字，切记，这个参数是最后一个参数，后面只能接档案名。

　　# tar -cf all.tar *.jpg

　　这条命令是将所有.jpg的文件打成一个名为all.tar的包。-c是表示产生新的包，-f指定包的文件名。

　　# tar -rf all.tar *.gif

　　这条命令是将所有.gif的文件增加到all.tar的包里面去。-r是表示增加文件的意思。

　　# tar -uf all.tar logo.gif

　　这条命令是更新原来tar包all.tar中logo.gif文件，-u是表示更新文件的意思。

　　# tar -tf all.tar

　　这条命令是列出all.tar包中所有文件，-t是列出文件的意思

　　# tar -xf all.tar

　　这条命令是解出all.tar包中所有文件，-t是解开的意思

　　压缩

　　tar –cvf jpg.tar *.jpg //将目录里所有jpg文件打包成tar.jpg

　　tar –czf jpg.tar.gz *.jpg //将目录里所有jpg文件打包成jpg.tar后，并且将其用gzip压缩，生成一个gzip压缩过的包，
    命名为jpg.tar.gz

　　tar –cjf jpg.tar.bz2 *.jpg //将目录里所有jpg文件打包成jpg.tar后，并且将其用bzip2压缩，生成一个bzip2压缩过的包，
    命名为jpg.tar.bz2

　　tar –cZf jpg.tar.Z *.jpg //将目录里所有jpg文件打包成jpg.tar后，并且将其用compress压缩，生成一个umcompress压缩过的包，
    命名为jpg.tar.Z

　　rar a jpg.rar *.jpg //rar格式的压缩，需要先下载rar for linux

　　zip jpg.zip *.jpg //zip格式的压缩，需要先下载zip for linux

　　解压

　　tar –xvf file.tar //解压 tar包

　　tar -xzvf file.tar.gz //解压tar.gz

　　tar -xjvf file.tar.bz2 //解压 tar.bz2

　　tar –xZvf file.tar.Z //解压tar.Z

　　unrar e file.rar //解压rar

　　unzip file.zip //解压zip

　　总结

　　1、*.tar 用 tar –xvf 解压

　　2、*.gz 用 gzip -d或者gunzip 解压

　　3、*.tar.gz和*.tgz 用 tar –xzf 解压

　　4、*.bz2 用 bzip2 -d或者用bunzip2 解压

　　5、*.tar.bz2用tar –xjf 解压

　　6、*.Z 用 uncompress 解压

　　7、*.tar.Z 用tar –xZf 解压

　　8、*.rar 用 unrar e解压

　　9、*.zip 用 unzip 解压

　　Linux中tar命令详解(转载的资料)

　　2008年04月17日 星期四 15:37

　　tar命令

　　tar 可以为文件和目录创建档案。利用tar，用户可以为某一特定文件创建档案(备份文件)，也可以在档案中改变文件，
    或者向档案中加入新的文件。tar最初被 用来在磁带上创建档案，现在，用户可以在任何设备上创建档案，
    如软盘。利用tar命令，可以把一大堆的文件和目录全部打包成一个文件，这对于备份文件或将
    几个文件组合成为一个文件以便于网络传输是非常有用的。Linux上的tar是GNU版本的。

　　语法：tar [主选项+辅选项] 文件或者目录

　　使用该命令时，主选项是必须要有的，它告诉tar要做什么事情，辅选项是辅助使用的，可以选用。

　　主选项：

　　c 创建新的档案文件。如果用户想备份一个目录或是一些文件，就要选择这个选项。

　　r 把要存档的文件追加到档案文件的未尾。例如用户已经作好备份文件，又发现还有一个目录或是一些文件忘记备份了，
    这时可以使用该选项，将忘记的目录或文件追加到备份文件中。

　　t 列出档案文件的内容，查看已经备份了哪些文件。

　　u 更新文件。就是说，用新增的文件取代原备份文件，如果在备份文件中找不到要更新的文件，则把它追加到备份文件的最后。

　　x 从档案文件中释放文件。

　　辅助选项：

　　b 该选项是为磁带机设定的。其后跟一数字，用来说明区块的大小，系统预设值为20(20*512 bytes)。

　　f 使用档案文件或设备，这个选项通常是必选的。

　　k 保存已经存在的文件。例如我们把某个文件还原，在还原的过程中，遇到相同的文件，不会进行覆盖。

　　m 在还原文件时，把所有文件的修改时间设定为现在。

　　M 创建多卷的档案文件，以便在几个磁盘中存放。

　　v 详细报告tar处理的文件信息。如无此选项，tar不报告文件信息。

　　w 每一步都要求确认。

　　z 用gzip来压缩/解压缩文件，加上该选项后可以将档案文件进行压缩，但还原时也一定要使用该选项进行解压缩。

　　Linux下的压缩文件剖析

　　对于刚刚接触Linux的人来说，一定会给Linux下一大堆各式各样的文件名给搞晕。别个不说，单单就压缩文件为例，
    我们知道在Windows下最常见 的压缩文件就只有两种，一是,zip，另一个是.rap。可是Linux就不同了，
    它有.gz、.tar.gz、tgz、bz2、.Z、.tar等众多的 压缩文件名，此外windows下的.zip和.rar也可以在Linux下使用，
    不过在Linux使用.zip和.rar的人就太少了。本文就来对这些 常见的压缩文件进行一番小结，希望你下次遇到这些文件时不至于被搞晕。

　　在具体总结各类压缩文件之前呢，首先要弄清两个概念：打包和压缩。打包是指将一大堆文件或目录什么的变成一个总的文件，
    压缩则是将一个大的文件通过一些压 缩算法变成一个小文件。为什么要区分这两个概念呢?
    其实这源于Linux中的很多压缩程序只能针对一个文件进行压缩，这样当你想要压缩一大堆文件时，
    你就 得先借助另它的工具将这一大堆文件先打成一个包，然后再就原来的压缩程序进行压缩。

　　Linux下最常用的打包程序就是tar了，使用tar程序打出来的包我们常称为tar包，tar包文件的命令通常都是以.tar结尾的。生成tar包后，
    就可以用其它的程序来进行压缩了，所以首先就来讲讲tar命令的基本用法：

　　tar命令的选项有很多(用man tar可以查看到)，但常用的就那么几个选项，下面来举例说明一下：

　　# tar -cf all.tar *.jpg

　　这条命令是将所有.jpg的文件打成一个名为all.tar的包。-c是表示产生新的包，-f指定包的文件名。

　　# tar -rf all.tar *.gif

　　这条命令是将所有.gif的文件增加到all.tar的包里面去。-r是表示增加文件的意思。

　　# tar -uf all.tar logo.gif

　　这条命令是更新原来tar包all.tar中logo.gif文件，-u是表示更新文件的意思。

　　# tar -tf all.tar

　　这条命令是列出all.tar包中所有文件，-t是列出文件的意思

　　# tar -xf all.tar

　　这条命令是解出all.tar包中所有文件，-t是解开的意思

　　以上就是tar的最基本的用法。为了方便用户在打包解包的同时可以压缩或解压文件，tar提供了一种特殊的功能。
    这就是tar可以在打包或解包的同时调用其它的压缩程序，比如调用gzip、bzip2等。

　　1) tar调用gzip

　　gzip是GNU组织开发的一个压缩程序，.gz结尾的文件就是gzip压缩的结果。与gzip相对的解压程序是gunzip。
    tar中使用-z这个参数来调用gzip。下面来举例说明一下：

　　# tar -czf all.tar.gz *.jpg

　　这条命令是将所有.jpg的文件打成一个tar包，并且将其用gzip压缩，生成一个gzip压缩过的包，包名为all.tar.gz

　　# tar -xzf all.tar.gz

　　这条命令是将上面产生的包解开。

　　2) tar调用bzip2

　　bzip2是一个压缩能力更强的压缩程序，.bz2结尾的文件就是bzip2压缩的结果。与bzip2相对的解压程序是bunzip2。
    tar中使用-j这个参数来调用gzip。下面来举例说明一下：

　　# tar -cjf all.tar.bz2 *.jpg

　　这条命令是将所有.jpg的文件打成一个tar包，并且将其用bzip2压缩，生成一个bzip2压缩过的包，包名为all.tar.bz2

　　# tar -xjf all.tar.bz2

　　这条命令是将上面产生的包解开。

　　3)tar调用compress

　　compress也是一个压缩程序，但是好象使用compress的人不如gzip和bzip2的人多。
    .Z结尾的文件就是bzip2压缩的结果。与 compress相对的解压程序是uncompress。tar中使用-Z这个参数来调用gzip。下面来举例说明一下：

　　# tar -cZf all.tar.Z *.jpg

　　这条命令是将所有.jpg的文件打成一个tar包，并且将其用compress压缩，生成一个uncompress压缩过的包，包名为all.tar.Z

　　# tar -xZf all.tar.Z

　　这条命令是将上面产生的包解开

　　有了上面的知识，你应该可以解开多种压缩文件了，下面对于tar系列的压缩文件作一个小结：

　　1)对于.tar结尾的文件

　　tar -xf all.tar

　　2)对于.gz结尾的文件

　　gzip -d all.gz

　　gunzip all.gz

　　3)对于.tgz或.tar.gz结尾的文件

　　tar -xzf all.tar.gz

　　tar -xzf all.tgz

　　4)对于.bz2结尾的文件

　　bzip2 -d all.bz2

　　bunzip2 all.bz2

　　5)对于tar.bz2结尾的文件

　　tar -xjf all.tar.bz2

　　6)对于.Z结尾的文件

　　uncompress all.Z

　　7)对于.tar.Z结尾的文件

　　tar -xZf all.tar.z

　　另外对于Window下的常见压缩文件.zip和.rar，Linux也有相应的方法来解压它们：

　　1)对于.zip

　　linux下提供了zip和unzip程序，zip是压缩程序，unzip是解压程序。它们的参数选项很多，这里只做简单介绍，依旧举例说明一下其用法：

　　# zip all.zip *.jpg

　　这条命令是将所有.jpg的文件压缩成一个zip包

　　# unzip all.zip

　　这条命令是将all.zip中的所有文件解压出来

　　2)对于.rar

　　要在linux下处理.rar文件，需要安装RAR for Linux，可以从网上下载，但要记住，RAR for Linux

　　不是免费的;然后安装：

　　# tar -xzpvf rarlinux-3.2.0.tar.gz

　　# cd rar

　　# make

　　这样就安装好了，安装后就有了rar和unrar这两个程序，rar是压缩程序，unrar是解压程序。它们的参数选项很多，
    这里只做简单介绍，依旧举例说明一下其用法：

　　# rar a all *.jpg

　　这条命令是将所有.jpg的文件压缩成一个rar包，名为all.rar，该程序会将.rar 扩展名将自动附加到包名后。

　　# unrar e all.rar

　　这条命令是将all.rar中的所有文件解压出来

　　到此为至，我们已经介绍过linux下的tar、gzip、gunzip、bzip2、bunzip2、compress、uncompress、 zip、unzip、rar、unrar等程式，
    你应该已经能够使用它们对.tar、.gz、.tar.gz、.tgz、.bz2、.tar.bz2、. Z、.tar.Z、.zip、.rar这10种压缩文件进行解压了，
    以后应该不需要为下载了一个软件而不知道如何在Linux下解开而烦恼了。而且以上方 法对于Unix也基本有效。

　　本文介绍了linux下的压缩程式tar、gzip、gunzip、bzip2、bunzip2、 compress、uncompress、zip、unzip、rar、unrar等程式，
    以及如何使用它们对.tar、.gz、.tar.gz、. tgz、.bz2、.tar.bz2、.Z、.tar.Z、.zip、.rar这10种压缩文件进行操作

      ***********/
}

void LPLinux::modifyFile()
{
    /**
      @ 登录帐号 zcg  密码  zcg123zcg
        登录方式：
        1、 ftp: 192.100.100.8
            输入用户名，密码
        2、 ssh 192.100.100.8 -l zcg
            输入密码
        3、 X -query 192.100.100.8 :1  其中（192.100.100.8)是要登录机器的地址
            切换到用户登录界面，输入zcg
      @ 把朱老师修改提交的代码（eposrc_20130310.zip）解压放在JH这个目录下
        但是要把代码（eposrc_20130310.zip）放在ip地址为（192.100.100.8)的机器上操作
        要用mput命令
        现用ftp:192.100.100.8登录到这个机器上
        $ mput eposrc_20130310.zip; (ps：mput提交的文件要在你打开ftp的路径下)
      @ 把解压的文件和 ~/develop/epo/include/ 下的文件作对比，看新的文件都有什么修改。
        例如：
        $ diff ~/develop/epo/include/log  log对比。

      @ 修改完成后用Qt提交，然后等待汤老师更新库文件。然后运行 JH/eposrc里的getresouce文件更新库。
        最后，打包，压缩。

        压缩文件： bin和lib分别压缩成一个包，其他的压缩成一个包。

      *********
      @ 下次修改朱老师的文件，不要更新，千万不要更新。一更新就得全部改了。
        现把朱老师的文件和原来的 ~/develop/epoffice/里面的文件对比
        然后把原来的文件修改。
        最后，更新文件。然后提交。如果朱老师又添加了新的文件，要到目录下查看，看有没有添加，如果添加了。
        比如：在/include/map文件中添加了 EPmapxkd.h这个文件
        那么要到 /include/map文件中
        svn st （查看文件状态）
        svn add EPmapxkd.h
        到qtcreator中打开map工程，commit。

      @ 如果自己本人的也没有提交，那么先提交自己的，然后在更新。要不然更新了就会把自己写的信息和更新的信息整合为一个文件。
        例如：
        svn   1.cpp里面
              文件内容为
              xx
        mine  1.cpp里面
              文件内容为
              xx
              kk
        other 1.cpp里面
              文件内容为
              xx
              dd
        如果other提交之前更新了，然后提交，那么svn里面的 1.cpp文件里的内容为
      **/
}

void LPLinux::pixelAndCentimeter()
{
    /**
     \brief
        1 英寸 ＝ 2.54 厘米 ＝ 25.4毫米

        1 厘米 ＝ 0.3937英寸
        72像素 /英寸 ＝ 28.346像素/厘米
        300像素/英寸 ＝ 118.11 像素/厘米

     */
}

void LPLinux::algorithm()
{
    /**
     \brief
     @note  宽度为w的距离画n条线，间距怎么运算。
        step = w/(n-1);

     */
}

void LPLinux::linuxCommand()
{
    /**
     \note      cd
     @a         返回前一个目录  cd -

     \brief     file

       功能说明：辨识文件类型。
    　　语　　法：file [-beLvz][-f <名称文件>][-m <魔法数字文件>...][文件或目录...]
    　　补充说明：通过file指令，我们得以辨识该文件的类型。
    　　参　　数：
    　　-b 　列出辨识结果时，不显示文件名称。
    　　-c 　详细显示指令执行过程，便于排错或分析程序执行的情形。
    　　-f<名称文件> 　指定名称文件，其内容有一个或多个文件名称呢感，让file依序辨识这些文件，格式为每列一个文件名称。
    　　-L 　直接显示符号连接所指向的文件的类别。
    　　-m<魔法数字文件> 　指定魔法数字文件。
    　　-v 　显示版本信息。
    　　-z 　尝试去解读压缩文件的内容。


     */
}

void LPLinux::softwareCompany()
{
    /**
     \brief     有一些想和geoanalyst软件相关的软件可以拿来参考参考
        landmark
        潜能恒信
        双狐
        casure

    */
}
