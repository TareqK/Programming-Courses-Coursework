
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node* ptr;
struct node
{
    int element;
    ptr next;
}node;
typedef ptr LINKEDLIST;
typedef ptr LISTPOSITION;

LINKEDLIST createLINKEDLIST(){

return (LINKEDLIST)malloc(sizeof(LINKEDLIST));
}

void add(LINKEDLIST r , int x)

{
    LISTPOSITION temp;
    while(r->next!=NULL)
    {
    r=r->next;
    }

    temp=(LISTPOSITION)malloc(sizeof(node));
   temp->element=x;
    r->next=temp;
    temp->next=NULL;



}

int isEmpty(LINKEDLIST r)
{
    if (r->next==NULL)
    return 1;
    else
    return 0;
}

void insert(LINKEDLIST r,LISTPOSITION p,int x)
{
LISTPOSITION temp=NULL;
if(p==NULL){
    printf("error");
    return;
    }
    else
    {
   temp->element=x;
    temp->next=p->next;
    p->next=temp;
    }
    }
void del(LINKEDLIST r)
{
LISTPOSITION p;
p=r->next;
while(p!=NULL)
{
r->next=p->next;
free(p);
p=r->next;
}
}

LISTPOSITION search(LINKEDLIST r, int x)
{
if(isEmpty(r))
{return NULL;}
else
{
while(r->next!=NULL){
if(r->element==x)
return r;
r=r->next;
}}
printf("%d not found",x);
return NULL;
}

void lprint(LINKEDLIST r)
{
while(r!=NULL)
{

printf("%d",r->element);
r=r->next;
}
}


