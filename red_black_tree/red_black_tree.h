// Data struct of red black tree.
struct myNode;

class RedBlackTree {
private:
	myNode* root;
	void turnLeft(myNode* node);
	void turnRight(myNode* node);
	void simpleDelete(myNode* node);
public:
	RedBlackTree();
	~RedBlackTree();

	void insert(int val);
	myNode* search(int val);
	void del(int val);
	int getLayers();
};