#include <iostream>
using namespace std;

/**
 * Starting from Gauss' formula for the sum of the first N natural numbers:
 *      1 + 2 + 3 + ... + n = n * (n + 1) / 2
 * If we multiply side by side by a number, we get all its multiples. For example, for 3:
 *      3 * (1 + 2 + 3 + ... + n) = 3 + 6 + 9 + ... + 3 * n = 3 * n * (n + 1) / 2 
 * */
int SumDivisibleByN(int n, int max) {
    int p = max / n;
    return n * (p * (p + 1)) / 2;
}

int main() {
    int max = 999;
    // To avoid adding multiples of 3 and 5 twice, we subtract multiples of 3 * 5 = 15
    int sum = SumDivisibleByN(3, max) + SumDivisibleByN(5, max) - SumDivisibleByN(15, max);
    cout << "Sum: " << sum << endl;
    return 0;
}