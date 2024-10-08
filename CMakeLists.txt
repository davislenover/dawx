# Setup
cmake_minimum_required(VERSION 3.25)
project(dawx)
set(CMAKE_CXX_STANDARD 23)
# First, specify output directory of build (i.e., the cmake debug folder/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# Add all sub-directories
add_subdirectory(Automata)
add_subdirectory(Exceptions)
add_subdirectory(MemManagement)
add_subdirectory(GoogleTests)
# Directory for lexical analysis of dawx file
add_subdirectory(Lexical)
# Directory for file IO
add_subdirectory(FileManagement)
# Specify the main name, specify main.cpp as the source file
add_executable(main main.cpp)
# Link subdirectories as libraries (whatever the name of the library is) to the main executable
# i.e., link the library Automata to main
target_link_libraries(main PUBLIC Automata Exceptions MemManagement)
