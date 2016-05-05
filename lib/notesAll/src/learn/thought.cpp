#include "thought.h"

thought::thought()
{
}

void thought::memory_register()
{
    /**
      程序的运行，一般需要开辟内存，有的是放在cpu的寄存器中，这样的话，存取速度比较快。
      要想变量放在cpu寄存器中，那么，需要在定义变量的时候加关键字：
      register int i = 10;

    cpu先从内存中获取数据，然后运算，运算完了后在放回内存中。

      */
}

void thought::more_effective()
{
    /**
让自己习惯C++
    \brief
    尽量以const，enum，inline替换 #define
        #define ASPNET_RATIO 1.635  作用域不一样。没有封装性
        编译器不认识ASPNET_RATIO ,因为在预处理的时候已经把ASPNET_RATIO替换成1.635了。因此一旦报错，编译器会提示1.635错了。
        每次替换后，都要开辟内存存储1.635。

        const int *p;常量指针（指针指向的地址的内容不能改变）
        int *const p; 指针常量（指针指向的地址不能改变）

        用const 可以定义class 专属常量。限制该变量只能在class的作用域内。
        为了确保常量至多只有一份，要使用静态常量：
        static const int number = 5;
        只要不去number的地址，则在类里声明并使用它，如果要生取地址，则必须要在外面另外定义，目的是要开辟内存。
        const int class::number;（不需要赋值，因为类里面已经声明并设初值了）

        #define 定义的宏可以用const或者enum替代，如果是宏函数，则可以用inline函数替代。因为他们可以安全检查。

    \brief
    尽可能使用const
        函数参数以const 引用传递，减少减少对象之间的拷贝、析构等函数调用的消耗
        函数返回const ，防止被赋值 (a*b = 1)

    \brief
    确定对象被使用前已被先初始化
    对于内置类型，则无须使用初始化列表也可以。
    初始化列表是在构造函数之前就使用了，他直接调用对象的拷贝构造函数
    QWidget w = w1；（先调用QWidget的构造函数初始化w，然后在调用拷贝构造函数赋值w）
    这样耗时比较长，如果时初始化列表，则直接调用拷贝，不需要先调用构造函数

    对引用，const类型的数据，要使用初始化列表。
    用初始化列表的目的时确保要使用的对象已经初始化了。


构造、析构、拷贝、赋值运算
    了解C++默默编写并调用那些函数
    若不想使用编译器自动生成的函数，就该明确拒绝
    为多态基类生命virtual 析构函数
    别让异常逃离析构函数
    绝不在构造和析构过程中调用virtual函数
    令 operator= 返回一个reference to *this
    在 operator= 中处理“自我赋值”
    复制对象时勿忘其每一个成分

资源管理
    以对象管理资源
    在资源管理类中小心copying 行为
    在资源管理类中提供对原始资源的访问
    成对使用new 和 delete时要采取相同形式
    以独立语句将newed 对象置入智能指针

设计与声明
    让接口容易被正确使用，不易被误用
    设计class犹如设计type
    宁以pass-by-reference-to-const 替换pass-by-value
    必须返回对象时，别妄想返回其reference
    将成员变量声明为private
    宁以non-member、non-friend替换menber函数
    若所有参数皆需类型转换，请为此采用non-member函数
    考虑写出一个不抛异常的swap函数

实现
    尽可能延后变量定义式的出现时间
    尽量少做转型动作
    避免返货handles 指向对象内部成分
    为“异常安全”而努力使值得的
    透彻了解inlining的里里外外
    将文件间的编译依赖关系降至最低

继承与面向对象设计
    确定你的public继承塑模出is-a关系
    避免遮掩继承而来的名称
    区分接口继承和实现继承
    考虑virtual函数以外的其他选择
    绝不重新定义继承而来的non-virtual函数
    绝不重新定义继承而来的缺省参数值
    通过复合塑模出has-a 或者“根据某物实现出”
    明智而审慎地使用private继承
    明智而审慎地使用多重继承

      */
}

void thought::javascript()
{
    /**
        JS自带函数
        concat
        将两个或多个字符的文本组合起来，返回一个新的字符串。
        var a = "hello";
        var b = ",world";
        var c = a.concat(b);
        alert(c);
        //c = "hello,world"
        indexOf
        返回字符串中一个子串第一处出现的索引（从左到右搜索）。如果没有匹配项，返回 -1 。
        var index1 = a.indexOf("l");
        //index1 = 2
        var index2 = a.indexOf("l",3);
        //index2 = 3
        charAt
        返回指定位置的字符。
        var get_char = a.charAt(0);
        //get_char = "h"
        lastIndexOf
        返回字符串中一个子串最后一处出现的索引（从右到左搜索），如果没有匹配项，返回 -1 。
        var index1 = lastIndexOf('l');
        //index1 = 3
        var index2 = lastIndexOf('l',2)
        //index2 = 2
        match
        检查一个字符串匹配一个正则表达式内容，如果么有匹配返回 null。
        var re = new RegExp(/^\w+$/);
        var is_alpha1 = a.match(re);
        //is_alpha1 = "hello"
        var is_alpha2 = b.match(re);
        //is_alpha2 = null
        substring
        返回字符串的一个子串，传入参数是起始位置和结束位置。
        var sub_string1 = a.substring(1);
        //sub_string1 = "ello"
        var sub_string2 = a.substring(1,4);
        //sub_string2 = "ell"
        substr
        返回字符串的一个子串，传入参数是起始位置和长度
        var sub_string1 = a.substr(1);
        //sub_string1 = "ello"
        var sub_string2 = a.substr(1,4);
        //sub_string2 = "ello"
        replace
        用来查找匹配一个正则表达式的字符串，然后使用新字符串代替匹配的字符串。
        var result1 = a.replace(re,"Hello");
        //result1 = "Hello"
        var result2 = b.replace(re,"Hello");
        //result2 = ",world"
        search
        执行一个正则表达式匹配查找。如果查找成功，返回字符串中匹配的索引值。否则返回 -1 。
        var index1 = a.search(re);
        //index1 = 0
        var index2 = b.search(re);
        //index2 = -1
        slice
        提取字符串的一部分，并返回一个新字符串（与 substring 相同）。
        var sub_string1 = a.slice(1);
        //sub_string1 = "ello"
        var sub_string2 = a.slice(1,4);
        //sub_string2 = "ell"
        split
        通过将字符串划分成子串，将一个字符串做成一个字符串数组。
        var arr1 = a.split("");
        //arr1 = [h,e,l,l,o]
        length
        返回字符串的长度，所谓字符串的长度是指其包含的字符的个数。
        var len = a.length();
        //len = 5
        toLowerCase
        将整个字符串转成小写字母。
        var lower_string = a.toLowerCase();
        //lower_string = "hello"
        toUpperCase
        将整个字符串转成大写字母。
        var upper_string = a.toUpperCase();
        //upper_string = "HELLO"

        ******************************************
        字符串函数扩充
        ******************************************

        String.prototype.LTrim = function()
        {
        return this.replace(/(^\s*)/g, "");
        }

        ===========================================
        //去除右边的空格
        ===========================================

        String.prototype.Rtrim = function()
        {
        return this.replace(/(\s*$)/g, "");
        }

        ===========================================
        //去除前后空格
        ===========================================
        String.prototype.Trim = function()
        {
        return this.replace(/(^\s*)|(\s*$)/g, "");
        }

        ===========================================
        //得到左边的字符串
        ===========================================
        String.prototype.Left = function(len)
        {

        if(isNaN(len)||len==null)
        {
        len = this.length;
        }
        else
        {
        if(parseInt(len)<0||parseInt(len)>this.length)
        {
        len = this.length;
        }
        }

        return this.substr(0,len);
        }

        ===========================================
        //得到右边的字符串
        ===========================================

        String.prototype.Right = function(len)
        {

        if(isNaN(len)||len==null)
        {
        len = this.length;
        }
        else
        {
        if(parseInt(len)<0||parseInt(len)>this.length)
        {
        len = this.length;
        }
        }

        return this.substring(this.length-len,this.length);
        }

        ===========================================
        //得到中间的字符串,注意从0开始
        ===========================================

        String.prototype.Mid = function(start,len)
        {
        return this.substr(start,len);
        }

        ===========================================
        //在字符串里查找另一字符串:位置从0开始
        ===========================================

        String.prototype.InStr = function(str)
        {

        if(str==null)
        {
        str = "";
        }

        return this.indexOf(str);
        }

        ===========================================
        //在字符串里反向查找另一字符串:位置0开始
        ===========================================

        String.prototype.InStrRev = function(str)
        {

        if(str==null)
        {
        str = "";
        }

        return this.lastIndexOf(str);
        }


        ===========================================
        //计算字符串打印长度
        ===========================================
        String.prototype.LengthW = function()
        {
        return this.replace(/[^\x00-\xff]/g,"**").length;
        }


        ===========================================
        //是否是正确的IP地址
        ===========================================
        String.prototype.isIP = function()
        {

        var reSpaceCheck = /^(\d+)\.(\d+)\.(\d+)\.(\d+)$/;

        if (reSpaceCheck.test(this))
        {
        this.match(reSpaceCheck);
        if (RegExp.$1 <= 255 && RegExp.$1 >= 0
        && RegExp.$2 <= 255 && RegExp.$2 >= 0
        && RegExp.$3 <= 255 && RegExp.$3 >= 0
        && RegExp.$4 <= 255 && RegExp.$4 >= 0)
        {
        return true;
        }
        else
        {
        return false;
        }
        }
        else
        {
        return false;
        }

        }


        ===========================================
        //是否是正确的长日期
        ===========================================
        String.prototype.isLongDate = function()
        {
        var r = this.replace(/(^\s*)|(\s*$)/g, "").match(/^(\d{1,4})(-|\/)(\d{1,2})\2(\d{1,2}) (\d{1,2}):(\d{1,2}):(\d{1,2})$/);
        if(r==null)
        {
        return false;
        }
        var d = new Date(r[1], r[3]-1,r[4],r[5],r[6],r[7]);
        return (d.getFullYear()==r[1]&&(d.getMonth()+1)==r[3]&&d.getDate()==r[4]&&d.getHours()==r[5]&&d.getMinutes()==r[6]&&d.getSeconds()==r[7]);

        }


        ===========================================
        //是否是正确的短日期
        ===========================================
        String.prototype.isShortDate = function()
        {
        var r = this.replace(/(^\s*)|(\s*$)/g, "").match(/^(\d{1,4})(-|\/)(\d{1,2})\2(\d{1,2})$/);
        if(r==null)
        {
        return false;
        }
        var d = new Date(r[1], r[3]-1, r[4]);
        return (d.getFullYear()==r[1]&&(d.getMonth()+1)==r[3]&&d.getDate()==r[4]);
        }

        ===========================================
        //是否是正确的日期
        ===========================================
        String.prototype.isDate = function()
        {
        return this.isLongDate()||this.isShortDate();
        }

        ===========================================
        //是否是手机
        ===========================================
        String.prototype.isMobile = function()
        {
        return /^0{0,1}13[0-9]{9}$/.test(this);
        }

        ===========================================
        //是否是邮件
        ===========================================
        String.prototype.isEmail = function()
        {
        return /^\w+((-\w+)|(\.\w+))*\@[A-Za-z0-9]+((\.|-)[A-Za-z0-9]+)*\.[A-Za-z0-9]+$/.test(this);
        }

        ===========================================
        //是否是邮编(中国)
        ===========================================
        String.prototype.isZipCode = function()
        {
        return /^[\\d]{6}$/.test(this);
        }

        ===========================================
        //是否是有汉字
        ===========================================
        String.prototype.existChinese = function()
        {
        //[\u4E00-\u9FA5]為漢字﹐[\uFE30-\uFFA0]為全角符號
        return /^[\x00-\xff]*$/.test(this);
        }

        ===========================================
        //是否是合法的文件名/目录名
        ===========================================
        String.prototype.isFileName = function()
        {
        return !/[\\\/\*\?\|:"<>]/g.test(this);
        }

        ===========================================
        //是否是有效链接
        ===========================================
        String.prototype.isUrl = function()
        {
        return /^http[s]?:\/\/([\w-]+\.)+[\w-]+([\w-./?%&=]*)?$/i.test(this);
        }

        ===========================================
        //是否是有效的身份证(中国)
        ===========================================
        String.prototype.isIDCard = function()
        {
        var iSum=0;
        var info="";
        var sId = this;

        var aCity={11:"北京",12:"天津",13:"河北",14:"山西",15:"内蒙古",21:"辽宁",22:"吉林",23:"黑龙 江",31:"上海",32:"江苏",33:"浙江",34:"安徽",35:"福建",36:"江西",37:"山东",41:"河南",42:"湖 北",43:"湖南",44:"广东",45:"广西",46:"海南",50:"重庆",51:"四川",52:"贵州",53:"云南",54:"西藏",61:"陕西",62:"甘肃",63:"青海",64:"宁夏",65:"新疆",71:"台湾",81:"香港",82:"澳门",91:"国外"};

        if(!/^\d{17}(\d|x)$/i.test(sId))
        {
        return false;
        }
        sId=sId.replace(/x$/i,"a");
        //非法地区
        if(aCity[parseInt(sId.substr(0,2))]==null)
        {
        return false;
        }

        var sBirthday=sId.substr(6,4)+"-"+Number(sId.substr(10,2))+"-"+Number(sId.substr(12,2));

        var d=new Date(sBirthday.replace(/-/g,"/"))

        //非法生日
        if(sBirthday!=(d.getFullYear()+"-"+ (d.getMonth()+1) + "-" + d.getDate()))
        {
        return false;
        }
        for(var i = 17;i>=0;i--)
        {
        iSum += (Math.pow(2,i) % 11) * parseInt(sId.charAt(17 - i),11);
        }

        if(iSum%11!=1)
        {
        return false;
        }
        return true;

        }

        ===========================================
        //是否是有效的电话号码(中国)
        ===========================================
        String.prototype.isPhoneCall = function()
        {
        return /(^[0-9]{3,4}\-[0-9]{3,8}$)|(^[0-9]{3,8}$)|(^\([0-9]{3,4}\)[0-9]{3,8}$)|(^0{0,1}13[0-9]{9}$)/.test(this);
        }

        ===========================================
        //是否是数字
        ===========================================
        String.prototype.isNumeric = function(flag)
        {
        //验证是否是数字
        if(isNaN(this))
        {

        return false;
        }

        switch(flag)
        {

        case null:        //数字
        case "":
        return true;
        case "+":        //正数
        return                /(^\+?|^\d?)\d*\.?\d+$/.test(this);
        case "-":        //负数
        return                /^-\d*\.?\d+$/.test(this);
        case "i":        //整数
        return                /(^-?|^\+?|\d)\d+$/.test(this);
        case "+i":        //正整数
        return                /(^\d+$)|(^\+?\d+$)/.test(this);
        case "-i":        //负整数
        return                /^[-]\d+$/.test(this);
        case "f":        //浮点数
        return                /(^-?|^\+?|^\d?)\d*\.\d+$/.test(this);
        case "+f":        //正浮点数
        return                /(^\+?|^\d?)\d*\.\d+$/.test(this);
        case "-f":        //负浮点数
        return                /^[-]\d*\.\d$/.test(this);
        default:        //缺省
        return true;
        }
        }

        ===========================================
        //是否是颜色(#FFFFFF形式)
        ===========================================
        String.prototype.IsColor = function()
        {
        var temp        = this;
        if (temp=="") return true;
        if (temp.length!=7) return false;
        return (temp.search(/\#[a-fA-F0-9]{6}/) != -1);
        }

        ===========================================
        //转换成全角
        ===========================================
        String.prototype.toCase = function()
        {
        var tmp = "";
        for(var i=0;i<this.length;i++)
        {
        if(this.charCodeAt(i)>0&&this.charCodeAt(i)<255)
        {
        tmp += String.fromCharCode(this.charCodeAt(i)+65248);
        }
        else
        {
        tmp += String.fromCharCode(this.charCodeAt(i));
        }
        }
        return tmp
        }

        ===========================================
        //对字符串进行Html编码
        ===========================================
        String.prototype.toHtmlEncode = function()
        {
        var str = this;

        str=str.replace(/&/g,"&amp;");
        str=str.replace(/</g,"&lt;");
        str=str.replace(/>/g,"&gt;");
        str=str.replace(/\'/g,"&apos;");
        str=str.replace(/\"/g,"&quot;");
        str=str.replace(/\n/g,"<br>");
        str=str.replace(/\ /g,"&nbsp;");
        str=str.replace(/\t/g,"&nbsp;&nbsp;&nbsp;&nbsp;");

        return str;
        }

        ===========================================
        //转换成日期
        ===========================================
        String.prototype.toDate = function()
        {
        try
        {
        return new Date(this.replace(/-/g, "\/"));
        }
        catch(e)
        {
        return null;
        }
        }
      */
}

void thought::virtualFunction()
{
    /**


class Point
{
public:
    virtual void get(){
        qDebug()<<Q_FUNC_INFO;
    }

    int m_x;
    int m_y;
};

void test()
{
    qDebug()<<Q_FUNC_INFO;
}

typedef void(*pFun)();

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);

    Point point;

    void(* pfun)();
    pFun p=&test;

    p();
    qDebug()<<"p1 = "<<&test<<" == "<<p;
    p = (pFun)*(int*)*(int*)(&point);
    qDebug()<<"p = "<<p;
    p();
    return 0;
//    return a.exec();
}


      */
}
