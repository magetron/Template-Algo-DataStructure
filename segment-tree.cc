#include <bits/stdc++.h>

using namespace std;

int rec_get_sum (int *segment_tree, int slow, int shigh, int low, int high, int cur) {
	//cout << cur << " " << slow << " " << shigh << endl;
	if (low <= slow && shigh <= high) return segment_tree[cur];
	else if (slow > high || shigh < low) return 0;
	
	int mid = (slow + shigh) / 2;
	return rec_get_sum(segment_tree, slow, mid, low, high, cur * 2) +
			rec_get_sum(segment_tree, mid + 1, shigh, low, high, cur * 2 + 1);
}

int get_sum (int *segment_tree, int size, int low, int high) {
	if (low < 0 || high > size - 1 || low > high) return -1;
	else return rec_get_sum(segment_tree, 0, size - 1, low, high, 1);
}

void rec_update (int *segment_tree, int low, int high, int i, int diff, int cur) {
	if (i < low || i > high) return;
	segment_tree[cur] += diff;
	if (low != high) {
		int mid = (low + high) / 2;
		rec_update(segment_tree, low, mid, i, diff, cur * 2);
		rec_update(segment_tree, mid + 1, high, i, diff, cur * 2 + 1);
	}
}


void update (int *arr, int *segment_tree, int n, int i, int new_val) {
	if (i < 0 || i > n - 1) return;
	int diff = new_val - arr[i];
	arr[i] = new_val;
	rec_update(segment_tree, 0, n - 1, i, diff, 1);
}

int rec_construct (int *arr, int low, int high, int *segment_tree, int cur) {
	// leaf
	if (low == high) {
		segment_tree[cur] = arr[low];
		//cout << cur << " " << arr[low] << endl;
		return arr[low];
	}

	// upper nodes
	int mid = (low + high) / 2;
	segment_tree[cur] = 
		rec_construct(arr, low, mid, segment_tree, cur * 2) + 
		rec_construct(arr, mid + 1, high, segment_tree, cur * 2 + 1);
	//cout << cur << " " << segment_tree[cur];
	return segment_tree[cur];
}


int *construct (int *arr, int n) {
	int height = (int)(ceil(log2(n)));
	int max_size = 2 * (int)pow(2, height) - 1;
	int *segment_tree = new int[max_size + 1];
	memset(segment_tree, 0, max_size * sizeof(int));
	rec_construct(arr, 0, n - 1, segment_tree, 1);
	//for (int i = 1; i <= max_size; i++) printf("%d ", segment_tree[i]);
	return segment_tree;
}

int main () {
	//freopen("segment-tree.ans", "w", stdout);
	int n = 6;
	int *arr = new int[n];
	arr[0] = 1;
	arr[1] = 3;
	arr[2] = 5;
	arr[3] = 7;
	arr[4] = 9;
	arr[5] = 11;
	int *segment_tree = construct(arr, n);
	cout << get_sum(segment_tree, n, 3, 5) << endl;
	update(arr, segment_tree, n, 3, 100);
	cout << get_sum(segment_tree, n, 3, 4) << endl;
	//fclose(stdout);
	return 0;
}
