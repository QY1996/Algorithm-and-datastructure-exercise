#include<vector>

struct myNode {
	int x, y;
	int G, H;
	myNode(int x_, int y_) : x(x_), y(y_){}
};

void AStar(std::vector<std::vector<char>>& map, std::vector<int>& startPoint, std::vector<int>& endPoint);