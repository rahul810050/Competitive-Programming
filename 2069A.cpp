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
			cin >> n;

			vi b(n - 2);
			read(b);

			bool flag = true;

			if (n == 3) {
					cout << "YES" << endl;
					continue;
			}

			for (int i = 1; i < n - 3; i++) {
					if (b[i] == 0 && b[i - 1] == 1 && b[i + 1] == 1) {
							flag = false;
							break;
					}
			}

			cout << (flag ? "YES" : "NO") << endl;
		}
		return 0;
}