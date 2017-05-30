//Lab linux final question 1
//Tareq Kirresh
//1142828
//بسم الله الرحمن الرحيم

#include<stdio.h>
#include<stdlib.h>
float findMedian(float *a, int n);
void InsertionSort(float array[] , int n);

int main()
{
	int matrixR,matrixC;//number of rows and colums
	int windowR,windowC;//window is always square
	matrixRows:
	printf("please enter the number of rows in the matrix:");
	scanf("%d",&matrixR);
	if(matrixR<1){
		printf("invalid input\n");
		goto matrixRows;
	}
	matrixColumns:
	printf("please enter the number of columns in the matrix:");
	scanf("%d",&matrixC);
	if(matrixC<1)
	{
		printf("invalid input\n");
		goto matrixColumns;
	}
	windowrow:
	printf("Please enter the window row size:");
	scanf("%d",&windowR);
	if(windowR>=matrixR)//if the window size is invalid we ask the user to enter it again 
	{
		printf("that is not a valid size \n");
		goto windowrow;
	}
	windowcolumn:
	printf("Please enter the window column size:");
	scanf("%d",&windowC);
	if(windowC>=matrixC)//same as above
	{
		printf("that is not a valid size \n");
		goto windowcolumn;
	}
	float matrix[matrixR][matrixC];//define the matrix
	int window_size=windowR*windowC;//calculate the size of the window
	float window[window_size];//define the window array
	int i,j,k;//some counters
	for(i=0;i<matrixR;i++)
	{
		for(j=0;j<matrixC;j++)
		{
			printf("Please enter matrix element %d,%d:",i+1,j+1);
			scanf("%f",&matrix[i][j]);
		}
	}
	
	/* printing the array to the user*/
	
	for(i=0;i<matrixR;i++)
	{
		for(j=0;j<matrixC;j++)
		{
			printf(" %.2f ",matrix[i][j]);
			
		}
		printf("\n");
	}
	
	
	printf("\n_______________________________\n");//to seperate the user matrix from the matrix we calculated
	
	
	/*doing the median filtering*/
	j=0;
	for(k=0;k<matrixR;k++){
       for(j=0;j<matrixC;j++){
		int Rpos=-windowR/2;//the row position realtive to the matrix
		int Cpos=-windowC/2;//the column position relative to the matrix
	for(i=0;i<window_size;i++)
	{
	
		if(j+Cpos<0||k+Rpos<0)//to find out if we are out of bounds or not
		{
		 window[i]=0;//if we are , then the value of that entry in the window is considered 0
		}
		else
		{
			window[i]= matrix[k+Rpos][j+Cpos];//otherwise , its the value in the matrix
		}
		
		if(Cpos==(windowC))//if we have reached the last column in the window
		{
			Cpos=-windowC/2;//go back to the first column
			Rpos++;//go down a row
		}
		else
		{
			Cpos++;//otherwise increment the current position
		}
		
		
	}
	matrix[k][j]=findMedian(window,window_size);
}


}

	/*printing the filtered array*/
	
	for(i=0;i<matrixR;i++)
	{
		for(j=0;j<matrixC;j++)
		{
			printf(" %.2f ",matrix[i][j]);
			
		}
		printf("\n");
	}
	
	
	return 0;
}

/*find the median of the elements in a window*/
float findMedian(float *a, int n)
{
	InsertionSort(a,n);
	
	if(n%2!=0){
		return a[n/2];
	}
	else
	{
		return ((a[(n/2)]+a[(n/2)-1])/2);
	}
}
/*we use insertion sort since it is fast to implement but not too slow*/
void InsertionSort(float array[] , int n)//to sort the elements in a window to find the median.
{
	int i,j;
	float temp;
	for (i = 1 ; i <= (n - 1); i++) {
    j = i;
 
    while ( j > 0 && array[j] < array[j-1]) {
				temp=array[j];
				array[j]=array[j-1];
				array[j-1]=temp;
 
      j--;
    }
  }
}
