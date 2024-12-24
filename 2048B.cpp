// coded by Cocane

#include <bits/stdc++.h>
#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define foru(i, n) for (int i = n - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
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
        ll n, k;
        cin >> n >> k;

        if (k == 1) {
            for (ll i = 1; i <= n; i++) {
                cout << i << " ";
            }
            cout << endl;
        } else {
            vll v(n, 0); 

            for (ll i = k - 1, j = 1; i < n; i += k, j++) {
                v[i] = j;
            }

            set<ll> used;
            for (ll i = 0; i < n; i++) {
                if (v[i] != 0) {
                    used.insert(v[i]);
                }
            }

            ll curr = 1;
            for (ll i = 0; i < n; i++) {
                if (v[i] == 0) { 
                    while (used.find(curr) != used.end() || curr > n) {
                        curr++;
                    }
                    v[i] = curr; 
                    used.insert(curr); 
                }
            }

            for (auto &it : v) cout << it << " ";
            cout << endl;
        }
    }
    return 0;
}
