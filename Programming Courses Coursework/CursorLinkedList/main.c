typedef unsigned int ptr;
struct node
{
    int element;
    ptr next;
}node;
typedef ptr LIST;
typedef ptr position;
struct node CURSOR_SPACE[ 27];
position cursor_alloc( void )
{
position p;
p = CURSOR_SPACE[0].next;
CURSOR_SPACE[0].next = CURSOR_SPACE[p].next;
return p;
}
void
cursor_free( position p)
{
CURSOR_SPACE[p].next = CURSOR_SPACE[0].next;
CURSOR_SPACE[0].next = p;
}

int is_empty( LIST L )
{
return( CURSOR_SPACE[L].next == 0);
}

int is_last( position p, LIST L)
{
return( CURSOR_SPACE[p].next == 0);
}

position find( int x, LIST L)
{
position p;
 p = CURSOR_SPACE[L].next;
 while( p && CURSOR_SPACE[p].element != x )
 p = CURSOR_SPACE[p].next;
 return p;
}

void delete( int x, LIST L )
{
position p, tmp_cell;
p = find_previous( x, L );
if( !is_last( p, L) )
{
tmp_cell = CURSOR_SPACE[p].next;
CURSOR_SPACE[p].next = CURSOR_SPACE[tmp_cell].next;
cursor_free( tmp_cell );
}
}

void insert( int x, LIST L, position p )
{
position tmp_cell;
tmp_cell = cursor_alloc( );
if( tmp_cell ==0 )
("Out of space!!!");
else
{
CURSOR_SPACE[tmp_cell].element = x;
CURSOR_SPACE[tmp_cell].next = CURSOR_SPACE[p].next;
CURSOR_SPACE[p].next = tmp_cell;
}}


position find_previous(int x , LIST L)
{
position p;
 p = CURSOR_SPACE[L].next;
 while( p && (CURSOR_SPACE[p].next.element) != x )
 p = CURSOR_SPACE[p].next;
 return p;
}
