#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#include"head.h"






void create_doccument(doccument* z, FILE* fp){//a function that scans a file and creates a doccument

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

void print_doccument(doccument* d, int percent,FILE* op){//a function that prints the doccument to the user

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

void summarize_doccument(doccument *d,int percent,FILE* op){//a function that summaries a doccument to the user entered %


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

void rank(sentence *s, doccument* d){//a function that ranks a sentence according to our criteria

	titleWordFeatures(s,d->title);
	sentenceLengthFeature(s,d->longest);
	sentenceLocationFeature(s);
	hasNumbers(s,d->numbers);
}

void titleWordFeatures(sentence *s, char* title){// a function that finds the ratio of the number of instances of the word in the sentance to the instances of the title
char* temp=s->content;
int counter=0;
while((temp=strstr(temp, title)) != NULL){
	counter++;
	}
	s->weight=s->weight+(float)((counter*(float)strlen(title))/(float)(s->length+strlen(title)));//divide the counter over this result.
}


void findNumbers(doccument* d){//finds how many numbers there are in the text

	sentence * stemp=d->content;
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

void hasNumbers(sentence* s, int numbers){//a function that finds the ratio between numbers in a sentence and total numbers in the text

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

void findLongest(doccument* d){//a function that returns the length of the longest sentence in the text.


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

void sentenceLengthFeature(sentence *s , int longest){// a function that finds the ratio between this sentence and the longest one in the text


	s->weight=s->weight+(float)(s->length/(float)longest);//calculating sentence length feature and adding it to the weight

}

void sentenceLocationFeature(sentence *s){//a function that finds the reciprocal of the index of the sentence in the paragraph

		s->weight= s->weight + (float)(1/(float)s->num);
}

sentence* insertion_sort(sentence* begin){

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


#endif // HEAD_H_INCLUDED
