#include <stdio.h>
#include <string.h>
#include "List.h"

/*
 * @brief compare Data1 with Data2
 *        Data1 Greater Than Data2 (Data1 > Data2 return > 0  )
 *        Data1 Less Than Data2 (Data1 < Data2 return < 0 )
 *        Data1 Equal To Data2 ( Data1 == Data2 return 0 )
 *
 */
typedef int (*TCompareFunction_RBTree)( void * Data1, void * Data2 , size_t DataSize);


typedef enum _RBTreeColor
{
    RBTree_RED,
    RBTree_BLACK
} TRBTreeColor;

/*
 * @brief Node Of RedBlack Tree
 */
typedef struct RBTreeNode
{
    void * data;
    TRBTreeColor color;
    struct RBTreeNode * fatherNode;
    struct RBTreeNode * leftChildNode;
    struct RBTreeNode * rightChildNode;
}TRBTreeNode, * PRBTreeNode;

/*
 * @brief RBTree resource
 * @ function pointor is used to set 
 */
typedef struct RBTree
{
    PRBTreeNode RootNode;
    TCompareFunction_RBTree Cmp;
    size_t DataSize;
}TRBTree,* PRBTree;

static void Del_Adjust_Color ( PRBTreeNode adjustNode );

/*
 * @brief if rootNodeChange return New RootNode else return NULL
 */
static PRBTreeNode Del_Adjust_Tree (PRBTreeNode deleteNode);

/*
 * @brief default cmpfunction
 */
static int DefaultCmp_RBTree ( void * Data1, void * Data2, size_t DataSize );
/*
 * @brief  Rotate Left must must have gfatherNode
 */
static PRBTreeNode RotateLeft ( PRBTreeNode CurrentNode );
/*
 * @brief Rotate Right node must have gfatherNode
 */
static PRBTreeNode RotateRight ( PRBTreeNode CurrentNode );

/*
 * @brief adjust node for rbTree
 */
static PRBTreeNode Adjust_RBTree_Node (PRBTreeNode currentNode);
/*
 * @brief only Add Data to Node in RBTree and eturn this node for adjustment if find one return null (no need to adjust)
 *
 */
static  PRBTreeNode Add_To_Node ( PRBTree prbTree, void * data );
/*
 * @brief find node in RBTree if not found return NULL else return pointor of pRBTreeNode
 */
static PRBTreeNode Find_Node ( PRBTree prbTree, void * data );

/*
 * @brief if not empty return 0 
 */
static int empty ( PRBTree prbTree );

/*
 * @brief get resource of red-black tree
 */
PRBTree RBTree_New( size_t DataSize, TCompareFunction_RBTree Cmp);



/*
 * @brief free all resource of rbTree
 */
int RBTree_Free( PRBTree rbTree );

/*
 * @brief : add data's pointor, BRTree will do data copy 
 *          if compare function not set, data will be compare 
 *          with memcpm ( data, node->data,SizeOfData )
 */
int RBTree_Add ( PRBTree prbTree, void * data );
/*
 * @brief : Del data's pointor, BRTree will do data copy 
 *          if compare function not set, data will be compare 
 *          with memcpm ( data, node->data,SizeOfData )
 */
int RBTree_Del ( PRBTree prbTree, void * data );



/*
 * @brief : use CompareFunction To Find Data, copy Find Data to Data
 * @param[in][out] Data : Data should include Key 
 *
 */
int RBTree_Search ( PRBTree prbTree, void * Data );

/*
 * @brief breadth first travel 
 * @param[in] outNodeArray 
 * @param[in] size of outNodeArray if not enought only put size 
 * @return number of node
 */
int Breadth_First_Travel ( PRBTreeNode node,PRBTreeNode outNodeArray, size_t sizeOfOutNodeArray );
