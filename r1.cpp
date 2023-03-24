int sum(int n, int acc) {
    if (n == 0) return acc;
    return sum(n - 1, acc + n * n);
}

int sum_of_squares(int n) {
    return sum(n, 0);
}
