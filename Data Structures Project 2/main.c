#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"linkedlist.c"

FILE* changeInputFile();
void printValid(FILE *);
void printFile(FILE*);
void printPostFix(FILE *);
void toPostfix(char []);
int priority(char);
int isValid(char z[])
{

if((strstr(z,"x/")!=NULL)||(strstr(z,"/x")!=NULL)||(strstr(z,"//")!=NULL)||(strstr(z,"/0")!=NULL)||(strstr(z,"xx")!=NULL)){
return 0;
}
else
return 1;
}




int main()
{
int status;
FILE* input=fopen("input.txt","r");

do{
printf("Please enter your selection\n1-Print From Input File \n2-Print only Valid \n3-Print only valid and result \n4-Print all and result\n 5-change input File \n6-Exit\nChoice: ");
scanf("%d",&status);


switch(status){
case(1):
printFile(input);
break;
case(2):
printValid(input);
break;
case(3):printPostFix(input);break;
//case(4):printFileAndCalc(input);
//break;
case(5):
input=changeInputFile();
break;
case(6):
return 0;
break;
default:
break;
}
}while(1);
return 0;
}
FILE* changeInputFile()
{
char buff[80];
printf("Please enter new file name with extention: ");
scanf("%s",buff);
return fopen(buff,"r");
}
void printFile(FILE* fp)
{
char buff[80];
while(fscanf(fp,"%s",buff)!=EOF){
printf("%s\n",buff);
}
rewind(fp);
}

void printValid(FILE* fp)
{
char buff[80];
while(fscanf(fp,"%s",buff)!=EOF){
if(isValid(buff))
{
printf("Valid:%d \t",isValid(buff));
printf("%s \n ",buff);
}
}
rewind(fp);
}

int priority(char z)
{

switch(z)
{
case('-'):return 1;
case('+'):return 2;
case('*'):return 3;
case('/'):return 4;
case('('):return 5;
case(')'):return 5;
default:
return 0;
}
}



void toPostfix(char x[]){

LINKEDLIST s;
createLINKEDLIST(s);
char c;
clrscr();
int i=0;
while(x[i]!='\0')
{

    if(priority(x[i])==0)
       printf("%c",x[i]);
    else
       if(x[i] == '(')
           push(s,'(');
       else
       {
         if(x[i] == ')')
             while((c=pop(s))!='(')
             printf("%c",c);
         else
         {
         while(priority(x[i]) <=priority(top(s)) && !IsEmpty(s))
             {
             c=pop(s);
             printf("%c",c);
             }
         push(s,x[i]);
         }
       }
       i++;
  }
  while(!IsEmpty(s))
    {
    c=pop(s);
    printf("%c",c);
    }
}



void printPostFix(FILE* fp)
{
	char buff[80];
	LINKEDLIST x;
	createLINKEDLIST(x);
	while(fscanf(fp,"%s",buff)!=EOF){
		toPostfix(buff);
		
}
rewind(fp);
}


/*int eval(int op1, int op2,char x){
     if(x=='+')
        return(op1+op2);
    if(x=='-')
        return(op1-op2);
    if(x=='*')
        return(op1*op2);
    if(x=='/')
            return(op1/op2);
    if(x=='%')
            return(op1%op2);
     
}*/
