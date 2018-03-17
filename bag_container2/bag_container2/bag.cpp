#include"bag.h"


bool bag::insert(int value)
{
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

bool bag::remove(int value)
{
	int index = find_position(value);
	if (used > 0 && index != -1) {
		shift_elements_left(index);
		used--;
		return true;
	}
	return false;
}

bool bag::binary_search(int value) const
{
	int start = 0;
	int end = int(used) - 1;
	while (start <= end) {
		int mid = (end + start) / 2;
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

size_t bag::insert_position(int value)
{
	for (size_t i = 0; i < used; i++) {
		if (value < data[i]) {
			return i;
		}
	}
	return used - 1;
}

void bag::shift_elements_right(size_t index)
{
	if (index < used - 1) {
		for (size_t i = used - 1; i > index; i--) {
			data[i] = data[i - 1];
		}
	}
}

int bag::find_position(int value)
{
	for (size_t i = 0; i < used; i++) {
		if (data[i] == value) {
			return int(i);
		}
	}
	return -1;
}

void bag::shift_elements_left(int index)
{
	for (size_t i = index; i < used - 1; i++) {
		data[i] = data[i + 1];
	}
}

