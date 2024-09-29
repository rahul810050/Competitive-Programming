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
				ll n,q;
				cin>>n>>q;

				vll v(n);

				for(auto &it : v) cin>>it;

				map<ll , ll> m;

				for (ll i = 0; i < n; i++)
				{
					ll temp = (i+1) * (n-i) - 1;
					m[temp]++;

					if(i>0){
						ll temp2 = (n-i) * i;
						m[temp2] += (v[i] - v[i-1] - 1);
					}
				}

				while (q--)
				{
					ll x; cin>>x;

					if(m.find(x) == m.end()) cout<<0<<" ";
					else cout<<m[x]<<" ";
				} cout<<endl;
			
		}
		return 0;
}