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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ptrr = 0;
    forn(i, n)
    {
      if (s[i] == '0')
        ptrr++;
    }

    if (ptrr == n || ptrr == 0)
    {
      out(n);
      continue;
    }
    int xx=1;

    forn(i, n)
    {
      if (s[i] == '1')
        xx++;
    }

    ptrr=xx;
    
    int x1 = -1, x2 = -1, y1 = -1, y2 = -1;

    forn(i, n)
    {
      if (s[i] == '1' && x1 == -1)
        x1 = i;
      if (s[i] == '0' && y1 == -1)
        y1 = i;
    }
    foru(i, n)
    {
      if (s[i] == '1' && x2 == -1)
        x2 = i;
      if (s[i] == '0' && y2 == -1)
        y2 = i;
    }

    int ct1 = 0, ct2 = 0;
    if (x1 != -1 && x2 != -1 && x1 <= x2)
    {
      for (int i = x1; i <= x2; i++)
        if (s[i] == '0')
          ct1++;
    }

    if (y1 != -1 && y2 != -1 && y1 <= y2)
    {
      for (int i = y1; i <= y2; i++)
        if (s[i] == '1')
          ct2++;
    }

    if (x1 < y1 && y1 < x2 && x2 < y2)
    {
      out(n - (ct1 + ct2 - 1));
      continue;
    }

    if (y1 < x1 && x1 < y2 && y2 < x2)
    {
      out(n - (ct1 + ct2 - 1));
      continue;
    }

    out(n - (ct1 + ct2));
  }

  return 0;
}
