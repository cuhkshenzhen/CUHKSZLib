#include "graph/Vertex.h"
#include "graph/Edge.h"

namespace cuhksz {

int Vertex::nextVertexID = 0;

Vertex::Vertex() {
    value = 0;
    use = true;
    id = Vertex::nextVertexID ++;
    inEdges.clear();
    outEdges.clear();
}

Vertex::Vertex(int value) : value(value) {
    use = true;
    id = Vertex::nextVertexID ++;
    inEdges.clear();
    outEdges.clear();
}

Vertex::Vertex(const Vertex& src) {
    value = src.value;
    use = src.use;
    id = Vertex::nextVertexID ++;
    inEdges.clear();
    outEdges.clear();
    for (std::list<Edge*>::const_iterator it = src.inEdges.begin(); it != src.inEdges.end(); ++ it)
        inEdges.push_back(*it);
    for (std::list<Edge*>::const_iterator it = src.outEdges.begin(); it != src.outEdges.end(); ++ it)
        outEdges.push_back(*it);
}

Vertex::~Vertex() {
    for (std::list<Edge*>::iterator it = inEdges.begin(); it != inEdges.end(); ++ it)
        if (*it != nullptr)
            delete *it;
    for (std::list<Edge*>::iterator it = outEdges.begin(); it != outEdges.end(); ++ it)
        if (*it != nullptr)
            delete *it;
    inEdges.clear();
    outEdges.clear();
}

Vertex& Vertex::operator= (const Vertex& src) {
    value = src.value;
    use = src.use;
    inEdges.clear();
    outEdges.clear();
    for (std::list<Edge*>::const_iterator it = src.inEdges.begin(); it != src.inEdges.end(); ++ it)
        inEdges.push_back(*it);
    for (std::list<Edge*>::const_iterator it = src.outEdges.begin(); it != src.outEdges.end(); ++ it)
        outEdges.push_back(*it);
    return *this;
}

bool Vertex::operator== (const Vertex& src) const {
    return id == src.id;
}

bool Vertex::operator!= (const Vertex& src) const {
    return !(*this == src);
}

bool Vertex::operator< (const Vertex& src) const {
    return value < src.value;
}

void Vertex::addEdge(Vertex& to, int value) {
    Edge* e = new Edge(this, &to, value);
    outEdges.push_back(e);
    to.inEdges.push_back(e);
}



}	// namespace cuhksz
