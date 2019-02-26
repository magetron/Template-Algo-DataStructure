#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "limits.h"

void swap (int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void heapify (int *arr, int current, int arr_len) {
	int max = current;
	int l = 2 * current + 1;
	int r = 2 * current + 2;
	if ( (l < arr_len) && (arr[l] > arr[max]) ) max = l;
	if ( (r < arr_len) && (arr[r] > arr[max]) ) max = r;
	if (max != current) {
		swap(&arr[current], &arr[max]);
		heapify(arr, max, arr_len);
	}
}

void build_heap (int *arr, int arr_len) {
	for (int i = arr_len / 2 - 1; i >= 0; i--) heapify(arr, i, arr_len);
}

void heap_sort (int *arr, int size) {
	build_heap(arr, size);
	for (int i = size - 1; i >= 0; i--) {
		swap(&arr[0], &arr[i]);
		heapify(arr, 0, i);
	}
}

int main () {
	int arr_len;
	scanf("%d", &arr_len);
	int *arr = malloc(sizeof(int) * arr_len);
	srand(time(NULL));
	for (int i = 0; i < arr_len; i++) {
		arr[i] = rand() % INT_MAX;
		printf("%d ", arr[i]);
	}
	printf("\n");
	clock_t begin = clock();
	heap_sort(arr, arr_len);
	clock_t end = clock();
	double time_spent = (double)(end - begin) * 1000 / CLOCKS_PER_SEC;
	for (int i = 0; i < arr_len; i++) printf("%d ", arr[i]);
	printf("\n time = %lf\n", time_spent);
	return 0;
}


