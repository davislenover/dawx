#include "Edge.h"

Edge::Edge(char IDSymbol, Node *matchNode) : IDSymbol{IDSymbol}, matchNode{matchNode} {
}

bool Edge::isMatch(char symbolToCheck) {
    if (symbolToCheck == this->IDSymbol) {
        return true;
    } else {
        return false;
    }
}

char Edge::getIDSymbol() {
    return this->IDSymbol;
}

Node* Edge::getMatchNode() {
    return this->matchNode;
}

bool Edge::operator==(Edge edge) {
    if (this->IDSymbol == edge.getIDSymbol() && this->getMatchNode() == edge.getMatchNode()) {
        return true;
    } else {
        return false;
    }
}