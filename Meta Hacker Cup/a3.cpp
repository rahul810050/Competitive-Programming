#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

// Function to calculate modular multiplicative inverse using Fermat's little theorem
long long mod_inverse(long long a, long long mod) {
    long long result = 1, power = mod - 2; // a^(p-1) ≡ 1 (mod p)
    while (power) {
        if (power & 1) result = (result * a) % mod;
        a = (a * a) % mod;
        power >>= 1;
    }
    return result;
}

// Function to calculate expected days
long long expected_days(long long W, long long G, long long L) {
    if (W <= G) return 0; // Already at or below target weight

    long long total_days = 0; // To accumulate expected days
    long long numerator = 0;   // To store numerator for expected days
    long long denominator = 1;  // Starting denominator for probability

    // We will calculate the expected days using a dynamic programming approach
    vector<long long> E(W + 1); // E[w] will hold the expected days for weight w

    // Fill the expected days from G to W
    for (long long w = W; w > G; w--) {
        if (w > G) {
            E[w] = (1 + E[w - 1]) % MOD; // Can lose weight
            if (w < W + L) {
                E[w] = (E[w] + E[w + 1]) % MOD; // Can also gain weight
                E[w] = (E[w] * mod_inverse(2, MOD)) % MOD; // Average due to 1/2 chance
            } else {
                // At the limit of W + L, can only lose weight
                E[w] = (E[w] * mod_inverse(1, MOD)) % MOD; // Remain as is
            }
        }
    }

    // Return the expected days for starting weight W
    return E[W];
}

int main() {
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        long long W, G, L;
        cin >> W >> G >> L;

        long long ans = expected_days(W, G, L);
        // To print the output
        cout << "Case #" << i << ": " << ans << endl;
    }

    return 0;
}
