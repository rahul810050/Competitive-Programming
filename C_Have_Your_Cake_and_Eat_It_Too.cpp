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
    int n;
    cin >> n;

    vector<vi> val(3, vi(n+1));
    vector<vi> pf(3, vi(n+1));

    forn(i, 3){
      for1(j, n){
        cin >> val[i][j];
        pf[i][j] = pf[i][j-1] + val[i][j];
      }
    }

    bool flag = false;
    vi perm = {0,1,2};
    int comp = (pf[perm[0]][n] + 2) / 3;

    forn(i, 6){
      int cur = 1;
      while(cur <= n && pf[perm[0]][cur] < comp) cur++;

      for(int j = cur + 1; j < n; j++){
        if(pf[perm[1]][j] - pf[perm[1]][cur] >= comp &&
           pf[perm[2]][n] - pf[perm[2]][j] >= comp){

          vii ans(3);
          ans[perm[0]] = {1, cur};
          ans[perm[1]] = {cur+1, j};
          ans[perm[2]] = {j+1, n};

          for(auto x : ans) cout << x.fi << ' ' << x.se << ' ';
          cout << endl;
          flag = true;
          break;
        }
      }
      if(flag) break;
      next_permutation(all(perm));
    }

    if(!flag) out(-1);
  }
  return 0;
}
