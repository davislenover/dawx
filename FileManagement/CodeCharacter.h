class CodeCharacter {
private:
    const char character;
    // Offset from beginning of file
    const int offset;
public:
    CodeCharacter(char readCharacter, int offsetFromStart) : character(readCharacter), offset(offsetFromStart) {};

    char getCharacter() {
        return this->character;
    }

    int getOffset() {
        return this->offset;
    }

};
