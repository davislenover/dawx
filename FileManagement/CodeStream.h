#include <string>
#include <iostream>
#include <fstream>

#define DAWX_FILE_EXT ".dawx"
#define DAWX_FILE_LEN 5
// Forward declare CodeCharacter class
class CodeCharacter;

class CodeStream {
private:
    const std::string filePath;
    // File input stream
    std::ifstream* fileObj;
    // Pointer to the current element
    char* curElementPointer;
    char* startElement;
    char* endPtr = 0;
public:
    // CodeStream is an iterator, C++17 deprecates std::iterator thus explicitly define typedefs
    // "using" to say "use iterator_category and replace with std::input_iterator_tag"
    using iterator_category = std::input_iterator_tag;
    // The value type the iterator will produce
    using value_type = std::string;
    // The difference between two values in the iterator is a subtraction between two element pointers
    using differnece_type = std::ptrdiff_t;
    using pointer = CodeCharacter*;
    using reference = CodeCharacter&;

    // Implement required operators for input iterators
    // Pre-Increment (++x)
    CodeStream& operator++();
    // Post-Increment (x++)
    CodeStream operator++(int);
    // Comparison (!=)
    bool operator!=(const CodeStream& other) const;
    // Dereference (*x)
    reference operator*() const;
    // Define begin and end functions for range based for loops
    // Returns an iterator pointing to the start
    CodeStream begin();
    // Returns an iterator pointing one past the end
    CodeStream end();

    CodeStream(std::string pathToFile);
};