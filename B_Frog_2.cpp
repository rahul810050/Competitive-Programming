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

const int N = 1e5 + 10;
int dp[N];

int frog(int i, vi &h, int k){
  int cost = INT_MAX;
  if(i == 0) return 0;
  if(dp[i] != -1) return dp[i];

  for(int j = 1; j <= k; j++){
    if(i - j >= 0)
      cost = min(cost, frog(i-j, h, k) + abs(h[i] - h[i-j]));
  }

  return dp[i] = cost;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n,k;
  cin>>n>>k;
  vi h(n);
  read(h);
  memset(dp, -1, sizeof(dp));

  out(frog(n-1, h, k));

  return 0;
}