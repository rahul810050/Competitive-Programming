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
#define read(a)       \
    for (auto &i : a) \
    cin >> i
#define out(ans) cout << ans << endl
#define yn(a) cout << (a ? "YES" : "NO") << endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

string s;
ll n;

bool is_1100(ll i)
{
    if (i < 0 || i + 3 >= n)
        return false;
    return s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0';
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        cin >> s;
        n = s.size();
        ll cnt = 0;

        forn(i, n)
        {
            if (is_1100(i))
                cnt++;
        }

        ll q;
        cin >> q;
        while (q--)
        {
            ll idx, val;
            cin >> idx >> val;
            idx--;

            if (s[idx] != ('0' + val))
            {
                bool before = is_1100(idx - 3) || is_1100(idx - 2) || is_1100(idx - 1) || is_1100(idx);
                s[idx] = '0' + val;
                bool after = is_1100(idx - 3) || is_1100(idx - 2) || is_1100(idx - 1) || is_1100(idx);
                cnt += (after - before);
            }

            yn(cnt > 0);
        }
    }

    return 0;
}
