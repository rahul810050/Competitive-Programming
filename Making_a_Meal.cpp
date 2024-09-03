#include<bits/stdc++.h>

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define foru(i, n) for(int i = n-1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
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
				vector<string> v(n);

				for (int i = 0; i < n; i++)
				{
					cin>>v[i];
				}

				int c = 0, o = 0, d = 0, e = 0, h = 0, f = 0;
				
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < v[i].length(); j++)
					{
						if(v[i][j] == 'c') c++;
						else if(v[i][j] == 'o') o++;
						else if(v[i][j] == 'd') d++;
						else if(v[i][j] == 'e') e++;
						else if(v[i][j] == 'h') h++;
						else if(v[i][j] == 'f') f++;
					}
					
					
				}

				vector<int> count;
					count.pb(c / 2);
					count.pb(o);
					count.pb(d);
					count.pb(e / 2);
					count.pb(f);
					count.pb(h);

					int mini = *min_element(all(count));
					
					cout<<mini<<endl;
				
		}
		return 0;
}