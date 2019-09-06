#include <bits/stdc++.h>

using namespace std;

int get(vector<int>& bit, int i) {
	int ans = 0;
	while (i >= 0) {
		ans += bit[i];
		i--;
	}
	return ans;
}


void update (vector<int>& bit, int l, int r, int val) {
	bit[l] += val;
	bit[r + 1] -= val;
}

int main () {
	int n = 10;
	vector<int> bit(n, 0);	
	update(bit, 0, 4, 100);
	update(bit, 4, 9, 200);
	cout << get(bit, 5) << endl;
	return 0;
}
