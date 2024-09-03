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
				vll v(n);

				for (ll i = 0; i < n; i++)
				{
					cin>>v[i];
				}
				

				for (ll i = 0; i < n; i++)
				{
					if(v[i] % 10 == 2) v[i] -= 1;
					if(v[i] % 10 == 4) v[i] -= 1;
					if(v[i] % 10 == 6) v[i] -= 1;
					if(v[i] % 10 == 8) v[i] -= 1;
					if(v[i] % 10 == 0) v[i] -= 1;
				}

				for (ll i = 0; i < n; i++)
				{
					cout<<v[i]<<" ";
				} cout<<endl;
				
				
		}
		return 0;
}