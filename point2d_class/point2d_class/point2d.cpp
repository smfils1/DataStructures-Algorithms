#include<iostream>
#include"point2d.h"
using std::cout;
using std::endl;


point2d::point2d()
{
	x = 0;
	y = 0;
}
point2d::point2d(double x, double y)
{
	point2d::x = x;
	point2d::y = y;
}

double point2d::get_x() const {
	return x;
}

double point2d::get_y() const {
	return y;
}

void point2d::shift(double dx, double dy) {
	x += dx;
	y += dy;
}

double point2d::distance(point2d &pt2) {
	return sqrt(pow(x_distance(pt2), 2) + pow(y_distance(pt2), 2));
}
void point2d::print() const {
	cout << '(' << x << ',' << y << ')' << endl;
}


double point2d::x_distance(point2d &pt2) {
	return pt2.get_x() - x;
}
double point2d::y_distance(point2d &pt2) {
	return pt2.get_y() - y;
}

double x;
double y;
