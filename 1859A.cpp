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
				int n; cin>>n;
				vi v(n);
				read(v);

				unordered_map<int , int> f;
				for (int i = 0; i < n; i++)
				{
					f[v[i]]++;
				}
				if(f.size() == 1) cout<<-1<<endl;
				else {
					sort(all(v));
					vi b, c;

					int ct = count(all(v),v[n-1]);
					for (int i = 0; i < ct; i++)
					{
						c.pb(v[n-1]);
					}

					for (int i = 0; i < n-ct; i++)
					{
						b.pb(v[i]);
					}
					cout<<b.size()<<" "<<c.size()<<endl;
					for(auto &it: b) cout<<it<<" "; cout<<endl;
					for(auto &it : c) cout<<it<<" "; cout<<endl;
					
				}
				
		}
		return 0;
}