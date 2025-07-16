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
    int n; cin>>n;
    vll v(n);
    read(v);
    vll prefix(n+1, 0);
    sort(all(v), greater<ll>());
    for(int i = 1; i <= n; i++) prefix[i] = prefix[i-1] + v[i-1];

    int ctT = 2 * n;
    for(int i = 1; i <= ctT; i++){
      ll x = 0;
      int a = (i+1)/2;
      int b = min(i, n);
      for(int j = a; j <= b; j++){
        ll y = i - j;
        ll xtrs = y * ((2LL * j - y - 1)) / 2;
        ll c = prefix[j]+xtrs;
        x = max(x,c);
      }
      if(i == ctT) cout<<x<<endl;
      else cout<<x<<" ";
    }
  }
  return 0;
}