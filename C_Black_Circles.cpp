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
typedef vector<pair<ll,ll>> vpll;
typedef vector<ll> vll;
typedef double dl;

ll dis(ll x1, ll y1, ll x2, ll y2){
    return 1ll * (x1 - x2) * (x1 - x2) + 1ll * (y1 - y2) * (y1 - y2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vpll v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].fi >> v[i].se;
        }
        
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        ll distance = dis(x1, y1, x2, y2);

        bool f = true;  

        for (int i = 0; i < n; i++) {
            if(dis(x2, y2, v[i].fi, v[i].se) <= distance){
                f = false;  
                break;
            }
        }
        
        yn(f);  
    }
    return 0;
}
