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

    int light[2 * n];

    int off = 0, on = 0;

    read(light);


    for (int i = 0; i < 2 * n; i++) {
        if (light[i] == 0) off++;
        else on++;
    }


    if (off == 0)  cout << "0 0" << endl;
				else {
        if (off >= on)  cout << (off % 2) << " " << on << endl;
        else cout << (on % 2) << " " << off << endl;
    }
		}
		return 0;
}