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
    int n;
    cin >> n;
    vi a(n);
    for (auto &i: a) cin >> i;
    vi p[2];
    for (int i : a) p[i%2].pb(i);
    ll ans = 0;
    if (p[1].size()) ans += accumulate(all(p[0]), 0LL);
    sort(p[1].rbegin(), p[1].rend());
    int m = p[1].size();
    for (int i = 0; i < (m+1)/2; i++) ans += p[1][i];
    cout << ans << endl;
  }
  return 0;
}