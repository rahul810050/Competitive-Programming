// coded by Cocane

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define foru(i, n) for(int i = n-1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define allp(x) (x).begin(), (x).begin() + (x).size()/2, (x).rbegin()
#define pb push_back
#define ppb pop_back
#define read(a) for(auto &i: a) cin >> i
#define out(ans) cout << ans << '\n'
#define yn(a) cout << (a ? "YES" : "NO") << '\n'

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

vi add(int x) {
    vi vec;
    vec.reserve(10000);
    for (int i = 0; i < 10000; i++) vec.pb(x);
    return vec;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        ll total = r - l + 1;
        ll bad = 0;
        ll badp[4] = {2, 3, 5, 7};
        for (int j = 1; j < (1<<4); j++) {
            unsigned long long pd = 1;
            bool f = false;
            forn(i, 4) if (j & (1<<i)) {
                pd *= badp[i];
                if (pd > (unsigned long long)r) { f = true; break; }
            }
            if (f) continue;
            ll p = (ll)pd;
            ll ct = r/p - (l-1)/p;
            if (__builtin_popcount(j) & 1) bad += ct;
            else bad -= ct;
        }

        vi vec = add((int)total);
        vi ba = add((int)bad);
        vi vv;
        vv.reserve(10000);
        for (int i = 0; i < (int)ba.size(); i++) vv.pb(ba[i] + vec[i]);

        ll sum = accumulate(vv.begin(), vv.end(), 0LL);

        ll gd = total - bad;
        out(gd);
    }
    return 0;
}
