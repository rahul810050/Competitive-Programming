// coded by Cocane

#include <bits/stdc++.h>

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define foru(i, n) for(int i = n-1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ppb pop_back
#define read(a) for(auto &i : a) cin >> i
#define out(ans) cout << ans << endl
#define yn(a) cout << (a ? "YES" : "NO") << endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

map<ll, bool> visit;
map<ll, vector<ll>> eleM;
ll ele;
ll mxLen = 0;

void dfs(ll curLen) {
    visit[curLen] = true;
    mxLen = max(mxLen, curLen);

    for (auto val : eleM[curLen - ele]) {
        if (!visit[curLen + val - 1]) {
            dfs(curLen + val - 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        cin >> ele;
        mxLen = 0;

        for1(i, ele) {
            ll iVal;
            cin >> iVal;
            iVal -= (ele - i + 1);

            if (i > 1) {
                eleM[iVal].pb(i);
            }
        }

        dfs(ele);
        out(mxLen);

        eleM.clear();
        visit.clear();
    }

    return 0;
}
