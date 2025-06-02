// coded by Cocane

#include <bits/stdc++.h>

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define foru(i, n) for (int i = n - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ppb pop_back
#define read(a)     \
	for (auto &i : a) \
	cin >> i
#define out(ans) cout << ans << " "
#define outln(ans) cout << ans << endl
#define yn(a) cout << (a ? "YES" : "NO") << endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

const int MOD = 998244353;

vll pow2xx = {1};

void getPow2(int e)
{
	while ((int)pow2xx.size() <= e)
	{
		ll nxt = (pow2xx.back() * 2) % MOD;
		pow2xx.pb(nxt);
	}
}

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
		vi p(n), q(n);
		read(p);
		read(q);

		vi posP(n), posQ(n);
		forn(i, n)
		{
			posP[p[i]] = i;
			posQ[q[i]] = i;
		}

		vector<vi> vec(n);
		forn(v, n)
		{
			int time = min(posP[v], posQ[v]);
			vec[time].pb(v);
		}

		getPow2(n - 1);

		priority_queue<int> pq;
		vi r(n, 0);

		for (int i = 0; i < n; i++)
		{
			for (int v : vec[i])
			{
				pq.push(v);
			}

			int M = pq.top();

			int oth1 = -1, oth2 = -1;
			if (posP[M] <= i)
			{
				int j = posP[M];
				int k = i - j;
				oth1 = q[k];
			}
			if (posQ[M] <= i)
			{
				int k = posQ[M];
				int j = i - k;
				oth2 = p[j];
			}
			int m = max(oth1, oth2);

			ll result = (pow2xx[M] + pow2xx[m]) % MOD;
			r[i] = (int)result;
		}

		forn(i, n) out(r[i]);
		cout << endl;
	}
	return 0;
}
