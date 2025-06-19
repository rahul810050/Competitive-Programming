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

void solve() {
    ll a = 0, b, c, d;
    ll mask = 1;
    bool valid = true;

    cin >> b >> c >> d;

    forn(i, 62) {
        bool bit_b = b & mask;
        bool bit_c = c & mask;
        bool bit_d = d & mask;

        if ((bit_b && !bit_c && !bit_d) || (!bit_b && bit_c && bit_d)) {
            valid = false;
            break;
        }

        if (bit_b && bit_c) {
            a += (1LL - bit_d) * mask;
        } else {
            a += bit_d * mask;
        }

        mask <<= 1;
    }

    cout<<(valid ? a : -1)<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
