package main

import (
	"fmt"
	"strconv"
)

/** We want the smallest common multiple of 1, 2, ... 20
* Since it has to be a multiple of 20, we iterate over the multiples of
* 20, and check it it divisible by the rest, starting from 19 downwards
* (because that is more restrictive and will skip faster).
 */
func smallestMultiple() uint64 {
	var smallestMultipleFound bool = false
	var multiple uint64 = 0
	// We don't check 10, 5, 4 and 2 because if a number is divisible by 20, it is divisible by those
	var divisorsToCheck = [...]uint64{19, 18, 17, 16, 15, 14, 13, 12, 11, 9, 8, 7, 6, 3}
	var i uint64
	for i = 1; !smallestMultipleFound; i++ {
		multiple = i * 20
		smallestMultipleFound = true
		for j := 0; j < 14 && smallestMultipleFound; j++ {
			smallestMultipleFound = (multiple%divisorsToCheck[j] == 0)
		}
	}
	return multiple
}

func main() {
	var expectedAnswer uint64 = 232792560
	var answer uint64 = smallestMultiple()
	if answer == expectedAnswer {
		fmt.Println("PASSED")
	} else {
		fmt.Println("FAILED (expected " + strconv.FormatUint(expectedAnswer, 10) + ", got " + strconv.FormatUint(answer, 10) + ")")
	}
}
