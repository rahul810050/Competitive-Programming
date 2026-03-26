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
    int n, k; cin>>n>>k;
    vector<pair<ll,int>> v;
    for(int i = 1; i <= n; i++){
      ll x; cin>>x;
      ll y = x % k;
      if(y == 0) y = k;
      v.pb({y, i});
    }
    
    // for(auto &it: v){
    //   cout<<it.first<<it.second<<" ";
    // } cout<<endl;
    // sort(all(v));
    // cout<<"sorted"<<endl;
    // for(auto &it: v){
    //   cout<<it.first<<it.second<<" ";
    // } cout<<endl;
    // for(auto &it: v){
    //   cout<<it.second<<" ";
    // } cout<<endl;
    // vi order;
    // for(auto &it: v){
    //   if(it.first == 0) order.pb(it.second);
    // }
    // sort(all(v), greater<pair<ll,int>>());
    // for(int i = n-1; i >= 0; i--){
    //   if(v[i].first != 0) order.pb(v[i].second);
    // }
    sort(v.begin(), v.end(), [](auto &a, auto &b){
      if(a.first == b.first)
        return a.second < b.second; 
      return a.first > b.first;     
    });
    for(auto &it: v) cout<<it.second<<" ";
    cout<<endl;
  }
  return 0;
}