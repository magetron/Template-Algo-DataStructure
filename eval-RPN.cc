#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define ll long long

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Solution {
public:
	inline ll convert(string& token) {
		ll a = 0;
		if (token[0] != '-') for (char c : token) a = a * 10 + (c - 48);
		else {
			for (int i = 1; i < token.length(); i++) a = a * 10 + (token[i] - 48);
			a = -a;
		}
		return a;
	}

    inline ll evalRPN(vector<string>& tokens) {
        stack<ll> st;
		for (string token : tokens) {
			if (token == "+" || token == "-" || token == "*" || token == "/") {
				ll a = st.empty() ? 0 : st.top();
				st.pop();
				ll b = st.empty() ? 0 : st.top();
				st.pop();
				if (token == "+") st.push(b + a);
				else if (token == "-") st.push(b - a);
				else if (token == "*") st.push(b * a);
				else if (token == "/") st.push(b / a);
			} else {
				ll a = convert(token);
				st.push(a);
			}
		}
		return st.top();
    }

	inline int is_operator (char& c) {
		switch ( c ) {
			case '+' :
				return 1; break;
			case '-' :
				return 1; break;
			case '*' :
				return 2; break;
			case '/' :
				return 2; break;
			case '^' :
				return 3; break;
			default :
				return 0;
		}
	}

    int calculate(string s) {
        vector<string> rpn;
		stack<char> ops;
		ops.push('@');
		ll n = 0;
		bool num = false;
		bool req = true;
		for (char ch : s) {
			if (isdigit(ch)) {
				n = n * 10 + (ch - 48);
				num = true;
				req = false;
			} else {
				if (num) {
					rpn.push_back(to_string(n));
					n = 0;
					num = false;
				}
				if (req && is_operator(ch)) {
					rpn.push_back("0");
					req = false;
				}
				if (is_operator(ch)) {
					char top = ops.top();
					while (is_operator(top) >= is_operator(ch)) {
						rpn.push_back({top});
						ops.pop();
						top = ops.top();
					}
					ops.push(ch);
				} else if (ch == '(') {
					ops.push(ch);
					req = true;
				} else if (ch == ')') {
					while (!(ops.top() == '(')) {
						rpn.push_back({ops.top()});
						ops.pop();
					}
					ops.pop();
				}
			}
		}
		if (num) rpn.push_back(to_string(n));
		while (ops.top() != '@') {
			rpn.push_back({ops.top()});
			ops.pop();
		}
		//for (auto i : rpn) cout << i << " ";
		//cout << endl;
		return evalRPN(rpn);
    }
};

