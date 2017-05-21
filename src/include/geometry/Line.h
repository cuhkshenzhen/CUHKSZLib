#ifndef CUHKSZ_GEOMETRY_LINE
#define CUHKSZ_GEOMETRY_LINE

#include "geometry/Point.h"

namespace cuhksz {

class Line {
 public:
  Line(Point<2> A, GVector<2> v);
  Line(const Line& src);
  ~Line();

  Line& operator=(const Line& src);

  double len() { return v.len(); }

  friend Point<2> getIntersection(const Line& l1, const Line& l2);
  friend double disToLine(Point<2> P, Line l);
  friend double disToSegment(Point<2> P, Line l);

 private:
  Point<2> A;
  GVector<2> v;
};

}  // namespace cuhksz

#endif  // CUHKSZ_GEOMETRY_LINE
