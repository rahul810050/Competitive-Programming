// coded by Cocane

#include<bits/stdc++.h>

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define foru(i, n) for(int i = n-1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define read(a) for(auto &i: a) cin >> i
#define out(ans) cout<<ans<<endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin>>t;
  while(t--){
    int n;
    string s;
    cin>>n>>s;

    vi pref(n), suff(n);
    vector<int> vis(26,0);

    // prefix distinct
    int cnt = 0;
    for(int i = 0; i < n; i++){
      if(vis[s[i]-'a'] == 0){
        cnt++;
        vis[s[i]-'a'] = 1;
      }
      pref[i] = cnt;
    }

    // reset
    fill(all(vis), 0);
    cnt = 0;

    // suffix distinct
    for(int i = n-1; i >= 0; i--){
      if(vis[s[i]-'a'] == 0){
        cnt++;
        vis[s[i]-'a'] = 1;
      }
      suff[i] = cnt;
    }

    int ans = 0;

    // try all splits
    for(int i = 0; i < n-1; i++){
      ans = max(ans, pref[i] + suff[i+1]);
    }

    out(ans);
  }
  return 0;
}