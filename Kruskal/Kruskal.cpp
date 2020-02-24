#include <iostream>
#include <algorithm>
#include <assert.h>
#include "Kruskal.h"

void Kruskal(graph& g) {
	assert(!g.dir);
	// 权重-起点-终点
	std::vector<std::vector<int>> edges;
	int vertexs = g.vertexs.size();
	for (int i = 0; i < vertexs; ++i) {
		auto temp = g.vertexs[i]->next;
		while (temp) {
			if (temp->vertex > i) {
				edges.push_back({ temp->weight, i, temp->vertex });
			}
			temp = temp->next;
		}
	}
	std::sort(edges.begin(), edges.end());

	std::cout << "Generating minimum spanning tree using Kruskal algorithm." << std::endl;

	// 将生成树中所有顶点连接到最小的顶点上，这里类似并查集的思想。
	std::vector<int> connect(vertexs);
	for (int i = 0; i < vertexs; ++i) connect[i] = i;
	int count = 0;
	for (int i = 0; i < edges.size(); ++i) {
		if (count == vertexs - 1) break;
		if (connect[edges[i][1]] == connect[edges[i][2]]) continue;
		int r = connect[edges[i][1]] < connect[edges[i][2]] ? connect[edges[i][1]] : connect[edges[i][2]];
		int temp = connect[edges[i][1]] > connect[edges[i][2]] ? edges[i][1] : edges[i][2];
		while (connect[temp] != r) {
			int t = connect[temp];
			connect[temp] = r;
			temp = t;
		}
		std::cout << edges[i][1] << " -- " << edges[i][2] << " weight: " << edges[i][0] << std::endl;
		++count;
	}
}