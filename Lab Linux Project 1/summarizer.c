/*Tareq Kirresh*/
/*1142828*/
/*Ayman Daraghmeh*/
/*Your Student# here*/
/*Lab linux project*/
/*A C program that takes a text file as input and Summarizes it*/
/*Project Code Name: TL;DR*/
/*Due Date 30/4/2016*/
/*Start Date 24/4/2016*/
/* بسم الله الرحمن الرحيم  */




#include"func.c"

int main(int argc, char *argv[]){


	//printf("%d",num); checking our work initially
	int rate=0;
	if(argc==3){
		rate = atoi(argv[2]);
	}else{
		printf("check inputs\n");//if there is the wrong number of arguments
		return 0;
	}

	if(rate>100 || rate<0){
		printf("check the rate\n");//if the rate is wrong
		return 0;
	}

	doccument d;
	doccument* z=&d;
	FILE* fp=fopen(argv[1],"r");

	if(fp==NULL){
		printf("check file name\n");//if the file does not exist
		return 0;
	}

	create_doccument(z,fp);
	//setting some doccument variables
	findNumbers(z);
	findLongest(z);
	char outputname[200];//preparing the output file
	strcpy(outputname,argv[1]);
	strcpy(z->title,argv[1]);
	char* t="_summarized";
	strcat(outputname,t);
	FILE* op=fopen(outputname,"w");

	summarize_doccument(z,rate,op);

	fclose(fp);
	fclose(op);
	return 0;
}
