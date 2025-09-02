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

int wt[105], val[105];
ll dp[105][100005];

ll func(int idx, int wt_left){
  if(wt_left == 0) return 0;
  if(idx < 0) return 0;
  if(dp[idx][wt_left] != -1) return dp[idx][wt_left];

  ll ans = func(idx - 1, wt_left); 
  if(wt_left - wt[idx] >= 0)
      ans = max(ans, func(idx - 1, wt_left - wt[idx]) + val[idx]); 

  return dp[idx][wt_left] = ans;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n,w;
  cin>>n>>w;
  for(int i = 0; i < n; i++){
    int x,y; cin>>x>>y;
    wt[i] = x;
    val[i] = y;
  }
  memset(dp, -1, sizeof(dp));
  cout<<func(n-1, w)<<endl;
  return 0;
}