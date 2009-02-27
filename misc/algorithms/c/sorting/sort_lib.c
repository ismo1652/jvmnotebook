//////////////////////////////////////////////////////////////////////
// Simple Quick Sort
/////////////////////
// Berlin Brown
//
// Based on the Quick Sort By:
// @author George Heineman (original)
// @date 6/15/08 (original)
// Core algorithm copyrighted to O'Reilly, Algorithms in a Nutshell
//////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <malloc.h>

/**
 * Group the subarray around a pivot element within the subarray.
 */
int sort_partition(void **arr, int(*cmp)(const void *, const void*),
                   int left, int right, int pivot_index) {
    int   idx;
    int   store;
    void  *pivot = arr[pivot_index];

    // Move the pivot to the end of the array
    void *tmp = arr[right];
    arr[right] = arr[pivot_index];
    arr[pivot_index] = tmp;

    // All values less than the pivot are moved
    // to the front of the array and pivot inserted 
    // just after them.
    store = left;
    for (idx = left; idx < right; idx++) {
        
        if (cmp(arr[idx], pivot) <= 0){
            tmp = arr[idx];
            arr[idx]   = arr[store];
            arr[store] = tmp;
            store++;
        } // End of the If

    } // End of the For
    
    tmp = arr[right];
    arr[right]  = arr[store];
    arr[store]  = tmp;
    return store;

} // End of the Function

