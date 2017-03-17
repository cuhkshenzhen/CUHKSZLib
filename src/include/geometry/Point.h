#ifndef CUHKSZ_GEOMETRY_POINT
#define CUHKSZ_GEOMETRY_POINT

#include <algorithm>
#include <iostream>
#include <cmath>

namespace cuhksz {

template <int N=2>
class Point {
public:
	Point() {
		memset(element, 0, N * sizeof(double));
	}

	explicit Point(double x) : element[0](x) {
		static_assert(N == 1, "X constructor only usable in 1D");
	}

	Point(double x, double y) : element[0](x), element[1](y) {
		static_assert(N == 2, "XY constructor only usable in 2D");
	}

	Point(double x, double y, double z) : element[0](x), element[1](y), element[2](z) {
		static_assert(N == 3, "XYZ constructor only usable in 3D");
	}

	~Point() { }

	// element can be change directly
	double& operator[](int const &index) const {
		return element[index];
	}

	// TODO: what about init a null Point then assign to element[i] + other.element[i]
	Point& operator+(Point const &other) const {
		Point ret(this);
		for (int i = 0; i < N; i ++)
			ret.element[i] += other.element[i];
		return ret;
	}

	Point& operator-(Point const &other) const {
		Point ret(this);
		for (int i = 0; i < N; i ++)
			ret.element[i] -= other.element[i];
		return ret;
	}

	void operator+=(Point const &other) const {
		for (int i = 0; i < N; i ++)
			element[i] += other.element[i];
	}

	void operator-=(Point const &other) const {
		for (int i = 0; i < N; i ++)
			element[i] -= other.element[i];
	}

	// dot product
	double operator*(Point const &other) const {
		double ret = 0.0;
		for (int i = 0; i < N; i ++)
			ret += element[i] * other.element[i];
		return ret;
	}

	Point& operator*(double const &constant) const {
		Point ret(this);
		for (int i = 0; i < N; i ++)
			ret.element[i] *= constant;
		return ret;
	}

	void operator*=(double const &constant) const {
		for (int i = 0; i < N; i ++)
			element[i] *= constant;
	}

	Point& operator/(double const &constant) const {
		Point ret(this);
		for (int i = 0; i < N; i ++)
			ret.element[i] /= constant;
		return ret;
	}

	void operator/=(double const &constant) const {
		for (int i = 0; i < N; i ++)
			element[i] /= constant;
	}

	bool operator==(Point const &other) const {
		for (int i = 0; i < N; i ++)
			if (element[i] != other.element[i])
				return false;
		return true;
	}

	bool operator!=(Point const &other) const {
		for (int i = 0; i < N; i ++)
			if (element[i] != other.element[i])
				return true;
		return false;
	}

	bool operator<(Point const &other) const {
		for (int i = 0; i < N; i ++)
			if (element[i] != other.element[i])
				return element[i] < other.element[i];
		return false;
	}

	bool operator<=(Point const &other) const {
		for (int i = 0; i < N; i ++)
			if (element[i] != other.element[i])
				return element[i] < other.element[i];
		return true;
	}

	bool operator>(Point const &other) const {
		for (int i = 0; i < N; i ++)
			if (element[i] != other.element[i])
				return element[i] > other.element[i];
		return false;
	}

	bool operator>=(Point const &other) const {
		for (int i = 0; i < N; i ++)
			if (element[i] != other.element[i])
				return element[i] > other.element[i];
		return true;
	}



	// cross product
	double operator^(Point const other) const {
		static_assert(N == 2, "cross product only apply to 2D");
		return element[0] * other.element[1] - element[1] * other.element[0];
	}


	friend ostream& operator<<(ostream& os, Point& const curPoint) {
		os << "(" << curPoint.element[0];
		for (int i = 1; i < N; i ++)
			os << ", " << curPoint.element[i];
		return os << ")";
	}

	friend istream& operator>>(istream& is, Point& const curPoint) {
		for (int i = 0; i < N; i ++)
			is >> curPoint.element[i];
		return is;
	}

	double len() {
		double ret = 0.0;
		for (int i = 0; i < N; i ++)
			ret += element[i] * element[i];
		return sqrt(ret);
	}

private:
	double element[N];	// coordinates
};

typedef Point Vector;	// same class as Point

}	// namespace cuhksz


#endif // CUHKSZ_GEOMETRY_POINT
