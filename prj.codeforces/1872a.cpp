#include <iostream>
#include <cmath>

int main() {
    int k;
    float a, b, c;
    std::cin >> k;

    for (int i=0; k>i; ++i){
        std::cin >> a >> b >> c;

        if (a > b){
            std::cout << ceil((a-b) / (c*2))<<"\n";
        }
        else{
            std::cout << ceil((b-a) / (c*2))<<"\n";
        }
    }
}
