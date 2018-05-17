#pragma once
#include<iostream>

class BST
{
private:
	class node;
public:
	BST();
	BST(const BST& source);
	BST& operator=(const BST& source);
	~BST();
	void insert(int data);
	void remove(int data);
	bool search(int data);
	

	

	friend std::ostream& operator<<(std::ostream& out, const BST& source);

private:
	class node {
	public:
		node(int data, node* left=nullptr, node* right = nullptr) {
			node::data = data;
			node::left = left;
			node::right = right;
		}
		int data;
		node * left;
		node * right;
	};
	node* root;
	void insert_helper(int data, node*& node);
	void remove_helper(int data, node*& node);
	bool search_helper(int data, node * node);
	int get_min(node * node) const;
	void print(node* node) const;
	void copy(node* node);
	void clear(node*& node);
	
};

std::ostream& operator<<(std::ostream& out, const BST& source);

