/*Tareq Kirresh*/
/*1142828*/
/*Lab linux project*/
/*A C program that takes a text file as input and Summarizes it*/
/*Project Code Name: TL;DR*/
/*Due Date 30/4/2016*/
/*Start Date 24/4/2016*/
/* بسم الله الرحمن الرحيم  */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct sentence{

	int num;//number of the sentence in the paragraph
	char content[80];//the content of the sentence,for testing purpouses , we are limiting this to 80 chars, or one whole line
	int length;//its length
	float weight;//its weight
	struct sentence* next;//the sentence that follows it
}sentence;

typedef struct sentence* paragraph_first;//a paragraph is a pointer to the first sentence

typedef struct paragraph
{
	int num;//the number of the pargraph in the doccument
	paragraph_first first;//the pointer to the contents of this paragraph
	struct paragraph* next;//the pointer to the next paragraph
}paragraph;

typedef struct doccument{

	int length;//the number of sentences in our doccument
	paragraph* content;//the content of our doccument
	char* title;//the title of our doccument
	int longest;//the length of the longest sentence
	int numbers;//the instances of numbers in this doccument
}doccument;
void create_doccument(doccument, FILE*);
void print_doccument(doccument );


int main()
{

	doccument d;
	FILE* fp=fopen("stuff.txt","r");
	create_doccument(d,fp);
	print_doccument(d);
	fclose(fp);
	return 0;
}
void create_doccument(doccument d, FILE* fp)//a function that scans a file and creates a doccument
{


	paragraph* temp=malloc(sizeof(paragraph));//allocate a paragraph
	printf("allocated paragraph");
	sentence * stemp=malloc(sizeof(sentence));//allocate a sentence
		printf("allocated sentence");
	temp->first=stemp;
	d.content=temp;//make it the first paragraph in the doccument
	int c;
	while((c=fgetc(fp))!=EOF)
	{
		if(c=='!'||c=='.'||c==',')
		{
			sentence* stemp2=malloc(sizeof(sentence));
			stemp->next=stemp2;
			stemp=stemp->next;
		}
	}
	stemp->next=NULL;
	temp->next=NULL;
	//allocate a sentence using malloc
	//traverse the file
	//char by char
	//and insert it into our sentnece
	//if the char is one of our delimiters
	//allocate a new sentence
	//if the char is a newline char
	//allocate a new paragraph
	//allocate a new sentence
	//keep going until we reach null


}

void print_doccument(doccument d)//a function that prints the doccument to the user
{
	paragraph* ptemp= d.content;
	sentence * stemp=ptemp->first;

	while(ptemp->next!=NULL)
	{
		while(stemp->next!=NULL)
		{
			printf("%s",stemp->content);
			stemp=stemp->next;
		}
		ptemp=ptemp->next;
	}
}

void summarize_doccument(doccument d)//a function that summaries a doccument to the user entered %
{

	//insertion sort the sentences and print the sentences.
	//Since we dont have paragraphs or doccuments here, we sort them into a linked list and print it

}

void rank(sentence s, int numbers,int longest)//a function that ranks a sentence according to our criteria
{
	//call all our ranking functions
}

void titleWordFeatures(sentence s, char* title)// a function that finds the ratio of the number of instances of the word in the sentance to the instances of the title
{
	char temp[80];
	char*token;
	int i;
	int num=0;
	int counter=1;
	for(i=0;i<80;i++)
	{
		temp[i]=s.content[i];
		if(temp[i]==' ')
		{
		counter++;	//find the number of words in the sentence
		}
	}

	 token = strtok(temp," ");

	   while( token != NULL )
   {
      printf( " %s\n", token );
      if(strcmp(token,title)==0)//use strtok to create substrings and use strcmp to compare them to the title , if it is equals , add one to the counter
      {
		  num++;
	  }

      token = strtok(NULL," ");
   }

   i=0;
   counter++;
   while(title[i]!='\0')
   {
	   if(title[i]==' ')
	   {
		   counter++;//finding the number of words in the title
	   }
   }

   s.weight=s.weight+(float)((float)num/(float)counter);//divide the counter over this result.


}

void findNumbers(doccument d)//finds how many numbers there are in the text
{
	paragraph* ptemp= d.content;
	sentence * stemp=ptemp->first;
	char c;
	int i;
	int n=0;
	while(ptemp->next!=NULL)//traverse every paragraph in the doccument
	{
		while(stemp->next!=NULL)//travarse every sentenec in a paragraph
		{
			i=0;
			while((c=stemp->content[i])!='\0')//traverse every char in a sentence
			{
				if(30<=c&&c<=39)//using ascii code , we find if it is a number
				n++;//if it is a number , we add it to a counter
			}
			stemp=stemp->next;
		}
		ptemp=ptemp->next;
	}
	d.numbers=n;//the ammount of numbers in this doccument is n
}

void hasNumbers(sentence s, int numbers)//a function that finds the ratio between numbers in a sentence and total numbers in the text
{
	int i=0;
	int n;
	char c;
	while((c=s.content[i])!='\0')
	{
		if(30<=c&&c<=39)
		n++;
	}
	s.weight= s.weight+(float)((float)n/(float)numbers);
}

void findLongest(doccument d)//a function that returns the length of the longest sentence in the text.
{
	paragraph* ptemp= d.content;
	sentence * stemp=ptemp->first;
	int max=0;//assume a value for max

	while(ptemp->next!=NULL)
	{
		while(stemp->next!=NULL)
		{
			if(strlen(stemp->content)>max)//if the length of the string is bigger than max , then max is equals to length of this string
			max=strlen(stemp->content);
			stemp=stemp->next;
		}
		ptemp=ptemp->next;
	}
	d.longest=max;
}

void sentenceLengthFeature(sentence s , int longest)// a function that finds the ratio between this sentence and the longest one in the text
{
	int i=0;
	int n=1;//there is at least one word in a sentence
	char c;
	while((c=s.content[i])!='\0')//getting the char at an index in the string
	{
		i++;
		if(c==' '||c=='\n')
		{
			n++;//finding the number of white spaces
		}
	}
	s.weight=s.weight+(float)(n/(float)longest);//calculating sentence length feature and adding it to the weight

}

void sentenceLocationFeature(sentence s)//a function that finds the reciprocal of the index of the sentence in the paragraph
{
		s.weight= s.weight + (float)(1/(float)s.num);
}

