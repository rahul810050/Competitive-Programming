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
			int n;
			cin >> n;
			vi v(n);
			forn(i, n) cin >> v[i];
			vi a(n);
			
			if(n == 1){
					cout << v[0] << endl;
					continue;
			}

			for (int i = 0; i < n; i++)
			{
				a[i] = i;
			}
			int mx = 0;
			
			
			ll bonEv = (n - 1) / 2;   
			ll bonOd = (n - 3) / 2;     
			
			ll resEv = 0, resOd = 0;
			for(int i = 0; i < n; i += 2){
					resEv = max(resEv, v[i] + bonEv);
			}
			for(int i = 1; i < n; i += 2){
					resOd = max(resOd, v[i] + bonOd);
			}
			
			cout << max(resEv, resOd) << endl;
		}
		return 0;
}