#include <stdio.h>
#include <stdlib.h>
#include "funcs.c"
#include <string.h>


int main(int argc, char* argv[])
{
	int tempr=atoi(argv[(1)]);
	int tempi=atoi(argv[(2)]);
	imaginary x= create_imaginary(tempr,tempi);
	tempr=atoi(argv[(4)]);
	tempi=atoi(argv[(5)]);
	imaginary y= create_imaginary(tempr,tempi);
	imaginary r;
	switch(argv[3][0]){
		case '+':r=addi(x,y);
		break;
		case '-':r=subi(x,y);
		break;
		case '*':r=muli(x,y);
		break;
		default:
		break;
	}
	
	print_imaginary(r);
	return 0;
	
	
	
}
