import java.util.Scanner;

public class hex {

	public static void main (String args[]){
		
		Scanner scan=new Scanner(System.in);
		String hex= scan.next();
		int i;
		try{
			i=Integer.parseInt(hex,16);
			System.out.println(i);
			
		}catch(NumberFormatException ex){System.out.println(ex);};
		
		
	}
	
}