#include<iostream>
using namespace std;

//The bag data structure is a data structure for storing the data in an unordered list.
//For the bag data structure, the insert function takes O(1), the remove function takes O(1)and 
//the search function take O(n).


class bag {

public:
	static const size_t CAPACITY = 20;

	bool insert(int value) {
		if (used < CAPACITY) {
			data[used++] = value;
			return true;
		}
		return false;
	}

	bool remove(int value) {
		for (size_t i = 0; i < used; i++) {
			if (data[i] == value) {
				data[i] = data[--used];
				return true;
			}

		}
		return false;
	}

	bool linear_search(int value) const {
		for (size_t i = 0; i < used; i++) {
			if (data[i] == value) {
				return true;
			}
		}
		return false;

	}

	size_t size() {
		return used;
	}

private:
	int data[CAPACITY];
	size_t used = 0;
};


int main() {
	bag a;
	cout << a.insert(1);
	system("pause");
	return 0;
}