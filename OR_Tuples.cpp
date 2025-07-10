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
    int p,q,r;
    cin>>p>>q>>r;
    ll ans=1;
    for(int i=0;i<21;i++)
    {
        if(p%2==1 && q%2==1 && r%2==0){ans*=1;}
        else if(p%2==1 && q%2==0 && r%2==1){ans*=1;}
        else if(p%2==0 && q%2==1 && r%2==1){ans*=1;}
        else if(p%2==0 && q%2==0 && r%2==0){ans*=1;}
        else if(p%2==1 && q%2==1 && r%2==1){ans*=4;}
        else{ans=0;break;}
            
        p=p/2;
        q=q/2;
        r=r/2;
    }
    cout<<ans<<endl;
  }
  return 0;
}