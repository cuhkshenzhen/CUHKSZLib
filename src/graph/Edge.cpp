#include "graph/Edge.h"

namespace cuhksz {

int Edge::nextEdgeID = 0;

Edge::Edge(Vertex* from, Vertex* to) : from(from), to(to) {
    val = 0;
    use = true;
    id = Edge::nextEdgeID ++;
}

Edge::Edge(Vertex* from, Vertex* to, int val) : from(from), to(to), val(val) {
    use = true;
    id = Edge::nextEdgeID ++;
}

Edge::Edge(const Edge& src) {
    from = src.from;
    to = src.to;
    val = src.val;
    use = src.use;
    id = Edge::nextEdgeID ++;
}

Edge::~Edge() { }

Edge& Edge::operator= (const Edge & src) {
    from = src.from;
    to = src.to;
    val = src.val;
    use = src.use;
}

bool Edge::operator== (const Edge& other) const {
    return id == other.id;
}

bool Edge::operator!= (const Edge& other) const {
    return !(*this == other);
}

bool Edge::operator< (const Edge& other) const {
    return val < other.val;
}

}	// namespace cuhksz
