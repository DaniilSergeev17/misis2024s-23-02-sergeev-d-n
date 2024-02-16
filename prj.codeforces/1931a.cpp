#include <iostream>
#include <string>
#include <vector>

int main() {
	int t = 0;
	std::cin >> t;
	std::vector<std::string> answer;
	for (int i = 0; i < t; i += 1) {
		int n = 0;
		std::cin >> n;
		bool flag = false;
		for (char j = 'a'; j <= 'z'; j += 1) {
			for (char k = 'a'; k <= 'z'; k += 1) {
				for (char l = 'a'; l <= 'z'; l += 1) {
					if (((j - 'a' + 1) + (k - 'a' + 1) + (l - 'a' + 1)) == n) {
						std::string trigram;
						trigram += j;
						trigram += k;
						trigram += l;
						answer.push_back(trigram);
						flag = true;
						break;
					}
				}
				if (flag) {
					break;
				}
			}
			if (flag) {
				break;
			}
		}
	}
	for (int i = 0; i < answer.size(); i += 1) {
		std::cout << answer[i] << "\n";
	}
}