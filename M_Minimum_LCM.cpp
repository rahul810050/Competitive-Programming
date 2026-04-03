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


bool isPrime(ll n){
  for(ll i = 2; i < n; i++){
    if(n % i == 0) return true;
  }
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin>>t;
  while(t--){
    ll n; cin>>n;
    // if(isPrime(n)){
    //   cout<<1<<" "<<n-1<<endl;
    //   continue;
    // }
    // ll a = n/2;
    // ll b = n % 2 == 0 ? a : a + 1;
    // vector<ll, pair<ll, ll>> v;
    // while(a > 0 && b < n){

    // }
    if(n % 2 == 0) {
      cout<<n/2<<" "<<n/2<<endl;
    } else {
      ll d = 1;
      for(ll i = 3; i * i <= n; i+=2){
        if(n % i == 0){
          d = i;
          break;
        }
      }
      if(d == 1){
        cout<<1<<" "<<n-1<<endl;
      } else {
        ll a = n / d;
        cout<<a<<" "<<n-a<<endl;
      }
    }
  }
  return 0;
}