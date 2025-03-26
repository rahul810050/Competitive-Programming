// coded by Cocane

#include <bits/stdc++.h>

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define foru(i, n) for (int i = n - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define read(a) for (auto &i : a) cin >> i
#define out(ans) cout << ans << endl
#define yn(a) cout << (a ? "YES" : "NO") << endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

int substract(int a, int b) {
    return max(a - b, 0);
}

int fMin(int a, int b) {
    return min(a, b);
}

int find3(int a, int b, int c) {
    return min({a, b, c});
}

int ctone(const string &str) {
    return count(all(str), '1');
}

int comSwa(int A1s, int B1s, int C1s, int len) {
    if (A1s == 0 || A1s == len) {
        if (B1s == 0 || B1s == len) {
            return (C1s == 0 || C1s == len) ? 0 : -1;
        }
        return (C1s == 0 || C1s == len) ? -1 : ((B1s + C1s == len) ? fMin(B1s, C1s) : -1);
    }
    if (B1s == 0 || B1s == len) {
        return (C1s == 0 || C1s == len) ? -1 : ((A1s + C1s == len) ? fMin(A1s, C1s) : -1);
    }
    if (C1s == 0 || C1s == len) {
        return (A1s + B1s == len) ? fMin(A1s, B1s) : -1;
    }
    if ((A1s + B1s + C1s) == 2 * len) {
        return find3(A1s, B1s, C1s);
    }
    return ((A1s + B1s + C1s) == len) ? find3(len - A1s, len - B1s, len - C1s) : -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string a, b, c;
        cin >> a >> b >> c;

        int A1s = ctone(a);
        int B1s = ctone(b);
        int C1s = ctone(c);

        out(comSwa(A1s, B1s, C1s, n));
    }
    return 0;
}
