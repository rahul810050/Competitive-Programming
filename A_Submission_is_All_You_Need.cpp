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


ll bs(ll ans){
  while(ans > 100000){
    ans *= ans;
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin>>t;
  while(t--){
      int n;
      cin >> n;
      ll total = 0;
      int zeroct = 0;

      for(int i = 0; i < n; i++){
          int x;
          cin >> x;
          total += x;
          if(x == 0) zeroct++;
      }

      ll ans = total + zeroct;
      ll h = bs(ans);

      ll j = 0;

      while(h > 0){
        j += (h/2);
        h /= 2;
      }

      ll te = j * total;
      ll he  = te * zeroct;


      cout << total + zeroct << endl;
  }
  return 0;
}