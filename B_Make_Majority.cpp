// coded by cocane

#include <bits/stdc++.h>

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define foru(i, n) for(int i = n-1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define allp(x) (x).begin(), (x).begin() + (x).size()/2, (x).rbegin()
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
        string a;
        cin >> a;
        bool ok = false;

        if (a.find("111") != string::npos) {
            ok = true;
        }

        int count11 = 0;
        for (size_t i = 0; i < n - 1; ++i) {
            if (a[i] == '1' && a[i+1] == '1') {
                ++count11;
                if (count11 >= 2) {
                    ok = true;
                    break;
                }
            }
        }

        if (!ok && count11 >= 1 && (a[0] == '1' || a[n-1] == '1')) {
            ok = true;
        }

        if (!ok && a[0] == '1' && a[n-1] == '1') {
            ok = true;
        }

        if (ok) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
