// coded by Cocane

#include<bits/stdc++.h>

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define out(ans) cout << ans << endl
#define yn(a) cout << (a ? "YES" : "NO") << endl

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
        int n, k;
        cin >> n >> k;

        vi v(n);
        for(auto &it : v) cin >> it;

        // sort(all(v));

        int mx_sweet = 0;
        int ct = 0;

        for (int i = 0; i < n; i++) {
            if(mx_sweet + v[i] > k) {
                break; 
            }
            mx_sweet += v[i];  
            ct++;  
        }
        
        cout << ct << endl;  
    }
    
    return 0;
}
