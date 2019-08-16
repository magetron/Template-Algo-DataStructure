#include <iostream>
#include <thread>

using namespace std;

void print_hello (int n) {
	cout << "Hello World!" << n << endl;
}

int main () {
	thread t0(print_hello, 0);
	thread t1(print_hello, 1);
	thread t2(print_hello, 2);

	t2.join();
	t1.join();
	t0.join();

	return 0;
}
