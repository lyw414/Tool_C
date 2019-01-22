#include <stdio.h>
#include "BinaryTree.h"

typedef struct _test
{
    int ID;
    char sID[64];
} test_str;

PBinaryTree pBinaryTree_src;
PBinaryTree pBinaryTree_tag;


PBinaryTree_Node New_Node ( int ID, char * szID )
{
    PBinaryTree_Node tmp;
    NEW_BinaryTree_Node(tmp,sizeof ( test_str ) );
    tmp->init(tmp);
    ((test_str *)(tmp->data))->ID = ID;
    strcpy( ((test_str *)(tmp->data))->sID,szID );
    //tmp->SetValue(tmp,&data)
    return tmp;
}

/* @brief gen binaryTree like follow
 * 
 *        A
 *
 *     /    \
 *    B      C
 *   / \      \ 
 *  D   E      I
 *    /   \   / 
 *   F     G J
 *    \
 *     H
 *
 */
void build_src()
{
    List ( tmplist,PBinaryTree_Node );
    tmplist.init(&tmplist);

    PBinaryTree_Node tmp;
    PBinaryTree_Node tmp1;
    PBinaryTree_Node tmp2;
    
    // A
    pBinaryTree_src->root_node = tmp = New_Node ( 0,"A" );
    tmp1 = New_Node ( 1, "B" );
    tmp2 = New_Node ( 2, "C" );
    tmplist.push_back(&tmplist,&tmp1);
    tmplist.push_back(&tmplist,&tmp2);

    tmp->SetLeftChild(tmp,tmp1);
    tmp->SetRightChild(tmp,tmp2);

    //B
    tmplist.pop_front (&tmplist,&tmp);

    tmp1 = New_Node ( 3,"D" );
    tmp2 = New_Node ( 4,"E" );

    tmplist.push_back(&tmplist,&tmp2);

    tmp->SetLeftChild(tmp,tmp1);
    tmp->SetRightChild(tmp,tmp2);

    //C
    tmplist.pop_front (&tmplist,&tmp);
    tmp1 = New_Node ( 8,"I" );
    tmplist.push_back(&tmplist,&tmp1);
    tmp->SetRightChild(tmp,tmp1);

    //D

    //E
    tmplist.pop_front (&tmplist,&tmp);

    tmp1 = New_Node ( 5,"F" );
    tmp2 = New_Node ( 6,"G" );

    tmplist.push_back(&tmplist,&tmp1);

    tmp->SetLeftChild(tmp,tmp1);
    tmp->SetRightChild(tmp,tmp2);
    
    // I
    tmplist.pop_front (&tmplist,&tmp);

    tmp1 = New_Node ( 9,"J" );

    tmp->SetLeftChild(tmp,tmp1);
 
    //F
    tmplist.pop_front (&tmplist,&tmp);
    tmp1 = New_Node ( 7,"H" );
    tmp->SetRightChild(tmp,tmp1);

    tmplist.free(&tmplist);
}

void shownode(PBinaryTree_Node pNode)
{
    printf ( "%s ",((test_str *)pNode->data)->sID);
}
int main ()
{
    int ret = 0;
    Init_Log("Test_BinaryTree","./log/",DEBUG_LEVEL,10,PTHREAD_MODE);
    NEW_BinaryTree (pBinaryTree_src,test_str);
    NEW_BinaryTree (pBinaryTree_tag,test_str);

    pBinaryTree_src -> init ( pBinaryTree_src );
    pBinaryTree_tag -> init ( pBinaryTree_tag );


    build_src();
    printf ("Src::\n");
    ret = pBinaryTree_src->breadth_first_travel(pBinaryTree_src,NULL,shownode);
    
    printf ("\n");
    PBinaryTree_Node * Pre = malloc ( sizeof ( void *) * ret );
    PBinaryTree_Node * In = malloc ( sizeof ( void *) * ret );

    pBinaryTree_src->pre_order_travel(pBinaryTree_src,Pre,shownode);
    printf ("\n");
    pBinaryTree_src->in_order_travel(pBinaryTree_src,In,shownode);
    printf ("\n");
    pBinaryTree_src->post_order_travel(pBinaryTree_src,NULL,shownode);
    printf ("\n");

    printf ("\nTag::\n");
    pBinaryTree_tag->build_by_pre_and_in( pBinaryTree_tag,Pre,In,ret);
    ret = pBinaryTree_tag->breadth_first_travel(pBinaryTree_tag,NULL,shownode);
    printf ("\n");
    ret = pBinaryTree_tag->pre_order_travel(pBinaryTree_tag,NULL,shownode);
    printf ("\n");
    ret = pBinaryTree_tag->in_order_travel(pBinaryTree_tag,NULL,shownode);
    printf ("\n");
    ret = pBinaryTree_tag->post_order_travel(pBinaryTree_tag,NULL,shownode);
    printf ("\n");
    
    pBinaryTree_tag->free(pBinaryTree_tag);
    pBinaryTree_tag->free(pBinaryTree_src);
    return 0;
}

