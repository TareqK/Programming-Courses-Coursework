public class Rescue extends Movie{



public Rescue()
{

	super();
		super.Type=3;
}
public Rescue(String name,String Starring ,String Language , String Country, int RunningTime)
{

super(name,Starring,Language,Country,RunningTime);
	super.Type=3;

}

@Override
	public String toString()

	{
		return("Rescue :" +Name+ " "+ Starring+" "+RunningTime+" "+Country+" "+Language);
	}

}
