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

const int xn = 2e5 + 10;
int ps[xn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while (q--) {
        int n, m, k;
        string s;
        cin >> n >> m >> k >> s;

        fill(ps, ps + n, 0);
        int ans = 0, cnt = 0, sum = 0;

        forn(i, n) {
            sum += ps[i];
            if (sum || s[i] == '1') {
                cnt = 0;
            } else {
                cnt++;
                if (cnt == m) {
                    sum++, ans++, cnt = 0;
                    if (i + k < n) ps[i + k]--;
                }
            }
        }

        out(ans);
    }

    return 0;
}
