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

int n,m;
int dx[] = {-1,0,+1,0};
int dy[] = {0,-1,0,+1};


inline bool inside(int i, int j){
	return (0 <= i && i < n && 0 <= j && j < m);
}


int main(){
		ios::sync_with_stdio(false);
		cin.tie(NULL);

		int t;
		cin>>t;
		while(t--){
				cin>>n>>m;

				vector<vector<ll>> v(n, vector<ll>(m));

				for(auto & it : v){
					for(auto & x: it) cin>>x;
				}

				

				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < m; j++)
					{
						ll mx = 0;

						for (int k = 0; k < 4; k++)
						{
							int ni = i + dx[k], nj = j + dy[k];
							if(inside(ni,nj)) mx = max(mx, v[ni][nj]);
						}
						
						v[i][j] = min(v[i][j], mx);

					}
					
				}

				for(auto &it: v){
					for(auto & element: it) cout<<element<<" ";
					cout<<endl;
				}
				
				
		}
		return 0;
}