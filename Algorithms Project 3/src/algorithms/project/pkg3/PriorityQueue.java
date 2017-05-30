/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package algorithms.project.pkg3;


/**
 * This class defines a priority queue and contains methods to perform insertion , deletion etc.
 * @author Shweta & haxx
 *
 */
public class PriorityQueue {
	
	// heap that maintains the queue
	public Heap heap;
	// max size of the queue, in this case 26
	private int maxSize;
	
	/**
	 * Constructor
	 * @param n
	 */
	private PriorityQueue(int n){
		this.maxSize = n;
		this.heap = new Heap(this.maxSize);
	}
	
	/**
	 * Creates a priority queue
	 * @param n
	 * @return
	 */
	public static PriorityQueue startHeap(int n){
		
		PriorityQueue priorityQueue= new PriorityQueue(n);
		return priorityQueue;
	}
	
	/**
	 * Inserts a new node in the queue and calls heapify up to arrange it to maintain the property of the queue
	 * @param pq
	 * @param node
	 */
	public void insert(TreeNode node){ 
		/*if (node.getFreq() <= 0){
			return;
		}*/
		// If the heap is full
		if(this.heap.heapSize==this.maxSize){
			System.out.println();
		}
		if (this.heap.heapSize >= this.maxSize) {
			System.out.println("The heap is full. Cannot add more elements.");
		}
		else {
			this.heap.heapSize++;
			this.heap.heapArray[this.heap.heapSize] = node;
			heap.heapifyUp(this.heap.heapSize);	
                        System.out.println(node.getFreq());
		}
	}

	/**
	 * Returns the root node
	 * @param heap
	 * @return
	 */
	public TreeNode findMin(){
		return heap.heapArray[1];
	}
	
	/**
	 * Returns and deletes the root node
	 * @param pq
	 * @return
	 */
	public TreeNode extractMin(){
		
		TreeNode node=this.findMin();
		this.delete(1);
		return node;
	}
	
	/**
	 * Deletes the node at index i of the array of the heap. Then calls heapify down to re arrange the heap to maintain the queue properties
	 * @param heap
	 * @param i
	 */
	private void delete(int i){
		// If the heap is empty
		if (heap.heapSize < 1){
			System.out.println("Heap is empty. Cannot delete element");
		}
		else{
			//int size = heap.heapSize; // To access the nth element
			heap.heapArray[i] = heap.heapArray[heap.heapSize];
			heap.heapArray[heap.heapSize] = null;
			heap.heapSize--;
			// Fix the heap
			heap.heapifyDown(i);
		}
	}
	
	/**
	 * Finds a node and changes its values. Then calls heapify up or heapify down to re arrange the heap
	 * @param heap
	 * @param node
	 * @param alpha
	 */
	public void changeKey(TreeNode node, int alpha){
		// Locate node in the array
		int i=0;
		for(i=1; i<=maxSize;i++){
			if(heap.heapArray[i].getSymbol()==node.getSymbol()){
				break;
			}
		}
		if (heap.heapArray[i].getFreq() <= alpha) {
			heap.heapArray[i].setFreq(alpha);
			heap.heapifyDown(i);
		}
		else {
			heap.heapArray[i].setFreq(alpha);
			heap.heapifyUp(i);
		}
	}
}

