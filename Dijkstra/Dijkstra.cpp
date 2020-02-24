#include <iostream>
#include <assert.h>
#include "Dijkstra.h"

void Dijkstra(graph& g, int startPoint) {
	int vertexs = g.vertexs.size();
	//  构造邻接矩阵
	std::vector<std::vector<int>> matrix(vertexs, std::vector<int>(vertexs, 0));
	for (int i = 0; i < vertexs; ++i) {
		auto temp = g.vertexs[i]->next;
		while (temp) {
			matrix[i][temp->vertex] = temp->weight;
			temp = temp->next;
		}
	}

	std::cout << "Starting Dijkstra algorithm." << std::endl;

	// 节点编号-节点距离
	std::vector<std::vector<int>> V;
	for (int i = 0; i < vertexs; ++i) {
		if (i != startPoint) {
			if (matrix[startPoint][i]) V.push_back({ i, matrix[startPoint][i] });
			else V.push_back({ i, INT_MAX });
			if (V[V.size() - 1][1] < V[0][1]) swap(V[0], V[V.size() - 1]);
		}
	}
	while (!V.empty()) {
		auto temp = V[0];
		std::cout << startPoint << " -- " << temp[0] << " distance: " << temp[1] << std::endl;
		V.erase(V.begin());
		for (int i = 0; i < V.size(); ++i) {
			if (temp[1] + matrix[temp[0]][V[i][0]] < V[i][1]) V[i][1] = temp[1] + matrix[temp[0]][V[i][0]];
			if (V[i][1] < V[0][1]) swap(V[0], V[i]);
		}
	}
}