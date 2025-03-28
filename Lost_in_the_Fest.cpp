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


int solve(vi & h, int n) {
	int bh = h[n - 1];
	int x = n - 1; 
	
	while (x > 0) {
			if (bh > *max_element(h.begin(), h.begin() + x)) {
					break;
			}
			swap(h[x], h[x - 1]);
			x--;
	}
	return (n - 1 - x);
}

int main(){
		ios::sync_with_stdio(false);
		cin.tie(NULL);

		int t;
		cin>>t;
		while(t--){
				int n; cin>>n;
				vi h(n);
				read(h);

				cout<<solve(h, n)<<endl;
				
		}
		return 0;
}