#include "Sort.h"
TCompareResultForSort CompareForSort ( void * data1,void * data2 )
{
    if ( (int)data1 == (int)data2 )    
    {
        return EQUAL;
    }
    else if ( (int)data1 > (int)data2 )    
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
    Sort(p,CompareForSort);
    p.SortFunc(&p,NULL,2,INSERT_SORT);
    return 0;
}
