#include <iostream>
#include <cmath>
using namespace std;

unsigned long long int largestPrimeFactor(unsigned long long int n){
    // Divide n by 2 until it's odd, or zero 
    while(n != 0 && n % 2 == 0) {
        n /= 2;
    }
    // If it's zero, it's an even number
    if(n == 0) {
        return 2;
    }
    unsigned long long int largestPrimeFactor = 3;
    for(unsigned long long int i=3; i<sqrt(n); i += 2) {
        while( n % i == 0 ) {
            n = n/i;
            largestPrimeFactor = (i > largestPrimeFactor)? i : largestPrimeFactor;
        }
    }
    // When n is a prime number larger than 2
    if(n > 2) {
        largestPrimeFactor = (n > largestPrimeFactor)? n : largestPrimeFactor;
    }
    return largestPrimeFactor;
}

int main() {
	unsigned long long int expectedAnswer = 6857;
	unsigned long long int answer = largestPrimeFactor(600851475143);
	if (answer == expectedAnswer) {
		cout << "PASSED" << endl;
	} else {
		cout << "FAILED (expected " << expectedAnswer << ", got " << answer << ")" << endl;
	}
    return 0;
}