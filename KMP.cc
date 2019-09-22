#include<bits/stdc++.h>
#define MAX_LENGTH 2000005
using namespace std;


vector<int> build_lps (string& p) {
	vector<int> lps(p.length());
	int i = 0;
	lps[0] = 0;
	int j = 1;
	while (j < p.length()) {
		if (p.at(j) == p.at(i)) {
			i++;
			lps[j] = i;
			j++;
		} else if (i != 0) i = lps[i - 1];
		else {
			lps[j] = 0;
			j++;
		}
	}
	return lps;
}

void kmp (string& s, string& p) {
	vector<int> lps = build_lps(p);
	int i = 0;
	int j = 0;
	while (i < s.length()) {
		while (i < s.length() && j < p.length() && s[i] == p[j]) { i++; j++; }
		if (j == p.length()) cout << i - p.length() << endl;
		if (j != 0) j = lps[j - 1]; else i = i + 1;
	}
}


int main () {
	string s("hello");
	string p("ll");
	kmp(s, p);
	return 0;
}
