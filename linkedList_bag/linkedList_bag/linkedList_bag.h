#pragma once
#include<iostream>
#include<cassert>

namespace sfils_csc212 {

	class linkedList_bag
	{
	public:
		linkedList_bag();
		linkedList_bag(const linkedList_bag& source);
		void insert(int entry);
		void insert(int entry, size_t index); 
		void remove();
		void remove(size_t index);
		void operator=(const linkedList_bag& source);
		friend std::ostream& operator<<(std::ostream& out, const linkedList_bag& container);
		~linkedList_bag();

	private:
		class node {
		public:
			node(int data = 0, node *next = nullptr) {
				node::data = data;
				node::next = next;
			}
			int data;
			node*next;
		};
		node *head_ptr;
		node*current_ptr;
		int number_of_nodes;
		node* search_index(size_t index);
		void deep_copy(const linkedList_bag & source);
	};

	std::ostream& operator<<(std::ostream& out, const linkedList_bag& container);

}