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
#define out(ans) cout << ans << endl
#define yn(a) cout << (a ? "YES": "NO") << endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n;
        ll u, d;
        cin >> n >> u >> d;
        vll hills(n);
        
        // Input each hill height
        for(auto &it : hills) cin >> it;

        int countIndex = 1; // Counter for the number of hills climbed
        bool parachuteUsed = false; // Track if parachute has been used

        for (int i = 0; i < n - 1; i++) {
            if (hills[i] <= hills[i + 1]) { // Climbing up or level
                ll height = hills[i + 1] - hills[i];
                if (height <= u) {
                    countIndex++;
                } else {
                    break;
                }
            } else { // Descending
                ll height = hills[i] - hills[i + 1];
                if (height <= d) {
                    countIndex++;
                } else if (!parachuteUsed) { // Use parachute if needed
                    countIndex++;
                    parachuteUsed = true;
                } else {
                    break;
                }
            }
        }

        cout << countIndex << endl;
    }
    return 0;
}
