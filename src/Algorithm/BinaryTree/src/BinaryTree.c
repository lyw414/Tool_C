#include "BinaryTree.h"
static void delete_BinaryTree_Node ( PBinaryTree_Node node )
{
    if ( node != NULL )
    {
        free ( node );
    }
}

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
    memcpy ( self -> data, value, self->data_size );
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

bool GetLeftChild_for_BinaryTree_Node (struct _binary_tree_Node * self, struct _binary_tree_Node * * pNode )
{
    if ( self == NULL )
    {
        UserError ( "in %s :: Self Is NULL!",__func__ );
        return false;
    }
 
    if ( ( *pNode = self -> pLeftChild ) == NULL )
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool GetRightChild_for_BinaryTree_Node (struct _binary_tree_Node * self, struct _binary_tree_Node * * pNode)
{
    if ( self == NULL )
    {
        UserError ( "in %s :: Self Is NULL!",__func__ );
        return false;
    }
 
    if ( ( *pNode = self -> pRightChild ) == NULL )
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

int breadth_first_travel_for_BinaryTree ( struct _binary_tree * self,PBinaryTree_Node NodeArray[],void ( * Node_Do ) ( PBinaryTree_Node pNode) )
{

    int index = 0;

    PBinaryTree_Node tmpnode = self->root_node;
    PBinaryTree_Node tmpnode1 = NULL;
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
    //init queue for binarytree
    List(BinaryTreeQueue,PBinaryTree_Node);
    BinaryTreeQueue.init(&BinaryTreeQueue);
    //push_back root_node
    BinaryTreeQueue.push_back ( &BinaryTreeQueue, &tmpnode );
    while ( !BinaryTreeQueue.empty(&BinaryTreeQueue) )
    {
        BinaryTreeQueue.pop_front(&BinaryTreeQueue,&tmpnode);

        if ( Node_Do != NULL )
        {
            Node_Do ( tmpnode );
        }

        if ( NodeArray != NULL )
        {
            NodeArray[index] = tmpnode;
        }

        index++;

        if ( tmpnode->GetLeftChild(tmpnode,&tmpnode1) )
        {
            BinaryTreeQueue.push_back ( &BinaryTreeQueue,&tmpnode1);
        }

        if ( tmpnode->GetRightChild(tmpnode,&tmpnode1) )
        {
            BinaryTreeQueue.push_back ( &BinaryTreeQueue,&tmpnode1);
        }

    }
    BinaryTreeQueue.free(&BinaryTreeQueue);
    return index;
}

int pre_order_travel_for_BinaryTree ( struct _binary_tree * self,PBinaryTree_Node NodeArray[],void ( * Node_Do ) ( PBinaryTree_Node  pNode) )
{
    PBinaryTree_Node root_node;
    PBinaryTree_Node left_child_node;
    PBinaryTree_Node right_child_node;
    int index = 0;

    if ( self == NULL )
    {
    
        UserError ( "in %s :: Self Is NULL!",__func__ );
        return 0;
    }

    if ( self->empty ( self ) )
    {
        UserDebug ( "in %s :: BinaryTree [%s] is Empty!", __func__,self -> szBinaryTreeName );
        return 0;
    }
    
    //Init For List
    List(BinaryTreeStack,PBinaryTree_Node);
    BinaryTreeStack.init(&BinaryTreeStack);

    root_node = self->root_node;
        
    while ( 1 )
    {
        if ( Node_Do != NULL )
        {
            Node_Do ( root_node );
        }

        if ( NodeArray != NULL )
        {
            NodeArray[index] = root_node;
        }
        index++;

        // Get Child_Node 
        root_node-> GetLeftChild ( root_node,&left_child_node );
        root_node-> GetRightChild ( root_node,&right_child_node );
        
        //Left and Right 
        if ( left_child_node == NULL && right_child_node == NULL )
        {
            if ( BinaryTreeStack.empty ( &BinaryTreeStack ) )
            { 
                break;
            }
            //pop one
            BinaryTreeStack.pop_back(&BinaryTreeStack, &root_node );
            continue;
        }
        if ( left_child_node != NULL && right_child_node == NULL )
        {
            root_node = left_child_node;
            continue;
        }
        if ( left_child_node != NULL && right_child_node != NULL )
        {
            BinaryTreeStack.push_back(&BinaryTreeStack, &right_child_node);
            root_node = left_child_node;
            continue;
        }
        if ( left_child_node == NULL && right_child_node != NULL )
        {
            root_node = right_child_node;
            continue;
        }

    }
    BinaryTreeStack.free(&BinaryTreeStack);
    return index;
}


int in_order_travel_for_BinaryTree ( struct _binary_tree * self,PBinaryTree_Node NodeArray[],void ( * Node_Do ) ( PBinaryTree_Node  pNode ) )
{
    PBinaryTree_Node root_node;
    PBinaryTree_Node left_child_node;
    PBinaryTree_Node right_child_node;

    int index = 0;

    if ( self == NULL )
    {
    
        UserError ( "in %s :: Self Is NULL!",__func__ );
        return 0;
    }

    if ( self->empty ( self ) )
    {
        UserDebug ( "in %s :: BinaryTree [%s] is Empty!", __func__,self -> szBinaryTreeName );
        return 0;
    }
    
    //Init For List
    List(BinaryTreeStack,PBinaryTree_Node);
    BinaryTreeStack.init(&BinaryTreeStack);

    root_node = self->root_node;
        
    while ( 1 )
    {

        // Get Child_Node 
        BinaryTreeStack.push_back(&BinaryTreeStack, &root_node);
        root_node-> GetLeftChild ( root_node,&left_child_node );

        if ( left_child_node != NULL )
        {
            root_node = left_child_node;
            continue;
        }
        else
        {
            do
            {
                if ( BinaryTreeStack.empty ( &BinaryTreeStack ) )
                {
                    BinaryTreeStack.free(&BinaryTreeStack);
                    return index;
                }
                BinaryTreeStack.pop_back ( &BinaryTreeStack, &root_node );
                if ( Node_Do != NULL )
                {
                    Node_Do ( root_node );
                }

                if ( NodeArray != NULL )
                {
                    NodeArray[index] = root_node;
                }
                index++;
            } while ( !root_node-> GetRightChild ( root_node,&right_child_node ) );
            root_node = right_child_node;
        }
        
    }
    BinaryTreeStack.free(&BinaryTreeStack);
    return index;
}

int Post_Order_travel_for_BinaryTree ( struct _binary_tree * self,PBinaryTree_Node NodeArray[],void ( * Node_Do) ( PBinaryTree_Node  pNode) )
{
    typedef struct _st_node
    {
        PBinaryTree_Node node;
        int is_visit;
    } st_node;
 
    st_node root_node;
    st_node left_child_node;
    st_node right_child_node;

    int index = 0;

    if ( self == NULL )
    {
    
        UserError ( "in %s :: Self Is NULL!",__func__ );
        return 0;
    }

    if ( self->empty ( self ) )
    {
        UserDebug ( "in %s :: BinaryTree [%s] is Empty!", __func__,self -> szBinaryTreeName );
        return 0;
    }
   
    //Init For List
    List(BinaryTreeStack,st_node);
    BinaryTreeStack.init(&BinaryTreeStack);

    root_node.node = self->root_node;
    root_node.is_visit = 0;
        
    while ( 1 )
    {
        // Get Child_Node 
        BinaryTreeStack.push_back(&BinaryTreeStack, &root_node);
        root_node.node -> GetLeftChild ( root_node.node,&left_child_node.node );

        if ( left_child_node.node != NULL )
        {
            left_child_node.is_visit = 0;
            root_node.node = left_child_node.node;
            continue;
        }
        else
        {
            do
            {
                if ( BinaryTreeStack.empty ( &BinaryTreeStack ) )
                {
                    BinaryTreeStack.free(&BinaryTreeStack);
                    return index;
                }

                BinaryTreeStack.pop_back(&BinaryTreeStack, &root_node);

                if ( root_node.is_visit == 1 )
                {
                    if ( Node_Do != NULL )
                    {
                        Node_Do ( root_node.node );
                    }

                    if ( NodeArray != NULL )
                    {
                        NodeArray[index] = root_node.node;
                    }

                }
                else
                {
                    if ( root_node.node -> GetRightChild ( root_node.node,&right_child_node.node ) )
                    {
                        root_node.is_visit = 1;
                        BinaryTreeStack.push_back(&BinaryTreeStack, &root_node);
                        root_node = right_child_node;
                        root_node.is_visit = 0;
                        break;
                    }
                    else
                    {
                        if ( Node_Do != NULL )
                        {
                            Node_Do ( root_node.node );
                        }

                        if ( NodeArray != NULL )
                        {
                            NodeArray[index] = root_node.node;
                        }
                    }
                }
           } while ( 1 );
        }

    }

    BinaryTreeStack.free(&BinaryTreeStack);
    return index;
}

bool build_by_pre_and_in_for_BinaryTree ( struct _binary_tree * self, PBinaryTree_Node Pre_[], PBinaryTree_Node In_[], int Num )
{
    typedef struct _Array_Info
    {
        int Pre_begin;
        int In_begin;
        int index_in_In;
        int Num;
    } Array_Info;

    //参数检查
    if ( self == NULL )
    {
        UserError ( "in %s :: Self Is NULL!",__func__ );
        return false;
    }

    if (  Pre_ == NULL || In_ == NULL || Num <= 0 )
    {
        UserError ( "in %s :: Nothing In Node_Array",__func__ );
        return 0;
    }
    
    //释放当前二叉树所有资源
    self->free(self);


    PBinaryTree_Node * Pre = malloc ( sizeof(void *) * Num );
    PBinaryTree_Node * In = malloc ( sizeof(void *) * Num );
    memcpy ( Pre,Pre_, sizeof ( void * ) * Num );
    memcpy ( In,In_, sizeof ( void * ) * Num );



    //Use List build Stack
    //Stack cache Rigtht_Node Index in InOrderArray
    List(BinaryTreeStack,Array_Info);

    PBinaryTree_Node root_node = NULL;
    Array_Info Root_Array_Info = { 0 };

    PBinaryTree_Node left_node = NULL;
    Array_Info LeftChild_Array_Info = { 0 };

    PBinaryTree_Node right_node = NULL;
    Array_Info RightChild_Array_Info = { 0 };


    //初始化 root_node   
    Root_Array_Info.Pre_begin = 0;
    Root_Array_Info.In_begin = 0;
    Root_Array_Info.Num = Num;

    if ( ( Root_Array_Info.index_in_In = ArrayFind ( In,Num,Pre, sizeof ( void * ) ) ) == -1 )
    {
        //根节点并未出现在 中序数组中
        UserError("in %s :: BinaryTree [%s] Pre and In Array Error!",__func__,self -> szBinaryTreeName );
        BinaryTreeStack.free(&BinaryTreeStack);
        return false;
    }

    NEW_BinaryTree_Node(self->root_node,self->data_size);
    self->root_node->init(self->root_node);
    memcpy(self->root_node->data,Pre[Root_Array_Info.Pre_begin]->data,self->data_size);
    In[Root_Array_Info.index_in_In] = Pre[Root_Array_Info.Pre_begin] = self->root_node;

    while (  1 )
    {
        //通过当前前序 中序 数组 获取根节点
        //根节点为开始前序开始第一个
        //NEW_BinaryTree_Node(root_node,self->data_size);
       
        root_node =  Pre[Root_Array_Info.Pre_begin];
        //memcpy ( root_node->data,Pre[Root_Array_Info.Pre_begin]->data, self -> data_size );


        //确定左子树 前序 中序开始下标
        LeftChild_Array_Info.Num = Root_Array_Info.index_in_In - Root_Array_Info.In_begin;

        //确定右子树 前序 中序开始下标
        RightChild_Array_Info.Num = Root_Array_Info.Num - Root_Array_Info.index_in_In + Root_Array_Info.In_begin - 1;

        //右节点是否为空
        if ( RightChild_Array_Info.Num != 0 )
        {
            RightChild_Array_Info.Pre_begin = Root_Array_Info.Pre_begin + Root_Array_Info.index_in_In - Root_Array_Info.In_begin + 1;
            RightChild_Array_Info.In_begin = Root_Array_Info.index_in_In + 1;

            if ( ( RightChild_Array_Info.index_in_In = ArrayFind ( In, Num, Pre + RightChild_Array_Info.Pre_begin, sizeof ( void * ) ) ) == -1 )
            {
                //根节点并未出现在 中序数组中
                UserError("in %s :: BinaryTree [%s] Pre and In Array Error!",__func__,self -> szBinaryTreeName );
                BinaryTreeStack.free(&BinaryTreeStack);
                return false;
            }

            NEW_BinaryTree_Node(right_node,self->data_size);
            right_node->init(right_node);
            root_node->pRightChild = right_node;
            memcpy(right_node->data,Pre[RightChild_Array_Info.Pre_begin]->data,self->data_size);
            In[RightChild_Array_Info.index_in_In] = Pre[RightChild_Array_Info.Pre_begin] = right_node;
            BinaryTreeStack.push_back(&BinaryTreeStack,&RightChild_Array_Info);
        }

        
        //是否存在左节点     
        if ( LeftChild_Array_Info.Num == 0 && BinaryTreeStack.empty(&BinaryTreeStack) )
        {
            break; 
        }

        if ( LeftChild_Array_Info.Num == 0 && !BinaryTreeStack.empty ( &BinaryTreeStack ) )
        {
            BinaryTreeStack.pop_back(&BinaryTreeStack,&Root_Array_Info);
            continue;
        }

        if ( LeftChild_Array_Info.Num != 0 )
        {
            LeftChild_Array_Info.Pre_begin = Root_Array_Info.Pre_begin + 1;
            LeftChild_Array_Info.In_begin = Root_Array_Info.In_begin;

            if ( ( LeftChild_Array_Info.index_in_In = ArrayFind ( In , Num ,Pre + LeftChild_Array_Info.Pre_begin, sizeof ( void * ) ) ) == -1 )
            {
                //根节点并未出现在 中序数组中
                UserError("in %s :: BinaryTree [%s] Pre and In Array Error!",__func__,self -> szBinaryTreeName );
                BinaryTreeStack.free(&BinaryTreeStack);
                return false;
            }

            NEW_BinaryTree_Node(left_node,self->data_size);
            left_node->init(left_node);
            root_node->pLeftChild = left_node;
            memcpy(left_node->data,Pre[LeftChild_Array_Info.Pre_begin]->data,self->data_size);
            In[LeftChild_Array_Info.index_in_In] = Pre[LeftChild_Array_Info.Pre_begin] = left_node;
            Root_Array_Info = LeftChild_Array_Info;
            continue;
        }

   }

   BinaryTreeStack.free(&BinaryTreeStack);
   return true;
}

bool build_by_post_and_in_for_BinaryTree ( struct _binary_tree * self, PBinaryTree_Node Post_[], PBinaryTree_Node In_[], int Num )
{
    return true;
}

bool free_for_BinaryTree ( struct _binary_tree * self )
{
    self -> post_order_travel ( self, NULL, delete_BinaryTree_Node );
    return true;
}

bool init_for_BinaryTree ( struct _binary_tree * self )
{
    return true;
}

bool empty_for_BinaryTree ( struct _binary_tree * self )
{
    if ( self == NULL )
    {
        UserError ( "in %s :: Self Is NULL!",__func__ );
        return false;
    }
    if ( self -> root_node == NULL )
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
    self->free(self);
    return true;
}


