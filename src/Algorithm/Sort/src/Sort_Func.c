#include "Sort_Func.h"
bool direct_insert_sort ( void * DataArray,size_t DataSize,size_t ArraySize,TCompareForSort compare_func)
{
    void * tmp = malloc ( DataSize );
    int iLoop1 = 0;
    int iLoop2 = 0;

    for ( iLoop1 = 1; iLoop1 < ArraySize; iLoop1++ )
    {
        //first compare decide whether do memcpy and swap
        switch ( compare_func ( DataArray + DataSize * ( iLoop1 - 1 ),DataArray + DataSize * iLoop1 ) )
        {
            case EQUAL :
            case GREATERTHAN :
                continue;
            case LESSTHAN :
                iLoop2 = iLoop1 - 1;
                memcpy ( tmp, DataArray + DataSize * iLoop1, DataSize );
                //backward shift 
                memcpy ( DataArray + DataSize * ( iLoop2 + 1 ),DataArray + DataSize *  iLoop2, DataSize );
                while ( 1 )
                {
                    switch ( compare_func ( DataArray + DataSize * iLoop2, tmp ) )
                    {

                        case EQUAL :
                        case GREATERTHAN :
                            //swap tmp to index [iLoop2 + 1]
                            memcpy ( DataArray + ( iLoop2 + 1 ) * DataSize, tmp, DataSize );
                            break;
                        case LESSTHAN :
                            //backward shift 
                            memcpy ( DataArray + DataSize * ( iLoop2 + 1 ),DataArray + DataSize *  iLoop2, DataSize );
                            // index iLoop2 move forward
                            iLoop2--;
                            if ( iLoop2 < 0 )
                            {
                                //swap tmp to first 
                                memcpy (DataArray ,tmp ,DataSize );
                                break;
                            }
                            else
                            {
                                continue;
                            }

                        default :
                            free ( tmp );
                            return false;
                    }
                    break;
                }
                continue;
            default :
                free ( tmp );
                return false;
        }
    }

    free ( tmp );
    return false;
}
static void showint ( void * DataArray,size_t ArraySize )
{
    int iLoop = 0;
    for ( iLoop = 0; iLoop < ArraySize; iLoop++ )
    {
        printf ( "%d ",*((int *)(DataArray) + iLoop ) );

    }
    printf ("\n");
}

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
/*
 * @brief this func is used for select Axle value from DataArray when defaule
 *        use simple Methon : only compare first middle last three value, when value less than 3 return middle , this default function 
 *
 * return > 0 Axle Value index 
 *            error
 */
static int AxleValueSelect ( void * DataArray,size_t DataSize,size_t ArraySize,TCompareForSort compare_func)
{
    switch ( ArraySize )
    {
        case 0 :
            return -1;
        case 1 :
            return 0;
        case 2 :
            return 1;
        default :
            switch ( compare_func ( DataArray, DataArray + ( ArraySize / 2 ) * DataSize ) )
            {
                case EQUAL :
                case GREATERTHAN :
                    switch ( compare_func ( DataArray + ( ArraySize / 2 ) * DataSize , DataArray + ( ArraySize - 1 ) * DataSize ) )
                    {
                        case EQUAL :
                        case GREATERTHAN :
                            return ( ArraySize / 2 );
                        case LESSTHAN :
                            switch ( compare_func ( DataArray , DataArray + ( ArraySize - 1 ) * DataSize ) )
                            {
                                case EQUAL:
                                case GREATERTHAN :
                                    return ( ArraySize - 1 );
                                case LESSTHAN :
                                    return 0;
                                default :
                                    return -1;
                            }
                        default :
                            return -1;
                    }
                case LESSTHAN :
                    switch ( compare_func ( DataArray,  DataArray + ( ArraySize - 1 ) * DataSize ) )
                    {
                        case EQUAL :
                        case GREATERTHAN :
                            return 0;
                        case LESSTHAN :
                            switch ( compare_func ( DataArray + ( ArraySize / 2 ) * DataSize, DataArray + ( ArraySize - 1 ) * DataSize ) )
                            {
                                case EQUAL:
                                case GREATERTHAN :
                                    return ( ArraySize - 1 );
                                case LESSTHAN :
                                    return ( ArraySize / 2 );
                                default :
                                    return -1;
                            }
                        default :
                            return -1;

                    }
                default :
                    return -1;
            }


    }

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

bool Func_Quick_Sort ( void * DataArray, size_t DataSize, size_t ArraySize, TCompareForSort compare_func )
{
    //Apply buffer for axle value and use it like queue
    int * GroupIndex_use = NULL;
    int * GroupIndex_free = NULL;
    int * GroupIndex_tmp = NULL;
    size_t EffectiveGroupNum_use = 0;
    size_t EffectiveGroupNum_free = 0;
    //size_t EffectiveGroupNum_tmp = 0;
    //int BeginIndex = 0;
    //int Endindex = 1;

    void * tmp = NULL;  

    //if size less than MinQuickSortSize use direct_insert_sort 
    size_t MinQuickSortSize = 16;
    
    int iLoop1 = 0;
    int iLoop2 = 0;
    int iLoop3 = 0;
    int index  = 0;

    if ( MinQuickSortSize >= ArraySize )
    {
        return direct_insert_sort ( DataArray, DataSize, ArraySize, compare_func );
    }
    else
    {
        EffectiveGroupNum_use = 1;
    }
    
    //calculate Max effective group number and allocate memory
    GroupIndex_use = (int *)malloc ( ( ( ArraySize / MinQuickSortSize + 1 ) * 2 ) * sizeof ( int ) );
    GroupIndex_free = (int *)malloc ( ( ( ArraySize / MinQuickSortSize + 1 ) * 2 ) * sizeof ( int ) );
    GroupIndex_use[0] = 0;
    GroupIndex_use[1] = ArraySize;


    tmp = malloc ( DataSize );
    //this function pointer is for set but not realize it 
    int ( * AxleValueSelectFunc ) ( void * DataArray, size_t DataSize, size_t ArraySize, TCompareForSort compare_func ) = AxleValueSelect;
    
    // no effective Group  stop it
    while ( EffectiveGroupNum_use > 0 )
    {
        //printf ( "%d %d %d\n", EffectiveGroupNum_use,  *(int *)(DataArray + GroupIndex_use[0] * DataSize), *(int *)(DataArray + ( GroupIndex_use[0]  +  GroupIndex_use[ 1] - 1 ) * DataSize ) );
        //printf ( "%d %d %d\n", EffectiveGroupNum_use,  GroupIndex_use[0],  GroupIndex_use[0]  +  GroupIndex_use[ 1] - 1 );
        //printf ( "%d\n", EffectiveGroupNum_use );
        
        for ( iLoop3 = 0; iLoop3 < EffectiveGroupNum_use; iLoop3++ ) 
        {
            iLoop1 = GroupIndex_use[iLoop3 * 2];
            iLoop2 = iLoop1 + GroupIndex_use[iLoop3 * 2 + 1] - 1;
            
            //select Axle Value
            index = AxleValueSelectFunc ( DataArray + iLoop1 * DataSize, DataSize, GroupIndex_use[iLoop3 * 2 + 1], compare_func );
            //swap Last Value with Axle Value 
            memcpy ( tmp, DataArray + ( index + iLoop1 ) * DataSize, DataSize );
            memcpy ( DataArray + (index + iLoop1 )* DataSize, DataArray + iLoop2 * DataSize, DataSize );
            //adjust Array to two part, one less than Axle Value . the other Greater than Axle Value
            while ( iLoop1 != iLoop2 )
            {
                while ( iLoop1 != iLoop2 )
                {

                    switch ( compare_func ( tmp, DataArray + iLoop1 * DataSize ) )
                    {
                        case EQUAL : //this make data balance
                        case GREATERTHAN :

                            //put iLoop1 to iLoop2 and do iLoop2 
                            memcpy ( DataArray + iLoop2 * DataSize, DataArray + iLoop1 * DataSize,DataSize );
                            iLoop2--;
                            if ( iLoop1 == iLoop2 )
                            {
                                memcpy ( DataArray + iLoop1 * DataSize, tmp, DataSize );
                            }
                            break;
                        case LESSTHAN :
                            iLoop1++;
                            if ( iLoop1 == iLoop2 )
                            {
                                memcpy ( DataArray + iLoop1 * DataSize, tmp, DataSize );
                                break;
                            }
                            else
                            {
                                continue;
                            }
                        default :
                            return false;
                    }

                    break;
                }

                while ( iLoop1 != iLoop2 )
                {
                    switch ( compare_func ( tmp, DataArray + iLoop2 * DataSize ) )
                    {
                        case EQUAL : //this make data balance
                        case LESSTHAN :
                            //put iLoop2 to iLoop1 and do iLoop1
                            memcpy ( DataArray + iLoop1 * DataSize, DataArray + iLoop2 * DataSize,DataSize );
                            iLoop1++;
                            if ( iLoop1 == iLoop2 )
                            {
                                memcpy ( DataArray + iLoop2 * DataSize, tmp, DataSize );
                            }
                            break;
                        case GREATERTHAN :
                            iLoop2--;
                            if ( iLoop1 == iLoop2 )
                            {
                                memcpy ( DataArray + iLoop2 * DataSize, tmp, DataSize );
                                break;
                            }
                            else
                            {
                                continue;
                            }
 
                            continue;
                        default :
                            return false;
                    }
                    break;
                }

            }
            //printf ( "%d %d %d\n",*(int *)tmp,GroupIndex_use[iLoop3 * 2 ], GroupIndex_use[iLoop3 * 2 + 1 ] );
            //showint(DataArray,ArraySize);
            //put new group to GroupArray 
            if (  iLoop1 - GroupIndex_use[iLoop3 * 2 ] > MinQuickSortSize ) 
            {
                GroupIndex_free[EffectiveGroupNum_free*2] = GroupIndex_use[iLoop3 * 2 ];
                GroupIndex_free[EffectiveGroupNum_free*2+1] = iLoop1 - GroupIndex_use[iLoop3*2];
                EffectiveGroupNum_free++;
            }

            if (  GroupIndex_use[iLoop3 * 2 + 1] - iLoop1 + GroupIndex_use[iLoop3*2] - 1 > MinQuickSortSize ) 
            {
                GroupIndex_free[EffectiveGroupNum_free*2] = iLoop1 + 1;
                GroupIndex_free[EffectiveGroupNum_free*2+1] = GroupIndex_use[iLoop3 * 2 + 1] - iLoop1 - 1 + GroupIndex_use[iLoop3*2];
                EffectiveGroupNum_free++;
            }


        }
        //change group pointer and EffectiveGroupNum 
        GroupIndex_tmp = GroupIndex_use;
        GroupIndex_use = GroupIndex_free;
        GroupIndex_free = GroupIndex_tmp;

        EffectiveGroupNum_use = EffectiveGroupNum_free;
        EffectiveGroupNum_free = 0;
    }
    
    //Do Direct Insert Sort at Last
    direct_insert_sort ( DataArray, DataSize, ArraySize, compare_func );
    free ( GroupIndex_use );
    free ( GroupIndex_free );
    return true;

}

bool Func_Merge_Sort( void * DataArray,size_t DataSize,size_t ArraySize,TCompareForSort compare_func)
{
    
    int MinMergeSortSize = 16; //must be power of 2

    int GroupSize = 0;
    int iLoop = 0;
    int iLoop1 = 0;
    int iLoop2 = 0;
    int iLoop3 = 0;
    int endIndex1 = 0;
    int endIndex2 = 0;
    int MergeTimes= 0;
    void *DataArray_use = DataArray;
    void *DataArray_free = malloc ( DataSize * ArraySize );
    void *DataArray_tmp = NULL;

    // regard MinMergerSortSize as steplength, do direct insert sort
    GroupSize = MinMergeSortSize;
    if (  ArraySize % GroupSize == 0 )
    {
        if ( ArraySize / GroupSize % 2 == 0 )
        {
            MergeTimes = ArraySize / GroupSize / 2;
        }
        else
        {
            MergeTimes = (ArraySize / GroupSize + 1 )/ 2;
        }
    }
    else
    {
        if ( ( ArraySize / GroupSize + 1 ) % 2 == 0 )
        {
            MergeTimes = ( ArraySize / GroupSize + 1 ) / 2;
        }
        else
        {

            MergeTimes = ( ( ArraySize / GroupSize + 1 ) + 1 ) / 2;
        }

    }
    for ( iLoop = 0; (iLoop + 1 )* GroupSize < ArraySize; iLoop++ )
    {
        direct_insert_sort ( DataArray_use + iLoop * GroupSize * DataSize, DataSize, GroupSize,compare_func );
    }
    //left number of Array's member need recalculate 
    direct_insert_sort ( DataArray_use + iLoop * GroupSize * DataSize, DataSize, ArraySize - iLoop * GroupSize, compare_func );

    while ( GroupSize < ArraySize )
    {

        //do merger step length is GroupSize and merger times is GroupNum
        for ( iLoop = 0; iLoop < MergeTimes - 1; iLoop++ )
        {
            //merge from DataArray_use to DataArray_free
            iLoop1 = iLoop * 2 * GroupSize; // index of first part of DataArray_use
            iLoop2 = ( iLoop * 2 + 1 ) * GroupSize;//index of second part of DataArray_use
            iLoop3 = iLoop1; // index of DataArray_free
            endIndex2 = ( iLoop * 2 + 2 )* GroupSize;
            endIndex1 = ( iLoop * 2 + 1 )* GroupSize;

            while ( iLoop1 < endIndex1 && iLoop2 < endIndex2 ) //end index of DataArray_free
            {
                switch ( compare_func ( DataArray_use + iLoop1 * DataSize,  DataArray_use + iLoop2 * DataSize ) )
                {
                    case EQUAL :
                        memcpy ( DataArray_free + iLoop3 * DataSize, DataArray_use + iLoop1 * DataSize, DataSize );
                        iLoop3++;
                        iLoop1++;
                        memcpy ( DataArray_free + iLoop3 * DataSize, DataArray_use + iLoop2 * DataSize, DataSize );
                        iLoop3++;
                        iLoop2++;
                        break;

                    case GREATERTHAN :
                         memcpy ( DataArray_free + iLoop3 * DataSize, DataArray_use + iLoop1 * DataSize, DataSize );
                        iLoop3++;
                        iLoop1++;
                        break;

                    case LESSTHAN :
                        memcpy ( DataArray_free + iLoop3 * DataSize, DataArray_use + iLoop2 * DataSize, DataSize );
                        iLoop3++;
                        iLoop2++;
                        break;
                    default :
                        return false;
                }

            }
            while (  iLoop1 < endIndex1 )
            {
                memcpy ( DataArray_free + iLoop3 * DataSize, DataArray_use + iLoop1 * DataSize, DataSize );
                iLoop3++;
                iLoop1++;
            }
            while ( iLoop2 < endIndex2 )
            {
                memcpy ( DataArray_free + iLoop3 * DataSize, DataArray_use + iLoop2 * DataSize, DataSize );
                iLoop3++;
                iLoop2++;
            }

        }
        //the last pair of group meybe short than GroupSize need judge length , do it separetly

        iLoop1 = iLoop * 2 * GroupSize; // index of first part of DataArray_use
        iLoop2 = ( iLoop * 2 + 1 ) * GroupSize;//index of second part of DataArray_use
        iLoop3 = iLoop1; // index of DataArray_free

        endIndex2 = ( iLoop * 2 + 2 )* GroupSize;
        endIndex1 = ( iLoop * 2 + 1 )* GroupSize;
    
        if ( iLoop1 < ArraySize && iLoop2 < ArraySize )
        {
            //there are two groups buf the second group's length maybe not enough
            while ( iLoop1 < endIndex1 && iLoop2 < ArraySize )
            {
                switch ( compare_func ( DataArray_use + iLoop1 * DataSize,  DataArray_use + iLoop2 * DataSize ) )
                {
                    case EQUAL :
                        memcpy ( DataArray_free + iLoop3 * DataSize, DataArray_use + iLoop1 * DataSize, DataSize );
                        iLoop3++;
                        iLoop1++;
                        memcpy ( DataArray_free + iLoop3 * DataSize, DataArray_use + iLoop2 * DataSize, DataSize );
                        iLoop3++;
                        iLoop2++;
                        break;

                    case GREATERTHAN :
                         memcpy ( DataArray_free + iLoop3 * DataSize, DataArray_use + iLoop1 * DataSize, DataSize );
                        iLoop3++;
                        iLoop1++;
                        break;

                    case LESSTHAN :
                        memcpy ( DataArray_free + iLoop3 * DataSize, DataArray_use + iLoop2 * DataSize, DataSize );
                        iLoop3++;
                        iLoop2++;
                        break;
                    default :
                        return false;
                }

            }
            while ( iLoop1 < ( iLoop * 2 + 1 ) * GroupSize )
            {
                memcpy ( DataArray_free + iLoop3 * DataSize, DataArray_use + iLoop1 * DataSize, DataSize );
                iLoop3++;
                iLoop1++;
            }
            while ( iLoop2 < ArraySize )
            {
                memcpy ( DataArray_free + iLoop3 * DataSize, DataArray_use + iLoop2 * DataSize, DataSize );
                iLoop3++;
                iLoop2++;
            }
        }
        else 
        {
            //copy to DataArray_free
            while ( iLoop1 < ArraySize )
            {
                memcpy ( DataArray_free + iLoop3 * DataSize, DataArray_use + iLoop1 * DataSize, DataSize );
                iLoop3++;
                iLoop1++;

            }
        }

        //swap DataArray_free with DataArray_use and recalculate mergeTimes
        DataArray_tmp = DataArray_use;
        DataArray_use = DataArray_free;
        DataArray_free = DataArray_tmp;

        GroupSize *= 2;

        if (  ArraySize % GroupSize == 0 )
        {
            if ( ArraySize / GroupSize % 2 == 0 )
            {
                MergeTimes = ArraySize / GroupSize / 2;
            }
            else
            {
                MergeTimes = (ArraySize / GroupSize + 1 )/ 2;
            }
        }
        else
        {
            if ( ( ArraySize / GroupSize + 1 ) % 2 == 0 )
            {
                MergeTimes = ( ArraySize / GroupSize + 1 ) / 2;
            }
            else
            {

                MergeTimes = ( ( ArraySize / GroupSize + 1 ) + 1 ) / 2;
            }

        }
        //showint ( DataArray_use,ArraySize );

    }

    //if DataArray_use is not DataArray copy DataArray_use to DataArray
    if ( DataArray_use != DataArray )
    {
        memcpy ( DataArray,DataArray_use, ArraySize * DataSize );
        free ( DataArray_use );
    }
    else
    {
        free ( DataArray_free );
    }

    return true;
}

//end file
