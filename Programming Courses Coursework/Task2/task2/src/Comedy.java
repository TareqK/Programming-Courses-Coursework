public class Comedy extends Movie{



public Comedy()
{

	super();
		super.Type=1;
}
public Comedy(String name,String Starring ,String Language , String Country, int RunningTime)
{

super(name,Starring,Language,Country,RunningTime);
	super.Type=1;

}

@Override
	public String toString()

	{
		return("Comedy :" +Name+ " "+ Starring+" "+RunningTime+" "+Country+" "+Language);
	}

}

