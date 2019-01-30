#include "stdio.h"
#include "stdlib.h"

// max binary heap
//		16
// 	14		11
// 5	     3	     7	 	4


void swap (int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void *swim (int *arr, int loc, int size) {
	while (loc > 0) {
		if (arr[loc / 2] < arr[loc]) swap(&arr[loc / 2], &arr[loc]);
		else break;
	}
}

void *sink (int *arr, int loc, int size) {
	while (loc < size - 1) {
		if (arr[loc * 2] > arr[loc]) swap(&arr[loc * 2], &arr[loc]);
		else if (arr[loc * 2 + 1] > arr[loc]) swap(&arr[loc * 2 + 1], &arr[loc]);
		else break;
	}
}

void print_heap(int *arr, int size) {
	for (int i = 0; i < size - 1; i++) printf("%d ", arr[i]);
}

int *init_heap (int size) {
	int *arr = malloc(sizeof(int) * size);
	return arr;
}

int main () {
	int size;
	scanf("%d", &size);
	int heap = init_heap(size);
	for (int i = 0; i < size; i++) {
		int new_element;
		scanf("%d", &new_element);


	
