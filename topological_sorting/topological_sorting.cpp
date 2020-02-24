#include <queue>
#include <iostream>
#include "topological_sorting.h"

void topologicalSorting(graph& g) {
	int length = g.vertexs.size();
	std::vector<int> inDegree(length, 0);
	for (auto v : g.vertexs) {
		eNode* temp = v->next;
		while (temp) {
			++inDegree[temp->vertex];
			temp = temp->next;
		}
	}

	std::queue<int> q;
	for (int i = 0; i < length; ++i) {
		if (!inDegree[i]) q.push(i);
	}

	std::cout << "Topological sorting begins..." << std::endl;
	while (!q.empty()) {
		int i = q.front();
		std::cout << i << " ";
		q.pop();
		auto temp = g.vertexs[i]->next;
		while (temp) {
			--inDegree[temp->vertex];
			if (!inDegree[temp->vertex]) q.push(temp->vertex);
			temp = temp->next;
		}
	}
	std::cout << std::endl;
}