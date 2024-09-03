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

vector<string> validString;

void generate(string &s, int open, int close){
	// cout<<s<<endl;
	if(open == 0 && close == 0){
		validString.pb(s);
		return;
	}
	if(open > 0){
		s.pb('(');
		generate(s, open - 1, close);
		s.pop_back();
	}
	if(close > 0 && close > open){
		s.pb(')');
		generate(s, open, close - 1);
		s.pop_back();
	}
}


int main(){
		ios::sync_with_stdio(false);
		cin.tie(NULL);

		
				int n; cin>>n;

				string s = "";
				generate(s, n, n);

				for(auto &i: validString) cout<< i <<" ";
				cout<<endl;

		
		return 0;
}