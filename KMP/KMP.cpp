#include <vector>
#include <iostream>
#include "KMP.h"

void KMP(std::string& s, std::string& pat) {
	int patSize = pat.size();
	if (!patSize) return;
	std::vector<int> next(patSize, -1);
	if (patSize > 1) next[1] = 0;
	for (int i = 2; i < patSize; ++i) {
		int temp = next[i - 1];
		while (temp >= 0 && pat[temp] != pat[i]) {
			temp = next[temp];
		}
		next[i] = temp + 1;
	}
	int i = 0, j = 0;
	int sSize = s.size();
	while (i < sSize) {
		std::cout << s << std::endl;
		std::string temp;
		for (int k = 0; k < i - j; ++k) temp.push_back(' ');
		temp += pat;
		std::cout << temp << std::endl;

		if (s[i] == pat[j]) {
			if (j == patSize - 1) {
				std::cout << "Found match!" << std::endl;
				if (j) j = next[j];
				else j = 0;
				++i;
				continue;
			}
			++i;
			++j;
		}
		else {
			if (j) j = next[j];
			else ++i;
		}
	}
}