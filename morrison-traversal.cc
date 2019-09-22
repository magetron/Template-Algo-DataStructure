#include <bits/stdc++.h>

using namespace std;

struct node {
	int val;
	node* left, *right;
	node (int v) : val(v), left(nullptr), right(nullptr) { }
};

void traverse (node* root) {
	node* cur = root;
	while (cur) 
		if (!cur -> left) {
			cout << cur -> val << " ";
			cur = cur -> right;
		} else {
			node* l = cur -> left;
			while (l -> right && l -> right != cur) l = l -> right;
			if (!l -> right) {
				l -> right = cur;
				cur = cur -> left;
			} else {
				l -> right = nullptr;
				cout << cur -> val << " ";
				cur = cur -> right;
			}
		}
}

int main () {
	node* root = new node(2);
	node* l1 = new node(1);
	node* r1 = new node(4);
	node* r2 = new node(3);
	root -> left = l1;
	root -> right = r1;
	r1 -> left = r2;
	traverse(root);
	return 0;
}
