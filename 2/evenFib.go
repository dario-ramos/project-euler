package main
import "fmt"

/**
* Every third term is even, so we can avoid testing if the term is even
* by only adding f1, f4, f7...
*/
func evenFibonacciSum(max int) int {
	var sum int = 0
	var fn int = 1
	var fn1 int = 1
	var fn2 int = fn + fn1
	for fn2 < max {
		sum += fn2
		fn = fn1 + fn2
		fn1 = fn2 + fn
		fn2 = fn + fn1
	}
	return sum
}

func main() {
	var expectedSum int = 4613732
	var sum int = evenFibonacciSum(4000000)
	if sum == expectedSum {
		fmt.Println("PASSED")	
	} else {
		fmt.Println("FAILED")
	}
}