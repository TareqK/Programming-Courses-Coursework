#include<stdio.h>
#include<stdlib.h>

void circleArea();
void squareArea();
void rectangleArea();
int main()
{

	printf("Welcome!Please make your choice\n1-Circle Area\n2-Square Area\n3-Rectangle Area\n4-Exit\nYour choice:");
	int c=getchar();
	switch(c){
		
		case '1':circleArea();
				break;
		case '2':squareArea();
				break;
		case '3':rectangleArea();
				break;
		case '4':return 0;
				break;
		default:printf("\nthis is not a valid input\nexiting....");
			break;
		}

	return 0;
}

void circleArea()
{
	double radius;
	printf("please enter the radius:");
	scanf("%lf",&radius);
	double area=radius*radius*3.14;
	printf("the area is:%lf",area);
	
}

void squareArea()
{
	double side;
	printf("Please enter the length of the side:");
	scanf("%lf",&side);
	double area=side*side;
	printf("the area is:%lf",area);
}

void rectangleArea()
{
	double length,width;
	printf("please enter the length:");
	scanf("%lf",&length);
	printf("please enter the width:");
	scanf("%lf",&width);
	double area=length*width;
	printf("the area is:%lf",area);
}
