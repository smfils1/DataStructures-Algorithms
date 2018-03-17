#pragma once

namespace sfils_csc212 {
	class bag1 {

	public:
		static const size_t CAPACITY = 10;
		bool insert(int value);
		bool remove(int value);
		bool linear_search(int value) const;
		size_t size() const {
			return used;
		}

	private:
		int data[CAPACITY];
		size_t used = 0;
	};
}


