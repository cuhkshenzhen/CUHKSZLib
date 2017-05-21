#ifndef CUHKSZ_GRAPH_VERTEX
#define CUHKSZ_GRAPH_VERTEX

#include <list>

namespace cuhksz {

class Edge;

class Vertex {
public:
    Vertex();
    Vertex(int value);
    Vertex(const Vertex& src);
    ~Vertex();

    int getVal() { return value; }
    void setVal(int newVal) { value = newVal; }
    bool isValid() { return use; }
    void setValid() { use = true; }
    void setInvalid() { use = false; }
    int getID() { return id; }

    Vertex& operator= (const Vertex& src);
    bool operator== (const Vertex& src) const;
    bool operator!= (const Vertex& src) const;
    bool operator< (const Vertex& src) const; // for sort

    void addEdge(Vertex& to, int value=0);
    int getInDegree() { return inEdges.size(); }
    int getOutDegree() { return outEdges.size(); }

    std::list<Edge*> inEdges;
    std::list<Edge*> outEdges;

private:
    int value;
    bool use;
    int id;
    static int nextVertexID;
};

}	// namespace cuhksz


#endif // CUHKSZ_GRAPH_VERTEX
