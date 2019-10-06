#include <bits/stdc++.h>

using namespace std;

class BIT {
	public:
		vector<int> bit;

		BIT (int n) : bit(vector<int>(n + 1, 0)) { };

		void update (int pos, int diff) {
			pos++;
			while (pos < bit.size()) {
				bit[pos] += diff;
				pos += (pos & (- pos));
			}
		}

		int get (int pos) {
			pos++;
			int ans = 0;
			while (pos > 0) { 
				ans += bit[pos] ;
				pos -= (pos & (- pos));
			}
			return ans;
		}

		void print () {
			for (int i = 1; i < bit.size(); i++) cout << bit[i] << " ";
			cout << endl;
		}
};

class RangeBIT {
	public:
		BIT bit1;
		BIT bit2;
		
		RangeBIT (int n) : bit1(BIT(n)), bit2(BIT(n)) { }

		void update (int l_pos, int r_pos, int diff) {
			l_pos--;
			r_pos--;
			bit1.update(l_pos, diff);
			bit1.update(r_pos + 1, -diff);
			bit2.update(l_pos, - diff * (l_pos - 1));
			bit2.update(r_pos + 1, diff * r_pos);
		}
		
		int sum (int pos) {
			return bit1.get(pos) * pos + bit2.get(pos);
		}

		int query (int l_pos, int r_pos) {			
			return sum(r_pos) - sum(l_pos - 1);
		}
};
