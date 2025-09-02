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

ll func(int idx, int val_left){
    if(val_left == 0) return 0;
    if(idx < 0) return 1e15;
    if(dp[idx][val_left] != -1) return dp[idx][val_left];
    
    ll ans = func(idx - 1, val_left);
    if(val_left - val[idx] >= 0)
        ans = min(ans, func(idx - 1, val_left - val[idx]) + wt[idx]);
    return dp[idx][val_left] = ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, w;
    cin >> n >> w;

    for(int i=0; i<n; i++) cin >> wt[i] >> val[i];
    memset(dp, -1, sizeof(dp));

    int mx = 0;
    for(int i=0; i<n; i++) mx += val[i];

    for(int i = mx; i >= 0; i--){
        if(func(n-1, i) <= w){
            cout << i << "\n";
            break;
        }
    }
  return 0;
}