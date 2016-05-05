#include "java.h"

java::java()
{
/**

    文件名：Hello.java

    package com.test;
    public class Hello
    {
     public static void main(String args[])
     {
     String str = "版本1： hello, welcome to chinaasp java 技术";
     System.out.println(str);
     }
    }

    Hello.java保存在D:\Java目录

    编译时使用

    javac Hello.java -d .\

    刚在当前目录按照源码中的包设置建立目录，并将字节码文件放在里面，即生成D:\Java\com\test\Hello.class

    运行时可在D:\Java路径下使用

    java com.test.Hello

    即可。
*/
}

void java::package()
{
        /**
    在dog目录下创建一个 dog.java 文件，dog.java 文件开头要有package dog。
    看javac的路径在哪里。 比如：
    ～ 下javac， 那就写package dog；
    如果dog 目录是在 ～/one/dog 的。那么dog.java 开头要写package one.dog;
    */
}

void java::jni_compile()
{
    /**

     必须要在src 目录下
    javah  -jni com.example.hellojni.MainActivity

    @project dir
        javah -classpath src -jni com.example.hellojni.MainActivity


      */
}
