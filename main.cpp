#include <iostream>

using namespace std;

int sum_of_squares(int n, int acc) {
    if (n == 0) return acc;
    return sum_of_squares(n - 1, acc + n * n);
}

int main() {
    int n = 5;
    cout << sum_of_squares(n, 0) << '\n';
    return 0;
}