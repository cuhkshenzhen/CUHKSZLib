#include <cmath>

#include "geometry/Line.h"

#define EPS 1e-6

namespace {

int dcmp(double x) {
  if (std::fabs(x) < EPS) return 0;
  return x > 0 ? 1 : -1;
}

}  // namespace

namespace cuhksz {

Line::Line(Point<2> A, GVector<2> v) : A(A), v(v) {}

Line::Line(const Line& src) {
  A = src.A;
  v = src.v;
}

Line::~Line() {}

Line& Line::operator=(const Line& src) {
  A = src.A;
  v = src.v;
  return *this;
}

Point<2> getIntersection(const Line& l1, const Line& l2) {
  GVector<2> u = l1.A - l2.A;
  double t = cross(l2.v, u) / cross(l1.v, l2.v);
  return l1.A + l1.v * t;
}

double disToLine(Point<2> P, Line l) {
  GVector<2> v1 = l.v, v2 = P - l.A;
  return std::fabs(cross(v1, v2) / v1.len());
}

double disToSegment(Point<2> P, Line l) {
  GVector<2> v1 = l.v, v2 = P - l.A, v3 = P - l.A - l.v;
  if (dcmp(v1 * v2) < 0)
    return v2.len();
  else if (dcmp(v1 * v3) > 0)
    return v3.len();
  else
    return std::fabs(cross(v1, v2) / v1.len());
}

}  // namespace cuhksz

#undef EPS
