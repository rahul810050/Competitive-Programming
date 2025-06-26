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
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> g(n);
        read(g);
        vi p(n);
        iota(all(p), 0);

        sort(all(p), [&](int x, int y) {
            if (g[x][y] == '1') return x < y;
            else return x > y;
        });

        for (auto i : p) cout << i + 1 << " ";
        cout << endl;
    }

    return 0;
}
