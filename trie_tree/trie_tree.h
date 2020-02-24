// This implementation is my implementation on Leetcode NO.208
#include<string>

struct myNode;

class Trie {
private:
	myNode* root;
public:
	Trie();
	void insert(std::string word);
	bool search(std::string word);
	bool startsWith(std::string prefix);
};