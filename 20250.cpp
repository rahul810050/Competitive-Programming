#include <bits/stdc++.h>
using namespace std;

int min_seconds(string s, string t) {
    int n = s.size(), m = t.size();
    
    // Find the longest common suffix between s and t
    int common_suffix_length = 0;
    for (int i = 0; i < min(n, m); i++) {
        if (s[n - 1 - i] == t[m - 1 - i]) // Compare from the end
            common_suffix_length++;
        else
            break;
    }

    // Time to type the non-overlapping parts + 1 second for copying the common suffix
    return (n - common_suffix_length) + (m - common_suffix_length) + common_suffix_length + 1;
}

int main() {
    int q; // Number of test cases
    cin >> q;

    while (q--) {
        string s, t;
        cin >> s >> t;

        // Calculate and output the minimum time for each test case
        cout << min_seconds(s, t) << endl;
    }

    return 0;
}
