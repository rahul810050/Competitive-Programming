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

bool findBeats(int n, int x, int y) {
    if (x == 0) return y == n - 1;
    if (x == n - 1) return y != 0;
    return x > y;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
			int n;
    cin >> n;
    string own;
    cin >> own;

    bool gd = false;

    forn(i, n) {
        if (own[i] != 'A') continue;
        bool gdMove = true;
        forn(j, n) {
            if (own[j] == 'B' && findBeats(n, j, i)) {
                gdMove = false;
            }
        }
        if (gdMove) {
            gd = true;
        }
    }

    if (gd) out("Alice");
    else out("Bob");
		}

    return 0;
}
