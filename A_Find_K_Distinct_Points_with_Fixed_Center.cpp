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
typedef vector<pair<int, int>> vpi;
typedef vector<ll> vll;
typedef double dl;


int main(){
		ios::sync_with_stdio(false);
		cin.tie(NULL);

		int t;
		cin>>t;
		while(t--){
				int xc, yc, k;
        cin >> xc >> yc >> k;

				// one way to do this

        // for (int i = 0; i < k - k % 2; i++)
        // {
        //     cout<< xc << " "<< yc - (i & 1 ? 1: -1) * (i / 2 + 1)<<endl;
        // }

				// if(k % 2 != 0){
				// 	cout<<xc<<" "<<yc<<endl;
				// }


				// another way to do this 
				int x = xc, y = yc;

				int a = k/2;

				for (int i = 0; i < a; i++)
				{
					cout<<++x<<" "<<++y<<endl;
				}

				x = xc; y = yc;

				for (int i = 0; i < a; i++)
				{
					cout<<--x<<" "<<--y<<endl;
				}
				
				if(k % 2 != 0) cout<<xc<<" "<<yc<<endl;

        
        
		}
		return 0;
}