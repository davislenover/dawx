#ifndef DAWX_DFAFACTORY_H
#define DAWX_DFAFACTORY_H

#include <unordered_map>
#include "Node.h"
#include "Edge.h"
#include "DFA.h"

int String;

class DFAFactory {
private:
    std::unordered_map<char,Node*> nodeMap;
    std::unordered_map<char,std::unordered_map<char,char>> edgeMap;
    Node* startNode = NULL;
    void parseEdges();
public:
    void addNode(char,State,std::unordered_map<char,char>);
    DFA* constructDFA();
};


#endif
