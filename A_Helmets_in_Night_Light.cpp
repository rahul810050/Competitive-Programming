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
    ll n, p;
    cin>>n>>p;
    vi a(n),b(n);
    read(a);
    read(b);
    vector<pair<ll,ll>> sorted, vec;
    for(ll i = 0; i < n; i++){
      sorted.pb({b[i], a[i]});
      // vec.pb({(a[i] * 1LL * b[i]), a[i]});
    }
    sort(sorted.begin(), sorted.end(), [](pair<ll,ll> &p1, pair<ll,ll> &p2){
      if(p1.first == p2.first)
          return p1.second > p2.second;
      return p1.first < p2.first;
    });
    // for(auto &it: sorted){
    //   cout<<"b a"<<endl;
    //   cout<<it.first<<" "<<it.second<<" "<<endl;
    // }
    // cout<<endl;
    // sort(vec.begin(), vec.end());
    ll ct = 1;
    ll total_cost = p;
    for(ll i = 0; i < n; i++){
      if(ct >= n){
        break;
      }
      ll use = min((ll)sorted[i].second , (ll)(n-ct));
      ll x = sorted[i].first * 1LL * use;
      // cout<<"x "<<x<<endl;
      ll y = use * 1LL * p;
      // cout<<"y "<<y<<endl;
      if(x < y){
        ct += sorted[i].second;
        // cout<<"count "<<ct<<endl;
        total_cost += x;
        // cout<<"total_cost "<<total_cost<<endl;
      } else {
        total_cost += (n - ct) * p;
        ct = n;
      }
    }
    // for(int i = 0; i < n; i++){
    //   if(ct == n){
    //     break;
    //   }
    //   int x = vec[i].first;
    //   int y = vec[i].second * p;
    //   if(x < y){
    //     ct += vec[i].second;
    //     total_cost += x;
    //   } else {
    //     total_cost += (n - ct) * p;
    //     ct = n;
    //   }
    // }
    // cout<<"ans"<<endl;
    out(total_cost);
  }
  return 0;
}