// coded by Cocane

#include<bits/stdc++.h>

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define foru(i, n) for(int i = n-1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define allp(x) (x).begin(), (x).begin() + (x).size()/2, (x).rbegin()
#define pb push_back
#define ppb pop_back
#define read(a) for(auto &i: a) cin >> i
#define out(res) cout << res << endl
#define yn(a) cout << (a ? "YES" : "NO") << endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

const int N = 6e6;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vi p, ip(N, 1);

    for (int i = 2; i < N; ++i) {
        if (!ip[i]) continue;
        p.pb(i);
        for (int j = i; j < N; j += i) {
            ip[j] = 0;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi a(n);
        read(a);
        sort(all(a), greater<int>());

        int res = 0;
        ll xx = 0, yy = 0;

        for (int i = 0; i < n; ++i) {
            xx += a[i];
            yy += p[i];
            if (xx >= yy) res = i + 1;
        }

        out(n - res);
    }

    return 0;
}
