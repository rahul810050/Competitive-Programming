#include <bits/stdc++.h>

#define ll long long int
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
    while(t--) {
        ll n, a, b;
        cin >> n >> a >> b;

        if(b <= a) {
            cout << n * a << endl;
        } else {
            
            ll x = min(n, b - a);
            
            // ll sum1 = (x * (2 * b - x + 1)) / 2;

            ll last = b + (x - 1) * (-1);

            ll sum1 = (x * (b + last)) / 2;

            ll sum2 = (n - x) * a;

            cout << sum1 + sum2 << endl;
        }
    }
    return 0;
}
