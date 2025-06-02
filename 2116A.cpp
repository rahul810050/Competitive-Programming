// coded by Cocane

#include<bits/stdc++.h>

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define foru(i, n) for(int i = n - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ppb pop_back
#define read(a) for(auto &i : a) cin >> i
#define out(ans) cout << ans << "\n"
#define yn(a) cout << (a ? "YES" : "NO") << "\n"

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        ll tkni = 2*d - 1;  
        ll tfkni = 2*c;     
        ll tgmain   = 2*b - 1; 
        ll tfmain   = 2*a;      

					if (tkni < min(tfkni, tfmain)) {
							out("Gellyfish");
					}
					else if (tfkni < min(tkni, tgmain)) {
							out("Flower");
					}
					else {
							if (tgmain < tfmain)
									out("Gellyfish");
							else
									out("Flower");
					}
    }

    return 0;
}
