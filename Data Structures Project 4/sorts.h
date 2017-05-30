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
void ShellSort(int*, int);
void QuickSort(int* , int , int);
void MergeSort(int *, int , int);
void HeapSort(int* , int);
void adjust(int * , int);
void heapify(int * , int);
int partition(int* , int , int);



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

void HeapSort(int a[],int size)
{
    int i,t;

    heapify(a,size);

    for(i=size-1; i>0; i--)
    {
        t = a[0];
        a[0] = a[i];
        a[i] = t;
        adjust(a,i);
    }
}
void MergeSort(int x[], int end, int start) {
 int j = 0;
 const int size = start - end + 1;
 int mid  = 0;
 int mrg1 = 0;
 int mrg2 = 0;
 int *executing=(int*)calloc(size,sizeof(int));
 if(end == start)
  return;

 mid  = (end + start) / 2;

 MergeSort(x, end, mid);
 MergeSort(x, mid + 1, start);

 for(j = 0; j < size; j++)
  executing[j] = x[end + j];

 mrg1 = 0;
 mrg2 = mid - end + 1;

 for(j = 0; j < size; j++) {
  if(mrg2 <= start - end)
   if(mrg1 <= mid - end)
    if(executing[mrg1] > executing[mrg2])
     x[j + end] = executing[mrg2++];
    else
     x[j + end] = executing[mrg1++];
   else
    x[j + end] = executing[mrg2++];
  else
   x[j + end] = executing[mrg1++];
 }
 free(executing);
}


void QuickSort( int a[], int l, int r)
{
    int i=l, j=r;
    int temp;   
    int pivot=a[(l+r)/2]; //pivot value is the mid value
 
    /* Split the array into two parts */
    do
    {    
        while (a[i] < pivot) i++; 
        while (a[j] > pivot) j--;
        if (i<=j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
            j--;
        }
    } while (i<=j);
 
    /* call the functions recursively */
    if (l < j) QuickSort(a, l, j);
    if (i < r) QuickSort(a, i, r);
}







void ShellSort(int x[],int size)
{
    int i,j,inc,temp;
    for(inc=size/2; inc>0; inc/=2)
    {
        for(i=inc; i<size; i++)
        {
            temp=x[i];
            for(j=1; j>inc; j-=inc)
            {
                if(temp<x[j-inc])
                    x[j]=x[j-inc];
                else
                    break;
                x[j]=temp;
            }
        }
    }
}
void swap (int a[], int left, int right)
{
    int temp;
    temp=a[left];
    a[left]=a[right];
    a[right]=temp;
}//end swap


void heapify(int a[],int n)
{
    int k,i,j,item;

    for(k=1; k<n; k++)
    {
        item = a[k];
        i = k;
        j = (i-1)/2;

        while((i>0)&&(item>a[j]))
        {
            a[i] = a[j];
            i = j;
            j = (i-1)/2;
        }
        a[i] = item;
    }
}

void adjust(int a[],int n)
{
    int i,j,item;

    j = 0;
    item = a[j];
    i = 2*j+1;

    while(i<=n-1)
    {
        if(i+1 <= n-1)
            if(a[i] <a[i+1])
                i++;
        if(item<a[i])
        {
            a[j] = a[i];
            j = i;
            i = 2*j+1;
        }
        else
            break;
    }
    a[j] = item;
}




