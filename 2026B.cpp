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


bool possi(int n, const vll &a, ll k) {

    vector<bool> dp1(n + 1, false);

    vector<bool> dp2(n + 1, false);

    dp1[0] = true;

    dp2[0] = false;


    for(int i = 0; i < n; ++i) {

        vector<bool> nxt(n + 1, false);

        vector<bool> nxt1(n + 1, false);


        if(dp1[i]) {

            if(i + 1 < n && abs(a[i + 1] - a[i]) <= k) {

                nxt[i + 2] = true;

            }

            if(k >= 1) {

                nxt1[i + 1] = true;

            }

        }


        if(dp2[i]) {

            if(i + 1 < n && abs(a[i + 1] - a[i]) <= k) {

                nxt1[i + 2] = true;

            }

        }


        for(int j = 0; j <= n; ++j) {

            if(nxt[j]) dp1[j] = true;

            if(nxt1[j]) dp2[j] = true;

        }

    }


    return dp1[n] || dp2[n];

}

int main(){
		ios::sync_with_stdio(false);
		cin.tie(NULL);

		int t;
		cin>>t;
		while(t--){
				int n;

        cin >> n;

        vll a(n);

        for(auto &it : a) cin >> it;



        ll l = 0, hi = (ll)1e18;

        ll ans = hi;

        while(l <= hi) {

            ll mid = l + (hi - l) / 2;

            if(possi(n, a, mid)) {

                ans = mid;

                hi = mid - 1;

            } else {

                l = mid + 1;

            }

        }


        cout << ans << "\n";
		}
		return 0;
}