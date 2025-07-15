// coded by Cocane

#include <bits/stdc++.h>

#define ll long long
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
#define out(ans) cout << ans << '\n'
#define yn(a) cout << (a ? "YES" : "NO") << '\n'

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
        int n, k;
        cin >> n >> k;
        vi a(n);
        read(a);
        sort(all(a));

        vi cnt = {1};
        for1(i, n - 1) {
            if (a[i] == a[i - 1]) cnt.back()++;
            else cnt.pb(1);
        }

        sort(all(cnt));
        int m = cnt.size(), printed = 0;

        forn(i, m - 1) {
            if (cnt[i] > k) {
                out(m - i);
                printed = 1;
                break;
            }
            k -= cnt[i];
        }

        if (!printed) out(1);
    }
    return 0;
}
