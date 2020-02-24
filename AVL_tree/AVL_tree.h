// Data struct of red black tree.
struct myNode;

class AVLTree {
private:
	myNode* root;
	myNode* turnLeft(myNode* node);
	myNode* turnRight(myNode* node);
	int getHeight(myNode* node);

	myNode* insert(myNode* tempRoot, int val);
	myNode* del(myNode* tempRoot, int val);
public:
	AVLTree();
	~AVLTree();

	int getHeight();
	void insert(int val);
	myNode* search(int val);
	void del(int val);
};