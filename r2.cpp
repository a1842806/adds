#include <iostream>

void stars(int n) {
    if (n == 0) 
    {
        std::cout << std::endl;
        return;
    }
    std::cout << '*';
    stars(n - 1);   
}