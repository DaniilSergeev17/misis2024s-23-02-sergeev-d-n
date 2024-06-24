#include <iostream>
#include <vector>
#include <cstdlib> 

int main() {
	int t;
	std::cin >> t;
	for (int q = 0; q != t; q++) {
		int n, m, sx, sy, d, rr;
		std::cin >> n >> m >> sx >> sy >> d;
		bool t1 = true, t2 = true;
		for (int j = 1; j <= n; j++) {
			if ((std::abs(sx - j) + std::abs(sy-1)) <= d) {
				t1 = false;
			}
		}
		for (int j = 1; j <= m; j++) {
			if ((std::abs(sx - n) + std::abs(sy - j)) <= d) {
				t1 = false;
			}
		}
		for (int j = 1; j <= n; j++) {
			if ((std::abs(sx - j) + std::abs(sy - m)) <= d) {
				t2 = false;
			}
		}
		for (int j = 1; j <= m; j++) {
			if ((std::abs(sx-1) + std::abs(sy - j)) <= d) {
				t2 = false;
			}
		}
		if (t1 || t2) {
			std::cout << n + m - 2<<"\n";
		}
		else {
			std::cout << -1 << "\n";
		}
	}
}
