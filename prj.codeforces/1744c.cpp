#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		int s, max=0, k=0;
		bool is_find=false;
		char r;
		std::string st;
		std::cin >> s >> r;
		std::cin >> st;
		// ïðîõîä ïî âñåé ñòðîêå
		for (int j = 0; j < s; j++) {
			if (is_find) {
				if (st[j] == 'g') {
					if (k > max) {
						max = k;
					}
					k = 0;
					is_find = false;
				}
				else {
					k += 1;
				}
			}
			else {
				if (st[j] == r) {
					k += 1;
					is_find = true;
				}
			}
		}
		// íà÷èíàåì ñ êîíöà
		for (int j = 0; j < s; j++) {
			if (!is_find) {
				break;
			}
			if (is_find) {
				if (st[j] == 'g') {
					if (k > max) {
						max = k;
					}
					break;
				}
				else {
					k += 1;
				}
			}
			else {
				break;
			}
		}
		if (r == 'g') {
			std::cout << 0 << '\n';
		}
		else {
			std::cout << max << '\n';
		}
	}
	
}
