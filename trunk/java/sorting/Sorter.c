//// For C/JNI, quick sort
//// 11/11/2012
//// Berlin Brown
//// CYGWIN_NT-6.1-WOW64 1.7.17(0.262/5/3) 2012-10-19 14:39 i686 Cygwin
//// i686-pc-mingw32-g++ (GCC) 4.5.2
//// On average, O(n log n) comparisons


#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sorter.h"

#if !defined(ARRAY_SIZE)
    #define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))
#endif

int swaps = 0;
int calls = 0;
int part_calls = 0;
int brute_ops = 0;

int findPivotIndex(int l, int r, int A[]) {
    int mi = (l + r) / 2;
    int li = l;
    int res = 0;
    if (A[li] >= A[mi]) {
        li = mi;
        mi = l;
    }
    if (A[r] <= A[li]) {
        res = li;
    } else if (A[r] <= A[mi]) {
        res = mi;
    }
    res = r;
    return res;
}

int part(int l, int r, int pi, int A[]) {
    int piv = A[pi];
    int tmp = 0;
    tmp = A[r];
    A[r] = A[pi];
    A[pi] = tmp;
    int store = l;
    for (int idx = l; idx < r; idx++) {
        if (A[idx] <= piv) {
            swaps++;
            tmp = A[idx];
            A[idx] = A[store];
            A[store] = tmp;
            store++;  
        }
        // count number of comparisons
        part_calls++;
    }
    tmp = A[r];
    A[r] = A[store];
    A[store] = tmp;
    return store;
}

void sort(int l, int r, int A[]) {
    if (r <= l) {
        return;
    }
    calls++;
    int pi = findPivotIndex(l, r, A);
    pi = part(l, r, pi, A);
    sort(l, pi - 1, A);
    sort(pi+1, r, A);
}

void brute_sort(int a, int len, int A[]) {
    int i = 0;
    int j = 0;
    int tmp = 0;
    int *b;
    for (i = 0; i < len; i++) {
        for (j = 0; j < len; j++) {
            if (A[i] < A[j]) {
                // swap
                tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
            brute_ops++;
        }
    }
    free(b);
}

/*
 * Class:     Sorter
 * Method:    sort
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_Sorter_sort(JNIEnv *env, jobject obj, jstring string) {
    const char *str = env->GetStringUTFChars(string, 0);
    char cap[255];
    int *ptr;
    int *ptr2;
    strcpy(cap, str);
    env->ReleaseStringUTFChars(string, str);
    printf("+ Launching Sort : %s \n", cap);

    const int sz = 160000 ;
    ptr = (int*) malloc(sz * sizeof(int));
    ptr2 = (int*) malloc(sz * sizeof(int)); 

    // Open the file and close
    FILE *fp;
    char line[255];
    int num = 0;
    int lines = 0;
    fp = fopen(cap, "r");
    if (fp != NULL) {
        while (fgets(line, sizeof(line), fp) != NULL) {
            num = atoi(line); 
            ptr[lines] = num;
            lines++;
        } // End of the while //
    } // End of if // 
    
    // Copy from ptr1 into ptr2  
    for (int j = 0; j < lines; j++)  {
    } // End of the for //

    int brute_exp = lines * lines; 
    int len = ARRAY_SIZE(ptr); 
    printf("Quick Sorting, count=%d len=%d", lines, len);
    sort(0, lines-1, ptr);
    int i = 0;
    printf("\n\n++ Printing Sort ++\n");
    for (i = 0; i < 14; i++) {
        printf("i:%d %d\n", i, ptr[i]);
    } // End of the for //
    printf("...\n");
    printf("! Number of swaps : %d , sort/calls : %d , parti/calls : %d , brute=%d ops=%d\n", swaps, calls, part_calls, brute_exp, brute_ops);
    free(ptr);
    free(ptr2);
    fclose(fp);
} // End of function //
