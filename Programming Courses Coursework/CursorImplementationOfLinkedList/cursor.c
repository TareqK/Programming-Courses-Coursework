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
void insert(LIST,position,char []);
void add(LIST,position);
void printList(LIST );

void initializeCursorSpace(SpaceSize){
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
    return NULL;
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

void insert(LIST L,position p,char x[16]){
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

