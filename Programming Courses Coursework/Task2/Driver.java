import java.io.*;
import java.util.*;

public class Driver{
public static void main(String []args){


File f = new File("movies.txt");
ArrayList<Movie> list=new ArrayList<Movie>();
try{
list= fromFileToArray(f);
list= SortByType(list);
list= SortByRuntime(list);

PrintWriter output=new PrintWriter("sorted_movies.txt");
for(int i=0;i<list.size();i++)
{
output.println(list.get(i).toString());
}
output.close();



}catch(FileNotFoundException ex){};



}

public static ArrayList fromFileToArray(File in)  throws FileNotFoundException
{
ArrayList<Movie> movielist= new ArrayList<Movie>();
try{
Scanner Scan=new Scanner(in);
String starring;
while(Scan.hasNext()){
String str = Scan.nextLine();
String s = "";
for (int i = 0; i < str.length(); i++) {
if (str.charAt(i) == '[') {
while (str.charAt(i) != ']') {
s += str.charAt(i);
++i;
if (i == str.length())
break;
}

}
if (str.charAt(i) == ',')
s += ';';
else
s += str.charAt(i);
}
String[] splited = s.split(";");


starring="";
for(int i=2;i<splited.length-3;i++)
{
starring+=splited[i];
}
String[] temp=splited[0].split(":");
for(int i=2;i<splited.length;i++)
{
String temp2=splited[i].replaceAll("\\s+","");
splited[i]=temp2;
}



switch(temp[0]){
case("Comedy"):
movielist.add(new Comedy((temp[1]),splited[1],splited[splited.length-1],(splited[splited.length-2]),(Integer.valueOf(splited[splited.length-3]))));
break;
case("Mystery"):
movielist.add(new Mystery((temp[1]),splited[1],splited[splited.length-1],(splited[splited.length-2]),(Integer.valueOf(splited[splited.length-3]))));
break;
case("Rescue"):
movielist.add(new Rescue((temp[1]),splited[1],splited[splited.length-1],(splited[splited.length-2]),(Integer.valueOf(splited[splited.length-3]))));
break;
case("Action"):
movielist.add(new Action((temp[1]),splited[1],splited[splited.length-1],(splited[splited.length-2]),(Integer.valueOf(splited[splited.length-3]))));
break;
case("Romance Comedy"):
movielist.add(new RComedy((temp[1]),splited[1],splited[splited.length-1],(splited[splited.length-2]),(Integer.valueOf(splited[splited.length-3]))));
break;
case("BlockBuster"):
movielist.add(new BlockBuster((temp[1]),splited[1],splited[splited.length-1],(splited[splited.length-2]),(Integer.valueOf(splited[splited.length-3]))));
break;
case("Romance"):
movielist.add(new Romance((temp[1]),splited[1],splited[splited.length-1],(splited[splited.length-2]),(Integer.valueOf(splited[splited.length-3]))));
break;
default:
movielist.add(new Movie((temp[1]),splited[1],splited[splited.length-1],(splited[splited.length-2]),(Integer.valueOf(splited[splited.length-3]))));
break;
}


}



}catch(FileNotFoundException ex){};


return movielist;
}

public static ArrayList SortByType(ArrayList<Movie> array)
{
for(int x=0; x<array.size(); x++)

{

for(int y=0; y<array.size()-1; y++)

{

if(array.get(y).Type>array.get(y+1).Type)

{



Collections.swap(array,y,y+1);

}

}

}

return array;

}

public static ArrayList SortByRuntime(ArrayList<Movie> array)
{
for(int x=0; x<array.size(); x++)

{

for(int y=0; y<array.size()-1; y++)

{

if(array.get(y).RunningTime>array.get(y+1).RunningTime)

{



Collections.swap(array,y,y+1);

}

}

}

return array;

}
}
