#include <stdio.h>
typedef struct _B_Tree_Node
{
    size_t keyNum; //关键字数目 keyNum < m 
    struct _B_Tree_Node * parent; //父节点
    struct _B_Tree_Node ** childNodeArray; //子节点块数组 childNodeArray[0] ~ childNodeArray[keyNum + 1]
    void ** Key; //关键字 key[0] ~ key[keyNum]

} TBTreeNode,* PBTReeNode;

typedef struct _B_Tree
{
    // caculate BTreeNode's KeyNum, a node's size should always approach Block's size
    size_t block_size;
      

} TBTree,* pBTree;
