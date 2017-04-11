#ifndef CUHKSZ_GRAPH_VERTEX
#define CUHKSZ_GRAPH_VERTEX

namespace cuhksz {

class Edge;

class Vertex {
private:
    Edge* e;
    int val;
};

}	// namespace cuhksz


#endif // CUHKSZ_GRAPH_VERTEX
