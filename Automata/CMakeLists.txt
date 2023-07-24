# When add sub-directory is called, the given Library name will be found
# SHARED indicates a dynamically linked library (.dll), meaning the library will be linked at runtime
# unlike STATIC, It is NOT part of the executable
add_library(Automata SHARED Node.cpp Edge.cpp DrainNode.cpp DFA.cpp DFAFactory.cpp)
# Some files make use of custom exceptions, thus, include them
target_link_libraries(Automata PUBLIC Exceptions MemManagement)
# Specify to build the Automata library in the lib directory
set_target_properties(Automata PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")