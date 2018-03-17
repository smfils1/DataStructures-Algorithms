#pragma once

class bag {

public:
	static const size_t CAPACITY = 10;
	bool insert(int value);
	bool remove(int value);
	bool binary_search(int value) const;
	size_t size() {
		return used;
	}

private:
	int data[CAPACITY];
	size_t used = 0;
	size_t insert_position(int value);
	void shift_elements_right(size_t index);
	int find_position(int value);
	void shift_elements_left(int index);
};



