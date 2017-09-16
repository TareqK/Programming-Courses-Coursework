


public class OfficeHour {
	//a special class OfficeHour which contains a 7 element array of strings
	//Used inside the class Faculty
	
	


	protected String[] days= new String[7];
	
	OfficeHour()
	{
		for(int i=0;i<7;i++)
		{
			days[i]="N/A";
		}
	}
	
	public void setMonday(String Monday)
	{
		days[0]=Monday;
	}
	public void setTuesday(String Tuesday)
	{
		days[1]=Tuesday;
	}
	public void setWednesday(String Wednesday)
	{
		days[2]=Wednesday;
	}
	public void setThursday(String Thursday)
	{
		days[3]=Thursday;
	}
	public void setFriday(String Friday)
	{
		days[4]=Friday;
	}
	public void setSaturday(String Saturday)
	{
		days[5]=Saturday;
	}
	public void setSuday(String Sunday)
	{
		days[6]=Sunday;
	}
	public String[] getDays() {
		return days;
	}

	public String toString(){
		
		return ("Office Hours: \nMonday: "+days[0]+"\nTuesday: "+days[1]+"\nWednesday: "+days[2]+"\nThursday: "+days[3]+"\nFriday:  "+days[4]+"\nSaturday: "+days[5]+"\nSunday: "+days[6]);
	}
	

	
}
