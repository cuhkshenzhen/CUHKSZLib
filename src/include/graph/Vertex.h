#ifndef CUHKSZ_GRAPH_VERTEX
#define CUHKSZ_GRAPH_VERTEX

#include <list>

namespace cuhksz {

class Edge;

class Vertex {
public:
    Vertex();
    Vertex(int val);
    Vertex(Vertex& src);
    ~Vertex();

    int getVal() { return val; }
    void setVal(int newVal) { val = newVal; }
    bool isValid() { return use; }
    void setValid() { use = true; }
    void setInvalid() { use = false; }
    int getID() { return id; }

    Vertex& operator= (Vertex& src);
    bool operator< (const Vertex& src) const; // for sort

    void addEdge(Vertex& to, int val=0);
    int getInDegree() { return inEdges.size(); }
    int getOutDegree() { return outEdges.size(); }

    std::list<Edge*> inEdges;
    std::list<Edge*> outEdges;

private:
    int val;
    bool use;
    int id;
    static int nextVertexID;
};

}	// namespace cuhksz


#endif // CUHKSZ_GRAPH_VERTEX
