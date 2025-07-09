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


const int MOD = 1e9 + 7;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin>>t;
  while(t--){
    int n; cin >> n;
      vi a(n);
      for (int i=0; i<n; i++) cin >> a[i];
      sort(a.begin(), a.end());
      vi b(n);
      for (int i=0; i<n; i++) cin >> b[i];
      sort(b.begin(), b.end(), greater<>());
      ll result = 1;
      for (int i=0; i<n; i++){
          int geq_count = a.size() - (upper_bound(a.begin(), a.end(), b[i]) - a.begin());
          result = result * max(geq_count - i, 0) % MOD;
      }
      cout << result << endl;
  }
  return 0;
}