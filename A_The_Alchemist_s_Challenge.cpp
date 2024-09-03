// coded by cocane

#include<bits/stdc++.h>

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define foru(i, n) for(int i = n-1; i >= 0; i--)
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        ll n, x, y; 
        cin >> n >> x >> y;

        vll v(n);
        forn(i, n) cin >> v[i];

        ll opp = 0;

        while (*max_element(all(v)) > 0) { 
            ll maxIndex = max_element(all(v)) - v.begin(); 

            if (v[maxIndex] - y >= 0) {
                v[maxIndex] -= y;
                opp++;
            } else {
                ll reduction = v[maxIndex];
                v[maxIndex] = 0;
                opp += (reduction + y - 1) / y;
            }

            forn(i, n) {
                if (v[i] > 0) {
                    v[i] -= x;
                    if (v[i] < 0) v[i] = 0;
                }
            }
        }

        cout << opp << endl;
    }
    return 0;
}