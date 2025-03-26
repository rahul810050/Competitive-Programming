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
				cin>>n;
				vi a(n);
				read(a);
				int ans=max(a[0], a[n-1]);
				if(n==1){
						cout<<a[0]<<endl;
						continue;
				}
				if(n==2){
					cout<<abs(a[0]-a[1])<<endl;
					continue;
				}
				if(n==3){
					int ans=max(a[0], a[2]);
					ans=max(ans, a[1]-a[0]-a[2]);
					cout<<ans<<endl;
					continue;
				}
				for(int i=1;i<n-1;i++){
						if(i==1){
								ans=max(ans, a[i]-a[i-1]);
						}
						else if(i==n-2){
								ans=max(ans, a[i]-a[i+1]);
						}
						else{
								ans=max(ans, a[i]);
						}


				}
				cout<<ans<<endl;
				

		}
		return 0;
}