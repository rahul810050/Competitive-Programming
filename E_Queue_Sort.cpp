// coded by Cocane

#include <bits/stdc++.h>

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define foru(i, n) for (int i = n - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define allp(x) (x).begin(), (x).begin() + (x).size() / 2, (x).rbegin()
#define pb push_back
#define ppb pop_back
#define read(a)     \
  for (auto &i : a) \
  cin >> i
#define out(ans) cout << ans << endl
#define yn(a) cout << (a ? "YES" : "NO") << endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

void solve()
{
  int n;
  cin >> n;
  vi a(n);
  read(a);

  int fm = 0;
  forn(i, n)
  {
    if (a[i] < a[fm])
      fm = i;
  }

  for (int i = fm + 1; i < n; i++)
  {
    if (a[i] < a[i - 1])
    {
      out(-1);
      return;
    }
  }

  out(fm);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}
