#include "BST.h"
static void Free_Node_BST ( struct _BST_Node * node )
{
    if ( node != NULL )
    {
        if ( node -> data != NULL )
        {
            free ( node -> data );
        }

        free ( node );
    }
}
bool set_value_BST_Node ( struct _BST_Node * self, void * data )
{
    if ( self -> data == NULL )
    {
        self -> data = malloc ( self -> data_size );
    }
    memcpy ( self -> data, data, self -> data_size );
    return true;
}

bool get_value_BST_Node ( struct _BST_Node * self, void * data )
{
    if( self -> data == NULL )
    {
        return false;
    }
    memcpy ( data, self -> data, self -> data_size );
    return true;
}

bool init_BST_Node ( struct _BST_Node * self )
{
    if ( self -> data != NULL )
    {
        free ( self -> data );
    }
    if ( self -> data_size != 0 )
    {
        self -> data = malloc ( self -> data_size );
    }
    else
    {
        UserError ( "in %s :: Data_Size is 0!",__func__);
        return false;
    }
    return true;
}

bool clear_BST_Node ( struct _BST_Node * self )
{
    if ( self -> data == NULL )
    {
        self -> data = malloc ( self -> data_size );
    }
    memset ( self -> data, 0x00, self -> data_size );
    return true;
}

bool free_BST_Node ( struct _BST_Node * self )
{
    if ( self -> data != NULL )
    {
        free ( self -> data );
    }
    self -> data_size = 0;
    self -> pLeftChildNode = NULL;
    self -> pRightChildNode = NULL;
    return true;
}

bool add_BST(struct _BST * self,void * data)
{

    PBST_Node before = NULL ;
    int ret = 0;
    if ( self == NULL )
    {
        UserError ( "in %s :: BST is unusefull!",__func__);
        return false;
    }

    if ( data == NULL )
    {
        UserError ( "in %s :: BST [%s] data is NULL!",__func__,self -> szBSTName);
        return false;
    }

    if ( self -> empty ( self ) )
    {
        NEW_BST_Node ( self -> root_node, self -> data_size );
        self -> root_node -> init ( self -> root_node );
        self -> root_node -> set_value ( self -> root_node, data );
        return true;
    }

    before = self -> root_node;

    while ( true )
    {
        ret = self -> compare_func ( before -> data, data );
        switch ( ret )
        {
            case 0 :
            case 1 :
               if ( before -> pRightChildNode != NULL )
               {
                    before = before -> pRightChildNode;
               }
               else
               {
                    NEW_BST_Node ( before -> pRightChildNode, self -> data_size );
                    before -> pRightChildNode -> init ( before -> pRightChildNode );
                    before -> pRightChildNode -> set_value ( before -> pRightChildNode,data);
                    return true;
               }
               break;
            case 2 :
               if ( before -> pLeftChildNode != NULL )
               {
                    before = before -> pLeftChildNode;
               }
               else
               {
                    NEW_BST_Node ( before -> pLeftChildNode, self -> data_size );
                    before -> pLeftChildNode -> init ( before -> pLeftChildNode );
                    before -> pLeftChildNode -> set_value ( before -> pLeftChildNode, data);
                    return true;
               }
               break;
            default :
                UserError ( "in %s :: BST [%s] compare_func return unkown compare result [%d]!",__func__,self -> szBSTName,ret);
                return false;
        }
    }
    return true;
}

int find_BST(struct _BST * self,void *data, void * dataout)
{
    PBST_Node before = NULL ;
    int ret = 0;
    int Loop = 0;
    if ( self == NULL )
    {
        UserError ( "in %s :: BST is unusefull!",__func__);
        return -1;
    }

    if ( data == NULL )
    {
        UserError ( "in %s :: BST [%s] data is NULL!",__func__,self -> szBSTName);
        return -1;
    }

    if ( self -> empty ( self ) )
    {
        return 0;
    }

    before = self -> root_node;

    while ( true )
    {
        ret = self -> compare_func ( before -> data, data );
        switch ( ret )
        {
            case 0 :
               memcpy ( dataout + Loop  * self -> data_size,before -> data,self -> data_size );
               Loop++;
            case 1 :
               if ( before -> pRightChildNode != NULL )
               {
                    before = before -> pRightChildNode;
               }
               else
               {
                    return Loop;
               }
               break;
            case 2 :
               if ( before -> pLeftChildNode != NULL )
               {
                    before = before -> pLeftChildNode;
               }
               else
               {
                    return Loop;
               }
               break;
            default :
                UserError ( "in %s :: BST [%s] compare_func return unkown compare result [%d]!",__func__,self -> szBSTName,ret);
                return false;
        }
    }
    return Loop;

}


int del_BST(struct _BST * self,void * data )
{
    int iLoop = 0;
    int ret = 0;
    PBST_Node before = NULL;
    PBST_Node after = NULL;
    PBST_Node after_after = NULL;
    PBST_Node tmp = NULL;

    PBST_Node before_left_child_tree_right_end = NULL;
    PBST_Node left_child_tree_right_end = NULL;

    if ( self == NULL )
    {
        UserError ( "in %s :: BST is NULL!",__func__);
        return -1;
    }
    
    if ( data == NULL )
    {
        UserError ( "in %s :: BST [%s] del data is NULL!",__func__,self->szBSTName);
        return -1;

    }

    if ( self == NULL )
    {
        UserError ("in %s :: BST [%s] compare_func is NULL!",__func__,self->szBSTName);
        return -1;
    }

    if ( self -> empty ( self ) )
    {
        UserError ("in %s :: BST [%s] is Empty!",__func__,self -> szBSTName);
        return iLoop;
    }
    
    after = self -> root_node;

    while ( true )
    {

        if ( self -> empty ( self ) )
        {
            UserError ("in %s :: BST [%s] is Empty!",__func__,self -> szBSTName);
            return iLoop;
        }
 
        ret = self->compare_func (  after -> data, data );
        switch ( ret )
        {
            case 0 :
                iLoop++;
                // find left_child_tree right_end_node and father_node 
                before_left_child_tree_right_end = after -> pLeftChildNode;
                

                while ( before_left_child_tree_right_end != NULL )
                {
                    left_child_tree_right_end = before_left_child_tree_right_end -> pRightChildNode;
                    if ( left_child_tree_right_end != NULL &&  left_child_tree_right_end -> pRightChildNode != NULL )
                    {
                        before_left_child_tree_right_end = left_child_tree_right_end;
                    }
                    else
                    {
                        break;
                    }
                }

                // find left_tree continuous equaled node , use last one for after  
                after_after = after -> pRightChildNode;
                while ( true )
                {
                    if ( after_after != NULL && self->compare_func ( after_after -> data, data ) == 0 )
                    {
                        tmp = after_after -> pRightChildNode;
                        after_after ->free(after_after);
                        free(after_after);
                        after_after = tmp;
                        iLoop++;
                    }
                    else
                    {
                        break;
                    }
                }

                // delete those equal node 
                if ( before_left_child_tree_right_end == NULL )
                {
                    if ( before == NULL )
                    {
                        self->root_node = after_after;
                    }
                    else
                    {
                        before -> pRightChildNode = after_after;
                    }
                }
                else
                {
                    if ( left_child_tree_right_end == NULL )
                    {
                        if ( before == NULL )        
                        {
                            self -> root_node = before_left_child_tree_right_end;
                            self -> root_node -> pRightChildNode = after_after;
                        }
                        else
                        {
                            before -> pRightChildNode = before_left_child_tree_right_end;
                            before_left_child_tree_right_end -> pRightChildNode = after_after;
                        }
                    }
                    else
                    {
                        if ( before == NULL )
                        {
                            before_left_child_tree_right_end -> pRightChildNode = left_child_tree_right_end->pLeftChildNode;
                            left_child_tree_right_end->pLeftChildNode = after->pLeftChildNode;
                            left_child_tree_right_end->pRightChildNode = after_after;
                            self->root_node = left_child_tree_right_end;
                        }
                        else
                        {
                            before_left_child_tree_right_end -> pRightChildNode = left_child_tree_right_end->pLeftChildNode;
                            left_child_tree_right_end->pLeftChildNode = after->pLeftChildNode;
                            left_child_tree_right_end->pRightChildNode = after_after;
                            before -> pRightChildNode = left_child_tree_right_end;
                        }
                    }
                }
                after -> free ( after );
                free ( after );
                before_left_child_tree_right_end = NULL;
                left_child_tree_right_end = NULL;
                if ( before != NULL )
                {
                    after = before;
                }
                else
                {
                    after = self->root_node;
                }
            case 1 :
                if ( after -> pRightChildNode != NULL )
                {
                    before = after;
                    after = after -> pRightChildNode;
                }
                else
                {
                    return iLoop;
                }
            case 2 :
                if ( after -> pLeftChildNode != NULL )
                {
                    before = after;
                    after = after -> pLeftChildNode;
                }
                else
                {
                    return iLoop;
                }
            default :
                UserError ("in %s :: BST [%s] compare_func return unkown type [%d]!",__func__,self -> szBSTName, ret );
                return -1;
        }
            
    }
    return iLoop;
}


bool change_BST(struct _BST * self, void * data, void * data1)
{
    return true;
}

bool reBuild_BST(struct _BST * self)
{
    return true;
}

int pre_order_travel_BST(struct _BST * self,PBST_Node * Pre, void ( * Node_Do ) ( PBST_Node node ) )
{
    int index = 0;
    PBST_Node root_node = NULL;

    if ( self == NULL )
    {
        UserError ( "in %s :: BST is NULL",__func__);
        return -1;
    }

    if ( self -> empty ( self ) )
    {
        UserDebug ( "in %s :: BST [%s] is empty!",__func__, self -> szBSTName );
        return 0;
    }

    //Stack 
    List ( BST_Stack, PBST_Node );
    BST_Stack.init ( &BST_Stack );

    root_node = self -> root_node;
    
    while ( 1 )
    {
        if ( Pre != NULL )
        {
            Pre [index] = root_node ;
        }
        index++;

        if ( Node_Do != NULL )
        {
            Node_Do ( root_node );
        }

        if ( root_node -> pRightChildNode != NULL )
        {
            BST_Stack.push_back ( &BST_Stack, &(root_node -> pRightChildNode) );
        }

        if ( root_node -> pLeftChildNode != NULL )
        {
            root_node = root_node -> pLeftChildNode;
            continue;
        }
        else
        {
            if ( BST_Stack.empty ( &BST_Stack ) )
            {
                break;
            }
            BST_Stack.pop_back ( &BST_Stack, &root_node );
        }

    }

    BST_Stack.free ( &BST_Stack );

    return index;
}

int in_order_travel_BST(struct _BST * self,PBST_Node * Pre, void ( * Node_Do ) ( PBST_Node node ) )
{
    int index = 0;

    PBST_Node root_node = NULL;

    if ( self == NULL )
    {
        UserError ( "in %s :: BST is NULL",__func__);
        return -1;
    }
    if ( self -> empty ( self ) )
    {
        UserDebug ( "in %s :: BST [%s] is empty!",__func__, self -> szBSTName );
        return 0;
    }

    //Stack 
    List ( BST_Stack, PBST_Node);
    BST_Stack.init ( &BST_Stack );


    root_node = self -> root_node; 

    while ( 1 ) 
    {

        BST_Stack.push_back ( &BST_Stack, &root_node );

        if ( root_node -> pLeftChildNode != NULL )
        {
            root_node = root_node -> pLeftChildNode;
            continue;
        }
        else
        {
            while ( 1 )
            {
                if ( BST_Stack.empty ( &BST_Stack ) ) 
                {
                    BST_Stack.free( &BST_Stack );
                    return index;
                }

                BST_Stack.pop_back ( &BST_Stack, &root_node );

                if ( Pre != NULL )
                {
                    Pre[index] = root_node;
                }

                index++;

                if ( Node_Do != NULL )
                {
                    Node_Do ( root_node );
                }
                
                if ( root_node -> pRightChildNode != NULL )
                {
                    root_node = root_node -> pRightChildNode;
                    break;
                }
                else
                {
                    continue;
                }
            }

        }

    }
    BST_Stack.free( &BST_Stack );
    return index;
}

int post_order_travel_BST(struct _BST * self,PBST_Node * Pre, void ( * Node_Do ) ( PBST_Node node ) )
{
    typedef struct _s_node_BST
    {
        char st;
        PBST_Node node;
    } Ts_node;

    Ts_node root_node;
    int index = 0;
    
    if ( self == NULL )
    {
        UserError ( "in %s :: BST is NULL",__func__);
        return -1;
    }

    if ( self -> empty ( self ) )
    {
        UserDebug ( "in %s :: BST [%s] is empty!",__func__, self -> szBSTName );
        return 0;
    }

    //Stack 
    List ( BST_Stack, Ts_node );
    BST_Stack.init ( &BST_Stack );

    root_node.st = 0;
    root_node.node = self->root_node;
    
    while ( 1 )
    {

        BST_Stack.push_back ( &BST_Stack, &root_node );

        if ( root_node.node -> pLeftChildNode == NULL )    
        {
            //if ( Pre != NULL )
            //{
            //    Pre[index] = root_node.node;
            //}
            //index++;
            //if ( Node_Do != NULL )
            //{
            //    Node_Do ( root_node.node );
            //}
            
            
            while ( 1 )
            {
                if ( BST_Stack .empty ( &BST_Stack ) )
                {
                    BST_Stack.free ( &BST_Stack );
                    return index;
                }

                BST_Stack.pop_back ( &BST_Stack, &root_node);

                if ( root_node.st == 0 )
                {
                    root_node.st = 1;
                    BST_Stack.push_back ( &BST_Stack, &root_node);
                    if ( root_node.node -> pRightChildNode != NULL )
                    {
                        root_node.st = 0;
                        root_node.node = root_node.node -> pRightChildNode;
                        break;
                    }
                }
                else
                {
                    if ( Pre != NULL )
                    {
                        Pre[index] = root_node.node;
                    }
                    index++;
                    if ( Node_Do != NULL )
                    {
                        Node_Do ( root_node.node );
                    }
                }
            }
            
        }
        else
        {
            root_node.st = 0;
            root_node.node = root_node.node->pLeftChildNode;
            continue;
        }

    }

    return index;
}

int breadth_first_travel_BST ( struct _BST * self,PBST_Node * Pre, void ( * Node_Do ) ( PBST_Node node ) )
{
    int index  = 0;
    PBST_Node tmp_node = NULL;
    if ( self == NULL )
    {
        UserError ( "in %s :: BST is NULL",__func__);
        return -1;
    }
    if ( self -> empty ( self ) )
    {
        UserDebug ( "in %s :: BST [%s] is empty!",__func__, self -> szBSTName );
        return 0;
    }
    //queue
    List ( BST_Queue, PBST_Node );
    BST_Queue.init ( &BST_Queue );
    
    tmp_node = self -> root_node;
    BST_Queue.push_back ( &BST_Queue, &tmp_node );

    while ( true )
    {
        if ( BST_Queue.empty ( &BST_Queue ) )
        {
            break;
        }
        BST_Queue.pop_front ( &BST_Queue, &tmp_node);
        if ( Pre != NULL )
        {
            Pre[index] = tmp_node;
        }
        index ++;
        if ( Node_Do != NULL )
        {
            Node_Do ( tmp_node );
        }
        if ( tmp_node -> pLeftChildNode != NULL )
        {
            BST_Queue.push_back ( &BST_Queue, &(tmp_node -> pLeftChildNode) );
        }
        if ( tmp_node -> pRightChildNode != NULL )
        {
            BST_Queue.push_back ( &BST_Queue, &(tmp_node -> pRightChildNode) );
        }
    }
    BST_Queue.free ( &BST_Queue );
    return index;
}

bool init_BST ( struct _BST * self )
{
    if ( self -> empty ( self ) )
    {
        self->clear ( self );
    }

    return true; 
}

bool clear_BST ( struct _BST * self )
{
    post_order_travel_BST(self, NULL, Free_Node_BST );
    self->root_node = NULL;
    return true;
}

bool free_BST ( struct _BST * self )
{
    post_order_travel_BST(self, NULL, Free_Node_BST );
    self->root_node = NULL;
    return true;
}

bool empty_BST ( struct _BST * self )
{

    if ( self->root_node == NULL )
    {
        return true;
    }
    else
    {
        return false;
    }
}
