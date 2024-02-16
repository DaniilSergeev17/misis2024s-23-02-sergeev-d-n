#include <iostream>

int main() {
    int N = 0;
    int M = 0;
    int S = 0;
    std::cin >> N >> M >> S;
    bool isSecondPlayerWins = (N <= S && M <= S) ||
        (N <= S && (M % (S + 1)) == 0) ||
        (M <= S && (N % (S + 1)) == 0);

    if (isSecondPlayerWins) {
        std::cout << 2 << "\n";
    }
    else {
        std::cout << 1 << "\n";
    }
}