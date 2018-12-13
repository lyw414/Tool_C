#ifndef LYW_CODE_LIST
#define LYW_CODE_LIST
#include <stdlib.h>
#include "Log.h"

/*
 *
 * @brief       双向链表节点 用于存储上下节点以及 数据指针
 *
 */
typedef struct _list_node
{
    void * pdata;
    struct _list_node * next;
    struct _list_node * front;

}TList_Node, * PList_Node;

/*
 * @brief       双链表属性 用于维护 链表基础属性 表长、数据size 表头尾
 *
 */ 
typedef struct _list_Info
{
    size_t data_size;
    size_t size;
    char listname[128];
    PList_Node head;
    PList_Node end;
    
    bool ( * push_back ) ( struct _list_Info * self,void * value );
    bool ( * get_back ) (struct _list_Info * self, void * value );
    bool ( * pop_back ) (struct _list_Info * self, void * value );

    bool ( * push_front ) (struct _list_Info * self, void * value );
    bool ( * get_front ) (struct _list_Info * self, void * value );
    bool ( * pop_front ) (struct _list_Info * self, void * value );

    bool (* clear ) (struct _list_Info * self);
    bool (* empty ) (struct _list_Info * self);

} TList;

typedef TList * PList;
/*
 * @brief 链表尾部添加 若链表为空 则同时添加到头
 * @param[in] self      _list_info 实例 用于维护链表自身属性以及头尾
 * @param[in] value     存储值得指针
 * 
 * return   true false
 */
bool push_back_for_list  ( struct _list_Info * self,void * value );
bool get_back_for_list  ( struct _list_Info * self,void * value );
bool pop_back_for_list  ( struct _list_Info * self,void * value );
bool push_front_for_list (struct _list_Info * self, void * value );
bool get_front_for_list (struct _list_Info * self,void * value );
bool pop_front_for_list (struct _list_Info * self, void * value );
bool clear_for_list (struct _list_Info * self);
bool empty_for_list (struct _list_Info * self);



/*
 * @brief 使用该宏获取链表实例
 *
 */
#define List(p,type) \
   TList p = { \
    .data_size = sizeof(type),\
    .listname = #p,\
    .size = 0,\
    .head = NULL,\
    .end = NULL,\
    .push_back = push_back_for_list,\
    .get_back = get_back_for_list,\
    .pop_back = pop_back_for_list,\
    .push_front = push_front_for_list,\
    .get_front = get_front_for_list,\
    .pop_front = pop_front_for_list,\
    .clear = clear_for_list,\
    .empty = empty_for_list\
   };\

#endif
