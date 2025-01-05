#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve() {
    int n, k;
    cin >> n >> k;

    if (k >= n) {
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
        }
        return 1;
    }

    map<int, int> freq;
    int unique = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (++freq[x] == 1) unique++;
    }

    if (k == 0) return unique;

    vector<int> counts;
    for (auto &[val, f] : freq) {
        counts.push_back(f);
    }

    sort(counts.begin(), counts.end());

    for (int count : counts) {
        if (count <= k) {
            k -= count;
            unique--;
        } else {
            break;
        }
    }

    return unique;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) cout << solve() << '\n';
    return 0;
}
