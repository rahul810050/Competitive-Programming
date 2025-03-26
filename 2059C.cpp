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

void solve() {
    int n;
    cin >> n;
    vector<vll> a(n, vll(n));

    forn(i, n) forn(j, n) cin >> a[i][j];

    vector<vll> dppp(n, vll(n));
    
    forn(i, n) {
        ll sum = 0;
        foru(j, n) {
            sum += a[i][j];
            dppp[i][j] = sum;  
        }
    }
    
    vi ord(n);
    forn(i, n) ord[i] = i;
    
    int maxmexiExcluded = 0;
    
    do {
        vll finaleHai(n);
        forn(i, n) {
            int Q = ord[i];  
            finaleHai[Q] = (i == n-1) ? 0 : dppp[Q][i+1];
        }
        
        vector<bool> sent(n + 1, false);
        forn(i, n) if(finaleHai[i] <= n) sent[finaleHai[i]] = true;
        
        int mexiExcluded = 0;
        while(mexiExcluded <= n && sent[mexiExcluded]) mexiExcluded++;
        
        maxmexiExcluded = max(maxmexiExcluded, mexiExcluded);
        
    } while(next_permutation(all(ord)));
    
    out(maxmexiExcluded);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
