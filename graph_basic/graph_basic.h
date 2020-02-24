// 定义使用邻接表的图结构
#include<vector>
struct eNode {
	int vertex;
	int weight;
	eNode* next;
	eNode(int v, int w) :vertex(v), weight(w), next(nullptr) {}
	~eNode() {
		if (next) delete next;
	}
};

struct vNode {
	int vertex;
	eNode* next;
	vNode(int v) :vertex(v), next(nullptr) {}
	~vNode() {
		if (next) delete next;
	}
};

class graph {
private:
	void DFS(int index, int& visited);
public:
	bool dir; //是否为有向图
	std::vector<vNode*> vertexs;
	// 输入邻接矩阵生成图
	graph(bool d, std::vector<std::vector<int>>& matrix);
	~graph();

	void DFS();
	void BFS();
};