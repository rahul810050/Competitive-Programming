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

vector<int> find_divisors(ll num, ll digit) {
    vector<int> result;

    result.push_back(1);

    if (num >= 3 || digit % 3 == 0) {
        result.push_back(3);
    }
    if (digit == 5) {
        result.push_back(5);
    }
    if (num >= 3 || (num == 2 && digit == 7)) {
        result.push_back(7);
    }
    if (num >= 6) {
        result.push_back(9);
    } else {
        long long factorial = 1;
        int i = 2;
        while (i <= num) {
            factorial *= i;
            i++;
        }

        if ((factorial * digit) % 9 == 0) {
            result.push_back(9);
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        ll n, d;
        cin >> n >> d;

        vector<int> divisors = find_divisors(n, d);

        for (auto &divisor : divisors) {
            cout << divisor << " ";
        }
        cout << endl;
    }

    return 0;
}
