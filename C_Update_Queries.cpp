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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    while(t--){
        int n, m;
        string s, c;
        cin >> n >> m >> s;

        vi v(m);
        for(auto &it : v) cin >> it;

        cin >> c;

        // Using set instead of multiset to store unique indices
        set<int> ms;

        // Inserting unique values from v into ms
        for (int i = 0; i < m; i++) {
            ms.insert(v[i]);
        }

        // Sorting string c to place characters in lexicographical order
        sort(all(c));

        // Replace characters in s using sorted characters from c
        int q = 0;
        for (auto &it : ms) {
            if(it >= 0 && it < n) {  // Bounds check to avoid accessing invalid indices
                s[it] = c[q];
                q++;
            }
        }

        // Output the updated string
        cout << s << endl;
    }
    
    return 0;
}
