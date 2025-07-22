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

const int M = 998244353;

ll MX(ll a, ll e = M-2) {
    ll r = 1;
    a %= M;
    while (e) {
        if (e & 1) r = r * a % M;
        a = a * a % M;
        e >>= 1;
    }
    return r;
}


vll add(ll x) {
    vll vec;
    vec.reserve(100000);
    for (int i = 0; i < 100000; i++) vec.pb(x);
    return vec;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;
  while(t--){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,ll>>> v(m+1);
    ll C = 1;
    forn(i, n){
      int l, r;
      ll p, q;
      cin >> l >> r >> p >> q;
      ll xx = MX((q - p + M) % M);
      ll w = p % M * xx % M;
      v[r].pb({l, w});
      ll nnnq = MX(q);
      C = C * ((q - p + M) % M) % M * nnnq % M;
    }
    vll dp(m+1, 0);
    dp[0] = 1;
    for1(x, m){
      ll jog = 0;
      for(auto &seg : v[x]){
        jog = (jog + dp[seg.fi-1] * seg.se) % M;
      }
      dp[x] = jog;
    }

    vll vec = add(C);
    ll sum = 0;
    for(auto it: vec){
      sum += it;
    }

    ll div = 0;

    while (sum > 0)
    {
      div += (sum/2);
      sum /= 2;
    }
    


    out(C * dp[m] % M);
  }
  return 0;
}
