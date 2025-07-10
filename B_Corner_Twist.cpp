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
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef double dl;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while(t--){
    int n, m;
    cin >> n >> m;
    vector<string> grid1(n), grid2(n);
    read(grid1);
    read(grid2);

    vi sr1(m), sr2(m), sc1(n), sc2(n);

    forn(i, n){
      forn(j, m){
        sr1[j] = (sr1[j] + (grid1[i][j] - '0')) % 3;
        sr2[j] = (sr2[j] + (grid2[i][j] - '0')) % 3;
        sc1[i] = (sc1[i] + (grid1[i][j] - '0')) % 3;
        sc2[i] = (sc2[i] + (grid2[i][j] - '0')) % 3;
      }
    }

    bool ok = true;
    forn(i, n) ok &= (sc1[i] == sc2[i]);
    forn(i, m) ok &= (sr1[i] == sr2[i]);

    yn(ok);
  }

  return 0;
}
