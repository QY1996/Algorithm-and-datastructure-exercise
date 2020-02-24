#include "sort.h"

void quick_sort(std::vector<int>& arr, int begin, int end, bool verbose) {
	if (begin >= end) return;
	int front = begin, back = end;
	while (front < back) {
		if (arr[front + 1] < arr[front]) {
			std::swap(arr[front], arr[front + 1]);
			++front;
		}
		else {
			std::swap(arr[back], arr[front + 1]);
			--back;
		}
	}
	quick_sort(arr, begin, front - 1, verbose);
	quick_sort(arr, front + 1, end, verbose);
	if (verbose) show(arr);
}

void quick_sort(std::vector<int>& arr, bool verbose) {
	quick_sort(arr, 0, arr.size() - 1, verbose);
}