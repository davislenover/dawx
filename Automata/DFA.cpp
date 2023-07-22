#include "DFA.h"

DFA::DFA(Node &startNode) : startNode{startNode} {};

/// <summary>Evaluates a given input string into the DFA instance. If the DFA accepts the String, returns the state ACCEPT. Otherwise, returns REJECT</summary>
State DFA::evaluate(std::string stringToEvaluate) {
    // Evaluate from start node (to set current node)
    this->currentNode = startNode.getTransition(stringToEvaluate[0]);
    // size_type guarantees a type big enough to represent the size of a string
    for (std::string::size_type strIndex = 1; strIndex < stringToEvaluate.size(); strIndex++) {
        this->currentNode = currentNode->getTransition(stringToEvaluate[strIndex]);
    }
    // Finally return current node state after loop completes
    return this->currentNode->getState();
}