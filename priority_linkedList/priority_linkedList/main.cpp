#include<iostream>
#include"priority_linkedlist.h"
using sfils_csc212::priority_linkedlist;
using namespace std;

//Explain why you should not have iterator for the priority_linkedlist.
/*
We should not have iterator for the priority_linkedlist 
because we one care about what first out which this the head(the return value of top())
the other data of the other nodes is unnessarity information
*/

//Calculate the running time of all three functions of priority_linkedlist.
/*
Push : O(n) because of sorting
Pop & Top : O(1) because we just remove at head.
*/


int main() {

	priority_linkedlist a;
	
	a.push(1);
	a.push(2);
	
	a.push(0);
	a.push(4);
	a.push(5);

	a.push(2);
	a.push(4);

	a.push(3);
	a.push(1);
	a.push(5); a.push(2);
	a.push(4);

	a.push(3);
	a.push(1);
	a.push(-100);
	a.push(100);
	a.pop();

	cout << a << endl;





	return 0;
}