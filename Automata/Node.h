#ifndef DAWX_NODE_H
#define DAWX_NODE_H

#include <vector>

// Forward declaration of Edge in Node (pre-defined before its use)
class Edge;

enum State {ACCEPT,REJECT};
class Node {
private:
    State state;
    std::vector<Edge> edgeList;

public:
    Node(State state);
    State getState();
    void addEdge(Edge edge);
    void removeEdge(Edge edge);
};

#endif
