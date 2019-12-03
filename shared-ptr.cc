#include<bits/stdc++.h>

using namespace std;


template<typename T>
class s_ptr {
public:
	T* ptr;
	int* ref_count;

	s_ptr () : ptr(nullptr), ref_count(nullptr) { }

	s_ptr (T* p) : ptr(p) {
		ref_count = new int(1);
		cout << "Created smart_ptr, ref_count = " << *ref_count << endl;
	}

	s_ptr (const s_ptr& sp) : ptr(sp.ptr), ref_count(sp.ref_count) {
		(*ref_count)++;
		cout<< "Copied smart_ptr, ref_count = " << *ref_count << endl;
	}

	~s_ptr () {
		if (ref_count) {
			(*ref_count)--;
			cout << "Deconstructed smart_ptr, ref_count = " << *ref_count << endl;
			if (*ref_count == 0) {
				delete ptr;
				delete ref_count;

				ptr = nullptr;
				ref_count = nullptr;
			}
		}
	}

	s_ptr<T>& operator = (const s_ptr<T>& sp) {
		if (this != &sp) {
			if (ref_count && --(*ref_count) == 0) {
				delete ptr;
				delete ref_count;
			}
			ptr = sp.ptr;
			ref_count = sp.ref_count;
			(*ref_count)++;
		}
		cout << "Assigned smart_ptr, ref_count = " << *ref_count << endl;
		return *this;
	}

	T& operator *() {
		return *ptr;
	}

	T* operator ->() {
		return ptr;
	}
};

int main () {
	s_ptr<int> sp(new int(5));
	cout << *sp << endl;
	s_ptr<int> sp1;
	sp1 = sp;
	cout << *sp << " " << *sp1 << endl;
	return 0;
}




