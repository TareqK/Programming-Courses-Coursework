/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package algorithms.project.pkg2;

import java.net.URL;
import java.util.ArrayList;
import java.util.Random;
import java.util.ResourceBundle;
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
    
    @FXML
    private Label errorLabel;
    @FXML
    private Label printLabel1;
    @FXML 
    private Label printLabel2;
    @FXML
    private TextField dimensionsTextField;
    
    public ArrayList<Integer> temp ;
    public Random random = new Random();
    public MatrixList matricies ;
    
    @FXML
    public void handleTextEvent1(ActionEvent event) {
        
        int x = Integer.parseInt(dimensionsTextField.getText());
        if(x<=0)
        {
            errorLabel.setText("Invalid value");
            dimensionsTextField.clear();
            return;
        }else{
        temp.add(x);
        errorLabel.setText("(User) value "+(temp.size())+" added");
        dimensionsTextField.clear();
        }
    }
    @FXML
    private void handleRandomButtonAction(ActionEvent event) {
       
        int x = 0;
        while(x==0){
        x = random.nextInt(20);
        }
        temp.add(x);
        errorLabel.setText("(Random) value "+(temp.size())+" added");
    }
    @FXML
    private void handlePrintResultButtonAction(ActionEvent event)
    {
        if(temp.size()>=3){
        int[] dimensions = new int[temp.size()];
        for (int i=0; i < dimensions.length; i++)
        {
            dimensions[i] = temp.get(i).intValue();
        }

        matricies = new MatrixList(dimensions);
        printLabel1.setText(matricies.toString());
        printLabel2.setText("With the respective Dimensions:\n"+temp.toString());
        }
        else{
            errorLabel.setText("Not enough dimensions given");
        }
    }
    @FXML
    private void handleStartOverButtonAction(ActionEvent event)
    {
        temp = new ArrayList<>();
        matricies = null;
        errorLabel.setText("Started Over");
        printLabel1.setText("");
        printLabel2.setText("");
        
    }
    
    @Override
    public void initialize(URL url, ResourceBundle rb) {
       temp =  new ArrayList<>();
    }    
    
}
