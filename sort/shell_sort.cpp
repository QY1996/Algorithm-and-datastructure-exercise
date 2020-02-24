#include "sort.h"

void shell_sort(std::vector<int>& arr, bool verbose) {
	int length = arr.size();
	int gap = length / 2;
	while (gap) {
		for (int base = 0; base < gap; ++base) {
			// Ö±½Ó²åÈëÅÅÐò
			int index = base;
			while (index < length - gap) {
				for (int i = base; i <= index; i += gap) {
					if (arr[index + gap] < arr[i]) {
						int temp = arr[index + gap];
						for (int j = index + gap; j > i; j -= gap) {
							arr[j] = arr[j - gap];
						}
						arr[i] = temp;
					}
				}
				index += gap;
			}
		}
		gap /= 2;
		if (verbose) show(arr);
	}
}