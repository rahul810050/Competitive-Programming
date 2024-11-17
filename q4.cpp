// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int q;
//     cin >> q;

//     while (q--) {
//         string s, t;
//         cin >> s >> t;

//         int sLen = s.length();
//         int tLen = t.length();
//         int commonLen = min(sLen, tLen);
        
//         int diffIndex = 0;
//         while (diffIndex < commonLen && s[diffIndex] == t[diffIndex]) {
//             diffIndex++;
//         }

//         long long totalOps = diffIndex ? diffIndex + 1 : diffIndex;
//         totalOps += (sLen - diffIndex) + (tLen - diffIndex);

//         cout << totalOps << endl;
//     }

//     return 0;
// }


// p2 connect the dots
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e5+2;
const ll C = 10 + 1;
 
vector<ll> par(N), sz(N, 0);
vector<vector<ll>> dp(N, vector<ll> (C, 0)), ind(N, vector<ll> (C, 0)), start_cnt(N, vector<ll> (C, 0)), end_cnt(N, vector<ll> (C,0));
 
ll find_par(ll a) {
    if (par[a] == a) return a;
    return par[a] = find_par(par[a]);
}
 
void unite(ll a, ll b){
    a = find_par(a), b = find_par(b);
    if (a == b) return;
    if (sz[b] > sz[a]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
}
 
void reset(ll n) {
    for (ll i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
        for (ll j = 1; j < C; j++) {
            dp[i][j] = start_cnt[i][j] = end_cnt[i][j] = 0;
            ind[i][j] = i;
        }
    }
}
 
void solve() {
    ll n, m, a, d, k;
    cin >> n >> m;
    reset(n);
    for (ll i = 0; i < m; i++) {
        cin >> a >> d >> k;
        start_cnt[a][d]++;
        end_cnt[a + k * d][d]++;
    }
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j < C; j++) {
            dp[i][j] = start_cnt[i][j] - end_cnt[i][j];
            if (i-j < 1) continue;
            if (dp[i-j][j]) {
                unite(ind[i-j][j], i);
                ind[i][j] = ind[i-j][j];
                dp[i][j] += dp[i-j][j];
            }
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        if (find_par(i) == i) ans++;
    }
    cout << ans << "\n";
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}