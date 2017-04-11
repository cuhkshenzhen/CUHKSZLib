#include "graph/Vertex.h"

namespace cuhksz {

int Vertex::nextVertexID = 0;

Vertex::Vertex() {
    val = 0;
    use = true;
    id = Vertex::nextVertexID ++;
    inEdges.clear();
    outEdges.clear();
}

Vertex::Vertex(int val) : val(val) {
    use = true;
    id = Vertex::nextVertexID ++;
    inEdges.clear();
    outEdges.clear();
}

Vertex::Vertex(const Vertex& src) {
    val = src.val;
    use = src.use;
    id = Vertex::nextVertexID ++;
    inEdges.clear();
    outEdges.clear();
    for (list<Edge*>::iterator it = src.inEdges.begin(); it != src.inEdges.end(); ++ it)
        inEdges.push_back(*it);
    for (list<Edge*>::iterator it = src.outEdges.begin(); it != src.outEdges.end(); ++ it)
        outEdges.push_back(*it);
}

Vertex::~Vertex() {
    edges.clear();
    for (list<Edge*>::iterator it = inEdges.begin(); it != inEdges.end(); ++ it)
        if (*it != NULL)
            delete *it;
}

Vertex& Vertex::operator= (const Vertex& src) {
    val = src.val;
    use = src.use;
    inEdges.clear();
    outEdges.clear();
    for (list<Edge*>::iterator it = src.inEdges.begin(); it != src.inEdges.end(); ++ it)
        inEdges.push_back(*it);
    for (list<Edge*>::iterator it = src.outEdges.begin(); it != src.outEdges.end(); ++ it)
        outEdges.push_back(*it);
}

bool Vertex::operator< (const Vertex& src) const {
    return val < src.val;
}

void addEdge(Vertex& to, int val) {
    Edge* e = new Edge(this, &to, val);
    outEdges.push_back(e);
    to.inEdges.push_back(e);
}



}	// namespace cuhksz
