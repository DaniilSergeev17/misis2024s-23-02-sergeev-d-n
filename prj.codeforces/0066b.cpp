#include <iostream>
#include <vector>

int count_smaller_nearest(std::vector<int> arr, int idx) {
	int current_rhs = arr[idx];
	int current_lhs = arr[idx];
	int count_rhs = 0;
	int count_lhs = 0;
	for (size_t i = idx+1; i < arr.size(); ++i) {
		if (current_rhs >= arr[i]) {
			count_rhs += 1;
			current_rhs = arr[i];
		}
		else {
			break;
		}
	}
	for (size_t i = idx-1; i >= 0; --i) {
		if (current_lhs >= arr[i]) {
			count_lhs += 1;
			current_lhs = arr[i];
		}
		else {
			break;
		}
	}
	return count_rhs + count_lhs;
}

int main() {
	int n = 0;
	std::cin >> n;
	std::vector<int> vec;

	for (size_t i = 0; i < n; ++i) {
		int a = 0;
		std::cin >> a;
		vec.push_back(a);
	}

	if (n == 1) {
		std::cout << 1;
		return 0;
	}

	int maxi = 0;
	for (size_t i = 0; i < n; ++i) {
		int mid_res = count_smaller_nearest(vec, i);
		maxi = std::max(maxi, mid_res);
	}
	std::cout << maxi + 1; // don't forget to add current
}