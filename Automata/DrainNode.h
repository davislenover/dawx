#ifndef DAWX_DRAINNODE_H
#define DAWX_DRAINNODE_H

#include "Node.h"

/// DrainNode is a special Node that always Rejects an input. @see State for Accept and Reject
class DrainNode : public Node {

public:
    DrainNode();
    /// This method will always return a pointer to the instance of the DrainNode
    Node* getTransition(char);
};


#endif
