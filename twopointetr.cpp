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
				int n,k; cin>>n>>k;
				vi v(n);
				read(v);
				int i=0,j=0,sum=0,maxi=0;
				while(j<=n){
					if(sum<k){
						if(j==n) break;
						sum+=v[j];
						j++;
					}
					else if(sum>k){
						sum-=v[i];
						i++;
					}
					else{
						maxi=max(maxi,j-i);
						i++;
						sum-=v[i-1];
					}
				}
				cout<<maxi<<endl;
		}
		return 0;
}