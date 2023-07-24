# MemManagement is expressed through headers (as they are template methods), thus utilize INTERFACE here
add_library(MemManagement INTERFACE)
target_include_directories(MemManagement INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(MemManagement PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")