#include<bits/stdc++.h>
#define MAX_LENGTH 2000005
using namespace std;

vector<int> build_lps (string& p) {
	vector<int> lps(p.length());
	int i = 0;
	int j = 1;
	while (j < p.length()) {
		if (p.at(i) == p.at(j)) {
			lps[j] = lps[j - 1] + 1;
			i++;
		}
		j++;
	}
	return lps;
}

void kmp (string& s, string& p, vector<int>& lps, vector<int>& ans) {
	int i = 0;
	int j = 0;
	while (i < s.length()) {
		//cout << i << endl;
		while (i < s.length() && j < p.length() && s.at(i) == p.at(j)) {
			i++; j++;
		}
		if (j == p.length()) ans.push_back(i - p.length() + 1);
		if (j != 0) j = lps[j - 1]; else i++;
	}
}

void match (string& s, string& p) {
	vector<int> lps = build_lps(p);
	vector<int> ans;
	kmp(s, p, lps, ans);
	if (ans.size() != 0) {
		cout << ans.size() << endl;
		for (auto it = ans.begin(); it != ans.end(); it++) cout << *it << " ";
		cout << endl << endl;
	} else {
		cout << "Not Found" << endl;
		cout << endl;
	}
}

int main () {
	string s("abxababxabc");
	string p("abxabc");
	match(s, p);
	return 0;
}
