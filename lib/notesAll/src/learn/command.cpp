#include "command.h"

command::command()
{
}

void command::ACL()
{
    /**
    ACL 是 Access Control List 的缩写，主要的目的是在提供传统的 owner,group,others 的read,write,execute
        权限之外的细部权限设定。
    ACL 可以针对单一使用者，单一档案或目录来进行 r,w,x 的权限规范，对于需要特殊权限的使用状况非常有帮组。


     */
}

void command::alias()
{
    /**
     $ alias lm='ls -al'

     */
}

void command::badblocks()
{
    /**
    磁盘维护-badblocks
    quotaon 返回 cfdisk
    OPENDIR
    　　功能说明：检查磁盘装置中损坏的区块。
    　　语　　法：badblocks [-svw][-b <区块大小>][-o <输出文件>][磁盘装置][磁盘区块数][启始区块]
    　　补充说明：执行指令时须指定所要检查的磁盘装置，及此装置的磁盘区块数。
    　　参　　数：
    　　-b<区块大小> 指定磁盘的区块大小，单位为字节。
    　　-o<输出文件> 将检查的结果写入指定的输出文件。
    　　-s 在检查时显示进度。
    　　-v 执行时显示详细的信息。
    　　-w 在检查时，执行写入测试。
    　　[磁盘装置] 指定要检查的磁盘装置。
    　　[磁盘区块数] 指定磁盘装置的区块总数。
    　　[启始区块] 指定要从哪个区块开始检查。
     */
}

void command::cat()
{
    /**
    文件管理-cat
    返回 chattr
    OPENDIR
    　　名称：cat
    　　使用权限：所有使用者
    　　使用方式：cat [-AbeEnstTuv] [--help] [--version] fileName
    　　说明：把档案串连接后传到基本输出（萤幕或加 > fileName 到另一个档案）
    　　参数：
    　　-n 或 --number 由 1 开始对所有输出的行数编号
    　　-b 或 --number-nonblank 和 -n 相似，只不过对于空白行不编号
    　　-s 或 --squeeze-blank 当遇到有连续两行以上的空白行，就代换为一行的空白行
    　　-v 或 --show-nonprinting
    　　范例：
    　　cat -n textfile1 > textfile2 把 textfile1 的档案内容加上行号后输入 textfile2 这个档案里
    　　cat -b textfile1 textfile2 >> textfile3 把 textfile1 和 textfile2 的档案内容加上行号（空白行不加）之后将内容附加到 textfile3 里。
    　　范例：
    　　把 textfile1 的档案内容加上行号后输入 textfile2 这个档案里
    　　cat -n textfile1 > textfile2
    　　把 textfile1 和 textfile2 的档案内容加上行号（空白行不加）之后将内容附加到 textfile3 里。
    　　cat -b textfile1 textfile2 >> textfile3
    　　cat /dev/null > /etc/test.txt 此为清空/etc/test.txt档案内容
    　　cat 也可以用来制作 image file。例如要制作软碟的 image file，将软碟放好后打
    　　cat /dev/fd0 > OUTFILE
    　　相反的，如果想把 image file 写到软碟，请打
    　　cat IMG_FILE > /dev/fd0
    　　注：
    　　1. OUTFILE 指输出的 image 档名。
    　　2. IMG_FILE 指 image file。
    　　3. 若从 image file 写回 device 时，device 容量需与相当。
    　　4. 通常用在制作开机磁片。
     */
}

void command::chattr()
{
    /**
    文件管理-chattr
    cat 返回 chgrp
    OPENDIR
        功能说明：改变文件属性。
        语　　法：chattr [-RV][-v<版本编号>][+/-/=<属性>][文件或目录...]
        补充说明：这项指令可改变存放在ext2文件系统上的文件或目录属性，这些属性共有以下8种模式：
        a：让文件或目录仅供附加用途。
        b：不更新文件或目录的最后存取时间。
        c：将文件或目录压缩后存放。
        d：将文件或目录排除在倾倒操作之外。
        i：不得任意更动文件或目录。
        s：保密性删除文件或目录。
        S：即时更新文件或目录。
        u：预防以外删除。
        参　　数：
        -R 递归处理，将指定目录下的所有文件及子目录一并处理。
        -v<版本编号> 设置文件或目录版本。
        -V 显示指令执行过程。
        +<属性> 开启文件或目录的该项属性。
        -<属性> 关闭文件或目录的该项属性。
        =<属性> 指定文件或目录的该项属性。

    chattr可以防止关键文件被修改
    　　在linux下，有些配置文件是不允许任何人包括root修改的，为了防止被误删除或修改，
    可以设定该文件的"不可修改位(immutable)"。
    　　例如：
    　　chattr +i /etc/fstab
    　　如果需要修改文件则：
    　　chattr -i /etc/fstab
    　　以后再修改文件。

        chattr -R -v 1 zsh.txt
    */
}

void command::chgrp()
{
    /**
    文件管理-chgrp
    chattr 返回 chmod
    OPENDIR
    　　功能说明：变更文件或目录的所属群组。
    　　语　　法：chgrp [-cfhRv][--help][--version][所属群组][文件或目录...] 或 chgrp [-cfhRv][--help][--reference=<参考文件或目录>][--version][文件或目录...]
    　　补充说明：在UNIX系统家族里，文件或目录权限的掌控以拥有者及所属群组来管理。您可以使用chgrp指令去变更文件与目录的所属群组，设置方式采用群组名称或群组识别码皆可。
    　　参　　数：
    　　-c或--changes 效果类似"-v"参数，但仅回报更改的部分。
    　　-f或--quiet或--silent 　不显示错误信息。
    　　-h或--no-dereference 　只对符号连接的文件作修改，而不更动其他任何相关文件。
    　　-R或--recursive 　递归处理，将指定目录下的所有文件及子目录一并处理。
    　　-v或--verbose 　显示指令执行过程。
    　　--help 　在线帮助。
    　　--reference=<参考文件或目录> 　把指定文件或目录的所属群组全部设成和参考文件或目录的所属群组相同。
    　　--version 　显示版本信息。
     */
}

void command::chkconfig()
{
    /**
    使用语法：
    chkconfig [--add][--del][--list][系统服务] 或 chkconfig [--level <等级代号>][系统服务][on/off/reset]

    chkconfig在没有参数运行时，显示用法。如果加上服务名，那么就检查这个服务是否在当前运行级启动。如果是，返回true，
    否则返回false。如果在服务名后面指定了on，off或者reset，那么chkconfi 会改变指定服务的启动信息。
    on和off分别指服务被启动和停止，reset指重置服务的启动信息，无论有问题的初始化脚本指定了什么。on和off开关，
    系统默认只对运行级3，4，5有效，但是reset可以对所有运行级有效。

    参数用法：
        --add 　增加所指定的系统服务，让chkconfig指令得以管理它，并同时在系统启动的叙述文件内增加相关数据。
        --del 　删除所指定的系统服务，不再由chkconfig指令管理，并同时在系统启动的叙述文件内删除相关数据。
        --level<等级代号> 　指定读系统服务要在哪一个执行等级中开启或关毕。
        等级0表示：表示关机
        等级1表示：单用户模式
        等级2表示：无网络连接的多用户命令行模式
        等级3表示：有网络连接的多用户命令行模式
        等级4表示：不可用
        等级5表示：带图形界面的多用户模式
        等级6表示：重新启动
        需要说明的是，level选项可以指定要查看的运行级而不一定是当前运行级。对于每个运行级，只能有一个启动脚本或者停止脚本。
        当切换运行级时，init不会重新启动已经启动的服务，也不会再次去停止已经停止的服务。

    chkconfig --list [name]：显示所有运行级系统服务的运行状态信息（on或off）。如果指定了name，那么只显示指定的服务在不同运行级的状态。
    chkconfig --add name：增加一项新的服务。chkconfig确保每个运行级有一项启动(S)或者杀死(K)入口。如有缺少，则会从缺省的init脚本自动建立。
    chkconfig --del name：删除服务，并把相关符号连接从/etc/rc[0-6].d删除。
    chkconfig [--level levels] name：设置某一服务在指定的运行级是被启动，停止还是重置。
     */
}

void command::chkconfig_example()
{
    /**
    防火墙设置
        chkconfig iptables on  开启防火墙
        chkconfig iptables off 关闭防火墙

    运行级文件：
    每个被chkconfig管理的服务需要在对应的init.d下的脚本加上两行或者更多行的注释。
    第一行告诉chkconfig缺省启动的运行级以及启动和停止的优先级。如果某服务缺省不在任何运行级启动，
    那么使用 - 代替运行级。第二行对服务进行描述，可以用\ 跨行注释。
    例如，random.init包含三行：
    # chkconfig: 2345 20 80
    # description: Saves and restores system entropy pool for \
    # higher quality random number generation.

    使用范例：
    chkconfig --list        #列出所有的系统服务
    chkconfig --add httpd        #增加httpd服务
    chkconfig --del httpd        #删除httpd服务
    chkconfig --level httpd 2345 on        #设置httpd在运行级别为2、3、4、5的情况下都是on（开启）的状态
    chkconfig --list        #列出系统所有的服务启动情况
    chkconfig --list mysqld        #列出mysqld服务设置情况
    chkconfig --level 35 mysqld on        #设定mysqld在等级3和5为开机运行服务，--level 35表示操作只在等级3和5执行，on表示启动，off表示关闭
    chkconfig mysqld on        #设定mysqld在各等级为on，“各等级”包括2、3、4、5等级

    如何增加一个服务：
    1.服务脚本必须存放在/etc/ini.d/目录下；
    2.chkconfig --add servicename
        在chkconfig工具服务列表中增加此服务，此时服务会被在/etc/rc.d/rcN.d中赋予K/S入口了；
    3.chkconfig --level 35 mysqld on
        修改服务的默认启动等级。
     */
}

void command::chkfontpath()
{
    /**
     *
     */
}

void command::chmod()
{
    /**
    文件管理-chmod
    chgrp 返回 chown
    OPENDIR
    　　指令名称 : chmod
    　　使用权限 : 所有使用者
    　　使用方式 : chmod [-cfvR] [--help] [--version] mode file...
    　　说明 : Linux/Unix 的档案调用权限分为三级 : 档案拥有者、群组、其他。利用 chmod 可以藉以控制档案如何被他人所调用。
    　　参数 :
    　　mode : 权限设定字串，格式如下 : [ugoa...][[+-=][rwxX]...][,...]，其中
    　　u 表示该档案的拥有者，g 表示与该档案的拥有者属于同一个群体(group)者，o 表示其他以外的人，a 表示这三者皆是。
    　　+ 表示增加权限、- 表示取消权限、= 表示唯一设定权限。
    　　r 表示可读取，w 表示可写入，x 表示可执行，X 表示只有当该档案是个子目录或者该档案已经被设定过为可执行。
    　　-c : 若该档案权限确实已经更改，才显示其更改动作
    　　-f : 若该档案权限无法被更改也不要显示错误讯息
    　　-v : 显示权限变更的详细资料
    　　-R : 对目前目录下的所有档案与子目录进行相同的权限变更(即以递回的方式逐个变更)
    　　--help : 显示辅助说明
    　　--version : 显示版本
    　　范例 :将档案 file1.txt 设为所有人皆可读取 :
    　　chmod ugo+r file1.txt
    　　将档案 file1.txt 设为所有人皆可读取 :
    　　chmod a+r file1.txt
    　　将档案 file1.txt 与 file2.txt 设为该档案拥有者，与其所属同一个群体者可写入，但其他以外的人则不可写入 :
    　　chmod ug+w,o-w file1.txt file2.txt
    　　将 ex1.py 设定为只有该档案拥有者可以执行 :
    　　chmod u+x ex1.py
    　　将目前目录下的所有档案与子目录皆设为任何人可读取 :
    　　chmod -R a+r *
    　　此外chmod也可以用数字来表示权限如 chmod 777 file
    　　语法为：chmod abc file
    　　其中a,b,c各为一个数字，分别表示User、Group、及Other的权限。
    　　r=4，w=2，x=1
    　　若要rwx属性则4+2+1=7；
    　　若要rw-属性则4+2=6；
    　　若要r-x属性则4+1=5。
    　　范例：
    　　chmod a=rwx file
    　　和
    　　chmod 777 file
    　　效果相同
    　　chmod ug=rwx,o=x file
    　　和
    　　chmod 771 file
    　　效果相同
    　　若用chmod 4755 filename可使此程序具有root的权限
     */
}

void command::chown()
{
    /**
    文件管理-chown
    chmod 返回 cksum
    OPENDIR
    　　指令名称 : chown
    　　使用权限 : root
    　　使用方式 : chmod [-cfhvR] [--help] [--version] user[:group] file...
    　　说明 : Linux/Unix 是多人多工操作系统，所有的档案皆有拥有者。利用 chown 可以将档案的拥有者加以改变。
        一般来说，这个指令只有是由系统管理者(root)所使用，一般使用者没有权限可以改变别人的档案拥有者，
        也没有权限把自己的档案拥有者改设为别人。只有系统管理者(root)才有这样的权限。

    　　参数 :
        user : 新的档案拥有者的使用者
        IDgroup : 新的档案拥有者的使用者群体(group)
        -c : 若该档案拥有者确实已经更改，才显示其更改动作
        -f : 若该档案拥有者无法被更改也不要显示错误讯息
        -h : 只对于连结(link)进行变更，而非该 link 真正指向的档案
        -v : 显示拥有者变更的详细资料
        -R : 对目前目录下的所有档案与子目录进行相同的拥有者变更(即以递回的方式逐个变更)

        --help : 显示辅助说明
        --version : 显示版本
    　　范例 :
    　　将档案 file1.txt 的拥有者设为 users 群体的使用者 jessie :
    　　chown jessie:users file1.txt
    　　将目前目录下的所有档案与子目录的拥有者皆设为 users 群体的使用者 lamport :
    　　chmod -R lamport:users *
     */
}

void command::chsh()
{
    /**
    系统管理-chsh
    uname 返回 userconf
    OPENDIR
    　　名称：chsh
    　　使用权限：所有使用者
    　　用法：shell>> chsh
    　　说明：更改使用者 shell 设定
    　　范例：
    　　shell>> chsh
    　　Changing fihanging shell for user1
    　　Password: [del]
    　　New shell [/bin/tcsh]: ### [是目前使用的 shell]
    　　[del]
    　　shell>> chsh -l ### 展示 /etc/shells 档案内容
    　　/bin/bash
    　　/bin/sh
    　　/bin/ash
    　　/bin/bsh
    　　/bin/tcsh
    　　/bin/csh

    */
}

void command::cksum()
{
    /**
    文件管理-cksum
    chown 返回 cmp
    OPENDIR
    　　功能说明：检查文件的CRC是否正确。
    　　语　　法：cksum [--help][--version][文件...]
    　　补充说明：CRC是一种排错检查方式，该演算法的标准由CCITT所指定，至少可检测到99.998%的已知错误。指定文件交由cksum演算，它会回报计算结果，供用户核对文件是否正确无误。若不指定任何文件名称或是所给予的文件名为"-"，则cksum指令会从标准输入设备读取数据。
    　　参　　数：
    　　--help 　在线帮助。
    　　--version 　显示版本信息。
     */
}

void command::cmp()
{
    /**
    文件管理-cmp
    cksum 返回 diff
    OPENDIR
    　　功能说明：比较两个文件是否有差异。
    　　语　　法：cmp [-clsv][-i <字符数目>][--help][第一个文件][第二个文件]
    　　补充说明：当相互比较的两个文件完全一样时，则该指令不会显示任何信息。若发现有所差异，预设会标示出第一个不同之处的字符和列数编号。若不指定任何文件名称或是所给予的文件名为"-"，则cmp指令会从标准输入设备读取数据。
    　　参　　数：
    　　-c或--print-chars 　除了标明差异处的十进制字码之外，一并显示该字符所对应字符。
    　　-i<字符数目>或--ignore-initial=<字符数目> 　指定一个数目。
    　　-l或--verbose 　标示出所有不一样的地方。
    　　-s或--quiet或--silent 　不显示错误信息。
    　　-v或--version 　显示版本信息。
    　　--help 　在线帮助。
     */
}

void command::col()
{
    /**
文档编辑-col
whereis 返回 colrm
OPENDIR
　　功能说明：过滤控制字符。
　　语　　法：col [-bfx][-l<缓冲区列数>]
　　补充说明：在许多UNIX说明文件里，都有RLF控制字符。当我们运用shell特殊字符">"和">>"，把说明文件的内容输出成纯文本文件时，控制字符会变成乱码，col指令则能有效滤除这些控制字符。
　　参　　数：
　　-b 过滤掉所有的控制字符，包括RLF和HRLF。
　　-f 滤除RLF字符，但允许将HRLF字符呈现出来。
　　-x 以多个空格字符来表示跳格字符。
　　-l<缓冲区列数> 预设的内存缓冲区有128列，您可以自行指定缓冲区的大小。
     */
}

void command::colrm()
{
    /**
文档编辑-colrm
col 返回 comm
OPENDIR
　　功能说明：滤掉指定的行。
　　语　　法：colrm [开始行数编号<结束行数编号>]
　　补充说明：colrm指令从标准输入设备读取书记，转而输出到标准输出设备。如果不加任何参数，则该指令不会过滤任何一行。
     */
}

void command::comm()
{
    /**
文档编辑-comm
colrm 返回 csplit
OPENDIR
　　功能说明：比较两个已排过序的文件。
　　语　　法：comm [-123][--help][--version][第1个文件][第2个文件]
　　补充说明：这项指令会一列列地比较两个已排序文件的差异，并将其结果显示出来，如果没有指定任何参数，则会把结果分成3行显示：第1行仅是在第1个文件中出现过的列，第2行是仅在第2个文件中出现过的列，第3行则是在第1与第2个文件里都出现过的列。若给予的文件名称为"-"，则comm指令会从标准输入设备读取数据。
　　参　　数：
　　-1 不显示只在第1个文件里出现过的列。
　　-2 不显示只在第2个文件里出现过的列。
　　-3 不显示只在第1和第2个文件里出现过的列。
　　--help 在线帮助。
　　--version 显示版本信息。
     */
}

void command::cp()
{
    /**
    文件管理-cp
    which 返回 in
    OPENDIR
    　　名称：cp
    　　使用权限：所有使用者
    　　使用方式：
    　　cp [options] source dest
    　　cp [options] source... directory
    　　说明：将一个档案拷贝至另一档案，或将数个档案拷贝至另一目录。
    　　参数：
    　　-a 尽可能将档案状态、权限等资料都照原状予以复制。
    　　-r 若 source 中含有目录名，则将目录下之档案亦皆依序拷贝至目的地。
    　　-f 若目的地已经有相同档名的档案存在，则在复制前先予以删除再行复制。
    　　范例：
    　　将档案 aaa 复制(已存在)，并命名为 bbb :
    　　cp aaa bbb
    　　将所有的C语言程序拷贝至 Finished 子目录中 :
    　　cp *.c Finished
    
    find *.c -exec cp ‘{}’ /tmp ‘;’

        有进度条
    rsync -a --progress src dest

     */
}

void command::csplit()
{
    /**
文档编辑-csplit
comm 返回 ed
OPENDIR
　　功能说明：分割文件。
　　语　　法：csplit [-kqsz][-b<输出格式>][-f<输出字首字符串>][-n<输出文件名位数>][--help][--version][文件][范本样式...]
　　补充说明：将文件依照指定的范本样式予以切割后，分别保存成名称为xx00,xx01,xx02...的文件。若给予的文件名称为"-"，则csplit指令会从标准输入设备读取数据。
　　参　　数：
　　-b<输出格式>或--suffix-format=<输出格式> 预设的输出格式其文件名称为xx00,xx01...等，您可以通过改变<输出格式>来改变输出的文件名。
　　-f<输出字首字符串>或--prefix=<输出字首字符串> 预设的输出字首字符串其文件名为xx00,xx01...等，如果你指定输出字首字符串为"hello"，则输出的文件名称会变成hello00,hello01...等。
　　-k或--keep-files 保留文件，就算发生错误或中断执行，也不能删除已经输出保存的文件。
　　-n<输出文件名位数>或--digits=<输出文件名位数> 预设的输出文件名位数其文件名称为xx00,xx01...等，如果你指定输出文件名位数为"3"，则输出的文件名称会变成xx000,xx001...等。
　　-q或-s或--quiet或--silent 不显示指令执行过程。
　　-z或--elide-empty-files 删除长度为0 Byte文件。
　　--help 在线帮助。
　　--version 显示版本信息。
     */
}

void command::cut()
{
    /**
    文件管理-cut
    indent 返回 ln
    OPENDIR
    　　名称：cut
    　　使用权限：所有使用者
    　　用法：cut -cnum1-num2 filename
    　　说明：显示每行从开头算起 num1 到 num2 的文字。
    　　范例：
    　　shell>> cat example
    　　test2
    　　this is test1
    　　shell>> cut -c0-6 example ## print 开头算起前 6 个字元
    　　test2
    　　this i
    　　cut其实很有用
    　　-c m-n 表示显示每一行的第m个字元到第n个字元。例如：
    　　---------file-----------
    　　liubi 23 14000
    　　---------file-----------
    　　# cut -c 3-9,12-20 file
    　　liubi 14000
    　　-f m-n 表示显示第m栏到第n栏(使用tab分隔)。例如：
    　　---------file-----------
    　　liubi 23 14000
    　　---------file-----------
    　　# cut -f 1,3 file
    　　liubi 14000
     */
}

void command::dmesg()
{
    /**
    dmesg | grep -in eth

     */
}

void command::df()
{
    /**
    名称:df
    　　使用权限: 所有使用者>
    　　使用方式: df [选项]... [FILE]...
    　　显示档案系统的状况，或是看所有档案系统的状况(预设值)
    　　-a, --all 包含所有的具有 0 Blocks 的档案系统
    　　--block-size={SIZE} 使用 {SIZE} 大小的 Blocks
    　　-h, --human-readable 使用人类可读的格式(预设值是不加这个选项的...)
    　　-H, --si 很像 -h, 但是用 1000 为单位而不是用 1024
    　　-i, --inodes 列出 inode 资讯，不列出已使用 block
    　　-k, --kilobytes 就像是 --block-size=1024
    　　-l, --local 限制列出的档案结构
    　　-m, --megabytes 就像 --block-size=1048576
    　　--no-sync 取得资讯前与sync (预设值)
    　　-P, --portability 使用 POSIX 输出格式
    　　--sync 在取得资讯前 sync
    　　-t, --type=TYPE 限制列出档案系统的 TYPE
    　　-T, --print-type 显示档案系统的形式
    　　-x, --exclude-type=TYPE 限制列出档案系统不要显示 TYPE
    　　-v (忽略)
    　　--help 显示这个帮手并且离开
    　　--version 输出版本资讯并且离开
     */
}

void command::diff()
{
    /**
    文件管理-diff
    cmp 返回 diffstat
    OPENDIR
    　　功能说明：比较文件的差异。
    　　语　　法：diff [-abBcdefHilnNpPqrstTuvwy][-<行数>][-C <行数>][-D <巨集名称>][-I <字符或字符串>][-S <文件>][-W <宽度>][-x <文件或目录>][-X <文件>][--help][--left-column][--suppress-common-line][文件或目录1][文件或目录2]
    　　补充说明：diff以逐行的方式，比较文本文件的异同处。所是指定要比较目录，则diff会比较目录中相同文件名的文件，但不会比较其中子目录。
    　　参　　数：
    　　-<行数> 　指定要显示多少行的文本。此参数必须与-c或-u参数一并使用。
    　　-a或--text 　diff预设只会逐行比较文本文件。
    　　-b或--ignore-space-change 　不检查空格字符的不同。
    　　-B或--ignore-blank-lines 　不检查空白行。
    　　-c 　显示全部内文，并标出不同之处。
    　　-C<行数>或--context<行数> 　与执行"-c-<行数>"指令相同。
    　　-d或--minimal 　使用不同的演算法，以较小的单位来做比较。
    　　-D<巨集名称>或ifdef<巨集名称> 　此参数的输出格式可用于前置处理器巨集。
    　　-e或--ed 　此参数的输出格式可用于ed的script文件。
    　　-f或-forward-ed 　输出的格式类似ed的script文件，但按照原来文件的顺序来显示不同处。
    　　-H或--speed-large-files 　比较大文件时，可加快速度。
    　　-l<字符或字符串>或--ignore-matching-lines<字符或字符串> 　若两个文件在某几行有所不同，而这几行同时都包含了选项中指定的字符或字符串，则不显示这两个文件的差异。
    　　-i或--ignore-case 　不检查大小写的不同。
    　　-l或--paginate 　将结果交由pr程序来分页。
    　　-n或--rcs 　将比较结果以RCS的格式来显示。
    　　-N或--new-file 　在比较目录时，若文件A仅出现在某个目录中，预设会显示：
    　　Only in目录：文件A若使用-N参数，则diff会将文件A与一个空白的文件比较。
    　　-p 　若比较的文件为C语言的程序码文件时，显示差异所在的函数名称。
    　　-P或--unidirectional-new-file 　与-N类似，但只有当第二个目录包含了一个第一个目录所没有的文件时，才会将这个文件与空白的文件做比较。
    　　-q或--brief 　仅显示有无差异，不显示详细的信息。
    　　-r或--recursive 　比较子目录中的文件。
    　　-s或--report-identical-files 　若没有发现任何差异，仍然显示信息。
    　　-S<文件>或--starting-file<文件> 　在比较目录时，从指定的文件开始比较。
    　　-t或--expand-tabs 　在输出时，将tab字符展开。
    　　-T或--initial-tab 　在每行前面加上tab字符以便对齐。
    　　-u,-U<列数>或--unified=<列数> 　以合并的方式来显示文件内容的不同。
    　　-v或--version 　显示版本信息。
    　　-w或--ignore-all-space 　忽略全部的空格字符。
    　　-W<宽度>或--width<宽度> 　在使用-y参数时，指定栏宽。
    　　-x<文件名或目录>或--exclude<文件名或目录> 　不比较选项中所指定的文件或目录。
    　　-X<文件>或--exclude-from<文件> 　您可以将文件或目录类型存成文本文件，然后在=<文件>中指定此文本文件。
    　　-y或--side-by-side 　以并列的方式显示文件的异同之处。
    　　--help 　显示帮助。
    　　--left-column 　在使用-y参数时，若两个文件某一行内容相同，则仅在左侧的栏位显示该行内容。
    　　--suppress-common-lines 　在使用-y参数时，仅显示不同之处。
     */
}

void command::diffstat()
{
    /**
文件管理-diffstat
diff 返回 file
OPENDIR
　　功能说明：根据diff的比较结果，显示统计数字。
　　语　　法：diff [-wV][-n <文件名长度>][-p <文件名长度>]
　　补充说明：diffstat读取diff的输出结果，然后统计各文件的插入，删除，修改等差异计量。
　　参　　数：
　　-n<文件名长度> 　指定文件名长度，指定的长度必须大于或等于所有文件中最长的文件名。
　　-p<文件名长度> 　与-n参数相同，但此处的<文件名长度>包括了文件的路径。
　　-w 　指定输出时栏位的宽度。
　　-V 　显示版本信息。
     */
}

void command::dirs()
{
    /**
    功能说明：显示目录记录。
    　　语　　法：dirs [+/-n -l]
    　　补充说明：显示目录堆叠中的记录。
    　　参　　数：
    　　+n 显示从左边算起第n笔的目录。
    　　-n 显示从右边算起第n笔的目录。
    　　-l 显示目录完整的记录。
     */
}

void command::du()
{
    /**
    磁盘管理-du
    dirs 返回 edquota
    OPENDIR
    　　功能说明：显示目录或文件的大小。
    　　语　　法：du [-abcDhHklmsSx][-L <符号连接>][-X <文件>][--block-size][--exclude=<目录或文件>][--max-depth=<目录层数>][--help][--version][目录或文件]
    　　补充说明：du会显示指定的目录或文件所占用的磁盘空间。
    　　参　　数：
    　　-a或-all 显示目录中个别文件的大小。
    　　-b或-bytes 显示目录或文件大小时，以byte为单位。
    　　-c或--total 除了显示个别目录或文件的大小外，同时也显示所有目录或文件的总和。
    　　-D或--dereference-args 显示指定符号连接的源文件大小。
    　　-h或--human-readable 以K，M，G为单位，提高信息的可读性。
    　　-H或--si 与-h参数相同，但是K，M，G是以1000为换算单位。
    　　-k或--kilobytes 以1024 bytes为单位。
    　　-l或--count-links 重复计算硬件连接的文件。
    　　-L<符号连接>或--dereference<符号连接> 显示选项中所指定符号连接的源文件大小。
    　　-m或--megabytes 以1MB为单位。
    　　-s或--summarize 仅显示总计。
    　　-S或--separate-dirs 显示个别目录的大小时，并不含其子目录的大小。
    　　-x或--one-file-xystem 以一开始处理时的文件系统为准，若遇上其它不同的文件系统目录则略过。
    　　-X<文件>或--exclude-from=<文件> 在<文件>指定目录或文件。
    　　--exclude=<目录或文件> 略过指定的目录或文件。
    　　--max-depth=<目录层数> 超过指定层数的目录后，予以忽略。
    　　--help 显示帮助。
    　　--version 显示版本信息。
     */
}

void command::ed()
{
    /**
文档编辑-ed
csplit 返回 egrep
OPENDIR
　　功能说明：文本编辑器。
　　语　　法：ed [-][-Gs][-p<字符串>][--help][--version][文件]
　　补充说明：ed是Linux中功能最简单的文本编辑程序，一次仅能编辑一行而非全屏幕方式的操作。
　　参　　数：
　　-G或--traditional 提供回兼容的功能。
　　-p<字符串> 指定ed在command mode的提示字符。
　　-s,-,--quiet或--silent 不执行开启文件时的检查功能。
　　--help 显示帮助。
　　--version 显示版本信息。
     */
}

void command::edquota()
{
    /**
    磁盘管理-edquota
    du 返回 eject
    OPENDIR
    　　功能说明：编辑用户或群组的quota。
    　　语　　法：edquota [-p <源用户名称>][-ug][用户或群组名称...] 或 edquota [-ug] -t
    　　补充说明：edquota预设会使用vi来编辑使用者或群组的quota设置。
    　　参　　数：
    　　-u 设置用户的quota，这是预设的参数。
    　　-g 设置群组的quota。
    　　-p<源用户名称> 将源用户的quota设置套用至其他用户或群组。
    　　-t 设置宽限期限。
     */
}

void command::echo()
{
    /**
    echo命令的功能是在显示器上显示一段文字，一般起到一个提示的作用。
    该命令的一般格式为： echo [ -n ] 字符串

    其中选项n表示输出文字后不换行；字符串能加引号，也能不加引号。用echo命令输出加引号的字符串时，
    将字符串原样输出；用echo命令输出不加引号的字符串时，将字符串中的各个单词作为字符串输出，各字符串之间用一个空格分割。

    功能说明：显示文字。
    语 　 法：echo [-ne][字符串]或 echo [--help][--version]

    补充说明：echo会将输入的字符串送往标准输出。输出的字符串间以空白字符隔开, 并在最后加上换行号。
    参　　 数：-n 不要在最后自动换行

    -e 若字符串中出现以下字符，则特别加以处理，而不会将它当成一般

    文字输出：
       \a 发出警告声；
       \b 删除前一个字符；
       \c 最后不加上换行符号；
       \f 换行但光标仍旧停留在原来的位置；
       \n 换行且光标移至行首；
       \r 光标移至行首，但不换行；
       \t 插入tab；
       \v 与\f相同；
       \\ 插入\字符；
       \nnn 插入nnn（八进制）所代表的ASCII字符；

    –help 显示帮助
    –version 显示版本信息
     */
}

void command::egrep()
{
    /**
    文档编辑-egrep
    ed 返回 ex
    OPENDIR
    　　功能说明：在文件内查找指定的字符串。
        egrep执行效果如grep
        -E，使用的语法及参数可参照grep指令，与grep不同点在于解读字符串的方法，
        egrep是用extended regular expression语法来解读，
        而grep则用basic regular expression语法，
        extended regular expression比basic regular expression有更完整的表达规
     */
}

void command::eject()
{
    /**
    磁盘管理-eject
    edquota 返回 mcd
    OPENDIR
    　　功能说明：退出抽取式设备。
    　　语　　法：eject [-dfhnqrstv][-a <开关>][-c <光驱编号>][设备]
    　　补充说明：若设备已挂入，则eject会先将该设备卸除再退出。
    　　参　　数：
    　　[设备] 设备可以是驱动程序名称，也可以是挂入点。
    　　-a<开关>或--auto<开关> 控制设备的自动退出功能。
    　　-c<光驱编号>或--changerslut<光驱编号> 选择光驱柜中的光驱。
    　　-d或--default 显示预设的设备，而不是实际执行动作。
    　　-f或--floppy 退出抽取式磁盘。
    　　-h或--help 显示帮助。
    　　-n或--noop 显示指定的设备。
    　　-q或--tape 退出磁带。
    　　-r或--cdrom 退出光盘。
    　　-s或--scsi 以SCSI指令来退出设备。
    　　-t或--trayclose 关闭光盘的托盘。
    　　-v或--verbose 执行时，显示详细的说明。
     */
}

void command::ex()
{
    /**
    文档编辑-ex
    egrep 返回 fgrep
    OPENDIR
    　　功能说明：在Ex模式下启动vim文本编辑器。ex执行效果如同vi -E，使用语法及参数可参照vi指令，如要从Ex模式回到普通模式，则在vim中输入:
     */
}

void command::fdisk()
{
    /**
    \brief

    fdisk -l /dev/sda ，观察硬盘之实体使用情形。  或者

    fdisk /dev/sda，可进入分割硬盘模式。

    1. 输入 m 显示所有命令列示。

    2. 输入 p 显示硬盘分割情形。

    3. 输入 a 设定硬盘启动区。

    4. 输入 n 设定新的硬盘分割区。

        4.1. 输入 e 硬盘为[延伸]分割区(extend)。

        4.2. 输入 p 硬盘为[主要]分割区(primary)。

    5. 输入 t 改变硬盘分割区属性。

    6. 输入 d 删除硬盘分割区属性。

    7. 输入 q 结束不存入硬盘分割区属性。

    8. 输入 w 结束并写入硬盘分割区属性



    扩展资料:linuxso站长总结的添加分区的流程

    fdisk  /dev/sda

    p   列出当前分区表

    n  添加新分区

    回车  选择开始的块地址,直接回车默认就可以了

    +2G   输入要添加分区的大小+200M，+1G这样的都能识别

    回车  确定

    w   写入并退出

    partprobe  更新当前分区表给内核 这一步非常重要, 否则你的分区重启才能看到.

    mkfs.ext3 /dev/sda6   格式化新建分区

    mount /dev/sda6 /data   挂载

    另外t 参数可以对分区格式做转换，fd是raid类型,e8是做LVM时用到的pv类型。

    前几天在学RHCE的分区练习..所以这些。。已经相当熟悉了，呵呵.

    关于使用fdisk命令对磁盘分区添加删除格式化等操作的详细使用
    */
}

void command::fgrep()
{
    /**
    文档编辑-fgrep
    ex 返回 fmt
    OPENDIR
    　　功能说明：查找文件里符合条件的字符串。
    　　语　　法：fgrep [范本样式][文件或目录...]
    　　补充说明：本指令相当于执行grep指令加上参数"-F"，详见grep指令说明。
     */
}

void command::file()
{
    /**
    @brief

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

void command::find()
{
    /**
    Linux中find常见用法示例
    ·find   path   -option   [   -print ]   [ -exec   -ok   command ]   {} \;
    find命令的参数；

    pathname: find命令所查找的目录路径。例如用.来表示当前目录，用/来表示系统根目录。
    -print： find命令将匹配的文件输出到标准输出。
    -exec： find命令对匹配的文件执行该参数所给出的shell命令。相应命令的形式为'command' { } \;，注意{ }和\；之间的空格。
    -ok： 和-exec的作用相同，只不过以一种更为安全的模式来执行该参数所给出的shell命令，在执行每一个命令之前，都会给出提示，让用户来确定是否执行。

    #-print 将查找到的文件输出到标准输出
    #-exec   command   {} \;      —–将查到的文件执行command操作,{} 和 \;之间有空格
    #-ok 和-exec相同，只不过在操作前要询用户
    例：
find . -name .svn | xargs rm -rf
    ====================================================

    -name   filename             #查找名为filename的文件
    -perm                        #按执行权限来查找
    -user    username             #按文件属主来查找
    -group groupname            #按组来查找
    -mtime   -n +n                #按文件更改时间来查找文件，-n指n天以内，+n指n天以前
    -atime    -n +n               #按文件访问时间来查GIN: 0px">

    -ctime    -n +n              #按文件创建时间来查找文件，-n指n天以内，+n指n天以前

    -nogroup                     #查无有效属组的文件，即文件的属组在/etc/groups中不存在
    -nouser                     #查无有效属主的文件，即文件的属主在/etc/passwd中不存
    -newer   f1 !f2              找文件，-n指n天以内，+n指n天以前
    -ctime    -n +n               #按文件创建时间来查找文件，-n指n天以内，+n指n天以前
    -nogroup                     #查无有效属组的文件，即文件的属组在/etc/groups中不存在
    -nouser                      #查无有效属主的文件，即文件的属主在/etc/passwd中不存
    -newer   f1 !f2               #查更改时间比f1新但比f2旧的文件
    -type    b/d/c/p/l/f         #查是块设备、目录、字符设备、管道、符号链接、普通文件
    -size      n[c]               #查长度为n块[或n字节]的文件
    -depth                       #使查找在进入子目录前先行查找完本目录
    -fstype                     #查更改时间比f1新但比f2旧的文件
    -type    b/d/c/p/l/f         #查是块设备、目录、字符设备、管道、符号链接、普通文件
    -size      n[c]               #查长度为n块[或n字节]的文件
    -depth                       #使查找在进入子目录前先行查找完本目录
    -fstype                      #查位于某一类型文件系统中的文件，这些文件系统类型通常可 在/etc/fstab中找到
    -mount                       #查文件时不跨越文件系统mount点
    -follow                      #如果遇到符号链接文件，就跟踪链接所指的文件
    -cpio                %;      #查位于某一类型文件系统中的文件，这些文件系统类型通常可 在/etc/fstab中找到
    -mount                       #查文件时不跨越文件系统mount点
    -follow                      #如果遇到符号链接文件，就跟踪链接所指的文件
    -cpio                        #对匹配的文件使用cpio命令，将他们备份到磁带设备中
    -prune                       #忽略某个目录

    文件管理-find
    file 返回 git
    OPENDIR
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
    　　find . -name "*" -exec grep xxx {} ; -print |morexxx为你想要找的字符串
     */
}

void command::find_example()
{
    find();
    /**
    ====================================================

    -name   filename             #查找名为filename的文件
    -perm                        #按执行权限来查找
    -user    username             #按文件属主来查找
    -group groupname            #按组来查找
    -mtime   -n +n                #按文件更改时间来查找文件，-n指n天以内，+n指n天以前
    -atime    -n +n               #按文件访问时间来查GIN: 0px">

    -ctime    -n +n              #按文件创建时间来查找文件，-n指n天以内，+n指n天以前

    -nogroup                     #查无有效属组的文件，即文件的属组在/etc/groups中不存在
    -nouser                     #查无有效属主的文件，即文件的属主在/etc/passwd中不存
    -newer   f1 !f2              找文件，-n指n天以内，+n指n天以前
    -ctime    -n +n               #按文件创建时间来查找文件，-n指n天以内，+n指n天以前
    -nogroup                     #查无有效属组的文件，即文件的属组在/etc/groups中不存在
    -nouser                      #查无有效属主的文件，即文件的属主在/etc/passwd中不存
    -newer   f1 !f2               #查更改时间比f1新但比f2旧的文件
    -type    b/d/c/p/l/f         #查是块设备、目录、字符设备、管道、符号链接、普通文件
    -size      n[c]               #查长度为n块[或n字节]的文件
    -depth                       #使查找在进入子目录前先行查找完本目录
    -fstype                     #查更改时间比f1新但比f2旧的文件
    -type    b/d/c/p/l/f         #查是块设备、目录、字符设备、管道、符号链接、普通文件
    -size      n[c]               #查长度为n块[或n字节]的文件
    -depth                       #使查找在进入子目录前先行查找完本目录
    -fstype                      #查位于某一类型文件系统中的文件，这些文件系统类型通常可 在/etc/fstab中找到
    -mount                       #查文件时不跨越文件系统mount点
    -follow                      #如果遇到符号链接文件，就跟踪链接所指的文件
    -cpio                %;      #查位于某一类型文件系统中的文件，这些文件系统类型通常可 在/etc/fstab中找到
    -mount                       #查文件时不跨越文件系统mount点
    -follow                      #如果遇到符号链接文件，就跟踪链接所指的文件
    -cpio                        #对匹配的文件使用cpio命令，将他们备份到磁带设备中
    -prune                       #忽略某个目录

    =====================================================
    如果你有个文件，想在多个位置进行替换，这里有很多方法来实现。调用test[someting]把当前目录里所有文件中的Windows替换成Linux，你可以像这样运行它：

    perl -i -pe 's/Windows/Linux/;' 文件
    要替换当前目录以及下层目录里所有文件中的Windows为Linux，你可以这样运行：

    find . -name '*.txt' -print | xargs perl -pi -e's/Windows/Linux/ig' *.txt
    或者如果你更需要让它只作用于普通文件上：

    find -type f -name '*.txt' -print0 | xargs --null perl -pi -e 's/Windows/Linux/'
    节省了大量的时间并且获得了高水平的大师等级！
    ======================================================

    $find   ~   -name   "*.txt"   -print    #在$HOME中查.txt文件并显示
    $find   .    -name   "*.txt"   -print
    $find   .    -name   "[A-Z]*"   -print   #查以大写字母开头的文件
    $find   /etc   -name   "host*"   -print #查以host开头的文件
    $find   .   -name   "[a-z][a-z][0–9][0–9].txt"    -print   #查以两个小写字母和两个数字开头的txt文件
    $find .   -perm   755   -print
    $find   .   -perm -007   -exec ls -l {} \;   #查所有用户都可读写执行的文件同-perm 777
    $find   . -type d   -print
    $find   .   !   -type   d   -print
    $find   .   -type l   -print

    $find   .   -size   +1000000c   -print        #查长度大于1Mb的文件
    $find   .   -size   100c         -print       # 查长度为100c的文件
    $find   .   -size   +10   -print              #查长度超过期作废10块的文件（1块=512字节）

    $cd /
    $find   etc   home   apps    -depth   -print   | cpio   -ivcdC65536   -o   /dev/rmt0
    $find   /etc -name "passwd*"   -exec grep   "cnscn"   {}   \;   #看是否存在cnscn用户
    $find . -name "yao*"   | xargs file
    $find   . -name "yao*"   |   xargs   echo    "" > /tmp/core.log
    $find   . -name "yao*"   | xargs   chmod   o-w

    ======================================================

    find   -name april*                     在当前目录下查找以april开始的文件
    find   -name   april*   fprint file        在当前目录下查找以april开始的文件，并把结果输出到file中
    find   -name ap* -o -name may*   查找以ap或may开头的文件
    find   /mnt   -name tom.txt   -ftype vfat   在/mnt下查找名称为tom.txt且文件系统类型为vfat的文件
    find   /mnt   -name t.txt ! -ftype vfat   在/mnt下查找名称为tom.txt且文件系统类型不为vfat的文件
    find   /tmp   -name wa* -type l            在/tmp下查找名为wa开头且类型为符号链接的文件
    find   /home   -mtime   -2                 在/home下查最近两天内改动过的文件
    find /home    -atime -1                  查1天之内被存取过的文件
    find /home -mmin    +60                  在/home下查60分钟前改动过的文件
    find /home   -amin   +30                  查最近30分钟前被存取过的文件
    find /home   -newer   tmp.txt             在/home下查更新时间比tmp.txt近的文件或目录
    find /home   -anewer   tmp.txt            在/home下查存取时间比tmp.txt近的文件或目录
    find   /home   -used   -2                  列出文件或目录被改动过之后，在2日内被存取过的文件或目录
    find   /home   -user cnscn                列出/home目录内属于用户cnscn的文件或目录
    find   /home   -uid   +501                  列出/home目录内用户的识别码大于501的文件或目录
    find   /home   -group   cnscn              列出/home内组为cnscn的文件或目录
    find   /home   -gid 501                   列出/home内组id为501的文件或目录
    find   /home   -nouser                    列出/home内不属于本地用户的文件或目录
    find   /home   -nogroup                   列出/home内不属于本地组的文件或目录
    find   /home    -name tmp.txt    -maxdepth   4   列出/home内的tmp.txt 查时深度最多为3层
    find   /home   -name tmp.txt   -mindepth   3   从第2层开始查
    find   /home   -empty                     查找大小为0的文件或空目录
    find   /home   -size   +512k                查大于512k的文件
    find   /home   -size   -512k               查小于512k的文件
    find   /home   -links   +2                查硬连接数大于2的文件或目录
    find   /home   -perm   0700                查权限为700的文件或目录
    find   /tmp   -name tmp.txt   -exec cat {} \;
    find   /tmp   -name   tmp.txt   -ok   rm {} \;

    find    /   -amin    -10     # 查找在系统中最后10分钟访问的文件
    find    /   -atime   -2        # 查找在系统中最后48小时访问的文件
    find    /   -empty             # 查找在系统中为空的文件或者文件夹
    find    /   -group   cat        # 查找在系统中属于 groupcat的文件
    find    /   -mmin   -5         # 查找在系统中最后5分钟里修改过的文件
    find    /   -mtime   -1       #查找在系统中最后24小时里修改过的文件
    find    /   -nouser           #查找在系统中属于作废用户的文件
    find    /   -user    fred     #查找在系统中属于FRED这个用户的文件

    查当前目录下的所有普通文件
    # find . -type f -exec ls -l {} \;
    -rw-r–r–    1 root      root         34928 2003-02-25   ./conf/httpd.conf
    -rw-r–r–    1 root      root         12959 2003-02-25   ./conf/magic
    -rw-r–r–    1 root      root          180 2003-02-25   ./conf.d/README
    查当前目录下的所有普通文件，并在- e x e c选项中使用ls -l命令将它们列出
    =================================================
    在/ l o g s目录中查找更改时间在5日以前的文件并删除它们：
    $ find logs -type f -mtime +5 -exec   -ok   rm {} \;

    =================================================
    查询当天修改过的文件
    [root@book class]# find   ./   -mtime   -1   -type f   -exec   ls -l   {} \;

    =================================================
    查询文件并询问是否要显示
    [root@book class]# find   ./   -mtime   -1   -type f   -ok   ls -l   {} \;
    < ls … ./classDB.inc.php > ? y
    -rw-r–r–    1 cnscn    cnscn       13709   1月 12 12:22 ./classDB.inc.php
    [root@book class]# find   ./   -mtime   -1   -type f   -ok   ls -l   {} \;
    < ls … ./classDB.inc.php > ? n
    [root@book class]#

    =================================================
    查询并交给awk去处理
    [root@book class]# who   |   awk   ’{print $1"\t"$2}’
    cnscn    pts/0

    =================================================
    awk—grep—sed

    [root@book class]# df   -k |   awk ‘{print $1}’ |   grep   -v   ’none’ |   sed   s"/\/dev\///g"
    文件系统
    sda2
    sda1
    [root@book class]# df   -k |   awk ‘{print $1}’ |   grep   -v   ’none’
    文件系统
    /dev/sda2
    /dev/sda1

    1)在/tmp中查找所有的*.h，并在这些文件中查找“SYSCALL_VECTOR"，最后打印出所有包含"SYSCALL_VECTOR"的文件名
    A) find   /tmp   -name   "*.h"   | xargs   -n50   grep SYSCALL_VECTOR
    B) grep   SYSCALL_VECTOR   /tmp/*.h | cut    -d’:'   -f1| uniq > filename
    C) find   /tmp   -name "*.h"   -exec grep "SYSCALL_VECTOR"   {}   \; -print

    2)find / -name filename -exec rm -rf {} \;
        find / -name filename -ok rm -rf {} \;

    3)比如要查找磁盘中大于3M的文件：
    find . -size +3000k -exec ls -ld {} ;

    4)将find出来的东西拷到另一个地方
    find *.c -exec cp ‘{}’ /tmp ‘;’

    如果有特殊文件，可以用cpio，也可以用这样的语法：
    find dir -name filename -print | cpio -pdv newdir

    6)查找2004-11-30 16:36:37时更改过的文件
    # A=`find ./ -name "*php"` |   ls -l –full-time $A 2>/dev/null | grep "2004-11-30 16:36:37"

    Linux-all, Linux | No Comments »

    find 实例
    四月 18th, 2006
    　　要在/usr/linux中查找所有的*.h，并在这些文件中查找“SYSCALL_VECTOR"，最后打印出所有包含"SYSCALL_VECTOR"的文件名，有以下几种方法实现
    find /usr/linux -name "*.h" | xargs -n50 grep SYSCALL_VECTOR
    grep SYSCALL_VECTOR /usr/linux/*.h | cut -d’:’ -f1 | uniq > filename
    find /usr/linux -name "*.h" -exec grep "SYSCALL_VECTOR" {} \; -print

    　　我用find / -name filename| rm -rf，不成功，请问为什么不成功？
    find / -name filename -exec rm -rf {} \;
    find . -name filename |rm -rf试一下{} 表示你找出来的结果。
    \; 则相当于“宪法”，没什么说头，就是这么规定的，在 -exec 后面需要一个表示该命令终结的的符号。可以在 man find 中找到答案。
    要让rm识别find的结果，如下：
    find / -name filename |xargs rm -rf
    之所以find . -name filename |rm -rf不通过，是因为rm命令不接受从标准输入传过来的指令
    查找含特定字符串的文件
    例如查找当前目录下含有"the string you want find…"字符串的文件：
    $find . -type f -exec grep “the string you want find…” {} ; -print

    　　从根目录开始查tmpfile，一旦查到马上删除
    find / -name "tmpfile" -exec rm {} \;

    　　find 的perm问题
    请问一下以下命令什么意思？关键是那个数字前的-，其他都还知道
    find -name ".*" -perm -007
    我知道
    find -name ".*" -perm 755
    这个是用来查找权限位为755的隐藏文件
    噢，对了还有，我上边的命令都省略了find的pathname参数 find默认是查找当前工作目录的吗？
    如果我用 -ok 替代 -exec, 那么还需要加上 {} \; 吗？
    这个已经清楚，仍然需要，因为 -ok 只是 -exec 的提示模式，它只是多了一个确认操作的步骤,刚才没有读懂那几句E文的意思 呵呵 不好意思
    -007是指查找所有用户都可读、写、执行的文件，要小心呀~~~
    解释解释？
    find -name ".*" -perm -007 和 find -name ".*" -perm 777 有区别吗？
    -007是怎么来得呢？
    不过有一个问题
    我用 find . -perm -100 会列出当前目录 . , 这是为什么呢？

    下面引用由explover在 2002/10/01 06:15am 发表的内容：
    -007是指查找所有用户都可读、写、执行的文件，要小心呀~~~
    -007是查找含其它用户(不同组,非属主)可读,写,执行的文件.并不一定要同组可读写,-是指最少权限为007.
    下面引用由一颗小白菜在 2002/10/01 10:16am 发表的内容：
    OK了， 呵呵
    不过有一个问题
    我用 find . -perm -100 会列出当前目录 . , 这是为什么呢？
    这种方法不会准确的找出目录的. -100是指权限至少是属主可运行.
    在unix系统下,你可以拥有对目录文件的执行权你才可以进入一个目录.这便是目录文件被列出的原因.
    find . -perm -001 -print找到往往是目录文件.
    我的意思当然不是使用这种方法来找目录，只不过不明白其中的 -100 意义了
    那以此类推，是不是 -010是指权限至少是owner同组可执行的吗？也就是说其实这里的010和-是分开的，-表示一个至少的意思，而且010才是真正用来描述权限位的？
    这样子就明白了 谢谢你噢

    将find出来的东西拷到另一个地方?
    find *.c -exec cp ‘{}’ /tmp ‘;’
    如果有特殊文件，可以用cpio，也可以用这样的语法：
    find dir -name filename -print | cpio -pdv newdir

    　　找出磁盘中某个大小范围内的文件
    比如要查找磁盘中大于3M的文件：
    find . -size +3000k -exec ls -ld {} ;

    　　如何用find查找某一天更改的文件？
    可以使用这一行命令来实现：
    A=`find ~ -print` | ls -l –full-time $A 2>/dev/null | grep "Jun 27" | grep 1998

    　　使用find 命令查找某个时间段的shell怎么写。比如11点到12点的。thanks
    创建一个脚本judgetime，内容如下：
    ls -l $*|awk ‘{split($8,hour,":");if((hour[1]>23 || hour[1] < 1)&&hour[1]<24)print}’
    到要查找的目录下，运行
    find ./ -name "*" -exec judgetime {} \;
    注意时间格式为２４小时制。
    thank you ，如果我要精确到分钟呢
    touch -t 04241112 starttemp #精确到12分钟
    touch -t 04241220 endtemp #截止到12点20
    find [dir] -newer starttemp -a ! -newer endtemp -exec ls -l {} \;
    ｎｅｗｅｒ？
    那昨天１２：１０文件如何呢？
    每天执行的时候，用当天的日期和时间戳替换一下不就行了吗？
    我不知道他是不是把所有的11：00~12：00的都找出来，是不是只执行一次还是每天都执行？
    这种情况俺猜想是自己的东西放在哪忘了，只记得当时是深夜了。
    有道理！
    不愧是斑竹！
    不光知道怎么解决问题，还知道在什么情况下出现这类问题，佩服佩服！
    问题又出现了。创建这个文件的时候。本来应该是时间的一栏现在写上了2002，而不是12：00.
    等到12：00过了吧！

    　　删除指定日期的文件
    find ./ -name 文件名 -exec rm -f {} \;
    例：删除当前30天内没用过的文件,用如下命令：
    find / -atime +30 -exec rm -f {} \;
    我自己试着写了一小段SHELL,也用ll ,grep, rm 几个命令，用起来还差强人意。
    对过滤出来的文件名列表中用了一个FOR语句，再执行rm 。现在我想把这段SHELL 扩展一下让它每天定时运行将 n 天前的文件删掉，有没有人能给我一些提示，谢谢！
    还有个问题，对于前面那位朋友提到的"find / -atime +30 -exec rm -f {} \;
    "方法，我很早就试过几次，不过好像都不太对，参数 -atime n 是查找n天前被访问过的文件，我不明白的是这里的时间参照点是什么，以及这个n天是怎么计算的。
    问 题二、对于"ll |cut -f 1" 这个命令我是不是用错了，我只想取出 ll 中列出的文件名，但用cut -f 命令做不到 ，
    我只好换用 ll |cut -c 59- 这种方式得到我要的文件名，but it’s a pool idear ！我也试过用awk ，
    好像也不对，看看大家可不可以给我一些小小的提醒，TKS SO MUCH
    问题三、如何改变 I结点 的日期格式 我现在的系统显示的格式是：
    -rw-r—– 1 msahz01 users 2253 2002年2月 2日 poheader.i
    我想把这换成
    -rw-rw-rw- 1 house users 2193 Apr 19 2001 hkdisp.p
    如何才能做到这点？
    awk 应该可以
    ll | awk ‘{print $9}’
    删除多少天之前的文件
    find /yourpath -mtime +31 -exec rm {} \;
    find /yourpath -mtime +366 -exec rm {} \;

    find中, -ctime, -mtime及其-atime有何区别

    请问 -ctime 和 -mtime 有什么关系 ?
    如果父目录的 ctime 改变, 那它下面的文件的 ctime 就会自动都改了吗 ?
    -ctime 和 -mtime ,-atime 这些信息是存在哪儿呢 ?

    我用 -mtime -1 找到了新建或改的文件.
    但怎样才能找到一天内 mv 来的文件呢( 它们的时间是原有的时间,早于一天 ) ?

    用-newer选项啊。
    你可以先touch一个你想要的时间的文件如下：
    $ touch -t 08190800 test
    $ ls -l test
    -rw-r–r– 1 dba other 0 Aug 19 08:00 test
    然后
    $ find . -newer test -print
    .
    ./.sh_history
    $ ls -l .sh_history
    -rw——- 1 dba other 154 Aug 20 17:39 .sh_history

    用touch可以写出你想要的任何时间的文件，然后用-newer ,! -newer选项即可成功。

    1.ctime含inode信息修改的时间.mtime只指文件内容建立或修改的时间.
    2 不会.
    3.这些信息应该是存在文件系统的超级块里.

    我查了书 -ctime 是指 inode 的改变(或称文件的状态改变).
    请问 inode 存了哪些信息 ?
    做了些小测试,-mtime 改, -ctime 一定也改.
    改文件名, -ctime 也会改.
    谁能回答 i-node 存了哪些东西 ?

    vi /usr/include/sys/inode.h

    班主,我不能 access /usr/include/sys/inode.h .
    可我发现 -atime 改了, -ctime 还没改. why ?
    ( 我先 cat 一个 ASCII 文件,再用 -atime -1 有它用 -ctime -1 居然没有它.)
    着岂不跟 inode 信息改变, ctime 就改矛盾吗?

    我不同意你贴出来的那段文章,正如我提到的那样,atime,ctime,mtime是放到超级块里,在sco unix下是一种叫stat的结构.(stat_32),不同的系统文件系统可能不同.
    sco 下inode的结构如下:

*/
}

void command::fmt()
{
    /**
    文档编辑-fmt
    fgrep 返回 fold
    OPENDIR
    　　功能说明：编排文本文件。
    　　语　　法：fmt [-cstu][-p<列起始字符串>][-w<每列字符数>][--help][--version][文件...]
    　　补充说明：fmt指令会从指定的文件里读取内容，将其依照指定格式重新编排后，输出到标准输出设备。若指定的文件名为"-"，则fmt指令会从标准输入设备读取数据。
    　　参　　数：
    　　-c或--crown-margin 每段前两列缩排。
    　　-p<列起始字符串>或-prefix=<列起始字符串> 仅合并含有指定字符串的列，通常运用在程序语言的注解方面。
    　　-s或--split-only 只拆开字数超出每列字符数的列，但不合并字数不足每列字符数的列。
    　　-t或--tagged-paragraph 每列前两列缩排，但第1列和第2列的缩排格式不同。
    　　-u或--uniform-spacing 每个字符之间都以一个空格字符间隔，每个句子之间则两个空格字符分隔。
    　　-w<每列字符数>或--width=<每列字符数>或-<每列字符数> 设置每列的最大字符数。
    　　--help 在线帮助。
    　　--version 显示版本信息。
     */
}

void command::fold()
{
    /**
    文档编辑-fold
    功能说明：限制文件列宽。
        语　　法：fold [-bs][-w<每列行数>][--help][--version][文件...]
        补充说明：fold指令会从指定的文件里读取内容，将超过限定列宽的列加入增列字符后，输出到标准输出设备。
        若不指定任何文件名称，或是所给予的文件名为“-”，则fold指令会从标准输入设备读取数据。
        参　　数：
        -b或--bytes 以Byte为单位计算列宽，而非采用行数编号为单位。
        -s或--spaces 以空格字符作为换列点。
        -w<每列行数>或--width<每列行数> 设置每列的最大行数。
        --help 在线帮助。
        --version 显示版本信息。
     */
}

void command::ftp()
{
    /**
     @ 在ftp下也可以操作文件夹的文件。
       要操作硬盘中的文件，命令前要加!.例如，要生成目录tmp，要这么写命令： !mkdir tmp
       要进入硬盘中的文件目录，要用lcd.例如，lcd tmp
     */
}

void command::ftp_example()
{
    /**
    ftp链接步骤：
    1、关闭防火墙
    2、打开vsftpd服务

    如果连上，但是输入用户名的时候登录不上
    先用命令查看状态：
          getsebool -a |grep ftp

        allow_ftpd_anon_write --> off
        allow_ftpd_full_access --> on    //这个为off，说明不能链接上
        allow_ftpd_use_cifs --> on
        allow_ftpd_use_nfs --> on
        ftp_home_dir --> on
        ftpd_connect_db --> off
        httpd_enable_ftp_server --> on
        sftpd_anon_write --> off
        sftpd_enable_homedirs --> off
        sftpd_full_access --> off
        sftpd_write_ssh_home --> off
        tftp_anon_write --> on

    修改状态：

        [root@ www.linuxidc.com vsftpd]# setsebool allow_ftpd_full_access 1
        [root@ www.linuxidc.com vsftpd]# setsebool allow_ftpd_use_cifs 1
        [root@ www.linuxidc.com vsftpd]# setsebool allow_ftpd_use_nfs 1
        [root@ www.linuxidc.com vsftpd]# setsebool -P ftp_home_dir 1
        [root@ www.linuxidc.com vsftpd]# setsebool httpd_enable_ftp_server 1
        [root@ www.linuxidc.com vsftpd]# setsebool tftp_anon_write 1
        [root@ www.linuxidc.com vsftpd]# service vsftpd restart
      */
}

void command::getfacl()
{
    /**
     在linux系统中,一个文件的权限设置是针对 User, Group, Other, 应用场景:
     有一个文件 acl_test1, 它的 User是 root , Group是root, 如果现在需要对系统中的某个用户开放rwx 权限,
     例如: 用户 one 需要对这个文件有rwx权限. 如果只是单纯的把文件的权限设置为 777, 那么,其他用户(two) 对这个文件
     也有rwx的权限.
     此时可以用setfacl命令.
     用这个命令之前,要确定该目录支持 ACL.

     根目录支持ACL
     mount -o remount,acl /

     查看
     mount

    getfacl filename
     */
}

void command::git()
{
    /**
    文件管理-git
    find 返回 gitview
    OPENDIR
        功能说明：文字模式下的文件管理员。
        语　　法：git
        补充说明：git是用来管理文件的程序，它十分类似DOS下的Norton Commander，具有互动式操作界面。
        它的操作方法和Norton Commander几乎一样，略诉如下：
        F1 ：执行info指令，查询指令相关信息，会要求您输入欲查询的名称。
        F2 ：执行cat指令，列出文件内容。
        F3 ：执行gitview指令，观看文件内容。
        F4 ：执行vi指令，编辑文件内容。
        F5 ：执行cp指令，复制文件或目录，会要求您输入目标文件或目录。
        F6 ：执行mv指令，移动文件或目录，或是更改其名称，会要求您输入目标文件或目录。
        F7 ：执行mkdir指令，建立目录。
        F8 ：执行rm指令，删除文件或目录。
        F9 ：执行make指令，批处理执行指令或编译程序时，会要求您输入相关命令。
        F10 ：离开git文件管理员。
     */
}

void command::git_example()
{
    /**
    @ 设置 git 的输出颜色

        alec@PC$ git config --global color.status auto
        alec@PC$ git config --global color.diff auto
        alec@PC$ git config --global color.branch auto
        alec@PC$ git config --global color.interactive auto

    @ git 配置文件   ～/.gitconfig


    配置本地仓库：
    ～/repo/test
    @ git init --bare  （在仓库中不能操作）

    @ git clone ~/repo/test  (拉下仓库内容,这是在当前用户下拉分支）

    @ git clone ssh://coderepo@192.8.51.1/~/repo/test
        由于该仓库中什么都没有，刚拉下的仓库用 git branch -a 看没有任何东西
        创建文件 test ， git add   test  ，此时，用git branch -a 看，发现有master分支。
        git commit；
        git push origin master:main_dev (把当前的文件提交到远程仓库中，同时在远程仓库创建main_dev 分支。

        git push origin main_dev:main_dev





      */
}

void command::gitview()
{
    /**
    文件管理-gitview
    git 返回 indent
    OPENDIR
        功能说明：Hex/ASCII的看文件程序。
        语　　法：gitview [-bchilv][文件]
        补充说明：gitview指令可用于观看文件的内容，它会同时显示十六进制和ASCII格式的字码。
        参　　数：
        -b 　单色模式，不使用ANSI控制码显示彩色。
        -c 　彩色模式，使用ANSI控制码显示色彩。
        -h 　在线帮助。
        -i 　显示存放gitview程序的所在位置。
        -l 　不使用先前的显示字符。
        -v 　显示版本信息。
     */
}

void command::grep()
{
    /**
    文档编辑-grep
    fold 返回 ispell
    OPENDIR
    　　功能说明：查找文件里符合条件的字符串。
        语　　法：grep [-abcEFGhHilLnqrsvVwxy][-A<显示列数>][-B<显示列数>][-C<显示列数>][-d<进行动作>]
        [-e<范本样式>][-f<范本文件>][--help][范本样式][文件或目录...]
        补充说明：grep指令用于查找内容包含指定的范本样式的文件，如果发现某文件的内容符合所指定的范本样式，
        预设grep指令会把含有范本样式的那一列显示出来。若不指定任何文件名称，或是所给予的文件名为“-”，则grep指令会从标准输入设备读取数据。
        参　　数：
        -a或--text 不要忽略二进制的数据。
        -A<显示列数>或--after-context=<显示列数> 除了显示符合范本样式的那一列之外，并显示该列之后的内容。
        -b或--byte-offset 在显示符合范本样式的那一列之前，标示出该列第一个字符的位编号。
        -B<显示列数>或--before-context=<显示列数> 除了显示符合范本样式的那一列之外，并显示该列之前的内容。
        -c或--count 计算符合范本样式的列数。
        -C<显示列数>或--context=<显示列数>或-<显示列数> 除了显示符合范本样式的那一列之外，并显示该列之前后的内容。
        -d<进行动作>或--directories=<进行动作> 当指定要查找的是目录而非文件时，必须使用这项参数，否则grep指令将回报信息并停止动作。
        -e<范本样式>或--regexp=<范本样式> 指定字符串做为查找文件内容的范本样式。
        -E或--extended-regexp 将范本样式为延伸的普通表示法来使用。
        -f<范本文件>或--file=<范本文件> 指定范本文件，其内容含有一个或多个范本样式，让grep查找符合范本条件的文件内容，格式为每列一个范本样式。
        -F或--fixed-regexp 将范本样式视为固定字符串的列表。
        -G或--basic-regexp 将范本样式视为普通的表示法来使用。
        -h或--no-filename 在显示符合范本样式的那一列之前，不标示该列所属的文件名称。
        -H或--with-filename 在显示符合范本样式的那一列之前，表示该列所属的文件名称。
        -i或--ignore-case 忽略字符大小写的差别。
        -l或--file-with-matches 列出文件内容符合指定的范本样式的文件名称。
        -L或--files-without-match 列出文件内容不符合指定的范本样式的文件名称。
        -n或--line-number 在显示符合范本样式的那一列之前，标示出该列的列数编号。
        -q或--quiet或--silent 不显示任何信息。
        -r或--recursive 此参数的效果和指定“-d recurse”参数相同。
        -s或--no-messages 不显示错误信息。
        -v或--revert-match 反转查找。
        -V或--version 显示版本信息。
        -w或--word-regexp 只显示全字符合的列。
        -x或--line-regexp 只显示全列符合的列。
        -y 此参数的效果和指定“-i”参数相同。
        --help 在线帮助。
     */
}

void command::grep_example()
{
    /**
    查找 /etc/passwd 这个文件中有 dmtsai的信息
    [root@www ~]# grep 'dmtsai' /etc/passwd

    捕捉有关键字 'eth'的行的后三行和前两行，并且以颜色显示
    $   dmesg |grep -n -A3 -B2 --color=auto 'eth'

    显示文档里面有 ‘the‘的行
    $   grep -n 'the' regular_express.txt

    显示文档里面没有 ‘the‘ 的行
    $   grep -vn 'the' regular_express.txt

    如果想搜索 test 或 taste 这个两个单词
    $   grep -n 't[ae]st' regular_express.txt

    有oo的行
    $   grep -n 'oo' regular_express.txt

    有oo，但是不想oo前面有g的行
    $   grep -n '[^g]oo' regular_express.txt

    oo前面有小写字母
    $   grep -n '[^a-z]oo' regular_express.txt
    $   grep -n '[^[:lower:]]oo' regular_express.txt

    有数字的列
    $   grep -n '[0-9]' regular_express.txt

    有‘the‘的行，同时’the‘在行首
    $   grep -n '^the' regular_express.txt

    开头是小写字符的一行
    $   grep -n '^[a-z]' regular_express.txt
    $   grep -n '^[[:lower:]]' regular_express.txt

    开头不是英文字母, [^a-zA-Z] ^在[]内表示反向选择 ，在[]外表示定位在行首的意思
    $   grep -n '^[^a-zA-Z]' regular_express.txt

    行尾结束为小数点(.)的那一行  '^$'表示不要空白 '^#'不要#开头的行， 在linux中点(.)有特殊意义，所以要表示点(.),
    则用 \.
    $   grep -n '\.$' regular_express.txt

    第一个 [-v '^$'] 表示 不要空白行， 第二个[-v '^#'] 表示不要开头为# 的行
    $   grep -v '^$' /etc/syslog.conf |grep -v '^#'


    find / -name "*" |xargs grep -n --color=auto "BEGIN:VCARD" 2>/dev/null (过滤掉错误)

    查找当前路径下所有的文件里有syberos的字符串, * /*  这是没有空格的.
    $  grep syberos  * /*
    $ grep syberos -rsni

    //  grep -v voicecall-manager 取反,滤掉 voicecall-manager的信息
    //  log 存放路径   /altdata/var/log/joural

    journalctl -a 是所有的log , f 是当前输出的
    $ journalctl -a |grep voicecall |grep -v voicecall-manager

     */
}

void command::groupadd()
{
    /**
    groupadd命令：增加一个新组

    为了方便管理，可以对一群有相近需求的用户新增一个组，groupadd命令可以实现这个功能。

    Usage: groupadd [options] GROUP

    Options:
      -f, --force             强制建立已经存在的组（如果存在则返回成功）
      -g, --gid GID           设置新建立组的识别码，0--499保留给系统服务,可以指定500以上的唯一数值（除非用--non-unique参数）。
      -o, --non-unique        允许重复使用组识别码。
      -p, --password PASSWORD 设置新组的密码
      -r, --system            创建一个系统账号
     */
}

void command::groupadd_example()
{
    /**
    1、新建立一个名为test的组
    linux@cdyemail:~$ sudo groupadd test
    linux@cdyemail:~$ cat /etc/group | grep test
    test:x:1002:

    注：/etc/group的格式
    group name : password : GID : user lists

    如：
    linux@cdyemail:~$ cat /etc/group | grep admin
    admin:x:119:linux
    admin: 用户名
    x: 密码段
    119: 组ID
    linux: 组内用户列表

    2、创建一个student组，并设置GID为2000
    linux@cdyemail:~$ sudo groupadd --gid 2000 student
    linux@cdyemail:~$ cat /etc/group | grep student
    student:x:2000:

    3、强制建立一个student组
    由于student组已经存在，所以再次创建会出错
    linux@cdyemail:~$ sudo groupadd student
    groupadd: group 'student' already exists #提示student组已经存在。

    linux@cdyemail:~$ sudo groupadd --force student #强制建立组
    linux@cdyemail:~$ cat /etc/group | grep student
    student:x:2000:

    4、两个组用同一个GID
    环境：student组的ID是 2000
    linux@cdyemail:~$ sudo groupadd --non-unique  --gid 2000 boy
    linux@cdyemail:~$ cat /etc/group | grep 2000
    student:x:2000:
    boy:x:2000:
     */
}

void command::groupdel()
{
    /**
     *
     */
}

void command::gzip()
{
    /**
    gzip [选项] 压缩（解压缩）的文件名
    各选项的含义：
    -c 将输出写到标准输出上，并保留原有文件。
    -d 将压缩文件解压。
    -l 对每个压缩文件，显示下列字段：
       压缩文件的大小
       未压缩文件的大小
       压缩比
       未压缩文件的名字
    -r 递归式地查找指定目录并压缩其中的所有文件或者是解压缩。
    -t 测试，检查压缩文件是否完整。
    -v 对每一个压缩和解压的文件，显示文件名和压缩比。
    -num 用指定的数字num调整压缩的速度，-1或--fast表示最快压缩方法（低压缩比），-9或--best表示最慢压缩方法（高压缩比）。系统缺省值为6。

  */
}

void command::gzip_example()
{
    /**
    假设一个目录/home下有文件mm.txt、sort.txt、xx.com。
    例1：把/home目录下的每个文件压缩成.gz文件。
    $ cd /home
    $ gzip *
    $ ls
    m.txt.gz sort.txt.gz xx.com.gz

    例2：把例1中每个压缩的文件解压，并列出详细的信息。
    $ gzip -dv *
    mm.txt.gz 43.1%-----replaced with mm.txt
    sort.txt.gz 43.1%-----replaced with sort.txt
    xx.com.gz 43.1%-----replaced with xx.com

    $ ls
    mm.txt sort.txt xx.com

    $ gzip -l *
    compressed uncompr. ratio uncompressed_name
    277 445 43.1% mm.txt
    278 445 43.1% sort.txt
    277 445 43.1% xx.com

    $ ls
    mm.txt.gz sort.txt.gz xx.com.gz

    例4：压缩一个tar备份文件，如usr.tar，此时压缩文件的扩展名为.tar.gz
    $ gzip usr.tar
    $ ls
    usr.tar.gz

     */
}

void command::gdb()
{
    /**
     分屏显示
     $ gdb -tui  cmos-voicecall

        gdb test   连接上执行程序
        用 break 设置断点
        break 7  (断点在 main.cpp里面的第7行)
        r  (运行, 跑到第7行会停下来)
        n  (运行到8行)
        break +7 (当前断点在7行, 此时在加 7 ,就到了14行)
        c  (继续执行, 如果没有上面的 n, 也就是运行到 8行,那么程序不会在14行停)
        break  Two::test (在Two::test 上设置断点)
        step   进入函数体内执行, 用finish 跳出
        break  one.cpp:14 (在 one.cpp 文件的 14行设置断点)
        break  one::(此时可以按tab 键,就可以查看重载函数,设置断点)
        break filename:function
        finish (当进入一个函数后, 运行函数的语句, 用finish退出该函数到上一层去)

        p (打印值, 目前只能打印基本类型数据, QString 目前还打印不了)

        p &a (打印a的地址)

     **/
}

void command::gdb_example()
{
    /**

      用 gdb 调试程序, 先要把cmos-voicecall.spec 的开始两行代码
        %define debug_packages %{nil}
        %define debug_package %{nil}
      注释掉, 编译具有调试信息的程序, 这里面编译生成了三个包
      cmos-voicecall-0.8.0-0.armv7tnhl.rpm
      cmos-voicecall-debugsource-0.8.0-0.armv7tnhl.rpm
      cmos-voicecall-debuginfo-0.8.0-0.armv7tnhl.rpm

      把这三个包都安装到手机上,然后运行 cmos-voicecall,
      用命令   gdb -p pid(cmos-voicecall 的进程号)

      @断点


        gdb调试正在运行的进程：

        GDB可以对正在执行的程序进行调度，它允许开发人员中断程序 并查看其状态，之后还能让这个程序正常地继续执行

        (gdb) attach xxxxx --- xxxxx为利用ps命令获得的子进程process id
        (gdb) stop --- 这点很重要，你需要先暂停那个子进程，然后设置一些断点和一些Watch
        (gdb) break 37 -- 在result = wib(value, div);这行设置一个断点,可以使用list命令察看源代码
        Breakpoint 1 at 0x10808: file eg1.c, line 37.
        (gdb) continue
        Continuing.

        Breakpoint 1, main () at eg1.c:37
        37                              result = wib(value, div);
        (gdb) step

        在完成调试之后，不要忘记用detach命令断开连接，让被调试的进程可以继续正常运行。

        我们可以通过  1)  gdb prog_name -> r               用在逐步调试自己的程序时
                        2)  gdb -> attach process_id       正在运行中的后台程序突然卡在了某个地方，先ps再gdb/attach
                        3)  gdb prog_name core              程序core掉了

        三种方式对一个程序进行调试；

        1. thread——gdb 多线程调试命令:
         info threads:           显示当前进程中的线程；
         thread thread_no:  进入线程xx，通常紧接而来的是 bt/f 命令；

        2. strace/ltrace:
         前者关注系统调用和程序所接收的信号；后者关注库函数调用；
         strace的应用在 我们没有程序的源码，或者不方便从头开始运行程序时；可以方便查看一个应用程序进行了哪些系统调用。
         而在希望知道程序都调用了动态库中的哪些函数时，我们使用 ltrace。ltrace有个-S选项，类似于strace功能。

        3.检查内存泄漏的工具：

        valgrind (in linux, free)
        visual leak detector (windows , free)
        boundschecker(windows, free)

        profile工具：
        oprofile
        vtune
         **/
}

void command::iconv()
{
    /**
    用法： iconv [选项...] [文件...]
    有如下选项可用:

    输入/输出格式规范：
        -f, --from-code=名称 原始文本编码
        -t, --to-code=名称 输出编码
        信息：
        -l, --list 列举所有已知的字符集
        输出控制：
        -c 从输出中忽略无效的字符
        -o, --output=FILE 输出文件
        -s, --silent 关闭警告
        --verbose 打印进度信息
        -?, --help 给出该系统求助列表
        --usage 给出简要的用法信息
        -V, --version 打印程序版本号
        例子:
        iconv -c -f gb2312 -t utf-8 aaa.txt >bbb.txt
        这个命令读取aaa.txt文件，从编码gb2312转换为utf-8编码,忽略无效的字符，其输出定向到bbb.txt文件。
        utf-8 和 gb2312 在 windows 上看是一样的,但在linux下是有区别的。在winndows上粘贴、复制utf-8编码的字都会改变其编码，变为gb2312。
     */
}

void command::iconv_example()
{
    /**
    @ 关于如何修改文件的编码：
      查看文件当前的编码的命令: file `ls`(这个 ` 是按键1旁边的按键）
      如果想把utf8 的编码改为gb18030的编码
      iconv -f utf8 -t gb18030 要修改的文件（比如：dataManager.h) >ddd.h
      mv ddd.h  dataManager.h
     */
}

void command::in()
{
    /**
文件管理-in
cp 返回 mcopy
OPENDIR
　　功能说明：连接文件或目录。
　　语　　法：ln [-bdfinsv][-S <字尾备份字符串>][-V <备份方式>][--help][--version][源文件或目录][目标文件或目录] 或 ln [-bdfinsv]
[-S <字尾备份字符串>][-V <备份方式>][--help][--version][源文件或目录...][目的目录]
　　补充说明：ln指令用在连接文件或目录，如同时指定两个以上的文件或目录，且最后的目的地是一个已经存在的目录，
则会把前面指定的所有文件或目录复制到该目录中。若同时指定多个文件或目录，且最后的目的地并非是一个已存在的目录，则会出现错误信息。
　　参　　数：
　　-b或--backup 　删除，覆盖目标文件之前的备份。
　　-d或-F或--directory 　建立目录的硬连接。
　　-f或--force 　强行建立文件或目录的连接，不论文件或目录是否存在。
　　-i或--interactive 　覆盖既有文件之前先询问用户。
　　-n或--no-dereference 　把符号连接的目的目录视为一般文件。
　　-s或--symbolic 　对源文件建立符号连接，而非硬连接。
　　-S<字尾备份字符串>或--suffix=<字尾备份字符串> 　用"-b"参数备份目标文件后，备份文件的字尾会被加上一个备份字符串，
预设的字尾备份字符串是符号"~"，您可通过"-S"参数来改变它。
　　-v或--verbose 　显示指令执行过程。
　　-V<备份方式>或--version-control=<备份方式> 　用"-b"参数备份目标文件后，备份文件的字尾会被加上一个备份字符串，
这个字符串不仅可用"-S"参数变更，当使用"-V"参数<备份方式>指定不同备份方式时，也会产生不同字尾的备份字符串。
　　--help 　在线帮助。
　　--version 　显示版本信息。
     */
}

void command::insmod()
{
    /**
    @brief

    insmod(install module)

    功能说明：载入模块 install loadable kernel module

    语法：insmod [-fkmpsvxX][-o <模块名称>][模块文件][符号名称 = 符号值]

    参数：

    -f 　不检查目前kernel版本与模块编译时的kernel版本是否一致，强制将模块载入。
    -k 　将模块设置为自动卸除。
    -m 　输出模块的载入信息。
    -o   <模块名称> 　指定模块的名称，可使用模块文件的文件名。
    -p 　测试模块是否能正确地载入kernel。
    -s 　将所有信息记录在系统记录文件中。
    -v 　执行时显示详细的信息。
    -x 　不要汇出模块的外部符号。
    -X 　汇出模块所有的外部符号，此为预设置。

    使用说明：Linux有许多功能是通过模块的方式，在需要时才载入kernel。
    如此可使kernel较为精简，进而提高效率，以及保有较大的弹性。这类可载入的模块，通常是设备驱动程序。

    insmod命令主要用于在Linux 2.4内核之前加载Linux内核模块命令。
    对于通过此命令加载的Linux内核模块，系统不仅不会自动解决内核模块之间的依赖关系，
    而且还要求将模块路径写详细。所以在Linux 2.6内核出现时，此命令已渐渐被遗忘。


    加载RAID1阵列级别模块，如下所示：

example:
    [root@rhel5 boot]# insmod /lib/modules/2.6.

    18-8.el5/kernel/drivers/md/raid1.ko

    [root@rhel5 boot]# lsmod |grep raid1

    raid1                  25153  0
    范例一：请尝试载入 cifs.ko 这个『文件系统』模块
    [root@www ~]# insmod /lib/modules/$(uname -r)/kernel/fs/cifs/cifs.ko
    [root@www ~]# lsmod | grep cifs
    cifs 212789 0

    从以上显示结果可知，RAID1模块已加载成功。只是在使用insmod命令加载模块时，需要使用绝对路径方能加载，且加载时无法自动解决依赖关系。
     */
}

void command::indent()
{
    /**
    文件管理-indent
    gitview 返回 cut
    OPENDIR
        功能说明：调整C原始代码文件的格式。
        语　　法：indent [参数][源文件] 或 indent [参数][源文件][-o 目标文件]
        补充说明：indent可辨识C的原始代码文件，并加以格式化，以方便程序设计师阅读。
        参　　数：
        -bad或--blank-lines-after-declarations 　在声明区段或加上空白行。
        -bap或--blank-lines-after-procedures 　在程序或加上空白行。
        -bbb或--blank-lines-after-block-comments 　在注释区段后加上空白行。
        -bc或--blank-lines-after-commas 　在声明区段中，若出现逗号即换行。
        -bl或--braces-after-if-line 　if(或是else,for等等)与后面执行区段的"{"不同行，且"}"自成一行。
        -bli<缩排格数>或--brace-indent<缩排格数> 　设置{ }缩排的格数。
        -br或--braces-on-if-line 　if(或是else,for等等)与后面执行跛段的"{"不同行，且"}"自成一行。
        -bs或--blank-before-sizeof 　在sizeof之后空一格。
        -c<栏数>或--comment-indentation<栏数> 　将注释置于程序码右侧指定的栏位。
        -cd<栏数>或--declaration-comment-column<栏数> 　将注释置于声明右侧指定的栏位。
        -cdb或--comment-delimiters-on-blank-lines 　注释符号自成一行。
        -ce或--cuddle-else 　将else置于"}"(if执行区段的结尾)之后。
        -ci<缩排格数>或--continuation-indentation<缩排格数> 　叙述过长而换行时，指定换行后缩排的格数。
        -cli<缩排格数>或--case-indentation-<缩排格数> 　使用case时，switch缩排的格数。
        -cp<栏数>或-else-endif-column<栏数> 　将注释置于else与elseif叙述右侧定的栏位。
        -cs或--space-after-cast 　在cast之后空一格。
        -d<缩排格数>或-line-comments-indentation<缩排格数> 　针对不是放在程序码右侧的注释，设置其缩排格数。
        -di<栏数>或--declaration-indentation<栏数> 　将声明区段的变量置于指定的栏位。
        -fc1或--format-first-column-comments 　针对放在每行最前端的注释，设置其格式。
        -fca或--format-all-comments 　设置所有注释的格式。
        -gnu或--gnu-style 　指定使用GNU的格式，此为预设值。
        -i<格数>或--indent-level<格数> 　设置缩排的格数。
        -ip<格数>或--parameter-indentation<格数> 　设置参数的缩排格数。
        -kr或--k-and-r-style 　指定使用Kernighan&Ritchie的格式。
        -lp或--continue-at-parentheses 　叙述过长而换行，且叙述中包含了括弧时，将括弧中的每行起始栏位内容垂直对其排列。
        -nbad或--no-blank-lines-after-declarations 　在声明区段后不要加上空白行。
        -nbap或--no-blank-lines-after-procedures 　在程序后不要加上空白行。
        -nbbb或--no-blank-lines-after-block-comments 　在注释区段后不要加上空白行。
        -nbc或--no-blank-lines-after-commas 　在声明区段中，即使出现逗号，仍旧不要换行。
        -ncdb或--no-comment-delimiters-on-blank-lines 　注释符号不要自成一行。
        -nce或--dont-cuddle-else 　不要将else置于"}"之后。
        -ncs或--no-space-after-casts 　不要在cast之后空一格。
        -nfc1或--dont-format-first-column-comments 　不要格式化放在每行最前端的注释。
        -nfca或--dont-format-comments 　不要格式化任何的注释。
        -nip或--no-parameter-indentation 　参数不要缩排。
        -nlp或--dont-line-up-parentheses 　叙述过长而换行，且叙述中包含了括弧时，不用将括弧中的每行起始栏位垂直对其排列。
        -npcs或--no-space-after-function-call-names 　在调用的函数名称之后，不要加上空格。
        -npro或--ignore-profile 　不要读取indent的配置文件.indent.pro。
        -npsl或--dont-break-procedure-type 　程序类型与程序名称放在同一行。
        -nsc或--dont-star-comments 　注解左侧不要加上星号(*)。
        -nsob或--leave-optional-semicolon 　不用处理多余的空白行。
        -nss或--dont-space-special-semicolon 　若for或while区段仅有一行时，在分号前不加上空格。
        -nv或--no-verbosity 　不显示详细的信息。
        -orig或--original 　使用Berkeley的格式。
        -pcs或--space-after-procedure-calls 　在调用的函数名称与"{"之间加上空格。
        -psl或--procnames-start-lines 　程序类型置于程序名称的前一行。
        -sc或--start-left-side-of-comments 　在每行注释左侧加上星号(*)。
        -sob或--swallow-optional-blank-lines 　删除多余的空白行。
        -ss或--space-special-semicolon 　若for或swile区段今有一行时，在分号前加上空格。
        -st或--standard-output 　将结果显示在标准输出设备。
        -T 　数据类型名称缩排。
        -ts<格数>或--tab-size<格数> 　设置tab的长度。
        -v或--verbose 　执行时显示详细的信息。
        -version 　显示版本信息。
     */
}

void command::ispell()
{
    /**
    文档编辑-ispell
    grep 返回 jed
    OPENDIR
        功能说明：拼字检查程序。
        语　　法：ispell [-aAbBClmMnNPStVx][-d<字典文件>][-L<行数>][-p<字典文件>][-w<非字母字符>][-W<字符串长度>][要检查的文件]
        补充说明：ispell预设会使用/usr/lib/ispell/english.hash字典文件来检查文本文件。若在检查的文件中找到字典没有的词汇，ispell会建议使用的词汇，或是让你将新的词汇加入个人字典。
        参　　数：
        -a 当其他程序输出送到ispell时，必须使用此参数。
        -A 读取到"&Include File&"字符串时，就去检查字符串后所指定文件的内容。
        -b 产生备份文件，文件名为.bak。
        -B 检查连字错误。
        -C 不检查连字错误。
        -d<字典文件> 指定字典文件。
        -l 从标准输入设备读取字符串，结束后显示拼错的词汇。
        -L<行数> 指定内文显示的行数。
        -m 自动考虑字尾的变化。
        -M 进入ispell后，在画面下方显示指令的按键。
        -n 检查的文件为noff或troff的格式。
        -N 进入ispell后，在画面下方不显示指令的按键。
        -p<字典文件> 指定个人字典文件。
        -P 不考虑字尾变化的情形。
        -S 不排序建议取代的词汇。
        -t 检查的文件为TeX或LaTeX的格式。
        -V 非ANSI标准的字符会以"M-^"的方式来显示。
        -w<非字母字符> 检查时，特别挑出含有指定的字符。
        -W<字符串长度> 不检查指定长度的词汇。
        -x 不要产生备份文件。
     */
}

void command::jed()
{
    /**
    文档编辑-jed
    ispell 返回 joe
    OPENDIR
    　　功能说明：编辑文本文件。
    　　语　　法：jed [-2n][-batch][-f<函数>][-g<行数>][-i<文件>][-I<文件>][-s<字符串>][文件]
    　　补充说明：Jed是以Slang所写成的程序，适合用来编辑程序原始代码。
    　　参　　数：
    　　-2 显示上下两个编辑区。
    　　-batch 以批处理模式来执行。
    　　-f<函数> 执行Slang函数。
    　　-g<行数> 移到缓冲区中指定的行数。
    　　-i<文件> 将指定的文件载入缓冲区。
    　　-i<文件> 载入Slang原始代码文件。
    　　-n 不要载入jed.rc配置文件。
    　　-s<字符串> 查找并移到指定的字符串。
     */
}

void command::joe()
{
    /**
    文档编辑-joe
    jed 返回 join
    OPENDIR
        功能说明：编辑文本文件。
        语　　法：joe [-asis][-beep][-csmode][-dopadding][-exask][-force][-help][-keepup]
        [-lightoff][-arking][-mid][-nobackups][-nonotice][-nosta][-noxon][-orphan][-backpath<目录>]
        [-columns<栏位>][-lines<行数>][-pg<行数>][-skiptop<行数>][-autoindent crlf linums overwrite rdonly wordwrap]
        [+<行数>][-indentc<缩排字符>][-istep<缩排字符数>][-keymap<按键配置文件>][-lmargin<栏数>]
        [-rmargin<栏数>][-tab<栏数>][要编辑的文件]
        补充说明：Joe是一个功能强大的全屏幕文本编辑程序。操作的复杂度要比Pico高一点，但是功能较为齐全。
        Joe一次可开启多个文件，每个文件各放在一个编辑区内，并可在文件之间执行剪贴的动作。
        参　　数：
        以下为程序参数
        -asis 字符码超过127的字符不做任何处理。
        -backpath<目录> 指定备份文件的目录。
        -beep 编辑时，若有错误即发出哗声。
        -columns<栏位> 设置栏数。
        -csmode 可执行连续查找模式。
        -dopadding 是程序跟tty间存在缓冲区。
        -exask 在程序中，执行"Ctrl+k+x"时，会先确认是否要保存文件。
        -force 强制在最后一行的结尾处加上换行符号。
        -help 执行程序时一并显示帮助。
        -keepup 在进入程序后，画面上方为状态列。
        -lightoff 选取的区块在执行完区块命令后，就会回复成原来的状态。
        -lines<行数> 设置行数。
        -marking 在选取区块时，反白区块会随着光标移动。
        -mid 当光标移出画面时，即自动卷页，使光标回到中央。
        -nobackups 不建立备份文件。
        -nonotice 程序执行时，不显示版权信息。
        -nosta 程序执行时，不显示状态列。
        -noxon 尝试取消“Ctrl+s”与“Ctrl+q”键的功能。
        -orphan 若同时开启一个以上的文件，则其他文件会置于独立的缓冲区，而不会另外开启编辑区。
        -pg<行数> 按“PageUp”或“PageDown”换页时，所要保留前一页的行数。
        -skiptop<行数> 不使用屏幕上方指定的行数。
        以下为文件参数
        +<行数> 指定开启文件时，光标所在的行数。
        -autoindent 自动缩排。
        -crlf 在换行时，使用CR-LF字符。
        -indentc<缩排字符> 执行缩排时，实际插入的字符。
        -istep<缩排字符数> 每次执行缩排时，所移动的缩排字符数。
        -keymap<按键配置文件> 使用不同的按键配置文件。
        -linums 在每行前面加上行号。
        -lmargin<栏数> 设置左侧边界。
        -overwrite 设置覆盖模式。
        -rmargin<栏数> 设置右侧边界。
        -tab<栏数> 设置tab的宽度。
        -rdonly 以只读的方式开启文件-wordwrap编辑时若超过右侧边界，则自动换行。
     */
}

void command::join()
{
    /**
    文档编辑-join
    joe 返回 look
    OPENDIR
        功能说明：将两个文件中，指定栏位内容相同的行连接起来。
        语　　法：join [-i][-a<1或2>][-e<字符串>][-o<格式>][-t<字符>][-v<1或2>][-1<栏位>][-2<栏位>][--help][--version][文件1][文件2]
        补充说明：找出两个文件中，指定栏位内容相同的行，并加以合并，再输出到标准输出设备。
        参　　数：
        -a<1或2> 除了显示原来的输出内容之外，还显示指令文件中没有相同栏位的行。
        -e<字符串> 若[文件1]与[文件2]中找不到指定的栏位，则在输出中填入选项中的字符串。
        -i或--igore-case 比较栏位内容时，忽略大小写的差异。
        -o<格式> 按照指定的格式来显示结果。
        -t<字符> 使用栏位的分隔字符。
        -v<1或2> 跟-a相同，但是只显示文件中没有相同栏位的行。
        -1<栏位> 连接[文件1]指定的栏位。
        -2<栏位> 连接[文件2]指定的栏位。
        --help 显示帮助。
        --version 显示版本信息。
     */
}

void command::kill()
{
    /**
     @a 休眠状态 pid 为进程id号
     kill -STOP pid
     @a 激活状态
     kill -CONT pid
      */
}

void command::less()
{
    /**
    文件管理-less
    ln 返回 locate
    OPENDIR
        名称：less
        使用权限：所有使用者
        使用方式：
        less [Option] filename
        说明：
        less 的作用与 more 十分相似，都可以用来浏览文字档案的内容，不同的是 less 允许使用者往回卷动
        以浏览已经看过的部份，同时因为 less 并未在一开始就读入整个档案，因此在遇上大型档案的开启
        时，会比一般的文书编辑器(如 vi)来的快速。
     */
}

void command::ln()
{
    /**
    文件管理-ln
    cut 返回 less
    OPENDIR
        指令名称 : ln
        使用权限 : 所有使用者
        使用方式 : ln [options] source dist，其中 option 的格式为 :
        [-bdfinsvF] [-S backup-suffix] [-V {numbered,existing,simple}]
        [--help] [--version] [--]
        说明 : Linux/Unix 档案系统中，有所谓的连结(link)，我们可以将其视为档案的别名，而连结又可分为两种 :
        硬连结(hard link)与软连结(symbolic link)，硬连结的意思是一个档案可以有多个名称，而软连结的方式则是产生一个特殊的档案，
        该档案的内容是指向另一个档案的位置。硬连结是存在同一个档案系统中，而软连结却可以跨越不同的档案系统。
        ln source dist 是产生一个连结(dist)到 source，至于使用硬连结或软链结则由参数决定。
        不论是硬连结或软链结都不会将原本的档案复制一份，只会占用非常少量的磁碟空间。
        参数 :
        -f : 链结时先将与 dist 同档名的档案删除
        -d : 允许系统管理者硬链结自己的目录
        -i : 在删除与 dist 同档名的档案时先进行询问
        -n : 在进行软连结时，将 dist 视为一般的档案
        -s : 进行软链结(symbolic link)-v : 在连结之前显示其档名
        -b : 将在链结时会被覆写或删除的档案进行备份
        -S SUFFIX : 将备份的档案都加上 SUFFIX 的字尾
        -V METHOD : 指定备份的方式

        --help : 显示辅助说明
        --version : 显示版本

        范例 :
        将档案 yy 产生一个 symbolic link : zz
        ln -s yy zz
        将档案 yy 产生一个 hard link : zz
        ln yy xx
     */
}

void command::local()
{
    /**

     */
}

void command::locate()
{
    /**
    文件管理-locate
    less 返回 lsattr
    OPENDIR
        名称：locate
        使用权限：所有使用者
        使用方式： locate [-q] [-d ] [--database=]
        locate [-r ] [--regexp=]
        locate [-qv] [-o ] [--output=]
        locate [-e ] [-f ] <[-l ] [-c]
        <[-U ] [-u]>
        locate [-Vh] [--version] [--help]
        说明：
        locate 让使用者可以很快速的搜寻档案系统内是否有指定的档案。其方法是先建立一个包括系统内所有档案名称及路径的数据库，
        之后当寻找时就只需查询这个数据库，而不必实际深入档案系统之中了。
        在一般的 distribution 之中，数据库的建立都被放在 contab 中自动执行。一般使用者在使用时只要用
        # locate your_file_name
        的型式就可以了。 参数：
        -u
        -U
        建立数据库，-u 会由根目录开始，-U 则可以指定开始的位置。
        -e
        将
        排除在寻找的范围之外。
        -l
        如果 是 1．则启动安全模式。在安全模式下，使用者不会看到权限无法看到的档案。这会始速度减慢，
        因为 locate 必须至实际的档案系统中取得档案的权限资料。
        -f
        将特定的档案系统排除在外，例如我们没有到理要把 proc 档案系统中的档案放在数据库中。
        -q
        安静模式，不会显示任何错误讯息。
        -n
        至多显示 个输出。
        -r
        使用正规运算式 做寻找的条件。
        -o
        指定数据库存的名称。
        -d
        指定数据库的路径
        -h
        显示辅助讯息
        -v
        显示更多的讯息
        -V
        显示程序的版本讯息 范例：
        locate chdrv : 寻找所有叫 chdrv 的档案
        locate -n 100 a.out : 寻找所有叫 a.out 的档案，但最多只显示 100 个
        locate -u : 建立数据库
        locate命令可以在搜寻数据库时快速找到档案，数据库由updatedb程序来更新，updatedb是由cron daemon周期性建立的，
        locate命令在搜寻数据库时比由整个由硬盘资料来搜寻资料来得快，但较差劲的是locate所找到的档案若是最近才建立或刚更名的，
        可能会找不到，在内定值中，updatedb每天会跑一次，可以由修改crontab来更新设定值。(etc/crontab)
        locate指定用在搜寻符合条件的档案，它会去储存档案与目录名称的数据库内，寻找合乎范本样式条件的档案或目录录，
        可以使用特殊字元（如”*”或”?”等）来指定范本样式，如指定范本为kcpa*ner, locate会找出所有起始字串为kcpa且结尾为ner的档案或目录，
        如名称为kcpartner若目录录名称为kcpa_ner则会列出该目录下包括子目录在内的所有档案。
        locate指令和find找寻档案的功能类似，但locate是透过update程序将硬盘中的所有档案和目录资料先建立一个索引数据库，
        在执行loacte时直接找该索引，查询速度会较快，索引数据库一般是由操作系统管理，但也可以直接下达update强迫系统立即修改索引数据库。
        不过第一次在执行update後再使用locate寻找档案常会失败，此时就要执行slocate ˉu该命令（也可执行updatedb指令，其效果相同）
        来更新slocate数据库，该命令会在/usr/sbin下产生slocate执行档，再由locate到此数据库寻找所要找的资料。
        */
}

void command::look()
{
    /**
    文档编辑-look
    join 返回 mtype
    OPENDIR
        功能说明：查询单字。
        语　　法：look [-adf][-t<字尾字符串>][字首字符串][字典文件]
        补充说明：look指令用于英文单字的查询。您仅需给予它欲查询的字首字符串，它会显示所有开头字符串符合该条件的单字。
        参　　数：
        -a 使用另一个字典文件web2，该文件也位于/usr/dict目录下。
        -d 只对比英文字母和数字，其余一慨忽略不予比对。
        -f 忽略字符大小写差别。
        -t<字尾字符串> 设置字尾字符串。
     */
}

void command::ls()
{
    /**
    @brief
    [root@www ~]# ls [--full-time] 目录名称
    选项不参数：
        -a ：全部的档案，连同隐藏档( 开头为 . 的档案) 一起列出杢(常用)
        -A ：全部的档案，连同隐藏档，但丌包括 . 与.. 这两个目录
        -d ：仅列出目录本身，而丌是列出目录内的档案数据(常用)
        -f ：直接列出结果，而丌迚行排序 (ls 预讴会以档名排序！)
        -F ：根据档案、目录等信息，给予附加数据结构，例如： *:代表可执行文件； /:代表目录； =:代表 socket 档案； |:代表 FIFO 档案；
        -h ：将档案容量以人类较易读的方式(例如 GB, KB 等等)列出杢；
        -i ：列出 inode 号码，inode 的意义下一章将会介绍；
        -l ：长数据串行出，包吨档案的属性不权限等等数据；(常用)
        -n ：列出 UID 与GID 而非使用者不群组的名称 (UID不GID会在账号管理提到！)
        -r ：将排序结果反向输出，例如：原本档名由小到大，反向则为由大到小；
        -R ：连同子目录内容一起列出杢，等亍该目录下的所有档案都会显示出杢；
        -S ：以档案容量大小排序，而丌是用档名排序；
        -t ：依时间排序，而不是用档名。
            --color=never ：丌要依据档案特性给予颜色显示；
            --color=always ：显示颜色
            --color=auto ：讥系统自行依据讴定来判断是否给予颜色
        --full-time ：以完整时间模式 (包吨年、月、日、时、分) 输出
        --time={atime,ctime} ：输出 access 时间戒改变权限属性时间 (ctime) 而非内容变更时间 (modification time)

     */
}

void command::lsattr()
{
    /**
    文件管理-lsattr
    locate 返回 mattrib
    OPENDIR
    　　功能说明：显示文件属性。
    　　语　　法：lsattr [-adlRvV][文件或目录...]
    　　补充说明：用chattr执行改变文件或目录的属性，可执行lsattr指令查询其属性。
    　　参　　数：
    　　-a 　显示所有文件和目录，包括以"."为名称开头字符的额外内建，现行目录"."与上层目录".."。
    　　-d 　显示，目录名称，而非其内容。
    　　-l 　此参数目前没有任何作用。
    　　-R 　递归处理，将指定目录下的所有文件及子目录一并处理。
    　　-v 　显示文件或目录版本。
    　　-V 　显示版本信息。
     */
}

void command::lsmod()
{
    /**
    @brief

    lsmod——显示已载入系统的模块
    说明：执行lsmod指令，会列出所有已载入系统的模块。
    Linux操作系统的核心具有模块化的特性，因此在编译核心时，无需把全部的功能都放入核心。
    你可以将这些功能编译成一个个单独的模块，待需要时再分别载入。

    有三列 ： Module (模块名称) 、 Size(模块大小)、 Used by（此模块是否被其他模块使用)

    mii 9409 2 8139too,8139cp <==mii 还被 8139cp, 8139too 使用
    当你要加载 8139too 时，需要先加载 mii 这个模块才可以顺利的加载 8139too

     */
}

void command::mattrib()
{
    /**
    文件管理-mattrib
    lsattr 返回 mc
    OPENDIR
        名称：mattrib
        使用权限：所有使用者
        使用方式：
        mattrib [-a|+a] [-h|+h] [-r|+r] [-s|+s] [-/] [-X] msdosfile [ msdosfiles ... ]说明：本程序可用来修改 MS_DOS 档案的属性。
        参数：
        -a/+a 除去/设定备份属性。
        -h/+h 除去/设定隐藏属性。
        -r/+r 除去/设定唯读属性。
        -s/+s 除去/设定系统属性。
        -/ 递回的处理包含所有子目录下的档案。
        -X 以较短的格式输出结果。
        范例：
        mattrib a: 列出 A 槽 MSDOS 格式磁片上所有档案的属性。
        mattrib -h -s -r a:msdos.sys 除去 A 槽磁片上 msdos.sys 档案的隐藏、系统与唯读属性。
        mattrib -r -/ a:*.* 除去 A 槽磁片上包含子目录下所有档案的唯读属性。
     */
}

void command::mc()
{
    /**
    文件管理-mc
    mattrib 返回 mdel
    OPENDIR
        功能说明：提供一个菜单式的文件管理程序。
        语　　法：mc [-abcdfhkPstuUVx][-C <参数>][-l <文件>][-v <文件>][目录]
        补充说明：执行mc之后，将会看到菜单式的文件管理程序，共分成４个部分。
        参　　数：
        -a 　当mc程序画线时不用绘图字符画线。
        -b 　使用单色模式显示。
        -c 　使用彩色模式显示。
        -C<参数> 　指定显示的颜色。
        -d 　不使用鼠标。
        -f 　显示mc函数库所在的目录。
        -h 　显示帮助。
        -k 　重设softkeys成预设置。
        -l<文件> 　在指定文件中保存ftpfs对话窗的内容。
        -P 　程序结束时，列出最后的工作目录。
        -s 　用慢速的终端机模式显示，在这模式下将减少大量的绘图及文字显示。
        -t 　使用TEMPCAP变量设置终端机，而不使用预设置。
        -u 　不用目前的shell程序。
        -U 　使用目前的shell程序。
        -v<文件> 　使用mc的内部编辑器来显示指定的文件。
        -V 　显示版本信息。
        -x 　指定以xterm模式显示。
     */
}

void command::mcd()
{
    /**

     */
}

void command::mcopy()
{
    /**
    文件管理-mcopy
    in 返回 mshowfat
    OPENDIR
        名称：mcopy
        使用权限：所有使用者
        使用方式：
        mcopy [-b/ptnvmoQOsSrRA] sourcefile targetfile
        mcopy [-b/ptnvmoQOsSrRA] sourcefile [ sourcefiles... ] targetdirectory
        mcopy [-tnvm] MSDOSsourcefile
        说明：
        本程序可用来复制 MSDOS 格式档案到 Linux 中，或是由 Linux 中复制 MSDOS 档案到磁片上。mcopy 可复制单一的档案到所指定的档案名称，
        或是复制数个档案到所指定的目录之中。来源与目的档案可为 MSDOS 或是 Linux 档案。
        参数：
        b 批次模式.这是为大量的档案复制进行最佳化的选项,但是当在复制档案过程中产生 crash 时，会有安全性的问题产生。/ 递回的复制。包含目录所含档案与其下所有子目录中的档案。
        p 维持档案原来的属性。
        Q 当复制多个档案产生错误时，尽快结束程序。
        t 复制纯文字档案。将 carriage return/line feeds 转换成 line feeds 字元。
        n 在覆盖 Linux 档案时不会出现警示讯息。
        o 在覆盖 MSDOS 档案时不会出现警示讯息。
        m 维持档案原来的修改时间。当目的档案已存在，且使用 -n 选项时，mcopy 会询问是否要覆盖或是另存新档。
        范例：
        mcopy a:autoexec.bat . 将 A 槽磁片根目录中的 autoexec.bat 复制到目前工作目录之下。
     */
}

void command::mdel()
{
    /**
    文件管理-mdel
    mc 返回 mdir
    OPENDIR
        名称：mdel
        使用权限：所有使用者
        使用方式：
        mdel [-v] msdosfile [ msdosfiles ... ]
        说明：
        本程序可用来删除 MSDOS 格式的档案。
        在删除唯读档案之前会先有提示讯息产生。
        参数：
        -v 显示更多的讯息。
        范例：
        mdel a:autoexec.bat . 将 A 槽磁片根目录中的 autoexec.bat 删除。
     */
}

void command::mdir()
{
    /**
文件管理-mdir
mdel 返回 mktemp
OPENDIR

    功能说明：显示MS-DOS目录。
    语　　法：mdir [-afwx/][目录]
    补充说明：mdir为mtools工具指令，模拟MS-DOS的dir指令，可显示MS-DOS文件系统中的目录内容。
    参　　数：
    -/ 显示目录下所有子目录与文件。
    -a 　显示隐藏文件。
    -f 　不显示磁盘所剩余的可用空间。
    -w 　仅显示目录或文件名称，并以横排方式呈现，以便一次能显示较多的目录或文件。
    -X 　仅显示目录下所有子目录与文件的完整路径，不显示其他信息。
     */
}

void command::mktemp()
{
    /**
文件管理-mktemp
mdir 返回 more
OPENDIR
　　功能说明：建立暂存文件。
　　语　　法：mktemp [-qu][文件名参数]
　　补充说明：mktemp可建立一个暂存文件，供shell script使用。
　　参　　数：
　　-q 　执行时若发生错误，不会显示任何信息。
　　-u 　暂存文件会在mktemp结束前先行删除。
　　[文件名参数] 　文件名参数必须是以"自订名称.XXXXXX"的格式。
     */
}

void command::mmove()
{
    /**
    文件管理-mmove
    more 返回 mread
    OPENDIR
        功能说明：在MS-DOS文件系统中，移动文件或目录，或更改名称。
        语　　法：mmove [源文件或目录...][目标文件或目录]
        补充说明：mmove为mtools工具指令，模拟MS-DOS的move指令，可在MS-DOS文件系统中移动现有的文件或目录，或是更改现有文件或目录的名称。
     */
}

void command::modinfo()
{
    /**
    @brief

    modinfo [-adln] [module_name|filename]
    选项不参数：
    -a ：仅列出作者名称；
    -d ：仅列出该 modules 的说明 (description)；
    -l ：仅列出授权 (license)；
    -n ：仅列出该模块的详细路径。
    事实上，这个 modinfo 除了可以『查阅在核心内的模块』之外，还可以检查『某个模块档案』，
    因此，如果你想要知道某个档案代表的意义为何，利用 modinfo 加上完整檔名吧！ 看看就晓得是啥玩意儿啰！

    */
}

void command::modprobe()
{
    /**
    @brief

    modprobe(module probe)

    功能说明：自动处理可载入模块。

    语　　法：modprobe [-acdlrtvV][--help][模块文件][符号名称 = 符号值]

    参　　数：
      -a或--all 　载入全部的模块。
      -c或--show-conf 　显示所有模块的设置信息。
      -d或--debug 　使用排错模式。
      -l或--list 　显示可用的模块。
      -r或--remove 　模块闲置不用时，即自动卸载模块。和rmmod相似
      -t或--type 　指定模块类型。
      -v或--verbose 　执行时显示详细的信息。
      -V或--version 　显示版本信息。
      -help 　显示帮助。
    补充说明：modprobe可载入指定的个别模块，或是载入一组相依的模块。
    modprobe会根据depmod所产生的相依关系，决定要载入哪些模块。若在载入过程中发生错误，在modprobe会卸载整组的模块。


    [举例]
    *查看modules的配置文件：
    $modprobe -c
    这里，可以查看modules 的配置文件，比如模块的alias.html' target='_blank'>别名是什么等。会打印许多行信息，例如其中的一行会类似如下：
    alias symbol:ieee80211_remove_wds_addr wlan

    *列出内核中所有已经或者未挂载的所有模块：
    $modprobe -l
    这里，我们能查看到我们所需要的模块，然后根据我们的需要来挂载；
    其实modprobe -l 读取的模块列表就位于 /lib/modules/'uname -r' 目录中；
    其中uname -r 是内核的版本.例如输出结果的其中一行是：
    /lib/modules/2.6.27-7-generic/kernel/arch/x86/oprofile/oprofile.ko

    *挂载vfat模块：
    #modprobe vfat
    这里，使用格式"modprobe 模块名"来挂载一个模块。挂载之后，用lsmod可以查看已经挂载的模块。模块名是不能带有后缀的，我们通过modprobe -l 所看到的模块，都是带有.ko 或.o后缀。

    *移除已经加载的模块：
    #modprobe -r  模块名
    这里，移除已加载的模块，和rmmod 功能相同。注意：模块名是不能带有后缀的，我们通过modprobe -l 所看到的模块，都是带有.ko 或.o后缀.

    与内核模块操作相关的命令还有:lsmod     modinfo   depmod    rmmod    insmod    modprobe

    modprobe 命令是根据depmod -a的输出/lib/modules/version/modules.dep来加载全部的所需要模块。
    删除模块的命令是：modprobe -r filename
    系统启动后，正常工作的模块都在/proc/modules文件中列出。使用lsmod命令也可显示相同内容。
    在内核中有一个“Automatic kernel module loading"功能被编译到了内核中。当用户尝试打开某类型的文件时，
    内核会根据需要尝试加载相应的模块。/etc/modules.conf或 /etc/modprobe.conf文件是一个自动处理内核模块的控制文件。

     */
}

void command::more()
{
    /**
文件管理-more
mktemp 返回 mmove
OPENDIR
　　名称：more
　　使用权限：所有使用者
　　使用方式：more [-dlfpcsu] [-num] [+/pattern] [+linenum] [fileNames..]
　　说明：类似 cat ，不过会以一页一页的显示方便使用者逐页阅读，而最基本的指令就是按空白键（space）就往下一页显示，按 b 键就会往回（back）一页显示，
    而且还有搜寻字串的功能（与 vi 相似），使用中的说明文件，请按 h 。
　　参数：-num 一次显示的行数
　　-d 提示使用者，在画面下方显示 [Press space to continue, 'q' to quit.] ，如果使用者按错键，则会显示 [Press 'h' for instructions.] 而不是 '哔' 声
　　-l 取消遇见特殊字元 ^L（送纸字元）时会暂停的功能
　　-f 计算行数时，以实际上的行数，而非自动换行过后的行数（有些单行字数太长的会被扩展为两行或两行以上）
　　-p 不以卷动的方式显示每一页，而是先清除萤幕后再显示内容
　　-c 跟 -p 相似，不同的是先显示内容再清除其他旧资料
　　-s 当遇到有连续两行以上的空白行，就代换为一行的空白行
　　-u 不显示下引号 （根据环境变数 TERM 指定的 terminal 而有所不同）
　　+/ 在每个档案显示前搜寻该字串（pattern），然后从该字串之后开始显示
　　+num 从第 num 行开始显示
　　fileNames 欲显示内容的档案，可为复数个数
　　范例：
　　more -s testfile 逐页显示 testfile 之档案内容，如有连续两行以上空白行则以一行空白行显示。
　　more +20 testfile 从第 20 行开始显示 testfile 之档案内容。
     */
}

void command::mount()
{
    /**
     @brief
命令格式：

　　mount [-t vfstype] [-o options] device dir

    　　其中：

    1.-t vfstype 指定文件系统的类型，通常不必指定。mount 会自动选择正确的类型。常用类型有：

    　　光盘或光盘镜像：iso9660

    　　DOS fat16文件系统：msdos

    　　Windows 9x fat32文件系统：vfat

    　　Windows NT ntfs文件系统：ntfs

    　　Mount Windows文件网络共享：smbfs

    　　UNIX(LINUX) 文件网络共享：nfs

    2.-o options 主要用来描述设备或档案的挂接方式。常用的参数有：

    　　loop：用来把一个文件当成硬盘分区挂接上系统

    　　ro：采用只读方式挂接设备

    　　rw：采用读写方式挂接设备

    　　iocharset：指定访问文件系统所用字符集

　　3.device 要挂接(mount)的设备。

　　4.dir设备在系统上的挂接点(mount point)。
    */
}

void command::mount_example()
{
    /**
    一 . 挂接光盘镜像文件

    1、从光盘制作光盘镜像文件。将光盘放入光驱，执行下面的命令

         #dd if=/dev/cdrom of=/home/sunky/mydisk.iso

    2、将文件和目录制作成光盘镜像文件，执行下面的命令

        #mkisofs -r -J -V mydisk -o /home/sunky/mydisk.iso /home/sunky/ mydir

     3、光盘镜像文件的挂接(mount)
        #mkdir /mnt/vcdrom
        注：建立一个目录用来作挂接点(mount point)

        #mount -o loop -t iso9660 /home/sunky/mydisk.iso /mnt/vcdrom
        注：使用/mnt/vcdrom就可以访问盘镜像文件mydisk.iso里的所有文件了

     4、mount -t iso9660 /home/xxxx.iso /mnt -o loop
     这里假设ISO文件在/home目录下。 -t参数是指定文件系统的类型，光盘或光盘镜像是iso9660，fat32文件系统是vfat，fat16文件系统是msdos
     xxx.iso指的是你的光盘镜像名称。
     /mnt是你根目录下的/mnt目录，这个你也可以指定为其它目录。表示把镜像加载到这个目录。
     查看这么ip地址的主机开了那些服务

    二 .挂接移动硬盘

        对linux系统而言，USB接口的移动硬盘是当作SCSI设备对待的。插入移动硬盘之前，应先用fdisk –l
        或 more /proc/partitions查看系统的硬盘和硬盘分区情况。

        #mount -t ntfs /dev/sdc1 /mnt/usbhd1

        #mount -t vfat /dev/sdc5 /mnt/usbhd2
        注：对ntfs格式的磁盘分区应使用-t ntfs 参数，对fat32格式的磁盘分区应使用-t vfat参数。

        若汉字文件名显示为乱码或不显示，可以使用下面的命令格式。

        #mount -t ntfs -o iocharset=cp936 /dev/sdc1 /mnt/usbhd1
        #mount -t vfat -o iocharset=cp936 /dev/sdc5 /mnt/usbhd2

        linux系统下使用fdisk分区命令和mkfs文件系统创建命令可以将移动硬盘的分区制作成linux系统所特

        有的ext2、ext3格式。这样，在linux下使用就更方便了。使用下面的命令直接挂接即可。

        #mount /dev/sdc1 /mnt/usbhd1

        开机就mount上windows下的分区自动将windows的d盘挂到/mnt/d上，用vi打开/etc/fstab，

        加入以下一行:
        /dev/hda5 /mnt/d vfat defaults,codepage=936,iocharset=cp936 0 0
        注意，先得手工建立一个/mnt/d目录


        mount局域网上其他windows机器共享出的目录(bjchenxu)
        mount -t smbfs -o username=guest,password=guest //machine/path /mnt/cdrom

    三.挂接U盘

        和USB接口的移动硬盘一样对linux系统而言U盘也是当作SCSI设备对待的。使用方法和移动硬盘完全

        一样。插入U盘之前，应先用fdisk –l 或 more /proc/partitions查看系统的硬盘和硬盘分区情况。

        插入U盘后，再用fdisk –l 或 more /proc/partitions查看系统的硬盘和硬盘分区情况。

        [root at pldyrouter root]# fdisk -l
        Disk /dev/sda: 73 dot 4 GB, 73407820800 bytes
        255 heads, 63 sectors/track, 8924 cylinders
        Units = cylinders of 16065 * 512 = 8225280 bytes
        Device Boot Start End Blocks Id System
        /dev/sda1 1 4 32098+ de Dell Utility
        /dev/sda2 * 5 2554 20482875 7 HPFS/NTFS
        /dev/sda3 2555 7904 42973875 83 Linux
        /dev/sda4 7905 8924 8193150 f Win95 Ext'd (LBA)
        /dev/sda5 7905 8924 8193118+ 82 Linux swap
        Disk /dev/sdd: 131 MB, 131072000 bytes
        9 heads, 32 sectors/track, 888 cylinders
        Units = cylinders of 288 * 512 = 147456 bytes
        Device Boot Start End Blocks Id System
        /dev/sdd1 * 1 889 127983+ b Win95 FAT32
        Partition 1 has different physical/logical endings:
        phys=(1000, 8, 32) logical=(888, 7, 31)
        系统多了一个SCSI硬盘/dev/sdd和一个磁盘分区/dev/sdd1,/dev/sdd1就是我们要挂接的U盘。

        #mkdir -p /mnt/usb
        注：建立一个目录用来作挂接点(mount point)

        #mount -t vfat /dev/sdd1 /mnt/usb

        注：现在可以通过/mnt/usb来访问U盘了, 若汉字文件名显示为乱码或不显示，可以使用下面的命令。
        #mount -t vfat -o iocharset=cp936 /dev/sdd1 /mnt/usb

    四.挂接Windows文件共享

        Windows网络共享的核心是SMB/CIFS，在linux下要挂接(mount)windows的磁盘共享，就必须安装和使用samba软件包。
        现在流行的linux发行版绝大多数已经包含了samba软件包，如果安装linux系统时未安装samba请首先安装samba。
        当然也可以到www.samba.org网站下载......新的版本是3.0.10版。

        当windows系统共享设置好以后，就可以在linux客户端挂接(mount)了，具体操作如下：

        # mkdir –p /mnt/samba
        注：建立一个目录用来作挂接点(mount point)

        # mount -t smbfs -o

        username=administrator,password=pldy123 //10.140.133.23/c$ /mnt/samba
        注：administrator 和 pldy123 是ip地址为10.140.133.23 windows计算机的一个用户名和密码， c$是这台计算机的一个磁盘共享

        如此就可以在linux系统上通过/mnt/samba来访问windows系统磁盘上的文件了。

    五.挂接UNIX系统NFS文件共享

        类似于windows的网络共享，UNIX(Linux)系统也有自己的网络共享，那就是NFS(网络文件系统)，
        下面我们就以SUN Solaris2.8和REDHAT as server 3 为例简单介绍一下在linux下如何mount nfs网络共享。

        在linux客户端挂接(mount)NFS磁盘共享之前，必须先配置好NFS服务端。

    1、Solaris系统NFS服务端配置方法如下：

        (1)修改 /etc/dfs/dfstab, 增加共享目录

        share -F nfs -o rw /export/home/sunky

        (2)启动nfs服务

            # /etc/init.d/nfs.server start

        (3)NFS服务启动以后，也可以使用下面的命令增加新的共享

            # share /export/home/sunky1

            # share /export/home/sunky2

            注：/export/home/sunky和/export/home/sunky1是准备共享的目录

    2、linux系统NFS服务端配置方法如下：

        (1)修改 /etc/exports,增加共享目录

            /export/home/sunky 10.140.133.23(rw)

            /export/home/sunky1 *(rw)

            /export/home/sunky2 linux-client(rw)

            注：/export/home/目录下的sunky、sunky1、sunky2是准备共享的目录，10.140.133.23、*、linux- client是被允许挂接此共享linux客户机的IP地址或主机名。
            如果要使用主机名linux-client必须在服务端主机/etc/hosts文 件里增加linux-client主机ip定义。格式如下：

            10.140.133.23 linux-client

        (2)启动与停止NFS服务

            /etc/rc.d/init.d/portmap start (在REDHAT中PORTMAP是默认启动的)

            /etc/rc.d/init.d/nfs start 启动NFS服务

            /etc/rc.d/init.d/nfs stop 停止NFS服务

            注：若修改/etc/export文件增加新的共享，应先停止NFS服务，再启动NFS服务方能使新增加的共享起作用。使用命令exportfs -rv也可以达到同样的效果。

    3、linux客户端挂接(mount)其他linux系统或UNIX系统的NFS共享

            # mkdir –p /mnt/nfs

            注：建立一个目录用来作挂接点(mount point)

            #mount -t nfs -o rw 10.140.133.9:/export/home/sunky /mnt/nfs

            注：这里我们假设10.140.133.9是NFS服务端的主机IP地址，当然这里也可以使用主机名，但必须在本机/etc/hosts文件里增加服务端ip定义。
            /export/home/sunky为服务端共享的目录。

            如此就可以在linux客户端通过/mnt/nfs来访问其它linux系统或UNIX系统以NFS方式共享出来的文件了。
            以上操作在redhat as server 3、redflag server4.1、suse server 9以及Solaris 7、Solaris 8、Solaris 9 for x86&sparc环境下测试通过。
     */
}

void command::mread()
{
    /**
    文件管理-mread
    mmove 返回 mren
    OPENDIR
    　　功能说明：将MS-DOS文件复制到Linux/Unix的目录中。
    　　语　　法：mread [MS-DOS文件...][Linux文件或目录]
    　　补充说明：mread为mtools工具指令，可将MS-DOS文件复制到Linux的文件系统中。
    这个指令目前已经不常用，一般都使用mcopy指令来代替。
     */
}

void command::mv()
{
    /**
    文件管理-mv
    mtoolstest 返回 od
    OPENDIR
    　　名称：mv
    　　使用权限：所有使用者
    　　使用方式：
    　　mv [options] source dest
    　　mv [options] source... directory
    　　说明：将一个档案移至另一档案，或将数个档案移至另一目录。
    　　参数：-i 若目的地已有同名档案，则先询问是否覆盖旧档。
    　　范例：
    　　将档案 aaa 更名为 bbb :
    　　mv aaa bbb
    　　将所有的C语言程序移至 Finished 子目录中 :
    　　mv -i *.c
     */
}

void command::nautilus()
{
    /**
    使用以下命令在shell终端中以窗口形式打开一个文件夹

    nautilus  dirname

    可以用 alias 命令来给nautilus命令重新起名字，容易记住

    alias opendir='nautilus'

    完成之后就可以用 opendir 命令来进行与 nautilus 命令相同的操作

    opendir dirname

    但是这样操作只能在本次打开的shell终端中有用，下次启动shell终端命令失效，
    可以将命令写入配置文件中

    $ vi ~/.bashrc

    打开配置文件后将 alias opendir='nautilus' 添加到配置文件中，如下图

    #export PATH=$PATH:/opt/usr/local/arm/4.3.2/bin
    alias sm='luit -encoding gbk telnet newsmth.net'
    alias xyj='luit -encoding gbk telnet 220.181.69.180 6666'
    alias openpdf='xdg-open'
    alias opendir='nautilus'

    这样在下次启动shell时命令还能使用

    */
}

void command::nm()
{
    /**
      @查看库里面有什么函数
      nm 库名


      */
}

void command::od()
{
    /**
    文件管理-od
    mv 返回 paste
    OPENDIR
    　　功能说明：输出文件内容。
    　　语　　法：od [-abcdfhilovx][-A <字码基数>][-j <字符数目>][-N <字符数目>][-s <字符串字符数>][-t <输出格式>][-w <每列字符数>][--help][--version][文件...]
    　　补充说明：od指令会读取所给予的文件的内容，并将其内容以八进制字码呈现出来。
    　　参　　数：
    　　-a 　此参数的效果和同时指定"-ta"参数相同。
    　　-A<字码基数> 　选择要以何种基数计算字码。
    　　-b 　此参数的效果和同时指定"-toC"参数相同。
    　　-c 　此参数的效果和同时指定"-tC"参数相同。
    　　-d 　此参数的效果和同时指定"-tu2"参数相同。
    　　-f 　此参数的效果和同时指定"-tfF"参数相同。
    　　-h 　此参数的效果和同时指定"-tx2"参数相同。
    　　-i 　此参数的效果和同时指定"-td2"参数相同。
    　　-j<字符数目>或--skip-bytes=<字符数目> 　略过设置的字符数目。
    　　-l 　此参数的效果和同时指定"-td4"参数相同。
    　　-N<字符数目>或--read-bytes=<字符数目> 　到设置的字符数目为止。
    　　-o 　此参数的效果和同时指定"-to2"参数相同。
    　　-s<字符串字符数>或--strings=<字符串字符数> 　只显示符合指定的字符数目的字符串。
    　　-t<输出格式>或--format=<输出格式> 　设置输出格式。
    　　-v或--output-duplicates 　输出时不省略重复的数据。
    　　-w<每列字符数>或--width=<每列字符数> 　设置每列的最大字符数。
    　　-x 　此参数的效果和同时指定"-h"参数相同。
    　　--help 　在线帮助。
    　　--version 　显示版本信息。
     */
}

void command::passwd()
{
    /**
    系统设置-passwd
    mouseconfig 返回 pwconv
    OPENDIR
    　　名称：passwd
    　　使用权限：所有使用者
    　　使用方式：passwd [-k] [-l] [-u [-f]] [-d] [-S] [username]
    　　说明：用来更改使用者的密码
    　　参数：
    　　-k
    　　-l
    　　-u
    　　-f
    　　-d 关闭使用者的密码认证功能, 使用者在登入时将可以不用输入密码, 只有具备 root 权限的使用者方可使用.
    　　-S 显示指定使用者的密码认证种类, 只有具备 root 权限的使用者方可使用.
     */
}

void command::passwd_example()
{
    /**
    修改用户密码， 把用户名为xkd的密码修改为123
    echo "123" | passwd --stdin xkd
     */
}

void command::paste()
{
    /**
    文件管理-paste
    od 返回 patch
    OPENDIR
    　　功能说明：合并文件的列。
    　　语　　法：paste [-s][-d <间隔字符>][--help][--version][文件...]
    　　补充说明：paste指令会把每个文件以列对列的方式，一列列地加以合并。
    　　参　　数：
    　　-d<间隔字符>或--delimiters=<间隔字符> 　用指定的间隔字符取代跳格字符。
    　　-s或--serial 　串列进行而非平行处理。
    　　--help 　在线帮助。
    　　--version 　显示帮助信息。
     */
}

void command::patch()
{
    /**
    文件管理-patch
    paste 返回 rcp
    OPENDIR
    　　功能说明：修补文件。
    　　语　　法：patch [-bceEflnNRstTuvZ]
        [-B <备份字首字符串>][-d <工作目录>][-D <标示符号>][-F <监别列数>][-g <控制数值>]
        [-i <修补文件>][-o <输出文件>][-p <剥离层级>][-r <拒绝文件>][-V <备份方式>][-Y <备份字首字符串>]
        [-z <备份字尾字符串>][--backup-if　　 -mismatch][--binary][--help][--nobackup-if-mismatch]
        [--verbose][原始文件 <修补文件>] 或 path [-p <剥离层级>] < [修补文件]
    　　补充说明：patch指令让用户利用设置修补文件的方式，修改，更新原始文件。倘若一次仅修改一个文件，
        可直接在指令列中下达指令依序执行。如果配合修补文件的方式则能一次修补大批文件，这也是Linux系统核心的升级方法之一。
    　　参　　数：
    　　-b或--backup 　备份每一个原始文件。
    　　-B<备份字首字符串>或--prefix=<备份字首字符串> 　设置文件备份时，附加在文件名称前面的字首字符串，该字符串可以是路径名称。
    　　-c或--context 　把修补数据解译成关联性的差异。
    　　-d<工作目录>或--directory=<工作目录> 　设置工作目录。
    　　-D<标示符号>或--ifdef=<标示符号> 　用指定的符号把改变的地方标示出来。
    　　-e或--ed 　把修补数据解译成ed指令可用的叙述文件。
    　　-E或--remove-empty-files 　若修补过后输出的文件其内容是一片空白，则移除该文件。
    　　-f或--force 　此参数的效果和指定"-t"参数类似，但会假设修补数据的版本为新　版本。
    　　-F<监别列数>或--fuzz<监别列数> 　设置监别列数的最大值。
    　　-g<控制数值>或--get=<控制数值> 　设置以RSC或SCCS控制修补作业。
    　　-i<修补文件>或--input=<修补文件> 　读取指定的修补问家你。
    　　-l或--ignore-whitespace 　忽略修补数据与输入数据的跳格，空格字符。
    　　-n或--normal 　把修补数据解译成一般性的差异。
    　　-N或--forward 　忽略修补的数据较原始文件的版本更旧，或该版本的修补数据已使　用过。
    　　-o<输出文件>或--output=<输出文件> 　设置输出文件的名称，修补过的文件会以该名称存放。
    　　-p<剥离层级>或--strip=<剥离层级> 　设置欲剥离几层路径名称。
    　　-f<拒绝文件>或--reject-file=<拒绝文件> 　设置保存拒绝修补相关信息的文件名称，预设的文件名称为.rej。
    　　-R或--reverse 　假设修补数据是由新旧文件交换位置而产生。
    　　-s或--quiet或--silent 　不显示指令执行过程，除非发生错误。
    　　-t或--batch 　自动略过错误，不询问任何问题。
    　　-T或--set-time 　此参数的效果和指定"-Z"参数类似，但以本地时间为主。
    　　-u或--unified 　把修补数据解译成一致化的差异。
    　　-v或--version 　显示版本信息。
    　　-V<备份方式>或--version-control=<备份方式> 　用"-b"参数备份目标文件后，备份文件的字尾会被加上一个备份字符串，
        这个字符串不仅可用"-z"参数变更，当使用"-V"参数指定不同备份方式时，也会产生不同字尾的备份字符串。
    　　-Y<备份字首字符串>或--basename-prefix=--<备份字首字符串> 　设置文件备份时，附加在文件基本名称开头的字首字符串。
    　　-z<备份字尾字符串>或--suffix=<备份字尾字符串> 　此参数的效果和指定"-B"参数类似，
        差别在于修补作业使用的路径与文件名若为src/linux/fs/super.c，加上"backup/"字符串后，文件super.c会备份于/src/linux/fs/backup目录里。
    　　-Z或--set-utc 　把修补过的文件更改，存取时间设为UTC。
    　　--backup-if-mismatch 　在修补数据不完全吻合，且没有刻意指定要备份文件时，才备份文件。
    　　--binary 　以二进制模式读写数据，而不通过标准输出设备。
    　　--help 　在线帮助。
    　　--nobackup-if-mismatch 　在修补数据不完全吻合，且没有刻意指定要备份文件时，不要备份文件。
    　　--verbose 　详细显示指令的执行过程。
     */
}

void command::ps()
{
    /**
    @brief

    使用方式：ps [options] [--help]
    说明：显示瞬间行程 (process) 的动态
    参数：
    ps 的参数非常多, 在此仅列出几个常用的参数并大略介绍含义
    -A 列出所有的行程
    -w 显示加宽可以显示较多的资讯
    -au 显示较详细的资讯
    -aux 显示所有包含其他使用者的行程

    au(x) 输出格式 :

    USER PID %CPU %MEM VSZ RSS TTY STAT START TIME COMMAND
    USER: 行程拥有者
    PID: pid
    %CPU: 占用的 CPU 使用率
    %MEM: 占用的记忆体使用率
    VSZ: 占用的虚拟记忆体大小
    RSS: 占用的记忆体大小
    TTY: 终端的次要装置号码 (minor device number of tty)
    STAT: 该行程的状态:
        D: 不可中断的静止
        R: 正在执行中
        S: 静止状态
        T: 暂停执行
        Z: 不存在但暂时无法消除
        W: 没有足够的记忆体分页可分配
        <: 高优先序的行程
        N: 低优先序的行程
        L: 有记忆体分页分配并锁在记忆体内 (即时系统或捱A I/O)
    START: 行程开始时间
    TIME: 执行的时间
    COMMAND:所执行的指令

    范例：

    ps
    PID TTY TIME CMD
    2791 ttyp0 00:00:00 tcsh
    3092 ttyp0 00:00:00 ps
    % ps -A
    PID TTY TIME CMD
    1 ? 00:00:03 init
    2 ? 00:00:00 kflushd
    3 ? 00:00:00 kpiod
    4 ? 00:00:00 kswapd
    5 ? 00:00:00 mdrecoveryd
    .......
    % ps -aux
    USER PID %CPU %MEM VSZ RSS TTY STAT START TIME COMMAND
    root 1 0.0 0.7 1096 472 ? S Sep10 0:03 init [3]
    root 2 0.0 0.0 0 0 ? SW Sep10 0:00 [kflushd]
    root 3 0.0 0.0 0 0 ? SW Sep10 0:00 [kpiod]
    root 4 0.0 0.0 0 0 ? SW Sep10 0:00 [kswapd]
    */
}

void command::ps_example()
{
    /**
    列举出系统中所有不是由你运行的程序！

    ps aux | grep -v `whoami`
    或者，更巧妙些的是，为什么不列出最占用时间的前十个程序呢：

    ps aux--sort=-%cpu | grep -m 11 -v `whoami`

    **/
}

void command::pgrep()
{
    /**
     获取进程的pid
     ps x|grep qtcreator |awk '{print $1}'
     pgrep qtcreator

     kill  进程
     pgrep qtcreator |xargs kill -9

     */
}

void command::qdebug()
{
    /**
        在终端输出彩色信息有点类似于html的语法，即在要输出的文字前加上转义字符。

        指令格式如下\033[*m

        这里的*就是转义字符，例如我们要输出一段绿色的文字

        qDebug("\033[32mHello!");

        输出结果：Hello！

        此外还可以设置字体的背景底色、是否加粗、清楚屏幕等等。。。。

        其中*的取值如下

        ??0 : Reset Color Attributes
        ??1 : 加粗
        ??2 : 去粗
        ??4 : 下划线
        ??5 : 闪烁
        ??7 : 反色
        ??21/22 : 加粗 正常
        ??24 : 去掉下划线
        ??25 : 停止闪烁
        ??27 : 反色
        ??30 : 前景，黑色
        ??31 : 前景，红色
        ??32 : 前景，绿色
        ??33 : 前景，黄色
        ??34 : 前景，篮色
        ??35 : 前景，紫色
        ??36 : 前景，青色
        ??37 : 前景，白色
        ??40 : 背景，黑色
        ??41 : 背景，红色
        ??42 : 背景，绿色
        ??43 : 背景，黄色
        ??44 : 背景，篮色
        ??45 : 背景，紫色
        ??46 : 背景，青色
        ??47 : 背景，白色

        其它转义字符命令

            清除屏幕 : \033c
        ??设定水平标位置 : \033[XG
        ??X为水平标位置。
        ??设定垂直标位置 : \033[Xd
        ??Y为垂直标位置。

            \033[0K : 删除从标到该行结尾
        ??\033[1K : 删除从该行开始到标处
        ??\033[2K : 删除整行?
        ??\033[0J : 删除标到萤幕结尾
        ??\033[1J : 删除从萤幕开始到标处
        ??\033[2J : 删除整个屏幕


      */
}

void command::qdebug_example()
{
    /**
     @
     qDebug()<<"\033[33mxingkongdao\033[0m";
     \033[33m  33代表绿色
     \033[0m    0 代表结束，如不结束，那么后面输出的log都是绿色的。

      */
}

void command::rcp()
{
    /**
    文件管理-rcp
    patch 返回 rm
    OPENDIR
    　　功能说明：远端复制文件或目录。
    　　语　　法：rcp [-pr][源文件或目录][目标文件或目录] 或 rcp [-pr][源文件或目录...][目标文件]
    　　补充说明：rcp指令用在远端复制文件或目录，如同时指定两个以上的文件或目录，且最后的目的地是一个已经存在的目录，则它灰把前面指定的所有文件或目录复制到该目录中。
    　　参　　数：
    　　-p 　保留源文件或目录的属性，包括拥有者，所属群组，权限与时间。
    　　-r 　递归处理，将指定目录下的文件与子目录一并处理。
     */
}

void command::route()
{
    /**
     route [-n]
        选项与参数： -n ： 将主机名以 IP 的方式显示
     */
}

void command::rhmask()
{
    /**
    文件管理-rhmask
    mshowfat 返回 whereis
    OPENDIR
        功能说明：产生与还原加密文件。
        语　　法：rhmask [加密文件][输出文件] 或 rhmask [-d][加密文件][源文件][输出文件]
        补充说明：执行rhmask指令可制作加密过的文件，方便用户在公开的网络上传输该文件，而不至于被任意盗用。
        参　　数：
        -d 　产生加密过的文件。
     */
}

void command::rm()
{
    /**
    文件管理-rm
    rcp 返回 slocate
    OPENDIR
    　　名称：rm
    　　使用权限：所有使用者
    　　使用方式：rm [options] name...
    　　说明：删除档案及目录。
    　　参数：
    　　-i 删除前逐一询问确认。
    　　-f 即使原档案属性设为唯读，亦直接删除，无需逐一确认。
    　　-r 将目录及以下之档案亦逐一删除。
    　　范例：
    　　删除所有C语言程序档；删除前逐一询问确认 :
    　　rm -i *.c
    　　将 Finished 子目录及子目录中所有档案删除 :
    　　rm -r Finished
     */
}

void command::rpm()
{
    /**
    @brief
    [root@www ~]# rpm -ivh package_name
    选项不参数：

    -i ：install 的意思
    -v ：察看更绅部的安装信息画面
    -h ：以安装信息列显示安装迚度

    查询已安装软件的信息：
    -q ：仅查询，后面接的软件名称是否有安装；
    -qa ：列出所有的，已经安装在本机 Linux 系统上面的所有软件名称；
    -qi ：列出该软件的详绅信息 (information)，包吨开发商、版本不说明等；
    -ql ：列出该软件所有的档案不目录所在完整文件名 (list)；
    -qc ：列出该软件的所有配置文件 (找出在 /etc/ 底下的檔名而已)
    -qd ：列出该软件的所有说明文件 (找出与man 有关的档案而已)
    -qR ：列出与该软件有关的相依软件所含的档案 (Required 的意思)
    -qf ：由后面接的文件名，找出该档案属亍哪一个已安装的软件； 查询某个 RPM 档案内吨有的信息：
    -qp[icdlR]：注意 -qp 后面接的所有参数以上面的说明一致。但用途仅在亍找出 某个 RPM 档案内的信息，而非已安装的软件信息！注意！

     */
}

void command::rpm_example()
{
    /**
    @brief 解压
    RPM包括是使用cpio格式打包的，因此可以先转成cpio然后解压，如下所示：S
    rpm2cpio xxx.rpm | cpio -div

    @brief
    文件名的信息，软件的版本，适合的平台，编译释出的次数
    rp-pppoe-3.1-5.i386.rpm
    范例一：安装 rp-pppoe-3.5-32.1.i386.rpm
    [root@www ~]# rpm -ivh rp-pppoe-3.5-32.1.i386.rpm
    Preparing... ####################################### [100%]
    1:rp-pppoe ####################################### [100%]

    范例二、一口气安装两个以上的软件时：
    [root@www ~]# rpm -ivh a.i386.rpm b.i386.rpm *.rpm
    # 后面直接接上许多的软件档案！

    范例三、直接由网络上面的某个档案安装，以网址来安装：
    [root@www ~]# rpm -ivh http://website.name/path/pkgname.rpm


    [root@www ~]# rpm -qa <==已安装软件  rpm -qa |grep openoffice.org3

    [root@www ~]# rpm -q[licdR] 已安装的软件名称 <==已安装软件

    [root@www ~]# rpm -qf 存在亍系统上面的某个文件名 <==已安装软件
    example:   rpm -qf /usr/lib/libperm.so
               就可以知道这个库在那个包里面

    [root@www ~]# rpm -qp[licdR] 未安装的某个文件名 <==查阅RPM档案

    范例七：假设我有下载一个 RPM 档案，想要知道该档案的需求档案，该如何？
    [root@www ~]# rpm -qpR filename.i386.rpm # 加上 -qpR ，找出该档案需求的数据！

   卸载redhat自带的yum组件
   [root@www ~]# rpm -qa |grep yum |xargs rpm -e --nodeps

    */
}

void command::rpmbuild()
{
    /**
     rpmbuild --bb test.spec



    %{_sysconfdir}        /etc

    %{_prefix}            /usr

    %{_exec_prefix}       %{_prefix}

    %{_bindir}            %{_exec_prefix}/bin

    %{_lib}               lib (lib64 on 64bit systems)

    %{_libdir}            %{_exec_prefix}/%{_lib}

    %{_libexecdir}        %{_exec_prefix}/libexec

    %{_sbindir}           %{_exec_prefix}/sbin

    %{_sharedstatedir}    /var/lib

    %{_datadir}           %{_prefix}/share

    %{_includedir}        %{_prefix}/include

    %{_oldincludedir}     /usr/include

    %{_infodir}           /usr/share/info

    %{_mandir}            /usr/share/man

    %{_localstatedir}     /var

    %{_initddir}          %{_sysconfdir}/rc.d/init.d

    %{_var}               /var

    %{_tmppath}           %{_var}/tmp

    %{_usr}               /usr

    %{_usrsrc}            %{_usr}/src

    %{_docdir}            %{_datadir}/doc

     */
}

void command::rpmbuild_example()
{
    /**
     *rpmbuild是一个从源代码生成rpm安装包的工具。使用rpmbuild生成一个rpm包，需要写一个.spec文件。
        spec文件的例子网上有很多，但是有几个地方是需要注意的：

    1. 一定要指定BuildRoot。否则RPM_BUILD_ROOT这个内置变量就是空的，会导致生成的rpm包不正确。

    2. 调用configure的时候最好写./configure，因为不同的安装包的configure程序很可能是不一样的；
        在make install的时候，一定要写成make DESTDIR=$RPM_BUILD_ROOT install
        这样才能够把生成的文件安装到BuildRoot对应的目录下面，rpmbuild才能发现到底安装了哪些文件。

    3. 有时候会遇到类似这样的错误：xxx should be in lib64
        这是因为rpmbuild会检查生成的库文件被复制到的位置，如果是64位机器，
        对应的库又被复制到了/usr/local/lib（而不是lib64）的话，就会报错。
        解决办法是想办法把库文件放到lib64目录下面去。如果是用标准的configure的话，
        就可以在configure的时候加上--libdir=/usr/local/lib64的选项。

        大概就是这些了。

        #下面是重点

        #pre是安装之前要做的事情
        说明下:
        %setup 不加任何选项，仅将软件包打开。
        %setup -n newdir 将软件包解压在newdir目录。
        %setup -c 解压缩之前先产生目录。
        %setup -b num 将第num个source文件解压缩。
        %setup -T 不使用default的解压缩操作。
        %setup -T -b 0 将第0个源代码文件解压缩。
        %setup -c -n newdir 指定目录名称newdir，并在此目录产生rpm套件。
        %patch 最简单的补丁方式，自动指定patch level。
        %patch 0 使用第0个补丁文件，相当于%patch ?p 0。
        %patch -s 不显示打补丁时的信息。
        %patch -T 将所有打补丁时产生的输出文件删除。
        ===================================
        %prep
        %setup -c

        #这时进入源码目录了，你可以执行Make或者执行你定义的编译命令，比如 sh xxoo.sh
        %build
        make

        #安装过程···
        %install
        #首先拷贝三个exe程序
        cp cmclient /usr/bin/
        cp cmserver /usr/bin/
        cp cmctl    /usr/bin/
        #添加服务
        cp cmserverd /etc/init.d/
        chkconfig --add cmserverd
        #chkconfig --add /etc/init.d/cmserverd
        chmod a+x /etc/init.d/cmserverd

        #根据arch拷贝动态库
        %ifarch x86_64
        cp /usr/local/component/Ice-3.3.1/lib64/libIce.so.3.3.1 /lib64/
        cp /usr/local/component/Ice-3.3.1/lib64/libIceUtil.so.3.3.1 /lib64/
        %else
        cp /usr/local/component/Ice-3.3.1/lib/libIce.so.3.3.1 /lib/
        cp /usr/local/component/Ice-3.3.1/lib/libIceUtil.so.3.3.1 /lib/
        %endif


        #卸载前要做的工作
        %preun
        service cmserverd stop
        chkconfig --del cmserverd
        unlink /etc/init.d/cmserverd

        #卸载后做的事情
        %postun
        #echo package "%{name}-%{version}-%{release}" uninstalled successfully

        #rpm编译清理时做的事情
        %clean
        rm -rf $RPM_BUILD_ROOT


        #我们的rpm中包含的文件列表,比如rpm -ql cmtools-1.0.0-1.el5
        /etc/init.d/cmserverd
        /lib/libIce.so.3.3.1
        /lib/libIceUtil.so.3.3.1
        /usr/bin/cmclient
        /usr/bin/cmctl
        /usr/bin/cmserver
        =========================输出了文件列表
        %files
        �fattr(-,root,root)
        /usr/bin/cmclient
        /usr/bin/cmserver
        /usr/bin/cmctl
        /etc/init.d/cmserverd
        %ifarch x86_64
        /lib64/libIce.so.3.3.1
        /lib64/libIceUtil.so.3.3.1
        %else
        /lib/libIce.so.3.3.1
        /lib/libIceUtil.so.3.3.1
        %endif
     */

}

void command::scp()
{
    /**
    从 本地 复制到 远程
    scp /home/daisy/full.tar.gz root@172.19.2.75:/home/root （然后会提示你输入另外那台172.19.2.75主机的root用户的登录密码，接着就开始copy了），复制目录加参数 -r 即可

    从 远程 复制到 本地
    scp root@/172.19.2.75:/home/root/full.tar.gz /home/daisy/full.tar.gz

    详细出处参考：http://www.jb51.net/LINUXjishu/70474.html
    copy 本地的档案到远程的机器上

    scp /etc/lilo.conf my@www.britepic.org:/home/my

    会将本地的 /etc/lilo.conf 这个档案 copy 到 www.britepic.org，使用者my 的家目录下。

    =====================================================

    copy远程机器上的档案到本地来

    scp my@www.britepic.org:/etc/lilo.conf /etc

    会将 http://www.britepic.org 中 /etc/lilo.conf 档案 copy 到本地的 /etc 目录下。
     */
}

void command::sed()
{
    /**
    sed是一个很好的文件处理工具，本身是一个管道命令，主要是以行为单位进行处理，可以将数据行进行替换、删除、新增、选取等特定工作，下面先了解一下sed的用法
    sed命令行格式为：
        sed [-nefri] ‘command’ 输入文本

    常用选项：
        -n∶使用安静(silent)模式。在一般 sed 的用法中，所有来自 STDIN的资料一般都会被列出到萤幕上。但如果加上 -n 参数后，则只有经过sed 特殊处理的那一行(或者动作)才会被列出来。
        -e∶直接在指令列模式上进行 sed 的动作编辑；
        -f∶直接将 sed 的动作写在一个档案内， -f filename 则可以执行 filename 内的sed 动作；
        -r∶sed 的动作支援的是延伸型正规表示法的语法。(预设是基础正规表示法语法)
        -i∶直接修改读取的档案内容，而不是由萤幕输出。

    常用命令：
        a   ∶新增， a 的后面可以接字串，而这些字串会在新的一行出现(目前的下一行)～
        c   ∶取代， c 的后面可以接字串，这些字串可以取代 n1,n2 之间的行！
        d   ∶删除，因为是删除啊，所以 d 后面通常不接任何咚咚；
        i   ∶插入， i 的后面可以接字串，而这些字串会在新的一行出现(目前的上一行)；
        p  ∶列印，亦即将某个选择的资料印出。通常 p 会与参数 sed -n 一起运作～
        s  ∶取代，可以直接进行取代的工作哩！通常这个 s 的动作可以搭配正规表示法！例如 1,20s/old/new/g 就是啦！

     */
}

void command::sed_example()
{
    /**
举例：（假设我们有一文件名为ab）
     删除某行
     [root@localhost ruby] # sed '1d' ab              #删除第一行
     [root@localhost ruby] # sed '$d' ab              #删除最后一行
     [root@localhost ruby] # sed '1,2d' ab           #删除第一行到第二行
     [root@localhost ruby] # sed '2,$d' ab           #删除第二行到最后一行

　　显示某行
.    [root@localhost ruby] # sed -n '1p' ab           #显示第一行
     [root@localhost ruby] # sed -n '$p' ab           #显示最后一行
     [root@localhost ruby] # sed -n '1,2p' ab        #显示第一行到第二行
     [root@localhost ruby] # sed -n '2,$p' ab        #显示第二行到最后一行

　　使用模式进行查询
     [root@localhost ruby] # sed -n '/ruby/p' ab    #查询包括关键字ruby所在所有行
     [root@localhost ruby] # sed -n '/\$/p' ab        #查询包括关键字$所在所有行，使用反斜线\屏蔽特殊含义

　　增加一行或多行字符串
     [root@localhost ruby]# cat ab
     Hello!
     ruby is me,welcome to my blog.
     end
     [root@localhost ruby] # sed '1a drink tea' ab  #第一行后增加字符串"drink tea"
     Hello!
     drink tea
     ruby is me,welcome to my blog.
     end
     [root@localhost ruby] # sed '1,3a drink tea' ab #第一行到第三行后增加字符串"drink tea"
     Hello!
     drink tea
     ruby is me,welcome to my blog.
     drink tea
     end
     drink tea
     [root@localhost ruby] # sed '1a drink tea\nor coffee' ab   #第一行后增加多行，使用换行符\n
     Hello!
     drink tea
     or coffee
     ruby is me,welcome to my blog.
     end

　　代替一行或多行
     [root@localhost ruby] # sed '1c Hi' ab                #第一行代替为Hi
     Hi
     ruby is me,welcome to my blog.
     end
     [root@localhost ruby] # sed '1,2c Hi' ab             #第一行到第二行代替为Hi
     Hi
     end

　　替换一行中的某部分
　　格式：sed 's/要替换的字符串/新的字符串/g'   （要替换的字符串可以用正则表达式）
     [root@localhost ruby] # sed -n '/ruby/p' ab | sed 's/ruby/bird/g'    #替换ruby为bird
　  [root@localhost ruby] # sed -n '/ruby/p' ab | sed 's/ruby//g'        #删除ruby

     插入
     [root@localhost ruby] # sed -i '$a bye' ab         #在文件ab中最后一行直接输入"bye"
     [root@localhost ruby]# cat ab
     Hello!
     ruby is me,welcome to my blog.
     end
     bye
     */
}

void command::slocate()
{
    /**
    文件管理-slocate
    rm 返回 split
    OPENDIR
    　　功能说明：查找文件或目录。
    　　语　　法：slocate [-u][--help][--version][-d <目录>][查找的文件]
    　　补充说明：slocate本身具有一个数据库，里面存放了系统中文件与目录的相关信息。
    　　参　　数：
    　　-d<目录>或--database=<目录> 　指定数据库所在的目录。
    　　-u 　更新slocate数据库。
    　　--help 　显示帮助。
    　　--version 　显示版本信息。
     */
}

void command::split()
{
    /**
    文件管理-split
    slocate 返回 tee
    OPENDIR
    　　名称：split
    　　使用权限：所有使用者
    　　使用方式：split [OPTION] [INPUT [PREFIX]]
    　　说明：
    　　将一个档案分割成数个。而从 INPUT 分割输出成固定大小的档案，其档名依序为 PREFIXaa, PREFIXab...；PREFIX 预设值为 `x'。
        若没有 INPUT 档或为 `-'，则从标准输入读进资料。
    　　选项：
    　　-b, --bytes=SIZE
    　　SIZE 值为每一输出档案的大小，单位为 byte。
    　　-C, --line-bytes=SIZE
    　　每一输出档中，单行的最大 byte 数。
    　　-l, --lines=NUMBER
    　　NUMBER 值为每一输出档的列数大小。
    　　-NUMBER
    　　与 -l NUMBER 相同。
    　　--verbose
    　　于每个输出档被开启前，列印出侦错资讯到标准错误输出。
    　　--help
    　　显示辅助资讯然后离开。
    　　--version
    　　列出版本资讯然后离开。
    　　SIZE 可加入单位: b 代表 512， k 代表 1K， m 代表 1 Meg。
    　　范例：
    　　PostgresSQL 大型数据库备份与回存：
    　　因 Postgres 允许表格大过你系统档案的最大容量，所以要将表格 dump 到单一的档案可能会有问题，使用 split 来进行档案分割。
    　　% pg_dump dbname | split -b 1m - filename.dump.
    　　重新载入
    　　% createdb dbname
    　　% cat filename.dump.* | pgsql dbname
     */
}

void command::ssh()
{
    scp();
    /**

     */
}

void command::strings()
{
    /**
    linux命令strings
           strings - 显示文件中的可打印字符
           strings 一般用来查看非文本文件的内容.

                  [-a|-|--all] [-f|--print-file-name] [-o] [--help] [-v|--version] [-n min-len|-min-len|--bytes=min-len] [-t
                  {o,x,d}[--target=bfdname] |--radix={o,x,d}] file

    描述 (DESCRIPTION)
           For each file given, GNU strings 显示每个指定的 file 文件里,包含的所有 有 4个 (或者 用 选项 指定 的 数字) 以 上
           连 续 可打印 字符 的字符串, 在 之后 紧跟着 一个 不可 打印 的 字符. 默认 情况 下, 它 只显示 目标文件 初始化 和 装载
           段 的 字符串; 对于 其它 类型 的 文件 它 显示 整个 文件 里包含 的 所有 字符串.

           strings 一般用来查看非文本文件的内容.

    选项 (OPTIONS)
           在 这里 并列 的 长选项 和 短选项 都是 等价的.
           -a
           --all
           -      与只是 扫描 目标 文件 初始化 和 装载 段, 而是 扫描 整个 文件.
           -f
           --print-file-name
                  在 显示 字符串 之前 先 显示 文件名.
           --help 在 标准 输出 打印 strings 命令 的 选项
                  列表
                  然后 退出.
           -v

           --version
                  在 标准 输出 打印 strings 命令 的 版本号 然后 退出.
           -n min-len

           -min-len

           -bytes=min-len
                  打印 至少 min-len 字符 长 的 字符串. 默认的 是 4.

           -t {o,x,d}

           --radix={o,x,d}
                  在 字符串 前面 显示 其在 文件 中 的 偏移量. 选项 中 的 单个 字符 指定 偏移量的 进制 是 八进制, 十六进制 还
                  是 十进制.

           --target=bfdname
                  指定 一种 目标 代码 格式 来 代替 你的 系统的 默认 格式. 关于 可用的 目标 代码格式 请 参见 objdump(1).

           -o     同 -t o.

     */
}

void command::strings_example()
{
    /**
    可见strings能输出文件中的可打印字符串（可指定字符串的最小长度），通常用来查看非文本文件（如二进制可执行文件）中的可读内容。比如：
    # strings /lib/tls/libc.so.6 | grep GLIBC

    GLIBC_2.0
    GLIBC_2.1
    GLIBC_2.1.1
    GLIBC_2.1.2
    GLIBC_2.1.3
    GLIBC_2.2
    GLIBC_2.2.1
    GLIBC_2.2.2
    GLIBC_2.2.3
    GLIBC_2.2.4
    GLIBC_2.2.6
    GLIBC_2.3
    GLIBC_2.3.2
    GLIBC_2.3.3
    GLIBC_2.3.4
    GLIBC_PRIVATE

    这样就能看到glibc支持的版本。
     */
}

void command::setup()
{
    /**
    系统设置-setup
    time 返回 sndconfig
    OPENDIR
    　　功能说明：设置公用程序。
    　　语　　法：setup
    　　补充说明：setup是一个设置公用程序，提供图形界面的操作方式。在setup中可设置7类的选项：
    　　１.登陆认证方式
    　　２.键盘组态设置
    　　３.鼠标组态设置
    　　４.开机时所要启动的系统服务
    　　５.声卡组态设置
    　　６.时区设置
    　　７.X Windows组态设置
     */
}

void command::service()
{
    /**
        service iptables stop   关闭防火墙服务
        service vsftpd off      关闭ftp服务

    nmap 192.68.17.14  查看服务
      如果没有打开ftp服务。则用service命令打开
    service vsftpd start
    service mysqld start

    linux 系统的服务(services)启动的接口是 /etc/init.d 这个目录下。
     */
    chkconfig();
    chkconfig_example();
}

void command::setfacl()
{
    /**
     *
     *
     */
}

void command::su()
{
    /**
     su [-lm] [-c 指令] [username]
    选项不参数：
        - ：单纯使用 - 如『 su - 』代表使用 login-shell 的变量档案读取方式来登入系统；
            若使用者名称没有加上去，则代表切换为 root 的身份。
        -l ：与-类似，但后面需要加欲切换的使用者账号！也是 login-shell 的方式。
        -m ：-m与-p 是一的，表示『使用目前的环境设定，而不读取新使用者的配置文件』
        -c ：仅进行一次指令，所以 -c 后面可以加上指令喔！
     */
}

void command::su_example()
{
    /**

     su -c "head -n 3 /etc/shadow"
     输入root密码

     */
}

void command::sudo()
{
    /**
    sudo [-b] [-u 新使用者账号]
    选项不参数：
        -b ：将后续的指令放到背景中让系统自行执行，而不与目前的 shell 产生影响
        -u ：后面可以接欲切换的使用者，若无此项则代表切换身份为 root 。

    在root用户下，使用visudo 修改/etc/sudoers文档
     */
}

void command::sudo_example()
{
    /**
    范例一：你想要以 sshd 的身份在 /tmp 底下建立一个名为 mysshd 的档案
    [root@www ~]# sudo -u sshd touch /tmp/mysshd
    [root@www ~]# ll /tmp/mysshd
    -rw-r--r-- 1 sshd sshd 0 Feb 28 17:42 /tmp/mysshd
    # 特别留意，这个档案的权限是由 sshd 所建立的情况喔！

     */
}

void command::tar()
{
    /**
    tar [-cxtzjvfpPN] 文件与目录 ....
    参数：
        -c ：建立一个压缩文件的参数指令(create 的意思)；
        -x ：解开一个压缩文件的参数指令！
        -t ：查看 tarfile 里面的文件！
        特别注意，在参数的下达中， c/x/t 仅能存在一个！不可同时存在！
        因为不可能同时压缩与解压缩。
        -z ：是否同时具有 gzip 的属性？亦即是否需要用 gzip 压缩？
        -j ：是否同时具有 bzip2 的属性？亦即是否需要用 bzip2 压缩？
        -v ：压缩的过程中显示文件！这个常用，但不建议用在背景执行过程！
        -f ：使用档名，请留意，在 f 之后要立即接档名喔！不要再加参数！
        　　　例如使用『 tar -zcvfP tfile sfile』就是错误的写法，要写成
        　　　『 tar -zcvPf tfile sfile』才对喔！
        -p ：使用原文件的原来属性（属性不会依据使用者而变）
        -P ：可以使用绝对路径来压缩！
        -N ：比后面接的日期(yyyy/mm/dd)还要新的才会被打包进新建的文件中！
        --exclude FILE：在压缩的过程中，不要将 FILE 打包！
     */
}

void command::tar_example()
{
    /**
范例一：将整个 /etc 目录下的文件全部打包成为 /tmp/etc.tar
    [root@linux ~]# tar -cvf /tmp/etc.tar /etc<==仅打包，不压缩！
    [root@linux ~]# tar -zcvf /tmp/etc.tar.gz /etc <==打包后，以 gzip 压缩
    [root@linux ~]# tar -jcvf /tmp/etc.tar.bz2 /etc <==打包后，以 bzip2 压缩
    # 特别注意，在参数 f 之后的文件档名是自己取的，我们习惯上都用 .tar 来作为辨识。
    # 如果加 z 参数，则以 .tar.gz 或 .tgz 来代表 gzip 压缩过的 tar file ～
    # 如果加 j 参数，则以 .tar.bz2 来作为附档名啊～
    # 上述指令在执行的时候，会显示一个警告讯息：
    # 『tar: Removing leading `/" from member names』那是关於绝对路径的特殊设定。

范例二：查阅上述 /tmp/etc.tar.gz 文件内有哪些文件？
    [root@linux ~]# tar -ztvf /tmp/etc.tar.gz
    # 由於我们使用 gzip 压缩，所以要查阅该 tar file 内的文件时，
    # 就得要加上 z 这个参数了！这很重要的！

范例三：将 /tmp/etc.tar.gz 文件解压缩在 /usr/local/src 底下
    [root@linux ~]# cd /usr/local/src
    [root@linux src]# tar -zxvf /tmp/etc.tar.gz
    # 在预设的情况下，我们可以将压缩档在任何地方解开的！以这个范例来说，
    # 我先将工作目录变换到 /usr/local/src 底下，并且解开 /tmp/etc.tar.gz ，
    # 则解开的目录会在 /usr/local/src/etc 呢！另外，如果您进入 /usr/local/src/etc
    # 则会发现，该目录下的文件属性与 /etc/ 可能会有所不同喔！

范例四：在 /tmp 底下，我只想要将 /tmp/etc.tar.gz 内的 etc/passwd 解开而已
    [root@linux ~]# cd /tmp
    [root@linux tmp]# tar -zxvf /tmp/etc.tar.gz etc/passwd
    # 我可以透过 tar -ztvf 来查阅 tarfile 内的文件名称，如果单只要一个文件，
    # 就可以透过这个方式来下达！注意到！ etc.tar.gz 内的根目录 / 是被拿掉了！

范例五：将 /etc/ 内的所有文件备份下来，并且保存其权限！
    [root@linux ~]# tar -zxvpf /tmp/etc.tar.gz /etc
    # 这个 -p 的属性是很重要的，尤其是当您要保留原本文件的属性时！

范例六：在 /home 当中，比 2005/06/01 新的文件才备份
    [root@linux ~]# tar -N "2005/06/01" -zcvf home.tar.gz /home

范例七：我要备份 /home, /etc ，但不要 /home/dmtsai
    [root@linux ~]# tar --exclude /home/dmtsai -zcvf myfile.tar.gz /home/* /etc

范例八：将 /etc/ 打包后直接解开在 /tmp 底下，而不产生文件！
    [root@linux ~]# cd /tmp
    [root@linux tmp]# tar -cvf - /etc | tar -xvf -
    # 这个动作有点像是 cp -r /etc /tmp 啦～依旧是有其有用途的！
    # 要注意的地方在於输出档变成 - 而输入档也变成 - ，又有一个 | 存在～
    # 这分别代表 standard output, standard input 与管线命令啦！

     */
}

void command::installBase()
{
    /**
    通常Linux应用软件的安装包有三种：
        1） tar包，如software-1.2.3-1.tar.gz。它是使用UNIX系统的打包工具tar打包的。
        2） rpm包，如software-1.2.3-1.i386.rpm。它是Redhat Linux提供的一种包封装格式。
        3） dpkg包，如software-1.2.3-1.deb。它是Debain Linux提供的一种包封装格式。
             而且，大多数Linux应用软件包的命名也有一定的规律，它遵循：
        名称-版本-修正版-类型

        例如：
        1） software-1.2.3-1.tar.gz 意味着：
        软件名称：software
        版本号：1.2.3
        修正版本：1
         类型：tar.gz，说明是一个tar包。
        2） sfotware-1.2.3-1.i386.rpm
        软件名称：software
        版本号：1.2.3
        修正版本：1
        可用平台：i386，适用于Intel 80x86平台。
        类型：rpm，说明是一个rpm包。
        注：由于rpm格式的通常是已编译的程序，所以需指明平台。在后面会详细说明。
        而software-1.2.3-1.deb就不用再说了吧！大家自己练习一下。

    一个Linux应用程序的软件包中可以包含两种不同的内容：
    1） 一种就是可执行文件，也就是解开包后就可以直接运行的。在Windows中所 有的软件包都是这种类型。安装完这个程序后，
        你就可以使用，但你看不到源程序。而且下载时要注意这个软件是否是你所使用的平台，否则将无法正常安装。
    2） 另一种则是源程序，也就解开包后，你还需要使用编译器将其编译成为可执行文件。这在Windows系统中是几乎没有的，
        因为Windows的思想是不开放源程序的。

    通常，用tar打包的，都是源程序；而用rpm、dpkg打包的则常是可执行程序。一般来说，自己动手编译源程序能够更具灵活性，
    但也容易遇到各种问题和困难。而相对来说，下载那些可执行程序包，反而是更容易完成软件的安装，当然那样灵活性就差多了。
    所以一般一个软件总会提供多种打包格式的安装程序的。你可以根据自己的情况来选择。
     */
    tar_install();
}

void command::tar_install()
{
    installBase();
    /**
    @ 搞定使用tar打包的应用软件
        1. 安装：
        整个安装过程可以分为以下几步：
        1） 取得应用软件：通过下载、购买光盘的方法获得；
        2）解压缩文件：一般tar包，都会再做一次压缩，如gzip、bz2等，所以你需要先解压。如果是最常见的gz格式，
    则可以执行：“tar –xvzf 软件包名”，就可以一步完成解压与解包工作。如果不是，则先用解压软件，再执行“tar –xvf 解压后的tar包”进行解包；
        3） 阅读附带的INSTALL文件、README文件；
        4） 执行“./configure”命令为编译做好准备；
        5） 执行“make”命令进行软件编译；
        6） 执行“make install”完成安装；
        7） 执行“make clean”删除安装时产生的临时文件。
        好了，到此大功告成。我们就可以运行应用程序了。但这时，有的读者就会问，我怎么执行呢？这也是一个Linux特色的问题。
    其实，一般来说， Linux的应用软件的可执行文件会存放在/usr/local/bin目录下！不过这并不是“放四海皆准”的真理，
    最可靠的还是看这个软件的 INSTALL和README文件，一般都会有说明。
        2. 卸载：
        通常软件的开发者很少考虑到如何卸载自己的软件，而tar又仅是完成打包的工作，所以并没有提供良好的卸载方法。
        那么是不是说就不能够卸载呢！其实也不是，有两个软件能够解决这个问题，那就是Kinstall和Kife，
    它们是tar包安装、卸载的黄金搭档。它们的使用方法，笔者会另行文介绍。在此就不加赘述了。
     */
}

void command::tee()
{
    /**
    文件管理-tee
    split 返回 tmpwatch
    OPENDIR
    　　功能说明：读取标准输入的数据，并将其内容输出成文件。
    　　语　　法：tee [-ai][--help][--version][文件...]
    　　补充说明：tee指令会从标准输入设备读取数据，将其内容输出到标准输出设备，同时保存成文件。
    　　参　　数：
    　　-a或--append 　附加到既有文件的后面，而非覆盖它．
    　　-i-i或--ignore-interrupts 　忽略中断信号。
    　　--help 　在线帮助。
    　　--version 　显示版本信息。
     */
}

void command::tmpwatch()
{
    /**
    文件管理-tmpwatch
    tee 返回 touch
    OPENDIR
    　　功能说明：删除暂存文件。
    　　语　　法：tmpwatch [-afqv][--test][超期时间][目录...]
    　　补充说明：执行tmpwatch指令可删除不必要的暂存文件，您可以设置文件超期时间，单位以小时计算。
    　　参　　数：
    　　-a或--all 　删除任何类型的文件。
    　　-f或--force 　强制删除文件或目录，其效果类似rm指令的"-f"参数。
    　　-q或--quiet 　不显示指令执行过程。
    　　-v或--verbose 　详细显示指令执行过程。
    　　-test 　仅作测试，并不真的删除文件或目录。
     */
}

void command::top()
{
    /**
    系统管理-top
    procinfo 返回 pstree
    OPENDIR
    　　名称：top
    　　使用权限：所有使用者
    　　使用方式：top [-] [d delay] [q] [c] [S] [s] [i] [n] [b]
    　　说明：实时显示 process 的动态
    　　参数：
    　　d : 改变显示的更新速度，或是在交谈式指令列( interactive command)按 s
    　　q : 没有任何延迟的显示速度，如果使用者是有 superuser 的权限，则 top 将会以最高的优先序执行
    　　c : 切换显示模式，共有两种模式，一是只显示执行档的名称，另一种是显示完整的路径与名称S : 累积模式，会将己完成或消失的子行程 ( dead child process ) 的 CPU time 累积起来
    　　s : 安全模式，将交谈式指令取消, 避免潜在的危机
    　　i : 不显示任何闲置 (idle) 或无用 (zombie) 的行程
    　　n : 更新的次数，完成后将会退出 top
    　　b : 批次档模式，搭配 "n" 参数一起使用，可以用来将 top 的结果输出到档案内
    　　范例：
    　　显示更新十次后退出 ;
    　　top -n 10
    　　使用者将不能利用交谈式指令来对行程下命令 :
    　　top -s
    　　将更新显示二次的结果输入到名称为 top.log 的档案里 :
    　　top -n 2 -b < top.log

             top  -H -p 641
     */
}

void command::touch()
{
    /**
    文件管理-touch
    tmpwatch 返回 umask
    OPENDIR
    　　名称：touch
    　　使用权限：所有使用者
    　　使用方式：
    　　touch [-acfm]
    　　[-r reference-file] [--file=reference-file]
    　　[-t MMDDhhmm[[CC]YY][.ss]]
    　　[-d time] [--date=time] [--time={atime,access,use,mtime,modify}]
    　　[--no-create] [--help] [--version]
    　　file1 [file2 ...]
    　　说明：
    　　touch 指令改变档案的时间记录。 ls -l 可以显示档案的时间记录。
    　　参数：
    　　a 改变档案的读取时间记录。
    　　m 改变档案的修改时间记录。
    　　c 假如目的档案不存在，不会建立新的档案。与 --no-create 的效果一样。
    　　f 不使用，是为了与其他 unix 系统的相容性而保留。
    　　r 使用参考档的时间记录，与 --file 的效果一样。
    　　d 设定时间与日期，可以使用各种不同的格式。
    　　t 设定档案的时间记录，格式与 date 指令相同。
    　　--no-create 不会建立新档案。
    　　--help 列出指令格式。
    　　--version 列出版本讯息。

    　　范例：
    　　最简单的使用方式，将档案的时候记录改为现在的时间。若档案不存在，系统会建立一个新的档案。
    　　touch file
    　　touch file1 file2
    　　将 file 的时间记录改为 5 月 6 日 18 点 3 分，公元两千年。时间的格式可以参考 date 指令，至少需输入 MMDDHHmm ，就是月日时与分。
    　　touch -c -t 05061803 file
    　　touch -c -t 050618032000 file
    　　将 file 的时间记录改变成与 referencefile 一样。
    　　touch -r referencefile file
    　　将 file 的时间记录改成 5 月 6 日 18 点 3 分，公元两千年。时间可以使用 am, pm 或是 24 小时的格式，日期可以使用其他格式如 6 May 2000 。
    　　touch -d "6:03pm" file
    　　touch -d "05/06/2000" file
    　　touch -d "6:03pm 05/06/2000" file
    　　touch 也可以制造一个空档(0 byte).例如DHCP Server所需的/etc/dhcpd.leases,dhcpd 必须要有这个档案才能运作正常.
        [root@/root]#touch /etc/dhcpd.leases
        [root@/root]#ls -l /etc/dhcpd.leases-rw-r--r-- 1 root root 0 Jul 3 05:50 /etc/dhcpd.leases
    　　记得上一次重灌前把/etc下的设定档tar起来，重灌好之后把原有设定还原，却发现系统检查设定档的时间有问题，这个时候用
    　　find /etc -name * -exec touch {};
    　　就可以把设定档的时间更新到与现在一致了。
     */
}

void command::type()
{
    /**
    type [-tpa] name 选项不参数：
     ：不加任何选项不参数时，type 会显示出 name 是外部指令还是 bash 内建指令
        -t ：当加入 -t 参数时，type 会将 name 以底下这些字眼显示出他的意义：
            file ：表示为外部指令；
            alias ：表示该指令为命令别名所设定的名称；
            builtin ：表示该指令为 bash 内建的指令功能；
        -p ：如果后面接的 name 为外部指令时，才会显示完整文件名；
        -a ：会由 PATH 发量定义的路径中，将所有含 name 的指令都列出来，包含 alias

        $ type -a ls    外部指令

        $ type cd       内建指令

     */
}

void command::umask()
{
    /**
    文件管理-umask
    touch 返回 which
    OPENDIR
    　　功能说明：指定在建立文件时预设的权限掩码。
    　　语　　法：umask [-S][权限掩码]
    　　补充说明：umask可用来设定[权限掩码]。[权限掩码]是由3个八进制的数字所组成，将现有的存取权限减掉权限掩码后，即可产生建立文件时预设的权限。
    　　参　　数：
    　　-S 　以文字的方式来表示权限掩码。
     */
}

void command::uname()
{
    /**
    @brief

    功能说明:显示系统信息。

    语 法:uname [-amnrsv][--help][--version]

    补充说明:uname可显示电脑以及操作系统的相关信息。

    参 数:
     -a或--all 显示全部的信息。
     -m或--machine 显示电脑类型。
     -n或-nodename 显示在网络上的主机名称。
     -r或--release 显示操作系统的发行编号。
     -s或--sysname 显示操作系统名称。
     -v 显示操作系统的版本。
     --help 显示帮助。
     --version 显示版本信息。

    example:
    1.#uname -a
    如果有x86_64就是64位的，没有就是32位的

    2.# uname -m
    x86_64

    3.# arch
    x86_64

    4.#file /bin/cat
    /bin/cat: ELF 64-bit LSB executable, AMD x86-64, version 1 (SYSV), for GNU/Linux 2.4.0, dynamically linked (uses shared libs), stripped

    */
}

void command::unrar()
{
    /**
      @ 解压rar
           unrar x  *.rar

      */
}

void command::useradd()
{
    /**
    系统管理-useradd
    chfn 返回 date
    OPENDIR
    　　功能说明：建立用户帐号。
    　　语　　法：useradd [-mMnr][-c <备注>][-d <登入目录>][-e <有效期限>][-f <缓冲天数>][-g <群组>][-G <群组>]
        [-s <shell>][-u <uid>][用户帐号] 或 useradd -D [-b][-e <有效期限>][-f <缓冲天数>][-g <群组>][-G <群组>][-s <shell>]
    　　补充说明：useradd可用来建立用户帐号。帐号建好之后，再用passwd设定帐号的密码．而可用userdel删除帐号。
        使用useradd指令所建立的帐号，实际上是保存在/etc/passwd文本文件中。
    　　参　　数：
    　　-c<备注> 　加上备注文字。备注文字会保存在passwd的备注栏位中。
    　　-d<登入目录> 　指定用户登入时的启始目录。
    　　-D 　变更预设值．
    　　-e<有效期限> 　指定帐号的有效期限。
    　　-f<缓冲天数> 　指定在密码过期后多少天即关闭该帐号。
    　　-g<群组> 　指定用户所属的群组。
    　　-G<群组> 　指定用户所属的附加群组。
    　　-m 　自动建立用户的登入目录。
    　　-M 　不要自动建立用户的登入目录。
    　　-n 　取消建立以用户名称为名的群组．
    　　-r 　建立系统帐号。
    　　-s<shell>　 　指定用户登入后所使用的shell。
    　　-u<uid> 　指定用户ID。
     */
}

void command::useradd_example()
{
    /**
    添加一个用户 two, -u 指定UID号为 5243, -d 指定家目录, -m 强制创建家目录
    $ sudo useradd two -u 5243 -d /home/two -m

    设置密码
    $ sudo passwd two
     */
}

void command::userconf()
{
    /**
    系统管理-userconf
    chsh 返回 userdel
    OPENDIR
    　　功能说明：用户帐号设置程序。
    　　语　　法：userconf [--addgroup <群组>][--adduser <用户ID><群组><用户名称><shell>][--delgroup <群组>][--deluser <用户ID>][--help]
    　　补充说明：userconf实际上为linuxconf的符号连接，提供图形界面的操作方式，供管理员建立与管理各类帐号。若不加任何参数，即进入图形界面。
    　　参　　数：
    　　--addgroup<群组> 　新增群组。
    　　--adduser<用户ID><群组><用户名称><shell> 　新增用户帐号。
    　　--delgroup<群组> 　删除群组。
    　　--deluser<用户ID> 　删除用户帐号。
    　　--help 　显示帮助。

     */
}

void command::userdel()
{
    /**
    系统管理-userdel
    userconf 返回 usermod
    OPENDIR
    　　功能说明：删除用户帐号。
    　　语　　法：userdel [-r][用户帐号]
    　　补充说明：userdel可删除用户帐号与相关的文件。若不加参数，则仅删除用户帐号，而不删除相关文件。
    　　参　　数：
    　　-r 　删除用户登入目录以及目录中所有文件。
     */
}

void command::usermod()
{
    /**
     *选项不参数:
        -c :后面接账号的说明,即 /etc/passwd 第五栏的说明栏,可以加入一些账号
        的说明。
        -d :后面接账号的家目录,即修改 /etc/passwd 的第六栏;
        -e :后面接日期,格式是 YYYY-MM-DD 也就是在 /etc/shadow 内的第八个
        字段数据啦!
        -f :后面接天数,为 shadow 的第七字段。
        -g :后面接初始群组,修改 /etc/passwd 的第四个字段,亦即是 GID 的字段!
        -G :后面接次要群组,修改这个使用者能够支持的群组,修改的是 /etc/group
        啰~
        -a :与-G 合用,可『增加次要群组的支持』而非『设定』喔!
        -l :后面接账号名称。亦即是修改账号名称, /etc/passwd 的第一栏!
        -s :后面接 Shell 的实际档案,例如 /bin/bash 戒 /bin/csh 等等。
        -u :后面接 UID 数字啦!即 /etc/passwd 第三栏的资料;
        -L :暂时将用户的密码冻结,讥他无法登入。其实仅改 /etc/shadow 的密码
        栏。
        -U :将 /etc/shadow 密码栏的 ! 拿掉,解冻啦!

     应用场景:
     @a  在系统中添加一个用户(one), 此时用户没有sudo 的功能,原因是因为没有把用户添加到 sudo这个群中.可以用usermod 添加.
         sudo usermod -G sudo  one
          这样one 就可以用sudo这个群的功能了.

     @a  系统中有 teacher, one, two, three四个用户, 现在要使 one, two, three 都在teacher这个群中.
         sudo usermod -G teacher one
         sudo usermod -G teacher two
         sudo usermod -G teacher three

         用groups 查看one, two, three 的有效用户.
         在用 newgrp 修改one, two, three 的有效用户.
         newgrp teacher
     */
}

void command::whereis()
{
    /**
    文件管理-whereis
    rhmask 返回 col
    OPENDIR
    　　功能说明：查找文件。
    　　语　　法：whereis [-bfmsu][-B <目录>...][-M <目录>...][-S <目录>...][文件...]
    　　补充说明：whereis指令会在特定目录中查找符合条件的文件。这些文件的烈性应属于原始代码，二进制文件，或是帮助文件。
    　　参　　数：
    　　-b 　只查找二进制文件。
    　　-B<目录> 　只在设置的目录下查找二进制文件。
    　　-f 　不显示文件名前的路径名称。
    　　-m 　只查找说明文件。
    　　-M<目录> 　只在设置的目录下查找说明文件。
    　　-s 　只查找原始代码文件。
    　　-S<目录> 　只在设置的目录下查找原始代码文件。
    　　-u 　查找不包含指定类型的文件。
     */
}

void command::which()
{
    /**
    文件管理-which
    umask 返回 cp
    OPENDIR
    　　功能说明：查找文件。
    　　语　　法：which [文件...]
    　　补充说明：which指令会在环境变量$PATH设置的目录里查找符合条件的文件。
    　　参　　数：
    　　-n<文件名长度> 　指定文件名长度，指定的长度必须大于或等于所有文件中最长的文件名。
    　　-p<文件名长度> 　与-n参数相同，但此处的<文件名长度>包括了文件的路径。
    　　-w 　指定输出时栏位的宽度。
    　　-V 　显示版本信息。
     */
}

void command::xhost()
{
    /**
     *xhost 是用来控制X server访问权限的。
    通常当你从hostA登陆到hostB上运行hostB上的应用程序时，
    做为应用程序来说，hostA是client,但是作为图形来说，
    是在hostA上显示的，需要使用hostA的Xserver,所以hostA是
    server.因此在登陆到hostB前，需要在hostA上运行xhost +
    来使其它用户能够访问hostA的Xserver.
    xhost + 是使所有用户都能访问Xserver.
    xhost + ip使ip上的用户能够访问Xserver.
    xhost + nis:user@domain使domain上的nis用户user能够访问
    xhost + inet:user@domain使domain上的inet用户能够访问。

    xhost +
        这个命令将允许别的用户启动的图形程序将图形显示在当前屏幕上。
        一般与DISPLAY共同使用
     */
}

void command::xhost_example()
{
    /**
    $ xhost +
    $ ssh 192.168.17.23 -l zcg
    $ 输入密码
    $ export DISPLAY=192.168.17.15:0.0
     */
}

void command::yum()
{
    /**
    @brief
    [root@www ~]# yum [option] [查询工作项目] [相关参数] 选项不参数：
    [option]：主要的选项，包拪有：
    -y ：当 yum 要等待用户输入时，这个选项可以自劢提供 yes 的响应；
    --installroot=/some/path ：将该软件安装在 /some/path 而丌使用默讣路径 [查询工作项目] [相关参数]：这方面的参数有：
    search ：搜寻某个软件名称戒者是描述 (description) 的重要关键字； list ：列出目前 yum 所管理的所有的软件名称不版本，有点类似 rpm -qa；

    1、进入/etc/yum.repos.d/目录。

    在命令行输入：wget http://www.linuxidc.com/files/2011/05/06/CentOS-Base.repo

    2、ls 一下，会看到一个文件名为CentOS-Base.repo的文件。

    3、将原来的文件rhel-debuginfo.repo改名为rhel-debuginfo.repo.bak

    4、将CentOS-Base.repo改名为rhel-debuginfo.repo这时

    这时再运行yum install libtool
    */
}

void command::insmod_modprobe()
{
    /**
    @brief

    @brief
    insmod 和modprobe的区别

    insmod 与 modprobe 都是载入 kernel module，不过一般差别于 modprobe 能够处理 module 载入的相依问题。
    比方你要载入 a module，但是 a module 要求系统先载入 b module 时，直接用 insmod 挂入通常都会出现错误讯息，
    不过 modprobe 倒是能够知道先载入 b module  后才载入 a module，如此相依性就会满足。
    不过 modprobe 并不是大神，不会厉害到知道 module 之间的相依性为何，
    该程式是读取 /lib/modules/2.6.xx/modules.dep 档案得知相依性的。而该档案是透过 depmod 程式所建立。

    补充说明：modprobe可载入指定的个别模块，或是载入一组相依的模块。modprobe会根据depmod所产生的相依关系，决定要载入哪些模块。
    使用 modprobe 真的是要比 insmod 方便徆多！因为他是直接去搜寻 modules.dep 的纨录，
    若在载入过程中发生错误，在modprobe会卸载整组的模块。

example:
    范例：请尝试载入 cifs.ko 这个『文件系统』模块
    [root@www ~]# insmod /lib/modules/$(uname -r)/kernel/fs/cifs/cifs.ko
    [root@www ~]# lsmod | grep cifs
    cifs 212789 0

    [root@www ~]# modprobe cifs
    # 徆方便吧！丌需要知道完整的模块文件名，这是因为该完整文件名已经记录到
    # /lib/modules/`uname -r`/modules.dep 当中的缘故啊！如果要移除的话：

    [root@www ~]# modprobe -r cifs
    范例二：请加载 vfat 这个『文件系统』模块

    [root@www ~]# insmod /lib/modules/$(uname -r)/kernel/fs/vfat/vfat.ko
    insmod: error inserting '/lib/modules/2.6.18-92.el5/kernel/fs/vfat/vfat.ko': -1 Unknown symbol in module
    # 无法加载 vfat 这个模块啊！伤脑筋！
    范例：将刚刚加载的 cifs 模块移除！
    [root@www ~]# rmmod cifs

    */
}

void command::zip()
{
    /**
    linux unzip 命令详解

    功能说明：解压缩zip文件

    语 法：unzip [-cflptuvz][-agCjLMnoqsVX][-P <密码>][.zip文件][文件][-d <目录>][-x <文件>] 或 unzip [-Z]

    补充说明：unzip为.zip压缩文件的解压缩程序。

    参 数：

    -c 将解压缩的结果显示到屏幕上，并对字符做适当的转换。

    -f 更新现有的文件。

    -l 显示压缩文件内所包含的文件。

    -p 与-c参数类似，会将解压缩的结果显示到屏幕上，但不会执行任何的转换。

    -t 检查压缩文件是否正确。

    -u 与-f参数类似，但是除了更新现有的文件外，也会将压缩文件中的其他文件解压缩到目录中。

    -v 执行是时显示详细的信息。

    -z 仅显示压缩文件的备注文字。

    -a 对文本文件进行必要的字符转换。

    -b 不要对文本文件进行字符转换。

    -C 压缩文件中的文件名称区分大小写。

    -j 不处理压缩文件中原有的目录路径。

    -L 将压缩文件中的全部文件名改为小写。

    -M 将输出结果送到more程序处理。

    -n 解压缩时不要覆盖原有的文件。

    -o 不必先询问用户，unzip执行后覆盖原有文件。

    -P<密码> 使用zip的密码选项。

    -q 执行时不显示任何信息。

    -s 将文件名中的空白字符转换为底线字符。

    -V 保留VMS的文件版本信息。

    -X 解压缩时同时回存文件原来的UID/GID。

    [.zip文件] 指定.zip压缩文件。

    [文件] 指定要处理.zip压缩文件中的哪些文件。

    -d<目录> 指定文件解压缩后所要存储的目录。

    -x<文件> 指定不要处理.zip压缩文件中的哪些文件。

    -Z unzip -Z等于执行zipinfo指令
      */
}

void command::dbus()
{
    /**
        dbus-monitor
        监听总线上的
        dbus
        信息
        •
        dbus-send --system --print-reply --dest=org.freedesktop.DBus
        /org/freedesktop/DBus org.freedesktop.DBus.ListActivatableNames
        •
        查
        看总线上已注册的
        service
        •
        dbus-send --session --type=method_call --print-reply
        --dest=cmos.testdbus.service /testdbus
        cmos.testdbus.service.serviceMethod string:"10“
        •
        调用已注册
        service
        的方法
        •
        dbus-send --session --type=signal --print-reply
        --dest=cmos.testdbus.service /testdbus
        cmos.testdbus.service.notifyClientDBusChanged string:"10“
        •
        发送
        dbus
        广播

        dbus-send [--system | --session] --type=method_call --print-reply
        --dest=连接名 对象路径 接口名.方法名 参数类型:参数值 参数类型:参数值
        dbus-send支持的参数类型包括：string, int32, uint32, double, byte, boolean。


        调试dbus, 在用下面的命令的时候,需要把journalctl -fa 打开, 然后运行下面的命令,journalctl -fa 的输出结果,需要开两个窗口
        dbus-send --system --type=signal /cn/cmos/bootcompleted/signal cn.cmos.bootcompleted.signal "string:BOOT_COMPLETED"

      @a dbus-monitor 只能监听到信号,不能监听到方法, 可以加  --print-reply 来输出, 如果dbus 调用不了接口,那么要考虑权限的问题
        dbus-send --session --type=method_call --dest=test.dbus.service /test test.dbus.interface.adaptorTestDbus
        dbus-send --session --type=method_call --dest=test.dbus.service /test test.dbus.interface.adaptorTestDbus
        dbus-send --system --type=method_call --print-reply  --dest=cn.cmos.antitheft /antitheft cn.cmos.antitheft.AtGetRemoteNum
        dbus-send --system --type=method_call --print-reply  --dest=com.syberos.contactsd / com.syberos.contactsd.getContacts
     */
}

void command::dd()
{
    /**
    http://blog.csdn.net/adaptiver/article/details/6672592

        使用dd这个linux命令可以创建一定大小文件。
        linux创建文件命令：dd命令
        把指定的输入文件拷贝到指定的输出文件中，并且在拷贝的过程中可以进行格式转换。语法：
        CODE:[Copy to clipboard]dd 〔选项〕
        QUOTE:
        if =输入文件(或设备名称)。
        of =输出文件(或设备名称)。
        ibs = bytes 一次读取bytes字节，即读入缓冲区的字节数。
        skip = blocks 跳过读入缓冲区开头的ibs*blocks块。
        obs = bytes 一次写入bytes字节，即写 入缓冲区的字节数。
        bs = bytes 同时设置读/写缓冲区的字节数(等于设置obs和obs)。
        cbs = bytes 一次转换bytes字节。
        count = blocks 只拷贝输入的blocks块。
        conv = ASCII 把EBCDIC码转换为ASCII码。
        conv = ebcdic 把ASCII码转换为EBCDIC码。
        conv = ibm 把ASCII码转换为alternate EBCDIC码。
        conv = blick 把变动位转换成固定字符。
        conv = ublock 把固定们转换成变动位
        conv = ucase 把字母由小写变为大写。
        conv = lcase 把字母由大写变为小写。
        conv = notrunc 不截短输出文件。
        conv = swab 交换每一对输入字节。
        conv = noerror 出错时不停止处理。
        conv = sync 把每个输入记录的大小都调到ibs的大小(用ibs填充)。
        fdformat命令
        低级格式化软盘。
        实例:
        创建一个100M的空文件
        dd if=/dev/zero of=hello.txt bs=100M count=1

        以上是linux创建文件命令：dd的用法
      */
}

void command::dd_example()
{
    /**
    http://blog.csdn.net/adaptiver/article/details/6672592

    2.实例分析
    2.1.数据备份与恢复
    2.1.1整盘数据备份与恢复
    备份
    将本地的/dev/hdx整盘备份到/dev/hdy ：dd if=/dev/hdx of=/dev/hdy
    将/dev/hdx全盘数据备份到指定路径的image文件：dd if=/dev/hdx of=/path/to/image
    备份/dev/hdx全盘数据，并利用gzip工具进行压缩，保存到指定路径：dd if=/dev/hdx | gzip
    >/path/to/image.gz
    恢复
    将备份文件恢复到指定盘：dd if=/path/to/image of=/dev/hdx
    将压缩的备份文件恢复到指定盘 ：gzip -dc /path/to/image.gz | dd of=/dev/hdx
    2.1.2.利用netcat远程备份
    在源主机上执行此命令备份/dev/hda：dd if=/dev/hda bs=16065b | netcat < targethost-IP >
    1234在目的主机上执行此命令来接收数据并写入/dev/hdc：netcat -l -p 1234 | dd of=/dev/hdc
    bs=16065b
    以下两条指令是目的主机指令的变化分别采用bzip2 gzip对数据进行压缩，并将备份文件保存在当
    前目录 ：
    netcat -l -p 1234 | bzip2 > partition.img
    netcat -l -p 1234 | gzip > partition.img
    2.1.3.备份MBR
    备份：
    备份磁盘开始的512Byte大小的MBR信息到指定文件：dd if=/dev/hdx of=/path/to/image
    count=1 bs=512
    恢复：
    将备份的MBR信息写到磁盘开始部分：dd if=/path/to/image of=/dev/hdx
    2.1.4.备份软盘
    将软驱数据备份到当前目录的disk.img文件：dd if=/dev/fd0 of=disk.img count=1 bs=1440k
    2.1.5.拷贝内存资料到硬盘
    将内存里的数据拷贝到root目录下的mem.bin文件：dd if=/dev/mem of=/root/mem.bin
    bs=1024
    2.1.6.从光盘拷贝iso镜像
    拷贝光盘数据到root文件夹下，并保存为cd.iso文件：dd if=/dev/cdrom of=/root/cd.iso
    2.2.增加Swap分区文件大小
    创建一个足够大的文件（此处为256M）：dd if=/dev/zero of=/swapfile bs=1024 count=262144
    把这个文件变成swap文件：mkswap /swapfile
    启用这个swap文件：swapon /swapfile
    在每次开机的时候自动加载swap文件, 需要在 /etc/fstab 文件中增加一行：/swapfile swap
    swap defaults 0 0
    2.3.销毁磁盘数据
    利用随机的数据填充硬盘：dd if=/dev/urandom of=/dev/hda1
    在某些必要的场合可以用来销毁数据。执行此操作以后，/dev/hda1将无法挂载，创建和拷贝操作
    无法执行。
    2.4磁盘管理
    2.4.1.得到最恰当的block size
    通过比较dd指令输出中所显示的命令执行时间，即可确定系统最佳的block size大小：
    dd if=/dev/zero bs=1024 count=1000000 of=/root/1Gb.filedd if=/dev/zero bs=2048 count=500000 of=/root/1Gb.file
    dd if=/dev/zero bs=4096 count=250000 of=/root/1Gb.file
    dd if=/dev/zero bs=8192 count=125000 of=/root/1Gb.file
    2.4.2测试硬盘读写速度
    通过两个命令输出的执行时间，可以计算出测试硬盘的读／写速度：
    dd if=/root/1Gb.file bs=64k | dd of=/dev/null
    hdd if=/dev/zero of=/root/1Gb.file bs=1024 count=1000000
    2.4.3.修复硬盘
    当硬盘较长时间（比如一两年年）放置不使用后，磁盘上会产生magnetic flux point。当磁头读到
    这些区域时会遇到困难，并可能导致I/O错误。当这种情况影响到硬盘的第一个扇区时，可能导致
    硬盘报废。下面的命令有可能使这些数据起死回生。且这个过程是安全，高效的。
    dd if=/dev/sda of=/dev/sda


      */
}
