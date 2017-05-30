#include <stdio.h>
#include <stdlib.h>

int id;
char* name;
int number;
double balance;
char type;
FILE* in;

void add_account(int i, char* n , int num , double b, char t)
{	int c;
	while((c=fgetc(in))!=EOF){}
	fprintf(in,"%d,%s,%d,%lf,%c",i,n,num,b,t);
	return ;
}

void display_accounts()
{
	while((fscanf(in,"%d,%s,%d,%lf,%c",&id,name,&number,&balance,&type))!=EOF)
	{
		print_account();
	}
	
	return ;
}


void close_account( int i)
{
	int c;
	while((fscanf(in,"%d,%s,%d,%lf,%c",&id,name,&number,&balance,&type))!=EOF)
	{
		if(id==i)
		break;
	}
	
	
   fseek( in, -4, SEEK_CUR );
   while((c=fgetc(in))!='\n')
   {
	    fseek( in, -1, SEEK_CUR );
	   fputc(' ',in);
   }
return ;   
}

void print_account()
{
	printf("%d,%s,%d,%lf,%c",id,name,number,balance,type);
	return;
}

void display_account_details(int i)

{
	while((fscanf(in,"%d,%s,%d,%lf,%c",&id,name,&number,&balance,&type))!=EOF)
	{
		if(id==i)
		break;
	}
	
	print_account();
}

void add_ammount(int i,double a){
	while((fscanf(in,"%d,%s,%d,%lf,%c",&id,name,&number,&balance,&type))!=EOF)
	{
		if(id==i)
		break;
	}
	
	balance= balance+a;
	
	fprintf(in,"%d,%s,%d,%lf,%c",id,name,number,balance,type);
	return;
}

void widthdraw_ammount(int i,double a)
{
		while((fscanf(in,"%d,%s,%d,%lf,%c",&id,name,&number,&balance,&type))!=EOF)
	{
		if(id==i)
		break;
	}
	
	balance= balance-a;
	
	fprintf(in,"%d,%s,%d,%lf,%c",id,name,number,balance,type);
	return;
}

void upload_data_file(FILE * ndata)
{
	fseek(in,0,SEEK_END);
	while((fscanf(ndata,"%d,%s,%d,%lf,%c",&id,name,&number,&balance,&type))!=EOF)
	{
		fprintf(in,"%d,%s,%d,%lf,%c",id,name,number,balance,type);
	}
	return;
	
}

void update_data_file(){

 /*didnt really need this one , you still didnt take struct and linked
  * lists  , it doesnt really matter*/
	
}

