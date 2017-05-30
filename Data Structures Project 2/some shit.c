#include<stdio.h>
#include<stdlib.h>
#define pi 3.14

int max(int,int);


int max(int x1, int x2)
{
	if(x1>x2)
	{
		return x1;
	}
	else
	{
		return x2;
	}
}

int main()
{
	int x1,x2;
	scanf("%d",&x1);
	scanf("%d",&x2);
	int x3=max(x1,x2);
	printf("%d",);
	return 0;

}
