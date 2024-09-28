#include "googletest/googletest/include/gtest/gtest.h"
#include "../FileManagement/CodeStream.h"
#include "../FileManagement/CodeCharacter.h"
#include <string>

TEST(CodeSteamTests, CodeStreamCreation) {

    CodeStream stream("B:\\Code Projects\\dawx\\TestFiles\\test.dawx");
    std::string testStr = "";

    int offsetTest = 0;
    for (CodeCharacter characterObj : stream) {
        testStr.push_back(characterObj.getCharacter());
        ASSERT_EQ(characterObj.getOffset(),++offsetTest);
    }

    ASSERT_EQ("This is a test\nHello world!", testStr);


}