#include "Stack.h"

typedef struct mynode
{
    int a;
    char buf[10];
} TMyNode;


Stack(myStack,TMyNode,12);

void showstruct(TMyNode * node)
{
    printf ( "%d [%s]\n",node->a,node->buf);
}

void add_all(int num)
{
    int iLoop = 0;
    TMyNode tnode;
    for ( iLoop = 0; iLoop < num; iLoop++ )
    {
        tnode.a = iLoop;
        sprintf ( tnode.buf, "%d", iLoop );
        myStack.push(&myStack,&tnode);
    }
}
void pop_all()
{
    TMyNode tnode;
    while ( !myStack.empty(&myStack) )
    {
        myStack.pop(&myStack,&tnode);
        showstruct(&tnode);
    }
}




int main ()
{
    Init_Log("Stack","./log/",DEBUG_LEVEL,1024,PTHREAD_MODE);
    myStack.init(&myStack);
    add_all(15);
    pop_all();
    return 0;
}
