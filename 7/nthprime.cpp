#include <iostream>
#include <cmath>
#include <cstdint>
#include <cstring>

using namespace std;

/**
* The sieve of Erathostenes, used here, is more efficient than trial division, at least in time (not memory).
* Memory performance can be improved by using a segmented sieve.
* Also, Erathostenes' algorithm can be improved to have O(n) time complexity.
* Finally, consider the Sieve of Atkin, which has as slightly better time complexity, at the cost of a more
* complex algorithm.
 */
uint64_t nthPrime(uint64_t n ) {
	// Estimate an upper bound for the nthPrime, so as to limit the sieve
	uint64_t upperBound = uint64_t(ceil(n * log(n*log(n))));

	// Allocate the sieve
	bool prime[upperBound + 1];
	std::memset(prime, true, sizeof(prime));

	// Cross out non primes
	for (uint64_t p = 2; p*p <= upperBound; p++) {
		if (prime[p]) {
			for ( uint64_t k = p * p; k <= upperBound; k += p) {
				prime[k] = false;
			}
		}
	}

	// Count primes in the sieve until the nth prime
	uint64_t nPrime = 0;
    uint64_t primeValue = 0;
	for (primeValue = 2; nPrime != n; primeValue++) {
		if (prime[primeValue]) {
			nPrime++;
		}
	}
	return primeValue - 1;
}

int main() {
	uint64_t expectedAnswer = 104743;
	uint64_t answer = nthPrime(10001);
	if (answer == expectedAnswer) {
		cout << "PASSED" << endl;
	} else {
		cout << "FAILED (expected " << expectedAnswer << ", got " << answer << ")" << endl;
	}
    return 0;
}