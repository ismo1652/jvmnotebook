//////////////////////////////////////////////////////////////////////
// Insert Sort
/////////////////////
// Berlin Brown
//
//////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void insert_sort(int a[], int array_size) {
	
	int i, j, current;	
	for (i=1; i < array_size; i++) {		
		current = a[i];
		j = i;
		while ((j > 0) && (a[j-1] > current)) {					   
			a[j] = a[j-1];
			j = j - 1;
		}
		a[j] = current;
	}

} // End of Function


int main(const int argc, const char *argv[]) {
	int i = 0;
	int arr [] = { 2, 3, 4, 1, 3, 6, 29, 2, 3, 7 };
	printf("Running insert sort example\n");
	insert_sort(arr, 10);
	
	for (i = 0; i < 10; i++) {
		printf(" index%d: %d\n", i, arr[i]);
	}
	printf("Done\n");

	return 0;
}

// End of File
