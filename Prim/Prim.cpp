#include <iostream>
#include <assert.h>
#include "Prim.h"

void Prim(graph& g) {
	int vertexs = g.vertexs.size();
	//  ππ‘Ï¡⁄Ω”æÿ’Û
	std::vector<std::vector<int>> matrix(vertexs, std::vector<int>(vertexs, 0));
	for (int i = 0; i < vertexs; ++i) {
		auto temp = g.vertexs[i]->next;
		while (temp) {
			matrix[i][temp->vertex] = temp->weight;
			temp = temp->next;
		}
	}

	std::cout << "Generating minimum spanning tree using Prim algorithm." << std::endl;
	std::vector<int> U;
	int visited = 1;
	U.push_back(0);
	while (U.size() < vertexs) {
		int minWeight = INT_MAX;
		int start = -1, end = -1;
		for (int u : U) {
			for (int i = 0; i < vertexs; ++i) {
				if (visited & (1 << i)) continue;
				if (matrix[u][i] > 0 && matrix[u][i] < minWeight) {
					minWeight = matrix[u][i];
					start = u;
					end = i;
				}
			}
		}
		U.push_back(end);
		visited |= (1 << end);
		std::cout << start << " -- " << end << " weight: " << minWeight << std::endl;
	}
}