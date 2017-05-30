
public class Student extends Person {
	
	protected int classStatus;//class status was defined as int , because there are only four class statuses.
	
	public Student()
	{
		super();
		classStatus=0;
	}
	public Student(String name,String address,String email,String phoneNumber,int classStatus)
	{
		super(name,address,email,phoneNumber);
		this.classStatus=classStatus;
	}
	public void setClassStatus(int classStatus)
	{
		this.classStatus=classStatus;
	}
	public int getClassStatus()
	{
		return classStatus;
	}
	
	public String toString()
	{
		String year;
		switch(classStatus)//switch statement to initialize the String year , which contains the string value of class status
		{
		case(0):
			year="Freshman";
		break;
		case(1):
			year="Sophomore";
		break;
		case(2):
			year="Junior";
		break;
		case(3):
			year="Senior";
		break;
		default:
			year="Unknown/Graduated";
			break;
		}
		
		return("name: "+name+"\nAddress: "+address+"\nEmail: "+email+"\nNumber: "+phoneNumber+"\nClass: "+year);
	}

}
