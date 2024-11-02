#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;  // Number of test cases

    while (t--) {
        ll n, m, r, c;
        cin >> n >> m >> r >> c;

        // Calculate Manhattan distances to each corner
        ll distance1 = abs(r - 1) + abs(c - 1); // Top-left corner
        ll distance2 = abs(r - 1) + abs(c - m); // Top-right corner
        ll distance3 = abs(r - n) + abs(c - 1); // Bottom-left corner
        ll distance4 = abs(r - n) + abs(c - m); // Bottom-right corner

        // The result is the maximum distance to any of the corners
        ll totalDistance = max({distance1, distance2, distance3, distance4});

        cout << totalDistance << '\n';
    }

    return 0;
}
