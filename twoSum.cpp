// coded by Cocane

#include <bits/stdc++.h>

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define foru(i, n) for (int i = n - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define allp(x) (x).begin(), (x).begin() + (x).size() / 2, (x).rbegin()
#define pb push_back
#define ppb pop_back
#define read(a) for (auto &i : a) cin >> i
#define out(ans) cout << ans << endl
#define yn(a) cout << (a ? "YES" : "NO") << endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, target;
        cin >> n >> target;

        vi v(n);
        read(v);

        vector<pair<int, int>> m;
        for (int i = 0; i < n; i++) {
            m.pb({v[i], i}); // add each element with its index
        }

        sort(all(m)); // sort based on the values in the pair

        int l = 0, r = n - 1;
        bool found = false;

        while (l < r) {
            int x = m[r].fi + m[l].fi;
            if (x == target) {
                cout << m[l].se + 1 << " " << m[r].se + 1 << endl;
								r--;
								l++;
                found = true;
                // break; // found the pair, exit the loop
            } else if (x < target) {
                l++;
            } else {
                r--;
            }
        }

        if (!found) {
            cout << "No pair found" << endl; // message if no pair sums up to target
        }
    }

    return 0;
}
