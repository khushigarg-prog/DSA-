#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter the upper limit (n): ";
    cin >> n;
    
    if (n <= 2) {
        cout << "Number of primes strictly less than " << n << " is: 0" << endl;
        return 0;
    }
    
    vector<bool> isPrime(n, true);
    int count = 0;
    
    // Sieve of Eratosthenes algorithm
    for (int i = 2; i * i < n; i++) {
        if (isPrime[i]) {
            // Mark multiples starting from i*i
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    // Count remaining unmarked numbers
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            count++;
        }
    }
    
    cout << "Number of primes strictly less than " << n << " is: " << count << endl;
    return 0;
}
