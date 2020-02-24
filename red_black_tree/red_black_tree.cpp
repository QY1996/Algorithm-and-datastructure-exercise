#include <iostream>
#include <stack>
#include <queue>
#include "red_black_tree.h"

#define BLACK false
#define RED true

struct myNode {
	int val;
	myNode* left;
	myNode* right;
	myNode* parent;
	bool color; // true means red, false means black.
	bool isLeaf;
	myNode(int v, bool c = BLACK, bool l = false) :val(v), left(nullptr), right(nullptr), parent(nullptr), color(c), isLeaf(l) {}
	~myNode() {
		if (left) delete left;
		if (right) delete right;
	}
};

RedBlackTree::RedBlackTree() :root(nullptr) {}

RedBlackTree::~RedBlackTree() {
	if (root) delete root;
}

void RedBlackTree::turnLeft(myNode* node) {
	if (node == root) {
		root = node->right;
		root->parent = nullptr;
		node->right = root->left;
		node->right->parent = node;
		root->left = node;
		node->parent = root;
	}
	else {
		if (node->parent->left == node) {
			node->parent->left = node->right;
		}
		else {
			node->parent->right = node->right;
		}
		node->right->parent = node->parent;
		myNode* temp = node->right;
		node->right = temp->left;
		node->right->parent = node;
		temp->left = node;
		node->parent = temp;
	}
}

void RedBlackTree::turnRight(myNode* node) {
	if (node == root) {
		root = node->left;
		root->parent = nullptr;
		node->left = root->right;
		node->left->parent = node;
		root->right = node;
		node->parent = root;
	}
	else {
		if (node->parent->right == node) {
			node->parent->right = node->left;
		}
		else {
			node->parent->left = node->left;
		}
		node->left->parent = node->parent;
		myNode* temp = node->left;
		node->left = temp->right;
		node->left->parent = node;
		temp->right = node;
		node->parent = temp;
	}
}

void RedBlackTree::insert(int val) {
	if (!root) {
		root = new myNode(val, BLACK);
		root->left = new myNode(0, BLACK, true);
		root->right = new myNode(0, BLACK, true);
		root->left->parent = root;
		root->right->parent = root;
		return;
	}

	myNode* toInsert = root;
	while (!toInsert->isLeaf) {
		if (toInsert->val > val) toInsert = toInsert->left;
		else if (toInsert->val < val) toInsert = toInsert->right;
		else return;
	}

	toInsert->val = val;
	toInsert->isLeaf = false;
	toInsert->left = new myNode(0, BLACK, true);
	toInsert->right = new myNode(0, BLACK, true);
	toInsert->left->parent = toInsert;
	toInsert->right->parent = toInsert;
	toInsert->color = RED;
	while (true){
		if (toInsert == root) {
			toInsert->color = BLACK;
			return;
		}
		if (toInsert->parent->color == BLACK) {
			return;
		}
		else {
			if (toInsert->parent->parent->left == toInsert->parent) {
				#define uncle toInsert->parent->parent->right
				if (uncle->color == RED) {
					toInsert->parent->color = BLACK;
					uncle->color = BLACK;
					toInsert = toInsert->parent->parent;
					toInsert->color = RED;
					continue;
				}
				else {
					if (toInsert->parent->right == toInsert) {
						turnLeft(toInsert->parent);
						toInsert = toInsert->left;
					}
					toInsert->parent->color = BLACK;
					toInsert->parent->parent->color = RED;
					turnRight(toInsert->parent->parent);
					return;
				}
			}

			else {
				#define uncle toInsert->parent->parent->left
				if (uncle->color == RED) {
					toInsert->parent->color = BLACK;
					uncle->color = BLACK;
					toInsert = toInsert->parent->parent;
					toInsert->color = RED;
					continue;
				}
				else {
					if (toInsert->parent->left == toInsert) {
						turnRight(toInsert->parent);
						toInsert = toInsert->right;
					}
					toInsert->parent->color = BLACK;
					toInsert->parent->parent->color = RED;
					turnLeft(toInsert->parent->parent);
					return;
				}
			}
		}
	}
}

myNode* RedBlackTree::search(int val) {
	myNode* temp = root;
	while (temp) {
		if (temp->isLeaf) return nullptr;
		if (temp->val < val) {
			temp = temp->right;
		}
		else if (temp->val > val) {
			temp = temp->left;
		}
		else return temp;
	}
	return nullptr;
}

void RedBlackTree::simpleDelete(myNode* toDel) {
	if (toDel->parent->left == toDel) {
		toDel->parent->left = new myNode(0, BLACK, true);
		delete toDel;
	}
	else {
		toDel->parent->right = new myNode(0, BLACK, true);
		delete toDel;
	}
}

void RedBlackTree::del(int val) {
	myNode* toDel = search(val);
	if (!toDel) return;
	while (!(toDel->left->isLeaf && toDel->right->isLeaf)) {
		if (!(toDel->left->isLeaf || toDel->right->isLeaf)) {
			myNode* exchange = toDel->right;
			while (!exchange->left->isLeaf) exchange = exchange->left;
			int temp = toDel->val;
			toDel->val = exchange->val;
			exchange->val = temp;
			toDel = exchange;
		}
		else {
			if (toDel->left->isLeaf) {
				int temp = toDel->val;
				toDel->val = toDel->right->val;
				toDel->right->val = temp;
				toDel = toDel->right;
				continue;
			}
			else {
				int temp = toDel->val;
				toDel->val = toDel->left->val;
				toDel->left->val = temp;
				toDel = toDel->left;
				continue;
			}
		}
	}

	if (toDel == root) {
		root = nullptr;
		delete toDel;
		return;
	}

	if (toDel->color == RED) {
		simpleDelete(toDel);
	}

	else {
		myNode* toDestroy = toDel;
		while (true){
			if (toDel == root) break;
			if (toDel->parent->left == toDel) {
				#define brother toDel->parent->right
				if (brother->color == RED) {
					toDel->parent->color = RED;
					brother->color = BLACK;
					turnLeft(toDel->parent);
					continue;
				}
				else {
					if (brother->right->color == RED) {
						brother->color = toDel->parent->color;
						toDel->color = BLACK;
						brother->right->color = BLACK;
						turnLeft(toDel->parent);
						break;
					}
					else if(brother->left->color == RED){
						brother->left->color = BLACK;
						brother->color = RED;
						turnRight(brother);
						continue;
					}
					else {
						brother->color = RED;
						toDel = toDel->parent;
						continue;
					}
				}
			}
			else {
				#define brother toDel->parent->left
				if (brother->color == RED) {
					toDel->parent->color = RED;
					brother->color = BLACK;
					turnRight(toDel->parent);
					continue;
				}
				else {
					if (brother->left->color == RED) {
						brother->color = toDel->parent->color;
						toDel->color = BLACK;
						brother->left->color = BLACK;
						turnRight(toDel->parent);
						break;
					}
					else if (brother->right->color == RED) {
						brother->right->color = BLACK;
						brother->color = RED;
						turnLeft(brother);
						continue;
					}
					else {
						brother->color = RED;
						toDel = toDel->parent;
						continue;
					}
				}
			}
		}
		simpleDelete(toDestroy);
	}
}

int RedBlackTree::getLayers() {
	if (!root) return 0;
	int layers = 0;
	myNode* temp = root, *last = root;
	std::queue<myNode*> q;
	q.push(root);
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		if (!temp->left->isLeaf) q.push(temp->left);
		if (!temp->right->isLeaf) q.push(temp->right);
		if (temp == last) {
			++layers;
			if(!q.empty()) last = q.back();
		}
	}
	return layers;
}