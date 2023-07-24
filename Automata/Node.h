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
    /// <summary>Creates a Node object with a given state. Nodes hold Edges for traversal between Nodes</summary>
    Node(State state);
    /// <summary>Destructor for Node objects. Deletes all Edge objects stored</summary>
    ~Node();
    /// <summary>Gets the state of the Node, used to determine if a char is accepted or not</summary>
    State getState();
    /// <summary>Adds an Edge to the Edge vector of the given Node instance. The Edge must contain a unique ID char (symbol).</summary>
    void addEdge(Edge);
    /// <summary>Removes an Edge from the Node. Checks for an ID char match to remove. This does not delete the Edge</summary>
    void removeEdge(Edge);
    /// <summary>Gets the Node (as a pointer) to transition to given a symbol</summary>
    Node* getTransition(char);
};

#endif
