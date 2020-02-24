#include "sort.h"

void heap_sort(std::vector<int>& arr, bool verbose) {
	int length = arr.size();
	// ¹¹½¨´ó¶¥¶Ñ
	for (int i = 1; i < length; ++i) {
		int index = i;
		while (index) {
			if (arr[index] > arr[(index - 1) / 2]) {
				std::swap(arr[index], arr[(index - 1) / 2]);
				index = (index - 1) / 2;
			}
			else break;
		}
	}

	// ÅÅÐò
	for (int i = length - 1; i >= 1; --i) {
		std::swap(arr[0], arr[i]);
		int index = 0;
		while (true) {
			int next = index;
			if (index * 2 + 1 < i && arr[index * 2 + 1] > arr[next]) next = index * 2 + 1;
			if (index * 2 + 2 < i && arr[index * 2 + 2] > arr[next]) next = index * 2 + 2;
			if (next == index) break;
			else {
				std::swap(arr[index], arr[next]);
				index = next;
			}
		}
		if (verbose) show(arr);
	}
}