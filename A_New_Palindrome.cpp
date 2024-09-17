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

		int t,i;
		cin>>t;
		for(i=0; i<t; i++){
				string s; cin>>s;
				
				map<char, int> v;
				int j;
				for (j = 0; j < s.length(); j++)
				{
					v[s[j]]++;
				}

				int f = 0;
				
				if(v.size() == 2){
					for(auto &it : v){
						if(it.se == 1){
							cout<<"NO"<<endl;
							f = 1;
							break;
						}
					}
					if(f == 0) cout<<"YES"<<endl;
				}
				else if(v.size() == 1){
					cout<<"NO"<<endl;
				}
				else cout<<"YES"<<endl;

		}
		return 0;
}