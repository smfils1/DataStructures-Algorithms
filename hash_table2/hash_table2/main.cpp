#include"hash_table2.h"
using sfils_csc212::hash_table2;
using namespace std;

int main() {

	hash_table2 a(5);
	//a.insert(25);
	//a.insert(15);
	a.insert(30,1);
	a.insert(5,2);
	a.insert(0,3);
	a.insert(35,4);
	a.insert(50,5);	
	a.insert(10,6); 
	a.insert(22, 7);
	a.insert(25,7);
	a.insert(85,8);
	a.insert(20,9); 
	//a.insert(5,10);
	//a.insert(0,11);
	a.insert(9, 20);
	a.insert(11,20);
	//.remove(9);
	hash_table2 b= a;
	//a.remove(5);
	//a.insert(8);
	/*a.insert(1);
	
	
	a.insert(3);
	a.insert(9);
	a.insert(1);
	a.insert(8);
	a.insert(-2);	
	a.insert(6);*/	
//a.~hash_table2();
	 
		b.insert(58, 0);
		a.insert(105, 0);
		a.insert(110, 0);
		a.insert(90, 0);
		a.insert(900,0);
		
		/*a.remove(105);
		a.remove(110);
		a.remove(9);
		a.remove(50);
		a.remove(30);*/
		/*a.remove(25);
		a.insert(85, 8);*/
		a.remove(9);
		cout << a;
	return 0;

}