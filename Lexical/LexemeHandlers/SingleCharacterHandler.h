#include "LexemeHandler.h"

class SingleCharacterHandler : public LexemeHandler {
private:
    TokenType generatedTokens[9] = {TokenType::LEFT_PAREN,TokenType::RIGHT_PAREN, TokenType::LEFT_CURLY_BRACE,
                                    TokenType::RIGHT_CURLY_BRACE, TokenType::LEFT_SQUARE_BRACKET, TokenType::RIGHT_SQUARE_BRACKET,
                                    TokenType::SEMICOLON, TokenType::PERIOD, TokenType::COMMA};
public:
    TokenType getIDTokenType(int tokenIndex = 0) override;
    Token generateToken(CodeCharacter curCharacter, CodeStream stream) override;
};
