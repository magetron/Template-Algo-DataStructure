#include <bits/stdc++.h>

using namespace std;

class MinStack {
	public:
		stack<int> s1, s2;
	
		MinStack () {
			s2.push(INT_MAX);
		}

		void push (int x) {
			if (x <= s2.top()) s2.push(x);
			s1.push(x);
		}

		void pop () {
			int x = s1.top();
			s1.pop();
			if (x == s2.top()) s2.pop();
		}

		int top () {
			return s1.top();
		}

		int getMin () {
			return s2.top();
		}
};

int main () {
	MinStack st;
	st.push(1);
	st.push(-1);
	st.push(9);
	st.push(-2);
	st.push(5);
	cout << st.getMin() << " " << st.top() << endl;
	st.pop();
	cout << st.top() << endl;
	st.pop();
	cout << st.getMin() << endl;
	return 0;
}
