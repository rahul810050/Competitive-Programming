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
				ll n,k;

				cin>>n>>k;

				vll v(n);

				for(auto &it : v) cin>>it;

				ll total_cards = accumulate(all(v),0LL);

				ll mx = *max_element(all(v));

				// the no. of decks will be the max frequency of any no. 
				// sum of all the frequency of all the no. then + k coins
				// then the max size of the deck will be -> sum / mx;

				ll total_max_cards = total_cards + k;
				ll m = n;
				int flag = 0;

				while (m > 1)
				{
					ll x = total_max_cards / m;
					if(x * m >= total_cards && x >= mx){
						cout<<m<<endl;
						flag = 1;
						break;
					}
					m--;
				}
				
				if(flag == 0) cout<<1<<endl;


		}
		return 0;
}