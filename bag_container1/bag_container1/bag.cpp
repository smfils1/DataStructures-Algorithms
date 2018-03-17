#include"bag.h"

bool bag::insert(int value)
{
	if (used < CAPACITY) {
		data[used++] = value;
		return true;
	}
	return false;
}

bool bag::remove(int value)
{
	for (size_t i = 0; i < used; i++) {
		if (data[i] == value) {
			data[i] = data[--used];
			return true;
		}
	}
	return false;
}

bool bag::linear_search(int value) const
{
	for (size_t i = 0; i < used; i++) {
		if (data[i] == value) {
			return true;
		}
	}
	return false;
}
