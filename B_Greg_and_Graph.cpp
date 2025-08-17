// coded by Cocane

#include<bits/stdc++.h>

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define foru(i, n) for(int i = n-1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
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

    int n; cin >> n;
    vector<vector<ll>> dist(n, vector<ll>(n));

    forn(i, n) {
        forn(j, n) {
            cin >> dist[i][j];
        }
    }

    vi del_vec(n);
    forn(i, n) {
        cin >> del_vec[i];
        del_vec[i]--;
    }

    reverse(all(del_vec));
    vll ans;

    forn(k, n) {
        int it = del_vec[k];
        
        forn(i, n) {
            forn(j, n) {
                dist[i][j] = min(dist[i][j], dist[i][it] + dist[it][j]);
            }
        }

        ll sum = 0;
        for(int i = 0; i <= k; i++) {
            for(int j = 0; j <= k; j++) {
                sum += dist[del_vec[i]][del_vec[j]];
            }
        }
        ans.pb(sum);
    }

    reverse(all(ans));
    for(auto s : ans) cout << s << " ";
    cout << endl;

    return 0;
}
