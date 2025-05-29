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
#define ppb pop_back
#define read(a) for(auto &i: a) cin >> i
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
				int n, k, d;
				cin>>n>>k>>d;
				vi v(n);
				read(v);
				sort(all(v)); 

				int blo = n, ans = 0;
				vector<pair<int, int>> reGrw;
				set<int> avail;

				forn(i, n) avail.insert(i);

				for1(j, d){
						for(auto it = reGrw.begin(); it != reGrw.end(); ){
								if(it->fi == j){
										blo++;
										avail.insert(it->se);
										it = reGrw.erase(it);
								} else ++it;
						}

						int pluck = blo - k;
						auto it = avail.begin();

						while(it != avail.end() && pluck > 0){
								int idx = *it;
								blo--;
								ans++;
								reGrw.pb({j + v[idx], idx});
								it = avail.erase(it);
								pluck--;
						}
				}

				out(ans);
		}
		return 0;
}
