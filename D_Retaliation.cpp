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
    vector<long long> v(n);
    for(auto &it : v) cin >> it;

    long long diff = v[1] - v[0];
    bool bad = 0;
    for(int i = 2; i < n; i++) if(diff != v[i] - v[i - 1]) bad = 1;
    
    if(bad) {
        cout << "NO" << endl;
        continue;
    }
    
    for(int i = 0; i < n; i++)
        v[i] = v[i] + (diff < 0 ? diff * (n - i) : -diff * (i + 1));
        
    cout << (v[0] >= 0 && v[0] % (n + 1) == 0 ? "YES" : "NO") << endl;
  }
  return 0;
}