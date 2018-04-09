//#include<stdlib.h>
#include"bag1.h"
#include<cassert>


using namespace std;
namespace sfils_csc212 {

	void bag1::insert(int value)	{
		assert(used < CAPACITY);
		data[used++] = value;			
	}

	void bag1::remove_one(int value)	{
		for (size_t i = 0; i < used; i++) {
			if (data[i] == value) {
				data[i] = data[--used];
				return;
			}
		}		
	}

	bool bag1::linear_search(int value) const {
		for (size_t i = 0; i < used; i++) {
			if (data[i] == value) {
				return true;
			}
		}
		return false;
	}

	size_t bag1::size() const {
	return used;
	}

	bag1 operator+(const bag1 &bag_1, const bag1 &bag_2) {
		assert((bag_1.size() + bag_2.size()) <= bag1::CAPACITY);
		bag1 bag_3;
		if (bag_1.size() < bag_2.size()) {
			bag_3 = bag_2;
			for (size_t i = 0; i < bag_1.size(); i++) {
				bag_3.insert(bag_1.data[i]);
			}
		}
		else {
			bag_3 = bag_1;
			for (size_t i = 0; i < bag_2.size(); i++) {
				bag_3.insert(bag_2.data[i]);
			}
		}
		return bag_3;
	}

	bool operator==(const bag1 &bag_1, const bag1 &bag_2) {
		if (bag_1.size() != bag_1.size()) {
			return false;
		}
		else {
			for (size_t i = 0; i < bag_1.size(); i++) {
				if (bag_1.data[i] != bag_2.data[i]) {
					return false;
				}
			}
			return true;
		}
	}

	ostream& operator<<(ostream &out, const bag1 &bag_1) {
		
		for (size_t i = 0; i < bag_1.size(); i++) {
			out << bag_1.data[i] << " ";
		}
		out << endl;
		return out;
	
	}

	void bag1::print() const {
		for (size_t i = 0; i < this->size(); i++) {
			cout << data[i] << " ";
		}
		cout << endl;
	
	}

}


