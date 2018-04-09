#include"point2d.h"
#include<iostream>
using std::cout;
using std::endl;
using std::ostream;
using std::istream;

namespace sfils_csc212 {
	
	point2d::point2d(double x, double y){
		point2d::x = x;
		point2d::y = y;
	}

	inline double point2d::get_x() const {
		return x;
	}

	inline double point2d::get_y() const {
		return y;
	}

	void point2d::set_x(double x){
		point2d::x = x;
		

	}

	void point2d::set_y(double y){
		
		point2d::y = y;

	}
	

	void point2d::shift(double dx, double dy) {
		x += dx;
		y += dy;
	}

	inline double point2d::distance(point2d &pt2) {
		return sqrt(pow(x_distance(pt2), 2) + pow(y_distance(pt2), 2));
	}

	void point2d::print() const {
		cout << '(' << x << ',' << y << ')' << endl;
	}

	inline double point2d::x_distance(point2d &pt2) {
		return pt2.get_x() - x;
	}

	inline double point2d::y_distance(point2d &pt2) {
		return pt2.get_y() - y;
	}

	point2d operator+(const point2d& p1, const point2d& p2) {
		point2d sum = point2d(p1.get_x() + p2.get_x(), p1.get_y() + p2.get_y());
		return sum;

	}

	ostream &operator<< (ostream &out, const point2d &number) {
		out << number.get_x() << " " << number.get_y() << endl;
		return out;
	}
	istream& operator>> (istream& in, point2d& number) {
		int a, b;
		in >> a;
		in >> b;
		number.set_x(a);
		number.set_y(b);
		return in;
	}
}