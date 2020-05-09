#include<bits/stdc++.h>

using namespace std;


int main () {
	vector<int> arr{153, 268, 111, 943, 792, 668, 813, 571, 789, 1017, 658, 10912, 743};

	vector<vector<int>> buckets(10, vector<int>(0));

	int max = -1;
	for (int a : arr) if (a > max) max = a;
	int max_d = 0;
	if (max == 0) max_d = 1; else {
		while (max) {
			max_d += 1;
			max /= 10;
		}
	}

	int target = 1;
	while (max_d) {
		target *= 10;
		max_d--;
	}

	
	int i = 10;
	int j = 1;

	while (i <= target) {
		for (int a : arr) {
			int cur_d = a % i / j;
			buckets[cur_d].push_back(a);
		}

		arr.clear();

		for (int k = 0; k < 10; k++) {
			for (int bk : buckets[k]) arr.push_back(bk);
			buckets[k].clear();
		}

		//debug
		for (int a : arr) cout << a << " "; cout << endl;

		i *= 10;
		j *= 10;
	}

	cout << "final : " << endl;
	for (int a : arr) cout << a << " "; cout << endl;

	return 0;
}

