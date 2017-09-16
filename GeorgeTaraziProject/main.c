#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct word{
	
	char content[10];
	int length;
	int instances;
}word;

typedef struct sentence{
	
	word content[80];
	int length;
}sentence ;

void remove_special(word* w);
void purify(sentence* w);//goes over all words and applies remove_special
void calculate_length(word* w);//calculates the length of a wrod
void find_and_delete_duplicate(sentence* s);//removes duplicate words
void sort_sentence(sentence * s);//sorts the setence structure
void print_sentence(sentence s);//prints the sentence strcuture
void read_from_file(sentence * s,FILE* in)//reads the sentence structure from a file
{
	int i=0;
	int j=0;
	int c;
do{
	
	while((c=fgetc(in))!=EOF)
	{
		if(c!=' ' || c!='\n'){
		s->content[i].content[j]=c;
		j++;
	}
	else
	{
		break;
	}
	}
	
	s->content[i].content[j]='\0';
	j=0;
	i++;
	
}while(c!=EOF);
	
}

void print_sentence(sentence s)
{
 int i;
 for(i=0;i<s.length;i++)
 {
	 printf("%s\n",s.content[i].content);
 }
	
}


void remove_special(word* w)
{
	int i;
	char c;
	calculate_length(w);
	for(i=0;i<w->length;i++)
	{
		c= w->content[i];
		if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
		{
		int j;
		for(j=i;j<i-1;i++)
		{
			w->content[j]=w->content[j+1];
		}
		w->length=w->length - 1;	
		}
	}
}

void calculate_length(word* w)
{
	w->length=strlen(w->content);
}

void find_and_delete_duplicate(sentence * s)
{
	int i;
	int j;
	int k;
	for(i=0;i<s->length;i++)
	{
		s->content[i].instances=1;
		for(j=0;j<s->length;j++)
		{
			if((strcmp(s->content[i].content,s->content[j].content))==0)
			{
				s->content[i].instances=s->content[i].instances +1;
				for(k=j;k<s->length-1;k++)
				{
					s->content[k]=s->content[k+1];
					s->length=s->length -1 ;
				}
			}
		}
	}
}

void sort_sentence(sentence * s)
{
	
	int i,j;
	word temp;
	for(i=0;i<(s->length-1);i++)
	{
		for(j=0;j<(s->length-i-1);j++)
		{
			if(s->content[j].length>s->content[j+1].length)
			{
				temp=s->content[j];
				s->content[j]=s->content[j+1];
				s->content[j+1]=temp;
			}
		}
	}


}




int main()
{
	sentence z;
	sentence *s=&z;
	FILE* in= fopen("input.txt");
	read_from_file(s,in);
	
	
	
}


