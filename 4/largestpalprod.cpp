#include <iostream>
#include <cstdint>

using namespace std;

bool isPalindrome(uint64_t number) {
	string s = std::to_string(number);
	for (auto i = 0; i < s.length()/2; i++){
		if (s[i] != s[s.length()-1-i]) {
			return false;
		}
	}
	return true;
}

uint64_t largestPalindromeProduct() {
	uint64_t largestPalindromeProduct = 0;
	for (uint64_t a = 100; a <= 999; a++) {
		for (uint64_t b = 100; b <= 999; b++) {
			if (a > b) {
				continue;
			}
			uint64_t product = a * b;
			if (isPalindrome(product) && product > largestPalindromeProduct) {
				largestPalindromeProduct = product;
			}
		}
	}
	return largestPalindromeProduct;
}

int main() {
	uint64_t expectedAnswer = 906609;
	uint64_t answer = largestPalindromeProduct();
	if (answer == expectedAnswer) {
		cout << "PASSED" << endl;
	} else {
		cout << "FAILED (expected " << expectedAnswer << ", got " << answer << ")" << endl;
	}
}
