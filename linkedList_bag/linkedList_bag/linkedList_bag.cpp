#include "linkedList_bag.h"

namespace sfils_csc212 {
	linkedList_bag::linkedList_bag()
	{
		head_ptr = nullptr;
		current_ptr = nullptr;
		number_of_nodes = 0;
	}
	linkedList_bag::linkedList_bag(const linkedList_bag & source)
	{
		deep_copy(source);
	}

	void linkedList_bag::operator=(const linkedList_bag & source)
	{
		deep_copy(source);
	}
	void linkedList_bag::insert(int entry)
	{
		if (head_ptr == nullptr) {//empty just glue a node and update curr & size
			head_ptr = new node(entry);
			current_ptr = head_ptr;
			number_of_nodes++;
		}
		else {//use curr to glue a node and update curr & size
			current_ptr->next = new node(entry);
			current_ptr = current_ptr->next;
			number_of_nodes++;
		}
	}

	void linkedList_bag::insert(int entry, size_t index)
	{
		assert(index <= number_of_nodes);//Available insert position
		if ((head_ptr == nullptr) || (index == number_of_nodes)) {//Insert a back cases 
			insert(entry);
		}
		else if (index == 0) {//Case: insert at front with not empty
			head_ptr = new node(entry, head_ptr);
			number_of_nodes++;
		}
		else {//middle case
			node* previous = search_index(index);
			previous->next = new node(entry, previous->next);
			number_of_nodes++;
		}
	}

	void linkedList_bag::remove()
	{
		if (head_ptr == nullptr) {//exit if empty
			return;
		}
		else if (number_of_nodes == 1) {//if size=1 just current and update curr and size
			delete current_ptr;
			head_ptr = nullptr;
			current_ptr = nullptr;
			number_of_nodes--;
		}
		else {//back case so use previos node(n-1) point to null then delete curr
			node* prev_current = search_index(number_of_nodes - 1);
			prev_current->next = nullptr;
			delete current_ptr;
			current_ptr = prev_current;
			number_of_nodes--;

		}
	}

	void linkedList_bag::remove(size_t index)
	{
		assert(index < number_of_nodes);//Avaible positions to remove
		if ((number_of_nodes == 1) || (index == number_of_nodes-1)) {//Cases to remove back
			remove();
		}
		else if (index == 0) {//Case to remove front when not empty so move up head and delete
			node*temp = head_ptr;
			head_ptr = head_ptr->next;
			delete temp;
			number_of_nodes--;

		}
		else {//Middle case
			node*previous = search_index(index);
			node*temp = previous->next;
			previous->next = temp->next;
			delete temp;
			number_of_nodes--;

		}

	}

	linkedList_bag::~linkedList_bag()
	{
		node*temp = head_ptr;
		while (temp != nullptr) {
			node*trash = temp;
			temp = temp->next;
			delete trash;


		}
	}

	linkedList_bag::node * linkedList_bag::search_index(size_t index)
	{//Function return previous node to index
		if (index == 1) {
			return head_ptr;
		}
		else {
			node*temp = head_ptr;
			for (int i = 0; i < index - 1; i++) {
				temp = temp->next;
			}
			return temp;
		}
	}

	void linkedList_bag::deep_copy(const linkedList_bag & source)
	{//new head w/ loop to initilize it using inset function
		node* new_head = nullptr;
		head_ptr = new_head;
		current_ptr = new_head;
		number_of_nodes = 0;
		node* temp = source.head_ptr;
		while (temp != nullptr) {
			insert(temp->data);
			temp = temp->next;
		}
	}

	std::ostream & operator<<(std::ostream & out, const linkedList_bag& container)
	{
		linkedList_bag::node *temp = container.head_ptr;
		while (temp != nullptr) {
			out << temp->data;
			temp = temp->next;
		}
		return out;
	}
}
