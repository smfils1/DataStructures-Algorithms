#include"hash_table.h"
using namespace std;

int main() {

	hash_table a(5);
	
	a.insert(5);
	a.insert(4);
	a.insert(100);
	a.insert(3);
	a.insert(2);

	
	hash_table b(10);
	b = a;
	
	a.insert(5);
	a.insert(4);
	a.insert(100);
	a.insert(3);
	a.insert(2);

	a.remove(4);
	cout << b;
	
	return 0;
}