project( Kruskal )
cmake_minimum_required( VERSION 3.0 )

file(GLOB SRCS *.h *.cpp)

include_directories( ${graph_basic_DIR} )
add_executable( ${PROJECT_NAME} ${SRCS})
target_link_libraries ( ${PROJECT_NAME} graph_basic )