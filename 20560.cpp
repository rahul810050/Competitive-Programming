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
				int n, m;
				cin>>n>>m;

				vector<pair<int, int>> v(n);
				for(auto &i: v) cin>>i.fi>>i.se;

				int peri = m * 4;
				
				int half = 0;

				for (int i = 1; i < n; i++)
				{
					half += v[i].fi + v[i].se;
					// cout<<abs(v[i].fi - v[i-1].fi) <<" "<< abs(v[i].se - v[i-1].se)<<endl;
				}
				
				
				cout<<peri + (half * 2)<<endl;
		}
		return 0;
}