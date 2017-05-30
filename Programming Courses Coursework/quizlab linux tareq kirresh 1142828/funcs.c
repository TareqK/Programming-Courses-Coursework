#include <stdio.h>
#include <stdlib.h>
#include "header.h"



typedef struct imaginary_t imaginary;
imaginary addi(imaginary x, imaginary y)
{
int tempr=(x.r)+(y.r);
int tempi=(x.i)+(y.i);
imaginary tempimaginary= create_imaginary(tempr,tempi);
return tempimaginary;
}

imaginary subi(imaginary x, imaginary y){
int tempr= x.r-y.r;
int tempi = x.i-y.i;
imaginary tempimaginary = create_imaginary(tempr,tempi);
return tempimaginary;
}

imaginary muli(imaginary x, imaginary y){

int tempr=((x.r)*(y.r))-((x.i)*(y.i));
int tempi=((x.r)*(y.i))+((y.r)*(x.i));
imaginary tempimaginary = create_imaginary(tempr,tempi);
return tempimaginary;
}

imaginary create_imaginary(int real, int imag)
{
	
	imaginary img;
	 img.r=real; 
	 img.i=imag;
	 return img;
}

void print_imaginary(imaginary x)
{
	printf("%d + %d i  \n",(int)x.r,(int)x.i);
	
}
