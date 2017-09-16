
import java.util.*;
public class Movie implements Comparator<Movie>,Comparable<Movie>{

	protected String Name;
	protected String Starring;
	protected String Language;
	protected String Country;
	protected int RunningTime;
	protected int Type=0;
	
	public Movie()
	{
		this.Name="jeff";
		this.Starring="jeff";
		this.Language="jeff";
		this.Country="jeff";
		this.RunningTime=7;
	}
	
	public Movie(String name,String Starring ,String Language , String Country, int RunningTime){
		this.Name=name;
		this.Starring=Starring;
		this.Language=Language;
		this.Country=Country;
		this.RunningTime=RunningTime;
	}
		
		

	public void setStarring(String s)
	{
		this.Starring=s;
	}
	public void setLanguage(String s)
	{
		this.Language=s;
	}
	public void setCountry(String s)
	{
		this.Country=s;
	}
	public void setRunningTime(int x)
	{
		this.RunningTime=x;
	}
	public void setName(String s)
	{
		this.Name=s;
	}
	public String getStarring()
	{
		return this.Starring;
	}
	public String getLanguage()
	{
		return this.Starring;
	}
	public String getCountry()
	{
		return this.Country;
	}
	public String getName()
	{
		return this.Name;
	}
	public int getRunningTime()
	{
		return this.RunningTime;
	}
	public String toString()

	{
		return("Movie :" +Name+ " "+ Starring+" "+RunningTime+" "+Country+" "+Language);
	}
	
	@Override
	
	public int compareTo(Movie b){
		
		System.out.println(this.Type+" "+b.Type);
		if(this.Type<b.Type)
		return 1;
		else
		return 0;
		
	}
	
	@Override
	public int compare(Movie a,Movie b)
	{
		return a.Type-b.Type;
	}
		
	
}
