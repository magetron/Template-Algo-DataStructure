#include "stdio.h"
#include "stdlib.h"
#define MAX_HEAP_SIZE 1024

// max at the top of the heap

void swap (int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void swim (int *heap, int loc, int size) {
	int cur = loc;
	while (heap[cur] > heap[cur / 2] && cur > 1) {
		swap(&heap[cur], &heap[cur / 2]);
		cur /= 2;
	}
}

void sink (int *heap, int loc, int size) {
	int cur = loc;
	while ((heap[cur] < heap[cur * 2] && cur * 2 <= size) || (heap[cur] < heap[cur * 2 + 1] && cur * 2 + 1 <= size)) 
		if (heap[cur] < heap[cur * 2]) {
			swap(&heap[cur], &heap[cur * 2]);
			cur *= 2;
		} else {
			swap(&heap[cur], &heap[cur * 2 + 1]);
			cur = cur * 2 + 1;
		}
}

void add (int *heap, int val, int *size) {
	heap[++*size] = val;
	swim(heap, *size, *size);
}

int pop (int *heap, int *size) {
	int num = heap[1];
	swap(&heap[*size], &heap[1]);
	*size = *size - 1;
	sink(heap, 1, *size);
	return num;
}

int main () {
	int heap[MAX_HEAP_SIZE];
	int size = 0;
	add(heap, 10, &size);
	add(heap, 8, &size);
	add(heap, 9, &size);
	add(heap, 15, &size);
	add(heap, 17, &size);
	add(heap, 3, &size);
	add(heap, 11, &size);
	for (int i = 1; i <= size; i++) printf("%d ", heap[i]); printf("\n");
	printf("%d %d\n", pop(heap, &size), pop(heap, &size));
	for (int i = 1; i <= size; i++) printf("%d ", heap[i]); printf("\n");
	printf("%d %d %d\n", pop(heap, &size), pop(heap, &size), pop(heap, &size));
	return 0;
}


