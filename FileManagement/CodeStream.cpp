#include "CodeStream.h"

CodeStream::CodeStream(std::string pathToFile) : filePath(pathToFile) {
    // Check if the file extension is ".dawx"
    if (this->filePath.substr(this->filePath.length()-DAWX_FILE_LEN,std::string::npos).compare(DAWX_FILE_EXT)) {
        // If so, attempt to open file
        this->fileObj = new std::ifstream(this->filePath);
        // Check if no error flags were set during opening of file
        if (!this->fileObj->fail()) {
            //
        }

    }
}

