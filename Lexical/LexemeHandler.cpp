#include "LexemeHandler.h"

void LexemeHandler::setNextHandler(LexemeHandler* handler) {
    this->nextHandler = handler;
}

LexemeHandler* LexemeHandler::getNextHandler() {
    return this->nextHandler;
}
