#include "DFAFactory.h"
#include <iostream>

void DFAFactory::addNode(char nodeID, State nodeState, int numberOfInputs, ...) {

    va_list args;
    va_start(args,numberOfInputs);
    std::unordered_map<char, char> connectedNodes = parseEdgeTransitions(numberOfInputs,args);

    if (!this->nodeMap.contains(nodeID)) {
        Node* newNode = new Node(nodeState);
        this->nodeMap[nodeID] = newNode;
        this->edgeMap[nodeID] = connectedNodes;
        // Set startNode if this call to addNode is the first
        if (this->startNode == NULL) {
            this->startNode = newNode;
        }
    }
}

std::unordered_map<char, char> DFAFactory::parseEdgeTransitions(int numberOfInputs, va_list args) {

    // Initialize variable arguments

    std::unordered_map<char,char> returnMap;

    // Loop through all inputs
    for (int index = 0; index < numberOfInputs; index++) {

        // Each time va_arg is called on args, the current value is given to edgeDef as a char pointer (from arg_ptr) and then arg_ptr is increased to the next argument in the list
        char* edgeDef = va_arg(args, char*);
        // Parse out both the symbol and which nodeID to transition to
        // Pointer arithmetic, assume that there are two elements within this array object, get the first element (i.e. at the base address)
        char symbol = edgeDef[0];
        // Then increment the pointer to the next memory address to get the next element (base address + 1)
        char gotoNodeID = edgeDef[1];
        // Add to map
        returnMap[symbol] = gotoNodeID;
    }
    return returnMap;
}

DFA* DFAFactory::constructDFA() {
    // Add Edges to Nodes
    this->parseEdges();
    // Construct DFA (get the iterator of the nodeMap and return the first value in the first key-value pair)
    return new DFA(*this->startNode);
}

void DFAFactory::parseEdges() {

    // Get map iterator for edgeMap
    std::unordered_map<char,std::unordered_map<char,char>>::iterator itForMap = this->edgeMap.begin();

    while(itForMap != this->edgeMap.end()) {

        // First gets key (i.e., the nodeID)
        char nodeID = itForMap->first;
        // Get edge transition map for given nodeID
        std::unordered_map<char,char> edgeTransitionMap = itForMap->second;
        // Get node from nodeMap
        Node* correspondingNode = nodeMap[nodeID];

        // Loop over edgeTransitionMap
        std::unordered_map<char,char>::iterator transitionMapArray = edgeTransitionMap.begin();
        while(transitionMapArray != edgeTransitionMap.end()) {
            // Get transition symbol (i.e., when the given node reads this symbol, which node should it transition to?)
            char symbol = transitionMapArray->first;
            // Get nodeID to transition to
            char gotoNodeID = transitionMapArray->second;

            // Check if the nodeMap actually contains the given nodeID before retrieving a pointer for said Node
            if (this->nodeMap.contains(gotoNodeID)) {
                // Create a new edge with the given symbol
                Edge* newEdge = new Edge(symbol,this->nodeMap[gotoNodeID]);
                // Add edge (de-reference)
                correspondingNode->addEdge(*newEdge);
            } else {
                // If the NodeID is unknown, throw an exception (note this takes in a reference to the nodeID)
                throw UnknownNodeException(&gotoNodeID);
            }
            // Increment iterator
            transitionMapArray++;
        }
        // Increment iterator for next Node/Edge map
        itForMap++;
    }

}
