#include <iostream>
#include <string>

int sum_of_digits(const std::string& n) {
    int sum = 0;
    for (char digit : n) {
        sum += digit - '0'; 
    }
    return sum;
}

int main() {
    std::string n;
    std::cin >> n;

    int count = 0;
    while (n.length() > 1) { 
        n = std::to_string(sum_of_digits(n)); 
        count++;
    }

    std::cout << count << '\n';
}