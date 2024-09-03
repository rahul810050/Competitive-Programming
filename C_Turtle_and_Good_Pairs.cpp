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
				int n; string s;
				cin>>n>>s;

				map<char, int > m;
				for (int i = 0; i < n; i++)
				{
					m[s[i]]++;
				}

				vector<pair<int, char>> v;

				for(auto &it : m){
					v.pb({it.second, it.first});
				}

				sort(all(v), greater<pair<int, char>>());

				string ans = "";


				while (true){
            int flag = 0;
            for (int i = 0; i < v.size(); i++){
                if(v[i].first > 0){
                    ans += v[i].second;
                    v[i].first--;
                    flag = 1;
                }
            }
            if(flag == 0) break;
        }
			
				cout<<ans<<endl;
		}
		return 0;
}