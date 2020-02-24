#include "sort.h"

void selection_sort(std::vector<int>& arr, bool verbose) {
	int length = arr.size();
	for (int i = 0; i < length - 1; ++i) {
		int minIndex = i;
		for (int j = i; j < length; ++j) {
			if (arr[j] < arr[minIndex]) minIndex = j;
		}
		if (minIndex != i) std::swap(arr[i], arr[minIndex]);
		if (verbose) show(arr);
	}
}