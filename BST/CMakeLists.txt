project( BST )
cmake_minimum_required( VERSION 3.0 )

file(GLOB SRCS *.h *.cpp)

add_executable( ${PROJECT_NAME} ${SRCS})