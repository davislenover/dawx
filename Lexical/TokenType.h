enum TokenType {

    // Single character tokens
    LEFT_PAREN, RIGHT_PAREN, LEFT_CURLY_BRACE, RIGHT_CURLY_BRACE, LEFT_SQUARE_BRACKET, RIGHT_SQUARE_BRACKET,
    SEMICOLON, PERIOD,

    // Math-related single character tokens
    COMMA, MINUS, PLUS, SLASH, STAR,

    // One or two character tokens
    EQUAL, EQUAL_EQUAL,
    BANG, BANG_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,

    // Literals
    ID, STRING, NUMBER,

    // Keywords
    DEC, AS, FUNC, TRUE, FALSE, FOR, WHILE, RETURN, IF, OR, AND

};
