import java.util.*;

public class driver {

	public static void main (String args[]){
		
		Scanner scan=new Scanner(System.in);
		String bin= scan.next();
		int i;
		try{
			i=parseBinary(bin);
			System.out.println(i);
			
		}catch(NumberFormatException ex){System.out.println(ex);};
		
		
	}
	
	public static int parseBinary(String bin) throws NumberFormatException{
	int power=1;
	int sum=0;
	for(int i=bin.length()-1;i>=0;i--){
		
		char ch=bin.charAt(i);
		if(ch=='0'||ch=='1')
		{
			sum+=(bin.charAt(i)-'0')*power;
			power=power*2;
			
		}
		else
		{
			throw new  NumberFormatException("Number is not binary we have : "+bin.charAt(i) );
		}
	}
	return sum;
	
	
	}
	
	
}
