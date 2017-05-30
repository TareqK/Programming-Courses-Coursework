/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package algorithms.project.pkg1;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;

/**
 *
 * @author haxx
 */
public class CourseList extends ArrayList{
    
protected ArrayList<Course> Courses;


    public CourseList() {
        this.Courses = new ArrayList<Course>();
    }
    
    public void addCourse(Course course){
        this.Courses.add(course);
        
    }
    
    public void addCourse(int CID,double Price)
    {
        Course tempCourse=new Course(CID,Price);
        this.Courses.add(tempCourse);
    }
    
    public void ReadFromFile(FileInputStream file) throws IOException{//This function Reads the colleges , courses , and prices from a file, where they are seperated by comma values
    int c1;
    StringBuilder temps1 = new StringBuilder();
    while ((c1 = file.read())!=-1) {
      
        if((char)c1!='\n'){
            temps1.append((char)c1);     
        }
        else{
            String[] tokens1= temps1.toString().split(",");
            int tempInt1;
            double tempDouble1=0;
            for(int i=0;i<tokens1.length;i++){
                tempInt1=Integer.parseInt(tokens1[i]);
                Course tempCourse1=new Course(tempInt1,tempDouble1);
                this.Courses.add(tempCourse1);
            }
            temps1.delete(0, temps1.length());
            
        }

        }
    
        
    }
   
    
@Override
    public String toString()
    {
        StringBuilder s = new StringBuilder();
        for(int i=0; i<this.Courses.size();i++)
        {
            s.append(this.Courses.get(i).toString());
            s.append("  ");
        }
        return s.toString();
     }
    
    public String toCourseString(){
                StringBuilder s = new StringBuilder();
        for(int i=0; i<this.Courses.size();i++)
        {
            s.append(this.Courses.get(i).getCourseID());
        }
        return s.toString();
        
        
    }
    

    
    
}
