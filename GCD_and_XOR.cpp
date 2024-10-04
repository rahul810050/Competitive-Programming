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
		cin>>t;
		while(t--){
				int n,k; cin>>n>>k;

				vi v(n);

				read(v);

				int cnt = 0;

        if (n == 1) {
            cout << (v[0] == k ? 0 : 1) << endl;
            continue;
        }

        for (int i = 0; i < n; i++) {
            if (v[i] == k) {
                continue;
            }

            cnt++;
            
            while(i < n-1 && v[i] == v[i + 1]) i++;
            
            bool flg = false;
            while (i < n && __gcd(v[i], k) == k) {
                i++;
                flg = true;
            }
            
            if(i < n  && flg ==  true) cnt++;
        }
        if(cnt >= 2){
            cout<< 2 <<endl;
        }

        else cout << cnt << endl;

		}
		return 0;
}