#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void BubbleSort(int *, int);
void RadixSort(int* , int );
void InsertionSort(int * , int);
void initInOrder(int*,int);
void initRandom(int * , int);
void initReverseOrder(int*,int);
void printArray(int* , int);


void BubbleSort(int array[],int n)
{
	int temp,i,j;
	for(i=0;i<(n-1);i++)
	{
		for(j=0;j<(n-i-1);j++)
		{
			if(array[j]>array[j+1])
			{
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}

}

void InsertionSort(int array[] , int n)
{
	int i,j,temp;
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


void RadixSort(int a[],int n) {
	int i, b[n], m = 0, exp = 1;
	for (i = 0; i < n; i++) {
		if (a[i] > m)
		   m = a[i];
	}
	while (m / exp > 0) {
		int box[10] = {
			0
		}
		;
		for (i = 0; i < n; i++)
		   box[a[i] / exp % 10]++;
		for (i = 1; i < 10; i++)
		   box[i] += box[i - 1];
		for (i = (n - 1); i >= 0; i--)
		   b[--box[a[i] / exp % 10]] = a[i];
		for (i = 0; i < n; i++)
		   a[i] = b[i];
		exp *= 10;
	}
	
}

void initRandom(int a[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		a[i]=random();
	}
}

void initInOrder(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		a[i]=(i+1);
	}
}

void initReverseOrder(int a[],int n)
{
	int i;
	int j=0;
	for(i=n;i>=0;i--)
	{
		a[i]=j;
		j++;
}
}

void printArray(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d \n",a[i]);
	}
	
}





