#include<bits/stdc++.h>

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define foru(i, n) for(int i = n-1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
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
				int n, d; cin>>n>>d;
				vi a(n);

				for (int i = 0; i < n; i++)
				{
					cin>>a[i];
				}

				long long ct = 0;

				int f = 0;

				for (int i = 0; i < n; i++)
				{
					if(a[i] > d && f == 0){
						ct++;
						f = 1;
					}
					else if(a[i] <= d && f == 1){
						ct++;
						f = 0;
					}
				}

				cout<<ct<<endl;
				
				
		}
		return 0;
}