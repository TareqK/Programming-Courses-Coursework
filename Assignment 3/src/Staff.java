
public class Staff extends Employee {
	
	protected String title;
	
	public String getTitle() {
		return title;
	}
	public void setTitle(String title) {
		this.title = title;
	}
	public Staff()
	{
		title="Project-o-Phile";
	}
	public Staff(String name,String address,String email,String phoneNumber,double salary,Office office,String title)
	{
		super(name,address,email,phoneNumber, salary, office);
		this.title=title;
	}
	public String toString()
	{
		return("name: "+name+"\nTitle: "+title+"\nAddress: "+address+"\nEmail: "+email+"\nNumber: "+phoneNumber+"\nSalary: "+salary+"\nOffice: "+office.toString()+"\nDate Hired: "+dateHired.toString());
	}

}
