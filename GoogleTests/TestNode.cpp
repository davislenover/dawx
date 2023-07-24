#include "googletest/googletest/include/gtest/gtest.h"
#include "../Automata/Node.h"
#include "../Automata/DFA.h"
#include "../Automata/DFAFactory.h"
#include "../Exceptions/UnknownNodeException.h"

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

TEST(DFATests,DFAEvaluationTest) {

    // Create a DFA that only accepts "Test" (case-sensitive)
    Node startNode(REJECT);
    Node node2(REJECT);
    Node node3(REJECT);
    Node node4(REJECT);
    Node node5(ACCEPT);

    Edge t('T',&node2);
    Edge e('e',&node3);
    Edge s('s',&node4);
    Edge tf('t',&node5);

    startNode.addEdge(t);
    node2.addEdge(e);
    node3.addEdge(s);
    node4.addEdge(tf);

    DFA dfa(startNode);
    GTEST_ASSERT_TRUE(dfa.evaluate("Test") == ACCEPT);
    GTEST_ASSERT_TRUE(dfa.evaluate("test") == REJECT);
    GTEST_ASSERT_TRUE(dfa.evaluate("tes") == REJECT);

}

TEST(DFATests,DFACreationTest) {

    DFAFactory factory;


    char transitionMap1[] = {'T','2'};
    factory.addNode('1',REJECT,1,transitionMap1);
    char transitionMap2[] = {'e','3'};
    factory.addNode('2',REJECT,1,transitionMap2);
    char transitionMap3[] = {'s','4'};
    factory.addNode('3',REJECT,1,transitionMap3);
    char transitionMap4[] = {'t','5'};
    factory.addNode('4',REJECT,1,transitionMap4);
    factory.addNode('5',ACCEPT,0);

    DFA* newDFA = factory.constructDFA();
    GTEST_ASSERT_TRUE(newDFA->evaluate("Test") == ACCEPT);
    GTEST_ASSERT_TRUE(newDFA->evaluate("test") == REJECT);
    GTEST_ASSERT_TRUE(newDFA->evaluate("tes") == REJECT);

}
