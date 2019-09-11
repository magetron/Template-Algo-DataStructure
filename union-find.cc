#include<bits/stdc++.h>

using namespace std;

class UnionFind {
	public:
		UnionFind (int n) {
			pre = vector<int>(n);
			for (int i = 0; i < n; i++) pre[i] = i;
		}

		int find (int x) {
			int r = x;
			while (pre[r] != r) r = pre[r];
			int i = x, j;
			while (i != r) {
				j = pre[i];
				pre[i] = r;
				i = j;
			}
			return r;
		}

		void join (int x, int y) {
			int fx = find(x); int fy = find(y);
			if (fx != fy) pre[fx] = fy;
		}

		bool query (int x, int y) {
			return find(x) == find(y);
		}

	private:
		vector<int> pre;
};

int main () {
	UnionFind uf(5);
	uf.join(1, 2);
	uf.join(2, 4);
	uf.join(0, 3);
	cout << uf.query(1, 4) << " " << uf.query(1, 0) << endl;
	return 0;
}

