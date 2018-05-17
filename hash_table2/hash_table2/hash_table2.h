#ifndef HASH_TABLE2_H
#define HASH_TABLE2_H

#include<iostream>



//TODO:make sure unsed mode really points to null
//TODO:remove = case in insert
//TODO:capacity assert
//TODO: dangling pointers remove cases

namespace sfils_csc212 {
	
	class hash_table2
	{
	public:
		hash_table2(size_t capacity = 16);
		//Postcondition: An hash table is created w/ each index pointing to a hash node .

		~hash_table2();
		//Postcondition: Deletes all hash, linked list, and bst nodes and resets the state of the table
		
		hash_table2(const hash_table2& source);
		//Postcondition: The state and nodes of source table is copied

		hash_table2& operator=(const hash_table2& source);
		//Postcondition: The state and nodes of source table is copied

		void insert(int key, int entry);
		//Postcondition: Inserts entry to table at an calculated index based on current mode('B' or 'L') & rehashes or switch modes when neccessary.

		void remove(int key);
		//Postcondition: Removes entry from table at an calculated index based on current mode('B' or 'L') & switch modes when neccessary.
				
		friend std::ostream& operator<<(std::ostream& out, const hash_table2& source);

	private:

		class ll_node {
		public:
			ll_node(int key, int data, ll_node *next = nullptr) {
				ll_node::key = key;
				ll_node::data = data;
				ll_node::next = next;
			}
			int key;
			int data;
			ll_node*next;
		};

		class bst_node {
		public:
			bst_node(int key, int data, bst_node* left = nullptr, bst_node* right = nullptr) {
				bst_node::key = key;
				bst_node::data = data;
				bst_node::left = left;
				bst_node::right = right;
			}
			int key;
			int data;
			bst_node * left;
			bst_node * right;
		};

		class hash_node {
		public:
			hash_node(ll_node * head_ptr = nullptr, bst_node * root_ptr = nullptr, char mode = 'L', size_t size = 0) {
				hash_node::head_ptr = head_ptr;
				hash_node::root_ptr = root_ptr;
				hash_node::size = size;
				hash_node::mode = mode;
			}
			ll_node * head_ptr;
			bst_node * root_ptr;
			size_t size;
			char mode;
		};

		hash_node** table;
		size_t capacity;
		size_t filled_positions;
		size_t hash(int entry);
		//Postcondition: Return a calculated index

		void rehash();
		//Postcondition: Double table size and capacity when threhold of .75 is reached w/ user entries in recalculated index

		void copy_index(size_t index, hash_node ** table);
		//Postcondition: Copies the hash node at specified index from of specified hash table. 

		void copy_index_helper(bst_node * root_ptr);
		//Postcondition: Copies the binary search tree from  specified root_ptr of a hash table.

		void LL_insert(int key, int entry, size_t index);
		//Postcondition: Inserts a new node w/ key and entry to the linkedlist at index of the table.

		void BST_insert(int key, int entry, size_t index);
		//Postcondition: Inserts a new node w/ key and entry to the binary search tree at index of the table.

		void BST_insert_helper(int key, int entry, bst_node *& root_ptr);
		//Postcondition: Inserts a new node w/ key and entry to a binary search tree at index of the table.

		void LL_remove(int key, size_t index);
		//Postcondition: Removes a node w/ key from the linkedlist at index of the table.

		size_t LL_search(int key, ll_node * head_ptr) const;
		//Postcondition: Returns the position of the node w/ key from a linkedlist.

		bool LL_search_key(int key, ll_node * head_ptr) const;
		//Postcondition: Returns true if key is found in a linked list otherwise returns false.

		void BST_remove(int key, size_t index);
		//Postcondition: Removes a node w/ key from the binary search tree at index of the table.

		void BST_remove_helper(int key, size_t index, bst_node *& root_ptr);
		//Postcondition: Removes a new node w/ key of a binary search tree at index of the table.

		bst_node* get_min_node(bst_node* node) const;
		//Postcondition: Returns a node w/ minimum key from a binary search tree.

		void switch_mode(size_t index);
		//Postcondition: Switches mode to 'B':binary search tree when tree size becomes 11 & to 'L':linkedlist when linkedlist size reduces to 8.


		void switch_BST_to_LL(size_t index, bst_node *& root);
		//Postcondition: binary search tree is converted to a linked list at index of the table.

		void switch_LL_to_BST(size_t index);
		//Postcondition: binary search tree is converted to a linked list at index of the table.
		
		void clear_index(size_t index);
		//Postcondition: Empty the binary search tree or the linkedlist at index of the table if either of them are full.

		void clear_index(size_t index, hash_node **& table);
		//Postcondition: Empty the binary search tree or the linkedlist at index of specified table if either of them are full.


		void clear_index_helper(bst_node *& node);
		//Postcondition: Empty a binary search tree  if it is full.


		void bst_print(bst_node* node) const;
		//FOR TESTING
		//Postcondition: Prints nodes from binary search tree in order
	};

	std::ostream& operator<<(std::ostream& out, const hash_table2& source);
	//FOR TESTING
	//Postcondition: Prints the entire table 


}

#endif