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
#define out(ans) cout << ans << "\n"
#define yn(a) cout << ((a) ? "YES" : "NO") << "\n"

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef queue<int> que;
typedef double dl;

const int MAXN = 10000001;
vb v(MAXN, true);


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    v[0] = v[1] = false;
    for (int i = 2; i * i < MAXN; i++) {
        if (!v[i]) continue;
        for (int j = i * i; j < MAXN; j += i) {
            v[j] = false;
        }
    }

    int t;
    cin >> t;
    while (t--) {
			int n, ans = 0;
    cin >> n;
    for1(i, n) {
        if (i >= 2 && v[i]) {
            ans += n / i;
        }
    }
    out(ans);
		}

    return 0;
}
