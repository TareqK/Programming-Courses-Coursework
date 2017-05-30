/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package algorithms.project.pkg3;

/**
 * This class defines a Heap as an array. It contains the heapify up and heapify down methods used for rearranging the heap on insertion or deletion of a node
 * @author Shweta & haxx
 *
 */
public class Heap {
	
	// array of nodes that will contains the contents of the heap
	TreeNode [] heapArray;
	
	//number of nodes in the heap at any given time
	int heapSize;
	
	/**
	 * Constructor
	 * @param n
	 */
	public Heap(int n){
		heapArray= new TreeNode[n+1];
		heapSize=0;
	}
	
	/**
	 * Places a newly inserted node to its correct position in the heap
	 * @param heap
	 * @param i
	 */
	public void heapifyUp(int i){
		
		if(i > 1) {
			//j is the parent of i. i/2 will inherently be the floor if i/2 as they are both integers
			int j = (i/2);
			//check if i has a lower frequency than j, and swap if so
			if(this.heapArray[i].getFreq() < this.heapArray[j].getFreq()) {
				
				//swap the two nodes
				this.swap(i, j);
				
				//recurse through
				heapifyUp(j);
			}
		}	
	}
	
	/**
	 * Re arranges the heap to maintain the property of this heap i.e freq of parent < freq of right child and left child
	 * @param heap
	 * @param i
	 */
	public void heapifyDown(int i){
		int left = 2 * i;
		int right = 2 * i + 1;
		int min;
		
		if(left <= heapSize && this.heapArray[left].getFreq() < this.heapArray[i].getFreq()) min = left;
		else min = i;
		if(right <= heapSize && this.heapArray[right].getFreq() < this.heapArray[min].getFreq()) min = right;
		
		if(min != i) {
			swap(min, i);
			heapifyDown(min);
		}
	}
	
	/**
	 * Swaps 2 nodes
	 * @param i
	 * @param j
	 */
	private void swap(int i, int j){
		TreeNode temp = this.heapArray[j];
		this.heapArray[j] = this.heapArray[i];
		this.heapArray[i] = temp;
	}

}
