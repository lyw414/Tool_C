#include <stdio.h>
#include "List.h"
#include "Log.h"

List(mylist,int);
bool add_all()
{
    int tmp = 0;
    mylist.push_back(&mylist,&tmp);
    tmp = 1;
    mylist.push_back(&mylist,&tmp);
    tmp = 2;
    mylist.push_back(&mylist,&tmp);
    tmp = 3;
    mylist.push_back(&mylist,&tmp);
    tmp = 4;
    mylist.push_back(&mylist,&tmp);
    tmp = 5;
    mylist.push_back(&mylist,&tmp);
    return true;
}

void pop_front_all ()
{
    int tmp = 0;
    int value;
    int size =  mylist.isize;
    for ( tmp = 0; tmp < size; tmp ++ )
    {
        mylist.pop_front(&mylist,&value);
        printf ( "Pop_Front [%d]\n",value);
    }
}

void pop_back_all()
{
    int tmp = 0;
    int value;
    int size =  mylist.isize;
    for ( tmp = 0; tmp < size; tmp ++ )
    {
        mylist.pop_back(&mylist,&value);
        printf ( "Pop_back [%d]\n",value);
    }
}

int main()
{
    Init_Log ( "List_Test","./log/",DEBUG_LEVEL,10,PTHREAD_MODE);
    add_all();
    pop_back_all();
    pop_front_all();
    mylist.clear(&mylist);

    return 0;
}
