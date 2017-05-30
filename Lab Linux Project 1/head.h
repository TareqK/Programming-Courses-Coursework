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

typedef struct doccument{

	int length;//the number of sentences in our doccument
	sentence* content;//the content of our doccument
	char title[80];//the title of our doccument
	int longest;//the length of the longest sentence
	int numbers;//the instances of numbers in this doccument
}doccument;


void create_doccument(doccument*,FILE*);
void findLongest(doccument*);
void findNumbers(doccument*);
void hasNumbers(sentence*,int);
sentence* insert(sentence*,sentence*,sentence*);
sentence* insertion_sort(sentence*);
void print_doccument(doccument*,int,FILE*);
void rank(sentence*,doccument*);
void sentenceLengthFeature(sentence*,int);
void sentenceLocationFeature(sentence*);
void titleWordFeatures(sentence*,char*);
void summarize_doccument(doccument*,int,FILE*);
