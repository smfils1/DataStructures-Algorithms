#include "dbag.h"
#include<cassert>


namespace sfils_csc212 {

	dbag::dbag(size_t capacity) {
		data = new int[capacity];
		dbag::capacity = capacity;
		used = 0;
	}

	void dbag::operator=(const dbag & source) {
		if (this == &source) {
			return;
		}
		int *new_data = nullptr;
		used = source.used;
		if (capacity != source.capacity) {
			capacity = source.capacity;
			new_data = new int[capacity];
			copy_data(new_data, source);
		}
		else {
			copy_data(new_data, source);
		}
	}

	dbag::dbag(const dbag & source) {
		if (this == &source) {
			return;
		}
		int *new_data = nullptr;
		used = source.used;
		if (capacity != source.capacity) {
			capacity = source.capacity;
			new_data = new int[capacity];
			copy_data(new_data, source);
		}
		else {
			copy_data(new_data, source);
		}
	}

	dbag::~dbag() {
		delete[] data;
	}

	void dbag::copy_data(int * new_data, const dbag & source) {
		for (size_t i = 0; i < used; i++) {
			*(data + i) = *(source.data + i);
		}
		delete[] data;
		data = new_data;

	}

	void dbag::insert(int value) {
		assert(used < capacity
		);
		data[used++] = value;

	}

	void dbag::remove_one(int value) {
		for (size_t i = 0; i < used; i++) {
			if (data[i] == value) {
				data[i] = data[--used];
				return;
			}
		}
	}

	bool dbag::linear_search(int value) const {
		for (size_t i = 0; i < used; i++) {
			if (data[i] == value) {
				return true;
			}
		}
		return false;
	}

	size_t dbag::size() const {
		return used;
	}

	std::ostream& operator<<(std::ostream &out, const dbag &bag) {
		for (size_t i = 0; i < bag.size(); i++) {
			out << bag.data[i] << " ";
		}
		out << std::endl;
		return out;
	}
}

