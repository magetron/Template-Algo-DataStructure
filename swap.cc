#include <bits/stdc++.h>

using namespace std;

void swap (int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

int main () {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	swap(a, b);
	cout << a << " " << b << endl;
	return 0;
}
