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

bool check(const vector<vi> &vv, int v){
  return (int)vv[v].size() >= v;
}

ll sum(const vi &a){
  ll total = 0;
  for(auto it: a) total += it;
  return total;
}

ll giveSum(ll sm){
  ll ans = 0;
  while(sm > 0){
      ans += sm%2;
      sm /= 2;
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin>>t;
  while(t--){
    int n;
    cin >> n;
    vi a(n+1);
    for1(i, n) cin >> a[i];

    vector<vi> vv(n+1);
    vi arr(n+1, 0);

    for1(i, n){
      int v = a[i];
      vv[v].pb(i);

      arr[i] = arr[i-1];

      if (check(vv, v)) {
        int it = (int)vv[v].size() - v; 
        int y = vv[v][it];           
        int x = arr[y - 1] + v;
        if (x > arr[i]) arr[i] = x;
      }
    }

    ll sm = sum(arr);
    ll ans = giveSum(sm);
    
    out(arr[n]);
  }
  return 0;
}
