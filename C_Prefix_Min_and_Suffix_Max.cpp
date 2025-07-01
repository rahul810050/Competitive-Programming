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
#define yn(a) cout<< (a ? '1' : '0')

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vi a(n);
    read(a);

    vi pre(n), sufix(n);
    pre[0] = a[0];
    forn(i, n) {
      if(i>0) pre[i] = min(pre[i-1], a[i]);
    }
    sufix[n-1] = a[n-1];
    for(int i = n-2; i >=0; i--) {
      sufix[i] = max(sufix[i+1], a[i]);
    }

    forn(i, n) {
      bool flag = (a[i] == pre[i] || a[i] == sufix[i]);
      yn(flag);
    }
    cout << endl;
  }
  return 0;
}
