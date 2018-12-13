#include "List.h"

bool empty_for_list (struct _list_Info * self)
{
    if ( self -> size > 0 )
    {
        return false;
    }
    else
    {
        return true;
    }
}

/*
 * @brief 链表尾部添加 若链表为空 则同时添加到头
 * @param[in] self      _list_info 实例 用于维护链表自身属性以及头尾
 * @param[in] value     存储值得指针
 *
 * return   true false
 */
bool push_back_for_list  (struct _list_Info * self,void * value )
{
   
    PList_Node tmp =  malloc ( sizeof ( TList_Node ) );
    tmp -> pdata =  malloc ( self -> data_size );
    memcpy ( tmp -> pdata, value, self -> data_size );
    //add to end 
    tmp -> front = self -> end;
    tmp -> next = NULL;
    //if front empty add to front
    if ( self -> head == NULL ) 
    {
        self -> head = tmp;
    }
    else
    {
        self -> end -> next = tmp;
    }

    self -> end = tmp;
    //add size
    (self -> size) ++;
    return true;
}

/*
 * @brief       获取链表尾值
 *
 * @param[in] self      _list_info 实例 用于维护链表自身属性以及头尾
 * @param[out] value    输出value
 *
 *
 * return true  false
 */

bool get_back_for_list  (struct _list_Info * self, void * value)
{
    if ( self -> empty (self) )
    {
        UserWarning ( "in %s :: List [%s] Is Empty!",__func__,self->listname);
        return false;
    }
    else
    {
        memcpy ( value, self -> end -> pdata, self -> data_size );
        return true;
    }
}

/*
 * @brief       弹出表尾数据，并清理内存
 *
 * @param[in] self      _list_info 实例 用于维护链表自身属性以及头尾
 * @param[out] value    输出value
 *
 *
 * return true  false
 */

bool pop_back_for_list  ( struct _list_Info * self, void * value )
{
    PList_Node tmp = NULL;
    if ( self -> empty (self) )
    {
        UserWarning ( "in %s :: List [%s] Is Empty!",__func__,self->listname);
        return false;
    }
    else
    {
        memcpy ( value, self -> end -> pdata, self -> data_size );
        (self->size )-- ;

        tmp = self -> end;

        self -> end = self -> end -> front;
        // if only one node left
        if ( self -> end == NULL )
        {
            self -> head = NULL;
        }
        else
        {
            //set last front one to be last one
            self -> end -> next = NULL;
        }

        // free memory
        free ( tmp -> pdata );
        free ( tmp );
        return true;
    }

}

bool push_front_for_list ( struct _list_Info * self, void * value )
{
    PList_Node tmp =  malloc ( sizeof ( TList_Node ) );
    tmp -> pdata =  malloc ( self -> data_size );
    memcpy ( tmp -> pdata, value, self -> data_size );

    //add to front
    tmp -> front = NULL;
    tmp -> next = self->head;

    //if front empty add to front
    if ( self -> head == NULL ) 
    {
        self -> head = tmp;
    }
    else
    {
        self -> head -> front = tmp;
    }
    self -> head = tmp;
    //add size
    (self -> size) ++;
    return true;
    
}

bool get_front_for_list (struct _list_Info * self, void * value )
{
    if ( self -> empty (self) )
    {
        UserWarning ( "in %s :: List [%s] Is Empty!",__func__,self->listname);
        return false;
    }
    else
    {
        memcpy ( value, self -> head -> pdata, self -> data_size );
        return true;
    }
}
bool pop_front_for_list (struct _list_Info * self, void * value )
{
    PList_Node tmp = NULL;
    if ( self -> empty (self) )
    {
        UserWarning ( "in %s :: List [%s] Is Empty!",__func__,self->listname);
        return false;
    }
    else
    {
        memcpy ( value, self -> head -> pdata, self -> data_size );
        (self->size )-- ;
        tmp = self -> head;

        self -> head = self -> head-> next;

        // if only one node left
        if ( self -> head == NULL )
        {
            self -> end = NULL;
        }
        else
        {
            //set last front one to be last one
            self -> head -> front = NULL;
        }

        // free memory
        free ( tmp -> pdata );
        free ( tmp );
        return true;
    }

}

bool clear_for_list (struct _list_Info * self)
{
    int iLoop = 0;
    PList_Node tmp = self -> head;
    PList_Node next = self -> head;
    for ( iLoop = 0; iLoop < self->size; iLoop++)
    {
       next = tmp->next;
       free ( tmp->pdata );
       free ( tmp );
       tmp = next;
    }
    self -> size = 0;
    self -> head = NULL;
    self -> end = NULL;
    self -> data_size = 0;
    return true;
}


