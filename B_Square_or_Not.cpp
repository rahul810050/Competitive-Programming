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

bool isPerfectSquare(int num) {
    if (num < 0) return false;
    int root = static_cast<int>(sqrt(num));
    return root * root == num;
}

int main(){
		ios::sync_with_stdio(false);
		cin.tie(NULL);

		int t;
		cin>>t;
		while(t--){
				int n;
        cin >> n;
        string s;
        cin >> s;

        if (isPerfectSquare(n)) {
            int root = static_cast<int>(sqrt(n));
            int zero_count = count(all(s), '0');
            int required_zero_count = (root - 2) * (root - 2);

            yn(zero_count == required_zero_count);
        } else {
            out("NO");
        }

		}
		return 0;
}