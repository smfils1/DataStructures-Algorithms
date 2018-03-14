#include<iostream>
#include<cmath>
using namespace std;

//TODO: Create .h & implemention file
//TODO: Create namespace

class point2d {
public:
	point2d() {
		x = 0;
		y = 0;
	}
	point2d(double x, double y) {
		point2d::x = x;
		point2d::y = y;
	}

	double get_x() const {
		return x;
	}

	double get_y() const {
		return y;
	}

	void shift(double dx, double dy) {
		x += dx;
		y += dy;
	}

	double distance(point2d &pt2) {
		return sqrt(pow(x_distance(pt2), 2) + pow(y_distance(pt2), 2));
	}
	void print() const {
		cout << '(' << x << ',' << y << ')' << endl;
	}

private:
	double x_distance(point2d &pt2) {
		return pt2.get_x() - x;
	}
	double y_distance(point2d &pt2) {
		return pt2.get_y() - y;
	}

	double x;
	double y;
};

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