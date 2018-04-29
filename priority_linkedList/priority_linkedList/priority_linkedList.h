#pragma once
#include<iostream>
#include<cassert>
//TODO: fix ruleof3;
namespace sfils_csc212 {

	class priority_linkedlist
	{
	public:
		priority_linkedlist();
		priority_linkedlist(const priority_linkedlist& source);
		void push(int entry);
		int pop();
		int top();
		priority_linkedlist operator=(const priority_linkedlist& source);
		friend std::ostream& operator<<(std::ostream& out, const priority_linkedlist& container);
		~priority_linkedlist();

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
		node *head_ptr;
		node*current_ptr;
		int number_of_nodes;
		node* priority_search(int entry);
		void clear();
		void insert_back(int entry);
		void deep_copy(const priority_linkedlist & source);
	};

	std::ostream& operator<<(std::ostream& out, const priority_linkedlist& container);

}
