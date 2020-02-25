#include <iostream>
#include <string>
#include "KMP.h"

int main() {
	std::cout << "Please input the string to be matched." << std::endl;
	std::string s;
	std::cin >> s;
	std::cout << "Please input pattern." << std::endl;
	std::string pat;
	std::cin >> pat;
	KMP(s, pat);
	return 0;
}