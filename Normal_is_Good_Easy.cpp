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

  ll t;
  cin>>t;
  while(t--){
    ll n;
    cin >> n;
    vll arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ll ans = 0;
    ll l = 1;

    for (ll i = 1; i <= n; i++)
    {

        if(i == n){
             ans += (l) * (l + 1) / 2;
        }
        else{
        if (arr[i] == arr[i - 1])
        {
            l++;
        }
        else
        {
            ans += (l) * (l + 1) / 2;
            l = 1;
        }
        }
    }

    cout << ans << endl;
  }
  return 0;
}