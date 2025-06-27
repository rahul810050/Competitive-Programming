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
#define out(ans) cout<<ans<<endl
#define yn(a) cout<< (a ? "YES": "NO") <<endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string A;
    cin >> A;

    vi logs;
    forn(i, n) {
        if (A[i] == 'L') logs.pb(i);
    }
    logs.pb(n + 1);

    int i = -1, next_log = 0;
    while (i < n - 1) {
        if (m >= logs[next_log] - i) {
            i = logs[next_log];
        } else {
            i += m;
            if (i > n - 1) {
                out("YES");
                return;
            }
            while (i < n && i < logs[next_log]) {
                if (A[i] != 'C' && k > 0) {
                    i++;
                    k--;
                } else {
                    out("NO");
                    return;
                }
            }
        }
        next_log++;
    }
    out("YES");
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
