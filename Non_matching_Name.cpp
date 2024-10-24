// coded by Cocane

#include<bits/stdc++.h>

#define ll long long
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        string a, b;
        cin >> a >> b;

        int hsh[26] = {0};

        for (int i = 0; i < n; i++) {
            hsh[a[i] - 'a']++;
        }
        for (int i = 0; i < m; i++) {
            hsh[b[i] - 'a']++;
        }

        bool ct = false;
        for (int i = 0; i < 26; i++) {
            if (hsh[i] > 1) { 
                ct = true;
                break;
            }
        }

        yn(ct);
    }

    return 0;
}
