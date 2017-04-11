#ifndef CUHKSZ_GRAPH_EDGE
#define CUHKSZ_GRAPH_EDGE

#include "graph/Vertex.h"

namespace cuhksz {

class Edge {
public:
    Edge(Vertex* from, Vertex* to);
    Edge(Vertex* from, Vertex* to, int val);
    Edge(const Edge & src);
    ~Edge();

    Vertex* getFrom() { return from; }
    Vertex* getTo() { return to; }
    int getVal() { return val; }
    void setVal(int newVal) { val = newVal; }
    bool isValid() { return use; }
    void setValid() { use = true; }
    void setInvalid() { use = false; }
    int getID() { return id; }

    Edge& operator= (const Edge & src);
    bool operator== (const Edge& other) const;
    bool operator!= (const Edge& other) const;

private:
    Vertex* from;
    Vertex* to;
    int val;
    bool use;
    int id;
    static int nextEdgeID;
};

}	// namespace cuhksz


#endif // CUHKSZ_GRAPH_EDGE
