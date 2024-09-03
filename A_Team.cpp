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

		int n;
		cin>>n;

		int ct = 0;
		while(n--){
				
				int a[3];
				int sure = 0;
				for (int i = 0; i < 3; i++)
				{
					cin>>a[i];
				}
				
				for (int i = 0; i < 3; i++)
				{
					if(a[i] == 1) sure++;
				}
				
				if(sure >= 2) ct++;

		}

		out(ct);

		return 0;
}