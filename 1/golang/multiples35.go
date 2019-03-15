package main
import "fmt"

func sumDivisibleByN(n int, max int) int {
    var p int = max / n;
    return n * (p * (p + 1)) / 2;
}

func multiples35(max int) int {
	// To avoid adding multiples of 3 and 5 twice, we subtract multiples of 3 * 5 = 15
    return sumDivisibleByN(3, max) + sumDivisibleByN(5, max) - sumDivisibleByN(15, max);
}

func main() {
	var expectedSum int = 233168
	var sum int = multiples35(999)
	if sum == expectedSum {
		fmt.Println("PASSED")	
	} else {
		fmt.Println("FAILED")
	}
}