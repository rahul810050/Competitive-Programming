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
				int n,m;
				cin>>n>>m;
				vector<vector<int>> a(n, vector<int> (m));

				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < m; j++)
					{
						cin>>a[i][j];
					}
					
				}

				if(n*m == 1) cout<<"-1"<<endl;
				else{
					for (int i = 0; i < n; i++)
					{
						for (int j = 0; j < m; j++)
						{
							cout<<a[(i + 1) % n][(j + 1) % m]<<" ";
						}
						cout<<endl;
					}
					
				}
				
		}
		return 0;
}