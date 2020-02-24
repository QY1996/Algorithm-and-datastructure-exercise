#include <iostream>
#include <string>
#include "AStar.h"

std::vector<int> getPos(std::string& str) {
	int index;
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == ',') {
			index = i;
			break;
		}
	}
	return std::vector<int>({ atoi(str.substr(0, index).c_str()), atoi(str.substr(index + 1, str.length() - index - 1).c_str()) });
}

int main() {
	std::cout << "This is a test of AStar. Please input the size of map." << std::endl;
	int s;
	std::cin >> s;
	std::vector<std::vector<char>>map(s, std::vector<char>(s, '.'));
	std::cout << "Please input the start point. Example: 0,0" << std::endl;
	std::string str;
	std::cin >> str;
	auto startPoint = getPos(str);
	std::cout << "Please input the end point. Example: 0,0" << std::endl;
	std::cin >> str;
	auto endPoint = getPos(str);
	std::cout << "Please input the end point. Example: 0,0. Input \"q\" to quit." << std::endl;
	while (true) {
		std::cin >> str;
		if (str == "q") break;
		auto temp = getPos(str);
		map[temp[1]][temp[0]] = '!';
	}
	AStar(map, startPoint, endPoint);
	return 0;
}