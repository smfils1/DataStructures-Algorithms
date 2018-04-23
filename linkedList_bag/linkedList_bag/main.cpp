#include <iostream>
#include"linkedList_bag.h"
using sfils_csc212::linkedList_bag;
using namespace std;

int main()
	

	linkedList_bag a;
	a.insert(9,0);
	a.insert(8);
	a.insert(7);
	a.insert(6);
	a.insert(5);
	cout << a << endl;
	a.remove(2);
	cout << a << endl;
	a.insert(0, 2);
	cout << a << endl;




	return 0;
}