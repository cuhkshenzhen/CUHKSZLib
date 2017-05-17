#ifndef CUHKSZ_GEOMETRY_POINT
#define CUHKSZ_GEOMETRY_POINT

#include <algorithm>
#include <cmath>
#include <iostream>

namespace cuhksz {

#define EPS 1e-6

template <int N = 2>
class Point {
 public:
  Point() { memset(element, 0, N * sizeof(double)); }

  explicit Point(double const x) {
    element[0] = x;
    static_assert(N == 1, "X constructor only usable in 1D");
  }

  Point(double const x, double const y) {
    element[0] = x, element[1] = y;
    static_assert(N == 2, "XY constructor only usable in 2D");
  }

  Point(double const x, double const y, double const z) {
    element[0] = x, element[1] = y, element[2] = z;
    static_assert(N == 3, "XYZ constructor only usable in 3D");
  }

  ~Point() {}

  // element can be change directly
  double &operator[](int const &index) const { return element[index]; }

  // TODO: what about init a null Point then assign to element[i] +
  // other.element[i]
  Point &operator+(Point const &other) const {
    Point ret(this);
    for (int i = 0; i < N; i++) ret.element[i] += other.element[i];
    return ret;
  }

  Point &operator-(Point const &other) const {
    Point ret(this);
    for (int i = 0; i < N; i++) ret.element[i] -= other.element[i];
    return ret;
  }

  Point &operator+=(Point const &other) {
    for (int i = 0; i < N; i++) element[i] += other.element[i];
    return *this;
  }

  Point &operator-=(Point const &other) {
    for (int i = 0; i < N; i++) element[i] -= other.element[i];
    return *this;
  }

  // dot product
  double operator*(Point const &other) const {
    double ret = 0.0;
    for (int i = 0; i < N; i++) ret += element[i] * other.element[i];
    return ret;
  }

  Point &operator*(double const &constant) const {
    Point ret(this);
    for (int i = 0; i < N; i++) ret.element[i] *= constant;
    return ret;
  }

  friend Point operator*(double const &constant, Point const &self) {
    return self * constant;
  }

  Point &operator*=(double const &constant) {
    for (int i = 0; i < N; i++) element[i] *= constant;
    return *this;
  }

  Point &operator/(double const &constant) const {
    Point ret(this);
    for (int i = 0; i < N; i++) ret.element[i] /= constant;
    return ret;
  }

  Point &operator/=(double const &constant) {
    for (int i = 0; i < N; i++) element[i] /= constant;
    return *this;
  }

  bool operator==(Point const &other) const {
    for (int i = 0; i < N; i++)
      if (fabs(element[i] - other.element[i]) < EPS) return false;
    return true;
  }

  bool operator!=(Point const &other) const { return !(*this == other); }

  bool operator<(Point const &other) const {
    for (int i = 0; i < N; i++)
      if (element[i] != other.element[i]) return element[i] < other.element[i];
    return false;
  }

  bool operator<=(Point const &other) const {
    for (int i = 0; i < N; i++)
      if (element[i] != other.element[i]) return element[i] < other.element[i];
    return true;
  }

  bool operator>(Point const &other) const {
    for (int i = 0; i < N; i++)
      if (element[i] != other.element[i]) return element[i] > other.element[i];
    return false;
  }

  bool operator>=(Point const &other) const {
    for (int i = 0; i < N; i++)
      if (element[i] != other.element[i]) return element[i] > other.element[i];
    return true;
  }

  // cross product
  double operator^(Point const other) const {
    static_assert(N == 2, "cross product only apply to 2D");
    return element[0] * other.element[1] - element[1] * other.element[0];
  }

  friend std::ostream &operator<<(std::ostream &os, Point const self) {
    os << "(" << self.element[0];
    for (int i = 1; i < N; i++) os << ", " << self.element[i];
    return os << ")";
  }

  double len() {
    double ret = 0.0;
    for (int i = 0; i < N; i++) ret += element[i] * element[i];
    return sqrt(ret);
  }

 private:
  double element[N];  // coordinates
};

}  // namespace cuhksz

#endif  // CUHKSZ_GEOMETRY_POINT
