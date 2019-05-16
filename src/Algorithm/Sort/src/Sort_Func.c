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

bool Func_Select_Sort ( void * DataArray, size_t DataSize, size_t ArraySize, TCompareForSort compare_func )
{
    int iLoop1;
    int iLoop2;
    void * tmp = malloc ( DataSize );
    int Index = 0;
    //查找最小
    for ( iLoop1 = 0; iLoop1 < ArraySize; iLoop1++ )
    {
        Index = iLoop1;
        for ( iLoop2 = iLoop1 + 1; iLoop2 < ArraySize; iLoop2++ )
        {
            switch ( compare_func ( DataArray + Index * DataSize,DataArray + iLoop2 * DataSize ) )
            {
                case EQUAL:
                    continue;
                case GREATERTHAN:
                    continue;
                case LESSTHAN:
                    Index = iLoop2;
                    continue;
                default :
                    return false;
            }
        }
        swap ( DataArray,DataSize,ArraySize,tmp,iLoop1,Index );
    }
    free ( tmp );
    return true;
}

bool Func_Shell_Sort ( void * DataArray, size_t DataSize, size_t ArraySize, TCompareForSort compare_func )
{
    size_t uiStepLength = ArraySize / 2;
    size_t uiLoop1 = 0;
    size_t uiLoop2 = 0;
    int iIndex = 0;
    void * tmpbuffer = malloc ( DataSize );
    //步长计算 方式为 2 的倍数递进 
    
    while ( uiStepLength >= 1 )
    {
        //按步长进行一轮直插排序
        for ( uiLoop1 = 0; uiLoop1 < uiStepLength; uiLoop1 ++ )
        {
            for ( iIndex = uiLoop1,uiLoop2 = uiLoop1 + uiStepLength; uiLoop2 < ArraySize; uiLoop2 += uiStepLength )
            {
                //直插排序 带步长
                switch ( compare_func ( DataArray + iIndex * DataSize, DataArray + uiLoop2 * DataSize ) )
                {
                    case EQUAL:
                    case GREATERTHAN:
                        break;
                    case LESSTHAN:
                        memcpy(tmpbuffer,DataArray + uiLoop2 * DataSize, DataSize);
                        //后移
                        memcpy ( DataArray + uiLoop2 * DataSize, DataArray + iIndex * DataSize, DataSize );
                        iIndex -= uiStepLength;
                        while ( iIndex >= 0 && compare_func ( DataArray + iIndex * DataSize, tmpbuffer )  == LESSTHAN )
                        {
                            //后移 
                            memcpy(DataArray + ( iIndex  + uiStepLength )* DataSize, DataArray + iIndex * DataSize, DataSize);
                            iIndex -= uiStepLength;

                        }
                        memcpy ( DataArray + ( iIndex + uiStepLength ) * DataSize, tmpbuffer,DataSize );
                        break;
                    default :
                        return false;
                }
                iIndex = uiLoop2;
                         
            }
        }

        uiStepLength /= 2;
    }

    return true;
}






//end file
