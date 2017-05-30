/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package algorithms.project.pkg3;


/**
 * This class defines a node of a binary tree and contains methods to access it data members
 * @author Shweta & haxx
 *
 */
public class TreeNode {

	//the symbol associated with this node
	private char symbol;
	//frequency with which this symbol appears in the input file
	private float freq;
	//left child
	public TreeNode left;
	// right child
	public TreeNode right;
	
	/**
	 * Constructor
	 * @param symbol
	 * @param freq
	 * @param left
	 * @param right
	 */
	public TreeNode(char symbol, float freq, TreeNode left, TreeNode right) {		
		this.setSymbol(symbol);
		this.setFreq(freq);
		this.setLeftChild(left);
		this.setRightChild(right);
	}

	/**
	 * @param symbol
	 */
	public void setSymbol(char symbol) {
		this.symbol = symbol;
	}

	/**
	 * 
	 * @return symbol of the node
	 */
	public char getSymbol() {
		return symbol;
	}

	/**
	 * frequency of the symbol in the input file
	 * @param _freq
	 */
	public void setFreq(float _freq) {
		this.freq = _freq;
	}

	/**
	 * @return the frequency of the the symbol
	 */
	public float getFreq() {
		return freq;
	}

	/**
	 * Sets the left child of the node
	 * @param left
	 */
	public void setLeftChild(TreeNode left) {
		this.left = left;
	}

	/**
	 * Returns the left child of the node
	 * @return left
	 */
	public TreeNode getLeftChild() {
		return left;
	}

	/**
	 * Sets the right child of the node
	 * @param right
	 */
	public void setRightChild(TreeNode right) {
		this.right = right;
	}

	/**
	 * Returns the right child of the node
	 * @return right
	 */
	public TreeNode getRightChild() {
		return right;
	}
        
        public void addTreeNode(boolean direction, TreeNode node)
        {
            if(direction==false)
            {
                this.left=node;
            }
            else
            {
                this.right=node;
            }
                    
        }
        
        public boolean isLeaf()
        {
            if(this.left==null && this.right ==null)
                return true;
            else
                return false;
        }
        
        public void printTree(){
            
            System.out.println(this.symbol);
            if(this.left!=null)
            {
             this.left.printTree();
             
            }
            if(this.right!=null)
            {
                this.right.printTree();
                
            }
            
            

            
        }
	
}
