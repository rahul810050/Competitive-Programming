// coded by Cocane

#include <bits/stdc++.h>

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define foru(i, n) for (int i = n - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define allp(x) (x).begin(), (x).begin() + (x).size() / 2, (x).rbegin()
#define pb push_back
#define ppb pop_back
#define read(a) for (auto &i : a) cin >> i
#define out(ans) cout << ans << endl
#define yn(a) cout << (a ? "YES" : "NO") << endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

ll factorial(int x) {
    if (x == 0) return 1;
    return x * factorial(x - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string k;
        cin >> n >> k;

        n = min(n, 7); 
        int len = factorial(n);

        string s = "";
        forn(i, len) {
            s += k;
        }

        s.erase(0, s.find_first_not_of('0'));
        if (s == "") s = "0";

        for (int i = 1; i <= 9; i += 2) {
            int rem = 0;
            for (char c : s) {
                rem = (rem * 10 + (c - '0')) % i;
            }
            if (rem == 0) cout << i << " ";
        }
        cout << '\n';
    }

    return 0;
}
