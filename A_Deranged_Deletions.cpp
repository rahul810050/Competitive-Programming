// coded by Cocane

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define foru(i, n) for(int i = n-1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define allp(x) (x).begin(), (x).begin() + (x).size()/2, (x).rbegin()
#define pb push_back
#define ppb pop_back
#define read(a) for(auto &i: a) cin >> i
#define out(ans) cout << ans << '\n'
#define yn(a) cout << (a ? "YES" : "NO") << '\n'

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
        vi a(n);
        read(a);

        bool flag = false;
        forn(i, n) {
            if (flag) break;
            for (int j = i + 1; j < n; j++) {
                if (a[i] > a[j]) {
                    out("YES");
                    out(2);
                    cout << a[i] << " " << a[j] << '\n';
                    flag = true;
                    break;
                }
            }
        }
        if (!flag) {
            yn(false);
        }
    }

    return 0;
}
