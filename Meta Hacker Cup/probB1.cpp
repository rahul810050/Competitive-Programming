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

vector<ll> prime_factors(ll x){
  vector<ll> res;
  for(ll p = 2; p * p <= x; ++p){
    while(x % p == 0){
      res.pb(p);
      x /= p;
    }
  }
  if(x > 1) res.pb(x);
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  if(!(cin >> T)) return 0;
  for1(tc, T){
    int N;
    ll A, B;
    cin >> N >> A >> B;

    // factorize B
    vector<ll> pf = prime_factors(B);
    sort(pf.rbegin(), pf.rend());

    ll P = 1;
    vector<ll> in_prefix;   
    vector<ll> in_suffix;   
    for(ll p : pf){
      if (P * p <= A){
        P *= p;
        in_prefix.pb(p);
      } else {
        in_suffix.pb(p);
      }
    }

    sort(in_suffix.begin(), in_suffix.end());

    vector<ll> ans(2 * N, 1);

    if(!in_prefix.empty()){
      int idx = N - 1;
      for(ll p : in_prefix){
        ans[idx] *= p;
        idx--;
        if(idx < 0) idx = N - 1; 
      }
    }

    if(!in_suffix.empty()){
      int idx = N;
      for(ll p : in_suffix){
        ans[idx] *= p;
        idx++;
        if(idx >= 2 * N) idx = N; 
      }
    }

    cout << "Case #" << tc << ":";
    for(int i = 0; i < 2 * N; ++i){
      cout << " " << ans[i];
    }
    cout << "\n";
  }

  return 0;
}
