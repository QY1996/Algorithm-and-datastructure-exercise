#include <random>
#include "sort.h"

void show(std::vector<int>& arr) {
	for (int i : arr) std::cout << i << " ";
	std::cout << std::endl;
}

int main() {
	std::cout << "Please input the amount of numbers." << std::endl;
	int num;
	std::cin >> num;
	std::cout << "Please input the maximum value of numbers." << std::endl;
	int max;
	std::cin >> max;
	++max;
	std::cout << "Please choose the algorithm you want to use.\n\
		1: bubble sort;\n\
		2: bucket sort;\n\
		3: counting sort;\n\
		4: heap sort;\n\
		5: insertion sort;\n\
		6: merge sort;\n\
		7: quick sort;\n\
		8: radix sort;\n\
		9: selection sort;\n\
		0: shell sort;\n\
		others: quit." << std::endl;
	while (true) {
		int choose;
		std::cin >> choose;
		std::vector<int> toSort;
		for (int i = 0; i < num; ++i) {
			toSort.push_back(std::rand() % max + 1);
		}
		std::cout << "The array to be sorted is:" << std::endl;
		show(toSort);
		std::cout << "Sort begin..." << std::endl;
		switch (choose) {
		case 1:
			bubble_sort(toSort, true);
			break;
		case 2:
			bucket_sort(toSort, true);
			break;
		case 3:
			counting_sort(toSort, true);
			break;
		case 4:
			heap_sort(toSort, true);
			break;
		case 5:
			insertion_sort(toSort, true);
			break;
		case 6:
			merge_sort(toSort, true);
			break;
		case 7:
			quick_sort(toSort, true);
			break;
		case 8:
			radix_sort(toSort, true);
			break;
		case 9:
			selection_sort(toSort, true);
			break;
		case 0:
			shell_sort(toSort, true);
			break;
		default:
			return 0;
		}
		std::cout << "Please give me another input." << std::endl;
	}
	return 0;
}