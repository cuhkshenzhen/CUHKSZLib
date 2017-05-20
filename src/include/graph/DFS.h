#ifndef CUHKSZ_GRAPH_DFS
#define CUHKSZ_GRAPH_DFS

namespace cuhksz {

#include <functional>
#include <set>

#include "graph/Vertex.h"

class DFS : public std::unary_function<Vertex, void> {
public:
    void operator() (Vertex& v) {
        vis.insert(v);
        for (Edge* e : v.outEdges) {
            Vertex& next = *e.to;
            if (vis.count(next) == 0)
                this->operator(next);
        }
    }
private:
    set<Vertex> vis;
};


}


#endif // CUHKSZ_GRAPH_DFS
