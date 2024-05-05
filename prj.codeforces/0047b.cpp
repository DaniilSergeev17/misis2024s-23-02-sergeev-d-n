#include <iostream>
#include <string>
#include <map>
#include <algorithm>

int main() {
    std::map<char, int> weight;
    for (int i = 0; i < 3; ++i) {
        std::string comparison;
        std::cin >> comparison;
        char more = comparison[0];
        char less = comparison[2];

        if (comparison[1] == '>') {
            weight[more]++;
            weight[less]--;
        }
        else {
            weight[more]--;
            weight[less]++;
        }
    }


    std::string result = "ABC";
    if (weight[result[0]] < weight[result[1]] && weight[result[1]] < weight[result[2]]) {
        std::cout << result << '\n';
        return 0;
    }
    while (std::next_permutation(result.begin(), result.end())) {
        if (weight[result[0]] < weight[result[1]] && weight[result[1]] < weight[result[2]]) {
            std::cout << result << '\n';
            return 0;
        }
    }
   

    std::cout << "Impossible" << '\n';
    return 0;
}
