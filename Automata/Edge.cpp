#include "Edge.h"

/// <summary>Creates an Edge object. An Edge contains an ID char and a matching Node (pointer).</summary>
Edge::Edge(char IDSymbol, Node *matchNode) : IDSymbol{IDSymbol}, matchNode{matchNode} {
}

/// <summary>Checks if a given input symbol matches the ID char in the Edge object. True if match, false otherwise</summary>
bool Edge::isMatch(char symbolToCheck) {
    if (symbolToCheck == this->IDSymbol) {
        return true;
    } else {
        return false;
    }
}

/// <summary>Gets the ID Symbol as a char</summary>
char Edge::getIDSymbol() {
    return this->IDSymbol;
}

/// <summary>Gets the match Node pointer. Typically called after true is returned from isMatch()</summary>
Node* Edge::getMatchNode() {
    return this->matchNode;
}

/// <summary>Check if an Edge object is equivalent to the Edge instance. Checks if the char IDs and the pointers of the MatchNode are the same for eachother</summary>
bool Edge::operator==(Edge edge) {
    if (this->IDSymbol == edge.getIDSymbol() && this->getMatchNode() == edge.getMatchNode()) {
        return true;
    } else {
        return false;
    }
}