#include "stdio.h"
#include "stdlib.h"

void swap (int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void swim (int *arr, int loc, int size) {
	while (loc > 0) {
		if (arr[loc / 2] < arr[loc]) {
			swap(&arr[loc / 2], &arr[loc]);
			loc = loc / 2;
		} else break;
	}
}

void sink (int *arr, int loc, int size) {
	while (loc <=  (size - 1) / 2) {
		int greater = loc * 2 + 1;
		if (arr[loc * 2] > arr[loc * 2 + 1]) greater = loc * 2;
		if (arr[greater] > arr[loc]) {
			swap(&arr[greater], &arr[loc]);
			loc = greater;
		} else break;
	}
}

void print_heap(int *arr, int size) {
	for (int i = 0; i < size; i++) printf("%d ", arr[i]);
	printf("\n");
}

int *init_heap (int size) {
	int *arr = malloc(sizeof(int) * size);
	return arr;
}

int main () {
	//freopen("binaryheap.in", "r", stdin); 
	int max_size;
	printf("Max Heap Size = ");
	scanf("%d", &max_size);
	int *arr = init_heap(max_size);
	int size = 0;
	short int op = -1;
	while (op != 4) {
		printf("1. add new element to the heap\n");
		printf("2. pop from top of the heap\n");
		printf("3. print heap\n");
		printf("4. exit\n");
		scanf("%hd", &op);
		int new_element;
		switch(op) {
			case 1 : scanf("%d", &new_element);
				 if (size + 1 > max_size) {
					 printf("ERROR : Segmentfault\n");
					 break;
				 } else {
					 size++;
					 arr[size - 1] = new_element;
					 swim(arr, size - 1, size);
				 }
				 break;
			case 2 : if (size - 1 < 0) printf("ERROR : Segmentfault\n");
				 else {
					printf("pop = %d\n", arr[0]);
				 	arr[0] = arr[size - 1];
				 	size--;
				 	sink(arr, 0, size);
				 }
				 break;
			case 3 : print_heap(arr, size);
				 break;
		}
	}
	//fclose(stdin);
	return 0;
}
