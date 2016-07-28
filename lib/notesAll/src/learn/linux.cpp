#include "linux.h"

Linux::Linux()
{
    /**
    root!123;
    xkd!123;
    @ 文件管理

    @ 文档编辑

    @ 文件传输

    @ 磁盘管理

    @ 磁盘维护

    @ 网络通讯

    @ 系统管理

    @ 系统设置

    @ 备份压缩

    @ 设备管理
     */

}

void Linux::learnRegularExpression_12()
{
    /**
     特殊符号：
     [:alnum:]      代表字母和数字，即[A-Z],[a-z],[0-9]
     [:alpha:]      字母
     [:digit:]      数字
     [:graph:]      除了空格符(空格键与[Tab]按键)外的其他所有按键
     [:lower:]      小写字母 [a-z]
     [:upper:]      大写字母 [A-Z]


     */
}

void Linux::learnShellScripts_13()
{
    /**
    判断符号［］
    ［ -f "/home/xkd" ]  返回false，因为这是一个目录
    ［ -d "/home/xkd" ]  返回true。

    输出运行结果 $?
    $ ./sum         运行sum这个应用程序
    $ echo $?       返回sum的运行结果
    $ $0 代表的是 执行的脚档名  ./sum   $0 等于 sum

    $#  : 代表后接的参数个数。
    $ ./sum xkd zsh xing zheng  $# 等于 4 （因为有四个参数）

    $@  : 代表[ $1 $2 $3 $4 ] ($1=xkd, $2=zsh, $3=xing, $4=zheng) $@ 等于 xkd zsh xing zheng

    $*  : 代表[ $1_$2_$3_$4 ]

    在中括号［］内的每个组件都需要有空格键来分隔
    在中括号［］内的变数，最好都以双引号 ”“ 括号起来
    在中括号［］内的常数，最好都以单或双引号括号起来

    例如：
    $ name="VBird Tsai"  注意，赋值的时候等号两边不能有空格。
    $ [ $name == "VBird" ] 出错，提示参数太多。因为这句相当于
       ［ VBird Tsai ＝＝ VBird ］


    ******************************************
    if 要注意空格
    if [ $type="contact" ]; then
    fi

    if [ 条件判断式 ]; then
            .....
    fi

    if [ 条件判断式 ]; then
            .....
    else
            .....
    fi

    if [ 条件判断式 ]; then
            .....
    elif [ 条件判断式 ]; then
            .....
    fi

    if test -f /etc/foo
    then
            .......
    fi

    if [ -f /etc/foo ]; then
            .......
    fi

    *****************************************
    case $变量名称 in
        "第一个变量内容")
        ......
        ;;      (以两个连续的分号来处理)

        "第二个变量内容")
        ......
        ;;

        *)      (最后一个变量内容都会用 * 来代表所有其他值
        ......
        exit 1
        ;;

    esac

    *****************************************
    for var in con1 con2 con3 ..; (第一次循环时  $var的内容为 con1)
    do
            ......
    done
    -------------------------------------
    for((初始值; 限制值; 执行步阶))
    do
            .......
    done

    *******************************************
    while [ condition ]
    do
        .....
    done
    ------------------------
    until [ condition ]
    do
        ....
    done


    *******************************************
    function 也是拥有内建变量的。他的内建变量与 shell script 很类似，函数名称用 $0 表示。
    后续的变量也是以 $1,$2...来取代。
    function fname() {
        .......

        echo "..... $0" 记住要双引号 "" 而不是单引号 ''
    }
    函数调用的时候

    fname "$0" $1" 而不是 fname $0 $1

    注意这几个符号的区别：
    ``, '', ""

    `` 表示执行的命令
    '' 表示字符
    "" 表示字符，但是当里面遇到 linux 的特殊字符的时候，可以替换

 */
}

void Linux::shellString()
{
    /**
    1、{} 大括号：
    用法一：通配符扩展
    eg: ls my_{finger,toe}s
    这条命令相当于如下命令的组合：
    ls my_fingers my_toes
    eg: mkdir {userA,userB,userC}-{home,bin,data}
    我们将得到 userA-home, userA-bin, userA-data, userB-home, userB-bin,userB-data,userC-home, userC-bin, userC-data，这几个目录
    用法二：可用于语句块的构造，语句之间用回车隔开。如果你想在某些使用单个语句的地方（比如在AND或OR列表中）使用多条语句，你可以把它们括在花括号{}中来构造一个语句块。
    eg:
    {
    grep -v "$cdcatnum" $strack_file > $temp_file
    cat $temp_file > $strack_file
    echo
    cat -n file1
    } (注：以上大括号中的四句命令够成了一个语句块)
    用法三：参数扩展
    ${name:-default} 使用一个默认值（一般是空值）来代替那些空的或者没有赋值的变量name；
    ${name:=default}使用指定值来代替空的或者没有赋值的变量name；
    ${name:?message}如果变量为空或者未赋值，那么就会显示出错误信息并中止脚本的执行同时返回退出码1。
    ${#name} 给出name的长度
    ${name%word} 从name的尾部开始删除与word匹配的最小部分，然后返回剩余部分
    ${name%%word} 从name的尾部开始删除与word匹配的最长部分，然后返回剩余部分
    ${name#word} 从name的头部开始删除与word匹配的最小部分，然后返回剩余部分
    ${name##word} 从name的头部开始删除与word匹配的最长部分，然后返回剩余部分
    （注，name为变量名，word为要匹配的字符串）
    用法三在处理字符串和未知变量时，是很有用的。

    2、[] 中括号：

    用法一：通配符扩展：
    允许匹配方括号中任何一个单个字符
    eg: ls /[eh][to][cm]*
    相当于执行 ls /etc /home（若有/eom目录，就相当于会执行ls /etc /home /eom）
    注：在mkdir命令下不能扩展
    用法二：用于条件判断符号：
    []符号可理解为指向test命令的一个软链接，所以其用法可完全参照test，将test位置替换为[便可。
    eg: if [ "$?" != 0 ] 等价于 if test "$?" != 0
    then echo "Executes error"


    3、`command` 反引号：`command`与$(command)的含义相同，都是返回当前执行命令的结果

    eg: #!/bin/sh
    for file in $(ls f*.sh);do
    lpr $file
    done
    exit 0
    该例实现了扩展f*.sh给出所有匹配模式的文件的名字。


    4、'string' 单引号 和 "string" 双引号

    双引号：如果想在定义的变量中加入空格，就必须使用单引号或双引号，
    单、双引号的区别在于双引号转义特殊字符而单引号不转义特殊字符
    eg: $ heyyou=home
    $ echo '$heyyou'
    $ $heyyou （$没有转义）
    eg: $ heyyou=home
    $ echo "$heyyou"
    $ home （很明显，$转义了输出了heyyou变量的值）


    5、$# 它的作用是告诉你引用变量的总数量是多少；

    $$ 它的作用是告诉你shell脚本的进程号；
    $* 以一个单字符串显示所有的脚本传递的参数。等价于$1 $2 $3.......；
    $@ 与$*基本类似（参见序号7），但在数组赋值时有些不同；
    $? 前一个命令的退出码；
    $- 显示shell使用的当前选项；
    $! 最后一个后台运行的进程ID号。


    6、$((...))语法：对括号内的表达式求值

    eg:
    #!/bin/sh
    x=0
    hile [ "$x" -ne 10 ];do
    echo $x
    x=$(($x+1))
    done
    exit 0


    7、shell中几种特殊的参数变量的引用

    $1、$2、$3……${10}、${11}、${12}…… ：表示脚本传入的的各个参数，注意当需表示两位数以后的参数时数字要用花括号括起。
    $@ 列出所有的参数，各参数用空格隔开
    $*: 列出所有的参数，各参数用环境变量IFS的第一个字符隔开


    8、命令列表：

    AND列表 statement1 && statement2 && statement3 && …:只有在前面所有的命令都执行成功的情况下才执行后一条命令
    OR列表 statement1 || statement2 || statement3 || …:允许执行一系列命令直到有一条命令成功为止，其后所有命令将不再被执行
    eg:#!/bin/sh
    touch file_one
    rm -f file_two
    if [ -f file_one ] && echo "hello" && [ -f file_two ] && echo " there"
    then
    echo "in if"
    else
    echo "in else"
    fi
    exit 0
    上例的输出为：
    hello
    in else
    关于AND列表与OR列表，在逻辑判断中很使用，下面就举一个其最常用的例子：
    [ condition ] && command for true || command for false:
    当条件为真时，执行commandfor true ,当条件为假时，执行command for false


    9、: 冒号：内建空指令，返回值为0

    eg: $ :
    $ echo $?
    $ 0
    while: (该语句结构可实现一个无限循环)


    10、; 分号: 在 shell 中，担任"连续指令"功能的符号就是"分号"

    eg:cd ~/backup ; mkdir startup ; cp ~/.* startup/.


    11、# 井号：表示符号后面的是注解文字，不会被执行；

    * 匹配文件名中的任何字符，包括字符串；
    ？ 匹配文件名中的任何单个字符。
    ~ 代表使用者的 home 目录


    12、\ 倒斜线：放在指令前，有取消 aliases（别名） 的作用；放在特殊符号前，则该特殊符号的作用消失；放在指令

    的最末端，表示指令连接下一行（使得回车符无效，只起换行作用）


    14、! 感叹号：通常它代表反逻辑的作用，譬如条件侦测中，用 != 来代表"不等于"


    15、** 次方运算：两个星号在运算时代表 "次方" 的意思

    eg:let "sus=2**3"
    echo "sus = $sus"
    $ sus = 8 -
     */
}

void Linux::UserManagerAcl_14()
{
    /**

     */
}

void Linux::openTheComputer_20()
{
    /**
    @ 开机过程
    1. 加载 BIOS 的硬件信息与进行自我测试，并依据设定取得第一个可开机的装置；
    2. 读取幵执行第一个开机装置内 MBR 的 boot Loader (亦即是 grub, spfdisk 等程序)；
    3. 依据 boot loader 的设定加载 Kernel ，Kernel 会开始侦测硬件与加载驱劢程序；
    4. 在硬件驱劢成功后，Kernel 会主动呼机 init 程序，而 init 会取得 run-level 信息；
    5. init 执行 /etc/rc.d/rc.sysinit 档案来准备软件执行的作业环境 (如网络、时区等)；
    6. init 执行 run-level 的各个服务之启动(script 方式)；
    7. init 执行 /etc/rc.d/rc.local 档案；
    8. init 执行终端机仿真程序 mingetty 来启动 login 程序，最后就等待用户登入啦；

    为了解决这个问题，所以 Linux 将 boot loader 的程序代码执行与设定值加载分成两个阶段 (stage) 来执行：

    Stage 1：执行 boot loader 主程序：
    第一阶段为执行 boot loader 的主程序，这个主程序必须要被安装在开机区，亦即是 MBR 或者是 boot sector 。
    但如前所述，因为 MBR 实在太小了，所以，MBR 戒 boot sector 通常仅安装 boot loader 的最小主程序， 并没有安装 loader 的相关配置文件；

    Stage 2：主程序加载配置文件：
    第二阶段为透过 boot loader 加载所有配置文件不相关的环境参数档案 (包括文件系统定义不主要配置文件 menu.lst)， 一般来说，配置文件都在 /boot 底下。

    @ Boot Loader(开机管理程序) 目前主流的Boot loader 是 grub  /boot/grub
        开机管理程序可以指定使用哪个核心来开机，并实际加载核心到内存当中解压缩与执行
        此时核心就能够开始在内存中活动，并侦测所有硬件信息与加载适当的驱动程序来使整部主机开始运作
        等到核心侦测硬件和加载驱动程序完毕后，整个系统就可以在PC上跑了。此后，系统才会呼叫外部程序
        开始准备软件执行的环境，并且实际的加载所有系统运作所需要的软件程序。最后系统就开始等待你的登录
        与操作。

        核心档案放置到 /boot中，并取名为 /boot/vmlinuz

    @ Boot Loader 加载核心
        核心模块(驱动程序)放置在 /lib/modules 这个目录内。由于模块放置到磁盘根目录内，因此在开机的过程中核心必须要
        挂载根目录，这样才能读取核心模块提供加载驱动程序的模块。

        核心模块是放置在SATA磁盘上面，你可以透过 BIOS 的 INT 13 取得 boot loader 与 kernel 档案来开机，
        然后 kernel 会开始接管系统幵丏侦测硬件及尝试挂载根目录来取得额外的驱劢程序。
        核心不识别SATA磁盘，所有无法加载SATA磁盘(/lib/modules)的驱动程序,这时候就得透过虚拟文件系统来处理这个问题

        虚拟文件系统(initial RAM Disk)一般使用的文档名为 /boot/initrd*** 。这个文档的特色是能够透过boot loader来加载到内存中，
        然后这个文档会被解压缩并且在内存当中仿真成一个根目录，并且此仿真在内存当中的文件系统能够提供一支可执行的程序，透过该程序来加载
        开机过程中所需要的核心模块。这些模块通常是USB，RAID，LVM，SCSI等文件系统与磁盘接口的驱动程序。等载入完成后会帮组核心重新呼叫
        /sbin/init 来开始后续的正常开机流程。

    @ 加载完核心模块后，主机开始正确运作，开始执行系统第一支程序  /sbin/init
        /sbin/init 最主要的功能就是准备软件执行的环境，，包括系统的主机名、网络讴定、诧系处理、文件系统格式及其他服务等。
        而所有的动作都会透过 init 的配置文件，亦即是 /etc/inittab 来规划，而 inittab 内还有一个很重要的设定项目，那就是默认的 runlevel (开机执行等级) 啦！

        [设定项目]:[run level]:[init 的动作行为]:[指令项目]
        可以才看 /etc/inittab 这个文件
        id:5:initdefault: <==预设的 runlevel 设定, 此 runlevel 为 5

        si::sysinit:/etc/rc.d/rc.sysinit <==准备系统软件执行的环境的脚本执行档 # 7 个不同 run level 的，需要启动的服务的 scripts 放置路径：
        l0:0:wait:/etc/rc.d/rc 0 <==runlevel 0 在 /etc/rc.d/rc0.d/
        l1:1:wait:/etc/rc.d/rc 1 <==runlevel 1 在 /etc/rc.d/rc1.d/
        l2:2:wait:/etc/rc.d/rc 2 <==runlevel 2 在 /etc/rc.d/rc2.d/
        l3:3:wait:/etc/rc.d/rc 3 <==runlevel 3 在 /etc/rc.d/rc3.d/
        l4:4:wait:/etc/rc.d/rc 4 <==runlevel 4 在 /etc/rc.d/rc4.d/
        l5:5:wait:/etc/rc.d/rc 5 <==runlevel 5 在 /etc/rc.d/rc5.d/
        l6:6:wait:/etc/rc.d/rc 6 <==runlevel 6 在 /etc/rc.d/rc6.d/

        # 是否允许按下 [ctrl]+[alt]+[del] 就重新启动的设定项目：
        ca::ctrlaltdel:/sbin/shutdown -t3 -r now

        # 底下两个设定则是关于不断电系统的 (UPS)，一个是没电力时的关机，一个是复电的处理
        pf::powerfail:/sbin/shutdown -f -h +2 "Power Failure; System Shutting Down"
        pr:12345:powerokwait:/sbin/shutdown -c "Power Restored; Shutdown Cancelled"

        1:2345:respawn:/sbin/mingetty tty1 <==其实 tty1~tty6 是由底下这六行决定的。
        2:2345:respawn:/sbin/mingetty tty2
        3:2345:respawn:/sbin/mingetty tty3
        4:2345:respawn:/sbin/mingetty tty4
        5:2345:respawn:/sbin/mingetty tty5
        6:2345:respawn:/sbin/mingetty tty6

        x:5:respawn:/etc/X11/prefdm -nodaemon <==X window 则是这行决定的！
     @  用户自定义开机启动程序 (/etc/rc.d/rc.local)
        这些开机过程会用到的配置文件则大多放置在 /etc/sysconfig/ 目录下。
        同时，由于核心还是需要加载一些启动程序 (核心模块)，此时系统自定义的装置与模块对应文件 (/etc/modprobe.conf) 就显的挺重要了喔！
     */
}

void Linux::configure()
{
    /**
    Linux环境下的软件安装，并不是一件容易的事情；如果通过源代码编译后在安装，当然事情就更为复杂一些；现在安装各种软件的教程都非常普遍；
    但万变不离其中，对基础知识的扎实掌握，安装各种软件的问题就迎刃而解了。Configure脚本配置工具就是基础之一，它是autoconf的工具的基本应用。

    与一些技巧相比，Configure显得基础一些，当然使用和学习起来就显得枯燥乏味一些，当然要成为高手，对基础的熟悉不能超越哦。

    为此我转载了一篇关于Configure选项配置的详细介绍。供大家参考

    'configure'脚本有大量的命令行选项。对不同的软件包来说，这些选项可能会有变化，但是许多基本的选项是不会改变的。
    带上'--help'选项执行'configure'脚本可以看到可用的所有选项。尽管许多选项是很少用到的，但是当你为了特殊的需求而configure一个包时，知道他们的存在是很有益处的。
    下面对每一个选项进行简略的介绍：

--cache-file=FILE
    'configure'会在你的系统上测试存在的特性(或者bug!)。
    为了加速随后进行的配置，测试的结果会存储在一个cache file里。
    当configure一个每个子树里都有'configure'脚本的复杂的源码树时，一个很好的cache file的存在会有很大帮助。

--help
    输出帮助信息。即使是有经验的用户也偶尔需要使用使用'--help'选项，
    因为一个复杂的项目会包含附加的选项。例如，GCC包里的'configure'脚本就包含了允许你控制是否生成和在GCC中使用GNU汇编器的选项。

--no-create(指定不需要的模块。例如： configure -no-xml,不需要xml这个模块)

    'configure'中的一个主要函数会制作输出文件。此选项阻止'configure'生成这个文件。你可以认为这是一种演习(dry run)，尽管缓存(cache)仍然被改写了。

--quiet
--silent

    当'configure'进行他的测试时，会输出简要的信息来告诉用户正在作什么。这样作是因为'configure'可能会比较慢，
    没有这种输出的话用户将会被扔在一旁疑惑正在发生什么，使用这两个选项中的任何一个都会把你扔到一旁。
    (译注：这两句话比较有意思，原文是这样的：If there was no such output, the user would be left wondering what is happening.
    By using this option, you too can be left wondering!)

--version

    打印用来产生'configure'脚本的Autoconf的版本号。

--prefix=PEWFIX

    '--prefix'是最常用的选项。制作出的'Makefile'会查看随此选项传递的参数，当一个包在安装时可以彻底的重新安置他的结构独立部分。
    举一个例子，当安装一个包，例如说Emacs，下面的命令将会使Emacs Lisp file被安装到"/opt/gnu/share"：
    $ ./configure --prefix=/opt/gnu

--exec-prefix=EPREFIX

    与'--prefix'选项类似，但是他是用来设置结构倚赖的文件的安装位置，编译好的'emacs'二进制文件就是这样一个文件。
    如果没有设置这个选项的话，默认使用的选项值将被设为和'--prefix'选项值一样。

--bindir=DIR

    指定二进制文件的安装位置，这里的二进制文件定义为可以被用户直接执行的程序。

--sbindir=DIR

    指定超级二进制文件的安装位置。这是一些通常只能由超级用户执行的程序。

--libexecdir=DIR

    指定可执行支持文件的安装位置。与二进制文件相反，这些文件从来不直接由用户执行，但是可以被上面提到的二进制文件所执行。

--datadir=DIR

    指定通用数据文件的安装位置。

--sysconfdir=DIR

    指定在单个机器上使用的只读数据的安装位置。

--sharedstatedir=DIR
    指定可以在多个机器上共享的可写数据的安装位置。

--localstatedir=DIR
    指定只能单机使用的可写数据的安装位置。
--libdir=DIR
    指定库文件的安装位置。

--includedir=DIR
    指定C头文件的安装位置。其他语言如C++的头文件也可以使用此选项。

--oldincludedir=DIR
    指定为除GCC外编译器安装的C头文件的安装位置。

--infodir=DIR
    指定Info格式文档的安装位置.Info是被GNU工程所使用的文档格式。

--mandir=DIR
    指定手册页的安装位置。

--srcdir=DIR
    这个选项对安装没有作用，他会告诉'configure'源码的位置。一般来说不用指定此选项，因为'configure'脚本一般和源码文件在同一个目录下。

--program-prefix=PREFIX
    指定将被加到所安装程序的名字上的前缀。例如，使用'--program-prefix=g'来configure一个名为'tar'的程序将会使安装的程序被命名为'gtar'。
    当和其他的安装选项一起使用时，这个选项只有当他被`Makefile.in'文件使用时才会工作。

--program-suffix=SUFFIX
    指定将被加到所安装程序的名字上的后缀。

--program-transform-name=PROGRAM
    这里的PROGRAM是一个sed脚本。当一个程序被安装时，他的名字将经过`sed -e PROGRAM'来产生安装的名字。

--build=BUILD
    指定软件包安装的系统平台。如果没有指定，默认值将是'--host'选项的值。

--host=HOST
    指定软件运行的系统平台。如果没有指定。将会运行`config.guess'来检测。

--target=GARGET
    指定软件面向(target to)的系统平台。这主要在程序语言工具如编译器和汇编器上下文中起作用。如果没有指定，默认将使用'--host'选项的值。

--disable-FEATURE
    一些软件包可以选择这个选项来提供为大型选项的编译时配置，例如使用Kerberos认证系统或者一个实验性的编译器最优配置。如果默认是提供这些特性，
    可以使用'--disable-FEATURE'来禁用它，这里'FEATURE'是特性的名字，例如：
    $ ./configure --disable-gui

-enable-FEATURE[=ARG]
    相反的，一些软件包可能提供了一些默认被禁止的特性,可以使用'--enable-FEATURE'来起用它。这里'FEATURE'是特性的名字。一个特性可能会接受一个可选的参数。例如：
    $ ./configure --enable-buffers=128
    `--enable-FEATURE=no'与上面提到的'--disable-FEATURE'是同义的。

--with-PACKAGE[=ARG]
    在自由软件社区里，有使用已有软件包和库的优秀传统。当用'configure'来配置一个源码树时，可以提供其他已经安装的软件包的信息。
    例如，倚赖于Tcl和Tk的BLT器件工具包。要配置BLT，可能需要给'configure'提供一些关于我们把Tcl和Tk装的何处的信息：
    $ ./configure --with-tcl=/usr/local --with-tk=/usr/local
    '--with-PACKAGE=no'与下面将提到的'--without-PACKAGE'是同义的。

--without-PACKAGE
    有时候你可能不想让你的软件包与系统已有的软件包交互。例如，你可能不想让你的新编译器使用GNU ld。通过使用这个选项可以做到这一点：
    $ ./configure --without-gnu-ld

--x-includes=DIR
    这个选项是'--with-PACKAGE'选项的一个特例。在Autoconf最初被开发出来时，流行使用'configure'来作为Imake的一个变通方法来制作运行于X的软件。
    '--x-includes'选项提供了向'configure'脚本指明包含X11头文件的目录的方法。

--x-libraries=DIR
    类似的，'--x-libraries'选项提供了向'configure'脚本指明包含X11库的目录的方法。

    在源码树中运行'configure'是不必要的同时也是不好的。一个由'configure'产生的良好的'Makefile'可以构筑源码属于另一棵树的软件包。
    在一个独立于源码的树中构筑派生的文件的好处是很明显的：派生的文件，如目标文件，会凌乱的散布于源码树。
    这也使在另一个不同的系统或用不同的配置选项构筑同样的目标文件非常困难。建议使用三棵树：一棵源码树(source tree)，一棵构筑树(build tree)，
    一棵安装树(install tree)。这里有一个很接近的例子，是使用这种方法来构筑GNU malloc包：

    $ gtar zxf mmalloc-1.0.tar.gz
    $ mkdir build && cd build
    $ ../mmalloc-1.0/configure
    creating cache ./config.cache
    checking for gcc... gcc
    checking whether the C compiler (gcc ) works... yes
    checking whether the C compiler (gcc ) is a cross-compiler... no
    checking whether we are using GNU C... yes
    checking whether gcc accepts -g... yes
    checking for a BSD compatible install... /usr/bin/install -c
    checking host system type... i586-pc-linux-gnu
    checking build system type... i586-pc-linux-gnu
    checking for ar... ar
    checking for ranlib... ranlib
    checking how to run the C preprocessor... gcc -E
    checking for unistd.h... yes
    checking for getpagesize... yes
    checking for working mmap... yes
    checking for limits.h... yes
    checking for stddef.h... yes
    updating cache ../config.cache
    creating ./config.status
    这样这棵构筑树就被配置了，下面可以继续构筑和安装这个包到默认的位置'/usr/local'：
    $ make all && make install
     */
}

void Linux::configure_example()
{
    /**
    http://blog.sina.com.cn/s/blog_609b4c0d01012j26.html

    echo yes | ./configure -opensource -embedded arm -xplatform qws/linux-arm-g++
    -no-webkit -qt-libtiff -qt-libmng  -qt-mouse-tslib -qt-mouse-pc
    -no-mouse-linuxtp -prefix /opt/qt-4.7.1   -I /usr/local/tslib/include -L /usr/local/tslib/lib
     */
}

void Linux::linuxConfigureFile()
{
    /**
    我们 Linux 系统的服务 (services) 启动的接口是在 /etc/init.d/ 这个目录下，
    目录下的所有档案都是 scripts ； 另外，包括开机 (booting) 过程也都是利用 shell script
    来帮忙搜寻系统的相关讴定数据， 然后再代入各个服务的讴定参数啊！举例来说，
    如果我们想要重新启动系统注册表档， 可以使用：『/etc/init.d/syslogd restart』，那个 syslogd 档案就是 script 啦

    /etc/passwd 系统上的帐号与一般身份使用者，还有root的相关信息。
    /etc/shadow 个人密码
    /etc/group  所有的组名 UID和GID是从这个文件中读出来的

    /etc/sysconfig/network-scripts/ifcfg-eth0       IP Netmask DHCP 与否 Gateway 等 (服务篇_P116)
    /etc/sysconfig/network                          主机名
    /etc/resolv.conf                                DNS IP
    /etc/hosts                                      私有IP对应的主机名

    /etc/sudoers                                    让其他用户也具有root的权限执行root的命令
    /etc/services
    这个档案则是记录架构在 TCP/IP 上面的总总协议，包括 http, ftp, ssh, telnet 等等服务所定义的 port number ，
    都是这个档案所规划出来的。如果你想要自定义一个新的协议与 port 的对应，就得要改这个档案了；

    /etc/protocols
    这个档案则是在定义出 IP 封包协议的相关数据，包括 ICMP/TCP/UDP 这方面的封包协议的定义等。

    /etc/init.d/network
    这个 script 最重要！因为可以一口气重新启动整个网络的参数！ 他会主动的去读取所有的网络配置文件，所以可以很快的恢复系统默认的参数值。

    ifup eth0 (ifdown eth0)
    启动或者是关闭某张网络接口。可以透过这个简单的 script 来处理喔！ 这两个 script 会主动到 /etc/sysconfig/network-scripts/ 目录下，
    读取适当的配置文件来处理啊！ (例如 ifcfg-eth0)。

    /etc/profile:此文件为系统的每个用户设置环境信息,当用户第一次登录时,该文件被执行.
    并从/etc/profile.d目录的配置文件中搜集shell的设置.
    /etc/bashrc:为每一个运行bash shell的用户执行此文件.当bash shell被打开时,该文件被读取.

    在初始化命令行提示符的时候会执行.bash_profile 来配置你的shell环境。但是如果你已经登录到机器，你在Gnome或者是KDE也开了一个新的终端窗口（xterm），
    这时，.bashrc会在窗口命令行提示符出现前被执行。当你在终端敲入/bin/bash时.bashrc也会在这个新的bash实例启动的时候执行。

    ~/.bash_profile:每个用户都可使用该文件输入专用于自己使用的shell信息,当用户登录时,该
    文件仅仅执行一次!默认情况下,他设置一些环境变量,执行用户的.bashrc文件.
    ~/.bashrc:该文件包含专用于你的bash shell的bash信息,当登录时以及每次打开新的shell时,该
    该文件被读取.
    ~/.bash_logout:当每次退出系统(退出bash shell)时,执行该文件.

    另外,/etc/profile中设定的变量(全局)的可以作用于任何用户,而~/.bashrc等中设定的变量(局部)只能继承/etc/profile中的变量,他们是"父子"关系.

    ~/.bash_profile 是交互式、login 方式进入 bash 运行的
    ~/.bashrc 是交互式 non-login 方式进入 bash 运行的
    通常二者设置大致相同，所以通常前者会调用后者。

    设置生效：可以重启生效，也可以使用命令：source


    //////////////////////////////////////////
    ~/.bash_history 记录的是前一次登入以前所执行过的指令，而至于这一次登入所执行的指令被
    暂存在内存中，当你成功的注销系统后，该指令记忆才会记录到 .bash_history 中

    启动X server
    如果 app: cannot connect X server (设置DisallowTCP=false)
    /etc/gdm/custom.conf
    [security]
    DisallowTCP=false
    AllowRemoteRoot=true

     */
}

void Linux::shell()
{
    /**
    上述过程中的$0是一个内部变量，它是必须的，而$1则可有可无，最常用的内部变量有$0、$#、$?、$*，它们的含义如下。
     $0:命令含命令所在的路径。  $#:传递给程序的总的参数数目。
     $?:Shell程序在Shell中退出的情况，正常退出返回0，反之为非0值。
    $*:传递给程序的所有参数组成的字符串
     */
}

void Linux::forgetRootPasswd()
{
    /**
    @ 重新启动，按任意键

    @ 按e进入 grub的编辑模式，出现一下选项
        root (hd0,0)
        kernel /vmlinuz-2.6.18-128.el5 ro root=LABEL=/ rhgb quiet
        initrd /initrd-2.6.18-128.el5.img
      选择kernel，再次按 e 进入kernel该行的编辑画面中，在最后输入single :
      kernel /vmlinuz-2.6.18-128.el5 ro root=LABEL=/ rhgb quiet single
      然后回车，再按 b 就可以进入单人维护模式。在这个模式下，你会在tty1的地方不需要输入密码即可取得终端权（而且是root身份)

    @ 最后用passwd修改密码
     */
}

void Linux::kernel()
{
    /**
     *本质：

    内核的1个任务是管理好硬件，服务好硬件。
    内核的2个任务是管理好应用，服务好应用。

    在以上两个任务中，最最重要的任务是管理好内存。
    因为大家都在内存里排队等着用cpu。所以kernel得制定规则维护秩序。

    权限：
    kernel在制定规则的时候受我大天朝户口制度的启发，规定：

        kernel属于城市户口享有特权；
        app 属于农村户口，某些事情需要进城（交给kernel陷入内核），kernel像官老爷一样来给你来处理，
        比如某些对设备的具体操控，处理完了把数据结果告诉你；如果你要计算1+1=2那到不用进城。

    中断：

        官老爷还养了一条狗，这条狗定时会叫（硬中断），官老爷用它来计时，以此分配每个app的用时。当然还有其他硬中断，
        这些会直接通过电路的某个管脚直接反馈上去。
        当app在干活的时候，kernel也随时standby，除了上面说的想做超过自己权限的事情得打报告等结果。同时kernel还监控app的运行，
        哪里出现个除零操作啊非法地址操作段错误啊等等也会被kernel获知（软中断），kernel就在此接管给你个coredump。


    概念：

        躺在硬盘里的叫程序。
        从硬盘里跑到内存可以随时执行的叫进程。
        在进程这个主干上又可以分多条控制流，比如一个活得分身两人才行：一个望风，一个干活，望风的有情况随时通知干活，所以他们之间得通信，黑话叫同步。
        调度很好理解但工作不好做，因为总得照顾好VIP和屌丝之间平衡。
        微内核就是非常懒得一种内核，懒到他只负责各大模块的通信，其他一概不管。
        宏内核就是恰恰相反的一种，什么调度驱动文件系统通信他都管。

    书：

        对于书的话，你要是能把那些intel的大部头英文手册看进去那真是NB。
        要是不行的话就从简单的开始吧，陈莉君有本很薄的书可以从它开始。
        光看书还是没用的还得看kernel源码，看的时候时刻提醒自己，kernel与其他app不同的地方是，kernel处理的数据是内存！你会看到一堆堆的地址处理。

    最后，Nachos是赫赫有名的教学用OS。万分推荐。
     */
}

void Linux::vim()
{
    /**
    高级一些的编辑器，都会包含宏功能，vim当然不能缺少了，在vim中使用宏是非常方便的：

    :qx     开始记录宏，并将结果存入寄存器x
    q     退出记录模式
    @x     播放记录在x寄存器中的宏命令
    稍微解释一下，当在normal模式下输入:qx后，你对文本的所有编辑动作将会被记录下来，再次输入q即退出了记录模
    式，然后输入@x对刚才记录下来的命令进行重复，此命令后可跟数字，表示要重复多少次，比如@x20，可以重复20次。这个在文本的批处理中是非常有用的。
    同时编辑多个文件
    在vim众多的插件中，有一个叫minibuffer的插件，就是下面所说的标签页功能了，可以支持同时编辑多个文件。
    标签命令

    :tabe fn     在一个新的标签页中编辑文件fn
    gt     切换到下一个标签页
    gT     切换到上一个标签页
    :tabr     切换到第一个标签页
    :tabl     切换到最后一个标签页
    :tabm [N]     把当前tab移动到第N个tab之后
    对，正如你所想象的那样，跟eclipse, ue等的标签页是一个意思！
    窗口命令
    ctrl+w s     水平分割窗口
    ctrl+w w     切换窗口
    ctrl+w q     退出当前窗口(由于同时有多个文件，此命令不会影响其他窗口)
    ctrl+w v     垂直分割窗口
    其他
    vim在保存之前不会对文件做实际的修改，只是加载到缓冲区中，对文件的编辑其实是对缓冲区的编辑，直到:w时才会存入物理文件。

    :e file     把file加载到新的缓冲区中
    :bn     跳转到下一个缓冲区
    :bd     删除缓冲区(关闭文件)
    :sp fn     分割窗口，并将fn加载到新的窗口中
    退出编辑器

    :w     将缓冲区写入文件，即保存修改
    :wq     保存修改并退出
    :x     保存修改并退出
    :q     退出，如果对缓冲区进行过修改，则会提示
    :q!     强制退出，放弃修改
    查找替换
    /pattern     向后搜索字符串pattern
    ?pattern     向前搜索字符串pattern
    n     下一个匹配(如果是/搜索，则是向下的下一个，?搜索则是向上的下一个)
    N     上一个匹配(同上)
    :%s/old/new/g     搜索整个文件，将所有的old替换为new
    :%s/old/new/gc     搜索整个文件，将所有的old替换为new，每次都要你确认是否替换
    复制粘贴
    dd     删除光标所在行
    dw     删除一个字(word)
    x     删除当前字符
    X     删除前一个字符
    D     删除到行末
    yy     复制一行，此命令前可跟数字，标识复制多行，如6yy，表示从当前行开始复制6行
    yw     复制一个字
    y$     复制到行末
    ggdG  全部删除
    p     粘贴粘贴板的内容到当前行的下面
    P     粘贴粘贴板的内容到当前行的上面
    ]p     有缩进的粘贴，vim会自动调节代码的缩进
    "a     将内容放入/存入a寄存器，可以支持多粘贴板
    附：比如常用的一个寄存器就是系统寄存器，名称为+，所以从系统粘贴板粘贴到vim中的命令为"+p,注意此处的+不表示操作符，二十一个寄存器。
    移动光标
    在vim中移动光标跟其他的编辑器中有很大的区别，不过一旦学会了，就会飞速的在文本中移动了。

    h,j,k,l     上，下，左，右
    ctrl-f     上翻一页
    ctrl-b     下翻一页
    %     跳到与当前括号匹配的括号处，如当前在{，则跳转到与之匹配的}处
    w     跳到下一个字首，按标点或单词分割
    W     跳到下一个字首，长跳，如end-of-line被认为是一个字
    e     跳到下一个字尾
    E     跳到下一个字尾，长跳
    b     跳到上一个字
    B     跳到上一个字，长跳
    0     跳至行首，不管有无缩进，就是跳到第0个字符
    ^     跳至行首的第一个字符
    $     跳至行尾
    gg     跳至文件的第一行
    gd     跳至当前光标所在的变量的声明处
    [N]G     跳到第N行，如0G，就等价于gg，100G就是第100行
    fx     在当前行中找x字符，找到了就跳转至
    ;     重复上一个f命令，而不用重复的输入fx
    tx     与fx类似，但是只是跳转到x的前一个字符处
    Fx     跟fx的方向相反
    ),(     跳转到上/下一个语句
    *     查找光标所在处的单词，向下查找
    #     查找光标所在处的单词，向上查找
    `.     跳转至上次编辑位置
    在屏幕上移动

    H     移动光标到当前屏幕上最上边的一行
    M     移动光标到当前屏幕上中间的一行
    L     移动光标到当前屏幕上最下边的一行
    书签
    ma     把当前位置存成标签a
    `a     跳转到标签a处
    编辑
    r     替换一个字符
    J     将下一行和当前行连接为一行
    cc     删除当前行并进入编辑模式
    cw     删除当前字，并进入编辑模式
    c$     擦除从当前位置至行末的内容，并进入编辑模式
    s     删除当前字符并进入编辑模式
    S     删除光标所在行并进入编辑模式
    xp     交换当前字符和下一个字符
    u     撤销
    ctrl+r     重做
    .     重复上一个编辑命令
    ~     切换大小写，当前字符
    g~iw     切换当前字的大小写
    gUiw     将当前字变成大写
    guiw     将当前字变成小写
    >>     将当前行右移一个单位
    <<     将当前行左移一个单位(一个tab符)
    ==     自动缩进当前行

    插入模式
    i     从当前光标处进入插入模式
    I     进入插入模式，并置光标于行首
    a     追加模式，置光标于当前光标之后
    A     追加模式，置光标于行末
    o     在当前行之下新加一行，并进入插入模式
    O     在当前行之上新加一行，并进入插入模式
    Esc     退出插入模式
    可视模式
    标记文本
    v     进入可视模式，单字符模式
    V     进入可视模式，行模式
    ctrl+v     进入可视模式，列模式，类似于UE的列模式
    o     跳转光标到选中块的另一个端点
    U     将选中块中的内容转成大写
    O     跳转光标到块的另一个端点
    aw     选中一个字
    ab     选中括号中的所有内容，包括括号本身
    aB     选中{}括号中的所有内容
    ib     选中括号中的内容，不含括号
    iB     选中{}中的内容，不含{}

    对标记进行动作
    >     块右移
    <     块左移
    y     复制块
    d     删除块
    ~     切换块中内容的大小写

    1． $ ctags –R * ($ 为Linux系统Shell提示符)
    2. $ vi –t tag (请把tag替换为您欲查找的变量或函数名)
    3． ：ts (ts 助记字：tags list, “:”开头的命令为VI中命令行模式命令)
    4． ：tp (tp 助记字：tags preview)—&#61664;此命令不常用，可以不用记
    5． ：tn (tn 助记字：tags next) —&#61664;此命令不常用，可以不用记
    6． Ctrl + ]
    7． Ctrl + T

    vim分割窗口的操作
    :split                        水平（上下）分割窗口
    :vsplit或者CTRL-W v           垂直（左右）分割窗口
    :new                          水平分割窗口，创建空文件
    :vnew                         垂直分割窗口，创建空文件

    vim多窗口操作命令
    :qall                         退出所有窗口
    :wall                         保存所有窗口
    :wqall或者:xall               保存并退出所有窗口
    :wqall!或者:xall！            保存并退出所有窗口，如果有的文件只读，不需要先设置写权限
    :qall!                        强制退出所有窗口
    CTRL-W W                      在窗口间移动
    CTRL-W O                      关闭其他所有窗口

    从一个文件复制到另一个文件
    V然后选择吧，选择好了，就按下y
     **/
}

void Linux::vim_conf()
{
    /**
     http://www.cnblogs.com/softwaretesting/archive/2011/07/12/2104435.html
     配置Vim的IDE编辑器
     "关于显示乱码的问题
     set fencs=utf-8,GB18030,ucs-bom,default,latin1

     开启文件类型侦测
     filetype on
     "根据侦测到的不同类型加载对应的插件
     filetype plugin on
     "根据侦测到的不同类型采用不同的缩进
     filetype indent on

     @a 下载ctags
     sudo apt-get install ctags

     @a 生成tags,用一下命令, 否则omnicppcomplete不能识别,补全功能就用不了.
     $ ctags -R  --c-kinds=+p --c++-kinds=+p --fields=+ialS --extra=+q .


     @a ctags --c-kinds=+px --c++-kinds=+px --fields=+iafkslS --extra=+qf your_file.cpp
        有了这个tag,还可以发挥vim的跳转功能.记得--extra一定要+f,这样遇到头文件我们也能跳转进头文件了
        要加 --fields=+lS 否则 echofunc.vim 插件识别不了

     @a 在.vimrc文件中设置vim使用的tags
        set tags=tags
        set tags+=./tags
        set tags+=path/tags

        [+ctrl+i 跳转到函数、变量和#define
        [+ctrl+d 跳转到#define处
        ctrl+i 向前跳到前几次光标位置
        ctrl+o 向后跳到后几次光标位置

        :ts //选择对应的tags
        用ctrl+]或者:tag跳转

        公司的代码.h和.c代码不在同一个目录，发现使用gf无法跳转到相应的头文件。
        解决方法是
        set path+=xxx
        xxx是头文件所在目录

        找到 tag：1 / 14 或更多
        :tselect        "显示列表

    @a 安装Taglist, 把插件解压放在.vim目录下.
       用TlistToggle 来打开窗口, 后期可以用winmanager来管理Taglist和nerdtree的布局
        F1      打开帮助
        回车键      跳到光标所在的标记的定义处(如将光标移到main函数,按回车键)
        o      新建一个窗口,跳到标记定义处
        p      预览标记定义(仍然在taglist窗口)
        空格      显示标记的原型(如函数原型)
        u      更新标记列表(比如源文件新增了一个函数,并在保存后,可在taglist窗口按u)
        s      选择排序字段
        d      删除光标所在的taglist文件(如用vi打开了两个文件f1.c,f2.c可以删除f1.c的标记)
        x      放大/缩小taglist窗口
        +      展开(指标记)
        -      折叠
        *      全部展开
        =      全部折叠
        [[      将光标移到前一个文件的起点
        ]]      将光标移到后一个文件的起点
        q      退出taglist窗口
        F1      关闭帮助

    @a 安装NERDTree, 把插件解压放在vim目录下
       用NERDTreeToggle 来打开窗口, 同Taglist

    @a 安装cscope, 这是用来查找的.
        sudo apt-get install cscope
        cscope 默认是c语言,如果要识别c++, 需要把文件放到 cscope.files里面,
        find . -name "*.h" -o -name "*.c" -o -name "*.cc" -o -name "*.cpp"  > cscope.files
        cscope -Rbq -i cscope.files
        ctags -R

        $ cscope -Rbq -f path/cscope.out (path是路径)
        $ cs add path/cscope.out (打开vim的情况)
        "if has("cscope") && filereadable("/usr/bin/cscope")
        " set csprg=/usr/bin/cscope
        " set csto=0
        " set cst
        " set nocsverb
        " " add any database in current directory
        " if filereadable("cscope.out")
        " cs add cscope.out
        " " else add database pointed to by environment
        " elseif $CSCOPE_DB != ""
        " cs add $CSCOPE_DB
        " endif
        " set csverb
        "endif
        nmap <C-@>s :cs find s <C-R>=expand("<cword>")<CR><CR>
        nmap <C-@>g :cs find g <C-R>=expand("<cword>")<CR><CR>
        nmap <C-@>c :cs find c <C-R>=expand("<cword>")<CR><CR>
        nmap <C-@>t :cs find t <C-R>=expand("<cword>")<CR><CR>
        nmap <C-@>e :cs find e <C-R>=expand("<cword>")<CR><CR>
        nmap <C-@>f :cs find f <C-R>=expand("<cfile>")<CR><CR>
        nmap <C-@>i :cs find i ^<C-R>=expand("<cfile>")<CR>$<CR>
        nmap <C-@>d :cs find d <C-R>=expand("<cword>")<CR><CR>
        let Tlist_Show_One_File = 1 "不同时显示多个文件的tag，只显示当前文件的
        let Tlist_Exit_OnlyWindow = 1 "如果taglist窗口是最后一个窗口，则退出vim
        let Tlist_Use_Right_Window = 1 "在右侧窗口中显示taglist窗口
        有英文注释的我就不说明了，我就说一下里边的键map映射
        如： nmap <C-\>s :cs find s <C-R>=expand("<cword>")<CR><CR>

            nmap 表示在vim的普通模式下，即相对于：编辑模块和可视模式，以下是几种模式
                        :map            普通，可视模式及操作符等待模式
                        :vmap           可视模式
                        :omap           操作符等待模式
                        :map!           插入和命令行模式
                        :imap           插入模式
                        :cmap           命令行模式
            <C-\>表示：Ctrl+\
            s表示输入(即按：s)s
            : 表示输入':'
            “cs find s"表示输入"cs find s"也即是要输入的命令
            <C-R>=expand("cword")总体是为了得到：光标下的变量或函数。cword 表示：cursor word, 类似的还有：cfile表示光标所在处的文件名

    @a  安装omnicppcomplete, 解压
        要在.vimrc 下添加:
        set nocp
        let OmniCpp_MayCompleteDot = 1 " autocomplete with .
        let OmniCpp_MayCompleteArrow = 1 " autocomplete with ->
        let OmniCpp_MayCompleteScope = 1 " autocomplete with ::
        let OmniCpp_SelectFirstItem = 2 " select first item (but don't insert)
        let OmniCpp_NamespaceSearch = 2 " search namespaces in this and included files
        let OmniCpp_ShowPrototypeInAbbr = 1 " show function prototype in popup window
        let OmniCpp_GlobalScopeSearch=1 " enable the global scope search
        let OmniCpp_DisplayMode=1 " Class scope completion mode: always show all members
        "let OmniCpp_DefaultNamespaces=["std"]
        let OmniCpp_ShowScopeInAbbr=1 " show scope in abbreviation and remove the last column
        let OmniCpp_ShowAccess=1

    @a  安装echofunc, 这个用来显示函数原型的插件
        把echofunc.vim 文件放到 .vim/plugin 下

    @a  安装SuperTab, 下载SuperTab.vba
        用Vi打开 SuperTab.vba 文件, 输入 UseVimball ~/.vim (打开vim的情况)

    @a  安装a.vim ,用来实现头文件和cpp文件之间的切换
        把 a.vim 文件放到 .vim/plugin 下
        头/源文件切换命令
                :A 头文件／源文件切换
                :AS 分割窗后并切换头/源文件(切割为上下两个窗口)
                :AV 垂直切割窗口后切换头/源文件(切割为左右两个窗口)
                :AT 新建Vim标签式窗口后切换
                :AN 在多个匹配文件间循环切换
            将光标所在处单词作为文件名打开
                :IH 切换至光标所在文件
                :IHS 分割窗口后切换至光标所在文件(指将光标所在处单词作为文件名打开)
                :IHV 垂直分割窗口后切换
                :IHT 新建标签式窗口后切换
                :IHN 在多个匹配文件间循环切换
            快捷键操作
                <Leader>ih 切换至光标所在文件*
                <Leader>is 切换至光标所在处(单词所指)文件的配对文件(如光标所在处为foo.h，则切换至foo.c/foo.cpp...)
                <Leader>ihn 在多个匹配文件间循环切换

    @a  cpp.vim (设置Qt 关键字)  放在 .vim/syntax/ 里
         不是编辑器的命令
         在 :set ff=unix  (打开vim的情况)

    @a  函数高亮 在 /usr/share/vim/vim73/syntax/c.vim 最后添加
        syn match cFuntions display "[a-zA-Z_][a-zA-Z_0-9]\{-1,}\s\{-0,}(\{1}"ms=s,me=e-1
        hi def link cFuntions Special
     */
}

void Linux::vim_plugin()
{
    /**
      @a  ctags
      设置快捷键: CTRL+F12
      map <C-F12> :!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q .<CR>
      nmap <F7> :!ctags -R --sort=yes --c++-kinds=+p --fields=+ialS --extra=+q .<CR>

      CTRL + ]  跳转到光标所在符号的定义。
      CTRL + t  回到上次跳转前的位置。

      @a  cscope
        sudo apt-get install cscope
      @a  QuickFix

      @a  OmniCppComplete
      @a  SuperTab
      @a  winmanager
          wm 布局 NERDTree 和 Taglist

      @a  taglist
      @a  A
      @a  Grep
      @a  VisualMark
      @a  NERDTree (plugin doc)
      @a  MiniBufExplorer (minibufexpl.vim)
      @a  ~/.vimrc
     */
}

void Linux::vim_taglist_conf()
{
    /**
    <CR>          跳到光标下tag所定义的位置，用鼠标双击此tag功能也一样
    o             在一个新打开的窗口中显示光标下tag
    <Space>       显示光标下tag的原型定义
    u             更新taglist窗口中的tag
    s             更改排序方式，在按名字排序和按出现顺序排序间切换
    x             taglist窗口放大和缩小，方便查看较长的tag
    +             打开一个折叠，同zo
    -             将tag折叠起来，同zc
    *             打开所有的折叠，同zR
    =             将所有tag折叠起来，同zM
    [[            跳到前一个文件
    ]]            跳到后一个文件
    q             关闭taglist窗口
    <F1>          显示帮助

   let Tlist_Show_One_File = 1            "不同时显示多个文件的tag，只显示当前文件的
   let Tlist_Exit_OnlyWindow = 1          "如果taglist窗口是最后一个窗口，则退出vim
   let Tlist_Use_Right_Window = 1         "在右侧窗口中显示taglist窗口

    - Tlist_Ctags_Cmd选项用于指定你的Exuberant ctags程序的位置，如果它没在你PATH变量所定义的路径中，需要使用此选项设置一下；

    - 如果你不想同时显示多个文件中的tag，设置Tlist_Show_One_File为1。缺省为显示多个文件中的tag；

    - 设置Tlist_Sort_Type为”name”可以使taglist以tag名字进行排序，缺省是按tag在文件中出现的顺序进行排序。
        按tag出现的范围（即所属的namespace或class）排序，已经加入taglist的TODO List，但尚未支持；

    - 如果你在想taglist窗口是最后一个窗口时退出VIM，设置Tlist_Exit_OnlyWindow为１；

    - 如果你想taglist窗口出现在右侧，设置Tlist_Use_Right_Window为１。缺省显示在左侧。

    - 在gvim中，如果你想显示taglist菜单，设置Tlist_Show_Menu为１。
        你可以使用Tlist_Max_Submenu_Items和Tlist_Max_Tag_Length来控制菜单条目数和所显示tag名字的长度；

    - 缺省情况下，在双击一个tag时，才会跳到该tag定义的位置，如果你想单击tag就跳转，设置Tlist_Use_SingleClick为１；

    - 如果你想在启动VIM后，自动打开taglist窗口，设置Tlist_Auto_Open为1；

    - 如果你希望在选择了tag后自动关闭taglist窗口，设置Tlist_Close_On_Select为1；

    - 当同时显示多个文件中的tag时，设置Tlist_File_Fold_Auto_Close为１，可使taglist只显示当前文件tag，其它文件的tag都被折叠起来。

    - 在使用:TlistToggle打开taglist窗口时，如果希望输入焦点在taglist窗口中，设置Tlist_GainFocus_On_ToggleOpen为1；

    - 如果希望taglist始终解析文件中的tag，不管taglist窗口有没有打开，设置Tlist_Process_File_Always为1；

    - Tlist_WinHeight和Tlist_WinWidth可以设置taglist窗口的高度和宽度。Tlist_Use_Horiz_Window为１设置taglist窗口横向显示；


    TlistToggle
    NERDTreeToggle
     */
}

void Linux::vim_cscope_conf()
{
    /**
    @a 生成一个cscope的数据库, 在项目的根目录运行下面的命令
     cscope -Rbq -f cscope.out

     进入vim后第一件事是要把刚才生成的cscope文件导入到vim中来, 用下面的命令:
     cs add /home/wooin/vim71/cscope.out /home/wooin/vim71


     */
}

void Linux::clearScreen()
{
    /**
    clear;
    printf "\033c"  ( \033 == \x1B == 27 == ESC )
    reset

     */
}

void Linux::diffMemoryFromRegister()
{
    /**
    （1）找到数据的指针。（指针可能存放在寄存器内，所以这一步就已经包括寄存器的全部工作了。）

    （2）将指针送往内存管理单元（MMU），由MMU将虚拟的内存地址翻译成实际的物理地址。

    （3）将物理地址送往内存控制器（memory controller），由内存控制器找出该地址在哪一根内存插槽（bank）上。

    （4）确定数据在哪一个内存块（chunk）上，从该块读取数据。

    （5）数据先送回内存控制器，再送回CPU，然后开始使用。
      */
}
