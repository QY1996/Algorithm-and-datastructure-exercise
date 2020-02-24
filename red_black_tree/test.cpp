#include <iostream>
#include "red_black_tree.h"

int main() {
	std::cout << "Please input the tree's nodes." << std::endl;
	int nums;
	RedBlackTree tree;
	std::cin >> nums;
	for (int i = 0; i < nums; ++i) tree.insert(i);
	char choose;
	while (true) {
		std::cout << "Please input the operation you want to do.\n 1: search, 2:insert, 3:delete, 4:get layers of red black tree, others:quit." << std::endl;
		std::cin >> choose;
		std::cin.clear();
		std::cin.sync();
		switch (choose) {
		case '1':
			std::cout << "Please input the number you want to search." << std::endl;
			std::cin >> nums;
			if (tree.search(nums)) std::cout << "Found " << nums << std::endl;
			else std::cout <<  nums << " not found." << std::endl;
			break;
		case '2':
			std::cout << "Please input the number you want to insert." << std::endl;
			std::cin >> nums;
			tree.insert(nums);
			break;
		case '3':
			std::cout << "Please input the number you want to delete." << std::endl;
			std::cin >> nums;
			tree.del(nums);
			break;
		case '4':
			std::cout << "The layer of red black tree is: " << tree.getLayers() << "." << std::endl;
			break;
		default:
			return 0;
		}
	}
	return 0;
}