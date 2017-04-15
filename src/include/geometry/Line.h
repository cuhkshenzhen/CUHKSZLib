#ifndef CUHKSZ_GEOMETRY_LINE
#define CUHKSZ_GEOMETRY_LINE

#include "geometry/Point.h"

namespace cuhksz {

class Line {
public:
    Line(Point<2> A, Vector<2> v);
    // Line(Point<2> A, Point<2> B);
    Line(const Line& src);
    ~Line();

    Line& operator= (const Line& src);

    double len() { return v.len(); }

    friend Point<2> getIntersection(const Line& l1, const Line& l2);

private:
    Point<2> A;
    Vector<2> v;
};

}

#endif // CUHKSZ_GEOMETRY_LINE
