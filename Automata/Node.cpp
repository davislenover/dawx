#include "Node.h"
#include "Edge.h"

/// <summary>Gets the state of the Node, used to determine if a char is accepted or not</summary>
State Node::getState() {
    return this->state;
}
/// <summary>Creates a Node object with a given state. Nodes hold Edges for traversal between Nodes</summary>
Node::Node(State state) {
    this->state = state;
}

/// <summary>Adds an Edge to the Edge vector of the given Node instance. The Edge must contain a unique ID char (symbol)</summary>
void Node::addEdge(Edge edge) {
    for (Edge edgeToCheck : this->edgeList) {
        if (edgeToCheck.getIDSymbol() == edge.getIDSymbol()) {
            return;
        }
    }
    this->edgeList.push_back(edge);
}

/// <summary>Removes an Edge from the Node. Checks for an ID char match to remove</summary>
void Node::removeEdge(Edge edge) {

    // Find position of Edge
    int indexToRemove = 0;
    bool isPresentInVector = false;
    for (int index = 0; index < this->edgeList.size(); index++) {
        // Uses overloaded operator
        if (this->edgeList[index] == edge) {
            indexToRemove = index;
            isPresentInVector = true;
            break;
        }
    }

    if (isPresentInVector) {
        this->edgeList.erase(edgeList.begin() + indexToRemove);
    }

}
