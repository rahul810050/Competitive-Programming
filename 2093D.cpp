// coded by Cocane

#include<bits/stdc++.h>

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define foru(i, n) for(int i = n - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define allp(x) (x).begin(), (x).begin() + (x).size()/2, (x).rbegin()
#define pb push_back
#define ppb pop_back
#define read(a) for(auto &i : a) cin >> i
#define out(ans) cout << ans << endl
#define yn(a) cout << (a ? "YES" : "NO") << endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int bits, q;
        cin >> bits >> q;

        while (q--) {
            string type;
            cin >> type;

            if (type == "->") {
                int a, b;
                cin >> a >> b;
                a--, b--;

                ll code = 0;
                foru(i, bits) {
                    int mask = 1 << i;

                    if (!(a & mask) && !(b & mask))
                        code ^= 0LL << (2 * i);
                    else if ((a & mask) && (b & mask))
                        code ^= 1LL << (2 * i);
                    else if ((a & mask) && !(b & mask))
                        code ^= 2LL << (2 * i);
                    else if (!(a & mask) && (b & mask))
                        code ^= 3LL << (2 * i);
                }

                out(code + 1);
            } else {
                ll code;
                cin >> code;
                code--;

                int x = 0, y = 0;

                foru(i, bits) {
                    ll val = (code >> (2 * i)) & 3;

                    if (val == 0) {
                        // x ^= 0, y ^= 0
                    } else if (val == 1) {
                        x ^= (1 << i);
                        y ^= (1 << i);
                    } else if (val == 2) {
                        x ^= (1 << i);
                    } else if (val == 3) {
                        y ^= (1 << i);
                    }
                }

                cout << x + 1 << ' ' << y + 1 << endl;
            }
        }
    }

    return 0;
}
