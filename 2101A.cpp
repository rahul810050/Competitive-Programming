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

void spiral(int n) {
    vector<vi> arr(n, vi(n, -1));

    int x, y;
    if (n % 2 == 0) x = y = n / 2 - 1;
    else x = y = n / 2;

    arr[x][y] = 0;
    int val = 1, step = 1;

    vector<pair<int, int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    while (val < n * n) {
        forn(d, 4) {
            int steps = step;
            if (d % 2) step++;

            int dx = dir[d].fi, dy = dir[d].se;
            forn(i, steps) {
                x += dx, y += dy;

                if (x >= 0 && x < n && y >= 0 && y < n && arr[x][y] == -1) {
                    arr[x][y] = val++;
                }
                if (val >= n * n) break;
            }
            if (val >= n * n) break;
        }
    }

    forn(i, n) {
        forn(j, n) cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        spiral(n);
    }

    return 0;
}
