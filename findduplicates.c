#include "stdio.h"
#include "string.h"
#include "math.h"
#define array_length 100

int arr1[array_length];
int arr2[array_length];
int arr1_size = 0;
int arr2_size = 0;

int init () {
	int tmp;
	scanf("%d", &arr1_size);
	for (int i = 0; i < arr1_size; i++) scanf("%d", &arr1[i]);
	scanf("%d", &arr2_size);
	for (int i = 0; i < arr2_size; i++) scanf("%d", &arr2[i]);
	return 0;
}

// Arr1 size = Arr2 size O(arr1_size + arr2_size)

int find_duplicates () {
	int i = 0;
	int j = 0;
	while (i < arr1_size && j < arr2_size) {
		if (arr1[i] > arr2[j]) j++;
		else if (arr1[i] < arr2[j]) i++;
		else {
			printf("%d ",arr1[i]);
			i++;
			j++;
		}
		//printf("i = %d %d\n", i, arr1[i]);
		//printf("j = %d %d\n", j, arr2[j]);
	}
	return 0;
}

// Arr1 >>>>>>>> Arr2 size O(arr1_size * lg arr2_size)

int binary_search (int start, int end, int num);

int find_duplicates () {
	for (int i = 0; i < arr1_size; i++) if (binary_search(0, arr2_size, arr1[i])) printf("%d ",arr1[i]);
	return 0;
}


int binary_search (int start, int end, int num){
	//printf("%d %d\n", start, end);
	if (start <= end) {
		int mid = round((start + end) / 2.0);
		if (arr2[mid] == num) return 1;
		else if (arr2[mid] > num) return binary_search(start, mid - 1, num);
		else if (arr2[mid] < num) return binary_search(mid + 1, end, num);
	} else return 0;
}

int main () {
	init();
	find_duplicates();
	return 0;
}

