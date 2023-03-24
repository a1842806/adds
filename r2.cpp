#include <iostream>

void stars(int n) {
    if (n == 0) return;
    std::cout << '*';
    stars(n - 1);   
}