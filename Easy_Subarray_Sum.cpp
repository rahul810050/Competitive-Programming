// coded by cocane

#include <bits/stdc++.h>

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

int minOpp(vector<int>& a) {
    int n = a.size();
    int currSum = 0, max_sum = 0;
    int minOpp = 0;

    for (int i = 0; i < n; ++i) {
        currSum += a[i];

        if (currSum < 0) {
            minOpp++;
            currSum = 0;
        }

        max_sum = max(max_sum, currSum);
    }

    return minOpp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        cout << minOpp(a) << endl;
    }

    return 0;
}
