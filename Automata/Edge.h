#ifndef DAWX_EDGE_H
#define DAWX_EDGE_H

// Forward declaration of Node in Edge (pre-defined before its use)
class Node;

class Edge {
private:
    char IDSymbol;
    Node* matchNode;
public:
    /// <summary>Creates an Edge object. An Edge contains an ID char and a matching Node (pointer).</summary>
    Edge(char, Node*);
    /// <summary>Checks if a given input symbol matches the ID char in the Edge object. True if match, false otherwise</summary>
    bool isMatch(char);
    /// <summary>Gets the ID Symbol as a char</summary>
    char getIDSymbol();
    /// <summary>Gets the match Node pointer. Typically called after true is returned from isMatch()</summary>
    Node* getMatchNode();
    /// <summary>Check if an Edge object is equivalent to the Edge instance. Checks if the char IDs and the pointers of the MatchNode are the same for eachother</summary>
    // Overloading equals operator
    bool operator==(Edge);
};

#endif