#include <iostream>
#include <cmath>
using namespace std;

// Function to count multiples of x in the range [l, r]
long long countMultiples(long long l, long long r, long long x) {
    return r / x - (l - 1) / x;
}

int main() {
    int t;
    cin >> t;  // Read the number of test cases
    
    while (t--) {
        long long l, r, k;
        cin >> l >> r >> k;
        
        int operations = 0;

        // Check for multiples in the range
        // We try values for x from 1 to the point where the multiples exceed the range
        for (long long x = 1; x * x <= r; ++x) {
            if (countMultiples(l, r, x) >= k) {
                operations++;
            }
            if (x != r / x && countMultiples(l, r, r / x) >= k) {
                operations++;
            }
        }

        // Output the result for this test case
        cout << operations << endl;
    }

    return 0;
}
