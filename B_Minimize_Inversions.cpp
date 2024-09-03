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
				ll n; cin>>n;
				vll a(n);
				vll b(n);
				for (ll i = 0; i < n; i++)
				{
					cin>>a[i];
				}
				
				for (ll i = 0; i < n; i++)
				{
					cin>>b[i];
				}
				
				map<ll,ll> m;

				for (ll i = 0; i < n; i++)
				{
					m[a[i]] = b[i];
				}

				for(auto & it: m){
					cout<<it.fi<<" ";
				} cout<<endl;

				for(auto &it : m){
					cout<<it.se<<" ";
				} cout<<endl;
				
		}
		return 0;
}