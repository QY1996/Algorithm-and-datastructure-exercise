#include <algorithm>
#include "sort.h"

void bucket_sort(std::vector<int>& arr, int gap, int begin) {
	if (arr.size() < 2) return;
	if (!gap) {
		selection_sort(arr);
		return;
	}
	std::vector<std::vector<int>> buckets(10);
	for (int i : arr) {
		buckets[(i - begin) / gap].push_back(i);
	}
	for (int i = 0; i < 10; ++i) {
		bucket_sort(buckets[i], gap / 9, begin + gap * i);
	}
	int index = 0;
	for (auto bucket : buckets) {
		for (int i : bucket) {
			arr[index] = i;
			++index;
		}
	}
}

void bucket_sort(std::vector<int>& arr, bool verbose) {
	int min = *std::min_element(arr.begin(), arr.end());
	int max = *std::max_element(arr.begin(), arr.end());
	bucket_sort(arr, (max - min) / 9, min);
	if (verbose) show(arr);
}