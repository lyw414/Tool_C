#include "Sort_Func.h"
static bool swap(void * DataArray,size_t DataSize,size_t ArraySize, void * tmpBuff,int i, int j )
{
    void * tmp = tmpBuff;
    if ( i > ArraySize || j > ArraySize )
    {
        return false;
    }
    memcpy ( tmp, DataArray + i * DataSize,DataSize);
    memcpy ( DataArray + i * DataSize,DataArray + j * DataSize,DataSize);
    memcpy ( DataArray + j * DataSize,tmp,DataSize);
    return true;
}


/*
 * @brief 查找SearcheData可以插入的位置
 *
 */

static int BinaryInsert(void * DataArray, void * SearchData,size_t DataSize,size_t ArraySize, TCompareForSort compare_func)
{
    int beginIndex = 0;
    int endIndex = ArraySize - 1;

    int compareIndex = (beginIndex + endIndex) / 2;

    while (  endIndex > beginIndex )
    {
        compareIndex = ( beginIndex + endIndex ) / 2 ;
        switch ( compare_func ( DataArray + compareIndex * DataSize, SearchData ) )
        {
            case EQUAL:
                return compareIndex;
            case LESSTHAN :
                endIndex = compareIndex - 1;
                break;
            case GREATERTHAN :
                beginIndex = compareIndex + 1;
                break;
        }

    }

    switch ( compare_func ( DataArray + beginIndex* DataSize ,SearchData) )
    {
        case EQUAL: 
            return beginIndex;
        case LESSTHAN :
            return beginIndex;
        case GREATERTHAN :
            return beginIndex + 1;
    }

    return 0;
}


bool Func_INSERT_SORT ( void * DataArray,size_t DataSize,size_t ArraySize,TCompareForSort compare_func)
{

    int iLoop = 0;
    int iLoop2 = 0;
    int insertIndex = 0;
    void * tmp = malloc ( DataSize );

    for ( iLoop = 1; iLoop < ArraySize; iLoop++)
    {
        insertIndex = BinaryInsert ( DataArray,DataArray + iLoop * DataSize,DataSize,iLoop,compare_func );
        if ( insertIndex == iLoop )
        {
            continue;
        }

        else
        {
            memcpy ( tmp, DataArray +  iLoop * DataSize, DataSize);
            for ( iLoop2 = iLoop - 1; iLoop2 >= insertIndex; iLoop2-- )
            {
                memcpy ( DataArray + ( iLoop2 + 1) * DataSize,DataArray +  iLoop2 * DataSize,DataSize );
            }
            memcpy ( DataArray + insertIndex * DataSize,tmp, DataSize);
        }

    }
    free ( tmp ) ;
    return true;
}

bool Func_Bubble_SORT ( void * DataArray,size_t DataSize,size_t ArraySize,TCompareForSort compare_func)
{
    int iLoop1;
    int iLoop2;
    void *tmp = malloc ( DataSize );
    for ( iLoop1 = 0; iLoop1 < ArraySize; iLoop1++)
    {
        for ( iLoop2 = iLoop1 + 1; iLoop2 < ArraySize;iLoop2++)
        {
            switch ( compare_func ( DataArray + iLoop1 * DataSize,DataArray + iLoop2*DataSize ) )
            {
                case EQUAL:
                    continue;
                case GREATERTHAN:
                    continue;
                case LESSTHAN:
                    swap ( DataArray,DataSize,ArraySize,tmp,iLoop1,iLoop2 );
                    continue;
            }
        }

    }
    free ( tmp );
    return true;
}


//end file
