#include "BST.h"

typedef struct _my_data
{
    int key;
    char data[64];
} TMy_Data,* PMy_Data;

int cmp ( void * p, void * p1 )
{
    PMy_Data d1 = (PMy_Data)p;
    PMy_Data d2 = (PMy_Data)p1;

    if ( d1->key > d2->key )
    {
        return 2;
    }

    if ( d1->key < d2->key )
    {
        return 1;
    }

    if ( d1->key == d2->key )
    {
        return 0;
    }

    return -1;
}

BST (bst,TMy_Data,cmp);

void  do_node_x ( PBST_Node node )
{
    PMy_Data d = (PMy_Data)(node->data);
    printf ( "Key [%d] Value [%s]!\n",d->key,d->data);
}

void set_my_data ( int key, PMy_Data p )
{
    p->key = key;
    memset ( p->data,0x00,sizeof ( p->data ) );
    sprintf ( p->data,"%d",key );
}

void add_num ( )
{
    TMy_Data d;
    int iLoop = 0;

    set_my_data ( 10,&d );
    bst.add ( &bst,&d );

    for ( iLoop = 0; iLoop < 20; iLoop++)
    {
        set_my_data ( iLoop,&d );
        bst.add ( &bst,&d );
    }

    set_my_data ( 10,&d );
    bst.add ( &bst,&d );
}

int main ()
{
    int iLoop = 0;
    int ret = 0;
    Init_Log("Test_BinaryTree","./log/",DEBUG_LEVEL,10,PTHREAD_MODE);
    bst.init ( &bst );
    add_num();
    //bst.post_order_travel(&bst,NULL,do_node_x);
    //bst.pre_order_travel(&bst,NULL,do_node_x);
    //bst.in_order_travel(&bst,NULL,do_node_x);
    //bst.breadth_first_travel(&bst,NULL,do_node_x);

    TMy_Data d;
    d.key = 10;
    PMy_Data pout = (PMy_Data)malloc ( sizeof ( TMy_Data ) * 10 );

    ret = bst.find ( &bst, &d, pout);
    for ( iLoop = 0; iLoop < ret ; iLoop++ )
    {
        printf ( "Key [%d] Value [%s]!\n",pout[iLoop].key,pout[iLoop].data);
    }
    
    bst.del ( &bst,&d);

    d.key = 5;
    ret = bst.find ( &bst, &d, pout);
    for ( iLoop = 0; iLoop < ret ; iLoop++ )
    {
        printf ( "Key [%d] Value [%s]!\n",pout[iLoop].key,pout[iLoop].data);
    }
 

    bst.free ( &bst );
    return 0;
}
