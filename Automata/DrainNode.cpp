#include "DrainNode.h"
DrainNode::DrainNode() : Node{REJECT} {
};

Node *DrainNode::getTransition(char symbol) {
    return this;
}
