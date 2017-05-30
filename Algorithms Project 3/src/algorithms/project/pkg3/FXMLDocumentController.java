/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package algorithms.project.pkg3;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.URL;
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
    private TextField inputText;
    
    public String inputFileString;
    
    public String outputFileString;
    
    public FileInputStream in;
    
    public FileOutputStream out;
    
    public Huffman huffman;
    
    
    @FXML
    private void handleCompressButtonAction(ActionEvent event) throws BadDataException, IOException {
        
        if(inputFileString == null)
        {
            errorLabel.setText("Please enter a file first");
            throw new BadDataException();
        }
        else{
		this.huffman.compress();
                errorLabel.setText("");
        }
    }
    
    @FXML
    private void handleDecompressButtonAction(ActionEvent event) throws BadDataException, IOException, DoneException{        
        if(inputFileString == null)
        {
            errorLabel.setText("Please enter a file first");
            throw new BadDataException();
        }
        else{
		
		
		huffman.decompress();
                errorLabel.setText("");
        
    }
    }
    @FXML
    public void handleTextEvent1(ActionEvent event) throws FileNotFoundException {
        try{
        inputFileString= inputText.getText();
        this.huffman=new Huffman(256,inputFileString);
        errorLabel.setText("File Read Sucessfuly!");
        }
        catch(FileNotFoundException e){
            
            errorLabel.setText("File Not found, please enter a valid file");
            inputFileString = null;
            huffman = null;
        }
    }
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }    
    
}
