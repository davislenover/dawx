#include "CodeStream.h"
#include "CodeCharacter.h"
#include <memory>
# define END_OF_FILE std::ifstream::traits_type::eof()

CodeStream::CodeStream(std::string pathToFile) : filePath(pathToFile) {
    // Check if the file extension is ".dawx"
    if (this->filePath.substr(this->filePath.length()-DAWX_FILE_LEN,std::string::npos).compare(DAWX_FILE_EXT) == 0) {
        // If so, attempt to open file
        // Create a shared pointer, the template type is the object to create and the parameters are the parameters to the constructor
        this->fileObj = std::make_shared<std::ifstream>(this->filePath);
        // Check if no error flags were set during opening of file
        if (!this->fileObj->fail() && !this->fileObj->eof()) {
            // Assign first character
            this->startElement= this->fileObj->get();
            this->offsetFromStart++;
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
    this->increment();
    return *this;
}

CodeStream CodeStream::operator++(int) {
    // Return then increment
    // Essentially, return a copy of this iterator (call copy constructor)
    CodeStream returnCopy(*this);
    // Then increment this and return copy
    this->increment();
    return returnCopy;
}

CodeStream::CodeStream(const CodeStream &codeStreamToCopy) : filePath(codeStreamToCopy.filePath), fileObj(codeStreamToCopy.fileObj),
offsetFromStart(codeStreamToCopy.offsetFromStart), offsetLoops(codeStreamToCopy.offsetLoops) {
    this->startElement = codeStreamToCopy.startElement;
    this->curElement = codeStreamToCopy.curElement;
}

bool CodeStream::operator!=(const CodeStream &other) const {
    // For two CodeStream objects to be equal the following must be true
    // 1. They share the same file path
    // 2. Their current element pointers must be the same and the character they store must be the same
    // Note, files will contain the same character so this should only (at least for now) be used to determine end of iterator
    return !(this->filePath.compare(other.filePath) == 0 && this->curElement == other.curElement);
}

CodeCharacter& CodeStream::operator*() const {
    // Construct CodeCharacter
    CodeCharacter* returnCharacter = new CodeCharacter(this->curElement, this->offsetFromStart, this->offsetLoops);
    return *returnCharacter;
}

CodeStream CodeStream::begin() {
    return CodeStream(this->filePath);
}

CodeStream CodeStream::end() {
    CodeStream returnEnd(*this);
    returnEnd.curElement = END_OF_FILE;
    return returnEnd;
}

CodeCharacter CodeStream::peek() {
    if (this->fileObj.get()) {
        char nextChar = this->fileObj->peek();
        return  this->offsetFromStart + 1 != INT_MAX ? CodeCharacter(nextChar, offsetFromStart+1, 0)
        : CodeCharacter(nextChar, offsetFromStart+1, offsetLoops+1);
    }
    return CodeCharacter(END_OF_FILE, 0, 0);
}

void CodeStream::increment() {
    if (this->fileObj.get() && this->curElement != END_OF_FILE) {
        this->curElement = this->fileObj->get();
        if (this->offsetFromStart == INT_MAX) {
            this->offsetLoops++;
        }
        this->offsetFromStart++;
    } else {
        // Default to end of file is file object pointer is invalid
        this->curElement = END_OF_FILE;
    }
}



