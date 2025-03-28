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

const int N = 1e6+10;

ll tree[N];

int n;

ll m;

bool isTreeSufficient(int mid){
	ll wood = 0;
	for (int i = 0; i < n; i++)
	{
		if(tree[i] > mid) wood += (tree[i] - mid);
	}
	return wood >= m;
}

int main(){
		ios::sync_with_stdio(false);
		cin.tie(NULL);

		cin>>n>>m;
		
		for (int i = 0; i < n; i++)
		{
			cin>>tree[i];
		}
		ll lo = 0, hi = 1e9, mid;
		while (hi - lo > 1)
		{
			mid = (hi + lo) / 2;
			if(isTreeSufficient(mid)){
				lo = mid;
			} else{
				hi = mid - 1;
			}
		}
		
		if(isTreeSufficient(hi)) cout<<hi<<endl;
		else cout<<lo<<endl;
		return 0;
}