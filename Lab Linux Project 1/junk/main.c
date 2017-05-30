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


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct sentence{
	
	int num;//number of the sentence in the paragraph
	char content[200];//the content of the sentence,for testing purpouses , we are limiting this to 200 chars, or one whole line
	int length;//its length
	float weight;//its weight
	struct sentence* next;//the sentence that follows it
}sentence;

typedef struct sentence* paragraph_first;//a paragraph is a pointer to the first sentence

/*typedef struct paragraph
{
	int num;//the number of the pargraph in the doccument
	paragraph_first first;//the pointer to the contents of this paragraph
	struct paragraph* next;//the pointer to the next paragraph
	* we did not end up needing this , since we simply reset the paragraph index counter 
	* when a new line appeared
}paragraph;*/

typedef struct doccument{
	
	int length;//the number of sentences in our doccument 
	sentence* content;//the content of our doccument
	char title[200];//the title of our doccument 
	int longest;//the length of the longest sentence
	int numbers;//the instances of numbers in this doccument
}doccument;

sentence* insert(sentence*, sentence*, sentence*);

sentence* insertion_sort(sentence* );

int main(int argc, char *argv[])
{
	
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
	int i=0;
	while(argv[1][i]!='\0')
	{
		z->title[i]=argv[1][i];
		i++;
	}
	z->title[i+1]='\0';
	findNumbers(z);
	findLongest(z);
	char outputname[200];//preparing the output file
	strcpy(outputname,argv[1]);
	char* t="_summarized";
	strcat(outputname,t);
	FILE* op=fopen(outputname,"w");
	summarize_doccument(z,rate,op);
	fclose(fp);
	fclose(op);
	return 0;
}
void create_doccument(doccument* z, FILE* fp)//a function that scans a file and creates a doccument
{



	
	sentence * stemp=malloc(sizeof(sentence));//allocate a sentence
	z->length=0;//the doccument length is 0
	z->content=stemp;
	int c;
	int i=0;
	int k=1;
	label:while((c=fgetc(fp))!=EOF)
	{
		
		if(c=='!'||c=='.'||c==',')//if the sentence has finished
		{
			z->length++;//increment the length of the doccument
			stemp->num=k;//the index of the doccument in the paragraph is k
			stemp->length=i;//the length of the sentence is i, the number of chars in it
			stemp->content[i]='.';//append a .
			stemp->content[i+1]='\0';//append null char
			stemp->weight=0;
			stemp->next=malloc(sizeof(sentence));//allocate a new sentence
			stemp=stemp->next;//traverse
			k++;//increment the index
			i=0;//resent i to 0
			goto label;//go back to the begining of the while loop
		
		}
		
		if(c=='\n')
		{
			i=0;//reset i to 0
			k=1;//reset the index to one 
			goto label;//go back to the start of the while loop
		}
			
		stemp->content[i]=c;//the char at i is the one we scan
		i++;//increment i
	}

	printf("doccument created\n");//once we are done , we print that a doccument has been created
	stemp->next=NULL;//and have the last sentence point to NULL
	return;
		
}

void print_doccument(doccument* d, int percent,FILE* op)//a function that prints the doccument to the user
{
	sentence * stemp=d->content;//start with having a pointer to the first sentence
	int counter=0;//and a counter of zero
	while(counter<=percent)//while counter is less than the calculated number of sentences we want to print
		{
			printf("%s",stemp->content);//print it on the screen to the used
			fprintf(op,"%s",stemp->content);//and print it to a file
			stemp=stemp->next;//traverse
			counter++;//and increment the counter
		}
	printf("\n");//print new line
}

void summarize_doccument(doccument *d,int percent,FILE* op)//a function that summaries a doccument to the user entered %
{
	
	sentence * stemp=d->content;//start with the first sentence in the doccument
	while(stemp->next!=NULL)
		{
			rank(stemp,d);//rank the sentence
			stemp=stemp->next;//move to the next
		}
	
	sentence* temp=insertion_sort(d->content);//insertion sort the sentences by wieght 
	d->content=temp;//change the content of the doccument to be the insertion sorted version
	float x=(float)d->length-(((float)percent/100)*((float)d->length));//calculate how many sentences we must print
	print_doccument(d,(int)x,op);//print them
}

void rank(sentence *s, doccument* d)//a function that ranks a sentence according to our criteria
{
	titleWordFeatures(s,d->title);
	sentenceLengthFeature(s,d->longest);
	sentenceLocationFeature(s);
	hasNumbers(s,d->numbers);
}

void titleWordFeatures(sentence *s, char* title)// a function that finds the ratio of the number of instances of the word in the sentance to the instances of the title
{


if(strstr(s->content, title) != NULL){
	s->weight=s->weight+(float)((float)strlen(title)/(float)s->length);//divide the counter over this result. 
}
}

void removeSubstring(char *s,const char *toremove)
{

  while( s=strstr(s,toremove) )
    memmove(s,s+strlen(toremove),1+strlen(s+strlen(toremove)));
}

void findNumbers(doccument* d)//finds how many numbers there are in the text
{
	sentence * stemp=d->content;
	int c;
	int n=0;
	while(stemp!=NULL)//travarse every sentenece in a paragraph
	{	
		int i=0;
		while(stemp->content[i]!='\0')//traverse every char in a sentence 
			{
					
				if(stemp->content[i]>='0'&&stemp->content[i]<='9'){//using ascii code , we find if it is a number
				n++;//if it is a number , we add it to a counter
			}
				i++; 
			}
		stemp=stemp->next;//traverse
				
		}
	d->numbers=n;//the ammount of numbers in this doccument is n

}

void hasNumbers(sentence* s, int numbers)//a function that finds the ratio between numbers in a sentence and total numbers in the text 
{
	if(numbers!=0){
	int i=0;
	int n=0;
	char c;
	while((c=s->content[i])!='\0')
	{
		i++;
		if(c>='0'&&c<='9'){
		n++;
	}
		
	}
	s->weight= s->weight+(float)((float)n/(float)numbers);
}
else
return;
}

void findLongest(doccument* d)//a function that returns the length of the longest sentence in the text.
{
	
	sentence * stemp=d->content;
	int max=0;//assume a value for max
	

		while(stemp->next!=NULL)
		{
			if(strlen(stemp->content)>max)//if the length of the string is bigger than max , then max is equals to length of this string
			max=strlen(stemp->content);
			stemp=stemp->next;
		}
	
	d->longest=max;
}

void sentenceLengthFeature(sentence *s , int longest)// a function that finds the ratio between this sentence and the longest one in the text 
{
	
	s->weight=s->weight+(float)(s->length/(float)longest);//calculating sentence length feature and adding it to the weight 
	
}

void sentenceLocationFeature(sentence *s)//a function that finds the reciprocal of the index of the sentence in the paragraph
{
		s->weight= s->weight + (float)(1/(float)s->num);
}

sentence* insertion_sort(sentence* begin)
{

   sentence* sorted = begin;
   sentence* preaktual = begin; 
   sentence* pom;
   sentence* pom1;
   
   while(preaktual -> next != NULL) {
       
       pom = sorted;
	   while( preaktual ->next  != NULL && pom != preaktual -> next && pom -> weight > preaktual->next->weight)
        pom = pom -> next;
       
       if(preaktual -> next != pom) { 
           //element is moving
           //we must connect element before with element after
           pom1 = preaktual -> next;
           preaktual -> next = preaktual -> next -> next;
           sorted = insert(sorted,pom, pom1);
            
       }else{
        
        preaktual = preaktual -> next;
       }

   }
  return sorted;
}

sentence* insert(sentence* begin, sentence* position, sentence* newItem){
   //check if we add to the beginning
   if(begin == position) {
       newItem -> next = begin;
       return newItem;
   }
   
   sentence* pom = begin;
   while(pom -> next != position) {
       pom = pom -> next;
   }
   
   newItem -> next = pom -> next;
   pom -> next = newItem;
   
   return begin;
 
}
