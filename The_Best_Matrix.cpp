// coded by Cocane

#include <bits/stdc++.h>

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
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;

        vector<vi> a(n, vi(m));
        forn(i, n) read(a[i]);

        vector<pair<int, int>> dir = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        int mn = n * m;

        for(auto [dr, dc] : dir){
            map<ll, int> freq;

            forn(i, n){
                forn(j, m){
                    ll k = 1LL * a[i][j] - 1LL * i * dr - 1LL * j * dc;
                    freq[k]++;
                }
            }

            for(auto &[_, cnt] : freq){
                mn = min(mn, n * m - cnt);
            }
        }

        cout << mn << endl;
    }

    return 0;
}
