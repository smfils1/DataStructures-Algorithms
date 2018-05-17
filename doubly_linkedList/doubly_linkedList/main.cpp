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

	return 0;
}