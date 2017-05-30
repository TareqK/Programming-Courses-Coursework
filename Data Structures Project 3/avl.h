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
avl_node_t *avl_find_previous(avl_tree_t*,int);
avl_node_t *findmin(avl_node_t *);
void avl_copy(avl_node_t *, avl_node_t*);
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

/* Balance a given tree */
void avl_balance( avl_tree_t *tree ) {

	avl_node_t *newroot = NULL;

	newroot = avl_balance_node( tree->root );

	if( newroot != tree->root )  {
		tree->root = newroot; 
	}
}

/* Insert a new node. */
void avl_insert( avl_tree_t *tree, int value ,int status, int class_ID,char* bdate, char* edate,char* name) {
	avl_node_t *node = NULL;
	avl_node_t *next = NULL;
	avl_node_t *last = NULL;

	/* Well, there must be a first case */ 	
	if( tree->root == NULL ) {
		node = avl_create_node();
		node->value = value;

		tree->root = node;

	/* Okay.  We have a root already.  Where do we put this? */
	} else {
		next = tree->root;

		while( next != NULL ) {
			last = next;

			if( value < next->value ) {
				next = next->left;

			} else if( value > next->value ) {
				next = next->right;

			/* Have we already inserted this node? */
			} else if( value == next->value ) {
				/* This shouldn't happen. */	
			}
		}

		node = avl_create_node();
		node->value=value;
		node->status=status;
		strcpy(node->name,name);
		strcpy(node->bdate,bdate);
		strcpy(node->edate,edate);
		node->class_ID=class_ID;
		

		if( value < last->value ) last->left = node;
		if( value > last->value ) last->right = node;
		
	}

	avl_balance( tree );
}

/* Find the node containing a given value */
avl_node_t *avl_find( avl_tree_t *tree, int value ) {
	avl_node_t *current = tree->root;

	while( current && current->value != value ) {
		if( value > current->value )
			current = current->right;
		else
			current = current->left;
	}

	return current;
}

/* Do a depth first traverse of a node. */
void avl_traverse_node_dfs( avl_node_t *node, int depth ) {
	int i = 0;

	if( node->left ) avl_traverse_node_dfs( node->left, depth + 2 );

	for( i = 0; i < depth; i++ ) putchar( ' ' );
	printf( "%d: %d\n", node->value, avl_balance_factor( node ) );

	if( node->right ) avl_traverse_node_dfs( node->right, depth + 2 );
}

/* Do a depth first traverse of a tree. */
void avl_traverse_dfs( avl_tree_t *tree ) {
	avl_traverse_node_dfs( tree->root, 0 );
}

void avl_delete(avl_tree_t *tree,int key)
{
	avl_node_t *node=avl_find(tree,key);
	avl_node_t *prevnode;
	
	if(node->right==NULL && node->left==NULL)
	{
		free(node);
		avl_balance(tree);
		return;
	}
	
	else if(node->right==NULL)
	{
		prevnode=avl_find_previous(tree,key);
		prevnode->left=node->left;
		free(node);
		avl_balance(tree);
		return;
	}
	else if(node->left==NULL)
	{
		prevnode=avl_find_previous(tree,key);
		prevnode->right=node->right;
		free(node);
		avl_balance(tree);
		return;
		
	}
	else if(node->right!=NULL && node->left!=NULL)
	{
		avl_node_t * temp=findmin(node->right);
		avl_copy(node,temp);
		avl_delete(tree,temp->value);
		free(node);
		avl_balance(tree);
		return;
		
	}
	
}
avl_node_t *avl_find_previous(avl_tree_t *tree,int key)
{
		avl_node_t *current = tree->root;
		avl_node_t *temp;
		

	while( current && current->value != key) {
		if( key > current->value ){
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
	FILE* in= fopen("student_data.csv","r");
	
	int value;
	int status;
	char name[20];
	char bdate[20];
	char edate[20];
	int class_ID;
	printf("file read succesfully");
	
	while((fscanf(in,"%d,%d,%d,%s,%s,%s",&value,&status,&class_ID,name,bdate,edate))!=EOF)
	{
		printf("file read succesfully");
		avl_insert(tree,value,status,class_ID,bdate,edate,name);
	}
	fclose(in);
	printf("file read succesfully");
}

int main(){
	
	
	printf("file read succesfully");
	avl_tree_t *Tree=avl_create();
	printf("file read succesfully");
	avl_read_file(Tree);
	printf("file read succesfully");
	avl_traverse_dfs(Tree);
	printf("file read succesfully");
	return 0;
}

