#include <string>
#include <iostream>
#include <fstream>
#include <memory>

#define DAWX_FILE_EXT ".dawx"
#define DAWX_FILE_LEN 5
// Forward declare CodeCharacter class
class CodeCharacter;

class CodeStream {
private:
    const std::string filePath;
    // File input stream
    std::shared_ptr<std::ifstream> fileObj;
    // Current element and start element
    char curElement;
    char startElement;
    // Offset from start, 0 means at start (no characters read)
    int offsetFromStart = 0;
    // Possible for offset to reach maximum integer count and thus overflow, this integer will indicate how many
    // overflows which have occurred
    int offsetLoops = 0;
    // Increment to next character in file stream
    void increment();

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

    // Get next character without incrementing iterator
    CodeCharacter peek();

    CodeStream(std::string pathToFile);
    // Copy constructor
    CodeStream(const CodeStream& codeStreamToCopy);
    ~CodeStream();
};