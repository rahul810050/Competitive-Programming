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

				vector<pair<int,int>> stamps(n);
				int mx_left = 0, mx_right = 0;

				for (int i = 0; i < n; i++)
				{
					cin>>stamps[i].fi>>stamps[i].se;
					mx_left = max(stamps[i].fi, mx_left);
					mx_right = max(stamps[i].se, mx_right);
				}
				
				cout<<2*(mx_left + mx_right)<<endl;
		}
		return 0; 	
}