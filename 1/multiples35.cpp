#include <iostream>
using namespace std;

/**
 * Starting from Gauss' formula for the sum of the first N natural numbers:
 *      1 + 2 + 3 + ... + n = n * (n + 1) / 2
 * If we multiply side by side by a number, we get all its multiples. For example, for 3:
 *      3 * (1 + 2 + 3 + ... + n) = 3 + 6 + 9 + ... + 3 * n = 3 * n * (n + 1) / 2 
 * */
int sumDivisibleByN(int n, int max) {
    int p = max / n;
    return n * (p * (p + 1)) / 2;
}

int multiples35(int max) {
    // To avoid adding multiples of 3 and 5 twice, we subtract multiples of 3 * 5 = 15
    return sumDivisibleByN(3, max) + sumDivisibleByN(5, max) - sumDivisibleByN(15, max);
}

int main() {
    int expectedSum = 233168;
    int sum = multiples35(999);
    string message = sum == expectedSum? "PASSED" : "FAILED (expected " + std::to_string(expectedSum) + ", got " + std::to_string(sum) + ")";
    cout << message << endl;
    return 0;
}