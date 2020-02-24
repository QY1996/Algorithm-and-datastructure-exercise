#include <iostream>
#include <stack>
#include <queue>
#include "AVL_tree.h"

struct myNode {
	int val;
	myNode* left;
	myNode* right;
	int height;
	myNode(int v) :val(v), left(nullptr), right(nullptr), height(1) {}
	~myNode() {
		if (left) delete left;
		if (right) delete right;
	}
};

AVLTree::AVLTree() :root(nullptr) {}

AVLTree::~AVLTree() {
	if (root) delete root;
}

int AVLTree::getHeight(myNode* node) {
	if (node) return node->height;
	else return 0;
}

int AVLTree::getHeight() {
	return getHeight(root);
}

myNode* AVLTree::turnLeft(myNode* node) {
	myNode* rtn = node->right;
	node->right = rtn->left;
	rtn->left = node;

	node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
	rtn->height = std::max(getHeight(rtn->left), getHeight(rtn->right)) + 1;
	return rtn;
}

myNode* AVLTree::turnRight(myNode* node) {
	myNode* rtn = node->left;
	node->left = rtn->right;
	rtn->right = node;

	node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
	rtn->height = std::max(getHeight(rtn->left), getHeight(rtn->right)) + 1;
	return rtn;
}

myNode* AVLTree::insert(myNode* node, int val) {
	if (node->val > val) {
		if (node->left) {
			node->left = insert(node->left, val);
			if (getHeight(node->left) - getHeight(node->right) > 1) {
				if (getHeight(node->left->left) > getHeight(node->left->right)) {
					return turnRight(node);
				}
				else {
					node->left = turnLeft(node->left);
					return turnRight(node);
				}
			}
		}
		else {
			node->left = new myNode(val);
		}
	}
	else if (node->val < val) {
		if (node->right) {
			node->right = insert(node->right, val);
			if (getHeight(node->right) - getHeight(node->left) > 1) {
				if (getHeight(node->right->right) > getHeight(node->right->left)) {
					return turnLeft(node);
				}
				else {
					node->right = turnRight(node->right);
					return turnLeft(node);
				}
			}
		}
		else {
			node->right = new myNode(val);
		}
	}
	else return node;

	node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
	return node;
}

void AVLTree::insert(int val) {
	if (!root) {
		root = new myNode(val);
	}
	else {
		root = insert(root, val);
	}
}

myNode* AVLTree::search(int val) {
	myNode* temp = root;
	while (temp) {
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

myNode* AVLTree::del(myNode* node, int val) {
	if (node->val > val) {
		node->left = del(node->left, val);
		if (getHeight(node->right) - getHeight(node->left) > 1) {
			if (getHeight(node->right->right) > getHeight(node->right->left)) {
				return turnLeft(node);
			}
			else {
				node->right = turnRight(node->right);
				return turnLeft(node);
			}
		}
	}
	else if (node->val < val) {
		node->right = del(node->right, val);
		if (getHeight(node->left) - getHeight(node->right) > 1) {
			if (getHeight(node->left->left) > getHeight(node->left->right)) {
				return turnRight(node);
			}
			else {
				node->left = turnLeft(node->left);
				return turnRight(node);
			}
		}
	}
	else {
		if (!node->left && !node->right) {
			delete node;
			return nullptr;
		}
		else if (getHeight(node->left) >= getHeight(node->right)) {
			myNode* temp = node->left;
			while (temp->right) temp = temp->right;
			node->val = temp->val;
			node->left = del(node->left, temp->val);
		}
		else {
			myNode* temp = node->right;
			while (temp->left) temp = temp->left;
			node->val = temp->val;
			node->right = del(node->right, temp->val);
		}
	}

	node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
	return node;
}

void AVLTree::del(int val) {
	root = del(root, val);
}