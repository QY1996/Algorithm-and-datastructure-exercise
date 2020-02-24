#include "trie_tree.h"
#include <vector>
#include <string>
struct myNode {
	char val;
	std::vector<myNode*> next;
	bool endNode;
	myNode(char c) {
		val = c;
		endNode = false;
	}
};

Trie::Trie() {
	root = new myNode('#');
}

bool Trie::search(std::string word) {
	myNode* temp = root;
	bool found;
	for (char c : word) {
		found = false;
		for (auto ptr : temp->next) {
			if (ptr->val == c) {
				temp = ptr;
				found = true;
				break;
			}
		}
		if (!found) {
			return false;
		}
	}
	return temp->endNode;
}

void Trie::insert(std::string word) {
	myNode* temp = root, * temp2;
	bool found;
	for (char c : word) {
		found = false;
		for (auto ptr : temp->next) {
			if (ptr->val == c) {
				temp = ptr;
				found = true;
				break;
			}
		}
		if (!found) {
			temp2 = new myNode(c);
			temp->next.push_back(temp2);
			temp = temp2;
		}
	}
	temp->endNode = true;
}

bool Trie::startsWith(std::string prefix) {
	myNode* temp = root;
	bool found;
	for (char c : prefix) {
		found = false;
		for (auto ptr : temp->next) {
			if (ptr->val == c) {
				temp = ptr;
				found = true;
				break;
			}
		}
		if (!found) {
			return false;
		}
	}
	return true;
}