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

ll comp_xor(ll n){
    if(n < 0) return 0;
    ll rem = n % 4;
    if(rem == 0) return n;
    if(rem == 1) return 1;
    if(rem == 2) return n + 1;
    return 0;
}

int main(){
		ios::sync_with_stdio(false);
		cin.tie(NULL);

		int t;
		cin>>t;
		while(t--){
				ll l, r, i, k;
        cin >> l >> r >> i >> k;
        ll m = 1LL << i;
        ll tstr, ten;
        if(l > k){
            tstr = (l - k + m -1) / m;
        }
        else{
            tstr = 0;
        }
        if(r >= k){
            ten = (r - k) / m;
        }
        else{
            ten = -1;
        }
        ll x_wx =0;
        if(tstr <= ten){
            ll c = ten - tstr +1;
            ll x_ten = comp_xor(ten);
            ll x_minas_1 = comp_xor(tstr -1);
            ll x_t = x_ten ^ x_minas_1;
            x_t = x_t << i;
            if(c %2 ==1){
                x_wx = x_t ^ k;
            }
            else{
                x_wx = x_t;
            }
        }
        ll xor_r = comp_xor(r);
        ll xor_l_minus_1 = comp_xor(l -1);
        ll x_total = xor_r ^ xor_l_minus_1;
        ll x_non_k = x_total ^ x_wx;
        cout << x_non_k << endl;
		}
		return 0;
}