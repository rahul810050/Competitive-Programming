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

void find_triplets(const string &s) {
    int n = s.length();

		// Simple cases first
    // 1. Case: a = s[0], b = s[1], c = s.substr(2)
    if (n >= 3) {
        string a = s.substr(0, 1);
        string b = s.substr(1, 1);
        string c = s.substr(2);
        if ((a <= b && c <= b) || (b <= a && b <= c)) {
            cout << a << " " << b << " " << c << endl;
            return;
        }
    }

    // 2. Case: a = s[0], b = s.substr(1, n-2), c = s[n-1]
    if (n >= 3) {
        string a = s.substr(0, 1);
        string b = s.substr(1, n - 2);
        string c = s.substr(n - 1, 1);
        if ((a <= b && c <= b) || (b <= a && b <= c)) {
            cout << a << " " << b << " " << c << endl;
            return;
        }
    }
    
    // for (int i = 1; i < n - 1; i++) {
    //     for (int j = i + 1; j < n; j++) {
    //         string a = s.substr(0, i);
    //         string b = s.substr(i, j - i);
    //         string c = s.substr(j);
            
    //         if ((a <= b && c <= b) || (b <= a && b <= c)) {
    //             cout << a << " " << b << " " << c << endl;
    //             return;
    //         }
    //     }
    // }
    
    
}


int main(){
		ios::sync_with_stdio(false);
		cin.tie(NULL);

		int t;
		cin>>t;
		while(t--){
				string s; cin>>s;

				find_triplets(s);

		}
		return 0;
}