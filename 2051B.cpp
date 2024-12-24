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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        ll n, a, b, c;
        cin >> n >> a >> b >> c;

        ll total = a + b + c;
        ll div = n / total;
        ll day = div * 3;
        ll remain = n % total;

        if (n <= a) {
            cout << 1 << endl;
        } else if (n > a && n <= a + b) {
            cout << 2 << endl;
        } else if (n > a + b && n <= total) {
            cout << 3 << endl;
        } else {
            if(remain < 1){
							cout<<day<<endl;
						} else{
								if (remain <= a) {
									cout << day + 1 << endl;
							} else if (remain > a && remain <= a + b) {
									cout << day + 2 << endl;
							} else if (remain > a + b && remain <= total) {
									cout << day + 3 << endl;
							}
						}
        }
    }
    return 0;
}
