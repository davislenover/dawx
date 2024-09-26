class CodeCharacter {
private:
    char character;
    // Offset from beginning of file
    int offset;
public:
    CodeCharacter(char readCharacter, int offsetFromStart) : character(readCharacter), offset(offsetFromStart) {};

    char getCharacter() {
        return this->character;
    }

    int getOffset() {
        return this->offset;
    }

};
