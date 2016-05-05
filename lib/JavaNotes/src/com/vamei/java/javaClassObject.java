/**
 类的定义语法： 
 [public][abstract | final] class className [extends superclassName ]
											[implements interfaceNameList]
 其中，修饰符 public ， abstract， final 说明了类的属性（省略即为 public），className 为类名， 
 superclassName为类的父类的名字， interfaceNameList 为类所实现的接口列表
 
 访问控制符： public、 private、protected、default
 访问控制符对于整个程序段是非常关键的，当需要让自己编写的这个类，被所有的其他类所公共拥有时，可以将类的访问控制符写为“public”。
 当需要让自己的类，只能被自己的包中的类所共同拥有时，就将类的访问控制符改为“default”。
 
 super 关键字
  相当于调用 父类的方法。 QWidget::mousePressEvent(e);
  super 关键字的功能：
  	点取父类中被子类隐藏了的数据成员
  	点取已经覆盖了的方法
  	作为方法名表示父类构造函数（方法） Widget（QWidget *parent = 0）{ super（parent）；}
	注意：无论是 super 还是 this，都必须放在构造方法的第一行。
	
 instanceof 运算符功能： 用来判断某个实例变量是否属于某种类的类型。 相当于 dynamic_cast
 
 final 关键字：
 	final 标记
 */

package com.vamei.java;


public class javaClassObject {

}
