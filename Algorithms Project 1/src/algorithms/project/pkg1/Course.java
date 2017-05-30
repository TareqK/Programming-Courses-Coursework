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
public class Course {
    protected int CourseID;
    
    protected double Price;

    public Course(int CourseID, double Price) {
        this.CourseID = CourseID;
        this.Price = Price;
    }

    public int getCourseID() {
        return CourseID;
    }

    public void setCourseID(int CourseID) {
        this.CourseID = CourseID;
    }

   public double getPrice() {
        return Price;
    }

    public void setPrice(double Price) {
        this.Price = Price;
    }
    
    @Override
    public String toString()
    {
        return (""+this.CourseID);
    }
}
