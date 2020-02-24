#include <algorithm>
#include "sort.h"

void radix_sort(std::vector<int>& arr, bool verbose) {
	int max = *std::max_element(arr.begin(), arr.end());
	std::vector<std::vector<int>> buckets(10);
	int ratio = 1;
	while (max) {
		for (int i : arr) {
			buckets[(i / ratio) % 10].push_back(i);
		}

		int index = 0;
		for (int i = 0; i < 10; ++i) {
			for (int i : buckets[i]) {
				arr[index] = i;
				++index;
			}
			buckets[i].clear();
		}

		max /= 10;
		ratio *= 10;

		if (verbose) show(arr);
	}
}