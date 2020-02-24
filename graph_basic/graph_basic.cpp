#include <assert.h>
#include <iostream>
#include <queue>
#include "graph_basic.h"

graph::graph(bool d, std::vector<std::vector<int>>& matrix) {
	assert(matrix.size());
	assert(matrix.size() == matrix[0].size());
	int n = matrix.size();

	dir = d;
	if (!d) {
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				assert(matrix[i][j] == matrix[j][i]);
			}
		}
	}
	
	for (int i = 0; i < n; ++i) {
		vertexs.push_back(new vNode(i));
		void* last = vertexs[i];
		for (int j = 0; j < n; ++j) {
			if (matrix[i][j]) {
				if (last == vertexs[i]) {
					((vNode*)last)->next = new eNode(j, matrix[i][j]);
					last = ((vNode*)last)->next;
				}
				else {
					((eNode*)last)->next = new eNode(j, matrix[i][j]);
					last = ((eNode*)last)->next;
				}
			}
		}
	}
}

graph::~graph() {
	for (int i = 0; i < vertexs.size(); ++i) delete vertexs[i];
}

void graph::DFS(int index, int& visited) {
	if ((1 << index) & visited) return;
	visited |= (1 << index);
	std::cout << index << " ";
	eNode* head = vertexs[index]->next;
	while (head) {
		DFS(head->vertex, visited);
		head = head->next;
	}
}

void graph::DFS() {
	//assert(dir);
	int visited = 0;
	DFS(0, visited);
	std::cout << std::endl;
}

void graph::BFS() {
	//assert(dir);
	int visited = 0;
	std::queue<int> q;
	for (int i = 0; i < vertexs.size(); ++i) {
		if (!((1 << i) & visited)) q.push(i);
		visited |= (1 << i);
		while (!q.empty()) {
			eNode* temp = vertexs[q.front()]->next;
			std::cout << q.front() << " ";
			q.pop();
			while (temp) {
				if (!((1 << temp->vertex) & visited)) q.push(temp -> vertex);
				visited |= (1 << temp->vertex);
				temp = temp->next;
			}
		}
	}
	std::cout << std::endl;
}