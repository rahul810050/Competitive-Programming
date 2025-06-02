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
#define out(ans) cout << ans << endl
#define yn(a) cout << ((a) ? "YES" : "NO") << endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef queue<int> que;
typedef double dl;

bool check(int k) {
    int j = sqrtl((ll)k * (k + 1) / 2);
    return ((ll)j * j != (ll)k * (k + 1) / 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (!check(n)) {
            out(-1);
            continue;
        }

        vi ans(n + 2);
        for1(i, n) ans[i] = i;

        int j = 0;
        for1(i, n) {
            while ((ll)j * j < (ll)i * (i + 1) / 2) j++;
            if ((ll)j * j == (ll)i * (i + 1) / 2) {
                swap(ans[i], ans[i + 1]);
            }
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
