
public class Office {
	private int room;
	private String Building;
	
	public Office()
	{
		room=100;
		Building="Masri";
	}
	public Office(int room,String Building)
	{
		this.room=room;
		this.Building=Building;
	}
	public int getRoom() {
		return room;
	}
	public void setRoom(int room) {
		this.room = room;
	}
	public String getBuilding() {
		return Building;
	}
	public void setBuilding(String building) {
		Building = building;
	}
	public String toString()
	{
		return("room "+room+" "+Building);
	}

}
