
import java.util.ArrayList;
public class Driver {
	public static void main(String []args){
	ArrayList<Object> persons =new ArrayList<Object>();//Creating a new ArrayList
	persons.add(new Person("tareq","jerusalem","tareq.tj@gmail.com","0595541800"));//defining 10 elements as asked
	persons.add(new Employee("salim","ramallah","salim@birzeit.edu","0598211111",1500,new Office(301,"masri")));
	persons.add(new Faculty("Suleiman","Jerusalem","N/A","0577712312",2500,new Office(220,"Aggad"),"PHD",new OfficeHour()));
	persons.add(new Faculty("Samer","Jerusalem","Samer@genericemailservice.com","05377724122",1500,new Office(407,"Masri"),"Teaching Assistant",new OfficeHour()));
	persons.add(new Faculty("Rula","Al-Beireh","rula@birzeit.edu","0531244467",1500,new Office(407,"Aggad"),"Teaching Assistant",new OfficeHour()));
	persons.add(new Staff("Yassin","Nablus","yasuo@hotmail.com","N/A",1500,new Office(100,"Ghanem"),"Master of the Forge"));
	persons.add(new Staff("Basil","Nablus","bibohabibo@hotmail.com","N/A",1500,new Office(100,"Ghanem"),"Apprentice"));
	persons.add(new Student("Tala","Jerusalem","N/A","N/A",1));
	persons.add(new Student("Ali","Ramallah","N/A","N/A",1));
	persons.add(new Student("Ramez","Bethlehem","N/A","N/A",1));
	
	for(int i=0;i<persons.size();i++){//a loop to print these elements
	
		System.out.println(persons.get(i).toString()+"\n________________________\n");
	}
	
	
	
	
}
	}
