#include <bits/stdc++.h>

using namespace std;

int main () {
	bitset<32> bits;
	for (int i = 0; i < 16; i++) bits.set(i);
	cout << bits.to_ulong() << endl;
	for (int i = 0; i < 15; i++) bits.reset(i);
	cout << bits.to_ulong() << endl;
	return 0;
}
