#include "hash_table2.h"
#include<cassert>

namespace sfils_csc212 {

	hash_table2::hash_table2(size_t capacity)
	{
		hash_table2::capacity = capacity;
		filled_positions = 0;
		table = new hash_node*[capacity]();
		for (size_t i = 0; i < capacity; i++) {
			table[i] = new hash_node[capacity]();
		}

	}
	hash_table2::hash_table2(const hash_table2 & source)
	{
		if (this != &source) {
			capacity = source.capacity;
			table = new hash_node*[capacity]();
			for (size_t i = 0; i < capacity; i++) {
				table[i] = new hash_node[capacity]();
				copy_index(i, source.table);
			}
		}
	}

	hash_table2& hash_table2::operator=(const hash_table2 & source)
	{
		if (this != &source) {			
			filled_positions = 0;
			if (capacity == source.capacity) {
				for (size_t i = 0; i < capacity; i++) {
					clear_index(i);
					copy_index(i, source.table);
				}
			}
			else {			
				for (size_t i = 0; i < capacity; i++) {
					clear_index(i);
					delete table[i];
				}	
				capacity = source.capacity;
				table = new hash_node*[capacity]();
				for (size_t i = 0; i < capacity; i++) {
					table[i] = new hash_node[capacity]();
					copy_index(i, source.table);
				}				
				
			}
		}
		return *this;
	}



	hash_table2::~hash_table2()
	{
		for (size_t i = 0; i <capacity; i++) {
			clear_index(i);
			delete table[i];
		}
		
		delete[] table;
	}

	void hash_table2::insert(int key, int entry)
	{
		size_t index = hash(key);
		if (table[index]->mode == 'L') {
			LL_insert(key, entry, index);
		}
		else {
			BST_insert(key, entry, index);
		}
		rehash();
		switch_mode(index);
	}

	size_t hash_table2::hash(int key)
	{
		return key % capacity;
	}

	void hash_table2::LL_insert(int key, int entry, size_t index)
	{
		hash_node *linked_list = table[index];
		if (!(LL_search_key(key, linked_list->head_ptr))) {
			if (linked_list->size == 0) {
				linked_list->head_ptr = new ll_node(key, entry);
				filled_positions++;
				linked_list->size++;
			}
			else {
				linked_list->head_ptr = new ll_node(key, entry, linked_list->head_ptr);				
				linked_list->size++;
			}
		}
	}

	void hash_table2::BST_insert(int key, int entry, size_t index)
	{
		if (table[index]->size == 0) {
			filled_positions++;
		}
		BST_insert_helper(key, entry, table[index]->root_ptr);
		//table[index]->size++;
	}

	void hash_table2::BST_insert_helper(int key, int entry, bst_node *& node)
	{
		if (node == nullptr) {
			node = new hash_table2::bst_node(key, entry);
			table[hash(key)]->size++;

		}
		else if (key < node->key) {
			BST_insert_helper(key, entry, node->left);
		}
		else if (key > node->key) {
			BST_insert_helper(key, entry, node->right);
		}
		else {
			return;
		}
	}

	void hash_table2::remove(int key)
	{
		size_t index = hash(key);
		if (table[index]->mode == 'L') {
			LL_remove(key,index);
		}
		else {
			BST_remove(key,index);
		}
		switch_mode(index);
	}


	size_t hash_table2::LL_search(int key, ll_node * head_ptr) const
	{
		size_t index = 0;
		while (head_ptr != nullptr) {
			if (head_ptr->key == key) {
				return index;
			}
			head_ptr = head_ptr->next;
			index++;
		}
		return index;
	}
	bool hash_table2::LL_search_key(int key, ll_node * head_ptr) const
	{
		size_t index = 0;
		while (head_ptr != nullptr) {
			if (head_ptr->key == key) {
				return true;
			}
			head_ptr = head_ptr->next;
			index++;
		}
		return false;
	}

	void hash_table2::LL_remove(int key, size_t index)
	{
		hash_node *linked_list = table[index];
		if (linked_list->size == 0) {
			return;
		}
		size_t ll_index = LL_search(key, linked_list->head_ptr);		
		if (ll_index < linked_list->size ) {
			if (ll_index == 0) {
				ll_node* trash = linked_list->head_ptr;
				linked_list->head_ptr = trash->next;
				delete trash;
				linked_list->size--;				
			}
			else {
				ll_node*previous = linked_list->head_ptr;
				for (size_t i = 1; i < ll_index; i++) {
					previous = previous->next;
				}
				ll_node* trash = previous->next;
				previous->next = trash->next;
				delete trash;
				linked_list->size--;
			}			
		}
		if (linked_list->size == 0) {
			filled_positions--;
		}
	}

	void hash_table2::BST_remove(int key, size_t index)
	{
		if (table[index]->size == 0) {
			return;
		}
		BST_remove_helper(key, index, table[index]->root_ptr);
		if (table[index]->size == 0) {
			filled_positions--;
		}
	}

	void hash_table2::BST_remove_helper(int key, size_t index, bst_node *& node)
	{
		if (node == nullptr) {
			return;
		}
		if (key < node->key) {
			BST_remove_helper(key, index, node->left);
		}
		else if (key > node->key) {
			BST_remove_helper(key, index, node->right);
		}
		else {
			bst_node* trash = nullptr;
			if (node->left == nullptr && node->right == nullptr) {
				trash = node;
				node = nullptr;
				delete trash;
				table[index]->size--;
			}
			else if (node->left == nullptr) {
				trash = node;
				node = node->right;
				delete trash;
				table[index]->size--;
			}
			else if (node->right == nullptr) {
				trash = node;
				node = node->left;
				delete trash;
				table[index]->size--;
			}
			else
			{	
				bst_node* original = get_min_node(node->right);
				node->data = original->data;
				node->key = original->key;
				BST_remove_helper(node->data, index, node->right);
			}

		}
	}

	hash_table2::bst_node*  hash_table2::get_min_node (bst_node* node) const
	{
		assert(node != nullptr);
		if (node->left == nullptr) {
			return node;
		}
		get_min_node(node->left);
	}


	void hash_table2::rehash()
	{
		double load_factor = filled_positions / double(capacity);
		if (load_factor >= 0.75) {
			size_t old_capacity = capacity;
			hash_node** old_table = table;
			capacity = 2 * capacity;
			table = new hash_node*[capacity]();
			for (size_t i = 0; i < capacity; i++) {
				table[i] = new hash_node[capacity]();
			}
			for (size_t i = 0; i < old_capacity; i++) {
				if (old_table[i]->mode == 'L') {
					copy_index(i, old_table);
				}
				else {
					copy_index(i, old_table);
				}
				clear_index(i, old_table);
			}			
			delete[] old_table;
		}
	}

	void hash_table2::copy_index(size_t index, hash_node ** table)
	{
		if (table[index]->mode == 'L') {
			hash_node *linked_list = table[index];
			ll_node* head_ptr = linked_list->head_ptr;
			while (head_ptr != nullptr) {
				insert(head_ptr->key, head_ptr->data);
				head_ptr = head_ptr->next;
			}
		}
		else {
			copy_index_helper(table[index]->root_ptr);
		}
	}

	void hash_table2::copy_index_helper(bst_node * node) {
		if (node == nullptr) {
			return;
		}
		else {
			insert(node->key, node->data);
			copy_index_helper(node->left);
			copy_index_helper(node->right);
		}
	}


	void hash_table2::switch_mode(size_t index)
	{
		hash_node *sub_container = table[index];
		if (sub_container->size == 8 && sub_container->head_ptr == nullptr) {
			sub_container->mode = 'L';
			table[index]->size = 0;
			filled_positions--;//test

			switch_BST_to_LL(index, sub_container->root_ptr);
		}
		if (sub_container->size == 11 && sub_container->root_ptr == nullptr) {
			sub_container->mode = 'B';
			table[index]->size = 0;//test
			filled_positions--;//test
			switch_LL_to_BST(index);
		}
	}

	void hash_table2::switch_BST_to_LL(size_t index, bst_node *& node)
	{
		if (node == nullptr) {
			return;
		}
		else {
			switch_BST_to_LL(index, node->left);
			switch_BST_to_LL(index, node->right);
			LL_insert(node->key, node->data, index);
			delete node;
		}
		node = nullptr; //TESt when bst remove finish
	}

	void hash_table2::switch_LL_to_BST(size_t index)
	{
		hash_node* linked_list = table[index];
		ll_node* temp = nullptr;		
		while (linked_list->head_ptr != nullptr) {
			int entry = linked_list->head_ptr->data;
			int key = linked_list->head_ptr->key;
			BST_insert(key, entry, index);
			temp = linked_list->head_ptr;
			linked_list->head_ptr = linked_list->head_ptr->next;
			delete temp;
		}
	}

	void hash_table2::clear_index(size_t index) 
	{
		if (table[index]->size != 0) {
			filled_positions--;
			if (table[index]->mode == 'L') {
				hash_node *linked_list = table[index];
				while (linked_list->head_ptr != nullptr) {
					ll_node* trash = linked_list->head_ptr;
					linked_list->head_ptr = trash->next;
					delete trash;
					linked_list->size--;
				}
			}
			else {
				clear_index_helper(table[index]->root_ptr);
				table[index]->root_ptr = nullptr;				
			}
		}
	
	}

	void hash_table2::clear_index(size_t index, hash_node **& table)
	{
		if (table[index]->size != 0) {
			filled_positions--;
			if (table[index]->mode == 'L') {
				hash_node *linked_list = table[index];
				while (linked_list->head_ptr != nullptr) {
					ll_node* trash = linked_list->head_ptr;
					linked_list->head_ptr = trash->next;
					delete trash;
					linked_list->size--;
				}
			}
			else {
				clear_index_helper(table[index]->root_ptr);
				table[index]->root_ptr = nullptr;
			}
		}

	}

	void hash_table2::clear_index_helper(bst_node *& node) 
	{
		if (node == nullptr) {
			return;
		}
		else {
			clear_index_helper(node->left);
			clear_index_helper(node->right);
			delete node;
		}
	}


	void hash_table2::bst_print(bst_node* node) const
	{
		if (node == nullptr) {
			return;
		}
		else {
			bst_print(node->left);
			std::cout << "(" << node->key << "," << node->data << ") ";
			bst_print(node->right);
		}
	}


	std::ostream & operator<<(std::ostream & out, const hash_table2 & source)
	{
		for (size_t i = 0; i < source.capacity; i++) {
			hash_table2::hash_node *table = source.table[i];
			out << i << " : ";

			if (table->mode == 'L') {
				hash_table2::ll_node * head_ptr = table->head_ptr;

				while (head_ptr != nullptr) {
					out << "(" << head_ptr->key << "," << head_ptr->data << ") ";
					head_ptr = head_ptr->next;
				}
				out << " Size: " << table->size << " Mode: " << table->mode;
				out << std::endl;
			}
			else {
				source.bst_print(table->root_ptr);
				out << " Size: " << table->size << " Mode: " << table->mode;


				out << std::endl;
			}
		}
		out << "Filled Positions: " <<source.filled_positions << std::endl;
		return out;
	}

}
