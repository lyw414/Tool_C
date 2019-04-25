#include "Sort.h"
bool SortForSort ( struct _Sort * this, void * DataArray,size_t DataSize,size_t ArraySize,TSortAlgorithmForSort SortAlgorithm)
{
    return _g_SortFuncArray[SortAlgorithm] ( DataArray,DataSize,ArraySize,this->Compare);
}
bool SetCompareForSort ( struct _Sort * this,TCompareForSort Compare)
{
    this->Compare = Compare;
    return true;
}
