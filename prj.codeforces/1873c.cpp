#include <iostream>
#include <string>
#include <map>
#include <algorithm>


int main() {
	std::map<int, int> myDictionary;
	int point_1 = 1, point_2 = 1, t;
	std::cin >> t;
	myDictionary[0] = 1;
	myDictionary[1] = 2;
	myDictionary[2] = 3;
	myDictionary[3] = 4;
	myDictionary[4] = 5;
	myDictionary[5] = 5;
	myDictionary[6] = 4;
	myDictionary[7] = 3;
	myDictionary[8] = 2;
	myDictionary[9] = 1;

	const int rows = 10;
	const int cols = 10;

	for (int z = 0; z < t; z++) {
		int k = 0;
		for (int i = 0; i < rows; ++i) {
			std::string st;
			std::cin >> st;
			for (int j = 0; j < cols; ++j) {
				if (st[j] == 'X') {
					point_1 = myDictionary[i];
					point_2 = myDictionary[j];
					k += std::min(point_1, point_2);
				}

			}
		}
		std::cout << k<<'\n';
	}
	
}
