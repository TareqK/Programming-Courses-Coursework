/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package algorithms.project.pkg1;

/**
 *
 * @author haxx
 */
public class College  {
    protected CourseList Courses;
    protected String CollegeName;
  
    public College(String CollegeName) {
        this.Courses=new CourseList();
        this.CollegeName = CollegeName;
        
    }
    public void addCourse(int CID, double Price)
    {
        Course tempCourse = new Course(CID,Price);
        this.Courses.addCourse(tempCourse);
        
    }
    
    public void addCourse(Course c){
        this.Courses.add(c);
    }
    @Override
    public String toString(){
        return(this.CollegeName+"\t"+this.Courses.toString());
    }

    public CourseList getCourses() {
        return Courses;
    }

    public void setCourses(CourseList Courses) {
        this.Courses = Courses;
    }

    public String getCollegeName() {
        return CollegeName;
    }

    public void setCollegeName(String CollegeName) {
        this.CollegeName = CollegeName;
    }
    
}
