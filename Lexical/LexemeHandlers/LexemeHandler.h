#include "../Token.h"
#include "../../FileManagement/CodeStream.h"

class LexemeHandler {
private:
    LexemeHandler* nextHandler;
protected:
    void setNextHandler(LexemeHandler* handler);
    LexemeHandler* getNextHandler();
public:
    virtual TokenType getIDTokenType(int tokenIndex = 0) = 0;
    virtual Token generateToken(CodeCharacter curCharacter, CodeStream stream) = 0;
};
