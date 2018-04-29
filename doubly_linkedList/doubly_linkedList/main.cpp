#include<iostream>
#include"doubly_linkedList.h"
using sfils_csc212::doubly_linkedList;
using namespace std;

//Explain why you need iterator for encapsulated linkedlist 
/*
An iterator is needed for encapsulated linkedlist but the client dont have access to the nodes
and the iterator allow us to iterate a linkedList without breaking encapulation.
Also, iterator is more efficient than creating a getter function like get_data(index) to iterate
Because the get_data(index) function requires searching which is O(n) and an iterator just moves to the next node.
*/

int main() {

	doubly_linkedList a;
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(2);
	a.insert(2);
	a.insert(2);
	a.insert(2);
	a.insert(2);
	a.insert(9,5);
	
	for (doubly_linkedList::iterator i = a.begin(); i!= a.end(); ++i ) {
		*i = 0;
	}

	a.remove(2);
	
	//a.remove();
	doubly_linkedList b;
	b= a;
	b.insert(2);

	cout << a << endl;
	//cout << b<< endl;



	return 0;
}