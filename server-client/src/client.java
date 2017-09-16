import java.net.*;
/* The java.io package contains the basics needed for IO operations. */
import java.io.*;
/** The SocketClient class is a simple example of a TCP/IP Socket Client.
 *
 */

public class SocketClient {
	
	public static void main(String[] args) {
	    /** Define a host server */
	    String host = "localhost";
	    /** Define a port */
	    int port = 19999;

	    StringBuffer instr = new StringBuffer();
	    String TimeStamp;
	    System.out.println("SocketClient initialized");
	    try {
	        /** Obtain an address object of the server */
	        InetAddress address = InetAddress.getByName(host);
	        /** Establish a socket connetion */
	        Socket connection = new Socket(address, port);
	        /** Instantiate a BufferedOutputStream object */
	        
	    }
	    finally{
	    	
	    	System.exit(0);
	    }
	      BufferedOutputStream bos = new BufferedOutputStream(connection.
                getOutputStream());
	            /** Instantiate an OutputStreamWriter object with the optional character
	             * encoding.
	             */
	            OutputStreamWriter osw = new OutputStreamWriter(bos, "US-ASCII");
	            

	            TimeStamp = new java.util.Date().toString();
	            String process = "Calling the Socket Server on "+ host + " port " + port +
	                " at " + TimeStamp +  (char) 13;

	            /** Write across the socket connection and flush the buffer */
	            osw.write(process);
	            osw.flush();
	    }
}