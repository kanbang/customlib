#include "LPQt.h"

LPQt::LPQt()
{
    /**
     http://qt-project.org/

     @ QWidget是一个窗口，在这个窗口上，可以添加框架QFrame以及QScrollBar(滚动棒）

     forever = for(;;)

     ***********************/
}

void LPQt::libraryAndProSettings()
{
    /**
      @ 调用自己写的程序库。
        工程map里面是一个EPmapView的继承QWidget的类，现生成一个动态库
        现在要在useMap工程中调用EPmapView这个类。
        首先，在useMap的pro文件中添加动态库路径
        LIBS += -L /home/xkd/workNotes/Libs/useMap (map生成的动态库放在这个路径下，这行语句指定
        动态库的搜索路径，最好些绝对路径）
        LIBS += -lmap1 (添加map1这个动态库）
        在useMap中，#include <EP,不会自动出现#include <EPmapVIew.h>,这是需要在pro文件中添加语句
        INCLUDEPATH += ../map (搜索map中 .h 的路径

        当在程序运行时，程序提醒错误是因为找不到某个库，那就说明没有添加这个库的路径。要在
        LD_LIBRARY_PATH环境变量中添加。
        一般情况下要在当前用户下的.bash_profile里加。
        export LD_LIBRARY_PATH=....;
    ************************/
}

void LPQt::signalSlot()
{
    /**
     @ 对于QComboBox对象来说，当在QComboBox选项中移动鼠标来选择item时，发射的是highlighted信号，
       当选中items中的某一个item时，发射的是activated信号。

     @ 对于QMenu对象来说，当在QMenu选项中移动鼠标选择item时，发射的hovered信号，当选中items中的某一个item时，发射的是triggered信号。

*/
}

void LPQt::aboutProFile(bool /*moreDetail*/)
{
    /**
     在QT中，有一个工具qmake可以生成一个makefile文件，它是由.pro文件生成而来的，.pro文件的写法如下：
1. 注释
    从“#”开始，到这一行结束。

2. 指定源文件
    SOURCES = *.cpp
    对于多源文件，可用空格分开，如：SOURCES = 1.cpp 2.cpp3.cpp
    或者每一个文件可以被列在一个分开的行里面，通过反斜线另起一行，就像这样:
    SOURCES = hello.cpp
     main.cpp
    一个更冗长的方法是单独地列出每一个文件，就像这样：
    SOURCES+= hello.cpp
    SOURCES +=main.cpp
    这种方法中使用“+=”比“=”更安全，因为它只是向已有的列表中添加新的文件，而不是替换整个列表。

3. 指定头文件
    HEADERS = hello.h或者HEADERS += hello.h
    列出源文件的任何一个方法对头文件也都适用。

4. 配置信息
    CONFIG用来告诉qmake关于应用程序的配置信息。
    CONFIG+= qt warn_on release
    在这里使用“+=”，是因为我们添加我们的配置选项到任何一个已经存在中。这样做比使用“=”那样替换已经指定的所有选项是更安全的。
    A> qt部分告诉qmake这个应用程序是使用Qt来连编的。这也就是说qmake在连接和为编译添加所需的包含路径的时候会考虑到Qt库的。
    B> warn_on部分告诉qmake要把编译器设置为输出警告信息的。
    C> release部分告诉qmake应用程序必须被连编为一个发布的应用程序。在开发过程中，程序员也可以使用debug来替换release

5. 指定目标文件名
    TARGET = filename
    如果不设置该项目，目标名会被自动设置为跟项目文件一样的名称

6. 添加界面文件(ui)
    INTERFACES = filename.ui

7. 平台相关性处理
    我们在这里需要做的是根据qmake所运行的平台来使用相应的作用域来进行处理。
    为Windows平台添加的依赖平台的文件的简单的作用域看起来就像这样：
    win32 {
    SOURCES += hello_win.cpp
    }
    所以如果qmake运行在Windows上的时候，它就会把hello_win.cpp添加到源文件列表中。
    如果qmake运行在其它平台上的时候，它会很简单地把这部分忽略。

8. 如果一个文件不存在，停止qmake
    如果某一个文件不存在的 时候，你也许不想生成一个Makefile。我们可以通过使用exists()函数来检查一个文件是否存在。
    我们可以通过使用error()函数把正在运 行的qmake停下来。这和作用域的工作方式一样。
    只要很简单地用这个函数来替换作用域条件。对main.cpp文件的检查就像这样：
    !exists( main.cpp ) {
     error( "No main.cpp file found")
    }
    “!”用来否定这个测试，比如，如果文件存在，exists( main.cpp)是真，如果文件不存在，!exists( main.cpp )是真。

9. 检查多于一个的条件
    假设你使用Windows并且当你在命令 行运行你的应用程序的时候你想能够看到qDebug()语句。
    除非你在连编你的程序的时候使用console设置，你不会看到输出。我们可以很容易地把 console添加到CONFIG行中，
    这样在Windows下，Makefile就会有这个设置。
    但是如果告诉你我们只是想在当我们的应用程序运行在 Windows下并且当debug已经在CONFIG行中的时候，
    添加console。这需要两个嵌套的作用域；只要生成一个作用域，然后在它里面再生成 另一个。把设置放在最里面的作用域里，就像这样：
    win32 {
     debug {
     CONFIG += console
      }
    }
    嵌套的作用域可以使用冒号连接起来，像这样：
    win32:debug {
    CONFIG += console
    }

10. 摸板
    模板变量告诉qmake为这个应用程序生成哪种makefile。下面是可供使用的选择：
    A> app -建立一个应用程序的makefile。这是默认值，所以如果模板没有被指定，这个将被使用。
    B> lib - 建立一个库的makefile。
    C> vcapp - 建立一个应用程序的VisualStudio项目文件。
    D> vclib - 建立一个库的VisualStudio项目文件。
    E> subdirs -这是一个特殊的模板，它可以创建一个能够进入特定目录并且为一个项目文件生成makefile并且为它调用make的makefile。

11. 生成Makefile
    当你已经创建好你的项目文件，生成Makefile就很容易了，你所要做的就是先到你所生成的项目文件那里然后输入：
    Makefile可以像这样由“.pro”文件生成：
    qmake -oMakefile hello.pro
    对于VisualStudio的用户，qmake也可以生成“.dsp”文件，例如：
    qmake -tvcapp -o hello.dsp hello.pro


 Qt pro工程文件 介绍

    分类：Qt/C++

    app - 建立一个应用程序的makefile。这是默认值，所以如果模板没有被指定，这个将被使用。

    lib - 建立一个库的makefile。

    vcapp - 建立一个应用程序的Visual Studio项目文件。

    vclib - 建立一个库的Visual Studio项目文件。

    subdirs - 这是一个特殊的模板，它可以创建一个能够进入特定目录并且为一个项目文件生成makefile并且为它调用make的makefile。

    “app”模板
    “app”模板告诉qmake为建立一个应用程序生成一个makefile。当使用这个模板时，下面这些qmake系统变量是被承认的。
    你应该在你的.pro文件中使用它们来为你的应用程序指定特定信息。

    HEADERS - 应用程序中的所有头文件的列表。

    SOURCES - 应用程序中的所有源文件的列表。

    FORMS - 应用程序中的所有.ui文件（由Qt设计器生成）的列表。

    LEXSOURCES - 应用程序中的所有lex源文件的列表。

    YACCSOURCES - 应用程序中的所有yacc源文件的列表。

    TARGET - 可执行应用程序的名称。默认值为项目文件的名称。（如果需要扩展名，会被自动加上。）

    DESTDIR - 放置可执行程序目标的目录。

    DEFINES - 应用程序所需的额外的预处理程序定义的列表。

    INCLUDEPATH - 应用程序所需的额外的包含路径的列表。

    DEPENDPATH - 应用程序所依赖的搜索路径。

    VPATH - 寻找补充文件的搜索路径。

    DEF_FILE - 只有Windows需要：应用程序所要连接的.def文件。

    RC_FILE - 只有Windows需要：应用程序的资源文件。

    RES_FILE - 只有Windows需要：应用程序所要连接的资源文件。

    CONFIG变量
    配置变量指定了编译器所要使用的选项和所需要被连接的库。配置变量中可以添加任何东西，但只有下面这些选项可以被qmake识别。

    下面这些选项控制着使用哪些编译器标志：

    release - 应用程序将以release模式连编。如果“debug”被指定，它将被忽略。

    debug - 应用程序将以debug模式连编。

    warn_on - 编译器会输出尽可能多的警告信息。如果“warn_off”被指定，它将被忽略。

    warn_off - 编译器会输出尽可能少的警告信息。

    下面这些选项定义了所要连编的库/应用程序的类型：

    qt - 应用程序是一个Qt应用程序，并且Qt库将会被连接。

    thread - 应用程序是一个多线程应用程序。

    x11 - 应用程序是一个X11应用程序或库。

    windows - 只用于“app”模板：应用程序是一个Windows下的窗口应用程序。

    console - 只用于“app”模板：应用程序是一个Windows下的控制台应用程序。

    dll - 只用于“lib”模板：库是一个共享库（dll）。

    staticlib - 只用于“lib”模板：库是一个静态库。

    plugin - 只用于“lib”模板：库是一个插件，这将会使dll选项生效。

    例如，如果你的应用程序使用Qt库，并且你想把它连编为一个可调试的多线程的应用程序，你的项目文件应该会有下面这行：

    CONFIG += qt thread debug注意，你必须使用“+=”，不要使用“=”，否则qmake就不能正确使用连编Qt的设置了，
    比如没法获得所编译的Qt库的类型了。



    qmake高级概念
    操作符

    “=”操作符      分配一个值给一个变量
    “+=”操作符     向一个变量的值的列表中添加一个值
    “-=”操作符      从一个变量的值的列表中移去一个值
    “*=”操作符      仅仅在一个值不存在于一个变量的值的列表中的时候，把它添加进去
    “~=”操作符      替换任何与指定的值的正则表达式匹配的任何值 DEFINES ~= s/QT_[DT].+/QT
    作用域
    win32:thread {
        DEFINES += QT_THREAD_SUPPORT
    } else:debug {
        DEFINES += QT_NOTHREAD_DEBUG
    } else {
        warning("Unknown configuration")
    }
    变量
    到目前为止我们遇到的变量都是系统变量，比如DEFINES、SOURCES和HEADERS。你也可以为你自己创建自己的变量，
    这样你就可以在作用域中使用它们了。创建自己的变量很容易，只要命名它并且分配一些东西给它。比如：

    MY_VARIABLE = value你也可以通过在其它任何一个变量的变量名前加$$来把这个变量的值分配给当前的变量。例如：

    MY_DEFINES = $$DEFINESMY_DEFINES = $${DEFINES}
    第 二种方法允许你把一个变量和其它变量连接起来，而不用使用空格。qmake将允许一个变量包含任何东西（包括$(VALUE)，
    可以直接在 makefile中直接放置，并且允许它适当地扩张，通常是一个环境变量）。
    无论如何，如果你需要立即设置一个环境变量，然后你就可以使用$$()方法。 比如：

    MY_DEFINES = $$(ENV_DEFINES)这将会设置MY_DEFINES为环境变量ENV_DEFINES传递给.pro文件地值。
    另外你可以在替换的变量里调用内置函数。这些函数（不会和下一节中列举的测试函数混淆）列出如下：

    join( variablename, glue, before, after )
    这 将会在variablename的各个值中间加入glue。如果这个变量的值为非空，那么就会在值的前面加一个前缀before和一个后缀after。
    只 有variablename是必须的字段，其它默认情况下为空串。如果你需要在glue、before或者after中使用空格的话，你必须提供它们。

    member( variablename, position )
    这将会放置variablename的列表中的position位置的值。如果variablename不够长，这将会返回一个空串。
    variablename是唯一必须的字段，如果没有指定位置，则默认为列表中的第一个值。

    find( variablename, substr )
    这将会放置variablename中所有匹配substr的值。substr也可以是正则表达式，而因此将被匹配。

    MY_VAR = one two three four
    MY_VAR2 = $$join(MY_VAR, " -L", -L) -Lfive
    MY_VAR3 = $$member(MY_VAR, 2) $$find(MY_VAR, t.*)
    MY_VAR2将会包含“-Lone -Ltwo -Lthree -Lfour -Lfive”，并且MYVAR3将会包含“three two three”。

    system( program_and_args )
    这将会返回程序执行在标准输出/标准错误输出的内容，并且正像平时所期待地分析它。比如你可以使用这个来询问有关平台的信息。

    UNAME = $$system(uname -s)    contains( UNAME, [lL]inux ):message( This looks like Linux ($$UNAME) to me )测试函数
    qmake提供了可以简单执行，但强大测试的内置函数。这些测试也可以用在作用域中（就像上面一样），在一些情况下，忽略它的测试值，
    它自己使用测试函数是很有用的。

    contains( variablename, value )
    如果value存在于一个被叫做variablename的变量的值的列表中，那么这个作用域中的设置将会被处理。例如：

    contains( CONFIG, thread ) {        DEFINES += QT_THREAD_SUPPORT    }如果thread存在于CONFIG变量的值的列表中时，
    那么QT_THREAD_SUPPORT将会被加入到DEFINES变量的值的列表中。

    count( variablename, number )
    如果number与一个被叫做variablename的变量的值的数量一致，那么这个作用域中的设置将会被处理。例如：

    count( DEFINES, 5 ) {        CONFIG += debug    }error( string )
    这个函数输出所给定的字符串，然后会使qmake退出。例如：

    error( "An error has occured" )文本“An error has occured”将会被显示在控制台上并且qmake将会退出。

    exists( filename )
    如果指定文件存在，那么这个作用域中的设置将会被处理。例如：

    exists( /local/qt/qmake/main.cpp ) {        SOURCES += main.cpp    }如果/local/qt/qmake/main.cpp存在，
    那么main.cpp将会被添加到源文件列表中。

    注意可以不用考虑平台使用“/”作为目录的分隔符。

    include( filename )
    项目文件在这一点时包含这个文件名的内容，所以指定文件中的任何设置都将会被处理。例如：

    include( myotherapp.pro )myotherapp.pro项目文件中的任何设置现在都会被处理。

    isEmpty( variablename )
    这和使用count( variablename, 0 )是一样的。如果叫做variablename的变量没有任何元素，那么这个作用域中的设置将会被处理。例如：

    isEmpty( CONFIG ) {        CONFIG += qt warn_on debug    }message( string )
    这个函数只是简单地在控制台上输出消息。

    message( "This is a message" )文本“This is a message”被输出到控制台上并且对于项目文件的处理将会继续进行。

    system( command )
    特定指令被执行并且如果它返回一个1的退出值，那么这个作用域中的设置将会被处理。例如：

    system( ls /bin ) {        SOURCES += bin/main.cpp        HEADERS += bin/main.h    }所以如果命令ls /bin返回1，
    那么bin/main.cpp将被添加到源文件列表中并且bin/main.h将被添加到头文件列表中。

    infile( filename, var, val )
    如果filename文件（当它被qmake自己解析时）包含一个值为val的变量var，那么这个函数将会返回成功。
    你也可以不传递第三个参数（val），这时函数将只测试文件中是否分配有这样一个变量var。

    以下为我的一个项目举例
    # 项目目标：为一个库文件

    TEMPLATE = lib# 编译项目文件所需头文件的路径INCLUDEPATH += ../common .
    # 目标文件路径DESTDIR=../lib# 条件依赖：Unix平台上 定义本想目的 UI目录， MOC目录，
    目的目录unix {  UI_DIR = ../.ui  MOC_DIR = ../.moc  OBJECTS_DIR = ../.obj}
    # 本项目配置：CONFIG         += qt warn_on release thread

    qmake 可以生成Makefile文件
    make 编译
    使用qmake -project时，会把本目录及其子目录内所有.cpp .h文件加入到项目输入文件中，使用是注意移去其他无用的文件。
    qmake生成的Makefile文件，可以根据需要做相应修改

*/
}

void LPQt::aboutqmake()
{
    /**
      @a  编译出来的库是没有符号的,会导致链接的时候报  symbol undefined 的错误提示
      CONFIG += hide_symbols

      @b  在pro文件,这样写,程序运行的时候,会到 /usr/lib/qt5/qml/org/nemomobile/contacts/
          下找库
      QMAKE_LFLAGS  += -Wl,-rpath,/usr/lib/qt5/qml/org/nemomobile/contacts/

      @c  指定程序通过pkgconfig来链接库,前提是得有对应的pc 文件 ,可以通过find / -name "*.pc" 文件查看

          CONFIG += link_pkgconfig
          PKGCONFIG += qtcontacts-sqlite-extensions
     */
}

void LPQt::aboutProFile()
{
    /**
     @ Qt工程文件pro中的DEFINES的作用
       告诉qmake编译器，如果程序中已经定义了
       #ifndef PI
       #define PI
       ...
       #else
       ...
       #endif
       如果在pro文件中
       DEFINES += PI,则告诉qmake，定义了PI，那么执行的是#else后面的语句。
       用+=号是累加，比如原来就已经#define P了，现在要定义另一个预处理PI，
       则是有#define了两个P，PI。
       +=号的功能和环境变量中的(PATH ＝ $(PATH):/lib) 的冒号(:)的功能类似。

    @  Qt程序一般使用Qt提供的qmake工具来编译。

    qmake工具可以使用与平台无关的.pro文件生成与平台相关的makefile。
    该工具包含了调用Qt内置代码生成工具（moc，uic，rcc）的必要逻辑规则。



    可以在命令行下，输入qmake -project来生成平台无关的pro文件。

    工程文件pro主要分为三种：app（单独的应用程序），lib（静态和动态库），subdirs（递归编译）。
    工程类型可以使用TEMPLATE变量来指定。

    如： TEMPLATE = app(默认不指定的情况下是app工程)



    对于app工程或者lib工程，有以下这些经常使用的变量：

    HEADERS：指定C++头文件

    SOURCES：指定C++实现文件

    FORMS：指定需要uic处理的ui文件

    RESOURCES：指定需要rcc处理的qrc文件

    DEFINES：指定预定义预处理器符号

    INCLUDEPATH：指定C++编译器搜索头文件路径

    LIBS：指定工程要链接的库

    CONFIG：指定工程配置和编译参数

    QT：指定工程所要使用的Qt模块

    VERSION：指定目标库版本号

    TARGET：指定可执行文件或库的基本文件名，默认为当前目录名

    DESTDIR：指定可执行文件放置的目录

    DLLDESTDIR：指定目标库文件放置的目录





    CONFIG：指定工程配置和编译参数

    以下对CONFIG变量做主要介绍:

    debug：编译有调试信息的可执行文件或则库

    release：编译不具有调试信息可执行文件或者库（如果同时指定debug release时，只有debug有效）

    warn_off：关闭大量警告,默认是打开的

    qt：指应用程序使用Qt

    dll:动态编译库

    staticlib：静态编译库

    plugin：编译一个插件

    console：应用程序需要写控制台

    当我们写CONFIG变量时，可以使用

    如：CONFIG = qt release warn_off

    或者CONFIG = qt

          CONFIG += release

          CONFIG += warn_off

    当想要移除某个设置时：CONFIG -= warn_off





    在pro文件里，可以使$$varName或者$${varName}来访问自己定义的变量，如

    MyVersion = 1.2

    FILE = 1.cpp

    TARGET = improve$${MyVersion}

    SOURCES = $$FILE



    pro文件里，访问环境变量的用法是：$(varName)

    pro文件里，访问Qt配置参数的用法：$$[varName]



    在不同的编译平台上编译时，需要设定条件。如：

    win32{

     SOURCES += 1.cpp

    }else{

     SOURCES += 2.cpp

    }

    或者

    win32：SOURCES += 3.cpp


     */
}

void LPQt::xmlTagName()
{
    /**
      QDomDocument 解析的xml文件，xml文件的节点名不能有空格。同时，开头第一个字符只能是字符和下划线。

      **/
}

void LPQt::errorInRun()
{
    /**
     @ Failed to start program. Path or permissions wrong?
       如果出现这样的错误，查看 "Projects"->"Run Settings"->"Executable".
       可能是路径下没有执行文件了

     @ has virtual functions but non-virtual-destructor
       出现这样的错误是因为里面有虚函数，但是析够函数的前面没有关键字 virtual.

     @ collect2: ld returned 1 exit status
       这样的错误一般都是因为有函数没有定义（遇到过的有虚函数和槽函数没有定义时出现这样的报错），或者是指针开辟内存的问题。

     @ expected class-name before ‘{’ token
       #include 头文件的问题。
       如果是#include 的问题，那么要注意 class EPmapItem;和#include <EPmapItem.h>的区别。
       如果两个头文件f1.h和f2.h互相包含，这时候可能会出错。因为互相包含，不能确定大小和类(type)。

       解决的方法是： 在f1.h中用class 类声明f2.h中的类，在f2.h中用class 类声明f1.h中的类。
                   不能在f1.h中用#include <f2.h>，在f2.h中用 #include <f1.h>

       还有可能是objectName和类名不一致的问题

     @ field ‘xxx’ has incomplete type
        class A; // incomplete type
        A* a;     // no error.
        A  b;     // error. b的大小无法确定。

        class A { int c; }
        A  d;     // no error. 类型已完成，d的大小可以确定了。

    **/

}

void LPQt::staticCompile()
{
    /**
    TEMPLATE = app
    TARGET = setup
    DEPENDPATH += . ../src ../.uidir
    INCLUDEPATH += . ../src ../.uidir
    DESTDIR = ../bin
    OBJECTS_DIR = ../.obj
    MOC_DIR = ../.moc
    RCC_DIR = ../.rcc
    UI_DIR = ../.uidir
    CONFIG += warn_on

    # Input
    FORMS += ../src/setupwizard.ui

    HEADERS += ../src/setupwizard.h \
            ../src/LoPManager.h \
            ../src/LoPInstaller.h \
            ../src/LoPUninstaller.h \
            ../src/LoPBuilder.h

    SOURCES += ../src/setupwizard.cpp \
            ../src/LoPManager.cpp \
            ../src/LoPInstaller.cpp \
            ../src/LoPUninstaller.cpp \
            ../src/LoPBuilder.cpp \
            ../src/installermain.cpp

    RESOURCES += ../setupwizard.qrc

    MYOBJECTS = ../.obj/setupwizard.o \
                ../.obj/LoPManager.o \
                ../.obj/LoPInstaller.o \
                ../.obj/LoPUninstaller.o \
                ../.obj/LoPBuilder.o \
                ../.obj/installermain.o \
                ../.obj/moc_setupwizard.o \
                ../.obj/moc_LoPInstaller.o \
                ../.obj/moc_LoPUninstaller.o \
                ../.obj/moc_LoPBuilder.o \
                ../.obj/qrc_setupwizard.o

    QTSTATICLIBS = $(QTDIR)/lib/libQtGui.a $(QTDIR)/lib/libQtCore.a
    QMAKE_POST_LINK=g++ -m64 -Wl,-rpath,$(QTDIR)/lib -o ../bin/setup $$MYOBJECTS $$QTSTATICLIBS -L/usr/X11R6/lib64
                    -L/usr/lib64 -lpng -lSM -lXrender -lfontconfig -lXext -lgthread-2.0 -lrt -lgobject-2.0

     */
}

void LPQt::aboutWidgetEvent()
{
    /**
      @ 窗口事件传递机制，见 EPDragDrop.cpp Line 35-36.

      @ 在mousePressEvent(QMouseEvent *)事件中，可以有event->button() == Qt::LeftButton;
        但是在，当按着鼠标左键移动的时候，mouseMoveEvent()事件中的event->button() 不一定等于 Qt::LeftButton;
        可以在mousePressEvent()事件中让一个bool型等于true，然后在mouseMoveEvent（）中作if （ bool），
        而不是if (event->button = Qt::LeftButton)

      @ bool EventFilter::eventFilter(QObject *watched,QEvent *event)
        {
         if (watched==Label1)
         {
         if (event->type()==QEvent::MouseButtonPress)
         {
            QMouseEvent *mouseEvent=static_cast<QMouseEvent *>event;
            if (mouseEvent->buttons() && Qt::LeftButton)
            {  // 更换一张大一点的图片    ..........
            }
         if (event->type()==QEvent::MouseButtonRelease)
         {    // 重新换回最初那张图片 ...........
         }
         return QWidget::eventFilter(watched,event);
        }
        **/
}

void LPQt::designerUi()
{
    /**
      @ 从外部导入ui文件，要考虑到objectName；
      **/
}

void LPQt::relationWidgetAndLayout()
{
    /**
      @ 要在QMainWindow中添加QWidget，可以new QWidget(this)添加

      @ 也可以用布局QLayout添加

      @ Qt布局窗口有这几个
        QHBoxLayout,QVBoxLayout,QGridLayout,QStackLayout
        可以执行布局管理器功能的其他类还有
        QSplitter,QScrollArea,QMainWindow,QMdiArea.
        这些类提供了一种用户可以灵活掌控的布局方式

        QGridLayout::addWidget(QWidget*,int row,int column,int spanRow,int Spancolumn)
        QGridLayout的工作是基于一个二维单元格，在这个布局中，布局的左上角的位置为(0,0)。、
        每一列的宽度是等于该列的宽度最大的部件的宽度

      **/
}

void LPQt::aboutQPainter()
{
    /**
      @ QPainter 可以不在paintEvent()中使用。如下（见EPView构造函数以及EPWindowPra）：
      @ 这种叫像素映射。
    QPixmap pixmap1(scene->sceneRect().size().width(),scene->sceneRect().size().height());
    pixmap1.load(":/AdesHelp.png");
    QPainter painter(&pixmap1);
    painter.initFrom(this);
    painter.setPen(Qt::red);
    painter.drawLine(0,0,400,200);
    scene->addPixmap(pixmap1);

    @ 这里要想画出来，要把QPixmap的大小设置和QRect一样。 问题来自EPlogTrackPayZone::paint(QPainter* painter, EPmapView* view);
    painter->drawPixmap(QRect r, QPixmap p);
    **/
}

void LPQt::aboutWidgetCoordinate()
{
    /**
      QWidget *widget = new QWidget;
      QPushButton *pb = new QPushButton(widget);
      widget->setGeometry(100,100,400,400);

      此处是一个窗口左上角为（0，0）.
      pb->setGeometry(400,400,60,20);
      widget->show();

      ************************************************
      窗口和设备有关，代表的是整个区域。
      视口是一部分，就是整个区域的一部分。视口类似于相机。你通过视口来看窗口。
      QPainter绘图，有三个坐标转换：
      @ 默认的坐标转换：
        以窗口的左上角为（0，0）。
      @ setWindow(-100,-100,200,200)
        以窗口的左上角为（-100,-100),右下角为（100，100),不管你怎么改变窗口的大小，窗口里面的内容都不变，只是进行缩放.
      @ setViewport()
        视口里面的内容是固定的，所以当你改变窗口大小时，窗口的内容会改变，不会缩放.
      @ setWorldMatrix(const QWMatrix &m, bool combine = false)

      @ translate()

      @ scale()

      @ shear()

      @ rotate()
      **/
}

void LPQt::aboutParentWidgetPointManager()
{
    /**
     \brief
     把一个widget作为另一个widget的父对象，那么父对象就会把子widget作为自己的一部分组合在一起。

     但是要是把一个widget作为QDialog的父对象就不会。
     */
}

void LPQt::aboutCompile()
{
    /**
      @ 在编译的时候出错，可以在compile output看看为什么出错。
      */
}

void LPQt::aboutQPixmapGrabWidget()
{
    /**
      @ QPixmap pixmap;
        QPixmap pix = pixmap.grabWidget(window,0,0,400,400);
        pix.save("pixmap","png");
        ********/
}

void LPQt::programToExe()
{
    /**

    http://www.cr173.com/html/15231_1.html
    *****

      @ 把程序转为exe文件，在windows下把qt中的lib文件放在当前目录下就可以。
      @ 如果是在linux下，要设置LD_LIBRARY_PATH的路径,把库的路径添加进来

      *************************/
}

void LPQt::runWithLib()
{
    /**
      @ 运行程序生成lib(库)的时候，要指定哪个程序来调用。
        指定了后，下次再运行这个库，会自动调用指定的执行文件（在Qt中运行）

      ****************/
}

void LPQt::output()
{
    /**
      @ QTextStream out(stdout, QIODevice::WriteOnly)
        out<<QString(); 如果不加endl，则不会显示结果
      ***********************/
}

void LPQt::input()
{
    /**
     @ QTextStream cin(stdin, QIODevice::ReadOnly);
       QTextStream cout(stdout, QIODevice::WriteOnly);
       QTextStream cerr(stderr, QIODevice::WriteOnly);
       **********/
}

void LPQt::useVariableInOtherFile()
{
    /**
      @ 在f1.cpp 中有一个全局变量 int global = 10; 如果想在f2.cpp中使用它，
        则在f2.cpp使用extern，同时还要包含f1.cpp(#include <f1.cpp>  例如：
        int  extern global 或者 extern int global;

        ****************/
}

void LPQt::thread()
{
    /**
      @ 在Qt中，一个QPushButton对象btn响应函数onButton()运行耗时（由于此时btn获得响应，因此再点击别的部件
        ，部件不会有响应）。为了解决这类问题，可以在onButton()函数中 thread（QThread的对象）.start()
        (运行一个进程)，然后在进程的run()函数中实现onButton的运行耗时的语句。

        connect(btn,SIGNAL(clicked()),this,SLOT(onButton()));
        void onButton()
        { thread.start();}

        void run()
        {
            运行比较耗时的程序。
        }
        QThread 有两个对象a，b。在run()函数中用mutex.lock();....;mutex.unlock();
        如果先a.start();则此时，run只能被a调用，b要想调用，得等a运行到mutex.unlock();

        在linux中，文件是可以同时被打开几份的，也可以同时修改。但是保存的时候最后一次保存的会把先前的全部覆盖掉。
        在windows中，文件则不能同时被打开几份，除了第一份有“读写”的功能，其他的都是有“只读”功能
      ********************/
}

void LPQt::paintInPaintEvent()
{
    /**
      @ QPainter::begin: Widget painting can only begin as a result of a paintEvent
        要避免这个问题可以设置你要画图的那个widget的一个属性，加上类似这样的代码
        this->setAttribute(Qt::WA_PaintOutsidePaintEvent);

        但是只支持X11
        */
}

void LPQt::ScrollBarVisibleEnabled()
{
    /**
      @ 如何设置滚动棒，如果以QGraphicsView作为主窗口，如果QGraphicsView的大小比QMainWindow的大。
        但是滚动棒的效果并没有生效。但是如果把QGraphicsScene加入到QGraphicsView中，则滚动棒会生效。
      @ 对于QAbstractScrollArea，在其paintEvent(QPaintEvent *)函数中，要调用QPainter，这要在其
        视口上绘图。QPainter painter(viewport());如果想滚动棒生效，一般是使用painter.translate(-滚动棒的x值，-滚动棒的y值)
      *****************/
}

void LPQt::pixmapContainsCursor()
{
    /**
      @ 图形都有一个形状区域，获得这个区域调用contains函数判断是否包含。

      **************/
}

void LPQt::newDelete()
{
    /**
      @ 类A 有一个QRect* r的指针，类 B 中的函数 func()中定义了一个A 的局部变量，并让A中r指针指向类B的QRect成员变量。
      void func(){
      A a;
      a.setRect(rect);  //当函数func运行结束后，会不会 delete r(具体看析构函数），也就是rect所指向的内存被delete了。
                        这时候rect这个成员变量不可用，否则程序会崩溃。
      A::~A(){
      delete r;
      }
      *********************/
}

void LPQt::aboutCodes()
{
    /**
     如果安装的Qt没有对应的编码，可以把其他的Qt的编码移到当前安装的Qt文件夹的bin文件里
     cp -rf /usr/local/Trolltech/Qt-4.6.4/plugins/codecs/ .   （.代表的是 ./bin)
     */
}

void LPQt::showChinese()
{
    /**
        用QPainter 在窗口中显示drawText画中文，要转换编码。比如下面的：
        QTextCodec *codec = QTextCodec::codecForName("GB18030");
        QString str = codec->toUnicode("淡淡的");

        QSettings settings("/home/xkd/mySoft",QSettings::IniFormat);
        settings.setIniCodec("utf8");
        settings.setValue("width",QObject::tr("xingkongdao"));
        qDebug()<<settings.value(QString("width"));

        @ 或者是这样
        QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
      **************/
}

void LPQt::background()
{
    /**
     \brief  true为有背景颜色，false为默认
        QLabel::setAutoFillBackground(false);

    */
}

void LPQt::aboutDebug()
{
    /**
     @brief 在Qt中，如果调试发现有QString和QList的值没有显示出来。
            需要依序安装这个几个软件，
            expat-2.0.1.tar.gz , Python-2.7.tar, gdb-7.5.tar.gz
     */
}

void LPQt::assignmentReason()
{
    /**
     \brief 关于赋值出现问题的原因
     @  可能在该类的拷贝构造函数中有些成员变量没有赋值

     */
}

void LPQt::aboutToolBarDoubleClick()
{
    /**
     \brief QToolBar上的菜单双击
     重新实现QToolButton这个对象，重载鼠标双击功能
     然后添加到QToolBar上 :: QToolBar::addWidget(QWidget*):
     */
}


void LPQt::aboutDataTypeTrans()
{
    /**
    QString str1 = “Test”;
    QByteArray ba = str1.toLatin1();
    const char *c_str2 = ba.data();

    这里得注意，中间的ba变量是必不可少的，不能直接用str1.toLatin1().data()。

    然后就是char*转QString：

    方法一：QString string = QString(QLatin1String(c_str2)) ;

    方法二：如果是中文系统，直接用 (const char*) str.local8Bit()
　　 例如
    　printf(“%s”, (const char*) str.local8Bit());
    　str是一个QString
     **/
}

void LPQt::Q_DECL_EXPORT()
{
    /**
      Q_DECL_EXPORT

       http://www.cnblogs.com/MuyouSome/p/3396766.html

      */
}
