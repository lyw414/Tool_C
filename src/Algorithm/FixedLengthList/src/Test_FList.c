#include <stdio.h>
#include "FixedLengthList.h"

typedef struct mynode
{
    int a;
    char buf[10];
} TMyNode;


FixedLengthList(flist,TMyNode,12);

void showstruct(TMyNode * node)
{
    printf ( "%d [%s]\n",node->a,node->buf);
}

void add_front(int num)
{
    int iLoop = 0;
    TMyNode tnode;
    for ( iLoop = 0; iLoop < num; iLoop ++ )
    {
        tnode.a = iLoop;
        sprintf ( tnode.buf, "%d", iLoop );
        flist.push_front(&flist,&tnode);
    }
}

void add_back(int num)
{
    int iLoop = 0;
    TMyNode tnode;
    for ( iLoop = 0; iLoop < num; iLoop ++ )
    {
        tnode.a = iLoop;
        sprintf ( tnode.buf, "%d", iLoop );
        flist.push_back(&flist,&tnode);
    }
}

void pop_front_all()
{
    printf ( "Test %s ::\n",__func__ );
    TMyNode tnode;
    while ( !flist.empty(&flist) )
    {
        flist.pop_front ( &flist,&tnode );
        showstruct(&tnode);
    }
}

void pop_back_all()
{
    printf ( "Test %s ::\n",__func__ );
    TMyNode tnode;
    while ( !flist.empty(&flist) )
    {
        flist.pop_back ( &flist,&tnode );
        showstruct(&tnode);
    }
}



int main () 
{
    Init_Log("FList","./log/",DEBUG_LEVEL,1024,PTHREAD_MODE);
    flist.init(&flist);
    add_front(16);
    pop_back_all();

    add_back(16);
    pop_front_all();
    

    flist.clear(&flist);

    return 0;
}
