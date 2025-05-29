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
#define read(a) for (auto &i : a) cin >> i
#define out(ans) cout << ans << endl
#define yn(a) cout << (a ? "YES" : "NO") << endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

const int MAXN = 2e5 + 100;
int n, arr[MAXN], aim[MAXN], pos[MAXN], mov = 0, res[MAXN][2];

void form(int i, int j) {
	if (i == j) return;
	res[++mov][0] = i;
	res[mov][1] = j;
	swap(arr[i], arr[j]);
	swap(pos[arr[i]], pos[arr[j]]);
	swap(aim[i], aim[j]);
}

void solve() {
	cin >> n;
	for1(i, n) {
		cin >> arr[i];
		pos[arr[i]] = i;
	}
	for1(i, n) {
		cin >> aim[i];
	}

	mov = 0;
	int misIdx = 0;

	for1(i, n) {
		if (arr[i] == aim[i]) {
			if (n % 2 == 0 || misIdx) {
				out(-1);
				return;
			}
			misIdx = i;
		} else if (aim[pos[aim[i]]] != arr[i]) {
			out(-1);
			return;
		}
	}

	if (n & 1) {
		form(misIdx, (n + 1) / 2);
	}

	for1(i, n / 2) {
		form(pos[aim[i]], n - i + 1);
	}

	out(mov);
	for1(i, mov) {
		cout << res[i][0] << ' ' << res[i][1] << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
