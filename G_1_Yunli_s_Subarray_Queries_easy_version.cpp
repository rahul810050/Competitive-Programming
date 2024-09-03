#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int>& subarray) {
    sort(subarray.begin(), subarray.end());
    int k = subarray.size();
    int min_ops = INT_MAX;

    for (int start = 0; start < k; start++) {
        int operations = 0;
        for (int i = 0; i < k; i++) {
            operations += abs(subarray[start] + i - subarray[i]);
        }
        min_ops = min(min_ops, operations);
    }

    return min_ops;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, k, q;
        cin >> n >> k >> q;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        while (q--) {
            int l, r;
            cin >> l >> r;
            l--;  // convert to 0-based indexing
            vector<int> subarray(a.begin() + l, a.begin() + l + k);
            cout << minOperations(subarray) << '\n';
        }
    }

    return 0;
}
