/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package algorithms.project.pkg1;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;
import java.util.Scanner;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

/**
 *
 * @author haxx
 */
public class FXMLDocumentController implements Initializable {
    
    
    public FileInputStream inFile1;
    public FileInputStream inFile2;
    public File in1;
    public File in2;
    public CollegeList Colleges = new CollegeList();
    public CourseList desiredCourses= new CourseList();
    //public File out;
    
   
    
    @FXML
    private Label errorLabel1;
    @FXML
    private TextField collegeFileText;
    @FXML
    private Label PrintLabel1;
    @FXML
    private Label PrintLabel2;
    @FXML
    private TextField desiredCoursesText;
    @FXML
    private Label errorLabel2;
    
    
    
    @FXML
    private void handleButtonAction(ActionEvent event) {
      
        errorLabel1.setText("");
        errorLabel2.setText("");
        PrintLabel1.setText(Colleges.toString());
        PrintLabel2.setText("");
        
    }
    
    @FXML
    private void findBestCollege(ActionEvent event)
    {
        String[] s = new String[Colleges.size()];
        s = Colleges.collegestoStringArray();
        int max=0;
        int indexOfMax=0;
        int temp;
        for(int i=0;i<s.length;i++)
        {
           temp = LongestCommonSubsequence.find(s[i].toCharArray(), desiredCourses.toCourseString().toCharArray());
           if(temp>max)
           {
               indexOfMax= i;
               max=temp;
           }
        }
        PrintLabel2.setText("The Best college is:"+Colleges.Colleges.get(indexOfMax).getCollegeName()+"\nWith "+max+" Matching Courses within the time frame");
    }
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    } 
    @FXML
    public void handleTextEvent1(ActionEvent event) throws FileNotFoundException, IOException
    {
        
        
        String s = collegeFileText.getText();
        try{
        in1 = new File(s);
       
        inFile1=new FileInputStream(in1);
        }
        catch(FileNotFoundException f){errorLabel1.setText("This File Does not exist, Please try again");return;}
        
        try{
        errorLabel1.setText("File read Sucessfully");
        Colleges.ReadFromFile(inFile1);
        }
        catch(IOException e){errorLabel1.setText("Error While reading File");}
        
    }
    @FXML
    public void handleTextEvent2(ActionEvent event) throws FileNotFoundException, IOException
    {
        String s = desiredCoursesText.getText();
        try{
        in2 = new File(s);
       
        inFile2=new FileInputStream(in2);
        }
        catch(FileNotFoundException f){errorLabel2.setText("This File Does not exist, Please try again");return;}
        
        try{
        errorLabel2.setText("File read Sucessfully");
        desiredCourses.ReadFromFile(inFile2);
        }
        catch(IOException e){errorLabel2.setText("Error While reading File");}
        
    }
    
}
