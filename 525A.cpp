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

				int n; cin>>n;

				string s; cin>>s;

				multiset<char> ms;

				int ct = 0;

				for (int i = 0; i < 2*n-2; i++)
				{

					if(islower(s[i])){
						ms.insert(s[i]);
					}
					else{
						if(ms.find(tolower(s[i])) != ms.end()) ms.erase(ms.find(tolower(s[i])));
						else{
							ct++;
							// ms.insert(tolower(s[i]));
						}
					}

					// if(i % 2 == 1){
					// 	if((s[i] - 'A') == (s[i-1] - 'a')) continue;
					// 	else{
					// 		if(ms.find(s[i] - 'A') == ms.end()){
					// 			ms.insert(s[i]- 'A');
					// 			ct++;
					// 		}
					// 		else{
					// 			ms.erase(s[i] - 'A');
					// 		}
					// 	}
					// }
				}

				cout<<ct<<endl;
				

		return 0;
}