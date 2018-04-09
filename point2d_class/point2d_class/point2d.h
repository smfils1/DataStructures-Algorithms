#pragma once

#include<iostream>

namespace sfils_csc212 {
	class point2d {

	public:
		point2d(double x = 0, double y = 0);
		double get_x() const;
		double get_y() const; 
		void set_x(double x);
		void set_y(double y);
		void shift(double dx, double dy);
		double distance(point2d &pt2);
		void print() const;
		friend point2d operator+(const point2d& p1, const point2d& p2);
	private:
		double x;
		double y;
		double x_distance(point2d &pt2);
		double y_distance(point2d &pt2);

	};
	std::ostream& operator<<(std::ostream& out, const point2d& p2);
	std::istream& operator>>(std::istream& in, point2d& p2);
	point2d operator+(const point2d& p1, const point2d& p2);
	 
}

