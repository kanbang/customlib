
public abstract class strategyDuck {
	strategyFlyBehavior _fly;
	strategyQuackBehavior _quack;
	public strategyDuck(){}
	
	public abstract void display();
	
	public void setFly(strategyFlyBehavior fly) {
		_fly = fly;
	}
	
	public void setQuack(strategyQuackBehavior quack) {
		_quack = quack;
	}
	
	public void performFly() {
		_fly.fly();
	}
	
	public void performQuack() {
		_quack.quack();
	}
	
	public void swim() {
		System.out.println("All the Ducks float , even decoys");
	}
}

class MallardDuck extends strategyDuck {
	public MallardDuck() {
		_fly = new strategyFlyWithWings();
		_quack = new strategyQuack();
	}
	public void display() {
		System.out.println(this.toString() + " I'm a real Mallard Duck !");
	}
}



















