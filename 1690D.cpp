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
		int n, k;
		string s;
		cin >> n >> k >> s;

		if (k == 1)
		{
			int x = count(all(s), 'B');
			cout << (x == 0 ? 1 : 0) << endl;
		}
		else
		{
			int currWhite = 0;

			for (int i = 0; i < k; i++)
			{
				if (s[i] == 'W')
					currWhite++;
			}

			int mnWhite = currWhite;

			for (int i = k; i < n; i++)
			{
				if (s[i - k] == 'W')
					currWhite--;
				
				if (s[i] == 'W')
					currWhite++;

				mnWhite = min(mnWhite, currWhite);
			}

			cout << mnWhite << endl;
		}
	}
	return 0;
}
