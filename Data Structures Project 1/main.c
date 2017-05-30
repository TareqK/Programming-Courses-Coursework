#define SpaceSpaceSize 100
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef unsigned int position;
struct node
{
    char element[16];
    position next;
};
typedef position LIST;
struct node cursor[SpaceSpaceSize];
LIST Char_buckets[2][27];

void initializeCursorSpace(int);
position cursorAlloc();
void insert(position ,char []);
void add(LIST,position);
void printList(LIST );



int main()
{
    char outputToFile[100][16];
    char inputFromFile[100][16];
    int i;
    int c;
    int arraysize=1;


    FILE* input = fopen("input.txt", "r");
    FILE* output= fopen("output.txt", "w");
    char buff[16];
    do
    {
        for(i=0; i<15; i++)
        {

            c=fgetc(input);
            buff[i]=c;

            if(c==EOF||c=='\n')
            {
                buff[i+1]='\0';
                break;
            }

        }
        {
            strcpy(inputFromFile[i],buff);
            arraysize++;
        }
    }

    while(c!=EOF);
   //sortRadix(outputToFile,inputFromFile,arraysize);

    for(i=0;i<=arraysize;i++)
    {
    printf("%s",inputFromFile[i]);
    }




    return 0;
}


void initializeCursorSpace(int SpaceSize){
    int i;
    for (i=0;i<SpaceSize - 1;i++)
    {
        cursor[i].next = i+1;
    }
    cursor[SpaceSize - 1].next = 0;
    for (i=0 ; i<27 ; i++)
    {
        Char_buckets[0][i] = cursorAlloc();
        Char_buckets[1][i] = cursorAlloc();
    }
}


position cursorAlloc(){
    if (cursor[0].next == 0){
    printf("Memory is Full!");
    return 0;
    }
    else
    {
        position p;
        p = cursor[0].next;
        cursor[0].next = cursor[p].next;
        cursor[p].next = 0;
        return p;
    }
}

void insert(position p,char x[16]){
    position n = cursorAlloc();
    strcpy(cursor[n].element,x);
    cursor[n].next = cursor[p].next;
    cursor[p].next = n;
}
void add(LIST l,position n){
        position temp = l;
        while (cursor[temp].next!=0)
        {
            temp = cursor[temp].next;
        }
        cursor[temp].next = n;
        cursor[n].next = 0;

}

void printList(LIST L) {
    position p = cursor[L].next;
    while (p != 0)
    {
        printf("%s\n",cursor[p].element);
        p = cursor[p].next;
    }
}
void sortRadix(char outputToFile[][16],char inputFromFile[][16],int arraysSize)
{
    char temp;                                      // char temp will be used to read char by char from each string //
    int count = 0, arrayCounter = 0;                // this counter will tell us when will we reach the last bucket //
    position n = cursor[Char_buckets[0][0]].next;        // this pointer will be used to check every node //
    int currentSet = 0;                             // the set of Char_buckets we are currently working on //
    int i,k;
    position p;

    for (i=0; i<arraysSize; i++)
    {
        temp = (cursor[n].element[14]);
        if (temp == ' ' || temp == '\0') temp = (int)'a' - 1;
        p = cursorAlloc();
        strcpy(cursor[p].element,outputToFile[i]);
        cursor[p].next = 0;
        insert(p,Char_buckets[0][(int) (temp - 'a' + 1)]);
    }


    for (i=1; i<15; i++)
    {
        while (count < 27)
        {
            while (n != 0)
            {
                temp = (cursor[n].element[14-i]);
                if (temp == ' ' || temp == '\0') temp = (int)'a' - 1;
                cursor[Char_buckets[currentSet][count]].next = cursor[n].next;
                insert(n,Char_buckets[!currentSet][(int) (temp - 'a' + 1)]);
                n = cursor[Char_buckets[currentSet][count]].next;
            }
            n = cursor[Char_buckets[currentSet][++count]].next;           // go to next bucket to sort //
        }
        currentSet = !currentSet;                                    // change current set of Char_buckets //
        count = 0;
        n = cursor[Char_buckets[currentSet][0]].next;
    }


    for (k=0; k<27; k++)
    {
        n = cursor[Char_buckets[0][k]].next;
        while (n != 0)
        {
            strcpy(inputFromFile[arrayCounter++],cursor[n].element);
            n = cursor[n].next;
        }
    }
}

