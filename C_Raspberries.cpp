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
    int n,k;
    cin>>n>>k;
    vi v(n);
    read(v);

    bool f = false;

    // check if already divisible
    for(auto &it:v){
      if(it % k == 0){
        f = true;
        break;
      }
    }

    if(f) {
      cout<<0<<endl;
      continue;
    } 

    else if(k == 4){
      int ct_even = 0;
      for(auto &it:v) if(it % 2 == 0) ct_even++;

      // option 1: make one element divisible by 4
      vi vec;
      for(auto &it : v){
        vec.pb((4 - it % 4) % 4);
      }
      ll mn_ops = *min_element(all(vec));

      // option 2: make two even numbers
      vi even_cost;
      for(auto &it:v){
        even_cost.pb(it % 2 == 0 ? 0 : 1);
      }
      sort(all(even_cost));
      ll best2 = even_cost[0] + even_cost[1];

      cout << min(mn_ops, best2) << endl;
    }

    else {
      vi ops;
      for(auto &it : v){
        ops.pb((k - it % k) % k);
      }
      ll mn_ops = *min_element(all(ops));
      cout<<mn_ops<<endl;
    }
  }
  return 0;
}