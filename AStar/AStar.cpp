#include <iostream>
#include <queue>
#include <unordered_set>
#include "AStar.h"

struct myNodeGreater {
	bool operator()(myNode* a, myNode* b) {
		return a->G + a->H > b->G + b->H;
	}
};

void showStat(std::vector<std::vector<char>>& map, std::vector<int>& endPoint, std::vector<std::vector<int>>& closeList, myNode* nowPos) {
	auto m(map);
	m[endPoint[1]][endPoint[0]] = 'E';
	for (auto it = closeList.begin(); it != closeList.end(); ++it) {
		m[(*it)[1]][(*it)[0]] = '#';
	}
	m[nowPos->y][nowPos->x] = 'P';
	std::cout << "Now the status is: " << std::endl;
	for (int i = 0; i < m.size(); ++i) {
		for (int j = 0; j < m[i].size(); ++j) {
			std::cout << m[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

template<class T>
bool find(std::vector<T> list, T target) {
	for (int i = 0; i < list.size(); ++i) if (list[i] == target) return true;
	return false;
}

void AStar(std::vector<std::vector<char>>& map, std::vector<int>& startPoint, std::vector<int>& endPoint) {
	int m = map.size();
	if (!m) return;
	int n = map[0].size();
	if (!n) return;

	std::vector<std::vector<int>> closeList;
	// 使用优先队列始种找到H值最小的点
	std::priority_queue<myNode*, std::vector<myNode*>, myNodeGreater> openList;
	myNode* startNode = new myNode(startPoint[0], startPoint[1]);
	startNode->G = 0;
	startNode->H = (abs(endPoint[0] - startNode->x) + abs(endPoint[1] - startNode->y)) * 10;
	openList.push(startNode);
	while (!openList.empty()) {
		myNode* nowPos = openList.top();
		openList.pop();
		showStat(map, endPoint, closeList, nowPos);
		if (nowPos->x == endPoint[0] && nowPos->y == endPoint[1]) {
			std::cout << "AStar finished." << std::endl;
			return;
		}
		closeList.push_back({ nowPos->x, nowPos->y });
		for (int i = -1; i <= 1; ++i) {
			for (int j = -1; j <= 1; ++j) {
				if ((i || j) && i + nowPos->x >= 0 && i + nowPos->x < n && j + nowPos->y >= 0 && j + nowPos->y < m && map[j + nowPos->y][i + nowPos->x] == '.' && !find(closeList, {i + nowPos->x, j + nowPos->y})) {
					myNode* temp = new myNode(i + nowPos->x, j + nowPos->y);
					temp->G = nowPos->G + ((!i || !j) ? 10 : 14);
					temp->H = (abs(endPoint[0] - temp->x) + abs(endPoint[1] - temp->y)) * 10;
					// 这里其实有个隐藏的问题，同一个点会多次被放进openList，带来更多的开销。
					openList.push(temp);
				}
			}
		}
	}
	std::cout << "AStar failed." << std::endl;
}