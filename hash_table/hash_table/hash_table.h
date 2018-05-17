#pragma once
#include<iostream>
class hash_table
{
public:	
	//key & change hash insert and remove note: need key member var for node and need a another search for key in public bool

	hash_table(size_t capacity = 5);
	~hash_table();
	hash_table(const hash_table& source);
	hash_table& operator=(const hash_table& source);
	void insert(int entry);
	void remove(int entry);
	friend std::ostream& operator<<(std::ostream& out, const hash_table& p);
	
private:
	size_t capacity;
	class ll_node{
	public:
		ll_node(int data, ll_node *next = nullptr) {
			ll_node::data = data;
			ll_node::next = next;
		}
		int data;
		ll_node*next;		
	};
	ll_node * *data;
	size_t hash(int data);
	ll_node *search(size_t index, int entry);
	size_t full_positions;
	void rehash();
	void clear();
	void copy(const hash_table & source);
	

};

std::ostream& operator<<(std::ostream& out, const hash_table& p);


