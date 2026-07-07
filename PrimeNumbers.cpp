#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    // Handle edge cases: numbers less than 2 are not prime
    if (n < 2) {
        cout << n << " is not prime" << endl;
        return 0;
    }

    bool isPrime = true;

    // Loop from 2 up to the square root of n
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            isPrime = false; // Found a factor, so it's not prime
            break;           // Exit the loop immediately
        }
    }

    // Final decision printed exactly once after the loop completes
    if (isPrime) {
        cout << n << " is a prime number" << endl;
    } else {
        cout << n << " is not prime" << endl;
    }

    return 0;
}
