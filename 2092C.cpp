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
		vector<ll> v(n);
		ll sum = 0;
		int odd_ct = 0;
		ll mx = 0;
		forn(i, n)
		{
			cin >> v[i];
			sum += v[i];
			if (v[i] % 2 != 0)
			{
				odd_ct++;
			}
			mx = max(mx, v[i]);
		}

		vector<int> ev, odd;
		for (int i = 0; i < n; i++)
		{
			if (v[i] % 2 == 0)
			{
				ev.push_back(v[i]);
			}
			else
			{
				odd.push_back(v[i]);
			}
		}

		sort(ev.begin(), ev.end(), greater<int>());
		sort(odd.begin(), odd.end(), greater<int>());

		if (ev.size() == 0 || odd.size() == 0)
		{
			// // int mx = 0;
			// for (int i = 0; i < n; i++)
			// {
			// 	// mx = max(v[i], mx);
			// }

			// cout << mx << endl;
		}
		else if (ev.size() == 1 && odd.size() == 1)
		{
			// cout << ev[0] + odd[0] << endl;
		}

		int ev_ct = n - odd_ct;
		if (odd_ct == 0 || ev_ct == 0)
		{
			cout << mx << "\n";
			continue;
		}
		ll cd_odd = sum - (odd_ct - 1);
		if (cd_odd % 2 == 0)
		{
			cd_odd--;
		}
		ll cd_even = sum - odd_ct;
		if (cd_even % 2 != 0)
		{
			cd_even--;
		}
		cout << max(cd_odd, cd_even) << "\n";
	}
	return 0;
}