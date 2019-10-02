#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();


class Trie {
public:
	struct Node {
		char c;
		vector<Node *> chs;
        bool end;
		Node (char ch) : c(ch), end(false) { }
	};

	Node* root;

    Trie() {
		root = new Node('@');		
    }

    void insert(string word) {
		Node* r = root;
		for (auto c : word) {
			bool found = false;
			for (auto ch : r -> chs) if (ch -> c == c) {
				r = ch;
				found = true;
				break;
			}
			if (!found) {
				Node *new_ch = new Node(c);
				r -> chs.push_back(new_ch);
				r = new_ch;
			}
		}
        r -> end = true;
    }

    bool search(string word) {
		Node* r = root;
		for (auto c : word) {
			bool found = false;
			for (auto ch : r -> chs) if (ch -> c == c) {
				r = ch;
				found = true;
				break;
			}
			if (!found) return false;
		}
		return r -> end;
    }

    bool startsWith(string prefix) {
		Node* r = root;
		for (auto c : prefix) {
			bool found = false;
			for (auto ch : r -> chs) if (ch -> c == c) {
				r = ch;
				found = true;
				break;
			}
			if (!found) return false;
		}
		return true;
    }
};


