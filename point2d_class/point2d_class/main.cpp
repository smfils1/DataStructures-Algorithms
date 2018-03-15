#include<iostream>
#include<cmath>
#include"point2d.h"
using namespace std;

//TODO: Create namespace

int main() {
	point2d p1;
	p1.print();
	point2d p2(2, 3);
	p2.print();
	p2.shift(1, 1);
	p2.print();
	cout << p1.distance(p2) << endl;


	system("pause");
	return 0;
}