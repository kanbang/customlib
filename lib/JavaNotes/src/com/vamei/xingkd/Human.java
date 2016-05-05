/**
 *如果包没有放在当前工作路径下，我们在使用包时，需要通知Java。比如，
 *我们将包放在/home/vamei/javapackage中，
 *这样Human.class位于/home/vamei/javapackage/com/vamei/society/Human.class，
 *而我们的工作路径为/home/vamei。这样，包就无法被找到。一个方法是在使用javac和java时，
 *用-classpath说明包所在的文件夹路径，比如:

 $javac -classpath /home/vamei/javapackage:. TestAgain.java

 $java -classpath /home/vamei/javapackage:. TestAgain

  就是从/home/vamei/javapackage和工作路径(.)中寻找包。
  Java可以从/home/vamei/javapackage中可以找到Human类，
  从.中可以找到TestAgain类。

另外也可以设置系统的CLASSPATH环境变量，将上述路径加入到该变量中，
而不用每次都键入-classpath选项。
 */
package com.vamei.xingkd;

public class Human {
	
	public Human(int h)
	{
		this.height = h;
		System.out.println("I'm born");
	}
	
	public int getHeight()
	{
		return this.height;
	}
	
	public void growHeight(int h)
	{
		this.height = this.height + h;
	}
	private int height;

    /*
     * static method, access population
     */
    public static int getPopulation()
    {
        return Human.population;
    }

    private static int population;
    private static boolean is_mammal = true;
}
