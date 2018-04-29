#pragma once
#include<iostream>
#include<cassert>

namespace sfils_csc212 {

	class doubly_linkedList
	{
	private:
		class node;
	public:
		class iterator;
		doubly_linkedList();
		doubly_linkedList(const doubly_linkedList& source);
		doubly_linkedList& operator=(const doubly_linkedList& source);
		~doubly_linkedList();
		void insert(int entry);
		void insert(int entry, size_t index);
		void remove();
		void remove(size_t index);
		size_t size();		
		iterator begin();
		iterator end();
		friend std::ostream& operator<<(std::ostream& out, const doubly_linkedList& container);
		//friend bool operator!=(const iterator& left, const iterator& right);
	class iterator {
		public:
			iterator(node*current) {
				current_itr = current;
			}
			int& operator*() const;
			iterator& operator++();
			iterator& operator++(int i);
			bool operator!=(const iterator& right) const ;
			bool operator==(const iterator& right) const;
			//friend class node;
		private:
				node * current_itr;
		};	

	private:
		class node {
		public:
			node(int data, node *prev = nullptr, node *next = nullptr) {
				node::data = data;
				node::next = next;
				node::prev = prev;
			}
			int data;
			node*next;
			node*prev;
			//friend class iterator;

		};		
		
		node *head_ptr;
		node*current_ptr;
		int number_of_nodes;
		node* search_index(size_t index);
		void clear();
		void deep_copy(const doubly_linkedList & source);
	};

	std::ostream& operator<<(std::ostream& out, const doubly_linkedList& container);
	//bool operator==(const iterator& left, const iterator& right);
	//bool operator!=(const iterator& left, const iterator& right);

}
