#include <iostream>
#include "Kruskal.h"

int main() {
	std::vector<std::vector<int>> matrix(5, std::vector<int>(5, 0));
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if(i != j) matrix[i][j] = ((i + j) * 177) % 13 + 1;
		}
	}
	graph g(false, matrix);
	std::cout << "I have a graph, it's DFS is:" << std::endl;
	g.DFS();
	std::cout << "It's BFS is:" << std::endl;
	g.BFS();
	Kruskal(g);
}