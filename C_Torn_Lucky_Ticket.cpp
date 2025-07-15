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

int digit_sum(const string &s) {
  int sum = 0;
  for (char c : s)
    sum += c - '0';
  return sum;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<string> s(n);
  read(s);

  ll ans = 0;
  int cnt[6][46] = {};

  for (const auto &y : s) {
    int len = y.size();
    int sum = digit_sum(y);
    cnt[len][sum]++;
  }

  for (const auto &L : s) {
    int lenL = L.size();
    for (int lenr = lenL % 2; lenr <= lenL; lenr += 2) {
      int l = lenL + lenr;
      if (l % 2 != 0) continue;

      int half = l / 2;
      if (half > lenL) continue;

      int suml = digit_sum(L.substr(0, half));
      int sumr = digit_sum(L.substr(half, lenL - half));

      int diff = suml - sumr;
      if (diff >= 0 && lenr <= 5 && diff <= 45)
        ans += cnt[lenr][diff];
    }
  }

  for (const auto &R : s) {
    int lenR = R.size();
    for (int lenl = lenR % 2; lenl < lenR; lenl += 2) {
      int l = lenR + lenl;
      if (l % 2 != 0) continue;

      int half = l / 2;
      if (half > lenR) continue;

      int suml = digit_sum(R.substr(lenR - half));
      int sumr = digit_sum(R.substr(0, lenR - half));

      int diff = suml - sumr;
      if (diff >= 0 && lenl <= 5 && diff <= 45)
        ans += cnt[lenl][diff];
    }
  }

  out(ans);
  return 0;
}
