 #include "EPSyberos.h"

EPSyberos::EPSyberos()
{
    /**
    @a
    \\192.168.160.121\研发中心\ui\手机\8设置-svn\8UI\PIN码UI\ui1.5
    samba4321

    192.168.160.237
    Yc9%oXDR@

    @redmine
    kongdao_xing

    @a
    手机没有显示链接 ， 设置->开发者选项->USB调试

    @a
    要先安装OS_EVolution 的版本
    http://192.168.160.123/Releases_Phone_w302/spread-1110-06/
    rootfs-upg-w302-1110-06.img

    @a  重中之重
    qml 里输出可能会中断，但是不会有任何报错。所以平时写程序要注意这点
    当你引用一个空的指针的时候,程序就会崩溃,这样log就输出不了

    调试的时候，有几个基本的要求，请注意：

    1.使用log验证某个函数是否被调用的时候，log要加在函数的入口处。
    2.如果发现程序运行结果与期望的不一致，应该先找到具体出问题的地方。
    3.调试的时候，尽量每次只修改一个地方。

    @a
    如果创建一个对象,但是没有给对象指定父类,然后把这个对象丢给qml,这个时候,由于这个对象没有父类,
    于是,qml在析构的时候会把这个对象析构了.

    @a
    rpm -qf /usr/lib/libperm.so
    就可以知道这个库在哪个包里面

    @a
    刷机并不会把原来的数据删除掉,只是把程序替换了,但是数据还在,
    比如设置里面的电话属性值.呼叫转移等

    @a
    如果scp 往手机上传文件,报 permission deny
    那么可能是手机上有这个文件,且权限不属于 developer

    @a
    要记住释放内存

    @a 电话打不进来,有可能是呼叫转移或者是blacklistd 没有起来.或者是已经把号码加入黑名单

    @a 呼叫转移设置不了,可能是因为手机欠费了.调试问题的时候,要考虑手机欠费的原因.

    @a cmos-guest
       1234567890

   nemo-qml-plugin-contacts
   commhistory-daemon


   qDebug()<<QString("%1%2").arg(__FILE__).arg(__LINE__);

   system-main [whitelists]
   /usr/etc/system-main.ini

   sudo dpkg-reconfigure gdm   gnome lightdmsud             

   查看系统版本
   /usr/etc/syberos-release

   sdk-invoker 0 com.syberos.voicecall:syberos.voicecall.ui:uiapp /usr/apps/voicecall/bin/voicecall demo
   sdk-invoker 0 com.syberos.contact:contact-contact:uiapp /usr/apps/contact/bin/contact demo

    PRAGMA key='testkey';PRAGMA cipher='aes-128-cbc';PRAGMA kdf_iter='100';

   @ 移动 sim  13681524845
   @ 移动 sim 13810364766  service : 727964
   @ 联通 sim 18500126142  service : 126142 puk: 41838761
   eim 100242 xkd4424168
  */
}

void EPSyberos::qdbus()
{
    /**
    @brief
    发送端只需创建一个信号原后发送即可：

    创建QT 的DBus信号
    QDBusMessage msg = QDBusMessage::createSignal("/hotel/path", "hoterl.interface", "checkIn");


    给信号赋值
    msg<<this->ui->checkInlineEdit->text().toInt();

    发射信号
    QDBusConnect::sessionBus().send(msg);

    @brief
    接受端

    绑定信号
    QDBusConnection::sessionBus().connect(QString(), QString(),
                    "dbus.client.interface", "Active", this, SLOT(ActiveEvent(int)));
    在ActiveEvent槽中执行你的应用程序需要对这个信号做出的反应即可


      */
}

void EPSyberos::cmos_voicecall_component()
{
    /**
    打电话过程中的数字输入文本框（组件)
    NumberEntryCall

    // 来电的时候，非锁屏状态的来电显示界面， 有 号码、电话归属地、来电
    ActiveCallSingleCallPanel

      */
}

void EPSyberos::cmos_voicecall_translate()
{
    /**
    翻译文件的修改，需要把qm文件复制到 /usr/apps/cmos-voicecall/qm/ 路径下

    要用命令行修改, 先到ts文件中修改翻译,然后用lrelease发布

    翻译没有翻译出来,有这么几种情况:
    @a   标识不对
    @b   宏斌的那边
    @c   编译文件没有加载上

      */
}

void EPSyberos::cmos_root()
{
    /**


      */
}

void EPSyberos::cmos_obs()
{
    /**
      点击文件名  [contact] (project ginkgo:devel:applications)
     */
}

void EPSyberos::cmos_gerrit()
{
    /**
      可以在gerrit 上面修改commit 信息

     */
}

void EPSyberos::cmos_spec()
{
    /**
    @a 默认是打包时有debuginfo包，加上上面两行后，打包时就没有debuginfo包了
    %define debug_packages %{nil}
    %define debug_package %{nil}

    这是因为 voicecall/syberos-voicecall
statusText
    Name: voicecall

    %prep
    //(这是要打包syberos-voicecall 这个文件夹,所以要添加syberos-%{name})
    %setup -q -n %{name}-%{version}/syberos-%{name}

    修改依赖包的时候，要注意spec文件的修改.要注意pkgconfig的作用。syberos-native-system只是个pc文件，是通过这个pc文件
    去找到对应的库。如果是这样写：
    buildRequires: syberos-native-system 这是去找 libsyberos-native-system.so 这个库

    buildRequires: pkgconfig(syberos-native-system)


     */
}

void EPSyberos::cmos_git()
{
    /**
    git 提交代码要切换到对应的分支，然后在修改，提交。不能在 A 分支上修改，然后提交到 B 分支上。
    这样 B 分支和 A 分支就相互糅合了。以后合并代码就相当麻烦。


    @a  如果git 提交了一次代码后,没有merge,那么就把用  git commit --amend ,这样就两次合为一次提交,
        不会出现两次提交

    @a  如果两个分支的内容是一样的,那么可以在提交到一个分支以后,通过gerrit 把内容合并到另一个分支上.
        Cherry Picker To  然后选择分支, 确定.
    */
}

void EPSyberos::cmos_qmake()
{
    /**
      gcc  -c main.c        编译
      gcc  main.o -o exe    链接
    @a 在 pro 文件里面写链接库的时候,如果要链接的库不在  /usr/lib, 需要指定库的路径
         因为 如果不指定,那么程序编译的时候会去 /usr/lib 下找库,如果找不到,那就报错.
        LIBS += -L/usr/lib/filePath

    @b 在 pro 里面, 可以直接加入头文件,  INCLUDEPATH 默认是在当前文件中搜索, 如果要想
       #include 当前文件中的 include 文件下的文件,那么需要这么解决:

       #include 可以包含到文件,不是HEADER 和 SOURCE 的作用,而是 INCLUDEPATH, INCLUDEPATH默认下
       会在当前路径下

       INCLUDEPATH += ./include 或者  #include<include/xxx.h>

    @c 还可以用另一种方法加库,  那就是编写 *.pc 文件,然后放在/usr/local/Trolltech/Qt-4.8.6/lib/pkgconfig/ 里
        这样就可以使用了.

        CONFIG += pkgconfig

        PKGCONFIG += QtGui QtXml

        QtGui.pc 这个文件中会定义头文件路径和需要链接的库的路径

    @a 在pro文件,这样写,程序运行的时候,会到 /usr/lib/qt5/qml/org/nemomobile/contacts/
         下找库, 程序链接的时候搜索的路径是用  -L , 程序运行的时候是用  -rpath
        QMAKE_LFLAGS  += -Wl,-rpath,/usr/lib/qt5/qml/org/nemomobile/contacts/
        QMAKE_RPATHDIR += /usr/lib/framework/

    @a  编译出来的库是没有符号的,会导致链接的时候报  symbol undefined 的错误提示
      CONFIG += hide_symbols

     */
}

void EPSyberos::cmos_object()
{
    /**
    @brief CDialog
    CDialog 组件show出来的时候，不能用visible属性，原因是逻辑太复杂，
    会导致显示的时候，界面卡死，解决方法：
    @a CDialog.animationVisible = true;

      */
}

void EPSyberos::cmos_work_error()
{
    /**
     @a OBS 查看编译状态
        block 状态是因为别的模块还没有编译好.
        fail  状态 和 building 状态的时候与我有关.

    @b  提交gerrit的时候,填写的信息:

        [Ginkgo-P]

        [Bug]
        [Solution]
        [Feature] 1.
                  2.
        [Others]
           merge appframework to main_dev

        可以用git checkout -b newbranch  remotes/origin/main_dev 切分一个本地分支,
        然后合并, 再commit

    @c  保持代码的整洁性


    @d  转bug 需要注意的事情

        comment       注释
        component     模块

        窗口管理器               李京 甲伟
        audio-manager

        中间件                 宋仓龙,子旺

    @e 如果是通过dbus 调用的,需要查看一下进程是否还在

    @a

     */
}

void EPSyberos::cmos_wiki()
{
    /**
     公共控件的窗口说明
      https://wiki.cmos.net/%E5%85%AC%E5%85%B1%E6%8E%A7%E4%BB%B6%E5%AF%B9%E5%BA%94%E8%A1%A8#CDialog
     */
}

void EPSyberos::cmos_gdb()
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

    @a  gdb 挂上程序
        用命令   gdb -p pid(cmos-voicecall 的进程号),此时,会把cmos-voicecall的调试信息加载进来

        gdb   应用程序, 例如: gdb voicecall

    @b  设置main函数的参数   set args

    @c  运行  r,在程序运行之前设置断点

    @d  c 程序运行, 相当于 F5

    @e   设置断点

    1027      3283  0.0  0.3 169600  7640 ?        SNsl 13:57   0:00 booster [syberos-widget]
    1027      3401  0.0  0.1  53300  3004 ?        SNs  13:57   0:00 booster [syberos-service]
    1027      5654  1.4  0.9 192928 17848 ?        SNsl 14:45   0:01 booster [syberos-qt]
    经常重启的时候，booster会打log，如果是qml的，就用gdb -p 5654【sybero-qt】的进程
    syberos-widget是qwidget的
    syberos-service是serivce的

     **/
}

void EPSyberos::cmos_dbus()
{
    /**
      @a dbus-monitor 只能监听 system 总线上的信号,不能监听到方法, 可以加  --print-reply 来输出,
        如果dbus 调用不了接口,那么要考虑权限的问题
      @a dbus-monitor --system
      @a dbus-monitor --session


        dbus-send --session --type=method_call --dest=test.dbus.service /test test.dbus.interface.adaptorTestDbus
        dbus-send --session --type=method_call --dest=test.dbus.service /test test.dbus.interface.adaptorTestDbus
        dbus-send --system --type=method_call --print-reply  --dest=cn.cmos.antitheft /antitheft cn.cmos.antitheft.AtGetRemoteNum
        dbus-send --system --print-reply --dest=com.syberos.blacklistd / com.syberos.blacklistd.substituteMdmViolationList array:string:"13601207729", array:string:"1"
     @a dbus 监听信号不需要 service ,
        QDBusConnection::sessionBus().connect("",
                                          "/org/nemomobile/contacts/sqlite",
                                          "org.nemomobile.contacts.sqlite",
                                          "contactsAdded",
                                          this,SLOT(restoreCount()));

        或者是QDbusInterface ,如果用QDbusInterface, 那么 service 必须得有
        QDBusInterface *interface = new QDBusInterface("test.dbus.service", "/test",
                                                   "test.dbus.interface");

     */
}

void EPSyberos::cmos_ui_main()
{
    /**

     */
}

void EPSyberos::cmos_ui_activeCallDialog()
{
    /**
      这是更新
      resfreshStatusText()


      @a 第二路电话进来的时候,并没有走onAcitveVoiceCallChanged
     */
}

void EPSyberos::cmos_signal_order()
{
    /**
    return "active";
    return "held";
    return "dialing";
    return "alerting";
    return "incoming";
    return "waiting";
    return "disconnected";

    电话会议:   callconf

    通话结束后,manager.activeVoicecall 在onStatusChange 发出时, manager.activeVoicecall 还是有效的,
    但是 statusText 是空的, 但是当 onActiveVoicecallChanged 这个信号发出时, manager.activeVoicecall = null

    @a 程序第一次启动
    {qrc:/qml/main.qml:426} -first===========onWindowVisibleChange==========="

    @ 第一次拨打电话的提示
    {qrc:/qml/main.qml:378} -first============onStartDial=============="  开始拨打的时候,发射这个信号
    {qrc:/qml/main.qml:530} -first============onStatusChanged========="
    {qrc:/qml/main.qml:580} -first============onDataChanged========="

    alerting(目前是对方铃声响了后发射这个信号), 接听的时候
    {qrc:/qml/main.qml:177} -first============onActiveVoiceCallChanged=============="


    {qrc:/qml/main.qml:530} -first============onStatusChanged========="
    {qrc:/qml/main.qml:580} -first============onDataChanged========="
    dialing(目前是对方接听后发射这个信号)
    {qrc:/qml/main.qml:177} -first============onActiveVoiceCallChanged=============="
    {qrc:/qml/main.qml:480} -first============onDurationChange========="

    @a 挂断
    {qrc:/qml/main.qml:530} -first============onStatusChanged========="
    {qrc:/qml/main.qml:580} -first============onDataChanged========="
    {qrc:/qml/main.qml:530} -first============onStatusChanged========="
    {qrc:/qml/main.qml:580} -first============onDataChanged========="
    {qrc:/qml/main.qml:149} -first============onVoiceCallsChange=============="
    {qrc:/qml/main.qml:586} -first============onCountChanged========="
    {qrc:/qml/main.qml:177} -first============onActiveVoiceCallChanged=============="


    @b 再添加电话的提示
    {qrc:/qml/main.qml:378} -first============onStartDial=============="
    {qrc:/qml/main.qml:149} -first============onVoiceCallsChange=============="
    {qrc:/qml/main.qml:586} -first============onCountChanged========="
    {qrc:/qml/main.qml:177} -first============onActiveVoiceCallChanged=============="
    {qrc:/qml/main.qml:580} -first============onDataChanged========="
    {qrc:/qml/main.qml:149} -first============onVoiceCallsChange=============="
    {qrc:/qml/main.qml:586} -first============onCountChanged========="
    {qrc:/qml/main.qml:530} -first============onStatusChanged========="
    {qrc:/qml/main.qml:580} -first============onDataChanged========="
    {qrc:/qml/main.qml:177} -first============onActiveVoiceCallChanged=============="
    {qrc:/qml/main.qml:480} -first============onDurationChange========="

    @c 打入电话,并未接通
    {qrc:/qml/main.qml:149} -first============onVoiceCallsChange=============="
    {qrc:/qml/main.qml:586} -first============onCountChanged========="
    {qrc:/qml/main.qml:177} -first============onActiveVoiceCallChanged=============="
    {qrc:/qml/main.qml:410} -first===========onWindowCreate==========="
    {qrc:/qml/main.qml:410} -first===========onWindowCreate==========="
    {qrc:/qml/main.qml:530} -first============onStatusChanged========="
    {qrc:/qml/main.qml:580} -first============onDataChanged========="
    {qrc:/qml/main.qml:149} -first============onVoiceCallsChange=============="
    {qrc:/qml/main.qml:586} -first============onCountChanged========="
    {qrc:/qml/main.qml:177} -first============onActiveVoiceCallChanged=============="

    @c 打入电话,接通
    {qrc:/qml/main.qml:149} -first============onVoiceCallsChange=============="
    {qrc:/qml/main.qml:586} -first============onCountChanged========="
    {qrc:/qml/main.qml:177} -first============onActiveVoiceCallChanged==============" incoming
    {qrc:/qml/main.qml:410} -first===========onWindowCreate==========="
    {qrc:/qml/main.qml:530} -first============onStatusChanged========="
    {qrc:/qml/main.qml:580} -first============onDataChanged========="
    {qrc:/qml/main.qml:177} -first============onActiveVoiceCallChanged==============" active
    {qrc:/qml/main.qml:530} -first============onStatusChanged========="
    {qrc:/qml/main.qml:580} -first============onDataChanged========="
    {qrc:/qml/main.qml:177} -first============onActiveVoiceCallChanged=============="  active
    {qrc:/qml/main.qml:530} -first============onStatusChanged========="
    {qrc:/qml/main.qml:580} -first============onDataChanged========="
    {qrc:/qml/main.qml:177} -first============onActiveVoiceCallChanged==============" active
    {qrc:/qml/main.qml:480} -first============onDurationChange========="

    拨出电话的时候,activeVoicecall 是 null, 等待状态变为alerting 后, activeVoicecall才被初始化
    @a  拨打10086 没有响铃的场景,
    {qrc:/qml/main.qml:384} -first============onStartDial=============="
    {qrc:/qml/main.qml:536} -first============onStatusChanged========="
    {qrc:/qml/main.qml:586} -first============onDataChanged========="
    {qrc:/qml/main.qml:177} -first============onActiveVoiceCallChanged=============="
    {qrc:/qml/main.qml:178} -first======activeVoicecall==== VoiceCallHandler(0xb74de270)"
    {qrc:/qml/main.qml:181} -first=====statusText======= active"
    {qrc:/qml/main.qml:536} -first============onStatusChanged========="
    {qrc:/qml/main.qml:586} -first============onDataChanged========="
    {qrc:/qml/main.qml:177} -first============onActiveVoiceCallChanged=============="
    {qrc:/qml/main.qml:178} -first======activeVoicecall==== VoiceCallHandler(0xb74de270)"
    {qrc:/qml/main.qml:181} -first=====statusText======= active"
    {qrc:/qml/main.qml:486} -first============onDurationChange========="

    @a 拨打18515065244
    {qrc:/qml/main.qml:384} -first============onStartDial=============="
    {qrc:/qml/main.qml:536} -first============onStatusChanged========="
    {qrc:/qml/main.qml:586} -first============onDataChanged========="
    {qrc:/qml/main.qml:177} -first============onActiveVoiceCallChanged=============="
    {qrc:/qml/main.qml:178} -first======activeVoicecall==== VoiceCallHandler(0xb74de270)"
    {qrc:/qml/main.qml:181} -first=====statusText======= alerting"

    {qrc:/qml/main.qml:536} -first============onStatusChanged========="
    {qrc:/qml/main.qml:586} -first============onDataChanged========="
    {qrc:/qml/main.qml:177} -first============onActiveVoiceCallChanged=============="
    {qrc:/qml/main.qml:178} -first======activeVoicecall==== VoiceCallHandler(0xb74de270)"
    {qrc:/qml/main.qml:181} -first=====statusText======= active"
    {qrc:/qml/main.qml:536} -first============onStatusChanged========="
    {qrc:/qml/main.qml:586} -first============onDataChanged========="
    {qrc:/qml/main.qml:177} -first============onActiveVoiceCallChanged=============="
    {qrc:/qml/main.qml:178} -first======activeVoicecall==== VoiceCallHandler(0xb74de270)"
    {qrc:/qml/main.qml:181} -first=====statusText======= active"
    {qrc:/qml/main.qml:486} -first============onDurationChange========="

     */
}

void EPSyberos::cmos_ui_activeCallDialog_addBlacklist()
{
    /**
    {
        if(manager.voiceCalls.count == 1)
        {
            manager.activeVoiceCall.hangup();
        } else
        {
            for(var i = 0; i< manager.voiceCalls.count; i++)
            {
                if(manager.voiceCalls.instance(i).statusText == 'incoming')
                {
                    manager.voiceCalls.instance(i).hangup();
                    gToast.requestToast(qsTr("Add to BlackList") + gAppTranslate.transflag,"", "");
                    return;
                }
            }

            for(var i = 0; i < callListModel.count; i++)
            {
                if(callListModel.get(i).Handler == "callconf")
                {
                    for(var j = 0; j < manager.voiceCalls.count; j++)
                    {
                        if(confMember.get(0).Handler == manager.voiceCalls.instance(j).handlerId)
                        {
                            manager.voiceCalls.instance(j).hangup();
                        }
                    }
                }
            }
        }

        gToast.requestToast(qsTr("Add to BlackList") + gAppTranslate.transflag,"", "");
    }

     */
}

void EPSyberos::cmos_permission()
{
    /**
     @a 远程号码的service接口 com.syberos.antitheft
     /etc/dbus-1/system.d/cn.cmos.antitheft.conf

     @a ofono /ril_0 org.ofono.Phonebook  GetSimPhonebookCount


     如何判断有没有权限:
     先看执行程序的 用户和群 ,比如执行程序的用户名是 service 和 systemapps,
     先切换到 service 用户下,通过dbus-send 测试一下,看看有没有结果,如果还是
     没有权限,

     */
}

void EPSyberos::cmos_spec_pro()
{
    /**
     @a 如果src.pro 文件里添加了 PKGCONFIG += Qt5Contacts, 那么需要在voicecall.spec
        文件中添加:

        BuildRequires: pkgconfig(Qt5Contacts)

        PS: 在本地机器上,不需要改spec文件也可以编译过,那是因为本地的SDK里已经安装了 Qt5Contacts 这个包.
        所以能编译过.

        但是在GBS上,每一次编译,都要依赖spec, 根据spec文件的BuildRequires这个节点的内容, 安装对应的包.
        所以如果spec 文件不添加,而pro文件里有,那么就会导致GBS上编译不过.

        GBS上每一次编译相当与搭建一个SDK环境,环境需要安装的包有spec文件决定.


        BuildRequires: pkgconfig(commhistory-qt5)

        Requires: libcommhistory-qt5-declarative
     */
}

void EPSyberos::cmos_key()
{
    /**
     @a 手机返回键 Qt::Key_Back  值为16777313

     @a 手机菜单键 Qt::Key_Menu  值为16777301

     @a 手机Home键 Qt::Key_Home
     */
}

void EPSyberos::google()
{
    /**
     google 搜索文件下载
     index of ubuntu 12.04
     */
}

void EPSyberos::sb2_env()
{
    /**
     每一个VirtualBox里面的系统都要安装 增强功能
     /srv/cmos/targets/cmos-target-armv7tnhl/etc/xdg/qtchooser
     这个目录下有设置sb2 编译时用的qt版本, 修改default.conf 文件.

     ln -s qt5.conf  default.conf

     安装包过程中,如果报错,错误信息是某些路径文件没有,可以手动的创建.


     libpulse-mainloop-glib  pulseaudio-devel

     有时候安装不成功可以ref一下,然后再安装

     magic 文件的问题
     用/usr/share/magic  代替 /parentroot/srv/..../usr/share/magic


     */
}

void EPSyberos::andriod_env()
{
    /**
    @ virtualbox 要想识别usb ，需要安装扩展包
        要么在preference里，要么在setting里
        把本机的用户添加到 vboxuser 这个组中（修改 /etc/group）。

    @ virtualbox 虚拟机中设置共享文件，但是没有权限，需要在虚拟机系统中把当前用户添加到 vboxuser这个组中（/etc/group).

     配置安卓开发环境.
    @a virtual device
        http://blog.csdn.net/wwbmyos/article/details/8660929

    @a 安装jdk
     sudo apt-get install openjdk-7-jre

    @a 解决adb 的问题, 因为是64位的系统,需要安装32位的库
      sudo apt-get install -y libc6-i386 lib32stdc++6 lib32gcc1 lib32ncurses5 lib32z1

    链接设备:
    需要虚拟机能链接android设备, 用lsusb 查看.
    配置下面的设备文件.
    @a /etc/udev/rules.d
    // http://blog.csdn.net/wangjia55/article/details/7986840
    http://rnmichelle.blog.51cto.com/2729211/766052/

    sudo ./adb shell 提示错误.
    error: device unauthorized. Please check the confirmation dialog on your device.
    这个信息是需要在手机的提示框中,点击确定,手机就把权限交给adb ,adb 就可以链接手机.(这里涉及权限问题)

    搭建android开发环境.
    @a  下载 adt
    @a  安装 jdk

     */
}

void EPSyberos::android_compile()
{
    /**
      http://www.mobiletrain.org/lecture/doc/android/2011-04/389.html

        source build/envsetup.sh
        lunch   (choose sp9838aea_5mod-userdebug )
        sudo apt-get install gnupg

        sudo apt-get install  flex

        sudo apt-get install  bison

        sudo apt-get install  gperf

        sudo apt-get install  build-essential

        sudo apt-get install  zip

        sudo apt-get install  curl

        sudo apt-get install  libc6-dev

        sudo apt-get install  libncurses5-dev:i386

        sudo apt-get install  x11proto-core-dev

        sudo apt-get install  libx11-dev:i386

        sudo apt-get install  libreadline6-dev:i386

        sudo apt-get install  g++-multilib

        sudo apt-get install  mingw32

        sudo apt-get install  tofrodos

        sudo apt-get install  python-markdown

        sudo apt-get install  libxml2-utils

        sudo apt-get install  xsltproc

        sudo apt-get install  zlib1g-dev:i386

        sudo apt-get install flex

        sudo apt-get gperf

        make

        jni
        /home/xkd/tmp/Android_Src/frameworks/base/services/core/jni/onLoad.java


      */
}

void EPSyberos::kernel_compile()
{
    /**
      http://mamicode.com/info-detail-1068054.html

      bochs
      http://www.pediy.com/kssd/pediy11/123767.html
      */
}

void EPSyberos::ios_env()
{
    /**screenLockChanged
    sudo apt-get install gnustep*

    export GNUSTEP_MAKEFILES=/usr/share/GNUstep/Makefiles/

    include $(GNUSTEP_MAKEFILES)/common.make
    APP_NAME = HelloWorld
    HelloWorld_HEADERS =
    HelloWorld_OBJC_FILES = main.m
    HelloWorld_RESOURCE_FILES =
    include $(GNUSTEP_MAKEFILES)/application.make

*/
}

void EPSyberos::syberos_sdk()
{
    /**
      @ 要当前用户安装，查看 .ssh 目录下的文件

      @ 虚拟机的网络地址要配置对

      @ 报错 ./Syberos_SDK/builders
           把.config/VirtualBox/Syberos_SDK 这个文件删除了

screenLockChanged
         zypper ref
         zyper --no-gpg-check in syberos-qt

      */
}

void EPSyberos::forget()
{
    /**
      @a 黑名单图标

      @a 合并通话的挂断通话 的高度

      @a 合并通话里面挂断的图标

      */
}

void EPSyberos::voicecall_Tp()
{
    /**
    @Tp
    Tp::Features
    Tp::Farstream
    Tp::StreamedMediaChannel
    Tp::StreamedMediaChannelPtr
    Tp::ChannelPtr
    Tp::CallChannelPtr
    Tp::Client
    Tp::ServicePoint
    Tp::PendingOperation
    Tp::PendingChannelRequest
    Tp::LocalHoldState
    Tp::LocalHoldStateReason

      */
}

void EPSyberos::git_push_id()
{
    /**
      @commit id

        @a  安卓端手动assert，切换到元心端，注网成功时，状态栏会显示“通话结束”持续一秒
        04cffc7bb495ce23f1b4616d791a49375138e1e6

        @a 修改来电接听的动画效果
        c1f391c3815e8848fe5efb81757ed5ec19efda8f


      */

}

void EPSyberos::contact_rebuild()
{
    /**
      contact 重构
      @a 联系人更新时，目前是先删除，后添加。
      -->  不删除，只是修改信息，然后根据信息排序，最后dataChanged

      @b 数字开头的联系人排序，比如 123， 231，这个要如何排序？（displayLable）

      @c 存联系人时，输入名字存在firstName， lastName为空， displayLabel 为 firstName + lastName;
      如果没有firstName， 则把号码为当做firstName来用。

      @a 联系人排序，名字一样的要放在一起

      @a 所有的model共用同一套数据（单例类），daemon下面的默认按名字排序，如果需要别的排序，把所有联系人传给用户自己排序。
      */
}

void EPSyberos::bochs_configure()
{
    /**
      http://os.51cto.com/art/201407/446838_all.htm

      http://www.cppblog.com/coreBugZJ/archive/2011/04/03/143334.aspx
      http://blog.chinaunix.net/uid-23817499-id-3418083.html

      sudo apt-get install bochs-x
      display_library: sdl


      */
}

void EPSyberos::qmlError()
{
    /**
    如果报异步渲染错误时， qspnode的，可能跟Loader的异步属性相关，修改一下第一个Loader

    Item
    {
        Item{
            Loader{}
        }
        // first
        Loader{}
    }
      */
}

void EPSyberos::install_sublime()
{
/**

   sudo apt-get install graphviz

  {
         "cmd": ["java", "-jar", "/home/xkd/download/plantuml.jar", "-charset", "utf-8", "-tpng", "$file"],
  }

  */
}


void EPSyberos::years()
{
    /**
      @module

      配置CC版本的开发环境
      配置release1.5 的开发环境
      编写API（syberos-qt）
      修改Framework2.0
      confd（settings）API接口调整（syberos-native）
      VoiceCall2.0的UI界面修改
      单元测试
      blacklist，voicecall，syberos-qt 的sessionBus改systemBus

      @bug
      [id] 14538  14211 14463 14430 13560 13559

      ***********************
      2015-09-16
      @bug
      [id] 17161 17163 17185 17183 17257

      @新功能
      MDM violation   contact概要设计
      在黑名单中添加了
      checkMDM substituteMDMViolation  getMDMs 三个接口， 已经在voicecall-manager, contact 进程中调用了addViolation 的上报接口

      2015-09-21
      @bug
      [id] 17339 17029 17364, 17344,17347, 17368

      weak40
      @bug
      xuanwu:

      @bug 10-08
      xuanwu: 17562  17564 17497 17573 17723 17724 17725 17713 17714 17715 17482
      17755 17756 17757 17792  17568  17704 17708 17709 17825 17822 17814 17821 17826 17751 17753
      17754 17776 17777 17778  17811 17904
      拨号盘输入号码时， t9model匹配结果显示
      ps: xuanwu 分支中， /data/system/blacklist 目录不能读写。（在做MDM时）
      完成MDM号码匹配策略，定义调用接口。

      @warning
      1、敏感权限的问题导致不能保存联系人，不能拨号。（原因是dbus不能调用）。


      weak42
      @bug
      17979 18028 17782 18041 18083  18107 18192 18209 18189 18211
      18219 18218 18158 18268 18269  17933 17934 17936 18190

      weak43
      @bug
      18363  18265 18371 18046  18497 18590 18375 18559(重要) 18599 18540 18517 18591 18600 18732

      加密通话


      @weak44
      UED提出的联系人详情页体验
      1、点击头像体验
      2、下拉、上拉的动画体验

      @bug
      18394 18870 18730 18820 18704 18392 18944 18682 18943 18998 18956 18973  18401 18387 19024 19059 19027 19280 19316
      18380 18383 17781 19272 19279 18993 19457 19562 18565 19141 19146 19149  19793
      */
}


void EPSyberos::need_to_do()
{
    /**
      @a voicecall启动的时候,检查 voicecall-manager 是否还在通话,如果在通话,
         则把voicecall的见面 show 出来.

      @a 把联系人的 sim 卡的导入和 vcard 的导入导出功能都放到 blacklist 上.
         黑名单可以有两个service, 其中一个和以前 sim, vcard 依赖的service是一样的,
         这样就比尔就可以不用修改也能用.

      @a WorkerThread

      @a voicecall 后台不在运行着，等有电话来了后在启动


      @a 20151026
            MDM_CONTACTID    不显示在联系人的字段中
            vcard 加载联系人时，等正在加载的提示框隐藏后在显示。

      @a 20151027
           联系人三个页签的title 慢慢消失（150ms）（点击搜索）
           无联系人ICON
           刚刚启动联系人时， 联系人页签窗口跳动，先是白屏，然后无联系人icon， 最后显示联系人（大量联系人）
           联系人头像点击时，先放大，后正常。  （finish）
           新建联系人（查询内存是否大于20M）
           号码通
           push replace

           1、联系人长按进入编辑状态时，整个列表往上走，取消时，整个列表往下走

     @a  os2.1
     联系人加载或者删除时，目前是一条一条的删除，每删除一条，就发山一次remove信号，这样每次都要刷新，响应，
     导致程序比较慢，可以考虑批量伤处  。

     加载model的时候，可以先加载联系人的model，然后在加载t9model， favoriteModel。
    真正的update

    联系人名字比较长，可以拖动

     */
}
