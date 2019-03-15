#include <iostream>
using namespace std;

/**
* Every third term is even, so we can avoid testing if the term is even
* by only adding f1, f4, f7...
*/
unsigned int evenFibonacciSum(unsigned int max) {
	unsigned int sum = 0;
	unsigned int fn = 1;
	unsigned int fn1 = 1;
	unsigned int fn2 = fn + fn1;
	while (fn2 < max) {
		sum += fn2;
		fn = fn1 + fn2;
		fn1 = fn2 + fn;
		fn2 = fn + fn1;
	}
	return sum;
}

int main() {
	unsigned int expectedSum = 4613732;
	unsigned int sum = evenFibonacciSum(4000000);
	if (sum == expectedSum) {
		cout << "PASSED" << endl;
	} else {
		cout << "FAILED" << endl;
	}
}