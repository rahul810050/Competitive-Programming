// // coded by Cocane

// #include<bits/stdc++.h>

// #define ll long long
// #define forn(i, n) for(int i = 0; i < n; i++)
// #define for1(i, n) for(int i = 1; i <= n; i++)
// #define foru(i, n) for(int i = n-1; i >= 0; i--)
// #define fi first
// #define se second
// #define all(x) (x).begin(),(x).end()
// #define allp(x) (x).begin(), (x).begin() + (x).size()/2, (x).rbegin()
// #define pb push_back
// #define out(ans) cout<<ans<<endl
// #define yn(a) cout<< (a ? "YES": "NO") <<endl

// using namespace std;

// typedef vector<int> vi;
// typedef vector<ll> vll;
// typedef double dl;


// int main(){
// 		ios::sync_with_stdio(false);
// 		cin.tie(NULL);

// 		int t;
// 		cin>>t;
// 		while(t--){
// 				int l,r,L,R;
// 				cin>>l>>r>>L>>R;

// 				// int intersection = min(r,R) - max(l,L) + 1;
// 				int intersection;
// 				if(r < L){
// 					intersection = L - r;
// 				}
// 				else if(R < l){
// 					intersection = l - R;
// 				}
// 				int ans = intersection - 1;
// 				if(intersection > 0){
// 					// ans = 1;
// 					cout<<1<<endl;
// 				}
// 				else{
// 					// ans += (l != L);
// 					// ans += (r != R);
// 					int x = max(l,L);
// 					int y = min(r,R);
// 					cout<<(--x) - (++y)<<endl;
// 				}
// 				// cout<<ans<<endl;
// 		}
// 		return 0;
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
				int l,r,L,R;
				cin>>l>>r>>L>>R;

				if(max(l,L) > min(r,R)){
					cout<<1<<endl;
				}
				else{
					int rooms = min(r,R) - max(l,L) + 1;
					int ans = rooms - 1;
					ans += (l != L);
					ans += (r != R);
					cout<<ans<<endl;
				}
		}
		return 0;
}