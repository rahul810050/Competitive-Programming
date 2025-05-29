// coded by Cocane

#include<bits/stdc++.h>

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define foru(i, n) for(int i = n-1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define allp(x) (x).begin(), (x).begin() + (x).size()/2, (x).rbegin()
#define pb push_back
#define ppb pop_back
#define read(a) for(auto &i: a) cin >> i
#define out(ans) cout<<ans<<endl
#define yn(a) cout<< (a ? "YES": "NO") <<endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;

		int ct01 = 0, ct10 = 0;

		for1(i, n - 1) {
			if (s[i - 1] == '0' && s[i] == '1') ct01++;
			else if (s[i - 1] == '1' && s[i] == '0') ct10++;
		}

		if (s[0] == '1') ct01++;

		int mov = ct01 + ct10;
		int total = n + mov;

		int xx = 0;
		if (max(ct01, ct10) >= 2) xx = 2;
		else if (ct01 >= 1 && ct10 >= 1) xx = 1;

		ll ans = total - xx;

		out(ans);
	}

	return 0;
}
