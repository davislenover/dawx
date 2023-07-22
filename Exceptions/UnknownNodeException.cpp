#include "UnknownNodeException.h"
#include <string>

UnknownNodeException::UnknownNodeException(std::string unknownNodeId) : unknownNodeId{unknownNodeId}  {};

const char* UnknownNodeException::what() const throw() {
    std::string unknown = "Unknown NodeId: " + this->unknownNodeId;
    return unknown.c_str();
};
