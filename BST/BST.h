// Data struct of binary search tree.
struct myNode;

class BST {
private:
	myNode* root;
public:
	BST();
	~BST();

	void insert(int val);
	bool search(int val);
	void del(int val);
	void traverse();
};