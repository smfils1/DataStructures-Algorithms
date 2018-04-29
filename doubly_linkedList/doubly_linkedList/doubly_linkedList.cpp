#include "doubly_linkedList.h"

namespace sfils_csc212 {
	// Constructor
	doubly_linkedList::doubly_linkedList()
	{
		head_ptr = nullptr;
		current_ptr = nullptr;
		number_of_nodes = 0;
	}
	//Copy Constructor
	doubly_linkedList::doubly_linkedList(const doubly_linkedList & source)
	{
		if (this != &source) {
			clear();
			deep_copy(source);
		}
	}

	//Assignment Operator
	doubly_linkedList& doubly_linkedList::operator=(const doubly_linkedList & source)
	{
		if (this != &source) {
			clear();
			deep_copy(source);

		}
		return *this;//for chaining
	}

	size_t doubly_linkedList::size()
	{
		return number_of_nodes;
	}

	//Destructor
	doubly_linkedList::~doubly_linkedList()
	{
		clear();
	}

	//Default insert @ end
	void doubly_linkedList::insert(int entry)//insert @back
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

	//Insert @ index
	void doubly_linkedList::insert(int entry, size_t index)
	{
		assert(index <= number_of_nodes);//Index must be valid
		if ((head_ptr == nullptr) || (index == number_of_nodes)) {//Cases: Empty list and/or insert at back
			insert(entry);
		}
		else if (index == 0) {//Case: Insert at head when NOT empty and update state
			head_ptr = new node(entry, nullptr, head_ptr);
			number_of_nodes++;
		}
		else {//Insert at middle by getting node before index position and connecting and update links
			node* previous = search_index(index);
			node*temp = previous->next;
			previous->next = new node(entry, previous, temp);
			temp->prev = previous->next;
			number_of_nodes++;
		}
	}

	//Default remove @ end
	void doubly_linkedList::remove()//remove back
	{
		if (head_ptr == nullptr) {//Case: Empty List so exit
			return;
		}
		else if (number_of_nodes == 1) {//Case: Only one node so delete current and update state
			delete current_ptr;
			head_ptr = nullptr;
			current_ptr = nullptr;
			number_of_nodes--;
		}
		else {//Case:Remove back when full and updatre state
			node* prev_current = current_ptr->prev;
			prev_current->next = nullptr;
			delete current_ptr;
			current_ptr = prev_current;
			number_of_nodes--;

		}
	}

	//Remove @ index
	void doubly_linkedList::remove(size_t index)
	{
		assert(index < number_of_nodes);//Avaible positions to remove
		if ((number_of_nodes == 1) || (index == number_of_nodes - 1)) {//Cases: Remove back
			remove();
		}
		else if (index == 0) {//Case:Remove front when full by move head up,delete, and update state
			node*temp = head_ptr;
			head_ptr = head_ptr->next;
			head_ptr->prev = nullptr;
			delete temp;
			number_of_nodes--;

		}
		else {//Case: Middle
			node*previous = search_index(index);
			node*temp = previous->next;
			previous->next = temp->next;
			delete temp;
			temp = previous->next;
			temp->prev = previous;
			number_of_nodes--;
			/*
			node*tmp = search_index(index + 1);//Need tmp to point to the node ypu want to remove for below to work properly
			node* tmp2 = tmp->prev;//Save tmp's prev_ptr to use later(tmp2)
			node* tmp3 = tmp->next;//Save tmp's next_ptr to use later(tmp3)
			tmp3->prev = tmp2;//The prev_ptr of the node thats after the one your want to remove is set to tmp2
			tmp2->next = tmp3;//The next_ptr of the node thats before the one your want to remove is set to tmp3
			delete tmp;//Now delete
			number_of_nodes--; */

		}

	}	
	//Helper search for previos node
	doubly_linkedList::node * doubly_linkedList::search_index(size_t index)
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

	// Helper reset state
	void doubly_linkedList::clear()
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

	//Helper copy nodes
	void doubly_linkedList::deep_copy(const doubly_linkedList & source)
	{//new head w/ loop to initilize it using inset function		
		node* temp = source.head_ptr; 
		while (temp != nullptr) {
			insert(temp->data);
			temp = temp->next;
		}
	}

	doubly_linkedList::iterator  doubly_linkedList::begin() {

		return iterator(head_ptr);

	}

	doubly_linkedList::iterator  doubly_linkedList::end() {

		return iterator(nullptr);

	}

	std::ostream & operator<<(std::ostream & out, const doubly_linkedList& container)
	{
		doubly_linkedList::node *temp = container.head_ptr;
		while (temp != nullptr) {
			out << temp->data << " ";
			doubly_linkedList::node *  prevtemp = temp->prev;

			if (prevtemp == nullptr) { out << "Prev: " << "NULL" << " | "; }
			else { out << "Prev: " << prevtemp->data << " | "; }
			doubly_linkedList::node *  nexttemp = temp->next;
			if (nexttemp == nullptr) { out << "Next: " << "NULL" << " "; }
			else { out << "Next: " << nexttemp->data << std::endl; }
			temp = temp->next;
		}
		return out;
	}
	
	int & doubly_linkedList::iterator::operator*() const
	{
		return current_itr->data;
	}
	doubly_linkedList::iterator & doubly_linkedList::iterator::operator++()
	{
		current_itr = current_itr->next;
		return *this;
	}
	doubly_linkedList::iterator & doubly_linkedList::iterator::operator++(int i)
	{
		iterator temp =*this;
		++(*this);
		return temp;
	}
	bool doubly_linkedList::iterator::operator==(const iterator & right) const
	{
		return current_itr == right.current_itr;

	}
	 
	bool doubly_linkedList::iterator::operator!=(const iterator & right) const
	{
		return current_itr != right.current_itr;
	}
	//
//doubly_linkedList::begin() {
//		return new iterator(head_ptr);
//	}
//	doubly_linkedList::iterator& doubly_linkedList::end() {
//
//		return new iterator(current);
//	}
//
}
