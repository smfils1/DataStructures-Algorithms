#pragma once
#include<iostream>

namespace sfils_csc212 {
	class bag1 {

	public:
		static const size_t CAPACITY = 10;
		void insert(int value);
		//Precondition: Bag not full
		//Postcondition: Insert value to bag
		void remove_one(int value);
		//Postcondition: Will remove one  occurrence of value if found
		bool linear_search(int value) const;
		//Postcondition: Return true if value is found in bag else returns false
		size_t size() const; 
		//Postcondition:  Returns the size of the bag
		
		friend bag1 operator+(const bag1 &bag_1, const bag1 &bag_2);
		friend bool operator==(const bag1 &bag_1, const bag1 &bag_2);
		friend std::ostream& operator<<(std::ostream &out, const bag1 &bag_1);



		void print() const;
	private:
		int data[CAPACITY];
		size_t used = 0;
	};

	bag1 operator+(const bag1 &bag_1, const bag1 &bag_2);
	//Precondition: Bag1 size plus Bag2 size must not exceed capacity
	//Postcondition: Returns a bag that is the union of both  bag1 & bag2
	bool operator==(const bag1 &bag_1, const bag1 &bag_2) ;
	//Postcondition: Returns true if  bag1 is equal to bag2 else false
	std::ostream& operator<<(std::ostream &out, const bag1 &bag_1);
	//Postcondition:Overloads << to output bag

}


