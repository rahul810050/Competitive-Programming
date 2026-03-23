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
    vector<vector<ll>> v(n);
    for (ll i = 0; i < n; i++)
    {
      int m; cin>>m;
      vll a(m);
      read(a);
      v[i]= a;
    }
    for(auto &i : v){
      sort(i.begin(), i.end());
    }
    vll all_min(n), second_min(n);
    
    for(ll i = 0; i < n; i++){
      all_min[i] = v[i][0];
      second_min[i] = v[i][1];
    }
    sort(all_min.begin(), all_min.end());
    sort(second_min.begin(), second_min.end());
    ll sum = accumulate(second_min.begin(), second_min.end(), (ll)0);
    sum -= second_min[0];
    sum += all_min[0];
    cout<<sum<<endl;
  }
  return 0;
}