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

vll divs(ll g) {
    vll d;
    for (ll i = 1; i * i <= g; i++) {
        if (g % i == 0) {
            d.pb(i);
            if (i * i != g) d.pb(g / i);
        }
    }
    return d;
}

bool func(const vll& b, ll x) {
    int n = b.size();
    vll a = b;
    forn(i, n - 1) {
        if (a[i + 1] % a[i] == 0) continue;
        if (a[i] % x == 0 && (a[i] / x) != 0 && (a[i + 1] % (a[i] / x)) == 0) {
            a[i] /= x;
        }
        else if (a[i + 1] % x == 0 && (a[i + 1] / x) >= a[i] && (a[i + 1] / x) % a[i] == 0) {
            a[i + 1] /= x;
        }
        else {
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vll b(n);
        read(b);

        vector<pair<ll,ll>> bad;
        forn(i, n - 1){
            if (b[i + 1] % b[i] != 0) bad.pb({b[i], b[i + 1]});
        }

        if (bad.empty()) {
            out(1);
            continue;
        }

        unordered_set<ll> cand;
        bool first = true;
        for (auto [u, v] : bad) {
            ll g = __gcd(u, v);
            vll ds = divs(g);
            unordered_set<ll> thisSet;
            for (ll d : ds) {
                thisSet.insert(u / d);
                thisSet.insert(v / d);
            }

            if (first) {
                cand = move(thisSet);
                first = false;
            } else {
                for (auto it = cand.begin(); it != cand.end(); ) {
                    if (thisSet.count(*it)) ++it;
                    else cand.erase(it++);
                }
            }

            if (cand.empty()) break;
        }

        ll answer = 1;
        for (ll x : cand) {
            if (x > 0 && func(b, x)) {
                answer = x;
                break;
            }
        }

        out(answer);
    }

    return 0;
}
