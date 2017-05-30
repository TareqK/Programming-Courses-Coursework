#define _XOPEN_SOURCE 500 /* Enable certain library functions (strdup) on linux. See feature_test_macros(7) */

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <assert.h>

struct avl_node_s {
	struct avl_node_s *left;
	struct avl_node_s *right;
	int value;
	int status;
	char name[20];
	char bdate[20];
	char edate[20];
	int class_ID;
};

typedef struct avl_node_s avl_node_t;

struct avl_tree_s {
	struct avl_node_s *root;
};

typedef struct avl_tree_s avl_tree_t;
avl_node_t *avl_find_previous(avl_tree_t*,char*);
avl_node_t *findmin(avl_node_t *);
void avl_copy(avl_node_t *, avl_node_t*);
void avl_in_order(avl_node_t *);
/* Create a new AVL tree. */
avl_tree_t *avl_create() {
	avl_tree_t *tree = NULL;

	if( ( tree = malloc( sizeof( avl_tree_t ) ) ) == NULL ) {
		return NULL;
	}

	tree->root = NULL;

	return tree;
}

/* Initialize a new node. */
avl_node_t *avl_create_node() {
	avl_node_t *node = NULL;

	if( ( node = malloc( sizeof( avl_node_t ) ) ) == NULL ) {
		return NULL;
	}

	node->left = NULL;
	node->right = NULL;
	node->value = 0;

	return node;
}

/* Find the height of an AVL node recursively */
int avl_node_height( avl_node_t *node ) {
	int height_left = 0;
	int height_right = 0;

	if( node->left ) height_left = avl_node_height( node->left );
	if( node->right ) height_right = avl_node_height( node->right );

	return height_right > height_left ? ++height_right : ++height_left;
}

/* Find the balance of an AVL node */
int avl_balance_factor( avl_node_t *node ) {
	int bf = 0;

	if( node->left  ) bf += avl_node_height( node->left );
	if( node->right ) bf -= avl_node_height( node->right );

	return bf ;
}

/* Left Left Rotate */
avl_node_t *avl_rotate_leftleft( avl_node_t *node ) {
 	avl_node_t *a = node;
	avl_node_t *b = a->left;

	a->left = b->right;
	b->right = a;

	return( b );
}

/* Left Right Rotate */
avl_node_t *avl_rotate_leftright( avl_node_t *node ) {
	avl_node_t *a = node;
	avl_node_t *b = a->left;
	avl_node_t *c = b->right;

	a->left = c->right;
	b->right = c->left;
	c->left = b;
	c->right = a;

	return( c );
}

/* Right Left Rotate */
avl_node_t *avl_rotate_rightleft( avl_node_t *node ) {
	avl_node_t *a = node;
	avl_node_t *b = a->right;
	avl_node_t *c = b->left;

	a->right = c->left;
	b->left = c->right;
	c->right = b;
	c->left = a;

	return( c );
}

/* Right Right Rotate */
avl_node_t *avl_rotate_rightright( avl_node_t *node ) {
	avl_node_t *a = node;
	avl_node_t *b = a->right;

	a->right = b->left;
	b->left = a;

	return( b );
}

/* Balance a given node */
avl_node_t *avl_balance_node( avl_node_t *node ) {
	avl_node_t *newroot = NULL;

	/* Balance our children, if they exist. */
	if(node!=NULL){
	if( node->left  !=NULL)
		node->left  = avl_balance_node( node->left  );
	if( node->right !=NULL )
		node->right = avl_balance_node( node->right );

	int bf = avl_balance_factor( node );

	if( bf >= 2 ) {
		/* Left Heavy */

		if( avl_balance_factor( node->left ) <= -1 )
			newroot = avl_rotate_leftright( node );
		else
			newroot = avl_rotate_leftleft( node );

	} else if( bf <= -2 ) {
		/* Right Heavy */

		if( avl_balance_factor( node->right ) >= 1 )
			newroot = avl_rotate_rightleft( node );
		else
			newroot = avl_rotate_rightright( node );

	} else {
		/* This node is balanced -- no change. */

		newroot = node;
	}
}
	return( newroot );
}

/* Balance a given tree */
void avl_balance( avl_tree_t *tree ) {

	avl_node_t *newroot = NULL;

	newroot = avl_balance_node( tree->root );

	if( newroot != tree->root )  {
		tree->root = newroot;
	}
}

/* Insert a new node.Based on lexographic order */
void avl_insert( avl_tree_t *tree, int value ,int status, int class_ID,char* bdate, char* edate,char* name) {
	avl_node_t *node = NULL;
	avl_node_t *next = NULL;
	avl_node_t *last = NULL;

	/* Well, there must be a first case */
	if( tree->root == NULL ) {
		node = avl_create_node();
		node = avl_create_node();
		node->value=value;
		node->status=status;
		strcpy(node->name,name);
		strcpy(node->bdate,bdate);
		strcpy(node->edate,edate);
		node->class_ID=class_ID;

		tree->root = node;
	/* Okay.  We have a root already.  Where do we put this? */
	} else {
		next = tree->root;

		while( next != NULL ) {
			last = next;

			if( strcmp(name,next->name)<0) {
				next = next->left;

			} else if( strcmp(name,next->name)>0) {
				next = next->right;

			/* Have we already inserted this node? */
			} else if( strcmp(name,next->name)==0||value==next->value) {
				
			}
		}

		node = avl_create_node();
		node->value=value;
		node->status=status;
		strcpy(node->name,name);
		strcpy(node->bdate,bdate);
		strcpy(node->edate,edate);
		node->class_ID=class_ID;


		if(  strcmp(name,last->name)<0) last->left = node;
		if( strcmp(name,last->name)>0 ) last->right = node;

	}

	avl_balance( tree );
}






void avl_in_order_tree(avl_tree_t *Tree)
{
	avl_in_order(Tree->root);
}

void avl_delete(avl_tree_t *tree,avl_node_t *node )
{

	avl_node_t *prevnode;



	if(node!=NULL){
	if(node->right==NULL && node->left==NULL)
	{
        prevnode=avl_find_previous(tree,node->name);
        prevnode->left=NULL;
        prevnode->right=NULL;
		free(node);
		node=NULL;

		avl_balance(tree);
		return;
	}

	else if(node->right==NULL&&node->left !=NULL)
	{
		prevnode=avl_find_previous(tree,node->name);
		prevnode->left=node->left;
		node->left=node->right;
		free(node);
		node=NULL;
		avl_balance(tree);
		return;
	}
	else if(node->left==NULL&&node->right!=NULL)
	{
		prevnode=avl_find_previous(tree,node->name);
		prevnode->right=node->right;
		node->right=node->left;
		free(node);
		node=NULL;
		avl_balance(tree);
		return;

	}
	else if(node->right!=NULL && node->left!=NULL)
	{
		avl_node_t * temp=findmin(node->right);
		avl_copy(node,temp);
		avl_delete(tree,temp);
		free(node);
		node=NULL;
		avl_balance(tree);
		return;

	}
}
}
avl_node_t *avl_find_previous(avl_tree_t *tree, char* key )
{
		avl_node_t *current = tree->root;
		avl_node_t *temp;


	while( current && (strcmp(current->name,key) != 0)) {
		if( strcmp(current->name,key)<0 ){
			temp=current;
			current = current->right;
		}
		else{
			temp=current;
			current = current->left;
		}
	}

	return temp;
}

avl_node_t *findmin(avl_node_t *node)
{
	avl_node_t* temp =node;
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp;
}

void avl_copy(avl_node_t * dest, avl_node_t *src)
{

	dest->value=src->value;
	dest->status=src->status;
	strcpy(dest->name,src->name);
	strcpy(dest->bdate,src->bdate);
	strcpy(dest->edate,src->edate);
	dest->class_ID=src->class_ID;
}

/* Balance a given node */
avl_node_t *avl_balance_node_by_name( avl_node_t *node ) {
	avl_node_t *newroot = NULL;

	/* Balance our children, if they exist. */
	if( node->left )
		node->left  = avl_balance_node( node->left  );
	if( node->right )
		node->right = avl_balance_node( node->right );

	int bf = avl_balance_factor( node );

	if( bf >= 2 ) {
		/* Left Heavy */

		if( avl_balance_factor( node->left ) <= -1 )
			newroot = avl_rotate_leftright( node );
		else
			newroot = avl_rotate_leftleft( node );

	} else if( bf <= -2 ) {
		/* Right Heavy */

		if( avl_balance_factor( node->right ) >= 1 )
			newroot = avl_rotate_rightleft( node );
		else
			newroot = avl_rotate_rightright( node );

	} else {
		/* This node is balanced -- no change. */

		newroot = node;
	}

	return( newroot );
}


void avl_read_file(avl_tree_t * tree)
{
	FILE* in;
	in=fopen("student.txt","r");

	int value;
	int status;
	int i;
	char name[20];
	char bdate[20];
	char edate[20];
	int class_ID;
	char temp[60];

	if(in==NULL)
	{
		printf("file not read");
		return;
	}

	while((fscanf(in,"%d,%d,%d",&value,&status,&class_ID))!=EOF)
	{
		for(i=0;i<60;i++)
		{
			temp[i]=fgetc(in);
			if(temp[i]=='\n'||temp[i]==EOF)
			{
				temp[i]='\0';
				break;
			}
		}
		char*token=strtok(temp,",");
		strcpy(bdate,token);
		token=strtok(NULL,",");
		strcpy(edate,token);
		token=strtok(NULL,",");
		strcpy(name,token);
		avl_insert(tree,value,status,class_ID,bdate,edate,name);

	}
	fclose(in);
	printf("file read succesfully\n");

}

void avl_in_order(avl_node_t *node)
{
	if(node!=NULL)
	{
		avl_in_order(node->left);
		printf("%s\n",node->name);
		avl_in_order(node->right);
	}
}

void avl_print_to_file(FILE* out,avl_node_t *node)
{


	if(node!=NULL)
	{
		avl_print_to_file(out,node->left);
		fprintf(out,"%d,%d,%d,%s,%s,%s\n",node->value,node->status,node->class_ID,node->bdate,node->edate,node->name);
		avl_print_to_file(out,node->right);
	}

}

int find_max_class(int i , avl_node_t *node)
{
	if(node!=NULL)
	{
		find_max_class(i,node->left);

		find_max_class(i,node->right);

		if(node->class_ID>i)
		{
			i=node->class_ID;
		}
	}



	return i;
}

void avl_print_by_class(int i,avl_node_t *node)
{
	if(node!=NULL)
	{

		avl_print_by_class(i,node->left);
		if(node->class_ID==i)printf("%d\n%d\n%d\n%s\n%s\n%s\n__________\n",node->value,node->status,node->class_ID,node->bdate,node->edate,node->name);
		avl_print_by_class(i,node->right);



	}




}

void avl_print_by_class_tree(int i , avl_tree_t *tree)
{


	if(i!=0){
	avl_print_by_class(i,tree->root);
	avl_print_by_class_tree(i-1,tree);
}

}

void avl_print_undergrad(avl_node_t *node)
{
	if(node!=NULL)
	{
		avl_print_undergrad(node->left);
		if(node->status==0)printf("%d\n%d\n%d\n%s\n%s\n%s\n________\n",node->value,node->status,node->class_ID,node->bdate,node->edate,node->name);
		avl_print_undergrad(node->right);
	}
}

void avl_print_grad_tree(avl_node_t *node)
{
	if(node!=NULL)
	{
		avl_print_grad_tree(node->left);
		if(node->status==1)printf("%d\n%d\n%d\n%s\n%s\n%s\n__________\n",node->value,node->status,node->class_ID,node->bdate,node->edate,node->name);
		avl_print_grad_tree(node->right);
	}
}
void avl_delete_student(avl_tree_t *tree, avl_node_t *node,int key)
{
	if(node!=NULL)
	{
		avl_delete_student(tree,node->left,key);
		if(node->value==key)avl_delete(tree,node);
		avl_delete_student(tree,node->right,key);

	}

}

void edit_by_id(avl_tree_t *tree, avl_node_t *node,int key)
{
	if(node!=NULL)
	{
		edit_by_id(tree,node->left,key);
		if(node->value==key)avl_edit(tree,node);
		edit_by_id(tree,node->right,key);

	}

}

void find_dup_id(avl_tree_t *tree, avl_node_t *node,int key)
{
	if(node!=NULL)
	{
		find_dup_id(tree,node->left,key);
		if(node->value==key){printf("an error has occured; this ID has been entered before");exit(0);}
		find_dup_id(tree,node->right,key);

	}

}

void avl_edit(avl_tree_t *tree, avl_node_t * node)
{
printf("This is the data. Make your selection\n");
printf("1-%d\n2-%d\n3-%d\n4-%s\n5-%s\n6-%s\n",node->value,node->status,node->class_ID,node->bdate,node->edate,node->name);
int c;
scanf("%d",&c);

switch (c)
{
case 1:
scanf("%d",&node->value);
break;
case 2:
scanf("%d",&node->status);
break;
case 3:
scanf("%d",&node->class_ID);
break;
case 4:
scanf("%s",node->bdate);
break;
case 5:
scanf("%s",node->edate);
break;
case 6:
scanf("%s",node->name);
break;



}

}


void avl_delete_grad(avl_tree_t *tree, avl_node_t *node)
{
	if(node!=NULL)
	{
		avl_delete_grad(tree,node->left);
		if(node->status==1)avl_delete(tree,node);
		avl_delete_grad(tree,node->right);

	}

}

void avl_insert_from_user(avl_tree_t * tree)
{

    int value;
	int status;
	char name[20];
	char bdate[20];
	char edate[20];
	int class_ID;

	scanf("%d",&value);
	scanf("%d",&status);
	scanf("%d",&class_ID);
	scanf("%s",name);
	scanf("%s",bdate);
	scanf("%s",edate);

	avl_insert(tree,value,status,class_ID,bdate,edate,name);



}
int main(){

	FILE* out= fopen("student_data.csv","w");
	avl_tree_t *Tree=avl_create();
	avl_read_file(Tree);
	int c;
	int j;
	while(1){
	printf("please make your selection\n1-print grad\n2-print undergrad\n3-delete grad\n4-print tree in lex order\n5-print class order\n6-Insert from terminal\n7-edit Student by ID \n8-Print to file\n9-del Student by Id\npress any other key to exit\n");
    scanf("%d",&c);
    switch(c){
    case 1:avl_print_grad_tree(Tree->root);
    break;
    case 2:avl_print_undergrad(Tree->root);
    break;
    case 3:avl_delete_grad(Tree,Tree->root);
    break;
    case 4:avl_in_order_tree(Tree);
    break;
    case 5:j=find_max_class(j,Tree->root);
    avl_print_by_class(j,Tree->root);
    break;
    case 6:avl_insert_from_user(Tree);
    break;
    case 7:
    scanf("%d",&j);
    edit_by_id(Tree,Tree->root,j);
    break;
    case 8:avl_print_to_file(out,Tree->root);
    break;
    
    case 9:
     scanf("%d",&j);
     avl_delete_student(Tree,Tree->root,j);
    break;
    default:
    exit(0);

    }

}
return 0;
}
