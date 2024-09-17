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

/*
** it basically works on only a 
monotonic function(which maintain a given order)
eg: 1,2,3,4,5,6-> ascending order
    6,5,4,3,2-> descending order
    TTTTFFFF-> monotonic function
    FFFTTTTT-> monotonic function
*/ 
/*
we can apply BS in y = x2 as well
we can apply BS in anywhere which
maintain a given order
*/ 


int main(){
		ios::sync_with_stdio(false);
		cin.tie(NULL);

		int n; cin>>n;
		vi v(n);
		forn(i, n) cin>>v[i];

		sort(all(v));

		int lo = 0, hi = n-1;
		int mid;

		int to_find; cin>>to_find;

		while (hi - lo > 1)
		{
			mid = (hi + lo) / 2;
			if(v[mid] < to_find) lo = mid + 1;
			else hi = mid;
		}
		
		if(to_find == v[hi]) cout<<hi<<endl;
		else if(to_find == v[lo]) cout<<lo<<endl;

		return 0;
}