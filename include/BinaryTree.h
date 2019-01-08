#ifndef LYW_CODE_BinaryTree
#define LYW_CODE_BinaryTree
#include "Log.h"
#include "List.h"
#include "Array_Operator.h"


typedef struct _binary_tree_Node
{
    void * data;
    size_t data_size;
    struct _binary_tree_Node * pLeftChild;
    struct _binary_tree_Node * pRightChild;

    bool ( * SetValue ) ( struct _binary_tree_Node * self, void * value );

    bool ( * SetLeftChild ) (struct _binary_tree_Node * self, struct _binary_tree_Node * pNode);
    bool ( * SetRightChild ) (struct _binary_tree_Node * self, struct _binary_tree_Node * pNode);

    bool ( * GetLeftChild ) (struct _binary_tree_Node * self, struct _binary_tree_Node * * pNode);
    bool ( * GetRightChild ) (struct _binary_tree_Node * self, struct _binary_tree_Node * * pNode);

    bool ( * init ) ( struct _binary_tree_Node * self);
    bool ( * free ) ( struct _binary_tree_Node * self);
    bool ( * clear ) ( struct _binary_tree_Node * self);


} TBinaryTree_Node,* PBinaryTree_Node;


typedef struct _binary_tree
{
    PBinaryTree_Node root_node;
    size_t data_size;
    size_t node_num;
    char szBinaryTreeName[64];
    int ( * breadth_first_travel )( struct _binary_tree * self,PBinaryTree_Node NodeArray[],void ( * Node_Do ) ( PBinaryTree_Node pNode) );
    int ( * pre_order_travel) ( struct _binary_tree * self,PBinaryTree_Node NodeArray[],void ( * Node_Do ) ( PBinaryTree_Node pNode) );
    int ( * in_order_travel) ( struct _binary_tree * self,PBinaryTree_Node NodeArray[],void ( * Node_Do ) ( PBinaryTree_Node pNode ) );
    int ( * post_order_travel) ( struct _binary_tree * self,PBinaryTree_Node NodeArray[],void ( * Node_Do) ( PBinaryTree_Node pNode) );
    bool ( * build_by_pre_and_in ) ( struct _binary_tree * self, PBinaryTree_Node Pre[], PBinaryTree_Node In[], int Num );
    bool ( * build_by_post_and_in ) ( struct _binary_tree * self, PBinaryTree_Node Post[], PBinaryTree_Node In[], int Num );
    bool ( * free ) ( struct _binary_tree * self );
    bool ( * init ) ( struct _binary_tree * self );
    bool ( * empty ) ( struct _binary_tree * self );
    bool ( * clear ) ( struct _binary_tree * self );
}TBinaryTree,* PBinaryTree;

bool SetValue_for_BinaryTree_Node (struct _binary_tree_Node * self, void * value );
bool SetLeftChild_for_BinaryTree_Node (struct _binary_tree_Node * self, struct _binary_tree_Node * pNode);
bool SetRightChild_for_BinaryTree_Node (struct _binary_tree_Node * self, struct _binary_tree_Node * pNode);
bool GetLeftChild_for_BinaryTree_Node (struct _binary_tree_Node * self, struct _binary_tree_Node * * pNode);
bool GetRightChild_for_BinaryTree_Node (struct _binary_tree_Node * self, struct _binary_tree_Node * *  pNode);
bool init_for_BinaryTree_Node  ( struct _binary_tree_Node * self);
bool free_for_BinaryTree_Node  ( struct _binary_tree_Node * self);
bool clear_for_BinaryTree_Node  ( struct _binary_tree_Node * self);

int breadth_first_travel_for_BinaryTree ( struct _binary_tree * self,PBinaryTree_Node NodeArray[],void ( * Node_Do ) ( PBinaryTree_Node  pNode) );
int pre_order_travel_for_BinaryTree ( struct _binary_tree * self,PBinaryTree_Node NodeArray[],void ( * Node_Do ) ( PBinaryTree_Node  pNode) );
int in_order_travel_for_BinaryTree ( struct _binary_tree * self,PBinaryTree_Node NodeArray[],void ( * Node_Do ) ( PBinaryTree_Node  pNode ) );
int Post_Order_travel_for_BinaryTree ( struct _binary_tree * self,PBinaryTree_Node NodeArray[],void ( * Node_Do) ( PBinaryTree_Node  pNode) );
bool build_by_pre_and_in_for_BinaryTree ( struct _binary_tree * self, PBinaryTree_Node Pre[], PBinaryTree_Node In[], int Num );
bool build_by_post_and_in_for_BinaryTree ( struct _binary_tree * self, PBinaryTree_Node Post[], PBinaryTree_Node In[], int Num );
bool free_for_BinaryTree ( struct _binary_tree * self );
bool init_for_BinaryTree ( struct _binary_tree * self );
bool empty_for_BinaryTree ( struct _binary_tree * self );
bool clear_for_BinaryTree ( struct _binary_tree * self );



#define BinaryTree_Node(p,Size)\
    struct _binary_tree_Node p = \
    {\
        .data = NULL,\
        .data_size = Size,\
        .pLeftChild = NULL,\
        .pRightChild = NULL,\
        .SetValue = SetValue_for_BinaryTree_Node,\
        .SetLeftChild = SetLeftChild_for_BinaryTree_Node,\
        .SetRightChild = SetRightChild_for_BinaryTree_Node,\
        .GetLeftChild = GetLeftChild_for_BinaryTree_Node,\
        .GetRightChild = GetRightChild_for_BinaryTree_Node,\
        .clear = clear_for_BinaryTree_Node,\
        .free = free_for_BinaryTree_Node,\
        .init = init_for_BinaryTree_Node\
    };\



#define _BinaryTree_Node(p,Size)\
    p = \
    {\
        .data = NULL,\
        .data_size = Size,\
        .pLeftChild = NULL,\
        .pRightChild = NULL,\
        .SetValue = SetValue_for_BinaryTree_Node,\
        .SetLeftChild = SetLeftChild_for_BinaryTree_Node,\
        .SetRightChild = SetRightChild_for_BinaryTree_Node,\
        .GetLeftChild = GetLeftChild_for_BinaryTree_Node,\
        .GetRightChild = GetRightChild_for_BinaryTree_Node,\
        .clear = clear_for_BinaryTree_Node,\
        .free = free_for_BinaryTree_Node,\
        .init = init_for_BinaryTree_Node\
    }\

#define NEW_BinaryTree_Node(p,Size)\
    p = malloc ( sizeof ( TBinaryTree_Node ) );\
    p->data = NULL;\
    p->data = NULL;\
    p->data_size = Size;\
    p->pLeftChild = NULL;\
    p->pRightChild = NULL;\
    p->SetValue = SetValue_for_BinaryTree_Node;\
    p->SetLeftChild = SetLeftChild_for_BinaryTree_Node;\
    p->SetRightChild = SetRightChild_for_BinaryTree_Node;\
    p->GetLeftChild = GetLeftChild_for_BinaryTree_Node;\
    p->GetRightChild = GetRightChild_for_BinaryTree_Node;\
    p->clear = clear_for_BinaryTree_Node;\
    p->free = free_for_BinaryTree_Node;\
    p->init = init_for_BinaryTree_Node;\


#define BinaryTree(p,Type)\
    struct _binary_tree p = \
    {\
        .root_node = NULL,\
        .data_size = sizeof ( Type ),\
        ,node_num = 0,\
        .szBinaryTreeName = #p,\
        .breadth_first_travel = breadth_first_travel_for_BinaryTree,\
        .pre_order_travel = pre_order_travel_for_BinaryTree,\
        .in_order_travel = in_order_travel_for_BinaryTree,\
        .post_order_travel = Post_Order_travel_for_BinaryTree,\
        .build_by_pre_and_in = build_by_pre_and_in_for_BinaryTree,\
        .build_by_post_and_in = build_by_post_and_in_for_BinaryTree,\
        .free = free_for_BinaryTree,\
        .init = init_for_BinaryTree,\
        .empty = empty_for_BinaryTree,\
        .clear= clear_for_BinaryTree\
    };

#define _BinaryTree(p,Type)\
    p = \
    {\
        .root_node = NULL,\
        .data_size = sizeof ( Type ),\
        ,node_num = 0,\
        .szBinaryTreeName = #p,\
        .breadth_first_travel = breadth_first_travel_for_BinaryTree,\
        .pre_order_travel = pre_order_travel_for_BinaryTree,\
        .in_order_travel = in_order_travel_for_BinaryTree,\
        .post_order_travel = Post_Order_travel_for_BinaryTree,\
        .build_by_pre_and_in = build_by_pre_and_in_for_BinaryTree,\
        .build_by_post_and_in = build_by_post_and_in_for_BinaryTree,\
        .free = free_for_BinaryTree,\
        .init = init_for_BinaryTree,\
        .empty = empty_for_BinaryTree,\
        .clear= clear_for_BinaryTree\
    }

#define NEW_BinaryTree(p,Type)\
    p = malloc ( sizeof ( TBinaryTree ) );\
    p->root_node = NULL;\
    p->data_size = sizeof ( Type );\
    p->node_num = 0;\
    strcpy ( p->szBinaryTreeName, #p);\
    p->breadth_first_travel = breadth_first_travel_for_BinaryTree;\
    p->pre_order_travel = pre_order_travel_for_BinaryTree;\
    p->in_order_travel = in_order_travel_for_BinaryTree;\
    p->post_order_travel = Post_Order_travel_for_BinaryTree;\
    p->build_by_pre_and_in = build_by_pre_and_in_for_BinaryTree;\
    p->build_by_post_and_in = build_by_post_and_in_for_BinaryTree;\
    p->free = free_for_BinaryTree;\
    p->init = init_for_BinaryTree;\
    p->empty = empty_for_BinaryTree;\
    p->clear= clear_for_BinaryTree;\

#endif
