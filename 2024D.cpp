#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;  // Number of test cases
    cin >> t;
    while (t--) {
        int n;  // Number of problems
        cin >> n;
        vector<ll> a(n), b(n);
        
        // Read the scores
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        // Read the parameters
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        // Vector to store the maximum points obtainable
        vector<ll> dp(n + 1, 0);
        
        // Fill the dp array from the end to the start
        for (int i = n - 1; i >= 0; --i) {
            // The current score if Prokhor submits the problem
            ll submitScore = a[i];
            // If he skips, he can get the score from the next valid problem
            if (i + 1 <= n) {
                dp[i] = max(dp[i + 1], submitScore); // either take the next problem or submit current
            }
            // Check the next problem he can access if he skips this one
            if (b[i] > 0 && b[i] <= n) {
                dp[i] = max(dp[i], submitScore + dp[b[i] - 1]); // if he skips, take the score from dp[b[i] - 1]
            }
        }

        // The answer for this test case is the maximum score obtainable starting from problem 0
        cout << dp[0] << "\n"; // Output the maximum points for this test case
    }

    return 0;
}
