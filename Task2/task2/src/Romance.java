public class Romance extends Movie{



public Romance()
{

	super();
		super.Type=6;
}
public Romance(String name,String Starring ,String Language , String Country, int RunningTime)
{

super(name,Starring,Language,Country,RunningTime);
	super.Type=6;

}

@Override
	public String toString()

	{
		return("Romance :" +Name+ " "+ Starring+" "+RunningTime+" "+Country+" "+Language);
	}

}
