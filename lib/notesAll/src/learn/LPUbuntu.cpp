#include "LPUbuntu.h"

LPUbuntu::LPUbuntu()
{
}

void LPUbuntu::apport()
{
    /**
     禁止使用ubuntu的软件支持，把 /etc/default/apport
     中的enable = 1

     */
}

void LPUbuntu::x64_run_x32()
{
    /**

    sudo apt-get install libc6-i386
    sudo apt-get install ia32-libs

      */
}

void LPUbuntu::update_unenter()
{
    /**

    看看安装的文件吧，哦，有boot文件夹，看看里面
    grub里面有menu.lst和menu.lst~两个文件？
    带～的往往是备份啊，看看时间，早点，不管了，大不了重装
    删除menu.lst，把menu.lst~改成menu.lst
    重启，又进入ubuntu图形界面了。

      */
}

void LPUbuntu::vim()
{
    /**
    1. 安装vim full版本

    由于Ubuntu预安装的是tiny版本，就会导致我们在使用上的产生不便。所以我们要安装vim的full版本。

    首先，先卸掉旧版的vi，输入以下命令： sudo apt-get remove vim-common

    然后安装full版的vim，输入命令：sudo apt-get install vim

    这样安装好了之后的VI就没有那么难用了。

    此方法是我自己使用的，很有效，但就是得联网。


    2. 编辑/etc/vim/vimrc.tiny

    由于/etc/vim/vimrc.tiny的拥有者是root用户，所以要在root的权限下对这个文件进行修改。很简单，这个文件里面的倒数第二句话是“set compatible”，将“compatible”改成“nocompatible”非兼容模式就可以解决方向键变ABCD的问题了。

    接下来要解决Backspace键的问题也很简单，在刚才那句话后面再加一句： set backspace=2

      */
}

void LPUbuntu::Terminal_changePage()
{
    /**
    Shift+Ctrl+T:新建标签页
    Shift+Ctrl+W:关闭标签页
    Ctrl+PageUp:前一标签页
    Ctrl+PageDown:后一标签页
    Shift+Ctrl+PageUp:标签页左移
    Shift+Ctrl+PageDown:标签页右移
    Alt+1:切换到标签页1
    Alt+2:切换到标签页2
    Alt+3:切换到标签页3

    Shift+Ctrl+N:新建窗口
    Shift+Ctrl+Q:关闭终端

    终端中的复制／粘贴:
    Shift+Ctrl+C:复制
    Shift+Ctrl+V:粘贴

    终端改变大小：
    F11：全屏
    Ctrl+plus:放大
    Ctrl+minus:减小
    Ctrl+0:原始大小
      */
}

void LPUbuntu::ubuntu_fcitx()
{
    /**
    1首先top，列出进程表，找到fcitx的pid

    或者直接pidof fcitx

    2 sudo kill 掉fcitx

    3  fcitx &  这里的意思是后台跑fcitx，等出现loader time之类的字样的时候，就可以Ctrl+C终止了，

    4  sogou-qimpanel &  同样，后台启动搜狗输入法面板,同样可以Ctrl+C终止

    此时就可以切换输入法试试看了
     */
}

void LPUbuntu::ubuntu_workspace()
{
    /**
    若要更改排數，鍵入以下指令，將最後面的數字改成您想要的數字。
        gsettings set org.compiz.core:/org/compiz/profiles/unity/plugins/core/ vsize 2
    若要更改列數，鍵入以下指令，將最後面的數字改成您想要的數字。
        gsettings set org.compiz.core:/org/compiz/profiles/unity/plugins/core/ hsize 3

      */
}

ubuntuCommand::ubuntuCommand()
{
    /**
     pkexec chmod 0440 /etc/sudoers

     */
}

void ubuntuCommand::apt_get()
{
    /**
    apt-get install xxx 安装程序的时候，报错下面的错：

    W: 您可能需要运行 apt-get update 来解决这些问题

    解决办法：
    进入/etc/apt/目录，将该目录下sources.list.d/及里面的内容全部删除，运行一下命令：
    sudo rm -r /etc/apt/sources.list.d/
    然后重新运行：sudo apt-get update。

      */
}

void ubuntuCommand::apt_file()
{
    /**
    刚才安装Spynner模块，使用的是easy_install spynner安装，各种文件缺失啊，无意中发现apt-file命令，
    从此再也不用担心编译软件缺少某个文件而不知所措了。
    1、首先得安装apt-file命令

        apt-get install apt-file

    2、接着更新apt-file的缓存

        apt-file update

    3、现在你可以使用apt-file搜索缺失的文件了，比如编译过程中提示缺少

        root@test:~# apt-file search XTest.h
        libbcprov-java-doc: /usr/share/doc/libbcprov-java-doc/api/org/bouncycastle/jce/provider/test/PKIXTest.html
        libreoffice-dev-doc: /usr/share/doc/libreoffice-dev/docs/common/ref/com/sun/star/test/XTest.html
        libsvgsalamander-java-doc: /usr/share/doc/libsvgsalamander-java-doc/api/com/kitfox/svg/xml/cpx/CPXTest.html
        libsvgsalamander-java-doc: /usr/share/doc/libsvgsalamander-java-doc/api/com/kitfox/svg/xml/cpx/class-use/CPXTest.html
        libxtst-dev: /usr/include/X11/extensions/XTest.h

    4、显然libxtst-dev包正是我们需要安装的

        apt-get install libxtst-dev

    5、查看git是那个包里面的, 然后通过apt-get install git 安装
        apt-cache  search git
      */
}

void ubuntuCommand::syberos_process()
{
    /**
     代码编译的流程

     sdk enter    -> 进入交叉编译环境

     sb2 是交叉编译的一个命令， 因为手机的cpu是arm架构的，精简指令集，
     而电脑的cpu是 X86的架构，如果在电脑上编译，那么得到的结果是X86的，
     因此需要sb2这个命令把代码编译成arm架构的文件，目前是为了能在手机上
     运行。
     可以用file 这个命令来看编译的结果文件是什么格式的。
     $  file cmos-voicecall-0.8.0-0.armv7tnhl.rpm
     $  cmos-voicecall-0.8.0-0.armv7tnhl.rpm: RPM v3.0 bin ARM(文件是arm的）

     sb2 -t cmos-target-armv7tnhl qmake   ->生成MakeFile文件

     sb2 -t cmos-target-armv7tnhl make    -> 编译代码

     // 把代码编译后并打包成一个rpm包，包放在下面的路径下，第一个是主程序，下面的是plugin，两者之间不一定有依赖关系

        /home/xkd/rpmbuild/RPMS/armv7tnhl/cmos-voicecall-0.8.0-0.armv7tnhl.rpm
        /home/xkd/rpmbuild/RPMS/armv7tnhl/cmos-voicecall-plugin_phonesetting-0.8.0-0.armv7tnhl.rpm


     \brief rpmbuild 如果报错， %define _app_system_appdir /usr/apps/%{appid}
     sb2 -t cmos-target-armv7tnhl rpmbuild --build-in-place --bb ../cmos_voicecall.spec

     把编译的rpm包传到手机上
     scp 源文件 目标文件 ， 例如：

     // 把 cmos-voicecall-0.8.0-0.armv7tnhl.rpm 传给手机上的developer用户，并放在/home/developer 这个路径下

     scp /home/xkd/rpmbuild/RPMS/armv7tnhl/cmos-voicecall-0.8.0-0.armv7tnhl.rpm  developer@192.168.100.100:/home/developer


     链接上手机

     ssh  developer@192.168.100.100
     密码： system

     要切换到手机的root用户下安装rpm包。
     su root
     密码 system

     journalctl -fa   (目前还不知道个命令是什么意思）

     // 由于远程登陆手机的时候，对手机的根目录只有读的权限，需要重新挂载
     // 要不然，在手机上安装程序会安装不上。

     mount -o remount, rw /   重新挂载手机，同时把权限改为rw，

     安装程序
     rpm -ivh --force /home/developer/cmos-voicecall-0.8.0-0.armv7tnhl.rpm

     查看安装成功后的文件属性
     ls /usr/apps/cmos-voicecall/bin/cmos-voicecall -al

     如果发现cmos-voicecall 这个程序的UID和GID不是 cmos-voicecall ,那么则修改为cmos-voicecall

          (UID.GID)
     chown cmos-voicecall.cmos-voicecall /usr/apps/cmos-voicecall/bin/cmos-voicecall

     卸载安装程序

     rpm -e cmos-voicecall
     rpm -e cmos-voicecall  --nodeps (强制删除，不用管依赖关系）
      */
}

#include <QScopedPointer>
void ubuntuCommand::syberos_install_lib()
{
    /**
    查看有没有安装库

    更新sdk, 可以从sdk中下载

    sb2 -t cmos-target-armv7tnhl -m sdk-install -R zypper ref

    sb2 -t cmos-target-armv7tnhl -m sdk-install -R zypper se csystem

    sb2 -t cmos-target-armv7tnhl -m sdk-install -R rpm -rebuilddb
    sb2 -t cmos-target-armv7tnhl -m sdk-install -R zypper ref --force
    sb2 -t cmos-target-armv7tnhl -m sdk-install -R zypper se qt
    echo 'PS1="MerSDK $PS1"' >> ~/.mersdk.profile
    sudo mkdir -p /srv/mer/targets/
    cd /srv/mer/targets/
    sudo tar xvjf ~/mer-target-armv7tnhl-qt53.tar.bz2
    sudo mv mer-target-armv7tnhl-qt53 mer-target-armv7tnhl
    sdk enter
    sb2 -t cmos-target-armv7tnhl qmake
    sb2 -t cmos-target-armv7tnhl make
    git branch -a
    git branch
    sb2 -t cmos-target-armv7tnhl -m sdk-install -R zypper se csystem
    sb2 -t cmos-target-armv7tnhl -m sdk-install -R zypper in qt5-qtcsystem-devel
    sb2 -t cmos-target-armv7tnhl make
    sb2 -t cmos-target-armv7tnhl -m sdk-install -R zypper se csystem

    // 安装库
    sb2 -t cmos-target-armv7tnhl -m sdk-install -R zypper in  qt5-qtcsystem-devel

    // 本地安装
    sb2 -t cmos-target-armv7tnhl -m sdk-install -R rpm -ivh --force --nodeps cmos-booster-devel-1.0-1.skytree.4.1.armv7tnhl.rpm
      */
}

void ubuntuCommand::syberos_work()
{
    /**
      修改 Text的renderType 属性
      renderType : enumeration
      */
}

void ubuntuCommand::git()
{
    /**
    http://www.oschina.net/question/565065_86025

    Fixed on 20141114(修改bug 的后一天),daily
    git 的功能类似svn，主要是用来管理代码的。

    // 显示所有分支代码， 前面带※的为当前代码的分支
    $: git branch -a

    // 查看状态，相当于 svn st 命令
    $: git status

    // 把修改了的文件添加的提交的列表，如果不提交，那么后面提交的时候用
    // git commit -a
    $: git add xxx.cpp xxx.h

    // 提交,如果commit 之前add了，commit的时候就只提交add的文件
    // commit 的时候会有一个文件说明，有点类似备注信息或者 log
    $: git commit

    // 指定那些文件要提交，填写了log信息后，就开始提交代码
    // git push origin 相当与 svn commit
    // main_dev 本地代码的分支
    // refs/for/(指定的分支，gerrit的语法，不是git的。主要是用来代码审查(code review)),
        下面这行代码就是把本地分支 main_dev 提交到服务器的main_dev 分支上。具体分支用git branch -a 查看
    $: git push origin main_dev:refs/for/main_dev

    // 提交本地test 分支作为远程的master分支
    $: git push origin test:master

    // 提交本地test分支作为远程的test分支
    $: git push origin test:test


    检出仓库：   $ git clone git://github.com/jquery/jquery.git

    查看远程仓库：$ git remote -v

    添加远程仓库：$ git remote add [name] [url]

    删除远程仓库：$ git remote rm [name]

    修改远程仓库：$ git remote set-url --push [name] [newUrl]

    拉取远程仓库：$ git pull [remoteName] [localBranchName]

    推送远程仓库：$ git push [remoteName] [localBranchName]
      */
}

void ubuntuCommand::git_example()
{
    /**
    把文件添加的stage（缓存区),一边通过commit 把缓存区的文件提交
    $ git add

    查看提交的历史记录
    $ git log

    查看历史命令，用来查看commit_id 号
    $ git reflog

    简化历史记录的信息
    $ git log --pretty=oneline

    回复到上一个版本, HEAD^ 上一个版本、 HEAD^^ 上上一个版本、 HEAD~100上100个版本
    $ git reset --hard HEAD^
    $ git reset HEAD  filename    恢复add 的状态
    $ git add
    $ git rm path -r

    $ git reset --hard id号（通过 git reflog来查看)

    查看工作区和版本库里面最新版本的区别
    $ git diff HEAD -- 文件

    丢弃工作区的修改
    git checkout -- file命令中的--很重要，没有--，就变成了“创建一个新分支”的命令
    一种是readme.txt自修改后还没有被放到暂存区，现在，撤销修改就回到和版本库一模一样的状态；
    一种是readme.txt已经添加到暂存区后，又作了修改，现在，撤销修改就回到添加到暂存区后的状态。

    $ git checkout -- 文件

    切换分支
    $ git checkout 分支名称


    修改git commit 除了 git commit --amend 还有 git commmit rebase, reset,
    把上次提交的回复，(这次提交和上次提交合为一个提交)
    $ git commit --amend

    把暂存区的修改撤销掉（unstage），重新放回工作区
    $ git reset HEAD file

    场景1：当你改乱了工作区某个文件的内容，想直接丢弃工作区的修改时，用命令git checkout -- file。
    场景2：当你不但改乱了工作区某个文件的内容，还添加到了暂存区时，想丢弃修改，分两步，
            第一步用命令git reset HEAD file，就回到了场景1，第二步按场景1操作。
    场景3：已经提交了不合适的修改到版本库时，想要撤销本次提交，参考版本回退一节，不过前提是没有推送到远程库。

    // 删除文件，然后 git commit
    $ git rm test.txt
      */
}

void ubuntuCommand::git_error()
{
    /**

    @a
    Permission denied (publickey).
    fatal: The remote end hung up unexpectedly

    1、cd ~/.ssh

    2、ssh-keygen -t rsa -C you@Email.com（xingkongdao@syberos.com)

    遇到 提示一路 回车

    遇到有Y 输入Y

    3、ssh-add id_rsa

     若出现： Could not open a connection to your authenticationagent.

    输入：ssh-agent bash  在使用 ssh-add id_rsa

    4、登录github.com --AccountSetting--ssh  点击Add  (Gerrit Settings SSH Public Keys)

    将id_rsa.pub 文件中的 内容添加进去

    最后git clone 成功 （with ssh）

    git clone with http 失败

    仓库创建
    1.   本地新建一个git仓库

        git --bare init

        如果是需要作为服务器仓库的，推荐加—bare，否则以后其他仓库push代码到此仓库时会有一些麻烦。

        具体可以参考：http://hi.baidu.com/mengdaant/item/62dc182908bf25f950fd87ff



        添加文件

        git add . // add all

        git add \\*.txt  // add all txt file


        添加文件后，直接git commit就完成了仓库创建。


    2.   本地克隆一个远程仓库

        2.1 克隆远程仓库

        git clone  <name> <url> <directory>

        这里，name可以不写，默认origin

        directory也可以不写，默认使用远程git一样的根目录名。



        2.2  添加远程仓库

        git remoteadd  <name>  <url>

        name可以任意取。 url必须是确实存在的git仓库。


    3.   同步远程仓库代码到本地

        git pull <name>

        如果pull时提示“You asked me to pull without telling me whichbranch you want to merge with”，
        说明本地有新建分支且已同步到服务器上，当从服务器下载代码时需要在本地config中配置该分支的merge信息。
        配置时可以参考下面的例子：

         $ git config branch.master.remote origin   //master是分支名，origin是远程仓库名

         $ git config branch.master.merge refs/heads/master

        具体可参考http://hubingforever.blog.163.com/blog/static/171040579201232184549211/


    4.   同步本地代码到远程仓库

        git push <remote name> <branchname>

        如果push时提示“ refusing to update checked out branch:refs/heads/master”，说明远程仓库创建是没有使用—bare选项。

        解决这个冲突需要远程仓库管理员：
        具体可以是将远程仓库当前分支切换到其他分支（如谁也不会使用的分支），
        或者按照提示内容，设置denyCurrentBranch = ignore。
        具体可参考http://hi.baidu.com/mengdaant/item/62dc182908bf25f950fd87ff



    @b
    如果git push origin 把当前分支推送到远程分支上时报错,
    那么有可能是 远程分支初始化的时候用  git init 而不是 git init --bare
    同时远程分支的当前分支(origin/main_dev)正好是你要推送的分支,所以报错.

    git push origin xkd:main_dev

    解决方法:
      @ 到服务器上切换分支,只要服务器的当前分支不是main_dev,那么在
          client 上推送就成功


    */
}









