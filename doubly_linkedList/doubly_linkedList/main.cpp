#include<iostream>
#include"doubly_linkedList.h"
using sfils_csc212::doubly_linkedList;
using namespace std;



int main() {

	doubly_linkedList a;
	a.insert(1);
	a.insert(2);
	a.insert(2);
	a.insert(2);
	a.insert(2);
	a.insert(2);
	a.insert(2);
	a.insert(2);
	a.insert(9,5);
	
	/*for (iterator i = a.begin(); i != a.end(), ++i) {
		cout << *i << endl;
	}
*/
	//a.remove(1);
	//a.remove();
	doubly_linkedList b;
	b= a;
	b.insert(3);

	cout << a << endl;
	//cout << b<< endl;



	return 0;
}