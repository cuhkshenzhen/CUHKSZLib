#ifndef CUHKSZ_GEOMETRY_POINT
#define CUHKSZ_GEOMETRY_POINT

#include <algorithm>
#include <iostream>
#include <cmath>

namespace cuhksz {

#define EPS 1e-6

template <int N=2>
class Point {
public:
	Point() {
		memset(elem, 0, N * sizeof(double));
	}

	explicit Point(double const x) {
		elem[0] = x;
		static_assert(N == 1, "X constructor only usable in 1D");
	}

	Point(double const x, double const y) {
		elem[0] = x, elem[1] = y;
		static_assert(N == 2, "XY constructor only usable in 2D");
	}

	Point(double const x, double const y, double const z) {
		elem[0] = x, elem[1] = y, elem[2] = z;
		static_assert(N == 3, "XYZ constructor only usable in 3D");
	}

    Point(const Point& src) {
        memcpy(elem, src.elem, N * sizeof(double));
    }

	~Point() { }

    Point& operator=(const Point& src) {
        memcpy(elem, src.elem, N * sizeof(double));
        return *this;
    }

	// elem can be change directly
	double& operator[](int const &index) const {
		return elem[index];
	}

	// TODO: what about init a null Point then assign to elem[i] + other.elem[i]
	Point& operator+(Point const &other) const {
		Point& ret = *(new Point);
		for (int i = 0; i < N; i ++)
			ret.elem[i] = elem[i] + other.elem[i];
		return ret;
	}

	Point& operator-(Point const &other) const {
		Point& ret = *(new Point);
		for (int i = 0; i < N; i ++)
			ret.elem[i] = elem[i] - other.elem[i];
		return ret;
	}

	Point& operator+=(Point const &other) {
		for (int i = 0; i < N; i ++)
			elem[i] += other.elem[i];
        return *this;
	}

	Point& operator-=(Point const &other) {
		for (int i = 0; i < N; i ++)
			elem[i] -= other.elem[i];
        return *this;
	}

	// dot product
	double operator*(Point const &other) const {
		double ret = 0.0;
		for (int i = 0; i < N; i ++)
			ret += elem[i] * other.elem[i];
		return ret;
	}

	Point& operator*(double const &constant) const {
		Point& ret = *(new Point);
		for (int i = 0; i < N; i ++)
			ret.elem[i] = elem[i] * constant;
		return ret;
	}

    friend Point operator*(double const &constant, Point const &self) {
        return self * constant;
    }

	Point& operator*=(double const &constant) {
		for (int i = 0; i < N; i ++)
			elem[i] *= constant;
        return *this;
	}

	Point& operator/(double const &constant) const {
		Point& ret = *(new Point);
		for (int i = 0; i < N; i ++)
			ret.elem[i] = elem[i] / constant;
		return ret;
	}

	Point& operator/=(double const &constant) {
		for (int i = 0; i < N; i ++)
			elem[i] /= constant;
        return *this;
	}

	bool operator==(Point const &other) const {
		for (int i = 0; i < N; i ++)
			if (fabs(elem[i] - other.elem[i]) < EPS)
				return false;
		return true;
	}

	bool operator!=(Point const &other) const {
		return !(*this == other);
	}

	bool operator<(Point const &other) const {
		for (int i = 0; i < N; i ++)
			if (elem[i] != other.elem[i])
				return elem[i] < other.elem[i];
		return false;
	}

	bool operator<=(Point const &other) const {
		for (int i = 0; i < N; i ++)
			if (elem[i] != other.elem[i])
				return elem[i] < other.elem[i];
		return true;
	}

	bool operator>(Point const &other) const {
		for (int i = 0; i < N; i ++)
			if (elem[i] != other.elem[i])
				return elem[i] > other.elem[i];
		return false;
	}

	bool operator>=(Point const &other) const {
		for (int i = 0; i < N; i ++)
			if (elem[i] != other.elem[i])
				return elem[i] > other.elem[i];
		return true;
	}

	friend std::ostream& operator<<(std::ostream& os, Point const self) {
		os << "(" << self.elem[0];
		for (int i = 1; i < N; i ++)
			os << ", " << self.elem[i];
		return os << ")";
	}

    // cross product
	friend double cross(const Point& v, const Point& w) {
		static_assert(N == 2, "cross product only apply to 2D");
		return v.elem[0] * w.elem[1] - v.elem[1] * w.elem[0];
	}

	double len() {
		double ret = 0.0;
		for (int i = 0; i < N; i ++)
			ret += elem[i] * elem[i];
		return sqrt(ret);
	}

    void normalize() {
        double l = len();
        for (int i = 0; i < N; i ++)
            elem[i] /= l;
    }

private:
	double elem[N];	// coordinates
};

#define Vector Point

}	// namespace cuhksz


#endif // CUHKSZ_GEOMETRY_POINT
