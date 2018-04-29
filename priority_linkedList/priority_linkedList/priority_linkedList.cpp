#include "priority_linkedlist.h"

namespace sfils_csc212 {
	priority_linkedlist::priority_linkedlist()
	{
		head_ptr = nullptr;
		current_ptr = nullptr;
		number_of_nodes = 0;
	}
	priority_linkedlist::priority_linkedlist(const priority_linkedlist & source)
	{
		if (this != &source) {
			clear();
			deep_copy(source);

		}
	}

	priority_linkedlist priority_linkedlist::operator=(const priority_linkedlist & source)
	{
		if (this != &source) {
			clear();
			deep_copy(source);

		}
		return *this;//for chaining
	}
	void priority_linkedlist::push(int entry)
	{
		if (head_ptr == nullptr) {//empty just glue a node and update curr & size
			head_ptr = new node(entry);
			current_ptr = head_ptr;
			number_of_nodes++;
			return;
		}

		node*middle = priority_search(entry);

		if (middle == nullptr) {
			current_ptr->next = new node(entry, current_ptr);//add curent to prev pointr
			current_ptr = current_ptr->next;
			number_of_nodes++;
		}
		else if (middle->prev == nullptr) {
			node*temp = head_ptr;
			head_ptr = new node(entry, nullptr, temp);
			temp->prev = head_ptr;
			number_of_nodes++;
		}
		else {
			
			node*previous = middle->prev;
			middle->prev = new node(entry, previous, middle);
			previous->next = middle->prev;
			number_of_nodes++;
		}
	}


	int priority_linkedlist::pop()
	{
		assert(head_ptr != nullptr);
		if (number_of_nodes == 1) {//if size=1 just current and update curr and size
			node*temp = head_ptr;
			head_ptr = head_ptr->next;
			head_ptr = nullptr;
			current_ptr= nullptr;
			int priority = temp->data;
			delete temp;
			number_of_nodes--;
			return priority;
		}
		else {//Case to remove front when not empty so move up head and delete
			node*temp = head_ptr;
			head_ptr = head_ptr->next;
			head_ptr->prev = nullptr;
			int priority = temp->data;
			delete temp;
			number_of_nodes--;
			return priority;
		}
	}

	int priority_linkedlist::top()
	{
		assert(head_ptr != nullptr);		
		return head_ptr->data;		
	}


	priority_linkedlist::~priority_linkedlist()
	{
		clear();
	}

	priority_linkedlist::node * priority_linkedlist::priority_search(int entry)
	{
		node*temp = head_ptr;
		while (temp != nullptr) {
			if(entry>=temp->data){
				return temp;
			}
			temp = temp->next;
		}
		return temp;
	}

	void priority_linkedlist::clear()
	{//Resets the list
		node*temp = head_ptr;
		while (temp != nullptr) {
			node*trash = temp;
			temp = temp->next;
			delete trash;
		}
		head_ptr = temp;
		current_ptr = temp;
		number_of_nodes = 0;
	}

	void priority_linkedlist::insert_back(int entry)//insert @back
	{
		if (head_ptr == nullptr) {//Case:Empty list so just insert at head and update state
			head_ptr = new node(entry);
			current_ptr = head_ptr;
			number_of_nodes++;
		}
		else {//Inserts at back and update state
			current_ptr->next = new node(entry, current_ptr);//add curent to prev pointr
			current_ptr = current_ptr->next;
			number_of_nodes++;
		}
	}

	void priority_linkedlist::deep_copy(const priority_linkedlist & source)
	{//new head w/ loop to initilize it using inset function
		node* temp = source.head_ptr;
		while (temp != nullptr) {
			insert_back(temp->data);
			temp = temp->next;
		}
	}

	std::ostream & operator<<(std::ostream & out, const priority_linkedlist& container)
	{
		priority_linkedlist::node *temp = container.head_ptr;
		while (temp != nullptr) {
			out << temp->data << " ";
			priority_linkedlist::node *  prevtemp = temp->prev;

			if (prevtemp == nullptr) { out << "Prev: " << "NULL" << " | "; }
			else { out << "Prev: " << prevtemp->data << " | "; }
			priority_linkedlist::node *  nexttemp = temp->next;
			if (nexttemp == nullptr) { out << "Next: " << "NULL" << " "; }
			else { out << "Next: " << nexttemp->data << std::endl; }
			temp = temp->next;
		}
		return out;
	}
}
