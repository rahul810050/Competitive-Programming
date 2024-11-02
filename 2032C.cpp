#include <bits/stdc++.h>
using namespace std;

#define CODE ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define foru(i, n) for(int i = n - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ppb pop_back
#define read(a) for(auto &i: a) cin >> i
#define out(answer) cout << answer << endl
#define yn(a) cout << (a ? "YES" : "NO") << endl

using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef double dl;

signed main() {
    CODE
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi v(n);
        read(v); 
        
        sort(all(v)); 
        int answer = n;  
        int l = 1;    
        int r = n;   
        
        while (l <= r) {
            int mid = (l + r) / 2;
            bool val = false;  
            
            for (int i = 0; i + mid - 1 < n; i++) {
                if (v[i] + v[i + 1] > v[i + mid - 1]) {
                    val = true;
                    break;
                }
            }
            
            if (val) {
                answer = min(answer, n - mid);
                l = mid + 1; 
            } else {
                r = mid - 1; 
            }
        }
        
        out(answer); 
    }
    return 0;
}
