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
				int n;
				cin>>n;
				int nPlus = n + 1;

				int a[nPlus];

				for (int i = 0; i <= n; i++)
				{
					cin>>a[i];
				}
				

				vi vSum;

				for (int i = 0; i <= n; i++)
				{
					sort(a,a+ (n-1));
					for (int j = n-1; j >= 0; j--)
					{
						if(a[j] > a[n] && a[j] <= 2 * a[n]){
							swap(a[j],a[n]);
					}
					}
					
				}
				ll sum = 0;
				
				for (int i = 0; i < n; i++)
				{
					sum += a[i];
				}

				cout<<sum<<endl;
				
		}
		return 0;
}