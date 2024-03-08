#include <iostream>
#include <vector>


int index_of_last(std::vector<int> vec) {
	int idx = -1;
	for (int i = 0; i < vec.size(); i += 1) {
		if (vec[i] == 1) {
			idx = i;
		}
	}
	return idx;
}

int index_of_first(std::vector<int> vec) {
	for (int i = 0; i < vec.size(); i += 1) {
		if (vec[i] == 1) {
			return i;
		}
	}
}

int sum_of_el(std::vector<int> vec) {
	int k = 0;
	for (int i = 0; i < vec.size(); i += 1) {
		k += vec[i];
	}
	return k;
}

int main() {
	int t = 0;
	std::cin >> t;
	std::vector<int> answers;
	for (int i = 0; i < t; i += 1) {
		int n = 2;
		std::cin >> n;
		std::vector<int> lst;
		for (int j = 0; j < n; j += 1) {
			int input = 0;
			std::cin >> input;
			lst.push_back(input);
		}
		int index_first = index_of_first(lst);
		int index_last = index_of_last(lst);
		int count_ones = sum_of_el(lst);
		answers.push_back(index_last - index_first - count_ones + 1);
	}
	for (int j = 0; j < answers.size(); j += 1) {
		std::cout << answers[j] << "\n";
	}
}