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
#define read(a) for (auto &i : a) cin >> i
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
  vi a(n + 1), b(n + 1);
  for1(i, n) cin >> a[i];
  for1(i, n) cin >> b[i];

  vi fa(2 * n + 1), fb(2 * n + 1);

  int p = 1;
  for (int i = 2; i <= n; ++i)
  {
    if (a[i] != a[i - 1])
    {
      fa[a[i - 1]] = max(fa[a[i - 1]], i - p);
      p = i;
    }
  }
  fa[a[n]] = max(fa[a[n]], n - p + 1);

  p = 1;
  for (int i = 2; i <= n; ++i)
  {
    if (b[i] != b[i - 1])
    {
      fb[b[i - 1]] = max(fb[b[i - 1]], i - p);
      p = i;
    }
  }
  fb[b[n]] = max(fb[b[n]], n - p + 1);

  int ans = 0;
  for (int i = 1; i <= 2 * n; ++i)
  {
    ans = max(ans, fa[i] + fb[i]);
  }

  out(ans);
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
