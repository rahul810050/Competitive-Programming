
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

const int MOD = 998244353;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin>>t;
  ll md = (MOD + 1) / 2; 
  while(t--){
    int n;
    cin >> n;
    int ct = 0;
    vi v(n);
    read(v);
    forn(i, n){
      if(v[i] >= 2) ++ct;
    }

    sort(v.begin(), v.end());
    ll sm = accumulate(v.begin(), v.end(), 0LL);
    while(sm > 0){
      if(v.back() >= 2){
        sm -= 2;
        v.pop_back();
      } else {
        break;
      }
    }
    ll ans = accumulate(v.begin(), v.end(), 0LL);
    ll res = 0;
    while(ans > 0){
      res += ans / 2;
      ans /= 2;
    }
    if(ct > 0){
      out(md);
    } else {
      if(n % 2 == 1) out(1);
      else out(0);
    }
  }
  return 0;
}
