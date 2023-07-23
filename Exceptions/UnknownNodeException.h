#ifndef DAWX_UNKNOWNNODEEXCEPTION_H
#define DAWX_UNKNOWNNODEEXCEPTION_H
#include <exception>
#include <string>

class UnknownNodeException : public std::exception {
private:
   char* unknownNodeId;
public:
    UnknownNodeException(char* unknownId);
    char* what();
};


#endif
