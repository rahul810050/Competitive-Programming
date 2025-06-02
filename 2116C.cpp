// coded by Cocane

#include<bits/stdc++.h>

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define foru(i, n) for(int i = n - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define read(a) for(auto &i : a) cin >> i
#define out(ans) cout << ans << "\n"
#define INF 100000000

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef queue<int> que;
typedef double dl;

int getGCD(int x, int y) {
    while (y) {
        int t = x % y;
        x = y;
        y = t;
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi a(n);
        read(a);
        int G = a[0];
        forn(i, n) G = getGCD(G, a[i]);
        int ctG = 0;
        forn(i, n) if (a[i] == G) ctG++;
        if (ctG > 0) {
            out(n - ctG);
            continue;
        }
        vi uni;
        vb alreadySeen(5001, false);
        forn(i, n) {
            if (!alreadySeen[a[i]]) {
                alreadySeen[a[i]] = true;
                uni.pb(a[i]);
            }
        }
        vi vv(5001, INF);
        que q;
        for (int v : uni) {
            vv[v] = 0;
            q.push(v);
        }
        int mnStp = INF;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            if (v == G) {
                mnStp = vv[v];
                break;
            }
            for (int u : uni) {
                int nx = getGCD(v, u);
                if (vv[nx] > vv[v] + 1) {
                    vv[nx] = vv[v] + 1;
                    q.push(nx);
                }
            }
        }
        out(mnStp + (n - 1));
    }
    return 0;
}
