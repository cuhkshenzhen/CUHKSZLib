#ifndef CUHKSZ_GEOMETRY_POINT
#define CUHKSZ_GEOMETRY_POINT

namespace cuhksz {

template <typename T>
class Point {
private:
	T element[];	// coordinates

};

typedef Point Vector;	// same class as Point

}	// namespace cuhksz


#endif // CUHKSZ_GEOMETRY_POINT
