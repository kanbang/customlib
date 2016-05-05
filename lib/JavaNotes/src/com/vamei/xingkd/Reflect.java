package com.vamei.xingkd;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.lang.reflect.*;

public class Reflect {
	public static void test()
	{
		ReflectExample reflect = new ReflectExample();
		Class tmp = reflect.getClass();
		
		System.out.println(reflect.getClass());
		
		try
		{
			System.out.println("反射类中所有的公有属性");
			Field[] fields = tmp.getFields();
			for(int i = 0; i < fields.length; i++)
			{
				Class<?> item = fields[i].getType();
				System.out.println("all public Fields " + item);
			}
			
			System.out.println();
			
			System.out.println("反射类中所有的属性");
			
			Field[] fa = tmp.getDeclaredFields();
			for(int i = 0; i< fa.length; i++)
			{
				Class<?> item = fa[i].getType();
				System.out.println("all Fields " + item);
			}
			
			System.out.println();
			
			System.out.println("反射类中私有的属性");
			
//			Field f = tmp.getDeclaredField("ReflectExample" );  
			//是否有权限访问反射类中的私有属性
//			f.setAccessible(true);
//			Integer i = (Integer)f.get(reflect);  
//			System.out.println(i);
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}		
	}
	public static void test_1()
	{
		
	}
}

class ReflectExample extends Object implements ActionListener
{
	private int m_value = 3;
	public  Integer m_num = new Integer(4);
	
	ReflectExample() {}
	ReflectExample(int value, String name)
	{
		m_num = m_value*value;
	}
	
	public void actionPerformed(ActionEvent e)
	{
		System.out.println("ReflectExample::actionPerformed(ActionEvent e)");
	}
	
	static void test()
	{
		
	}
}
