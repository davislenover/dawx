// Header Guides
// Check to see if the symbol DAWX_NODE_H is defined in this file, if it's not, include whatever is in the defined symbol below
// Thus, once the symbol definition (the code) is actually included in a given file, when the if is checked again, the code will not be included again!
#ifndef DAWX_NODE_H
// to define and endif, is the definition of the symbol "DAWX_NODE_H"
#define DAWX_NODE_H

// Angular brackets are not relative
#include <vector>
// Double quotes mean relative to this file
#include "Edge.h"

// Forward declaration of Edge in Node (pre-defined before its use)

enum State {ACCEPT,REJECT};
class Node {
private:
    State state;
    std::vector<Edge> edgeList;

public:
    Node(State state);
    State getState();
    void addEdge(Edge);
    void removeEdge(Edge);
    Node* getTransition(char);
};

#endif
