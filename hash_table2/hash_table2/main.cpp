#include"hash_table2.h"
using sfils_csc212::hash_table2;


int main() {
	//All requirements completed 

	// Advantages of this implementation:		
	/*
		For a system like a student information system where the key is a number and the item is an student object
		Ex: hash_table2<int,Student> CCNY_STUDENT_SYSTEM ;
		searching is one of the most important feature.
		We switch from a linked list to a binary search tree when searching becomes inefficient.
		Search is O(n) instead of 0(C) due to the large size of the linked list. 
		A binary search tree deliver O(lgn) search speed.
		However, at some point due to removal and/or rehashing the efficiency of a linked list
		will go back to O(C) so at that point its best to switch back from a bst to a linked list.
		
	*/

	//Implementation Summary:
	/*
		Once a hash_table2 object is created each index of its table will point to a hash_node.
		Each hash node contains an empty linkeded list & binary search tree, 
		a mode variable indicating the current mode, and a size variable indicating the size of the current structure in use.
		When inserting or removing the mode of a hash node may switch to a binary search tree when its size reaches 11,
		or switch back to a linked list when its size reduces to 8.
		This process happens while also reharshing when a threshold of .75 is reached.
		-Value semantics is safe
	*/


	hash_table2<int, int> a;
	a.insert(1, 1);
	std::cout << a;
	return 0;
}