#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node* ptr;
struct node
{
    char element[16];
    ptr next;
}node;
typedef ptr LIST;
typedef ptr position;
position add(LIST, char []);
LIST createlist();

void createCursor(LIST r, position last)
{
last->next=r;
}

position cursorAlloc(LIST r){
position p;
p=r->next;
r->next=p->next;
return p;
}

void cursorFree(LIST r , position p)
{
p->next=r->next;
r->next=p;


}

position find(LIST r , char x[])
{
position p;
p=r->next;
while(p->next!=r && strcmp(p->element,x)!=0)
p=p->next;
return p;
}



position findPre(LIST r,  char x[])
{
position p = find(r,x);
position lastP =r;
while(lastP->next!=r && lastP->next!=p){
lastP=lastP->next;
}
return lastP;
}

void cursorDel(LIST r ,char x[])
{
position p;
position temp;
p = findPre(r,x);
if(!isLast(r,p))
{
temp=p->next;
p->next=temp->next;
cursorFree(r ,temp);
}
}

int isLast(LIST r, position p)
{
if(p->next==r)
return 1;
else
return 0;
}

void cursorInsert(LIST r,position p,char x[])
{
position temp;
temp=cursorAlloc(r);
if(temp==r)
{
printf("Out of space");
return;
}
else
{
strcpy(temp->element,x);
temp->next=p->next;
p->next=temp;

}
}

void cursorPrint(LIST r){
position p=r;
do
{
printf("%s",p->element);
p=p->next;
}while(p!=r);
}

