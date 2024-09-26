#include "CodeStream.h"
#include "CodeCharacter.h"

#include <memory>

CodeStream::CodeStream(std::string pathToFile) : filePath(pathToFile) {
    // Check if the file extension is ".dawx"
    if (this->filePath.substr(this->filePath.length()-DAWX_FILE_LEN,std::string::npos).compare(DAWX_FILE_EXT)) {
        // If so, attempt to open file
        // Create a shared pointer, the template type is the object to create and the parameters are the parameters to the constructor
        this->fileObj = std::make_shared<std::ifstream>(this->filePath);
        // Check if no error flags were set during opening of file
        if (!this->fileObj->fail() && !this->fileObj->eof()) {
            // Assign first character
            this->fileObj->get(this->startElement);
            this->curElement = this->startElement;
        }
    }
}

CodeStream::~CodeStream() {
    // Close file and clear any remaining memory
    // While iterating, other references to the file input stream are stored
    // Want to check that this object is the only one left with the file input stream reference before closing it
    if (this->fileObj.use_count() == 1) {
        this->fileObj->close();
    }
}

CodeStream& CodeStream::operator++() {
    // Increment to next character (i.e., get next character)
    if (this->fileObj && !this->fileObj->eof()) {
        this->fileObj->get(this->curElement);
        // Then return
        return *this;
    } else {
        // Set to end of iterator
        this->isEndOfIterator = true;
        return *this;
    }
}

CodeStream CodeStream::operator++(int) {
    // Return then increment
    // Essentially, return a copy of this iterator (call copy constructor)
    CodeStream returnCopy(*this);
    // Then increment this and return copy
    if (this->fileObj && !this->fileObj->eof()) {
        this->fileObj->get(this->curElement);
        return returnCopy;
    } else {
        // Set to end of iterator
        this->isEndOfIterator = true;
        return returnCopy;
    }
}

CodeStream::CodeStream(const CodeStream &codeStreamToCopy) : filePath(codeStreamToCopy.filePath), fileObj(codeStreamToCopy.fileObj) {
    this->startElement = codeStreamToCopy.startElement;
    this->curElement = codeStreamToCopy.curElement;
}

bool CodeStream::operator!=(const CodeStream &other) const {
    // For two CodeStream objects to be equal the following must be true
    // 1. They share the same pointer to the same file input stream
    // 2. Their current element pointers must be the same and the character they store must be the same
    return this->fileObj.get() == other.fileObj.get() && this->curElement == other.curElement && this->isEndOfIterator == other.isEndOfIterator;
}

CodeCharacter& CodeStream::operator*() const {
    // Construct CodeCharacter
    CodeCharacter* returnCharacter = new CodeCharacter(this->curElement, this->fileObj->gcount());
    return *returnCharacter;
}

CodeStream CodeStream::begin() {
    return *this;
}

CodeStream CodeStream::end() {
    CodeStream returnEnd(*this);
    returnEnd.isEndOfIterator = true;
    return returnEnd;
}



