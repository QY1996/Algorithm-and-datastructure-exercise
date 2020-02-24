#include "sort.h"

void insertion_sort(std::vector<int>& arr, bool verbose) {
	int length = arr.size();
	for (int i = 0; i < length - 1; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (arr[i + 1] < arr[j]) {
				int temp = arr[i + 1];
				arr.erase(arr.begin() + i + 1);
				arr.insert(arr.begin() + j, temp);
				break;
			}
		}
		if (verbose) show(arr);
	}
}