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
#define read(a) for (auto &i : a) cin >> i
#define out(ans) cout << ans << endl
#define yn(a) cout << (a ? "YES" : "NO") << endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

#define PI acos(-1.0)

bool func(vector<double> &vols , double V, int people) {
	int ct = 0;
    for(auto vol: vols){
			ct += (int) (vol/V);
		}
	return ct >= people;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
			int n,f;
        cin >> n >> f;
				vi radii(n);
				vector<double> vols(n);

        forn(i, n) cin >> radii[i];
				for (int i = 0; i < n; i++)
				{
					vols[i] = PI * radii[i] * radii[i];
				}
				
        // sort(all(radii));

        

        double lo = 0, hi = *max_element(all(vols));
        double ans = 0;
        while (hi - lo > 1e-4) {
            double mid = (lo + hi) / 2;
            if (func(vols, mid, f+1)) {
                ans = mid;
                lo = mid ;  // Move right for the best answer
            } else {
                hi = mid ;
            }
        }

        // double vol = PI * ans * ans;
        cout << fixed << setprecision(4) << ans << endl;
    }
    return 0;
}
