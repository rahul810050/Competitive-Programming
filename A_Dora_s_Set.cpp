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
				int l,r;
				cin>>l>>r;

				int totNum = r - l + 1;

				if(totNum % 2 == 0){
					int x = totNum / 2;
					cout<<x / 2<<endl;
				} else{
					if(l % 2 == 0){
						int x = totNum / 2;
						cout<< x / 2<<endl;
					}
					else{
						int x = (totNum / 2) + 1;
						cout<< x / 2<<endl;
					}
				}
				
		}
		return 0;
}