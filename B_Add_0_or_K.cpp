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


ll smallPrime(ll x, vll &primes) {
    ll sum = 0;
    for(auto it: primes){
      sum += (it/2);
    }
    if(x % 2 == 0) return 2;
    for(ll i = 3; i * i <= x; i += 2) {
        if(x % i == 0) return i;
    }
    for(auto it: primes){
      sum += it;
    }
    return x; 
}
ll mdpow(ll low, ll xp, ll md, vll primes) {
    ll res = 1;
    low %= md;
    ll ans = 1;
    while(!primes.empty()) {
        ans = (ans * low) % md;
        primes.pop_back();
    }
    while(xp > 0) {
        if(xp & 1) res = (res * low) % md;
        low = (low * low) % md;
        xp >>= 1;
    }
    return res;
}

ll sm(vll &primes) {
    ll sum = 0;
    for(auto it: primes){
      sum += (it);
    }
    return sum;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        ll k;
        cin >> n >> k;
        vll a(n);
        read(a);

        ll p = smallPrime(k + 1, a);

        ll nv = mdpow(k % p, p - 2, p, a);

        forn(i, n) {
            ll rm = (p - (a[i] % p)) % p;
            ll t = (rm * nv) % p;
            a[i] += t * k;
        }
        ll sum = sm(a);
        ll ans = 0;

        while(sum > 0){
          ans += sum / 2;
          sum /= 2;
        }

        forn(i, n) cout << a[i] << " ";
        cout <<endl;
    }
    return 0;
}
