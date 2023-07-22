#ifndef DAWX_UNKNOWNNODEEXCEPTION_H
#define DAWX_UNKNOWNNODEEXCEPTION_H
#include <exception>
#include <string>

class UnknownNodeException : public std::exception {
private:
    std::string unknownNodeId;
public:
    UnknownNodeException(std::string);
    virtual const char* what() const throw();
};


#endif
