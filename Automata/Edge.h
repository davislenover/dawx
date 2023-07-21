#ifndef DAWX_EDGE_H
#define DAWX_EDGE_H

// Forward declaration of Node in Edge (pre-defined before its use)
class Node;

class Edge {
private:
    char IDSymbol;
    Node* matchNode;
public:
    Edge(char, Node*);
    bool isMatch(char);
    char getIDSymbol();
    Node* getMatchNode();
    // Overloading equals operator
    bool operator==(Edge);
};

#endif