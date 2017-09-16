
public class Driver {

	public static  void main(String [] args){
	Shape s1=new Circle("red",true,5.5);
	System.out.println(s1);
	System.out.println(s1.getArea());
	System.out.println(s1.getPeremiter());
	System.out.println(s1.getColor());
	System.out.println(s1.isFilled());
	//System.out.println(s1.getRadius());//Although it is upcast to type Circle, the method
	//getRadius() is not present in Class Shape, meaning it was not overridden by class Circle.
	
	Circle c1=(Circle)s1;
	System.out.println(c1);
	System.out.println(c1.getArea());
	System.out.println(c1.getPeremiter());
	System.out.println(c1.getColor());
	System.out.println(c1.isFilled());
	System.out.println(c1.getRadius());
	
	Shape s2=new Shape();
	
	Shape s3= new Rectangle("red",false,1,2);
	System.out.println(s3);
	System.out.println(s3.getArea());
	System.out.println(s3.getPeremiter());
	System.out.println(s3.getColor());
//	System.out.println(s3.getLength());//again, getLength() does not exist in Class Shape
	//Meaning it cannot be overwritten or invoked in the first place
	
	Rectangle r1=(Rectangle)s3;
	System.out.println(r1);
	System.out.println(r1.getArea());
	System.out.println(r1.getColor());
	System.out.println(r1.getLength());
	
	Shape s4=new Square(6);
	
	System.out.println(s4);
	System.out.println(s4.getArea());
	System.out.println(s4.getColor());
//	System.out.println(s4.getSide());//Same as above , the method getSide() does not exist in the superclass Shape
	
	Rectangle r2=(Rectangle)s4;
	System.out.println(r2);
	System.out.println(r2.getArea());
	System.out.println(r2.getColor());
//	System.out.println(r2.getSide());//getSide() does not exist in Rectangle. this causes an error
	System.out.println(r2.getLength());
	
	
	Square sq1=(Square)r2;
	System.out.println(sq1);
	System.out.println(sq1.getArea());
	System.out.println(sq1.getColor());
	System.out.println(sq1.getSide());//getSide() does not exist in Rectangle. this causes an error
	System.out.println(sq1.getLength());
	
	
	
	
	}
}
