#include "sort.h"

void bubble_sort(std::vector<int>& arr, bool verbose) {
	int length = arr.size();
	for (int i = length - 2; i >=0; --i) {
		for (int j = 0; j <= i; ++j) {
			if (arr[j] > arr[j + 1]) std::swap(arr[j], arr[j + 1]);
		}
		if (verbose) show(arr);
	}
}