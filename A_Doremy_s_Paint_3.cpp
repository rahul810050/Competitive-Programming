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
    int n; cin>>n;
    vi v(n);
    read(v);
    unordered_map<int,int> mp;
    for(int i = 0; i <n; i++){
      mp[v[i]]++;
    }
    if(n == 2){
      cout<<"Yes"<<endl;
      continue;
    } else if(n == 3){
      if(mp.size() <= 2){
        cout<<"Yes"<<endl;
      } else {
        cout<<"No"<<endl;
      }
    } else if(n >= 4){
      if(mp.size() == 1){
        cout<<"Yes"<<endl;
      } else if(mp.size() == 2){
        vi freq;
        for(auto &it: mp){
          freq.pb(it.second);
        }
        if(freq[0] == freq[1] || freq[0] == (freq[1]-1) || (freq[0]-1) == freq[1]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
      } 
      else cout<<"No"<<endl;
    }
  }
  return 0;
}