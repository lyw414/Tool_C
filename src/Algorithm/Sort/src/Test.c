#include "Sort.h"
#include <stdlib.h>
#include <sys/time.h>
TCompareResultForSort CompareForSort ( void * data1,void * data2 )
{

    if ( (*(int *)(data1)) == (*(int*)(data2)) )    
    {
        return EQUAL;
    }
    else if ( (*(int *)(data1)) > (*(int *)(data2)) )    
    {
        return LESSTHAN;
    }
    else
    {
        return GREATERTHAN;
    }
}

int main()
{
    int maxsize = 102400000;
    int * a = (int *)malloc ( maxsize * sizeof (int));
    int * b = (int *)malloc ( maxsize * sizeof (int));

    int iLoop = 0;
    struct timeval tv;
    struct timeval tv1;

    for ( iLoop = 0; iLoop < maxsize; iLoop++)
    {
        b[iLoop] = random();
    }


//    Sort(p,CompareForSort);
    PSort p = Init_Sort ( CompareForSort );


    memcpy ( a,b,maxsize * sizeof ( int )  );
    gettimeofday ( &tv, NULL);
    //p->SortFunc(&p,a,sizeof(int),maxsize ,Bubble_SORT);
    gettimeofday ( &tv1, NULL);
    printf ( "Bubble %d\n", tv1.tv_sec*1000000 + tv1.tv_usec - tv.tv_sec*1000000 - tv.tv_usec);

    memcpy ( a,b,maxsize * sizeof ( int )  );
    gettimeofday ( &tv, NULL);
    //p->SortFunc(p,a,sizeof(int),maxsize,SELECT_SORT);
    gettimeofday ( &tv1, NULL);
    printf ( "Select %d\n", tv1.tv_sec*1000000 + tv1.tv_usec - tv.tv_sec*1000000 - tv.tv_usec);

    memcpy ( a,b,maxsize * sizeof ( int )  );
    gettimeofday ( &tv, NULL);
    //p->SortFunc(p,a,sizeof(int),maxsize ,DIRECT_INSERT_SORT);
    gettimeofday ( &tv1, NULL);
    printf ( "direct insert %d\n", tv1.tv_sec*1000000 + tv1.tv_usec - tv.tv_sec*1000000 - tv.tv_usec);
    
    memcpy ( a,b,maxsize * sizeof ( int )  );
    gettimeofday ( &tv, NULL);
    //p->SortFunc(p,a,sizeof(int),maxsize ,INSERT_SORT);
    gettimeofday ( &tv1, NULL);
    printf ( "binary insert %d\n", tv1.tv_sec*1000000 + tv1.tv_usec - tv.tv_sec*1000000 - tv.tv_usec);

    memcpy ( a,b,maxsize * sizeof ( int )  );
    gettimeofday ( &tv, NULL);
    //p->SortFunc(p,a,sizeof(int),maxsize ,SHELL_SORT);
    gettimeofday ( &tv1, NULL);
    printf ( "SHELL %d\n", tv1.tv_sec*1000000 + tv1.tv_usec - tv.tv_sec*1000000 - tv.tv_usec);



    memcpy ( a,b,maxsize * sizeof ( int )  );
    gettimeofday ( &tv, NULL);
    p->SortFunc(p,a,sizeof(int),maxsize,QUICK_SORT);
    gettimeofday ( &tv1, NULL);
    printf ( "quick %d\n", tv1.tv_sec*1000000 + tv1.tv_usec - tv.tv_sec*1000000 - tv.tv_usec);

    //for ( iLoop = 0; iLoop < maxsize; iLoop++ )
    //{
    //    printf ("%d ",a[iLoop] );
    //}
    //printf ("\n\n");



    memcpy ( a,b,maxsize * sizeof ( int )  );
    gettimeofday ( &tv, NULL);
    p->SortFunc(p,a,sizeof(int),maxsize,MERGE_SORT);
    gettimeofday ( &tv1, NULL);
    printf ( "merge %d\n", tv1.tv_sec*1000000 + tv1.tv_usec - tv.tv_sec*1000000 - tv.tv_usec);



    //memcpy ( a,b,maxsize * sizeof ( int )  );
    gettimeofday ( &tv, NULL);
    qsort (b,maxsize,sizeof(int),CompareForSort);
    gettimeofday ( &tv1, NULL);
    printf ( "sys quick %d\n", tv1.tv_sec*1000000 + tv1.tv_usec - tv.tv_sec*1000000 - tv.tv_usec);

    if ( memcmp ( a, b , maxsize * sizeof (int) ) != 0 )
    {
        printf ("FALSE\n");
    }
    else
    {
        printf ("TRUE\n");
    }

    //for ( iLoop = 0; iLoop < maxsize; iLoop++ )
    //{
    //    printf ("%d ",a[iLoop] );
    //}
    //printf ("\n");

    //for ( iLoop = 0; iLoop < maxsize; iLoop++ )
    //{
    //    printf ("%d ",b[iLoop] );
    //}
    //printf ("\n");



    Free_Sort ( p );
    return 0;
}
