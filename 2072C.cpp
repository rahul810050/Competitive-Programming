// coded by Cocane

#include<bits/stdc++.h>

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define foru(i, n) for(int i = n - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define allp(x) (x).begin(), (x).begin() + (x).size()/2, (x).rbegin()
#define pb push_back
#define ppb pop_back
#define read(a) for(auto &i : a) cin >> i
#define out(ans) cout << ans << endl
#define yn(a) cout << (a ? "YES" : "NO") << endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

void solve() {
	int l, val;
	cin >> l >> val;
	vi ans(l, val);
	int orVal = 0;
	bool f = true;

	forn(i, l - 1) {
		if (((orVal | i) & val) == (orVal | i)) {
			orVal |= i;
			ans[i] = i;
		} else {
			f = false;
			break;
		}
	}

	if (f && ((orVal | (l - 1)) == val)) {
		ans[l - 1] = l - 1;
	}

	for (auto it : ans) cout << it << ' ';
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
