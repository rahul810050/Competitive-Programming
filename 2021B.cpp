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
				int n,x;
				cin>>n>>x;

				vi v(n);

				read(v);

				sort(all(v));

				map<ll, ll> m1,m2;

				for(auto &it: v) m1[it]++;

				int ct = 0;

				while (true)
				{
					if(m1[ct] > 0){
						m1[ct]--;
						int f = m1[ct];
						m2[ct % x] += f;
						ct++;
					}
					else if(m2[ct % x] > 0){
						m2[ct % x]--;
						ct++;
					} else{
						break;
					}
				}

				cout<<ct<<endl;
				
		}
		return 0;
}