#include "googletest/googletest/include/gtest/gtest.h"
#include "../Automata/Node.h"
#include "../Automata/Edge.h"

TEST(DFATests,NodeTest) {

    Node node(ACCEPT);
    GTEST_ASSERT_EQ(node.getState(),ACCEPT);

    Node node1(REJECT);
    GTEST_ASSERT_FALSE(node1.getState() == ACCEPT);

}
