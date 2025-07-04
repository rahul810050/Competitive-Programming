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
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    int ans = n;

    for (char c = 'a'; c <= 'z'; c++) {
      int i = 0, cur = 0;
      while (i < n) {
        int j = i;
        while (j < n && ((s[j] == c) == (s[i] == c))) {
          j++;
        }
        if (s[i] != c) {
          cur = max(cur, j - i);
        }
        i = j;
      }

      if (cur == 0) {
        ans = 0;
        break;
      }

      int pw = 0;
      while ((1 << pw) <= cur) pw++;
      ans = min(ans, pw);
    }

    out(ans);
  }

  return 0;
}