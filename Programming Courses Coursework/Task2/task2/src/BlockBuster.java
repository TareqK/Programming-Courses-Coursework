public class BlockBuster extends Movie{



public BlockBuster()
{

	super();
		super.Type=7;
}
public BlockBuster(String name,String Starring ,String Language , String Country, int RunningTime)
{

super(name,Starring,Language,Country,RunningTime);
	super.Type=7;

}

@Override
	public String toString()

	{
		return("BlockBuster :" +Name+ " "+ Starring+" "+RunningTime+" "+Country+" "+Language);
	}

}
