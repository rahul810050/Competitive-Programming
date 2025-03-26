// coded by Cocane

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)
#define read(a) for (auto &i : a) cin >> i

typedef vector<int> vi;

// Function to check if the array can be reduced to a sorted sequence
string canReduceToSorted(int n, vi &v) {
    // Iterating through the array and checking the condition
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            return "NO"; // If condition breaks, return NO
        } else {
            v[i + 1] -= v[i]; // Reduce the next element
        }
    }
    return "YES"; // If all conditions pass, return YES
}

// Driver function to handle multiple test cases
void solveTestCases() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n;
        cin >> n; // Size of the array
        vi v(n);  // Array to store values
        read(v);  // Read the array

        // Output the result for the current test case
        cout << canReduceToSorted(n, v) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solveTestCases();
    return 0;
}
