#include <iostream> 
using namespace std; 

int main() { 
    // Change x to double to preserve decimal values
    double x = 2.1000; 
    int n = 3; 
    long binform = n; 
    double ans = 1; 

    while (binform > 0) { 
        if (binform % 2 == 1) { 
            ans = ans * x; 
        } 
        x = x * x; 
        binform = binform / 2; 
    } 

    cout << ans; // Outputs 9.261
}
