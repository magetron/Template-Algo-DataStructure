#include <bits/stdc++.h>

using namespace std;

int get_sum (vector<int>& bit, int i) {
	i++;
	int ret = 0;
	while (i > 0) {
		ret += bit[i];
		i -= (i & (- i));
	}
	return ret;
}


void update (vector<int>& bit, int i, int val) {
	i++;
	while (i <= bit.size()) {
		bit[i] += val;
		i += (i & (- i));
	}
}

vector<int> construct (vector<int>& arr) {
	int n = arr.size();
	vector<int> bit(n + 1, 0);
	for (auto it = arr.begin(); it != arr.end(); it++) update(bit, it - arr.begin(), *it);
	return bit;
}

int main () {
	vector<int> arr{ 2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> bit = construct(arr);
	cout << get_sum(bit, 5) << endl;
	int diff = 3;
	update(bit, 3, diff);
	cout << get_sum(bit, 5) << endl;
	return 0;
}
