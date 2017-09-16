
public class Circle extends Shape {
	protected double radius;

	public Circle() {
		super();
		radius=0;
	}

	public Circle(String color, boolean filled , double radius) {
		super(color, filled);
		this.radius=radius;
	}

	public double getRadius() {
		return radius;
	}

	public void setRadius(double radius) {
		this.radius = radius;
	}

	@Override
	public double getArea() {
		return 3.14*3.14*radius;
	}

	@Override
	public double getPeremiter() {
		
		return 2*3.14*radius;
	}

	@Override
	public String toString() {
		return "Circle [radius=" + radius + ", color=" + color + ", filled="
				+ filled + ", getArea()=" + getArea() + ", getPeremiter()="
				+ getPeremiter() + "]";
	}


	
	

}
