
public class Movie {
	
	protected String title;
	protected String starring;
	protected int runningTime;
	protected String country;
	protected String language;
	
	
	
	public Movie(String title, String starring, int runningTime,
			String country, String language) {
		this.title = title;
		this.starring = starring;
		this.runningTime = runningTime;
		this.country = country;
		this.language = language;
	}
	
	
	public Movie() {
		this.title="Minions";
		this.starring="Sandra Bullock, Jon Hamm , Micheal Keaton";
		this.runningTime= 91;
		this.country="USA";
		this.language="English";
	}


	public String getTitle() {
		return title;
	}
	public void setTitle(String title) {
		this.title = title;
	}
	public String getStarring() {
		return starring;
	}
	public void setStarring(String starring) {
		this.starring = starring;
	}
	public int getRunningTime() {
		return runningTime;
	}
	public void setRunningTime(int runningTime) {
		this.runningTime = runningTime;
	}
	public String getCountry() {
		return country;
	}
	public void setCountry(String country) {
		this.country = country;
	}
	public String getLanguage() {
		return language;
	}
	public void setLanguage(String language) {
		this.language = language;
	}
	@Override
	public String toString() {
		return(title + "\n"+starring +"\n"+runningTime+"\n"+country+"\n"+language);
		
	}
		
	

}
