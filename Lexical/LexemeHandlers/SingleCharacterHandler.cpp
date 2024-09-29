#include "SingleCharacterHandler.h"
#include "../../FileManagement/CodeCharacter.h"

TokenType SingleCharacterHandler::getIDTokenType(int tokenIndex) {
    return this->generatedTokens[tokenIndex];
}

Token SingleCharacterHandler::generateToken(CodeStream* stream) {
    CodeCharacter curCharacter = *(*stream);
    char character = curCharacter.getCharacter();
    if (character == '(') {
        return Token(TokenType::LEFT_PAREN,"(",curCharacter.getOffset());
    } else if (character == ')') {
        return Token(TokenType::RIGHT_PAREN,")",curCharacter.getOffset());
    } else if (character == '{') {
        return Token(TokenType::LEFT_CURLY_BRACE,"{",curCharacter.getOffset());
    } else if (character == '}') {
        return Token(TokenType::RIGHT_CURLY_BRACE,"}",curCharacter.getOffset());
    } else if (character == '[') {
        return Token(TokenType::LEFT_SQUARE_BRACKET,"[",curCharacter.getOffset());
    } else if (character == ']') {
        return Token(TokenType::RIGHT_SQUARE_BRACKET,"]",curCharacter.getOffset());
    } else if (character == ';') {
        return Token(TokenType::SEMICOLON,";",curCharacter.getOffset());
    } else if (character == '.') {
        return Token(TokenType::PERIOD,".",curCharacter.getOffset());
    } else if (character == ',') {
        return Token(TokenType::COMMA,",",curCharacter.getOffset());
    }
    // If failed, pass stream to next handler
    return this->getNextHandler()->generateToken(stream);
}
