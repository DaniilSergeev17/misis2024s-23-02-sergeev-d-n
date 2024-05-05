#include <iostream>
#include <vector>

int main() {
	int n = 1;
	std::cin >> n;
	int maxi = 0;
	for (int i = 0; i < n; ++i) {
		int h = 1;
		std::cin >> h;
		maxi = std::max(maxi, h);
	}

	std::cout << maxi;
}