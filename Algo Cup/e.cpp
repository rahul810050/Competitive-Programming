// coded by Cocane

#include <bits/stdc++.h>

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define foru(i, n) for(int i = n-1; i >= 0; i--)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define allp(x) (x).begin(), (x).begin() + (x).size()/2, (x).rbegin()
#define pb push_back
#define ppb pop_back
#define read(a) for(auto &i: a) cin >> i
#define out(ans) cout << ans << endl
#define yn(a) cout << (a ? "YES": "NO") << endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef double dl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y, Z, A, B;
    cin >> X >> Y >> Z >> A >> B;
    vector<int> Map[A + 1];

    for (int j = 0; j < B; j++) {
        int p, q;
        cin >> p >> q;
        Map[p].pb(q);
        Map[q].pb(p);
    }

    vector<int> distance1(A + 1, INT_MAX);
    vector<int> distance2(A + 1, INT_MAX);
    vector<int> distanceA(A + 1, INT_MAX);
    queue<int> pQueue;

    pQueue.push(1);
    distance1[1] = 0;
    while (!pQueue.empty()) {
        int current = pQueue.front();
        pQueue.pop();
        for (auto neighbor : Map[current]) {
            if (distance1[neighbor] == INT_MAX) {
                distance1[neighbor] = distance1[current] + 1;
                pQueue.push(neighbor);
            }
        }
    }

    pQueue.push(2);
    distance2[2] = 0;
    while (!pQueue.empty()) {
        int current = pQueue.front();
        pQueue.pop();
        for (auto neighbor : Map[current]) {
            if (distance2[neighbor] == INT_MAX) {
                distance2[neighbor] = distance2[current] + 1;
                pQueue.push(neighbor);
            }
        }
    }

    pQueue.push(A);
    distanceA[A] = 0;
    while (!pQueue.empty()) {
        int current = pQueue.front();
        pQueue.pop();
        for (auto neighbor : Map[current]) {
            if (distanceA[neighbor] == INT_MAX) {
                distanceA[neighbor] = distanceA[current] + 1;
                pQueue.push(neighbor);
            }
        }
    }

    int result = 1e18;
    for (int j = 1; j <= A; ++j) {
        result = min(result, distance1[j] * X + distance2[j] * Y + distanceA[j] * Z);
    }
    cout << result << "\n";
    return 0;
}
