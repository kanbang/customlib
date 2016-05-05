// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
    /**
    创建一个String 对象，语法：new String(stringValue),这个调用会将参数转换为字符串，并作为一个String 对象。事实上任何一个字符串常量都是一个Ｓtring对象，可以将其直接作为对象来使用，这和使用new String()创建对象的区别是：typeof的返回值不同，一个是“stirng",另一个是"object".

    string.indexOf(searchString,position)----从position（可选）位置开始，搜索字符串中的第一个searchSting所出现的位置并返回。例如："hello,jack".indexOf("hello")将返回０；
    "abcabc".indexOf("a",1)将返回３；

    string.lastIndexOf(searchString,position)--------从position(可选）位置开始，搜索字符串中的最后一个searchString所出现的位置并返回。如："abcabc".lastIndexOf("b")将返回４

    string.charAt(pos)-------返回字符串中位置为pos的字符。例如："abc".charAt(1)返回"b"

    stirng.charCodeAt(pos)------返回字符串中位置为pos的字符代码。对于ASCII 字符，这将返回其ASCII代码。例如："abc".charCodeAt(0)返回９７，表示字符"a"的ASCII码。

    string.slice(start,end)--------返回字符串中起始位置为start,结束位置为end(不包括end)的子字符串

    string.split(separator,linmit)------ 将字符串以separator作为分割符切割成多个子字符串，并将他们作为一个数组返回。linmit(可选)表示数组的最大长度，超过的部分将被舍弃。 separator分隔符不被包含在任何子字符串中，如果sepatator为空字符串，则返回字符串中的字符序列组成的数组。如果split方法没有任何参数，则返回仅包含字符串本身，仅有一个元素的数组。

    string.split(separator,linmit)-------例如："a1,b1,c1".split(",")将返回["a1","b1","c1"];

    "a,b,c".split(",",2)将返回["a","b"];

    "a,b,c".split("")将返回["a",",","b",",","c"];

    "ab,c".split()将返回["ab,c"]
    string.substr(start,length)--------返回字符串中起始位置为start,长度为length的子字符串。例如："abcdefg".substr(1,3)将返回"bcd"；

    string.substring(start,end)------返回字符串中起始位置为start,结束位置为end（包括end)的子字符串。这个方法和slice方法唯一不同体现在是否包含了end位置的字符。


    替换和匹配字符串


    （１）replace(searchValue,replaceValue)方法
                该方法将字符串中第一个出现的searchValue子字符串替换为replaceValue，并返回新的字符串。原有的字符串不受影响。

    例如：var str1="aaaa";

    var str2=str1.replace("a","b");

    alert(str2);//输出"baaa"
    alert(str1);//输出"aaaa"

    上面代码中可以看出，使用replace函数仅能替换一个实例。如果要替换多个实例，则需要使用正则表达式，例如str.replace(/a/g,"b")能够将"aaaa"替换为"bbbb".

    （２）match(reExp)方法

    从字符串中搜索出匹配regExp正则表达式的所有子字符串，将他们作为一个数组返回。利用对象类型到布尔类型的转换规则，还可以判断一个字符串是否匹配regExp表示的正则表达式。

    例如：var strInput=prompt("请输入一个数字：",0);

    while(!strInput.match(/\d+/)){
             strInput=prompt("请输入一个数字：",0);
    }

    （３）search(regExp)方法

    从字符串中搜索出匹配regExp正则表达式的第一个子字符串，返回其索引位置。例如：var str="aabcabcabc";

    alert(str.search(/abc/g));//显示“１”

    （４）String 对象的大小写转换

    var str="abc";

    str.toLowerCase()//转化小写

    str.toUpperCase()//转化大写

    （５）String 对象的连接

    var str="abc";

    var str2=str.concact("def","ghi");

    alert(str2);//将输出"abcdefghi"

  */
import QtQuick 1.1

Rectangle {
    width: 100
    height: 62
}

