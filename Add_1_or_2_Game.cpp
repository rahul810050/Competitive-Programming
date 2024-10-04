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
				int n; cin>>n;

				if(n == 1) cout<<"ALICE"<<endl;
				else if(n == 2) cout<<"BOB"<<endl;
				else if(n == 3) cout<<"BOB"<<endl;
				else if(n == 4) cout<<"BOB"<<endl;
				else if(n == 5) cout<<"BOB"<<endl;
				else if(n == 6) cout<<"BOB"<<endl;
				else if(n == 7) cout<<"ALICE"<<endl;
				else if(n == 8) cout<<"BOB"<<endl;
				else if(n == 9) cout<<"BOB"<<endl;
				else if(n == 10) cout<<"ALICE"<<endl;
		}
		return 0;
}