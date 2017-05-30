/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package algorithms.project.pkg1;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author haxx
 */
public class CollegeList extends ArrayList{
    
    protected ArrayList<College> Colleges ;

    public CollegeList() {
        this.Colleges = new ArrayList<College>();
    }
    
    public void AddCollege(College college){
        this.Colleges.add(college);
    }
    
    public void ReadFromFile(FileInputStream file) throws IOException{//This function Reads the colleges , courses , and prices from a file, where they are seperated by comma values
    int c;
    StringBuilder temps = new StringBuilder();
    while ((c = file.read())!=-1) {
      
        if((char)c!='\n'){
            temps.append((char)c);     
        }
        else{
            String[] tokens= temps.toString().split(",");
            College tempCollege = new College(tokens[0]);
            int tempInt;
            double tempDouble;
            for(int i=1;i<tokens.length;i=i+2){
                tempInt=Integer.parseInt(tokens[i]);
                tempDouble=Double.parseDouble(tokens[i+1]);
                tempCollege.addCourse(tempInt,tempDouble);
            }
            this.Colleges.add(tempCollege);
            temps.delete(0, temps.length());
            
        }

        }
        
    }
    
    @Override
    public String toString(){
       StringBuilder s = new StringBuilder();
       
       for(int i=0; i<this.Colleges.size();i++)
       {
           s.append(this.Colleges.get(i).toString());
           s.append("\n");
           
       }
       
       return s.toString();

    }
    
    public String[]  collegestoStringArray(){
    
    int temp=this.Colleges.size();
    String[] s = new String[temp];
                
       for(int i=0; i<this.Colleges.size();i++)
       {
           s[i]=this.Colleges.get(i).toString();
           
       }
            
    return s;
    }
}

