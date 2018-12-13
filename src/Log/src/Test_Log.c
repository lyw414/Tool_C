#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include "Log.h"



void * func ( void * p )
{
    sleep ( 1 );
    int iLoop = 0;
    while ( iLoop < 20 )
    {
        iLoop ++;
        UserError("in %s :: %d",__func__,iLoop );
        UserWarning("in %s :: %d",__func__,iLoop );
        UserDebug("in %s :: %d",__func__,iLoop );
    }
    return NULL;
}


int main()
{
    pthread_t t1;
    pthread_t t2;
    int ret1, ret2;
    Init_Log ( "LYWTEST","./",ERROR_LEVEL,10,PTHREAD_MODE);
    
    ret1 = pthread_create ( &t1,NULL,func,NULL);
    printf ( "pthread [%d] create\n",ret1);
    ret2 = pthread_create ( &t2,NULL,func,NULL);
    printf ( "pthread [%d] create\n",ret2);

    pthread_join ( t1, NULL );
    pthread_join ( t2, NULL );


    return 0;
}
