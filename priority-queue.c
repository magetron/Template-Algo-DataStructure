#include "stdio.h"
#include "stdlib.h"

// max at the top of the heap

int swim (int *heap, int loc, int size) {
	int cur = loc;
	while (heap[cur] > heap[cur / 2] && cur > 1) {
		swap(&heap[cur], &heap[cur / 2]);
		cur /= 2;
	}
}

int sink (int *heap, int size) {
	
}

int main () {
	return 0;
}


