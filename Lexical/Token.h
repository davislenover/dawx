#include "TokenType.h"
#include <string>

class Token {
private:
    const TokenType type;
    const std::string lexeme;
    // A literal can come in many different type forms, thus, use void*
    const void* literalObj;
    // The offset to the start of the first lexeme character from the beginning of the file
    const int charOffsetBegin;
    // The length of the lexeme
    const int length;
public:
    // Constructor with initializer list (allows for initializing const member values)
    // These const data types have a default constructor which will set their values already, thus they will be stuck with their default values
    Token(const TokenType tokenType, std::string lexemeToAdd, int beginningOffset, void* literal = nullptr) :
    type(tokenType), lexeme(lexemeToAdd), charOffsetBegin(beginningOffset), literalObj(literal), length(lexemeToAdd.length()) {};

    const TokenType getType();
    const std::string& getLexeme();
    const void* getLiteral();
    const int getBeginOffset();
    const int getLexemeLength();
};
