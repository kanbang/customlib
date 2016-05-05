
/**
 可以新建一个包，在包里面写代码，包的使用是用 import 某个包的。
 import com.vamei.xingkd.* 表示 import  ./com/vamei/xingkd/ 下的所有文件。
 如果想只是导入一个文件，那么可以这么用：
 import com.vamei.xingkd.Human;
 
 也可以不用使用 import com.vamei.xingkd.*;
 但是定义对象的时候，就得把路径写了。
 com.vamei.xingkd.Human aPerson = new com.vamei.xingkd.Human(180);
 */
import com.vamei.xingkd.*;
import com.vamei.java.*;

import java.awt.*;

import javax.swing.JFrame;
public class epmain {
	/**
	 * @param args 
	 */
	public static void main(String[] args){
		strategyDuck obj = new MallardDuck();
		
		obj.display();
		obj.performFly();
		obj.performQuack();
		obj.swim();
		
		Human aPerson = new Human(180); 
		System.out.println(aPerson.getHeight());
		
//		JFrame jf = new JFrame();
//		jf.setSize(400, 200);
//		jf.show();
		
//		Adder adder = new Adder();
		
//		Reflect.test();
		
//		javaNetwork.testDownNetFile();
		
		int[] value = {100};
		changeValue(value);
		System.out.println(value); 
		
		System.out.println("邢孔导");
		
		show();
	}
	
	public static void changeValue(int[] value)
	{
		value[0] = 4;
	}
	
	private static void show()
	{
		System.out.println("xingkongdao");
	}
}


