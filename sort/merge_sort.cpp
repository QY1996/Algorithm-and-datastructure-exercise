#include "sort.h"

void merge_sort(std::vector<int>& arr, int begin, int end, bool verbose) {
	if (begin == end) return;
	merge_sort(arr, begin, (begin + end) / 2, verbose);
	merge_sort(arr, (begin + end) / 2 + 1, end, verbose);
	std::vector<int> temp;
	int left = begin, right = (begin + end) / 2 + 1;
	while (left <= (begin + end) / 2 && right <= end) {
		if (arr[left] <= arr[right]) {
			temp.push_back(arr[left]);
			++left;
		}
		else {
			temp.push_back(arr[right]);
			++right;
		}
	}
	if (left <= (begin + end) / 2) {
		temp.insert(temp.end(), arr.begin() + left, arr.begin() + (begin + end) / 2 + 1);
	}
	else {
		temp.insert(temp.end(), arr.begin() + right, arr.begin() + end + 1);
	}
	for (int i = begin; i <= end; ++i) arr[i] = temp[i - begin];
	if (verbose) show(arr);
}

void merge_sort(std::vector<int>& arr, bool verbose) {
	merge_sort(arr, 0, arr.size() - 1, verbose);
}