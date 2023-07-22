#ifndef DAWX_DFA_H
#define DAWX_DFA_H

#include <string>
#include "Node.h"

class DFA {

private:
    Node startNode;
    Node* currentNode;

public:
    DFA(Node &startNode);
    State evaluate(std::string);

};


#endif
