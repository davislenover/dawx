#include "googletest/googletest/include/gtest/gtest.h"
#include "../Automata/Node.h"
#include "../Automata/Edge.h"
#include "../Automata/DrainNode.h"

TEST(DFATests,NodeStateTest) {

    Node node(ACCEPT);
    GTEST_ASSERT_EQ(node.getState(),ACCEPT);

    Node node1(REJECT);
    GTEST_ASSERT_FALSE(node1.getState() == ACCEPT);

}

TEST(DFATests,NodeTransitionTest) {

    // Define Nodes (declare on Heap)
    Node* testNode1 = new Node(ACCEPT);
    Node* testNode2 = new Node(REJECT);
    // Create Edges
    Edge edge1('q',testNode1);
    Edge edge2('w',testNode2);

    // Create Node and house both Edges
    Node mainNode(ACCEPT);
    mainNode.addEdge(edge1);
    mainNode.addEdge(edge2);

    GTEST_ASSERT_TRUE(mainNode.getTransition('q')==testNode1);
    GTEST_ASSERT_TRUE(mainNode.getTransition('w')==testNode2);

    delete testNode1;
    delete testNode2;

}

TEST(DFATests,NodeRejectTransitionTest) {

    // Define Nodes (declare on Heap)
    Node* testNode1 = new Node(ACCEPT);
    Node* testNode2 = new Node(REJECT);
    // Create Edges
    Edge edge1('q',testNode1);
    Edge edge2('w',testNode2);

    // Create Node and house both Edges
    Node mainNode(ACCEPT);
    mainNode.addEdge(edge1);
    mainNode.addEdge(edge2);

    GTEST_ASSERT_TRUE(mainNode.getTransition('q')==testNode1);
    GTEST_ASSERT_TRUE(mainNode.getTransition('w')==testNode2);

    // Any undefined transition should be auto drained
    // Note, the rejectNode is allocated to the heap thus it is imperative the pointer is known for deletion later
    Node* rejectNode = mainNode.getTransition('x');
    GTEST_ASSERT_TRUE(rejectNode->getState() == REJECT);

    delete testNode1;
    delete testNode2;
    delete rejectNode;

}
