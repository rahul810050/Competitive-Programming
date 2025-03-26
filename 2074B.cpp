// #include<bits/stdc++.h>
// using namespace std;

// int main(){
// 	int t; cin>>t;
// 	while (t--)
// 	{
// 		int n; cin>>n;
// 		vector<int> v(n);
// 		for(auto &it: v) cin>>it;
// 		long long sum = accumulate(v.begin(), v.end(), 0);
// 		cout<<sum - (n-1)<<endl;
// 	}
	
// }



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

		// vi v(5);
		// read(v);
		// sort(all(v));
		

		int q; cin>>q;
		int l = 0, h = q;
		int mid;
		while (h - l > 1)
		{
			mid = (h + l)/ 2;
			if((mid * mid) > q) h = mid -1;
			else l = mid;
		}
		
		if(l * l == q) cout<<l<<endl;
		else cout<<h<<endl;

		return 0;
}