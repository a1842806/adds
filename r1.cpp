int sum_of_squares(int n, int acc) {
    if (n == 0) return acc;
    return sum_of_squares(n - 1, acc + n * n);
}