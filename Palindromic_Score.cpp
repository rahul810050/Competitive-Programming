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
				int a,b,c;
				cin>>a>>b>>c;
				vi v={a,b,c};
				sort(all(v));
				int cnt=0;
				for(int i=0;i<3;i++){
					if(v[i]%2 ) cnt++;
				}
				if(cnt==3){
					cout<<v[0]+v[1]-1<<endl;
				}else if(cnt==2){
					if(v[2]%2){
						cout<<v[0]+v[1]<<endl;}
						else{
							 cout<<v[0]+v[1]-1<<endl;
						}
				}else if(cnt==1){
					{
						cout<<v[0]+v[1]<<endl;
					}
				}else cout<<v[0]+v[1]<<endl;
		}
		return 0;
}