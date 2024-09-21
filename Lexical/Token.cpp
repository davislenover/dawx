#include "Token.h"

const TokenType Token::getType() {
    return this->type;
}

const std::string &Token::getLexeme() {
    return this->lexeme;
}

const void *Token::getLiteral() {
    return this->literalObj;
}

const int Token::getBeginOffset() {
    return this->charOffsetBegin;
}

const int Token::getLexemeLength() {
    return this->length;
}

