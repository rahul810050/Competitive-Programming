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
				ll n;
				cin>>n;
				vll v(n);
				read(v);
				
				ll ans = accumulate(all(v), 0LL);

				sort(all(v),greater<int>());
				// vll x(n);

				// for (int i = n-1; i >= 0; i++)
				// {
				// 	x[i] = v[i] + x[i-1];
				// }

				int sum=0;
				ans=max(ans,(n*n));

	
				for (ll i = 1; i < n; i++)
				{
					
						sum+=v[i-1];
						
						ll cnt=(n-i)*(n-i);
					
					ans=max(ans,sum+cnt);

				
				}
				cout<<ans<<endl;
				
		}
		return 0;
}