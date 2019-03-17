package main

import (
	"fmt"
	"strconv"
)

func isPalindrome(number uint64) bool {
	var s string = strconv.FormatUint(number, 10)
	for i := 0; i < len(s)/2; i++ {
		if s[i] != s[len(s)-1-i] {
			return false
		}
	}
	return true
}

func largestPalindromeProduct() uint64 {
	var a uint64
	var b uint64
	var largestPalindromeProduct uint64 = 0
	for a = 100; a <= 999; a++ {
		for b = 100; b <= 999; b++ {
			var product uint64 = a * b
			if isPalindrome(product) && product > largestPalindromeProduct {
				largestPalindromeProduct = product
			}
		}
	}
	return largestPalindromeProduct
}

func main() {
	var expectedAnswer uint64 = 906609
	var answer uint64 = largestPalindromeProduct()
	if answer == expectedAnswer {
		fmt.Println("PASSED")
	} else {
		fmt.Println("FAILED (expected " + strconv.FormatUint(expectedAnswer, 10) + ", got " + strconv.FormatUint(answer, 10) + ")")
	}
}
