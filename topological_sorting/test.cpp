#include <iostream>
#include "topological_sorting.h"

int main() {
	std::vector<std::vector<int>> matrix(5, std::vector<int>(5, 0));
	matrix[0][1] = 1;
	matrix[0][2] = 1;
	matrix[0][3] = 1;
	matrix[2][3] = 1;
	matrix[3][4] = 1;
	matrix[4][1] = 1;
	graph g(true, matrix);
	std::cout << "I have a graph, it's DFS is:" << std::endl;
	g.DFS();
	std::cout << "It's BFS is:" << std::endl;
	g.BFS();
	std::cout << "It's topological sorting is:" << std::endl;
	topologicalSorting(g);
}