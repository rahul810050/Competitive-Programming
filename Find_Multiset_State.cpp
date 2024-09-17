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
        int n, k;
        cin >> n >> k;
        
        multiset<int> ms;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            ms.insert(x);
        }

        for (int i = 0; i < k; i++) {
            auto min_it = ms.begin();
            auto max_it = prev(ms.end());

            int mn = *min_it;
            int mx = *max_it;

            ms.erase(min_it);
            ms.erase(max_it);

            ms.insert(mn + mx);
        }

        for (auto it : ms) {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}
