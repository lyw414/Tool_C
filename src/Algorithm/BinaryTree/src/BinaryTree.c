#include "BinaryTree.h"
bool SetValue_for_BinaryTree_Node (struct _binary_tree_Node * self, void * value )
{
    if ( value == NULL )
    {
        UserError ( "in %s :: Value Is NULL!",__func__ );
        return false;
    }
    if ( self == NULL )
    {
        UserError ( "in %s :: Self Is NULL!",__func__ );
        return false;
    }
    memset ( self -> data, value, self->data_size );
    return true;
}

bool SetLeftChild_for_BinaryTree_Node (struct _binary_tree_Node * self, struct _binary_tree_Node * pNode)
{
   if ( self == NULL )
    {
        UserError ( "in %s :: Self Is NULL!",__func__ );
        return false;
    }
    self -> pLeftChild = pNode;
    return true;
}

bool SetRightChild_for_BinaryTree_Node (struct _binary_tree_Node * self, struct _binary_tree_Node * pNode)
{
    if ( self == NULL )
    {
        UserError ( "in %s :: Self Is NULL!",__func__ );
        return false;
    }
    self -> pRightChild = pNode;
    return true;
}

bool GetLeftChild_for_BinaryTree_Node (struct _binary_tree_Node * self, struct _binary_tree_Node * pNode)
{
    if ( self == NULL )
    {
        UserError ( "in %s :: Self Is NULL!",__func__ );
        return false;
    }
 
    if ( ( pNode = self -> pLeftChild ) == NULL )
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool GetRightChild_for_BinaryTree_Node (struct _binary_tree_Node * self, struct _binary_tree_Node * pNode)
{
    if ( self == NULL )
    {
        UserError ( "in %s :: Self Is NULL!",__func__ );
        return false;
    }
 
    if ( ( pNode = self -> pRightChild ) == NULL )
    {
        return false;
    }
    else
    {
        return true;
    }

}

bool init_for_BinaryTree_Node  ( struct _binary_tree_Node * self)
{
    if ( self == NULL )
    {
        UserError ( "in %s :: Self Is NULL!",__func__ );
        return false;
    }
    self -> data = malloc ( self -> data_size );
    return true;
}
bool free_for_BinaryTree_Node  ( struct _binary_tree_Node * self)
{
    if ( self == NULL )
    {
        UserError ( "in %s :: Self Is NULL!",__func__ );
        return false;
    }
    if ( self -> data != NULL )
    {
        free ( self -> data );
        self -> data = NULL;
    }
    if ( self -> pLeftChild != NULL )
    {
        free ( self -> pLeftChild );
        self -> pLeftChild = NULL;
    }
    if ( self -> pRightChild != NULL )
    {
        free ( self -> pRightChild );
        self -> pRightChild = NULL;
    }
    return true;
}
bool clear_for_BinaryTree_Node  ( struct _binary_tree_Node * self)
{
    if ( self == NULL )
    {
        UserError ( "in %s :: Self Is NULL!",__func__ );
        return false;
    }

    memset ( self -> data,0x00,self -> data_size );
    self -> data = NULL;

    if ( self -> pLeftChild != NULL )
    {
        free ( self -> pLeftChild );
        self -> pLeftChild = NULL;
    }

    if ( self -> pRightChild != NULL )
    {
        free ( self -> pRightChild );
        self -> pRightChild = NULL;
    }

    return true;
}

int breadth_first_travel_for_BinaryTree ( struct _binary_tree * self,TBinaryTree_Node NodeArray[],void ( * Node_Do ) ( PBinaryTree_Node * pNode) )
{

    int index = 0;
    if ( self == NULL )
    {
        UserError ( "in %s :: Self Is NULL!",__func__ );
        return 0;
    }

    if ( self -> empty(self) )
    {
        UserError ( "in %s :: BinaryTree [%s] Is Empty!",__func__,self -> szBinaryTreeName);
        return 0;
    }
    PBinaryTreeNode tmpnode = &(self->root_node);
    PBinaryTreeNode tmpnode1 = NULL;
    void * value = NULL;
    //init queue for binarytree
    List(BinaryTreeQueue,PBinaryTree_Node);
    BinaryTreeQueue.init(&BinaryTreeQueue);
    //push_back root_node
    BinaryTreeQueue.push_back ( &BinaryTreeQueue, &tmpnode )
    while ( !BinaryTreeQueue.empty(&BinaryTreeQueue) )
    {
        BinaryTreeQueue.pop_front(&BinaryTreeQueue,(void *)(&tmpnode));

        if ( Node_DO != NULL )
        {
            Node_DO ( tmpnode );
        }

        if ( NodeArray != NULL )
        {
            memcpy ( &NodeArray[index],tmpnode,sizeof(TBinaryTreeNode) );
        }

        if ( tmpnode->GetLeftChild(tmpnode,&tmpnode1) )
        {
            BinaryTreeQueue.push_back ( &BinaryTreeQueue,&tmpnode1);
        }

        if ( tmpnode->GetRightChild(tmpnode,&tmpnode1) )
        {
            BinaryTreeQueue.push_back ( &BinaryTreeQueue,&tmpnode1);
        }

        index++;
    }
    return index;
}
int pre_order_travel_for_BinaryTree ( struct _binary_tree * self,TBinaryTree_Node NodeArray[],void ( * Node_Do ) ( PBinaryTree_Node * pNode) )
{
    
}
int in_order_travel_for_BinaryTree ( struct _binary_tree * self,TBinaryTree_Node NodeArray[],void ( * Node_Do ) ( PBinaryTree_Node * pNode ) )
{

}
 int Post_Order_travel_for_BinaryTree ( struct _binary_tree * self,TBinaryTree_Node NodeArray[],void ( * Node_Do) ( PBinaryTree_Node * pNode) )
{

}
bool build_by_pre_and_in_for_BinaryTree ( struct _binary_tree * self, TBinaryTree_Node Pre[], TBinaryTree_Node In[], int Num )
{
    int index = 0;
    if ( self == NULL )
    {
        UserError ( "in %s :: Self Is NULL!",__func__ );
        return 0;
    }
    //
    if ( !self -> empty(self) )
    {
        self->clear(self);
        return 0;
    }


}
bool build_by_post_and_in_for_BinaryTree ( struct _binary_tree * self, TBinaryTree_Node Post[], TBinaryTree_Node In[], int Num )
{

}
bool free_for_BinaryTree ( struct _binary_tree * self )
{

}
bool init_for_BinaryTree ( struct _binary_tree * self )
{

}

bool empty_for_BinaryTree ( struct _binary_tree * self )
{
    if ( self == NULL )
    {
        UserError ( "in %s :: Self Is NULL!",__func__ );
        return 0;
    }
    if ( self -> node_num == 0)
    {
       return true;
    }
    else
    {
        return false;
    }
}

bool clear_for_BinaryTree ( struct _binary_tree * self )
{

}


