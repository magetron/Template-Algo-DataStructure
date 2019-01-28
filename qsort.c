#include "stdio.h"
#include "stdlib.h"

void swap (int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int partition (int *arr, int low, int high) {
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j < high; j++) 
		if (arr[j] <= pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	swap(&arr[i + 1], &arr[high]);
	return i + 1;
}

void pqsort (int *arr, int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		pqsort(arr, low, pi - 1);
		pqsort(arr, pi + 1, high);
	}
}

int *init_arr (int arr_len) {
	int *new_arr = malloc(sizeof(int) * arr_len);
	for (int i = 0; i < arr_len; i++) scanf("%d", &new_arr[i]);
	return new_arr;
}

void print_arr (int *arr, int arr_len) {
	for (int i = 0; i < arr_len; i++) printf("%d ", arr[i]);
	printf("\n");
}

int main () {
	int arr_len;
	scanf("%d", &arr_len);
	int *arr = init_arr(arr_len);
	pqsort(arr, 0, arr_len - 1);
	print_arr(arr, arr_len);
}

