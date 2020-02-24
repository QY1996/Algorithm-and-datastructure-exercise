#include <iostream>
#include <stack>
#include "BST.h"

struct myNode {
	int val;
	myNode* left;
	myNode* right;
	myNode(int v) :val(v), left(nullptr), right(nullptr) {}
	~myNode() {
		if (left) delete left;
		if (right) delete right;
	}
};

BST::BST() :root(nullptr) {}

BST::~BST() {
	if(root) delete root;
}

void BST::insert(int val) {
	if (!root) {
		root = new myNode(val);
		return;
	}

	myNode* temp = root;
	while (temp->val != val) {
		if (temp->val < val) {
			if (temp->right) temp = temp->right;
			else {
				temp->right = new myNode(val);
				return;
			}
		}
		else {
			if (temp->left) temp = temp->left;
			else {
				temp->left = new myNode(val);
				return;
			}
		}
	}

	std::cout << "The BST already has a node:" << val << std::endl;
}

bool BST::search(int val) {
	myNode* temp = root;
	while (temp) {
		if (temp->val < val) {
			temp = temp->right;
		}
		else if (temp->val > val) {
			temp = temp->left;
		}
		else return true;
	}
	return false;
}

void BST::del(int val) {
	if (!root) return;
	myNode* toDel = nullptr;
	if (root->val == val) {
		toDel = root;
		if (!root->left) root = root->right;
		else {
			myNode* temp = root->left;
			while (temp->right) temp = temp->right;
			temp->right = root->right;
			root = root->left;
		}
	}
	else {
		myNode* parent, *child;
		parent = root;
		while (parent->left || parent->right) {
			if (parent->val > val) {
				child = parent->left;
				if (!child) break;
				if (child->val == val) {
					if (!child->left) {
						parent->left = child->right;
					}
					else {
						parent->left = child->left;
						myNode* temp = parent->left;
						while (temp->right) temp = temp->right;
						temp->right = child->right;
					}
					toDel = child;
					child->left = nullptr;
					child->right = nullptr;
					break;
				}
				parent = child;
			}
			else {
				child = parent->right;
				if (!child) break;
				if (child->val == val) {
					if (!child->right) {
						parent->right = child->left;
					}
					else {
						parent->right = child->right;
						myNode* temp = parent->right;
						while (temp->left) temp = temp->left;
						temp->left = child->left;
					}
					toDel = child;
					child->left = nullptr;
					child->right = nullptr;
					break;
				}
				parent = child;
			}
		}
	}
	if (toDel) delete toDel;
}

void BST::traverse() {
	std::cout << "The traverse of BST is:\n";
	std::stack<myNode*> s;
	myNode* temp = root;
	while (temp) {
		s.push(temp);
		temp = temp->left;
	}
	while (!s.empty()) {
		temp = s.top();
		s.pop();
		std::cout << temp->val << " ";
		temp = temp->right;
		while (temp) {
			s.push(temp);
			temp = temp->left;
		}
	}
	std::cout << std::endl;
}