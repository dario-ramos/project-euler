#include <iostream>

using namespace std;

/** We want the smallest common multiple of 1, 2, ... 20
* Since it has to be a multiple of 20, we iterate over the multiples of
* 20, and check it it divisible by the rest, starting from 19 downwards
* (because that is more restrictive and will skip faster).
*/
uint64_t smallestMultiple() {
    bool smallestMultipleFound = false;
    uint64_t multiple = 0;
    // We don't check 10, 5, 4 and 2 because if a number is divisible by 20, it is divisible by those
    int divisorsToCheck[14] = {19, 18, 17, 16, 15, 14, 13, 12, 11, 9, 8, 7, 6, 3};
    for(uint64_t i=1; !smallestMultipleFound; i++) {
        multiple = i * 20;
        smallestMultipleFound = true;
        for(auto i=0; i<14 && smallestMultipleFound; i++) {
            smallestMultipleFound = (multiple % divisorsToCheck[i] == 0);
        }
    }
    return multiple;
}

int main() {
	uint64_t expectedAnswer = 232792560;
	uint64_t answer = smallestMultiple();
	if (answer == expectedAnswer) {
		cout << "PASSED" << endl;
	} else {
		cout << "FAILED (expected " << expectedAnswer << ", got " << answer << ")" << endl;
	}
    return 0;
}