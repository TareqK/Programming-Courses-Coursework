import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;
import javafx.scene.layout.*;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.FlowPane;
import javafx.scene.layout.GridPane ;
import javafx.scene.layout.ColumnConstraints;
import javafx.geometry.Pos;
import javafx.scene.layout.BorderPane;

public class Microwave extends Application{
public void start(Stage stage)
{
	
BorderPane border = new BorderPane();

  GridPane gridpane = new GridPane();
  border.centerProperty();
 
     	int counter=1;
	
     for(int i=0;i<3;i++){
		 for(int j=0;j<3;j++){
			 String s= (""+counter);
     gridpane.add(new Button(s),j ,i); // column=2 row=1
     counter++;
 }
 
 }
 gridpane.add(new Button("0"),0,4);
  gridpane.add(new Button("St"),1,4);
   gridpane.add(new Button("sp"),2,4);
     Group root = new Group(gridpane);
  
         border.setCenter(gridpane);
         border.setTop(new Button("DISPLAY                          "));
         border.setLeft(new Button("This \n Is \n the \n display \n \n \n"));
Scene scene = new Scene(border);
       stage.setTitle("My JavaFX Application");
        stage.setScene(scene);
        stage.show();
    }
    
        public static void main(String[] args) {
        launch(args);
    }
}

