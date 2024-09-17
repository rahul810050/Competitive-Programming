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
				vector<pair<int , int>> v(3);

				int x1,x2,x3,y1,y2,y3;
				cin>>x1>>y1>>x2>>y2>>x3>>y3;

				if(y1 != y2 && y1 != y3 && y2 != y3) cout<<"YES"<<endl;
				else if(x1 != x2 && x1 != x3 && x2 != x3) cout<<"YES"<<endl;
				else cout<<"NO"<<endl;
				
		}
		return 0;
}