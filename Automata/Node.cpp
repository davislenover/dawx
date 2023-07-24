#include "Node.h"
#include "Edge.h"
#include "DrainNode.h"

Node::Node(State state) : state{state} {
}

State Node::getState() {
    return this->state;
}

void Node::addEdge(Edge edge) {
    for (Edge edgeToCheck : this->edgeList) {
        if (edgeToCheck.getIDSymbol() == edge.getIDSymbol()) {
            return;
        }
    }
    this->edgeList.push_back(edge);
}

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

Node* Node::getTransition(char symbol) {
    for (Edge edge : this->edgeList) {
        if (edge.isMatch(symbol)) {
            return edge.getMatchNode();
        }
    }
    // TODO this MUST be deleted off of the Heap!
    DrainNode* drainNode = new DrainNode();
    return drainNode;
}
