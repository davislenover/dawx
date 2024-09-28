add_library(Lexical SHARED Token.cpp TokenType.h
        LexemeHandlers/LexemeHandler.cpp
        LexemeHandlers/LexemeHandler.h
        LexemeHandlers/SingleCharacterHandler.cpp
        LexemeHandlers/SingleCharacterHandler.h)