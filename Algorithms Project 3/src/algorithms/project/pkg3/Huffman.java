/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package algorithms.project.pkg3;

/**
 *
 * @author haxx
 */


import java.io.IOException;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;

/**
 * This class contains methods that aid in generation of huffman code using a priority queue.
 * @author Shweta
 *
 */
public class Huffman {
	
	//the total number of alphabets in the input file
	protected int total_letters;
	
	// the number of alphabets - 26. This will be the max size of the queue
	protected int n;
	
	//array containing all symbols from a to z
	protected char[] S;
	
	//array containing the frequency of each symbol in S
	protected float[] P;
	
	//array containing the huffman code of each symbol in S
	protected String[] code;

	//priority queue used for generating the prefix code tree
	protected PriorityQueue priorityQueue;
	
	//input file name
	protected FileInputStream in;
        
        protected FileOutputStream out; 
        
        protected StringBuilder inputString;
        
	protected StringBuilder outputString;
        
        protected String name;
        
        protected int uchars;
        
        protected int [] chars; 
        
        protected float [] charfreqs;
        
	/**
	 * Initializes the arrays S, P and code
	 * @param _n
     * @param name
     * @throws java.io.FileNotFoundException
	 */
	public Huffman(int _n,String name) throws FileNotFoundException {		
		this.n=_n;
                this.name=name;
                this.inputString= new StringBuilder();
                this.outputString= new StringBuilder();
                this.out= new FileOutputStream(this.name+".huff");
                this.in= new FileInputStream(this.name);
                
                this.uchars=0;
		//initialize S with the characters from a to z
		this.S = new char[n];
		char j = (char)0;
		for(int i = 0; i < n; i++, j++) {
			S[i] = j;
		}
		
		//initialize total letters and P with 0
		this.total_letters = 0;
		this.P = new float[n];
		for(int i = 0; i < n; i++) {
			P[i] = 0;
		}
		
		//initialize code

		
	}
	
	/**
	 * 1. Parses the file to fill S and compute total_letters
	 * 2. Fills the priority queue with TreeNodes containing symbols and the frequency of the symbol in the input file
	 * 3. Constructs a prefix code binary tree
	 * 4. Generates the huffman code of each symbol using depth 1st
	 * 5. Finally produces an output file containing the symbols, their frequencies and code.
     * @throws java.io.IOException
	 */
	public void compress() throws IOException{
		
		parseFile();
		fillQueue();
		constructPrefixCodeTree();
		TreeNode node = priorityQueue.extractMin();
		traverseDepthFirst(node, "");
                node.printTree();
                out.write('0');
                writeTree(node);
		writeCode();
	}
	
	/**
	 * Generates an output file containing the symbols, their frequencies and code.
     * @throws java.io.IOException
	 */
	public void writeCode() throws IOException{
		//writing output to the console

                out.write('\n');
		//rewriting the input file with huffman code in fileName.huffman
		try{
			int input;
			char inputC;
                        
			FileInputStream read;
                        
                        read = new FileInputStream(name);
			while((input = read.read()) != -1) {
			    //inputC = (char) input;
			    //outputString.append(code[input]);
                            int temp= findUnique((char)input);
                            System.out.println(code[temp]);
                            for(int i =0; i<code[temp].length();i++)
                            {
                                
                                out.write(code[temp].charAt(i));
                            }
			}
                        
                        out.close();
		}
		catch(IOException exc){
		}
		
	}
	
	/**
	 * Traverses in a depth first manner and generates huffman code for each symbol
	 * @param node
	 * @param code
	 */
	private void traverseDepthFirst(TreeNode node, String code) throws IOException {
		//only proceed if tree is not null
		if(node != null) {
			//compute the index of the symbol in S
			int index=0;
			for(int i=0;i<=uchars;i++){
				if((char)chars[i] == node.getSymbol()){
					index= i;
					break;
				}
			}
			// store the current code in the code array at the index of the symbol
			this.code[index] = code;
                        
                        
                    
                                        
                        
			//traverse left
			this.traverseDepthFirst(node.getLeftChild(), code + "0");
			//traverse right
			this.traverseDepthFirst(node.getRightChild(), code + "1");
		
                    
}
        }
	
	/**
	 * Generates the prefix code tree
	 */
	void constructPrefixCodeTree(){
		
		//construct binary tree with the symbols in S stored in PQ
		for(int i = 1; i <= uchars-1; i++) {
			//create the tree
			TreeNode parent = new TreeNode(' ', 0, null, null);
			

			//extract the minimum from priority queue and make them it the rightchild
			TreeNode rightChild = priorityQueue.extractMin();
			parent.setRightChild(rightChild);
			
			//extract the new minimum from priority queue and make them it the leftchild
                        TreeNode leftChild = priorityQueue.extractMin();
			parent.setLeftChild(leftChild);		
			//set the frequency to the combined frequency of leftChild and rightChild
			parent.setFreq(parent.right.getFreq() + parent.left.getFreq());
			priorityQueue.insert(parent);
		}
	}
	
	/**
	 * Build the priority queue with the symbol with least frequency on top of the queue
	 */
	void fillQueue(){	
	this.priorityQueue = PriorityQueue.startHeap(this.uchars);	
		TreeNode node;
		for(int i = 1; i <= uchars; i++) {
			node = new TreeNode ((char)chars[i],charfreqs[i] , null, null);
			this.priorityQueue.insert(node);
		}
	}
	
        void uniqueChars()
        {
            for(int i=0;i<n;i++)
            {
                if(P[i]>0)
                {
                    this.uchars++;
                }
            }
            
            chars= new int[uchars+1];
            charfreqs= new float[uchars+1];
            int counter =0;
            for(int i=0;i<n;i++)
            {
                if(P[i]>0)
                {
                    chars[counter]=i;
                    charfreqs[counter]=P[i];
                    counter++;
                }
            }
            	this.code = new String[uchars+1];
		for(int i = 1; i <=uchars ; i++) {
			code[i] = "";
		}
        }
	/**
	 * Parses the input file to fill in S and compute total_letters
	 * @param fileName
	 */
	void parseFile() throws FileNotFoundException, IOException{
		// Store the contents of the file in a string
       
        
        this.total_letters = 0;
        try {
            int c ;
            while ((c=in.read())!=-1){
               inputString.append((char)c);
               this.P[c]++;
               this.total_letters++;
            }
            
        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block

        }

        uniqueChars();
}
        
        public StringBuilder getCode() throws IOException{
            StringBuilder s = new StringBuilder();
            try {
            int c ;
            while ((c=in.read())!='\n'){
               s.append((char)c);
            }
           
            while((c=in.read())!=-1)
            {
                this.inputString.append((char)c);
            }
            System.out.println(inputString.toString());
            
        } catch (FileNotFoundException e) {
                // TODO Auto-generated catch block

        }
            return s;
        }
        
 
        
        

        public  void readTree(boolean direction,TreeNode node,StringBuilder code) throws IOException, BadDataException, DoneException//creates a huffman tree from a file
        {
        
            if(code.length()>0&&node!=null){
             switch (code.charAt(0)) {
                    //its a node
                    case '0':
                    {
                        TreeNode tnode = new TreeNode(' ',0,null,null);
                        node.addTreeNode(direction,tnode);
 
                       
                        code.deleteCharAt(0);
                        code.trimToSize();
                        
                            
                        readTree(false,tnode,code);
                        readTree(true,tnode,code);//read down the tree
                        

                        break;
                    }
                    //its a leaf
                    case '1':
                    {
                        code.deleteCharAt(0);
                        code.trimToSize();
                        char[] c= new char[8] ; 
                        code.getChars(0, 8, c, 0);
                        String s = String.copyValueOf(c);
                        int b= Integer.parseInt(s, 2);

                        TreeNode tnode = new TreeNode((char)b,0,null,null);
       
                        node.addTreeNode(direction,tnode);//you have reached a leaf
                  
                       
                        code.delete(0, 8);
                        code.trimToSize();
                        //readTree(!direction,node,code);
                        readTree(false,tnode,code);
                        readTree(true,tnode,code);//read down the tree
                      

                    }
                    default:break;
                }
            }
            
            else {
            }
            
               
            
        }
	
        public void decode(TreeNode node) throws IOException{
            
            TreeNode temp = node;
            int c;
            for(int i=0;i<inputString.length();i++)
            {
                if(!temp.isLeaf()){
                    
                if(inputString.charAt(i)=='0')
                {
                    temp=temp.left;
                }else{ 
                    
                if(inputString.charAt(i)=='1')
                {
                    temp=temp.right;

                }
                }
                System.out.println("HELOOOOOOOOOOOOOOOOOOO");

                }else{
                
                System.out.println(temp.getSymbol());
                outputString.append(temp.getSymbol());
                temp=node;
                }

            }
            System.out.println(outputString.toString());
            for(int i=0; i<outputString.length();i++)
            {
                out.write(outputString.charAt(i));
                
            }
                    
                  
        }
        
       public void writeTree(TreeNode node) throws IOException
       {
           
            if(node!=null){
                if(!node.isLeaf())
                {
                out.write('0');
                
                }
           else{
               

               
                out.write('1');
                    String tempString=Integer.toBinaryString(node.getSymbol());
                    StringBuilder tString = new StringBuilder(tempString);
                    while(tString.length()<8)
                        {
                       tString.insert(0,'0');
                        }
 
                            for(int i=0;i<tString.length();i++)
                            {
                                out.write(tString.charAt(i));
                            }
           }
       
             writeTree(node.left);
             writeTree(node.right);
       }
       
}

       public void decompress() throws IOException, BadDataException, DoneException
       {
           
           TreeNode node = new TreeNode(' ',0,null,null);

           StringBuilder hcode = this.getCode();
           readTree(false,node,hcode);
           node=node.left.left;
           node.printTree();
           decode(node);
           
       }
       
       public int findUnique(char c){
           for (int i=0;i<uchars;i++)
           {
               if(c==chars[i]){
                   return i;
               }
           }
            return 0;
           
       }
}
    