// coded by Cocane

#include <bits/stdc++.h>

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define foru(i, n) for (int i = n - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define allp(x) (x).begin(), (x).begin() + (x).size() / 2, (x).rbegin()
#define pb push_back
#define ppb pop_back
#define read(a)       \
    for (auto &i : a) \
    cin >> i
#define out(ans) cout << ans << endl
#define yn(a) cout << (a ? "YES" : "NO") << endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

const int mod = 1e9 + 7;

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int divi(int a, int b) { return a / b; }

int bs(vi &arr, int key)
{
    int l = 0, r = arr.size() - 1;
    while (l <= r)
    {
        int mid = divi(add(l, r), 2);
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            l = add(mid, 1);
        else
            r = sub(mid, 1);
    }
    return -1;
}

bool func(int x)
{
    return (x & 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi a(n);
        read(a);

        int dd = bs(a, 1e9 + 1);

        int l = 1;
        int i = 1;
        while (i < n)
        {
            if (a[i] % a[sub(i, 1)] != 0)
            {
                int pp = __gcd(a[i], a[sub(i, 1)]);
                int stor = divi(a[sub(i, 1)], pp);
                int gc = __gcd(stor, l);
                l = mul(divi(l, gc), stor);
            }
            i = add(i, 1);
        }

        out(l);
    }
    return 0;
}
