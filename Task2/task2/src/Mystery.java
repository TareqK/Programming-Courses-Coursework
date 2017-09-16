public class Mystery extends Movie{



public Mystery()
{

	super();
		super.Type=2;
}
public Mystery(String name,String Starring ,String Language , String Country, int RunningTime)
{

super(name,Starring,Language,Country,RunningTime);
	super.Type=2;

}

@Override
	public String toString()

	{
		return("Mystery :" +Name+ " "+ Starring+" "+RunningTime+" "+Country+" "+Language);
	}

}
