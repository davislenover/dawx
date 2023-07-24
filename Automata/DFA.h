#ifndef DAWX_DFA_H
#define DAWX_DFA_H

#include <string>
#include "Node.h"

class DFA {

private:
    Node startNode;
    Node* currentNode;

public:
    /// <summary>Create a DFA given a starting node to enter the DFA. @see evaluate() function for evaluation of a String from the starting Node</summary>
    DFA(Node &startNode);
    /// <summary>Evaluates a given input string into the DFA instance. If the DFA accepts the String, returns the state ACCEPT. Otherwise, returns REJECT</summary>
    State evaluate(std::string);

};


#endif
