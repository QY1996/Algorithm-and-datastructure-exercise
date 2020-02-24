#include <algorithm>
#include "sort.h"

void counting_sort(std::vector<int>& arr, bool verbose) {
	int min = *std::min_element(arr.begin(), arr.end());
	int max = *std::max_element(arr.begin(), arr.end());

	int* count = new int[max - min + 1];
	memset(count, 0, sizeof(int) * (max - min + 1));
	for (int i : arr) ++count[i - min];
	int index = 0;
	for (int i = 0; i <= max - min; ++i) {
		while (count[i]) {
			arr[index] = i + min;
			++index;
			--count[i];
		}
	}
	if (verbose) show(arr);
}