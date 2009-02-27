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

extern int sort_partition(void **arr, int(*cmp)(const void *, const void*),
                          int left, int right, int pivot_index);

/**
 * Find the position of the kth element
 */
int select_kth(void **arr, int (*cmp)(const void*, const void *),
               int k, int left, int right) {
    int idx = select_pivot_index(arr, left, right);
    
    int pivot_index = partition(arr, cmp, left, right, idx);
    if (left + k -1  == pivot_index) {
        return pivot_index;
    }

    // Continue the loop, narrowing the range.
    if (left+k-1 < pivot_index) {
        return select_kth(arr, cmp, k, left, pivot_index - 1);
    } else {
        return select_kth(arr, cmp, k - (pivot_index-left+1), pivot_index+1, right);
    } // End of the if - else
}

void median_sort(void**arg, int(*cmp)(const void *, const void *),
                 int left, int right) {

    // If the subarray to be sorted has 1 (or fewer) elements
    // We are done.
    if (right <= left) {
        return;
    }

    // Get the midpoint and median element position
    int mid = (right - left + 1) / 2;
    int me  = select_kth(arr, cmp, mid+1, left, right);

    median_sort(arr, cmp, left, left+mid-1);
    median_sort(arr, cmp, left + mid + 1, right);
    
} // End of the Function //

/**
 * Main Entry Point.
 */
int main(const int argc, const char *argv[]) {

    printf("Running Median Sort\n");
    printf("Done\n");
    // zero is success, one is error.
    exit(0);
}
