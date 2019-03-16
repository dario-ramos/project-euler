package main
import (
	"fmt"
	"math"
	"strconv"
)

func largestPrimeFactor(n uint64) uint64 {
    // Divide n by 2 until it's odd, or zero 
    for n != 0 && n % 2 == 0 {
        n /= 2
    }
    // If it's zero, it's an even number
    if n == 0 {
        return 2
    }
	var largestPrimeFactor uint64 = 3
	var i uint64;
    for i = 3; i<uint64(math.Sqrt(float64(n))); i += 2 {
        for n % i == 0 {
			n = n/i;
			if i > largestPrimeFactor {
				largestPrimeFactor = i
			}
        }
    }
    // When n is a prime number larger than 2
    if n > 2 && n > largestPrimeFactor {
        largestPrimeFactor = n
    }
    return largestPrimeFactor
}

func main() {
	var expectedAnswer uint64 = 6857
	var answer uint64 = largestPrimeFactor(600851475143)
	if answer == expectedAnswer {
		fmt.Println("PASSED")
	} else {
		fmt.Println("FAILED (expected " + strconv.FormatUint(expectedAnswer, 10) + ", got " + strconv.FormatUint(answer, 10) + ")")
	}
}