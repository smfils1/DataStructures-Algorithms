#pragma once
#include<iostream>
#include<cassert>

namespace sfils_csc212 {

	class doubly_linkedList
	{
	public:
		doubly_linkedList();
		doubly_linkedList(const doubly_linkedList& source);
		void insert(int entry);
		void insert(int entry, size_t index);
		void remove();
		void remove(size_t index);
		doubly_linkedList& operator=(const doubly_linkedList& source);
		friend std::ostream& operator<<(std::ostream& out, const doubly_linkedList& container);
		~doubly_linkedList();

	private:
		class node {
		public:
			node(int data = 0, node *prev = nullptr, node *next = nullptr) {
				node::data = data;
				node::next = next;
				node::prev = prev;
			}
			int data;
			node*next;
			node*prev;
		};
		/**/
		class iterator {
			iterator(node* position) {
				position = current;
			}
		private:
			node* current;
		};
		iterator& begin();
		iterator& end();
		

		node *head_ptr;
		node*current_ptr;
		int number_of_nodes;
		node* search_index(size_t index);
		void clear();
		void deep_copy(const doubly_linkedList & source);
	};

	std::ostream& operator<<(std::ostream& out, const doubly_linkedList& container);

}
