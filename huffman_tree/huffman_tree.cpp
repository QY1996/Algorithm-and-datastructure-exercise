#include <iostream>
#include <queue>
#include <stack>
#include "huffman_tree.h"

struct huffmanNode {
	int weight;
	char c;
	huffmanNode* left;
	huffmanNode* right;
	huffmanNode(int w, char _c = 0) :weight(w), c(_c), left(nullptr), right(nullptr) {}
	~huffmanNode() {
		if(left) delete left;
		if(right) delete right;
	}
};

huffmanNode* create(const std::vector<char>& characters, const std::vector<int>& weights) {
	int n = characters.size();
	if (!n || n != weights.size()) {
		std::cout << "Create fail, please check input." << std::endl;
		return nullptr;
	}

	// Use a min heap to creat huffman tree.
	struct huffmanGreater {
		bool operator () (huffmanNode* a, huffmanNode* b){
			return a->weight > b->weight;
		}
	};

	std::priority_queue<huffmanNode*, std::vector<huffmanNode*>, huffmanGreater> q;
	for (int i = 0; i < n; ++i) {
		q.push(new huffmanNode(weights[i], characters[i]));
	}

	huffmanNode* small1 = q.top(), *small2, *temp;
	q.pop();
	while (!q.empty()) {
		small2 = q.top();
		q.pop();
		temp = new huffmanNode(small1->weight + small2->weight);
		temp->left = small1;
		temp->right = small2;
		q.push(temp);
		small1 = q.top();
		q.pop();
	}

	std::cout << "Create success! \nTree structure is:\n";
	print(small1);
	std::cout << std::endl;

	return small1;
}

void print(huffmanNode* huffmanTree) {
	if (!huffmanTree->left && !huffmanTree->right) std::cout << huffmanTree->c;
	else {
		std::cout << "mid:(";
		print(huffmanTree->left);
		std::cout << ", ";
		print(huffmanTree->right);
		std::cout << ")";
	}
}

std::string encode(huffmanNode* huffmanTree, std::string input) {
	std::vector<std::string> tab(26);
	std::string temp;
	huffmanNode* root = nullptr;
	std::queue<std::string> q;
	q.push("");
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		root = huffmanTree;
		for (char c : temp) {
			if (c == '0') root = root->left;
			else root = root->right;
		}
		if (root->c) tab[root->c - 'a'] = temp;
		if (root->left) q.push(temp + '0');
		if (root->right) q.push(temp + '1');
	}
	temp.clear();
	for (char c : input) {
		temp += tab[c - 'a'];
	}
	return temp;
}

std::string decode(huffmanNode* huffmanTree, std::string input) {
	huffmanNode* root = huffmanTree;
	std::string s;
	for (char c : input) {
		if (root->c) {
			s += root->c;
			root = huffmanTree;
		}
		if (c == '0') root = root->left;
		else root = root->right;
	}
	if (root->c) {
		s += root->c;
	}
	return s;
}