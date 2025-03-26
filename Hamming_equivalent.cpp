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

inline int ctSetBit(int n) {
    return __builtin_popcount(n);
}

void solve() {
    int n;
    cin >> n;
    vi p(n);
    read(p);

    unordered_map<int, int> bitCountMap;
    forn(i, n) {
        bitCountMap[p[i]] = ctSetBit(p[i]);
    }

    unordered_map<int, int> posMap;
    forn(i, n) {
        posMap[p[i]] = i;
    }

    forn(i, n) {
        int tget = i + 1;

        if (p[i] != tget) {
            if (posMap.find(tget) == posMap.end() || 
                bitCountMap[p[i]] != bitCountMap[tget]) {
                out("No");
                return;
            }

            int targetIndex = posMap[tget];
            swap(p[i], p[targetIndex]);

            posMap[p[targetIndex]] = targetIndex;
            posMap[p[i]] = i;
        }
    }

    out("Yes");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
