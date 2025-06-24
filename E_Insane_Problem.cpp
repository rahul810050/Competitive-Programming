// coded by Cocane

#include <bits/stdc++.h>

#define ll long long
#define lli long long int
#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define foru(i, n) for(int i = n - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define allp(x) (x).begin(), (x).begin() + (x).size() / 2, (x).rbegin()
#define pb push_back
#define ppb pop_back
#define read(a) for(auto &i : a) cin >> i
#define out(ans) cout << ans << endl
#define yn(a) cout << (a ? "YES" : "NO") << endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        ll k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;
        ll kn = 1, ans = 0;

        for(; r2 / kn >= l1; kn *= k) {
            ans += max(0LL, min(r2 / kn, r1) - max((l2 - 1) / kn + 1, l1) + 1);
        }

        out(ans);
    }

    return 0;
}
