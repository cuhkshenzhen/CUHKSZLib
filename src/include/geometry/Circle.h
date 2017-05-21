#ifndef CUHKSZ_GEOMETRY_CIRCLE
#define CUHKSZ_GEOMETRY_CIRCLE

#include <cmath>
#include "geometry/Point.h"

namespace cuhksz {

#define PI 3.1415926

class Circle {
 public:
  Circle() : O(Point<2>(0, 0)), r(1.0) {}
  explicit Circle(double r) : O(Point<2>(0, 0)), r(r) {}
  explicit Circle(Point<2> O) : O(O), r(1.0) {}
  Circle(Point<2> O, double r) : O(O), r(r) {}
  ~Circle() {}

  double getArea() { return PI * r * r; }

  double getPerimeter() { return 2.0 * PI * r; }

  Point<2> getPoint(double rad) {
    return O + GVector<2>(r * std::cos(rad), r * std::sin(rad));
  }

 private:
  Point<2> O;
  double r;
};

#undef PI

}  // namespace cuhksz

#endif  // CUHKSZ_GEOMETRY_CIRCLE
