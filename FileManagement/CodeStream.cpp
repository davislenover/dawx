#include "CodeStream.h"

CodeStream::CodeStream(std::string pathToFile) : filePath(pathToFile) {
    // Check if the file extension is ".dawx"
    if (this->filePath.substr(this->filePath.length()-DAWX_FILE_LEN,std::string::npos).compare(DAWX_FILE_EXT)) {
        // If so, attempt to open file
        this->fileObj = new std::ifstream(this->filePath);
        // Check if no error flags were set during opening of file
        if (!this->fileObj->fail() && !this->fileObj->eof()) {
            // Assign first character
            this->startElement = new char;
            this->fileObj->get(*this->startElement);
            // Create separate memory space for current element (otherwise incrementing will modify the start pointer)
            this->curElementPointer = new char;
            *this->curElementPointer = *this->startElement;
        }
    }
}

CodeStream::~CodeStream() {
    // Close file and clear any remaining memory
    this->fileObj->close();
    delete this->fileObj;
    delete this->curElementPointer;
    delete this->startElement;
}

CodeStream& CodeStream::operator++() {
    // Increment to next character (i.e., get next character)
    if (this->fileObj && !this->fileObj->eof()) {
        this->fileObj->get(*this->curElementPointer);
        // Then return
        return *this;
    } else {
        // Set to end of iterator
        this->curElementPointer = nullptr;
        return *this;
    }
}

CodeStream CodeStream::operator++(int) {
    // Return then increment
    // Essentially, return a copy of this iterator (call copy constructor)
    CodeStream returnCopy(*this);
    // Then increment this and return copy
    if (this->fileObj && !this->fileObj->eof()) {
        this->fileObj->get(*this->curElementPointer);
        return returnCopy;
    } else {
        // Set to end of iterator
        this->curElementPointer = nullptr;
        return returnCopy;
    }
}

CodeStream::CodeStream(const CodeStream &codeStreamToCopy) : filePath(codeStreamToCopy.filePath), fileObj(codeStreamToCopy.fileObj) {
    // Only the curElementPointer and startElement need to be copied by memory (as copying their pointers will point memory to the same location as the original object)
    // TODO make copy open new input file stream
    this->startElement = new char;
    *this->startElement = *codeStreamToCopy.startElement;
    this->curElementPointer = new char;
    *this->curElementPointer = *codeStreamToCopy.curElementPointer;
}

