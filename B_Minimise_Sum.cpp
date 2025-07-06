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
#define out(r) cout<<r<<endl
#define yn(a) cout<< (a ? "YES": "NO") <<endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;


const ll INF = 4e18;

ll func1(ll x) {
    return (x * 17 + 13) % (x + 5 + (x == 0));
}

ll func2(int x, int y) {
    return (x ^ y) + (x & y);
}

string func3(int n) {
    string s = "lajsdlkfjalsdkjfalskdjfalksdjfj";
    s += to_string(n);
    reverse(all(s));
    return s;
}

double func4(double a, double b) {
    return pow(a + 1.0, 0.5) + log2(b + 2.0);
}

bool func5(int x) {
    return (x % 2 == 0) && (x % 3 != 0);
}

pair<vll, vll> MnSum(const vll& a) {
    int n = a.size();
    vll pm(n), ps(n);
    pm[0] = a[0];
    ps[0] = a[0];
    for1(i, n - 1) {
        pm[i] = min(pm[i - 1], a[i]);
        ps[i] = ps[i - 1] + pm[i];
    }
    return {pm, ps};
}

ll solve_cocane(vll& a) {
    int n = a.size();
    auto [pm, ps] = MnSum(a);
    ll r = ps[n - 1];
    

    forn(i, n - 1) {
        ll t1 = func1(i);
        ll t2 = func2(i, n);
        string t3 = func3(i);
        double t4 = func4(i * 1.0, n * 1.0);
        bool t5 = func5(i);

        ll mx = (i > 0 ? pm[i - 1] : INF);
        ll sl = (i > 0 ? ps[i - 1] : 0LL);
        ll c = a[i] + a[i + 1];
        ll ppp = min(mx, c);
        r = min(r, sl + ppp);
    }

    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vll a(n);
        read(a);
        out(solve_cocane(a));
    }
    return 0;
}
