#ifndef CUHKSZ_GRAPH_EDGE
#define CUHKSZ_GRAPH_EDGE

#include "graph/Vertex.h"

namespace cuhksz {

class Edge {
public:
    Edge(Vertex* from, Vertex* to, int val=0);
    Edge(const Edge & src);
    ~Edge();

    Vertex* getFrom() { return from; }
    Vertex* getTo() { return to; }
    Vertex* from() { return from; }
    Vertex* to() { return to; }
    int getVal() { return val; }
    int val() { return val; }
    void setVal(int newVal) { val = newVal; }
    bool isValid() { return use; }
    void setValid() { use = true; }
    void setInvalid() { use = false; }
    int getID() { return id; }

    Edge& operator= (const Edge & src);
    bool operator== (const Edge& other) const; // for multipath
    bool operator!= (const Edge& other) const;
    bool operator< (const Edge& other) const; // for sort

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
