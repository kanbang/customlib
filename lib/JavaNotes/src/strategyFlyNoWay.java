
public class strategyFlyNoWay implements strategyFlyBehavior {
	public void fly() {
		System.out.println(this.toString());
	}
}

class strategyFlyWithWings implements strategyFlyBehavior {
	public void fly() {
		System.out.println(this.toString());
	}
}