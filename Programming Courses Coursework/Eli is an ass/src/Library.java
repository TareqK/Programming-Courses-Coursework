


public class Library {
	
	public Movie[] library = new Movie[10] ;
	public int[] status= {0,0,0,0,0,0,0,0,0,0};
	protected int counter;
	
	
	public Library(){
		
		this.counter=0;
	}
	public void addMovie(String title , String starring, int runningTime, String country ,String language)
	
	{

		if(counter<10){
			library[counter]=new Movie(title,starring,runningTime , country,language);
			
		}
		else
		{
			System.out.println("library is full");
			
		}
	
	}
	
	public void borrowMovie(String title)
	{
		for(int i=0;i<counter;i++)
		{
			if(library[i].getTitle()==title)
			{
				if(status[i]==0){
				System.out.println("movie has been found and borrowed");
				return;
				}
				else
				{
					System.out.println("movie is already borrowed");
					return;
					
				}
			}
			
		}
		
	System.out.println("Movie not found ");
	
	}
	
	
	public void returnMovie(String title){
		
		for(int i=0;i<counter;i++)
		{
		
			if(library[i].getTitle()==title){
			
				
				if(status[i]==1)
				{
					status[i]=0;
					System.out.println("Movie succesfully returned");
					return;
				}
				
				
				else
				{
					System.out.println("Movie is already present");
					return;
				}
				
				
			}
		
		}
		
			System.out.println("Movie not found");
			return;
		
	}
	
	public void printAvailableMovies(){
		
	for(int i=0;i<counter;i++)
		if(status[i]==0)
		{
			System.out.println(library[i].toString());
			
		}
	
	}
	
	
	
}
