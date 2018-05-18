#ifndef HASH_TABLE2_H
#define HASH_TABLE2_H

#include<iostream>


namespace sfils_csc212 {

	template<class Id, class Item>
	class hash_table2
	{
	public:
		hash_table2(size_t capacity = 16);
		//Postcondition: An hash table is created w/ each index pointing to a hash node .

		~hash_table2();
		//Postcondition: Deletes all hash, linked list, and bst nodes and resets the state of the table
		
		hash_table2(const hash_table2<Id, Item>& source);
		//Postcondition: The state and nodes of source table is copied

		hash_table2<Id, Item>& operator=(const hash_table2<Id, Item>& source);
		//Postcondition: The state and nodes of source table is copied

		void insert(Id key, Item entry);
		//Postcondition: Inserts entry into table at an calculated index based on current mode('B' or 'L') & rehashes or switch modes when neccessary.

		void remove(Id key);
		//Postcondition: Removes entry from table at an calculated index based on current mode('B' or 'L') & switch modes when neccessary.
		
		template<class Id, class Item>
		friend std::ostream& operator<<(std::ostream& out, const hash_table2<Id, Item>& source);

	private:

		class ll_node {
		public:
			ll_node(Id key, Item data, ll_node *next = nullptr) {
				ll_node::key = key;
				ll_node::data = data;
				ll_node::next = next;
			}
			Id key;
			Item data;
			ll_node*next;
		};

		class bst_node {
		public:
			bst_node(Id key, Item data, bst_node* left = nullptr, bst_node* right = nullptr) {
				bst_node::key = key;
				bst_node::data = data;
				bst_node::left = left;
				bst_node::right = right;
			}
			Id key;
			Item data;
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
		size_t hash(Id key);
		//Postcondition: Return a calculated index

		void rehash();
		//Postcondition: Double table size and capacity when threshold of .75 is reached & recalculates index of user entries

		void copy_index(size_t index, hash_node ** table);
		//Postcondition: Copies the hash node at a specified index from of specified hash table. 

		void copy_index_helper(bst_node * root_ptr);
		//Postcondition: Copies the binary search tree from  specified root_ptr of a hash table.

		void LL_insert(Id key, Item entry, size_t index);
		//Postcondition: Inserts a new node w/ key and entry to the linkedlist at index of the table.

		void BST_insert(Id key, Item entry, size_t index);
		//Postcondition: Inserts a new node w/ key and entry to the binary search tree at index of the table.

		void BST_insert_helper(Id key, Item entry, bst_node *& root_ptr);
		//Postcondition: Inserts a new node w/ key and entry to a binary search tree at index of the table.

		void LL_remove(Id key, size_t index);
		//Postcondition: Removes a node w/ key from the linkedlist at index of the table.

		size_t LL_search(Id key, ll_node * head_ptr) const;
		//Postcondition: Returns the position of the node w/ key from a linkedlist.

		bool LL_search_key(Id key, ll_node * head_ptr) const;
		//Postcondition: Returns true if key is found in a linked list otherwise returns false.

		void BST_remove(Id key, size_t index);
		//Postcondition: Removes a node w/ key from the binary search tree at index of the table.

		void BST_remove_helper(Id key, size_t index, bst_node *& root_ptr);
		//Postcondition: Removes a new node w/ key of a binary search tree at index of the table.

		bst_node* get_min_node(bst_node* node) const;
		//Precondition: Tree is not empty
		//Postcondition: Removes the node w/ minimum key from a binary search tree.

		void switch_mode(size_t index);
		//Postcondition: Switches mode to 'B':binary search tree when tree size becomes 11 & to 'L':linkedlist when linkedlist size reduces to 8.

		void switch_BST_to_LL(size_t index, bst_node *& root);
		//Postcondition: Binary search tree is converted to a linked list at index of the table.

		void switch_LL_to_BST(size_t index);
		//Postcondition: binary search tree is converted to a linked list at index of the table.
		
		void clear_index(size_t index);
		//Postcondition: Empties the binary search tree or the linkedlist at index of the table if either of them is full.

		void clear_index(size_t index, hash_node **& table);
		//Postcondition: Empties the binary search tree or the linkedlist at index of specified table if either of them are full.

		void clear_index_helper(bst_node *& node);
		//Postcondition: Empties a binary search tree  if it is full.


		void bst_print(bst_node* node) const;
		//FOR TESTING Primative types
		//Postcondition: Prints nodes from binary search tree in order
	};

	template<class Id, class Item>
	std::ostream& operator<<(std::ostream& out, const hash_table2<Id, Item>& source);
	//FOR TESTING Primative types
	//Postcondition: Prints the entire table and its state 
}

#include"hash_table2.tpp" // Implementation
#endif