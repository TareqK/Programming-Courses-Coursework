import java.io.File;
import java.io.*;
import java.util.Scanner;

public class ReadFile {

    public static void main(String[] args) {
    	
    	double m=0,f=0;
    	double mavg,favg;
    	int mcounter=0,fcounter=0;

        try {
            Scanner input = new Scanner(System.in);
            System.out.print("Enter the file name with extention : ");
            File file = new File(input.nextLine());
            System.out.print("Enter the file name with extention : ");
            File out=new File(input.nextLine());
            PrintWriter print= new PrintWriter(out);

            input = new Scanner(file);


            while (input.hasNext()) {
                String line = input.next();
                String gender=input.next();
                int grade=input.nextInt();
                System.out.println(line+" "+gender+" "+grade);
               print.print((line+" "+gender+" "+grade+"\n"));
               if(gender.charAt(0)=='m')
               {
            	   mcounter++;
            	   m+=grade;
            	   
               }
               else
               {
            	   fcounter++;
            	   f+=grade;
            	   
               }
                
                
          
            }
            mavg=m/mcounter;
            favg=f/fcounter;
            System.out.println(mavg+" "+favg );
            print.print("The Male Average is: "+mavg+"\nThe Female Average is: "+favg);
            input.close();
            print.close();

        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }}
