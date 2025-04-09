// coded by Cocane

#include<bits/stdc++.h>

#define ll long long
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
			int n ; cin>>n;
				vi v(n);
				read(v);
				auto remove1 = remove(all(v), 1);
				v.erase(remove1, v.end());
				for(auto &it: v) cout<<it<<" ";
				cout<<endl;
		}
		return 0;
}