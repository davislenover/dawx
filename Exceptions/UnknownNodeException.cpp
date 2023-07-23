#include "UnknownNodeException.h"
#include <cstring>

UnknownNodeException::UnknownNodeException(char* unknownId) : unknownNodeId(unknownId) {};

char *UnknownNodeException::what() {
    std::string message = "Unknown Node ID: ";
    message += this->unknownNodeId;

    char* cstr = new char[message.length() + 1];
    strcpy(cstr,message.c_str());
    return cstr;

};
