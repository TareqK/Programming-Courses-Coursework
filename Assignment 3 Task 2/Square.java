
public class Square extends Rectangle {

	protected double side;
	public Square()
	{
		super(0,0);
		side=0;
	}
	public Square(double side) {
		super(side,side);
		
	}

	public Square(String color, boolean filled, double side) {
		super(color, filled, side, side);

	}

	public double getSide() {
		return side;
	}

	public void setSide(double side) {
		this.side = side;
	}
	@Override
	public void setWidth(double side) {

		super.setWidth(side);
	}
	@Override
	public void setLength(double side) {

		super.setLength(side);
	}
	@Override
	public String toString() {
		return "Square [side=" + side + ", color=" + color + ", filled="
				+ filled + "]";
	}

	
	
	

}
