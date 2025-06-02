// coded by Cocane

#include <bits/stdc++.h>

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define foru(i, n) for (int i = n - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ppb pop_back
#define read(a)     \
    for (auto &i : a) \
        cin >> i
#define out(ans) cout << ans << "\n"
#define yn(a) cout << (a ? "YES" : "NO") << "\n"

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef queue<int> que;
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
        vi d(n);
        read(d);
        vi l(n), r(n);
        forn(i, n) cin >> l[i] >> r[i];

        int left = 0;
        vi last;
        bool failed = false;

        forn(i, n)
        {
            if (d[i] == -1)
            {
                last.pb(i);
            }
            else
            {
                left += d[i];
            }

            while (left < l[i])
            {
                if (last.empty())
                {
                    out(-1);
                    failed = true;
                    break;
                }
                d[last.back()] = 1;
                ++left;
                last.ppb();
            }
            if (failed) break;

            while (left + (int)last.size() > r[i])
            {
                if (last.empty())
                {
                    out(-1);
                    failed = true;
                    break;
                }
                d[last.back()] = 0;
                last.ppb();
            }
            if (failed) break;
        }

        if (failed) continue;

        for (auto &x : d)
        {
            cout << max(0, x) << " ";
        }
        cout << endl;
    }
    return 0;
}
