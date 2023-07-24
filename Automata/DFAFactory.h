#ifndef DAWX_DFAFACTORY_H
#define DAWX_DFAFACTORY_H

#include <unordered_map>
#include "Node.h"
#include "Edge.h"
#include "DFA.h"
#include "../Exceptions/UnknownNodeException.h"
#include <cstdarg>

int String;

class DFAFactory {
private:
    std::unordered_map<char,Node*> nodeMap;
    std::unordered_map<char,std::unordered_map<char,char>> edgeMap;
    Node* startNode = NULL;
    void parseEdges();
    std::unordered_map<char, char> parseEdgeTransitions(int,va_list);
public:
    /// <summary>Constructs and adds a Node to be added in the DFA.
    /// @param char - the given nodeID
    /// @param State - the State of the Node
    /// @param int - how many edge transitions the Node will have
    /// @param ... a variable number of char arrays with two elements, the first element corresponds to the transition symbol (i.e., the symbol to trigger the transition), the second element corresponds to the nodeID (or Node) to transition to.
    /// It is imperative that the variable args have exactly the number of edge transitions specified
    /// </summary>
    void addNode(char,State,int,...);
    /// <summary>Constructs a DFA from the given Nodes added
    /// @throws UnknownNodeException if any edge transition contains an unknown NodeID
    /// </summary>
    DFA* constructDFA();
};


#endif
