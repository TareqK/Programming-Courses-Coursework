import java.util.Date;


public class Employee extends Person {
	protected double salary;
	protected Date dateHired;
	protected Office office;
	
	public Employee()
	{
		super();
		salary=1500;
		dateHired=new Date();//default constructor for date used
		office=new Office();
		
	}
	public Employee(String name,String address,String email,String phoneNumber,double salary,Office office)
	{
		super(name,address,email,phoneNumber);
		this.dateHired=new Date();
		this.salary=salary;
		this.office=office;
	}
	public double getSalary() {
		return salary;
	}
	public void setSalary(double salary) {
		this.salary = salary;
	}
	public Date getDateHired() {
		return dateHired;
	}
	public void setDateHired(Date dateHired) {
		this.dateHired = dateHired;
	}
	public Office getOffice() {
		return office;
	}
	public void setOffice(Office office) {
		this.office = office;
	}
	
	public String toString() {
	
		return("name: "+name+"\nAddress: "+address+"\nEmail: "+email+"\nNumber: "+phoneNumber+"\nSalary: "+salary+"\nOffice: "+office.toString()+"\nDate Hired: "+dateHired.toString());
	}
	
	
	
	

}
