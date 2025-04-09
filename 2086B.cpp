// coded by Cocane

#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define allp(x) (x).begin(), (x).begin() + (x).size()/2, (x).rbegin()
#define pb push_back
#define ppb pop_back
#define read(a) for(auto &i: a) cin >> i
#define out(ans) cout << ans << endl
#define yn(a) cout << (a ? "YES" : "NO") << endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

const int MODULO = 1000000007;
const int LIMIT = 1000005;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n >> k >> x;
        vi v(n);
        read(v);
        
        vi pp(n * k);
        for (int i = 0; i < n * k; i++) {
            pp[i] = v[i % n];
        }

        int total = accumulate(all(v), 0);
        
        if (total * k < x) {
            out(0);
            continue;
        }

        vi prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + v[i];
        }

        int ct_pos = 0;
        for (int i = 0; i < n; i++) {
            int prereq = x + prefixSum[i];
            int mn = 0;
            if (prereq > total) {
                mn = (prereq + total - 1) / total - 1;
            }
            if (mn < k) {
                ct_pos += (k - mn);
            }
        }
        out(ct_pos);
    }
    return 0;
}
