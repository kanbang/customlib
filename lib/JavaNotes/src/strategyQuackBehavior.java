
public interface strategyQuackBehavior {
	public void quack();
}

class strategyQuack implements strategyQuackBehavior {
	public void quack() {
		System.out.println(this.toString());
	}
}

class strategyMuteQuack implements strategyQuackBehavior {
	public void quack() {
		System.out.println(this.toString());
	}
}