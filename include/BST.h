#ifndef LYW_CODE_BST
#define LYW_CODE_BST
#include "List.h"

typedef struct _BST_Node
{
    void * data;
    size_t data_size;
    struct _BST_Node * pLeftChildNode;
    struct _BST_Node * pRightChildNode;
    bool ( * set_value ) ( struct _BST_Node * self, void * data );
    bool ( * get_value ) ( struct _BST_Node * self, void * data );
    bool ( * init ) ( struct _BST_Node * self );
    bool ( * clear ) ( struct _BST_Node * self );
    bool ( * free ) ( struct _BST_Node * self );
} TBST_Node,* PBST_Node;


bool set_value_BST_Node ( struct _BST_Node * self, void * data );
bool get_value_BST_Node ( struct _BST_Node * self, void * data );
bool init_BST_Node ( struct _BST_Node * self );
bool clear_BST_Node ( struct _BST_Node * self );
bool free_BST_Node ( struct _BST_Node * self );

typedef struct _BST
{
    PBST_Node root_node;
    size_t data_size;
    int ( * compare_func ) ( void * data1, void * data2 );
    char szBSTName[64];
    bool ( * add ) (struct _BST * self,void * data);
    int ( * find ) (struct _BST * self,void * data,void * dataout);
    int ( * del ) (struct _BST * self,void * data);
    bool ( * change ) (struct _BST * self, void * data, void * data1);
    bool ( * reBuild ) (struct _BST * self);
    int ( * pre_order_travel ) (struct _BST * self,PBST_Node * Pre, void ( * Node_Do ) ( PBST_Node node ) );
    int ( * in_order_travel ) (struct _BST * self,PBST_Node * Pre, void ( * Node_Do ) ( PBST_Node node ) );
    int ( * post_order_travel ) (struct _BST * self,PBST_Node * Pre, void ( * Node_Do ) ( PBST_Node node ) );
    int ( * breadth_first_travel ) (struct _BST * self,PBST_Node * Pre, void ( * Node_Do ) ( PBST_Node node ) );
    bool ( * init ) ( struct _BST * self );
    bool ( * clear ) ( struct _BST * self );
    bool ( * free ) ( struct _BST * self );
    bool ( * empty ) ( struct _BST * self );
} TBST,* PBST;

/*
 * @brief    provide compare func for data cmp return must like follow
 *
 * 0   equal
 * 1   bigger
 * 2   smaller
 * 
 */
typedef int ( * Tcompare_func_BST ) ( void * data1, void * data2 );
typedef void ( * TNode_Do_BST ) ( PBST_Node node );


bool add_BST(struct _BST * self,void * data);
int find_BST(struct _BST * self,void * data, void * dataout);
int del_BST(struct _BST * self,void * data);
bool change_BST(struct _BST * self, void * data, void * data1);
bool reBuild_BST(struct _BST * self);
int pre_order_travel_BST(struct _BST * self,PBST_Node * Pre, void ( * Node_Do ) ( PBST_Node node ) );
int in_order_travel_BST(struct _BST * self,PBST_Node * Pre, void ( * Node_Do ) ( PBST_Node node ) );
int post_order_travel_BST(struct _BST * self,PBST_Node * Pre, void ( * Node_Do ) ( PBST_Node node ) );
int breadth_first_travel_BST(struct _BST * self,PBST_Node * Pre, void ( * Node_Do ) ( PBST_Node node ) );
bool init_BST ( struct _BST * self );
bool clear_BST ( struct _BST * self );
bool free_BST ( struct _BST * self );
bool empty_BST ( struct _BST * self );





#define BST_Node(p,Size) \
   TBST_Node p = \
    {\
        .data = NULL,\
        .data_size = Size,\
        .pLeftChildNode = NULL,\
        .pRightChildNode = NULL,\
        .set_value = set_value_BST_Node,\
        .get_value = set_value_BST_Node,\
        .init = init_BST_Node,\
        .clear = clear_BST_Node,\
        .free = free_BST_Node,\
    };

#define _BST_Node(p,Size) \
    p = \
    {\
        .data = NULL,\
        .data_size = Size,\
        .pLeftChildNode = NULL,\
        .pRightChildNode = NULL,\
        .set_value = set_value_BST_Node,\
        .get_value = set_value_BST_Node,\
        .init = init_BST_Node,\
        .clear = clear_BST_Node,\
        .free = free_BST_Node,\
    }


#define NEW_BST_Node(p,Size) \
    p = ( PBST_Node )malloc ( sizeof ( TBST_Node ) );\
    p->data = NULL;\
    p->data_size = Size;\
    p->pLeftChildNode = NULL;\
    p->pRightChildNode = NULL;\
    p->set_value = set_value_BST_Node;\
    p->get_value = set_value_BST_Node;\
    p->init = init_BST_Node;\
    p->clear = clear_BST_Node;\
    p->free = free_BST_Node;\



#define BST(p,Type,cmp_func) \
    TBST p = \
    {\
        .root_node = NULL,\
        .data_size = sizeof ( Type ),\
        .compare_func = cmp_func,\
        .szBSTName = #p ,\
        .add = add_BST,\
        .find = find_BST,\
        .del = del_BST,\
        .change = change_BST,\
        .reBuild = reBuild_BST,\
        .pre_order_travel = pre_order_travel_BST,\
        .in_order_travel = in_order_travel_BST,\
        .post_order_travel = post_order_travel_BST,\
        .breadth_first_travel = breadth_first_travel_BST,\
        .init = init_BST,\
        .clear = clear_BST,\
        .free = free_BST,\
        .empty = empty_BST,\
    };


#define _BST(p,Type,cmp_func) \
    p = \
    {\
        .root_node = NULL,\
        .data_size = sizeof ( Type ),\
        .compare_func = cmp_func,\
        .szBSTName = #p ,\
        .add = add_BST,\
        .find = find_BST,\
        .del = del_BST,\
        .change = change_BST,\
        .reBuild = reBuild_BST,\
        .pre_order_travel = pre_order_travel_BST,\
        .in_order_travel = in_order_travel_BST,\
        .post_order_travel = post_order_travel_BST,\
        .breadth_first_travel = breadth_first_travel_BST,\
        .init = init_BST,\
        .clear = clear_BST,\
        .free = free_BST,\
        .empty = empty_BST,\
    }


#define NEW_BST(p,Type,cmp_func) \
    p = ( PBST ) malloc ( sizeof ( TBST ) );\
    p->data_size = sizeof ( Type );\
    p->root_node = NULL;\
    p->compare_func = cmp_func;\
    strcpy ( p->szBSTName, #p );\
    p->add = add_BST;\
    p->find = find_BST;\
    p->del = del_BST;\
    p->change = change_BST;\
    p->reBuild = reBuild_BST;\
    p->pre_order_travel = pre_order_travel_BST;\
    p->in_order_travel = in_order_travel_BST;\
    p->post_order_travel = post_order_travel_BST;\
    p->breadth_first_travel = breadth_first_travel_BST;\
    p->init = init_BST;\
    p->clear = clear_BST;\
    p->free = free_BST;\
    p->empty = empty_BST;\

#endif 
