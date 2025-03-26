// coded by Cocane

#include <bits/stdc++.h>

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)
#define read(a) for (auto &i : a) cin >> i
using namespace std;

typedef vector<int> vi;

void solve() {
    int n;
    cin >> n;
    vi v(n);
    read(v);

    if (n == 2) {
        cout << "Yes" << endl;
        return;
    }

    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[v[i]]++;
    }

    if (freq.size() > 2) {
        cout << "No" << endl;
        return;
    }

    if (freq.size() == 2) {
        auto it = freq.begin();
        int val1 = it->second;
        int val2 = (++it)->second;
        if (abs(val1 - val2) > 1) {
            cout << "No" << endl;
            return;
        }
    }
    
    cout << "Yes" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
