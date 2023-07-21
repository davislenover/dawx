#ifndef DAWX_DRAINNODE_H
#define DAWX_DRAINNODE_H

#include "Node.h"

class DrainNode : public Node {

public:
    DrainNode();
    Node* getTransition(char);
};


#endif
