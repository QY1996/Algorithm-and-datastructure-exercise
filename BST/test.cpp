#include <iostream>
#include <string>
#include "BST.h"

int main() {
	std::cout << "This is a test of BST, please input nums to choose function.\n\
		1: insert;\n\
		2: search;\n\
		3: delete;\n\
		4: traverse;\n\
		others: quit." << std::endl;
	BST bst;
	char choose;
	std::cin >> choose;
	std::cin.clear();
	std::cin.sync();
	while ('1' <= choose && choose <= '4') {
		int v;
		switch (choose) {
		case '1':
			std::cout << "Input the number to be inserted:" << std::endl;
			std::cin >> v;
			bst.insert(v);
			break;
		case'2':
			std::cout << "Input the number to be searched:" << std::endl;
			std::cin >> v;
			if(bst.search(v)) std::cout << v << " found." << std::endl;
			else std::cout << v << " not found." << std::endl;
			break;
		case'3':
			std::cout << "Input the number to be deleted:" << std::endl;
			std::cin >> v;
			bst.del(v);
			break;
		case'4':
			bst.traverse();
			break;
		default:
			return 0;
		}
		std::cout << "Please give me another input." << std::endl;
		std::cin >> choose;
	}
	return 0;
}