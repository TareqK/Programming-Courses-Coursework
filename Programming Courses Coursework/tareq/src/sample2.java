import java.io.IOException;

import com.leapmotion.leap.Controller;
import com.leapmotion.leap.Frame;
import com.leapmotion.leap.Gesture;
import com.leapmotion.leap.Hand;
import com.leapmotion.leap.Listener;
import com.leapmotion.leap.Vector;


class SampleListener extends Listener {

	public void onInit(Controller controller) {//when we create the new controller IE a "new" leapmotion "device"
		System.out.println("Initialized");
	}

	public void onConnect(Controller controller) {//when a leap motion is connected and its service is running
		System.out.println("Connected");
		controller.enableGesture(Gesture.Type.TYPE_SWIPE);
		controller.enableGesture(Gesture.Type.TYPE_CIRCLE);
		controller.enableGesture(Gesture.Type.TYPE_SCREEN_TAP);
		controller.enableGesture(Gesture.Type.TYPE_KEY_TAP);
	}

	public void onDisconnect(Controller controller) {//when a leapmotion service is stopped and the device is disconnected
		//Note: not dispatched when running in a debugger.
		System.out.println("Disconnected");
	}

	public void onExit(Controller controller) {//when the controller is deleted
		System.out.println("Exited");
	}

	public void onFrame(Controller controller) {//when a new frame has arrive
		
		
		Frame frame =controller.frame();
		if(frame.id()%2==0)
		{
			for(int i=0;i<frame.hands().count();i++)
			{
				
				Hand hand = frame.hands().get(i);
				Vector v= hand.translation(controller.frame(10));
				if(hand.isLeft()&&hand.grabStrength()==1&&v.getZ()<-20&&controller.frame(10).hand(i).id()==hand.id())
				{
				
					System.out.println("left");
					
				}
				else if(hand.isRight()&&hand.grabStrength()==1&&v.getZ()<-20&&controller.frame(10).hand(i).id()==hand.id())
					{
			
					System.out.println("right");
					
					}
			}
		}
        
		
	
	}
	
	

		

}

class sample2 {
    public static void main(String[] args) {
        // Create a sample listener and controller
        SampleListener listener = new SampleListener();
        Controller controller = new Controller();

        // Have the sample listener receive events from the controller
        controller.addListener(listener);

        // Keep this process running until Enter is pressed
        System.out.println("Press Enter to quit...");
        try {
            System.in.read();
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Remove the sample listener when done
        controller.removeListener(listener);
    }
}
