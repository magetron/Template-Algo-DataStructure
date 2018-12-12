#include "stdio.h"
#define max_arr_length 100

void merge (int arr[], int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int tmp_left[n1];
	int tmp_right[n2];
	for (int i = 0; i < n1; i++) tmp_left[i] = arr[l + i];
	for (int i = 0; i < n2; i++) tmp_right[i] = arr[m + 1 + i];	
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (tmp_left[i] <= tmp_right[j]) {
			arr[k] = tmp_left[i];
			i++;
		} else {
			arr[k] = tmp_right[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = tmp_left[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = tmp_right[j];
		j++;
		k++;
	}
	return;
}

void mergesort(int arr[], int l, int r) {
	if (l < r) {
		int m = (r + l) / 2;
		mergesort(arr, l, m);
		mergesort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
	return;
}

int arr[max_arr_length];

int main () {
	freopen("mergesort.in", "r", stdin);
	freopen("mergesort.ans", "w", stdout);
	int loc = 0;
	int n;
	do {
		scanf("%d", &n);
		if (n != -1) {
			arr[loc] = n;
			loc++;
		}
	} while (n != -1);
	for (int i = 0; i < loc; i++) printf("%d ", arr[i]);
	mergesort(arr, 0, loc - 1);
	printf("\n");
	for (int i = 0; i < loc; i++) printf("%d ", arr[i]);
	return 0;
	fclose(stdin);
	fclose(stdout);
}

