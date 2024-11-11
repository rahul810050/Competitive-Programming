// Optimized by Cocane

#include <bits/stdc++.h>

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define yn(a) cout << (a ? "YES" : "NO") << endl

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        string s;
        cin >> n >> a >> b >> s;

        int x = 0, y = 0;
        set<pair<int, int>> visited_positions;
        bool found = false;

        for (int i = 0; i < n * n; i++) { // n * n bounds for cycle detection in 10x10 grid
            if (x == a && y == b) {
                found = true;
                break;
            }

            visited_positions.insert({x, y});

            // Move Alice according to the direction in the sequence
            char move = s[i % n];
            if (move == 'N') y++;
            else if (move == 'E') x++;
            else if (move == 'S') y--;
            else if (move == 'W') x--;

            // Check if Alice is revisiting a position without meeting the target
            if (visited_positions.count({x, y}) && (x != a || y != b)) {
                break; // Alice is stuck in a cycle without reaching (a, b)
            }
        }

        yn(found);
    }
    return 0;
}
