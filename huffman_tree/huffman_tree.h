#include <vector>
#include <string>

// Data struct of huffman tree.
struct huffmanNode;

// Given a list of characters and their weights, return a huffman tree.
huffmanNode* create(const std::vector<char>& characters, const std::vector<int>& weights);

// Print a huffman tree;
void print(huffmanNode* huffmanTree);

// Automatic encode a string;
std::string encode(huffmanNode* huffmanTree, std::string input);

// Automatic decode a string
std::string decode(huffmanNode* huffmanTree, std::string input);