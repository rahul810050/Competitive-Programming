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
		string a, b;
		cin >> a >> b;

		int ct_odd_a = 0, ct_odd_b = 0, ct_even_a = 0, ct_even_b = 0;

		for (int i = 0; i < n; i++)
		{
			if (i % 2 == 0)
			{
				if (a[i] == '1')
				{
					ct_even_a++;
				}
			}
			else
			{
				if (a[i] == '1')
				{
					ct_odd_a++;
				}
			}

			if (i % 2 == 0)
			{
				if (b[i] == '0')
				{
					ct_even_b++;
				}
			}
			else
			{
				if (b[i] == '0')
				{
					ct_odd_b++;
				}
			}
		}

		if(ct_even_a<=ct_odd_b){
			// cout<<"YES"<<endl;
		}

		
		if(ct_odd_a<=ct_even_b){
			// cout<<"YES"<<endl;
		}



		if (ct_odd_a <= ct_even_b && ct_even_a <= ct_odd_b)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}