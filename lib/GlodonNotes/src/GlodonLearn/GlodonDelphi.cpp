#include "GlodonDelphi.h"

GlodonDelphi::GlodonDelphi()
{
    /**
      @ 注释

      @ 新的过程和函数特征
        @ 圆括号
        @ 重载
        @ 缺省值参数

      @ 变量

      @ 常量

      @ 运算符
        @ 赋值运算符
        @ 比较运算符
        @ 逻辑表达式
        @ 算术运算符
        @ 按位运算符
        @ 加减运算过程

      @ Object Pascal类型
        @ 类型的比较
        @ 字符
        @ 字符串
        @ 变体类型
        @ Currency

      @ 用户自定义类型
        @ 数组
        @ 动态数组
        @ 记录
        @ 集合
        @ 对象
        @ 指针
        @ 类型别名

      @ 强制类型转换盒类型约定

      @ 字符串资源

      @ 测试条件
        @ if 语句
        @ case 语句

      @ 循环
        @ for 循环
        @ while 循环
        @ repeat...until
        @ Break()过程
        @ Continue()过程

      @ 过程和函数

      @ 作用域

      @ 单元
        @ uses 语句
        @ 循环单元引用

      @ 包
        @ 使用Delphi的包
        @ 包的语法

      @ 面向对象编程

      @ 使用Delphi对象
        @ 声明和实例化
        @ 析构

      @ 方法
        @ 方法的类型
        @ 属性
        @ 可见性表示符
        @ 友类
        @ 对象的秘密
        @ TObject : 所有对象的祖先
        @ 接口

      @ 结构化异常处理
        @ 异常类
        @ 执行的流程
        @ 重新触发异常

      @ 运行期类型信息

      @ 总结
      */

}

void GlodonDelphi::delphi_object_pascal_type()
{
    delphi_char();
    delphi_string();
    /**
    @ Object Pascal特点
        数据类型特别严谨，传递给函数的实参必须和函数或过程定义的形参的类型完全相同，
        不可能出现类型转换的警告信息， void指针除外


      */
}

void GlodonDelphi::delphi_window()
{
    /**

    @ TForm

    @ TApplication

    @ TScreen


      */
}

void GlodonDelphi::delphi_create_window()
{
    /**
    @ 如何创建一个单元文件的窗口，同时把这个窗口放心另一个自定义的窗口上

    //  Unit3.pas
        Uses
            Unit1;

        TForm3.FormMouseDown(....)
        var
            tmp : TForm1; //TForm1 实在Unit1里面定义的
        begin
            tmp := TForm1.Create(Form3); //也可以用Self
            tmp.Parent := Form3;
            tmp.Show;
        end;

      */
}

void GlodonDelphi::delphi_constructor()
{
    /**
    @ 为了给对象分配内存，可以调用 Create 对象方法。这是一种构造器，
      可以用于类中，是为该类的实例分配内存的特殊对象方法。实例由构造器返回，
      为了储存对象以备后用，可以将它赋给变量。 默认的TObject.Create
      构造器会将新实例的所有数据初始化为零

    @ 用户可以自定义构造器，构造器可以命名为 Create ，或者其他任何名称：
      只需在该名称前使用 constructor 关键字即可。 这样就不调用TObject.Create



      */
}

void GlodonDelphi::delphi_class_object()
{
    /**
    @ 类，一种用户自定义的数据类型

    @ Delphi中函数的声明是在interface里的，函数的定义是在 implementation 里的


      */
}

void GlodonDelphi::delphi_unit()
{
    /**
    @ 单元是组成Pascal程序的单独的源代码模块，单元由函数和过程组成，这些函数
      和过程被主程序调用。

    @ 一个单元包含三个部分：
        @ 一个 unit 语句
            每一个单元都必须在开头有这样的一条语句，用来识别单元的名称，
            名称必须和文件名一样。如果一个文件的名字为 FooBar，则，unit
            语句可能是： unit FooBar；

        @ interface 部分，在 unit 后面的源代码必须是 interface 语句
            interface 和 implementation 语句之间的信息能被其他单元和程序共享。
            这部分是声明类型、常量、变量、过程和函数的地方，这些能被主程序和其他单元
            调用，这里只有声明。 interface 要占一行。

        @ implementation 它在 interface 的后面。
            可以在此声明不被其他单元所调用的任何数据类型、常量和变量，这里是定义了在
            interface 声明的函数和过程。
    @ 单元可能包含其他两个部分：
        @ initialization 部分，在单元中，initialization 放在文件结尾前，它包含
            初始化单元的代码，主程序只调用一次

        @ finalization ，在单元中放在 initialization 和 end 之间。

     ************************************
     ************************************

    @ users 子句在一个程序或单元中用来列出想要包含进来的单元

    @ 有三种类型的单元文件 ：
        @ 窗体/数据模块和框架的单元文件
            由Delphi 5自动生成。每个窗体/数据模块或框架都有一个对应的单元文件。例如：
            不能让两个窗体共用一个单元文件。为了解释窗体文件，我们不在窗体、数据模块和
            框架之间进行区分

        @ 组件的单元文件
            有程序员或Delphi 5 创建新的组件时生成的

        @ 通用的单元文件
            有程序员创建的，用于声明在应用程序中要访问的数据类型、变量、过程、类等

      */
}

void GlodonDelphi::delphi_project()
{
    /**
      @ Delphi 的工程文件的后缀名为：      *.dpr
      @ Delphi 的单元文件的后缀名为：      *.pas
      @ Delphi 的窗体文件的后缀名为：      *.dfm
      @ Delphi 的资源文件的后缀名为：      *.res
      @ Delphi 的项目选项文件的后缀名为：    *.dof
      @ Delphi 桌面设置文件的后缀名为：     *.dsk
      @ Delphi 项目文件的备份文件的扩展名是： .~dp
      @ Delphi 单元文件的备份文件的扩展名为： .~pa

      *********************
      @ 当创建一个窗体时，系统自动创建一个窗体文件(扩展名为 *.dfm)和一个单元文件(扩展名为 *.pas)
        dfm文件是脚本化的文件，其中定义了窗体的外观、尺寸、位置 等属性信息

        编译过的单元是不可执行的，以 *.dcu 为扩展名(有些类似库)。在建立应用程序链接阶段，所有的 .dcu
        文件被链接成为可执行程序
      @ begin ... end 之间的语句是应用程序要执行的主代码。
      */
}

void GlodonDelphi::delphi_char()
{
    delphi_object_pascal_type();
    delphi_string();
    /**
      \brief 三种类型字符

      @ AnsiChar    一个字节

      @ WideChar    两个字节

      @ Char 在目前相当于AnsiChar，以后的版本中相当于WideChar

      */
}

void GlodonDelphi::delphi_string()
{
    delphi_object_pascal_type();
    delphi_char();
    /**
    @ 字符串是代表一组字符的变量类型，每一种语言都有自己的字符串类型的存储和使用方式。

        @ AnsiString 这是Pascal缺省的字符串类型，它是有AnisChar字符组成，
          没有长度限制，同时与null结束的字符串相兼容

        @ ShortString 保留该类型是为了向后兼容Delphi 1.0， 它的长度限制在
          255个字符内

        @ WideString 功能上和AnsiString相似，但它是由WideChar字符组成的。

        @ PChar 指向null结束的Char字符串指针，类似于 C 中的 char *或者 lpstr
          类型

        @ PAnsiChar 指向null结束的AnsiChar字符串指针

        @ PWideChar 指向null结束的WideChar字符串指针

        通常情况下，如果像下面这样定义一个变量，编译器默认为AnsiString字符串 ：

            var
                S:string ; //编译器认为S的类型为AnsiString

            var
                {$H-}
                 S1 : string ; // S1 是ShortString类型
                {$H+}
                 S2 : string ; // S2是AnsiString类型

            var
            S:string[63];       // 63个字符的ShortString字符串

      */
}

void GlodonDelphi::delphi_compile_grammar()
{
    /**
    @ { $H- } 编译器开关

    @ { $R *.RES }
        告诉编译器去链接一个资源文件，该资源文件与项目文件相同，但扩展名为 .res ,这个文件包含程序图标和版本信息


    @ {$APPTYPE CONSOLE}  说明该程序是控制台程序

        可以用这个语句代替  USE语句、 {$R *.RES} 、Application.Initialize、 Application.Run.

    @ {$IFDEF DEBUG} 是否定义了一个特殊的字符 DEBUG

    @   {$IF one }

        {$ELSEIF two }

        {$ELSE}

        {$IFEND}


      */
}
