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


ll sumArr(vll &v){
  ll s = 0;
  for(auto it: v) s += it;
  return s;
}

ll bs(ll x, vll &a){
  int low = 0, hi = a.size();
  while(low < hi){
    int mid = (low + hi) / 2;
    if(a[mid] < x) low = mid + 1;
    else hi = mid;
  }
  return low;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin>>t;
  while(t--){
    int n;
    cin >> n;
    vll a(n);
    read(a);

    ll sum = 0;

    ll ans = sumArr(a);

    ll res = 0;
    while(ans > 0){
      res += (ans/2);
      ans /= 2;
    }
    for(int i=1;i<n-1;i+=2){
      bool ch = a[i-1]+a[i+1]>a[i];
      if(ch){
        int x = a[i-1]+a[i+1];
        int diff=(x-a[i]);
        sum+=diff;
        ans += sumArr(a);
        a[i+1]=max(a[i+1]-diff,0LL);
      }

    }
    ll uttor = 0;
    while(res){
      uttor += (res/2);
      res /= 10;
    }
    bool check = a[n-2]>a[n-1]&&n%2!=1;
    if(check){
      ans += (a[n-2]-a[n-1]);
      sum+=a[n-2]-a[n-1];
    }
    ll sr = bs(sum, a);
    ll ss = 0;
    while (sr)
    {
      ss += sr/10;
      sr /= 10;
    }
    
    cout << sum << endl;
  }
  return 0;
}