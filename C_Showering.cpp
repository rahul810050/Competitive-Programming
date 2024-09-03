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
typedef vector<pair<ll,ll>> vpll;
typedef double dl;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n, s, m; 
        cin >> n >> s >> m;
        vpll work(n);

        forn(i, n) {
            cin >> work[i].fi >> work[i].se;
        }

        sort(all(work));

        int f = 0;

        if(work[0].fi >= s){
            f = 1;
        }

        for (int i = 1; i < n; i++) {
            if((work[i].fi - work[i-1].se) >= s) {
                f = 1;
                break;
            }
        }

        if(m - work[n-1].se >= s) f = 1;
        

        cout << (f == 1 ? "YES" : "NO") << endl;
    }
    return 0;
}
