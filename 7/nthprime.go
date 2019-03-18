package main

import (
	"fmt"
	"math"
	"strconv"
)

/**
* The sieve of Erathostenes, used here, is more efficient than trial division, at least in time (not memory).
* Memory performance can be improved by using a segmented sieve.
* Also, Erathostenes' algorithm can be improved to have O(n) time complexity.
* Finally, consider the Sieve of Atkin, which has as slightly better time complexity, at the cost of a more
* complex algorithm.
 */
func nthPrime(n uint64) uint64 {
	// Estimate an upper bound for the nthPrime, so as to limit the sieve
	var upperBound uint64 = uint64(math.Ceil(float64(n) * math.Log(float64(n)*math.Log(float64(n)))))

	// Allocate the sieve
	var prime = make([]bool, upperBound+1)
	var i uint64
	for i = 0; i < upperBound; i++ {
		prime[i] = true
	}

	// Cross out non primes
	var p uint64
	for p = 2; p*p <= upperBound; p++ {
		if prime[p] {
			var k uint64
			for k = p * p; k <= upperBound; k += p {
				prime[k] = false
			}
		}
	}

	// Count primes in the sieve until the nth prime
	var nPrime uint64
	for p = 2; nPrime != n; p++ {
		if prime[p] {
			nPrime++
		}
	}
	return p - 1
}

func main() {
	var expectedAnswer uint64 = 104743
	var answer uint64 = nthPrime(10001)
	if answer == expectedAnswer {
		fmt.Println("PASSED")
	} else {
		fmt.Println("FAILED (expected " + strconv.FormatUint(expectedAnswer, 10) + ", got " + strconv.FormatUint(answer, 10) + ")")
	}
}
