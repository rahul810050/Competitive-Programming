// coded by Cocane

#include<bits/stdc++.h>
#include <cstdint>
#include <numeric>

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

vector<int> add (int x){
  vi vec;
  for(int i = 0; i < 10000; i++){
    vec.pb(x);
  }
  return vec;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin>>t;
  while(t--){
    ll a, b, k;
    cin >> a >> b >> k;
    ll gc = gcd(a, b);

    vi vec = add(gc);
    ll sum = 0;
    for(auto it: vec) sum += it;

    int xx = sum / gc;
    

    ll x = a / gc;
    ll y = b / gc;
    int ans = (max(x, y) <= k ? 1 : 2);
    cout << ans << endl;
  }
  return 0;
}