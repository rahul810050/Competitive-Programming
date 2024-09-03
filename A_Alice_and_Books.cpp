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
				int n;cin>>n;

				vi v(n);
				forn(i,n) cin>>v[i];

				// sort(all(v));

				// int largest = v[n-1];  
				// int count_largest = count(all(v), largest);
        // if(count_largest == n){
				// 	cout<<largest *2<<endl;
				// }
				// else{
				// 	int second_largest = -1;

        // for (int i = n - 2; i >= 0; i--) {
        //     if (v[i] != largest) {
        //         second_largest = v[i];
        //         break;
        //     }
        // }

				// cout<<largest + second_largest<<endl;
				// }

				int mx = 0;

				forn(i,n-1) mx = max(mx, v[i]);

				cout<<mx + v[n-1]<<endl;
				
		}
		return 0;
}