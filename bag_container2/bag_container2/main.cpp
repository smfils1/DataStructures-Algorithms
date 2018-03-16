#include<iostream>
using namespace std;

// This bag data structure has a search time of O(lg n), and a insert/remove time of O(n).

class bag {

public:
	static const size_t CAPACITY = 10;
	bool insert(int value) {
		if (used < CAPACITY) {
			if (used == 0) {
				data[used++] = value;
			}
			else {
				used++;
				size_t index = insert_position(value);
				shift_elements_right(index);
				data[index] = value;
			}
			return true;
		}
		return false;
	}

	bool remove(int value) {
		int index = find_position(value);
		if (used > 0 && index != -1) {
			shift_elements_left(index);
			used--;
			return true;
		}
		return false;
	}

	bool binary_search(int value) const {		
		size_t start = 0;
		size_t end = used - 1 ;		
		while (start <= end) {
			size_t mid = (end + start) / 2;
			if (data[mid] == value) {
				return true;
			}
			else if (data[mid] < value) {
				start = mid + 1;
			}
			else {
				end = mid - 1;
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

	size_t insert_position(int value) {
		for (size_t i = 0; i < used; i++) {
			if (value < data[i]) {
				return i;
			}
		}
		return used - 1;
	}

	void shift_elements_right(size_t index) {
		if (index < used - 1) {
			for (size_t i = used - 1; i > index; i--) {
				data[i] = data[i - 1];
			}
		}
	}


	int find_position(int value) {
		for (int i = 0; i < used; i++) {
			if (data[i] == value) {
				return i;
			}
		}
		return -1;
	}

	void shift_elements_left(int index) {
		for (size_t i = index; i < used - 1; i++) {
			data[i] = data[i + 1];
		}
	}
};

int main() {
	bag a;
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);
	a.remove(1);
	cout<<a.size();
	

	system("pause");
	return 0;
}