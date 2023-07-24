# 'Google_test' is the subproject name
project(Google_tests)
# 'googletest' is the folder with Google Test sources
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
# TestNode.cpp needs Automata lib to function, thus include it's directory
include_directories(../Automata)
include_directories(../MemManagement)
# 'Google_Tests_run' is the target name
# 'TestNode.cpp' is source file with tests
add_executable(Google_Tests_run TestNode.cpp)
# Add Google Test libraries as well as Automata
target_link_libraries(Google_Tests_run gtest gtest_main Automata)