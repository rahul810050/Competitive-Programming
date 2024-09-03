#include <bits/stdc++.h>

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define foru(i, n) for(int i = n-1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define pb push_back
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

				multiset<int> m;

        vi a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
			m.insert(a[i]);
        }

        bool isMinTurn = true;

        while (a.size() > 1) {
            if (isMinTurn) {
                auto minIt = min_element(a.begin(), a.end());
                a.erase(minIt);
            } else {
                auto maxIt = max_element(a.begin(), a.end());
                a.erase(maxIt);
            }
            isMinTurn = !isMinTurn;
        }

        cout << a[0] << endl;
    }
    return 0;
}
