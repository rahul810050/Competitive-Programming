// coded by cocane

#include <bits/stdc++.h>

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define foru(i, n) for(int i = n-1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define out(ans) cout<<ans<<endl
#define yn(a) cout<< (a ? "YES": "NO") <<endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vi v(n);

        forn(i, n) cin >> v[i];

        unordered_map<int, int> hsh; 

        for (int i = 0; i < n; i++) {
            hsh[v[i]]++;
        }

        bool f = false;

        for (const auto& p : hsh) {
            if (p.second % 2 == 1) {
                f = true;
                break;
            }
        }

        cout << (f ? "YES" : "NO") << endl;
    }
    return 0;
}
