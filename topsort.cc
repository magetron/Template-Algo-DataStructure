#include<bits/stdc++.h>

using namespace std;


// Directed Graph
class Graph {
	public:
		vector<vector<int>> g;
		
		Graph (int n) : g(vector<vector<int>>(n, vector<int>())) { }
		
		void point (int a, int b) {
			g[a].push_back(b);
		}
	
};

void dfs(int pos, Graph& g, vector<int>& ans, vector<bool>& v) {
	for (auto c : g.g[pos]) if (!v[c]) {
		v[c] = true;
		dfs(c, g, ans, v);
		ans.push_back(c);
	}
}

vector<int> top_sort (Graph& g) {
	vector<int> ans;
	vector<bool> v(g.g.size(), false);
	for (int i = 0; i < g.g.size(); i++) if (!v[i]) {
		v[i] = true;
		dfs(i, g, ans, v);
		ans.push_back(i);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main () {
	Graph g(8);
	g.point(0,6);
	g.point(1,2);
	g.point(1,4);
	g.point(1,6);
	g.point(3,4);
	g.point(3,0);
	g.point(5,1);
	g.point(7,0);
	g.point(7,1);
	auto ans = top_sort(g);
	for (auto i : ans) cout << i << " ";
	cout << endl;
	return 0;
}
