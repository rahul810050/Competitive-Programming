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


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin>>t;
  while(t--){
    ll n; cin>>n;
    vll a(n), b(n);
    read(a);
    read(b);
    vll c1(2*n+1, 0), c2(2*n+1, 0);

    // ll i = 1, j = 0;
    // c1.pb(a[0]);
    // while(i < n && j < n){
    //   if(c1[i+j] == a[i]){
    //     c1.pb(a[i++]);
    //   } else if(c1[i+j] == b[j]){
    //     c1.pb(b[j++]);
    //   } else {
    //     c1.pb(a[i++]);
    //   }
    // }
    // ll mx = 0;
    // ll ct = 1;
    // for(ll k = 1; k < 2*n; k++){
    //   if(c1[k-1] == c1[k]) ct++;
    //   else ct = 1;
    //   mx = max(ct,mx);
    // }

    // i = 0; j = 1;
    // c2.pb(b[0]);
    // while(i < n && j < n){
    //   if(c2[i+j] == a[i]){
    //     c2.pb(a[i++]);
    //   } else if(c2[i+j] == b[j]){
    //     c2.pb(b[j++]);
    //   } else {
    //     c2.pb(b[j++]);
    //   }
    // }
    // ct = 1;
    // for(ll k = 1; k < 2*n; k++){
    //   if(c2[k-1] == c2[k]) ct++;
    //   else ct = 1;
    //   mx = max(ct,mx);
    // }
    // out(mx);
    
    for(ll i = 0; i < n; ){
      int j = i;
      while(j < n && a[j] == a[i]) j++;
      c1[a[i]] = max(c1[a[i]], j-i);
      i = j;
    }

    for(ll i = 0; i < n;){
      int j = i;
      while(j < n && b[j] == b[i]) j++;
      c2[b[i]] = max(c2[b[i]], j-i);
      i = j;
    }
    ll ans = 0;
    for(ll i = 1; i <= 2*n; i++){
      ans = max(ans, c1[i]+c2[i]);
    }
    out(ans);
  }
  return 0;
}