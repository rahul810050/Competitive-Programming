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

		vi pre0, pre1;
		for (int i = 0; i < n - 1; i++)
		{
			if (s[i] == '0')
				pre0.pb(i);
			else
				pre1.pb(i);
		}

		reverse(all(pre1));  // Preserving reverse logic as is

		int pi = pre0.size() - 1;
		int pola = pre1.size() - 1;
		int mal = n * (n + 1) / 2;

		for (int i = n - 1; i >= 0; i--)
		{
			while (pi >= 0 && pre0[pi] >= i)
				pi--;
			while (pola >= 0 && pre1[pola] >= i)
				pola--;

			if (s[i] == '1')
			{
				if (pi >= 0 && pre0[pi] < i)
				{
					mal -= (i + 1);
					pi--;
				}
				else if (pola >= 0 && pre1[pola] < i)
				{
					mal -= (i + 1);
					pola--;
				}
			}
		}

		out(mal);
	}
	return 0;
}
