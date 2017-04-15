#include "geometry/Line.h"

namespace cuhksz {

Line::Line(Point<2> A, Vector<2> v) : A(A), v(v) { }

// Line::Line(Point<2> A, Point<2> B) : A(A) {
//     v = B - A;
// }

Line::Line(const Line& src) {
    A = src.A;
    v = src.v;
}

Line::~Line() { }

Line& Line::operator= (const Line& src) {
    A = src.A;
    v = src.v;
    return *this;
}

Point<2> getIntersection(const Line& l1, const Line& l2) {
    Vector<2> u = l1.A - l2.A;
    double t = cross(l2.v, u) / cross(l1.v, l2.v);
    return l1.A + l1.v * t;
}

}
