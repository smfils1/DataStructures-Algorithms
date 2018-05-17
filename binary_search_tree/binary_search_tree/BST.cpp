#include "BST.h"
#include<cassert>


BST::BST()
{
	root = nullptr;
}

BST::BST(const BST & source)
{
	clear(root);
	copy(source.root);
}

BST & BST::operator=(const BST & source)
{
	clear(root);
	copy(source.root);
	return *this;
}


BST::~BST()
{
	clear(root);
}

void BST::insert(int data)
{
	insert_helper(data, root);
}

void BST::insert_helper(int data, node *& node)
{
	if (node == nullptr) {
		node = new BST::node(data);
	}
	else if (data <= node->data) {
		insert_helper(data, node->left);
	}
	else {
		insert_helper(data, node->right);
	}
}

bool BST::search(int data)
{
	return search_helper(data, root);
}

bool BST::search_helper(int data, node * node)
{
	if (node == nullptr) {
		return false;
	}
	else if (data == node->data) {
		return true;
	}
	else if (data < node->data) {
		return search_helper(data, node->left);
	}
	else {
		return search_helper(data, node->right);
	}
}


int  BST::get_min(node* node) const
{	
	assert(node != nullptr);
	
	if (node->left == nullptr) {
		return node->data;
	}
	get_min(node->left);
}


void BST::remove(int data)
{
	remove_helper(data, root);
}

void BST::remove_helper(int data, node *& node)
{
	if (node == nullptr) {
		return;
	}
	if (data < node->data) {
		remove_helper(data, node->left);
	}
	else if (data > node->data) {
		remove_helper(data, node->right);
	}
	else {
		BST::node* trash = nullptr;
		if (node->left == nullptr && node->right == nullptr) {
			trash = node;
			node = nullptr;
			delete trash;
		}
		else if (node->left == nullptr) {
			trash = node;
			node = node->right;
			delete trash;
		}
		else if (node->right == nullptr) {
			trash = node;
			node = node->left;
			delete trash;
		}
		else
		{
			node->data = get_min(node->right);
			remove_helper(node->data, node->right);
		}

	}
}

void BST::print(node* node) const
{
	if (node == nullptr) {
		return;
	}
	else {
		print(node->left);
		std::cout << node->data << std::endl;
		print(node->right);
	}
}

void BST::copy(node * node)
{//do i need to clear
	if (node == nullptr) {
		return;
	}
	else {
		insert(node->data);
		copy(node->left);		
		copy(node->right);
	}
}

void BST::clear(node *& node)
{	
	if (node == nullptr) {
		return;
	}
	else {		
		clear(node->left);
		clear(node->right);
		delete node;
		node = nullptr;
	}
}

std::ostream& operator<<(std::ostream & out, const BST& source)
{
	source.print(source.root);
	return out;
}

