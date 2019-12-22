#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

void hello (int n) {
	cout << "Hello World!" << n << endl;
}

class Fctor {
	public:
		void operator ()(string& msg) {
			cout << "from t0 : " << msg << endl;
			msg = "Ha changed in t0";
		}
};

int main1 () {
	string s = "Hello World!";

	thread t0((Fctor()), ref(s)); // start running t1
	
	//t0.join(); // main thread waits for t1 to finish
	//t0.detach(); // t1 runs freely on its own -- daemon process
	
	//if (t0.joinable()) t0.join(); // check joinable, once detached, always detached

	t0.join();

	cout << "from main : " << s << endl;
	
	cout << this_thread::get_id() << endl;

	cout << t0.get_id() << endl;

	cout << thread::hardware_concurrency() << endl;

	return 0;
}

mutex mu;

inline void shared_print (string msg, int id) {
	mu.lock();
	cout << msg << id << endl;
	mu.unlock();
}


void func1 () {
	for (int i = 0; i > -100; i--)
		shared_print(string("From t1: "), i);		
}

int main () {
	thread t1(func1);

	for (int i = 0; i < 100; i++)
		shared_print(string("From main: "), i);	

	t1.join();

	return 0;
}

/*
 *
 * two ways to do things concurrently
 * 1. multi-processing
 * 2. multi-threading
 *
 * why multi threading ??
 *  * fast to start
 *  * low management performance cost (overhead)
 * 	* shared memory communication is faster 
 * BUT..
 * 	* difficult to implement (issues to be carefully handled)
 * 	* cannot run distributed systems 
 * 		(one way to improve is that comm thru certain channel)
 * 
 * Over-subscription
 * use std::thread::hardware_concurrency()
 */
