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

int len(const string &s) {
    return (int)s.length();
}

bool check(const string &s, int i, char c){
  return s[i] == c;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin>>t;
  while(t--){
    int n,k;
    string s;
    cin >> n >> k;
    cin >> s;

    int cnt = 0;
    int ct = 0;
    for (int i = 0; i < k; ++i) if (s[i] == '1') ++cnt;
    bool baje = (cnt == k);
    for (int i = k; i < n && !baje; ++i) {
      if (s[i] == '1') ++cnt;
      if (s[i - k] == '1') --cnt;
      if (cnt == k) baje = true;
    }

    if (baje) {
      cout << "NO" << '\n';
      continue;
    }

    vi p(n);
    int l = 1, h = n;
    forn(i, n){
      if (check(s, i, '1')) p[i] = l++;
      else p[i] = h--;
    }

    cout << "YES" << '\n';
    
    forn(i, n){
      if (i) cout << ' ';
      cout << p[i];
    }
    cout << '\n';
  }
  return 0;
}
