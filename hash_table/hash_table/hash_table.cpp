#include "hash_table.h"


hash_table::hash_table(size_t capacity)
{
	hash_table::capacity = capacity;
	full_positions = 0;
	data = new ll_node*[capacity]();
}


hash_table::~hash_table()
{
	clear();
}

hash_table::hash_table(const hash_table & source)
{
	if (full_positions != 0) {
		clear();
		data = new ll_node*[capacity]();
	}
	copy(source);
}

hash_table& hash_table::operator=(const hash_table & source)
{
	if (full_positions != 0) {
		clear();
		data = new ll_node*[capacity]();
	}
	copy(source);
	return *this;
}



size_t hash_table::hash(int data)
{
	return data % capacity;
}

hash_table::ll_node * hash_table::search(size_t index, int entry)
{
	ll_node *prev = nullptr;
	ll_node * head_ptr = data[index];
	while (head_ptr-> next != nullptr && head_ptr->data != entry ) {
		prev = head_ptr;
		head_ptr = head_ptr->next;
	}
	return prev;
}


void hash_table::rehash()
{	
	ll_node* head_ptr = nullptr;
	size_t size = capacity;
	ll_node** old_data = data;
	capacity = 2 * capacity;
	full_positions = 0;
	data = new ll_node*[capacity]();
	//data = new_data;
	for (size_t i = 0; i < size; i++) {
		head_ptr = old_data[i];
		while (head_ptr != nullptr) {
			int entry = head_ptr->data;
			insert(entry);
			ll_node* temp = head_ptr;
			head_ptr = head_ptr->next;
			delete temp;
		}
		head_ptr = nullptr;
	}
	delete[] old_data;
}

void hash_table::clear()
{
	ll_node* head_ptr = nullptr;
	full_positions = 0;
	for (size_t i = 0; i < capacity; i++) {
		head_ptr = data[i];
		while (head_ptr != nullptr) {			
			ll_node* temp = head_ptr;
			head_ptr = head_ptr->next;
			delete temp;
		}
		head_ptr = nullptr;
	}
	delete[] data;
}

void hash_table::copy(const hash_table & source)
{
	if (capacity != source.capacity) {
		capacity = source.capacity;
		delete[] data;
		data = new ll_node*[capacity]();
	}
	ll_node* head_ptr = nullptr;	
	full_positions = 0;	
	for (size_t i = 0; i < capacity; i++) {
		head_ptr = source.data[i];
		while (head_ptr != nullptr) {
			int entry = head_ptr->data;
			insert(entry);
			head_ptr = head_ptr->next;			
		}
		head_ptr = nullptr;
	}
}

void hash_table::insert(int entry)
{
	size_t index = hash(entry);
	ll_node* head_ptr = data[index];
	if (head_ptr == nullptr) {
		data[index] = new ll_node(entry);
		full_positions++;
	}
	else {
		ll_node*temp = new ll_node(entry, head_ptr);
		data[index] = temp;
	}
	double load_factor = full_positions / double(capacity);
	if (load_factor >= 0.75) {
		rehash();
	}
}

void hash_table::remove(int entry)
{
	size_t index = hash(entry);
	ll_node* head_ptr = data[index];
	if (head_ptr == nullptr) {
		return;
	}
	else if(head_ptr->next==nullptr && head_ptr->data == entry){
		delete head_ptr;
		data[index] = nullptr;
		full_positions--;
	}
	else if (head_ptr->data == entry) {
		ll_node* temp = head_ptr;
		head_ptr = head_ptr->next;
		delete temp;
		temp = head_ptr;
		data[index] = temp;
	}
	else {
		ll_node* prev = search(index, entry);
		ll_node* curr = prev->next;
		if (curr != nullptr) {
			prev->next = curr->next;
			delete curr;
		}
		/*else {
			return;
		}	*/	
	}
}

std::ostream & operator<<(std::ostream & out, const hash_table& p)
{
	for (size_t i = 0; i < p.capacity; i++) {
		hash_table::ll_node* head_ptr = p.data[i];
		out << i << " : ";
		while (head_ptr != nullptr) {
			out << head_ptr->data << " ";
			head_ptr = head_ptr->next;
		}
		out << std::endl;
	}
	return out;
}
