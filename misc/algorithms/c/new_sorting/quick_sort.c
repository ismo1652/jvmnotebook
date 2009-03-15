//

void quick_sort(int a[], int l, int r) {
	
   int j;   
   if (l < r) { 
	   
	   j = partition( a, l, r);
       quick_sort( a, l, j-1);
       quick_sort( a, j+1, r);
   }
   
}

int partition( int a[], int l, int r) {
	
	int pivot, i, j, t;
	pivot = a[l];
	i = l; j = r+1;
	
	while (1) {
	   
		do ++i; while( a[i] <= pivot && i <= r );
		do --j; while( a[j] > pivot );
		if( i >= j ) break;
		t = a[i]; a[i] = a[j]; a[j] = t;
	}
	t = a[l]; a[l] = a[j]; a[j] = t;
	return j;
}

//////////////////////////////////////////////////////////////////////


int main(const int argc, const char *argv[]) {

	int i = 0;
	int arr [] = { 2, 3, 4, 1, 3, 6, 29, 2, 3, 7 };
	printf("Running quick sort example\n");
	quick_sort(arr, 0, 9);
	
	for (i = 0; i < 10; i++) {
		printf(" index%d: %d\n", i, arr[i]);
	}
	
	printf("Done\n");
	
	return 0;
}
