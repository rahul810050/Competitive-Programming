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

        vi v(n);
        forn(i, n) cin >> v[i];

        bool valid = true;

        unordered_set<int> has;  

        has.insert(v[0]);  

        for (int i = 1; i < n; i++) { 

            int current = v[i];

            if (has.find(current - 1) == has.end() && has.find(current + 1) == has.end()) {
                valid = false;
                break;
            }
            has.insert(v[i]);
        }

        yn(valid);
    }

    return 0;
}
