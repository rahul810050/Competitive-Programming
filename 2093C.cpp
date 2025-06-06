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
#define out(ans) cout<<ans<<endl
#define yn(a) cout<< (a ? "YES": "NO") <<endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

bool isPrime(int x) {
        if (x <= 1) return false;
        for (int i = 2; i * i <= x; i++) {
                if (x % i == 0) return false;
        }
        return true;
}


int main(){
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int t;
        cin >> t;
        while(t--){
					int x, k;
					cin >> x >> k;
					if (k > 1 && x > 1) out("NO");
					else if (k == 1) yn(isPrime(x));
					else yn(k == 2);
        }
        return 0;
}
