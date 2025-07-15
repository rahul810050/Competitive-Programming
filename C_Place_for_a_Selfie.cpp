// coded by Cocane

#include <bits/stdc++.h>

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define foru(i, n) for(int i = n - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define allp(x) (x).begin(), (x).begin() + (x).size() / 2, (x).rbegin()
#define pb push_back
#define ppb pop_back
#define read(a) for(auto &i : a) cin >> i
#define out(ans) cout << ans << endl
#define yn(a) cout << (a ? "YES" : "NO") << endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  forn(tc, t) {
    int n, m;
    cin >> n >> m;
    vi v(n);
    read(v);
    sort(all(v));

    forn(i, m) {
      int a, b, c;
      cin >> a >> b >> c;
      ll threshold = 4LL * a * c;
      bool flag = false;

      int ind = lower_bound(all(v), b) - v.begin();

      int res = -1;

      if (ind < n) {
        ll diff = 1LL * (v[ind] - b) * (v[ind] - b);
        if (diff < threshold) {
          flag = true;
          res = v[ind];
        }
      }

      if (ind > 0) {
        ll diff = 1LL * (v[ind - 1] - b) * (v[ind - 1] - b);
        if (diff < threshold) {
          if (!flag || v[ind - 1] < res) {
            flag = true;
            res = v[ind - 1];
          }
        }
      }

      if (flag) {
        cout << "YES\n" << res << "\n";
      } else {
        cout << "NO\n";
      }
    }

    if (tc != t - 1) cout << '\n';
  }

  return 0;
}
