#include "RBTree.h"

static void Del_Adjust_Color ( PRBTreeNode adjustNode )
{
    if ( adjustNode == NULL )
    {
        return;
    }

    if ( adjustNode->leftChildNode != NULL )
    {
        if ( adjustNode->leftChildNode->color == RBTree_RED )
        {
            adjustNode->leftChildNode->color = RBTree_BLACK;
        }
    }

    if ( adjustNode->rightChildNode != NULL )
    {
        if ( adjustNode->rightChildNode->color == RBTree_RED )
        {
            adjustNode->rightChildNode->color = RBTree_BLACK;
        }
    }
    return;
}
/*
 * @brief if rootNodeChange return New RootNode else return NULL
 */
static PRBTreeNode Del_Adjust_Tree (PRBTreeNode deleteNode_)
{
    /* find brother node */   
    PRBTreeNode deleteNode = deleteNode_;
    PRBTreeNode brotherNode = NULL;
    PRBTreeNode fatherNode = NULL;
    if ( deleteNode == NULL )
    {
        return NULL;
    }

    if ( deleteNode->fatherNode == NULL )
    {
        return NULL;
    }

    while ( true )
    {
        fatherNode = deleteNode->fatherNode;
        brotherNode = deleteNode->fatherNode->leftChildNode == deleteNode ? deleteNode->fatherNode->leftChildNode : deleteNode->fatherNode->rightChildNode;
        if ( brotherNode->color == RBTree_RED )
        {
           /* rotate */
           if ( deleteNode->fatherNode->leftChildNode == deleteNode )
           {
                /* leftChildNOde , rotate left*/
                if (  fatherNode->fatherNode != NULL )
                {
                    if ( fatherNode->fatherNode->leftChildNode == fatherNode )
                    {
                        fatherNode->fatherNode->leftChildNode = brotherNode;
                    }
                    else
                    {
                        fatherNode->fatherNode->rightChildNode = brotherNode;
                    }
                }
                brotherNode->fatherNode = fatherNode->fatherNode;
                fatherNode->fatherNode = brotherNode;
                fatherNode->rightChildNode = brotherNode->leftChildNode;
                brotherNode->leftChildNode = fatherNode;
                fatherNode->rightChildNode->color = RBTree_RED;
                Del_Adjust_Color ( fatherNode->rightChildNode );
           }
           else
           {
                /* leftChildNOde , rotate left*/
                if (  fatherNode->fatherNode != NULL )
                {
                    if ( fatherNode->fatherNode->leftChildNode == fatherNode )
                    {
                        fatherNode->fatherNode->leftChildNode = brotherNode;
                    }
                    else
                    {
                        fatherNode->fatherNode->rightChildNode = brotherNode;
                    }
                }
                brotherNode->fatherNode = fatherNode->fatherNode;
                fatherNode->fatherNode = brotherNode;
                fatherNode->leftChildNode = brotherNode->rightChildNode;
                brotherNode->rightChildNode = fatherNode;
                fatherNode->leftChildNode->color = RBTree_RED;
                Del_Adjust_Color ( fatherNode->leftChildNode );
           }
           break;
        }
        else
        {
            /* change brother's color to red */
            brotherNode->color = RBTree_RED;
            Del_Adjust_Color ( brotherNode );
            deleteNode = fatherNode;
        }

        if ( deleteNode->fatherNode == NULL )
        {
            return NULL;
        }
    }
}

/*
 * @brief default cmpfunction
 */
static int DefaultCmp_RBTree ( void * Data1, void * Data2, size_t DataSize )
{
    return memcmp ( Data1,Data2,DataSize );
}
/*
 * @brief  Rotate Left
 */
static PRBTreeNode RotateLeft ( PRBTreeNode CurrentNode )
{
    PRBTreeNode currentNode = NULL;
    PRBTreeNode fatherNode = NULL;
    PRBTreeNode gfatherNode = NULL;

    if ( CurrentNode == NULL || CurrentNode->fatherNode == NULL || CurrentNode->fatherNode->fatherNode == NULL )
    {
        /* currentNode is NULL , No father or no gfather, No need to rotate */
        return NULL;
    }

    currentNode = CurrentNode;
    gfatherNode = currentNode->fatherNode->fatherNode;
    if ( currentNode->fatherNode->leftChildNode == currentNode )
    {
        /* currentNode is left child node , need to adjust first */ 
        /* currentNode to be fatherNode , fatherNode to be rightChildNode of currentNode */

        fatherNode = currentNode->fatherNode;
        gfatherNode->rightChildNode = currentNode;
        currentNode->fatherNode = gfatherNode;
        fatherNode->leftChildNode = currentNode->rightChildNode;
        currentNode->rightChildNode = fatherNode;
        fatherNode->fatherNode = currentNode;
        currentNode = fatherNode;
    }

    fatherNode = currentNode->fatherNode;

    /* rotate to left */
    /* change color */ 
    gfatherNode->color = RBTree_RED;
    fatherNode->color = RBTree_BLACK;
    /* rotate */
    if ( gfatherNode->fatherNode != NULL )
    {
        if ( gfatherNode->fatherNode->rightChildNode == gfatherNode )
        {
            gfatherNode->fatherNode->rightChildNode = fatherNode;
        }
        else
        {
            gfatherNode->fatherNode->leftChildNode = fatherNode;
        }
    }
    
    fatherNode->fatherNode = gfatherNode->fatherNode;
    gfatherNode->fatherNode = fatherNode;
    gfatherNode->rightChildNode = fatherNode->leftChildNode;
    fatherNode->leftChildNode = gfatherNode;

    if ( fatherNode->fatherNode == NULL )
    {
        return fatherNode;
    }
    return NULL;
}

/*
 * @brief Rotate Right
 */
static PRBTreeNode RotateRight ( PRBTreeNode CurrentNode )
{
    PRBTreeNode currentNode = NULL;
    PRBTreeNode fatherNode = NULL;
    PRBTreeNode gfatherNode = NULL;

    if ( CurrentNode == NULL || CurrentNode->fatherNode == NULL || CurrentNode->fatherNode->fatherNode == NULL )
    {
        /* currentNode is NULL , No father or no gfather, No need to rotate */
        return NULL;
    }

    currentNode = CurrentNode;
    gfatherNode = currentNode->fatherNode->fatherNode;
    if ( currentNode->fatherNode->rightChildNode == currentNode )
    {
        /* currentNode is right child node , need to adjust first */ 
        /* currentNode to be fatherNode , fatherNode to be leftChildNode of currentNode */
        fatherNode = currentNode->fatherNode;
        gfatherNode->leftChildNode = currentNode;
        currentNode->fatherNode = gfatherNode;
        fatherNode->rightChildNode = currentNode->leftChildNode;
        currentNode->leftChildNode = fatherNode;
        fatherNode->fatherNode=currentNode;
        currentNode = fatherNode;
    }
    fatherNode = currentNode->fatherNode;
    /* rotate to left */
    /* change color */ 
    gfatherNode->color = RBTree_RED;
    fatherNode->color = RBTree_BLACK;
    /* rotate */
    if ( gfatherNode->fatherNode != NULL )
    {
        if ( gfatherNode->fatherNode->rightChildNode == gfatherNode )
        {
            gfatherNode->fatherNode->rightChildNode = fatherNode;
        }
        else
        {
            gfatherNode->fatherNode->leftChildNode = fatherNode;
        }
    }

    fatherNode->fatherNode = gfatherNode->fatherNode;
    gfatherNode->fatherNode = fatherNode;
    gfatherNode->leftChildNode = fatherNode->rightChildNode;
    fatherNode->rightChildNode = gfatherNode;
    if ( fatherNode->fatherNode == NULL )
    {
        return fatherNode;
    }
    return NULL;
}

/*
 * @brief adjust node for rbTree
 */
static PRBTreeNode Adjust_RBTree_Node (PRBTreeNode CurrentNode)
{
    PRBTreeNode fatherNode = NULL;
    PRBTreeNode uncleNode = NULL;
    PRBTreeNode gfatherNode = NULL;
    PRBTreeNode currentNode = CurrentNode;
    int CurrentLeftOrRight = 0;
    if ( currentNode == NULL )
    {
        return NULL;
    }

    while ( 1 )
    {
        if ( currentNode->fatherNode == NULL )
        {
            currentNode->color = RBTree_BLACK;
            return NULL;
        }
        fatherNode = currentNode->fatherNode;
        if ( fatherNode->color == RBTree_BLACK )
        {
            return NULL;
        }
        if ( fatherNode->fatherNode == NULL )
        {
            return NULL;
        }
        gfatherNode = fatherNode->fatherNode;

        if ( fatherNode == gfatherNode->rightChildNode )
        {
            /* fatherNode if rightChild */
            /* get uncleNode */
            uncleNode = gfatherNode->leftChildNode;
            if ( uncleNode == NULL || uncleNode->color == RBTree_BLACK )
            {
                return RotateLeft( currentNode );
            }
            else
            {
                /* only change color */
                uncleNode->color = RBTree_BLACK;
                fatherNode->color = RBTree_BLACK;
                gfatherNode->color = RBTree_RED;
                currentNode = gfatherNode;
            }


        }
        else
        {
            /* fatherNode if LeftChild */
            /* get uncldeNode*/
            uncleNode = gfatherNode->rightChildNode;
            /* fatherNode is black no need to adjust*/
            if ( uncleNode == NULL || uncleNode->color == RBTree_BLACK )
            {
                return RotateRight ( currentNode );
            }
            else
            {
                /* only change color */
                uncleNode->color = RBTree_BLACK;
                fatherNode->color = RBTree_BLACK;
                gfatherNode->color = RBTree_RED;
                currentNode = gfatherNode;
            }
        }
    }
}
/*
 * @brief only Add Data to Node in RBTree and eturn this node for adjustment
 */
static PRBTreeNode Add_To_Node ( PRBTree prbTree, void * data )
{
    PRBTreeNode node;
    PRBTreeNode newNode;
    int ret = 0;
    /*empty add rootNode*/
    if ( empty ( prbTree ) )
    {
        newNode = ( PRBTreeNode )malloc ( sizeof ( TRBTreeNode ) );
        newNode->color = RBTree_BLACK;
        newNode->data = malloc ( prbTree->DataSize );
        newNode->fatherNode = NULL;
        newNode->leftChildNode = NULL;
        newNode->rightChildNode = NULL;
        memcpy ( newNode->data,data,prbTree->DataSize );
        prbTree -> RootNode = newNode;
        return NULL;
    }
    /*not empty from rootNode to find update node or add new node*/
    node = prbTree->RootNode;
    while ( 1 )
    {
        ret = prbTree->Cmp ( data, node->data, prbTree->DataSize );
        if ( ret > 0 ) 
        {
            //data > node->data rightChildeNode
            if ( node->rightChildNode != NULL )
            {
                node = node->rightChildNode;
            }
            else
            {
                break;
            }
        }
        else if ( ret < 0 ) 
        {
            //data < node->data leftChildeNode
            if ( node->rightChildNode != NULL )
            {
                node = node->rightChildNode;
            }
            else
            {
                break;
            }
        }
        else
        {
            //find and update this node 
            memcpy ( node -> data, data, prbTree->DataSize );
            return NULL;
        }
    }

    /*add new node to leafNode, return it for adjust*/
    newNode = ( PRBTreeNode )malloc ( sizeof ( TRBTreeNode ) );
    newNode->color = RBTree_RED;
    newNode->data = malloc ( prbTree->DataSize );
    memcpy ( newNode->data, data, prbTree->DataSize );
    newNode->fatherNode = node;
    newNode->leftChildNode = NULL;
    newNode->rightChildNode = NULL;
    if ( ret > 0 )
    {
        node->rightChildNode = newNode;
    }
    else 
    {
        node->leftChildNode = newNode;
    }
    return newNode;
}

/*
 * @brief find node in RBTree if not found return NULL else return pointor of pRBTreeNode
 */
static PRBTreeNode Find_Node ( PRBTree prbTree, void * data )
{
    PRBTreeNode node;
    int ret = 0;
    if ( empty ( prbTree ) )
    {
        return NULL;
    }
    node = prbTree->RootNode;
    while ( node != NULL )
    {
        ret = prbTree->Cmp ( data, node->data, prbTree->DataSize );
        if ( ret > 0 ) 
        {
            //data > node->data rightChildeNode
            node = node->rightChildNode;
        }
        else if ( ret < 0 ) 
        {
            //data < node->data leftChildeNode
            node = node->rightChildNode;
        }
        else
        {
            return node;
        }
    }
    return NULL;
}

/*
 * @brief if not empty return 0 
 */
static int empty ( PRBTree prbTree )
{
    if ( prbTree != NULL )
    {
        if ( prbTree->RootNode != NULL )
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    return 1;
}

/*
 * @brief get resource of red-black tree
 */

PRBTree RBTree_New( size_t DataSize, TCompareFunction_RBTree Cmp)
{
    //need set DataSize for RBTree
    PRBTree prbTree = (PRBTree)malloc(sizeof(TRBTree));
    memset ( prbTree,0x00,sizeof ( TRBTree ) );
    prbTree->DataSize = DataSize;
    prbTree->DataSize = DataSize;

    if ( Cmp == NULL )
    {
        prbTree->Cmp = DefaultCmp_RBTree;
    }
    else
    {
        prbTree->Cmp = Cmp;
    }

    return prbTree;
}

/*
 * @breif destroy red-black tree
 */
int RBTree_Free( PRBTree rbTree )
{
    return 0;
}

/*
 * @brief  add data's pointor, BRTree will do data copy 
 *         if compare function not set, data will be compare 
 *         with memcpm ( data, node->data,SizeOfData )
 */
int RBTree_Add ( PRBTree prbTree, void * data )
{
    PRBTreeNode currentNode = NULL;
    PRBTreeNode newNode = NULL;
    if ( empty ( prbTree ) )
    {
        //need a new node 
        newNode = ( PRBTreeNode )malloc ( sizeof ( TRBTreeNode ) );
        newNode->color = RBTree_BLACK;
        newNode->data = malloc ( prbTree->DataSize );
        newNode->fatherNode = NULL;
        newNode->leftChildNode = NULL;
        newNode->rightChildNode = NULL;
        memcpy ( newNode->data,data,prbTree->DataSize );
        prbTree -> RootNode = newNode;
        return 1;
    }
    //do search first 
    currentNode = Add_To_Node ( prbTree, data );
    if ( currentNode != NULL )
    {
        //adjust node 
        if ( ( newNode = Adjust_RBTree_Node (currentNode) ) != NULL )
        {
            prbTree->RootNode = newNode;
        }
    }
    return 1;
}

/*
 * @brief : Del data's pointor, BRTree will do data copy 
 *          if compare function not set, data will be compare 
 *          with memcpm ( data, node->data,SizeOfData )
 */
int RBTree_Del ( PRBTree prbTree, void * data )
{
    PRBTreeNode currentNode = Find_Node ( prbTree, data );
    PRBTreeNode replaceNode;
    PRBTreeNode tmpNode;
    
    if ( currentNode == NULL )
    {
        /* not Found */
        return 1;
    }
    /* judge currentNode whether has leftChildNode */
    replaceNode = currentNode->leftChildNode;
    if ( replaceNode != NULL )
    {
        /* has leftChildNode ,find Max leftChildNode */
        if ( currentNode->rightChildNode == NULL )
        {
            /* only has leftChildNOde,current must be BLACK and rightChildNode Must be red */
            /* change leftChildNode color to BLack, replace currentNode*/
            currentNode->leftChildNode->color = RBTree_BLACK;
            currentNode->leftChildNode->fatherNode = currentNode->fatherNode;
            if ( currentNode->fatherNode != NULL )
            {
                if ( currentNode->fatherNode->leftChildNode == currentNode )
                {
                    currentNode->fatherNode->leftChildNode = currentNode->leftChildNode;
                }
                else
                {
                    currentNode->fatherNode->rightChildNode = currentNode->leftChildNode;
                }
            }
            else
            {
                /* currentNode is rootNode */
                prbTree->RootNode = currentNode->leftChildNode;
            }
            free(currentNode->data);
            free(currentNode);
        }
        else
        {
            /* find Max LeftChildNode */
            while ( replaceNode->rightChildNode != NULL ) 
            {
                replaceNode = replaceNode->rightChildNode;
            }
            /* replace currentNode with repalceNode */
            free(currentNode->data);
            currentNode->data = replaceNode->data;
            currentNode = replaceNode;
            /* Delete replaceNode */
            if ( replaceNode->fatherNode->leftChildNode == replaceNode )
            {
                replaceNode->fatherNode->leftChildNode = NULL;
            }
            else
            {
                replaceNode->fatherNode->rightChildNode = NULL;
            }
            if ( replaceNode->color == RBTree_BLACK )
            {
                /* BLACK Node, need adust */
                tmpNode = Del_Adjust_Tree (replaceNode);
                if ( tmpNode != NULL )
                {
                    prbTree->RootNode = tmpNode;
                }

            }
            free(currentNode);
        }
    }
    else
    {
        /* judge currentNode whether has rightChildNode */
        if ( currentNode->leftChildNode == NULL )
        {
            /* leafe Node */
            if ( currentNode->color == RBTree_RED )
            {
                /* Red Node , Delete it Directly */
                if ( currentNode->fatherNode != NULL )
                {
                    if ( currentNode->fatherNode->leftChildNode == currentNode ) 
                    {
                        currentNode->fatherNode->leftChildNode = NULL;
                    }
                    else
                    {
                        currentNode->fatherNode->rightChildNode = NULL;
                    }
                }
                else
                {
                    prbTree->RootNode = NULL;
                }
            }
            else
            {
                /* BLACK Node , Need adjust Tree*/
                tmpNode = Del_Adjust_Tree (replaceNode);
                if ( tmpNode != NULL )
                {
                    prbTree->RootNode = tmpNode;
                }


            }
            free(currentNode->data);
            free(currentNode);
        }
        else
        {
            /* only has rightChildNOde,current must be BLACK and rightChildNode Must be red */
            /* change rightChildNode color to BLack, replace currentNode*/

            currentNode->rightChildNode->color = RBTree_BLACK;
            currentNode->rightChildNode->fatherNode = currentNode->fatherNode;
            if ( currentNode->fatherNode != NULL )
            {
                if ( currentNode->fatherNode->leftChildNode == currentNode )
                {
                    currentNode->fatherNode->leftChildNode = currentNode->rightChildNode;
                }
                else
                {
                    currentNode->fatherNode->rightChildNode = currentNode->rightChildNode;
                }
            }
            else
            {
                /* currentNode is rootNode */
                prbTree->RootNode = currentNode->rightChildNode;
            }
            free(currentNode->data);
            free(currentNode);
        }
    }
}


/*
 * @brief           use CompareFunction To Find Data, copy Find Data to Data
 * @param[in][out]  Data Data should include Key 
 *
 */
int RBTree_Search ( PRBTree prbTree, void * data )
{
    PRBTreeNode node = Find_Node ( prbTree, data );
    if ( node != NULL )
    {
        memcpy ( data,node->data,prbTree->DataSize );
        return 1;
    }
    return 0;
}

/*
 * @brief breadth first travel 
 * @param[in] outNodeArray 
 * @param[in] size of outNodeArray if not enought only put size 
 * @return number of node
 */
int Breadth_First_Travel ( PRBTreeNode node,PRBTreeNode outNodeArray, size_t sizeOfOutNodeArray )
{
    int index = 0;
    PRBTreeNode now = node;
    PRBTreeNode tmp = NULL;
    List(mylist,PRBTreeNode);
    outNodeArray[0] = *node;
    if ( now != NULL )
    {
        mylist.push_back(&mylist,&node);
    }
    else
    {
        return index;
    }   
    while ( !mylist.empty ( &mylist ) ) 
    {
        mylist.pop_front ( &mylist ,&now );
        outNodeArray[index] = *now;
        index++;
        if ( now->leftChildNode != NULL ) 
        {
            mylist.push_back( &mylist ,&(now->leftChildNode));
        }

        if ( now->rightChildNode != NULL ) 
        {
            mylist.push_back( &mylist ,&(now->rightChildNode));
        }
    }
    return 0;
}

