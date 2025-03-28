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
		vector<int> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}

		vector<int> store;
		int i = 0;
		while (i < n - 1)
		{
			int ct = 1;
			if (v[i + 1] > v[i])
			{
				while (i < n - 1 && v[i + 1] > v[i])
				{
					ct++;
					i++;
				}
			}
			else if (v[i + 1] < v[i])
			{
				while (i < n - 1 && v[i + 1] < v[i])
				{
					ct++;
					i++;
				}
			}
			else
			{
				i++;
				continue;
			}

			store.push_back(ct);
		}

		int sz = store.size();
		if (sz == 1)
		{
			int first_el = store[0];
			cout << first_el * (first_el - 1) / 2 << endl;
		}
		else
		{
			int val = 0;
			for (int i = 0; i < sz - 1; i++)
			{
				int sum = store[i] + store[i+1] - 1;
				if (i == 0)
				{
					val += sum * (sum - 1) / 2;
					continue;
				}

				val += ((sum * (sum - 1) / 2) - (store[i] * (store[i] - 1) / 2));
			}

			cout<<val<<endl;
		}
	}
	return 0;
}