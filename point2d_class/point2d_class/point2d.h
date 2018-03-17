#pragma once

namespace sfils_csc212 {
	class point2d {

	public:
		point2d();
		point2d(double x, double y);
		double get_x() const;
		double get_y() const;
		void shift(double dx, double dy);
		double distance(point2d &pt2);
		void print() const;

	private:
		double x;
		double y;
		double x_distance(point2d &pt2);
		double y_distance(point2d &pt2);

	};
}

