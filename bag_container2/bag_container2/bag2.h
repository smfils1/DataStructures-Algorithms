#ifndef BAG2_H
#define BAG2_H


namespace sfils_csc212 {
	class bag2 {

	public:
		static const size_t CAPACITY = 10;
		bag2()
		//Precondition: Bag is be sorted. 
		//Postcondition: Bag is initilized and is set empty.
		{
			used = 0;
		}
		

		bool insert(int value);
		//Precondition: Bag is be sorted. 
		//Postcondition: Value is copied to bag and returns true, otherwise returns false while maintaining an sorted bag. 
		
		bool remove(int value);
		//Precondition: Bag is be sorted 
		//Postcondition: Value is removed from bag and returns true, otherwise returns false while maintaining an sorted bag. 

		bool binary_search(int value) const;
		//Precondition: Bag is be sorted.
		//Postcondition: Value is found and returns true, otherwise returns false. 

		 size_t size() const
		//Postcondition: Returns size to bag
		 {		 
			 return used;
		 }
		
	private:
		int data[CAPACITY];
		size_t used;
		size_t insert_position(int value);
		//Precondition: Bag must be sorted.
		//Postcondition: Returns value's position of insertion.

		void shift_elements_right(size_t index);
		//Precondition: Index is the intended position for value insertion. 
		//Postcondition: Elements are shifted right starting from index.

		int find_position(int value);
		//Postcondition: Returns index of the first element that equals value. Return -1 if value not found.

		void shift_elements_left(int index);
		//Precondition: Index is the intended position for value deletion. 
		//Postcondition: Elements are shifted left starting from index+1.

	};
}

#endif


