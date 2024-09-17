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
				int n;
        cin >> n;

        vector<vector<char>> v(2, vector<char>(n));

        forn(i, 2) {
            forn(j, n) {
                cin >> v[i][j];
            }
        }

        bool f = false; 

        for (int j = 0; j < n; j++) {
            if ((v[0][j] == 'R' && (v[1][j] == 'G' || v[1][j] == 'B')) || 
                (v[1][j] == 'R' && (v[0][j] == 'G' || v[0][j] == 'B'))) {
                f = true;  
                break; 
            }
        }

        // Output result
        if (f) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
		}
		return 0;
}