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
    int n,cnt=0;
    cin>>n;
    vector<int> v(n);
    map<int, int> mp;
    for(int i=0; i<n; i++){
      cin>>v[i];
      // if(v[i]==1){
      //   cnt++;
      //   continue;
      // }
      mp[v[i]]++;
    }
    int mx=0;
    for(auto i: mp){
      mx=max(mx,i.second);
    }
    for(auto i: mp){
      if(i.second==mx&&i.first==1){
        cout<<n-mx-cnt<<endl;
        cnt=1;
      }
    }
    if(cnt==1) continue;
    cout<<n-mx-cnt+1<<endl;
  }
  return 0;
}