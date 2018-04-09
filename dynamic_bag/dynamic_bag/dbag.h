#pragma once
#include<iostream>

namespace sfils_csc212 {

	class dbag {
	public:
		static const int DEFAULT_CAPACITY = 10;
		dbag(size_t capacity = DEFAULT_CAPACITY);
		dbag(const dbag& source);
		void operator=(const dbag& source);
		void insert(int value);
		//Precondition: Bag not full
		//Postcondition: Insert value to bag
		void remove_one(int value);
		//Postcondition: Will remove one  occurrence of value if found
		bool linear_search(int value) const;
		//Postcondition: Return true if value is found in bag else returns false
		size_t size() const;
		//Postcondition:  Returns the size of the bag
		friend std::ostream& operator<<(std::ostream &out, const dbag& bag);
		

		~dbag();
	private:
		int * data;
		size_t used;
		size_t capacity;
		void copy_data(int *new_data, const dbag& source);

	};

	std::ostream& operator<<(std::ostream &out, const dbag& bag);
	//Postcondition:Overloads << to output bag
}

