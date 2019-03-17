package main

import (
	"fmt"
	"strconv"
)

/**
* Just like the sum of natural numbers, the sum of its squares has a closed expression:
* sum_{i=1}^{n}{i^2} = n * (n+1) * (2n + 1) / 6
* Therefore, this can be solved in O(1) for all n
 */
func squareSumDiff(n uint64) uint64 {
	var sumOfSquares = n * (n + 1) * (2*n + 1) / 6
	var sum = n * (n + 1) / 2
	return (sum * sum) - sumOfSquares
}

func main() {
	var expectedAnswer uint64 = 25164150
	var answer uint64 = squareSumDiff(100)
	if answer == expectedAnswer {
		fmt.Println("PASSED")
	} else {
		fmt.Println("FAILED (expected " + strconv.FormatUint(expectedAnswer, 10) + ", got " + strconv.FormatUint(answer, 10) + ")")
	}
}
