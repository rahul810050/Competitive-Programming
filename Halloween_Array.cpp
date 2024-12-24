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
#define pb push_back
#define ppb pop_back
#define read(a) for(auto &i: a) cin >> i
#define out(ans) cout<<ans<<endl
#define yn(a) cout<< (a ? "YES": "NO") <<endl

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
        int n, l, r;
        cin >> n >> l >> r;

        vector<lli> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        sort(all(v));

        bool has_duplicate = false;
        for (int i = 1; i < n; i++) {
            if (v[i] == v[i - 1]) {
                has_duplicate = true;
                break;
            }
        }

        // Check if any element is repeated and within the range
        if (has_duplicate) {
            if (0 >= l && 0 <= r) {
                cout << "YES" << endl;
                continue;
            }
        }

        // If n is greater than 8, immediately return "NO"
        if (n > 8) {
            cout << "NO" << endl;
            continue;
        }

        lli pro = 1;
        bool valid = false;
        
        // Check XOR between pairs and calculate the product
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                lli xor_val = v[i] ^ v[j];
                if (xor_val == 0) {
                    pro = 0;
                    break;
                }
                if (pro > r / xor_val) {
                    pro = r + 1;
                    break;
                }
                pro *= xor_val;
            }
            if (pro == 0 || pro > r) break;
        }

        // Check if the product is within the range [l, r]
        if (pro >= l && pro <= r) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
