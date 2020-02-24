#include <iostream>
#include "huffman_tree.h"

int main() {
	std::vector<char> characters;
	std::vector<int> weights;
	for (int i = 0; i < 26; ++i) {
		characters.push_back('a' + i);
		weights.push_back(26 - i);
	}
	huffmanNode* huffmanTree = create(characters, weights);
	
	std::cout << "Please input a string to be encoded." << std::endl;
	std::string s;
	std::cin >> s;
	std::string e = encode(huffmanTree, s);
	std::cout << "Encoded cipher is:" << e << std::endl;
	std::string d = decode(huffmanTree, e);
	std::cout << "Decoded string is:" << d << std::endl;

	delete huffmanTree;

	return 0;
}