#include <iostream>
#include <vector>

int count_murders(const std::vector<int>& arr, const int& idx) {
	int count = 0;
	int radius = 1;

	if (arr.size() == 1) {
		return arr[idx];
	}

	if (arr[idx] == 1) {
		count += 1;
	}

	int range = std::min(static_cast<int>(arr.size() - idx - 1), idx);
	for (size_t i = 0; i < range; ++i) {
		if (arr[idx - radius] + arr[idx + radius] == 2) {
			count += 2;
			radius += 1;
		}
		else {
			radius += 1;
		}
	}

	if (idx == range) {
		for (size_t i = idx + radius; i < arr.size(); ++i) {
			count += arr[i];
		}
	}
	else {
		for (int i = idx - radius; i >= 0; --i) { // int because of >= 0
			count += arr[i];
		}
	}
	return count;
}

int main() {
	int n = 0;
	int a = 1;
	std::cin >> n >> a;
	std::vector<int> murders;

	for (size_t i = 0; i < n; ++i) {
		int n_murders = 0;
		std::cin >> n_murders;
		murders.push_back(n_murders);
	}

	std::cout << count_murders(murders, a - 1);
}