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
					int n,x,y;
					cin>>n>>x>>y;

					string s; cin>>s;

					int a_x = 0, a_y = 0;

					bool bobWin = false;

					for (int i = 0; i < n; i++)
					{
						if(s[i] == 'R'){
							a_x++;
							int b_x = abs(a_x - x);
							int b_y = abs(a_y - y);
							if(b_x + b_y == i+1){
								bobWin = true;
								// return 0;
								break;
							}
						}
						else if(s[i] == 'L'){
							a_x--;
							int b_x = abs(a_x - x);
							int b_y = abs(a_y - y);
							if(b_x + b_y == i+1){
								bobWin = true;
								// return 0;
								break;
							}
						}
						else if(s[i] == 'U'){
							a_y++;
							int b_x = abs(a_x - x);
							int b_y = abs(a_y - y);
							if(b_x + b_y == i+1){
								bobWin = true;
								// return 0;
								break;
							}
						}
						else if(s[i] == 'D'){
							a_y--;
							int b_x = abs(a_x - x);
							int b_y = abs(a_y - y);
							if(b_x + b_y == i+1){
								bobWin = true;
								// return 0;
								break;
							}
						}
					}

					yn(bobWin);
					
			}
			return 0;
	}