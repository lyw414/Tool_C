#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int a1 = 1;
int a2 = 1;
int a3 = 1;
int a4 = 1;
int a5 = 1;
int a6 = 1;
int a7 = 1;
int a8 = 1;

int sum ( int x, int y)
{
    switch(x)
    {
    case 1 :
        x = 1;
    case 2 :
        x = 2;
    default :
        x = 3;

    }
    return x;
}


int loop1( int loop, int x  )
{

    while ( loop > 1 );
    {
        x--;
        loop--;
    }
    return x;

}

int test1 ( int x1, int x2, int x3, int x4, int x5, int x6, int x7, int x8 )
{
    volatile int z;
    return 0;
}

void call_test1()
{
    test1 ( a1, a2, a3, a4, a5, a6, a7, a8 );
}


void compare()
{
    int a = 10;
    int b = 20;
    char oC = 0x33;
    char oC1 = 0x34;

    if ( a > b )
    {
        return;
    }

    if ( oC > oC1 )
    {
        return;
    }
}
int main ( int argc, char * argv[] )
{
    call_test1 ( );
    return 0;
}
