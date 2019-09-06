#include <bits/stdc++.h>

using namespace std;

class Bit {
	vector<int> bit1;
	vector<int> bit2;
	private:
		void __update(vector<int>&bit, int i, int val) {
			while (i < bit.size()) {
				bit[i] += val;
				i += (i & (-i));
			}
		}

		int __get_sum(vector<int>&bit, int i) {
			int ans = 0;
			while (i > 0) {
				ans += bit[i];
				i -= (i & (-i));
			}
			return ans;
		}
	
	public:
		Bit (int n) {
			bit1 = vector<int>(n + 1, 0);
			bit2 = vector<int>(n + 1, 0);
		}

		void update (int l, int r, int val) {
			__update(bit1, l, val);
			__update(bit1, r + 1, -val);
			__update(bit2, l, val * (l - 1));
			__update(bit2, r + 1, -val * r);
		}
		
		int get_sum (int l, int r) {
			return (__get_sum(bit1, r) * r - __get_sum(bit2, r)) - (__get_sum(bit1, (l - 1)) * (l - 1) - __get_sum(bit2, l - 1));
		}

};


int main () {
	int n = 50;
	Bit bit(n);
	// 1..n
	bit.update(1, 50, 100);
	bit.update(1, 25, 200);
	bit.update(26, 50, 100);
	cout << bit.get_sum(1, 3) << endl;
	cout << bit.get_sum(26, 27) << endl;
	return 0;
}
	

