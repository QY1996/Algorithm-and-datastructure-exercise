project( graph_basic )
cmake_minimum_required( VERSION 3.0 )

set(graph_basic_DIR ${CMAKE_CURRENT_SOURCE_DIR} CACHE INTERNAL "graph_basic_DIR")

file(GLOB SRCS *.h *.cpp)

add_library( ${PROJECT_NAME} STATIC ${SRCS})