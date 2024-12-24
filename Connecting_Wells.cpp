// coded by Cocane

#include<bits/stdc++.h>

#define ll long long
#define lli long long int
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

struct Location {
    lli x, y;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<Location> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i].x >> v[i].y;
        }

        if(n == 1){
            cout << 0 << "\n";
            continue;
        }

        vector<lli> dist(n, LLONG_MAX);
        vector<bool> inMST(n, false);
        dist[0] = 0;
        lli ans = 0;

        for(int _ = 0; _ < n; _++){
            int u = -1;
            lli best = LLONG_MAX;
            for(int i = 0; i < n; i++){
                if(!inMST[i] && dist[i] < best) {
                    best = dist[i]; 
                    u = i;
                }
            }
            inMST[u] = true;
            ans = max(ans, dist[u]);

            for(int v_idx = 0; v_idx < n; v_idx++){
                if(!inMST[v_idx]){
                    lli dx = llabs(v[u].x - v[v_idx].x);
                    lli dy = llabs(v[u].y - v[v_idx].y);
                    lli cost;
                    if(v[u].x == v[v_idx].x) {
                        cost = (dy + 1) / 2; 
                    } else if(v[u].y == v[v_idx].y) {
                        cost = (dx + 1) / 2;
                    } else {
                        cost = max(dx, dy);
                    }

                    if(cost < dist[v_idx]) {
                        dist[v_idx] = cost;
                    }
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
