// coded by Cocane

#include <bits/stdc++.h>

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define foru(i, n) for(int i = n-1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define allp(x) (x).begin(), (x).begin() + (x).size()/2, (x).rbegin()
#define pb push_back
#define ppb pop_back
#define read(a) for(auto &i: a) cin >> i
#define out(ans) cout << ans << endl
#define yn(a) cout << (a ? "NO" : "YES") << endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

void check1100(set<int>& ind, const string& s, int p) {
    if (p >= 0 && p + 3 < s.size()) {
        if (s.substr(p, 4) == "1100") {
            ind.insert(p);   
        } else {
            ind.erase(p);    
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int q;
        cin >> q;

        set<int> ind;  

        if (s.size() >= 4) {
            for (int i = 0; i <= s.size() - 4; ++i) {
                if (s.substr(i, 4) == "1100") {
                    ind.insert(i);
                }
            }
        }

        while (q--) {
            int i, v;
            cin >> i >> v;
            --i; 

            if (s[i] - '0' != v) {
                s[i] = v + '0';

                if (s.size() >= 4) {
                    for (int j = max(0, i - 3); j <= min((int)s.size() - 4, i); ++j) {
                        check1100(ind, s, j);
                    }
                }
            }

            yn(ind.empty());
        }
    }
    return 0;
}
