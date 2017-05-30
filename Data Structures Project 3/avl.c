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
	char* value;
	int ID;
	int status;
};

typedef struct avl_node_s avl_node_t;
typedef struct avl_node_t * avl_tree_t;

avl_node_t* findmin(avl_node_t*);
/* Create a new AVL tree. */
avl_node_t * avl_create() {
	avl_node_t *tree = NULL;

	if( ( tree = malloc( sizeof( avl_tree_t ) ) ) == NULL ) {
		return NULL;
	}

	tree = NULL;

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
	node->value = NULL;
	node->ID= 0;

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
void avl_balance( avl_node_t* tree ) {

	avl_node_t *newroot = NULL;

	newroot = avl_balance_node( tree );

	if( newroot != tree )  {
		tree = newroot; 
	}
}

/* Insert a new node. */
void avl_insert( avl_node_t *tree, char *value ) {
	avl_node_t *node = NULL;
	avl_node_t *next = NULL;
	avl_node_t *last = NULL;

	/* Well, there must be a first case */ 	
	if( tree == NULL ) {
		node = avl_create_node();
		strcpy(node->value,value);

		tree = node;

	/* Okay.  We have a root already.  Where do we put this? */
	} else {
		next = tree;

		while( next != NULL ) {
			last = next;

			if( strcmp(value,next->value)<0 ) {
				
				next = next->left;

			} else if( strcmp(value,next->value)>0 ) {
				next = next->right;

			/* Have we already inserted this node? */
			} else if( strcmp(value,next->value)==0 ) {
				/* This shouldn't happen. */	
			}
		}

		node = avl_create_node();
		strcpy(node->value,value);

		if(  strcmp(value,next->value)<0  ) last->left = node;
		if(  strcmp(value,next->value)>0 ) last->right = node;
		
	}

	avl_balance( tree );
}

/* Find the node containing a given value */
avl_node_t *avl_find_by_name( avl_node_t *tree, char* value ) {
	avl_node_t *current = tree;

	while( current && (strcmp(current->value,value)!=0) ) {
		if(strcmp(current->value,value)<0)
		
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
	printf( "%s: %d\n", node->value, avl_balance_factor( node ) );

	if( node->right ) avl_traverse_node_dfs( node->right, depth + 2 );
}

/* Do a depth first traverse of a tree. */
void avl_traverse_dfs( avl_node_t *tree ) {
	avl_traverse_node_dfs( tree, 0 );
}


avl_node_t *avl_find_by_id( avl_node_t *tree, int value ) {
	avl_node_t *current = tree;

	while( current && current->ID != value ) {
		if( value > current->ID )
			current = current->right;
		else
			current = current->left;
	}

	return current;
}

void deleteNode(avl_node_t *root, int code)
{
    // NULL case
    if (root == NULL) return ;

    // If the code to be deleted is smaller than the root's code,
    // then it lies in left subtree
    if (code < root->ID)
       deleteNode(root->left, code);

    // If the code to be deleted is greater than the root's code,
    // then it lies in right subtree
    else if (code > root->ID)
       deleteNode(root->right, code);

    // if code is same as root's code, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
         
            free(root);
            
        }
        else if (root->right == NULL)
        {
          
            free(root);
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        avl_node_t *temp = findmin(root->right);

        // Copy the inorder successor's content to this node
        root->ID = temp->ID;
        root->status=temp->status;
        strcpy(root->value,temp->value);

        // Delete the inorder successor
        deleteNode(root->right, temp->ID);
    }
    avl_balance_node(root);
}
avl_node_t* findmin(avl_node_t *node)
{
	avl_node_t *temp=node;
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp;
}

int main ()
{
	avl_node_t *TREE;
	TREE=avl_create();
	int i;
	for(i=0;i<5;i++)
	{
		avl_insert(TREE,(char*)i);
	}
	
	avl_traverse_dfs(TREE);
	return 0;
}

