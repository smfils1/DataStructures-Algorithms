#include"bag1.h"

namespace sfils_csc212 {

	bool bag1::insert(int value)	{
		if (used < CAPACITY) {
			data[used++] = value;
			return true;
		}
		return false;
	}

	bool bag1::remove(int value)	{
		for (size_t i = 0; i < used; i++) {
			if (data[i] == value) {
				data[i] = data[--used];
				return true;
			}
		}
		return false;
	}

	bool bag1::linear_search(int value) const {
		for (size_t i = 0; i < used; i++) {
			if (data[i] == value) {
				return true;
			}
		}
		return false;
	}
}


