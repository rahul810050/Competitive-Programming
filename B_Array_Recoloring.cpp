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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vi a(n);
        read(a);
        ll ans = 0;
        if (k > 1) {
            sort(allr(a));
            ans = accumulate(a.begin(), a.begin() + k + 1, 0LL);
        } else {
            int l = *max_element(a.begin(), a.end() - 1);
            int r = *max_element(a.begin() + 1, a.end());
            ans = max(l + a.back(), r + a[0]);
        }
        out(ans);
    }

    return 0;
}
