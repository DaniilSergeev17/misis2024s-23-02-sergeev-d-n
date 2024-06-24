#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k, point=0, res=0;
        std::cin >> n >> k;
        std::string st;
        std::cin >> st;
        for (int j = 0; j < n; j++) {
            char pp = st[j];
            if (pp == 'B') {
                if (point == 0) {
                    point = k - 1;
                    if (point == 0) {
                        res += 1;
                    }
                }
                else if (point != 0) {
                    if (point == 1) {
                        point = 0;
                        res += 1;
                    }
                    else {
                        point -= 1;
                    }
                }
            }
            else if (point != 0) {
                if (point == 1) {
                    point = 0;
                    res += 1;
                }
                else {
                    point -= 1;
                }
            }
        }
        if (point != 0) {
            res += 1;
        }
        std::cout << res << "\n";
    }

}
