// coded by Cocane

#include <bits/stdc++.h>

#define ll long long
#define lli long long int
#define forn(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define foru(i, n) for (int i = n - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ppb pop_back
#define read(a) for (auto &i : a) cin >> i
#define out(ans) cout << ans << endl
#define yn(a) cout << (a ? "YES" : "NO") << endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

const int mod = 1e9 + 7;

ll binpow(ll a, ll b) {
    if (b == 0) return 1;
    if (b % 2) return (a * binpow(a, b - 1)) % mod;
    return binpow((a * a) % mod, b / 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vll a(n);
        read(a);

        ll sum = 0, sumsq = 0;
        forn(i, n) {
            sum = (sum + a[i]) % mod;
            sumsq = (sumsq + (a[i] * a[i]) % mod) % mod;
        }

        sum = (sum * sum) % mod;
        sum = (sum - sumsq + mod) % mod;
        sum = (sum * binpow(2, mod - 2)) % mod;

        ll cnt = (n * (n - 1) / 2) % mod;
        out((sum * binpow(cnt, mod - 2)) % mod);
    }

    return 0;
}
