#include <iostream>

using namespace std;

/**
* Just like the sum of natural numbers, the sum of its squares has a closed expression:
* sum_{i=1}^{n}{i^2} = n * (n+1) * (2n + 1) / 6
* Therefore, this can be solved in O(1) for all n
 */
uint64_t squareSumDiff(uint64_t n ) {
	uint64_t sumOfSquares = n * (n + 1) * (2*n + 1) / 6;
	uint64_t sum = n * (n + 1) / 2;
	return (sum * sum) - sumOfSquares;
}

int main() {
	uint64_t expectedAnswer = 25164150;
	uint64_t answer = squareSumDiff(100);
	if (answer == expectedAnswer) {
		cout << "PASSED" << endl;
	} else {
		cout << "FAILED (expected " << expectedAnswer << ", got " << answer << ")" << endl;
	}
    return 0;
}