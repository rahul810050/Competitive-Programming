// coded by Cocane

#include<bits/stdc++.h>

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
#define out(ans) cout << ans << endl
#define yn(a) cout << (a ? "YES" : "NO") << endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

bool can(vll& pos, vll& neg, ll t) {
    ll p = 0, n = 0, s = 0, m = 0;

    while (p < pos.size() || n < neg.size()) {
        while (s + (p < pos.size() ? pos[p] : 0) > t) {
            if (n < neg.size()) {
                s += neg[n];
                m = max(m, s);
                n++;
            } else {
                return false;
            }
            s = max(0LL, s);
        }

        if (p < pos.size()) {
            s += pos[p];
            m = max(m, s);
            p++;
        } else if (n < neg.size()) {
            s += neg[n];
            m = max(m, s);
            n++;
            s = max(0LL, s);
        }
    }

    return m <= t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        vll a(n), pos, neg;
        read(a);

        forn(i, n) {
            if (a[i] >= 0)
                pos.pb(a[i]);
            else
                neg.pb(a[i]);
        }

        if (pos.empty()) {
            out(0);
            continue;
        }

        ll l = *max_element(all(pos));
        ll r = accumulate(all(pos), 0LL);
        ll ans = r;

        while (l <= r) {
            ll mid = (l + r) / 2;

            if (can(pos, neg, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        out(ans);
    }

    return 0;
}
