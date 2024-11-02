#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define foru(i, n) for(int i = n-1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ppb pop_back
#define read(a) for(auto &i : a) cin >> i
#define out(ans) cout << ans << endl
#define yn(a) cout << (a ? "YES" : "NO") << endl

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

int query(int i, int j);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int flag = 0;
        vector<int> s;
        vector<int> ans(n + 1, 0);

        for (int i = 2; i <= n; ++i) {
            if (!flag) {
                int x = query(i, 1);
                if (x == -1) {
                    return 0;
                }

                s.pb(i);

                if (x == 0) {
                    flag = 1;
                    ans[i] = 1;
                }
            } else {
                while (!s.empty()) {
                    int x = s[0];
                    s.erase(s.begin());

                    int y = query(i, x);
                    if (y == 0) {
                        ans[i] = x;
                        s.pb(i);
                        break;
                    }
                }
            }
        }

        cout << "! ";
        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
