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

const ll MOD = 998244353;

ll mdExpo(ll x, ll exp, ll m) {
	ll res = 1;
	x %= m;
	while(exp > 0) {
			if(exp & 1)
					res = (res * x) % m;
			x = (x * x) % m;
			exp >>= 1;
	}
	return res;
}

ll addition(ll a, ll b) {
    return a + b;
}

ll subtraction(ll a, ll b) {
    return a - b;
}

ll multiplication(ll a, ll b) {
    return a * b;
}

ll division(ll a, ll b) {
    return (b != 0) ? (a / b) : 0;
}

int main(){
		ios::sync_with_stdio(false);
		cin.tie(NULL);

		int t;
		cin>>t;
		while(t--){
				ll n;
				cin >> n;
				if(n % 2 == 1){
						ll expo = (n - 1) / 2;
						cout << mdExpo(4, expo, MOD) % MOD << endl;
				}
				else{
						ll expo = (n / 2) - 1;
						cout << (3 * mdExpo(4, expo, MOD)) % MOD << endl;
				}
		}
		return 0;
}
