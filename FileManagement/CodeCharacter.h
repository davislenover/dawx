class CodeCharacter {
private:
    char character;
    // Offset from beginning of file
    int offset;
    int offsetLoops;
public:
    CodeCharacter(char readCharacter, int offsetFromStart, int offsetLoops) : character(readCharacter), offset(offsetFromStart), offsetLoops(offsetLoops) {};

    char getCharacter() {
        return this->character;
    }

    int getOffset() {
        return this->offset;
    }

};
