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
        int n, f, k; 
        cin >> n >> f >> k;

        f--; 
        k--;

        vi v(n);

        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int fthNum = v[f];  

        sort(all(v), greater<int>());  

        int count_fthNum = count(all(v), fthNum);
        int first_fthNum = find(all(v), fthNum) - v.begin();
        int last_fthNum = first_fthNum + count_fthNum - 1;

        if (k < first_fthNum) {
            cout << "NO" << endl;
        } else if (k > last_fthNum) {
            cout << "YES" << endl;
        } else {
            if (count_fthNum > 1 && k != last_fthNum) {
                cout << "MAYBE" << endl;
            } else {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}
