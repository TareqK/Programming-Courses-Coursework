
public class Faculty extends Employee {

	protected String rank;
	protected OfficeHour officehours;
	
	public Faculty()
	{
		super();
		rank="Teaching assistant";
		officehours=new OfficeHour();
	}

	public Faculty(String name,String address,String email,String phoneNumber,double salary,Office office,String rank,OfficeHour officehours)
	{
		super(name,address,email,phoneNumber,salary,office);
		this.rank=rank;
		this.officehours=officehours;
		
	}
	public String getRank() {
		return rank;
	}

	public void setRank(String rank) {
		this.rank = rank;
	}
	public String toString()
	 {
		String temp=officehours.toString();
	
		return ("name: "+name+"\nRank: "+rank+"\nAddress: "+address+"\nEmail: "+email+"\nNumber: "+phoneNumber+"\nSalary: "+salary+"\nOffice: "+office.toString()+"\nDate Hired: "+dateHired.toString()+"\n"+temp);
	}


	
	
}
