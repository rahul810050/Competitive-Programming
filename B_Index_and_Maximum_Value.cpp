// coded by Cocane

#include<bits/stdc++.h>

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define foru(i, n) for(int i = n-1; i >= 0; i--)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define out(ans) cout<<ans<<endl

using namespace std;

typedef vector<ll> vll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;

        vll v(n);
        forn(i, n) cin >> v[i];

        ll curr_mx = *max_element(all(v));  

        vll mx;  

        while (m--) {
            char c;
            ll l, r;
            cin >> c >> l >> r;

            if (c == '+') {
                if (curr_mx >= l && curr_mx <= r) {
                    curr_mx++;  
                }
                mx.pb(curr_mx);  
            } 
            else {  
                if (curr_mx >= l && curr_mx <= r) {
                    curr_mx--; 
                }
                mx.pb(curr_mx);  
            }
        }

        for(auto &it : mx)  cout << it << " ";  
        cout << endl;
    }

    return 0;
}
