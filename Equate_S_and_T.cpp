// coded by Cocane

#include <bits/stdc++.h>

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define foru(i, n) for(int i = n - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define allp(x) (x).begin(), (x).begin() + (x).size() / 2, (x).rbegin()
#define pb push_back
#define ppb pop_back
#define read(a) for(auto &i : a) cin >> i
#define out(ans) cout << ans << endl
#define yn(a) cout << (a ? "YES" : "NO") << endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;
const ll MOD_VAL = 1e9 + 7;

string modString(const string &str) {
    string ans;
    for (char ch : str) {
        ans += ch;
        if (ans.size() >= 2 && ans[ans.size() - 2] == 'a' && ans[ans.size() - 1] == 'b') {
            ans.pop_back(); 
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        string s, t;
        cin >> s >> t;

        string mod_s = modString(s);
        string mod_t = modString(t);

        if (mod_s.size() != mod_t.size()) {
            cout << "NO" << endl;
        } else {
            bool is_equal = true;
            for (int it = 0; it < mod_s.size(); it++) {
                if (mod_s[it] != mod_t[it]) {
                    is_equal = false;
                    break;
                }
            }
            cout << (is_equal ? "YES" : "NO") << endl;
        }
    }
    return 0;
}
