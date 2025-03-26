// coded by Cocane

#include<bits/stdc++.h>

// #define ll long long
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

// typedef vector<int> vi;
// typedef vector<ll> vll;
typedef double dl;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL);
typedef vector<int> vi;
typedef long long ll;

void readGrid(int rows, int cols, vi &matrix) {
    for (int i = 0; i < rows * cols; i++) {
        cin >> matrix[i];
    }
}

int computeMoves(int rows, int cols, vi &matrix) {
    int totalCells = rows * cols;
    vi cc(totalCells + 1, 0);
    vector<bool> exst(totalCells + 1, false);

    for (int i = 0; i < totalCells; i++) {
        int color = matrix[i];
        if (!exst[color]) {
            exst[color] = true;
            cc[color] = 1; 
        }
    }

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int index = r * cols + c;
            int color = matrix[index];

            if (c + 1 < cols && matrix[index + 1] == color) {
                cc[color] = 2;
            }

            if (r + 1 < rows && matrix[index + cols] == color) {
                cc[color] = 2;
            }
        }
    }

    ll tc = 0;
    int maxCost = 0;
    for (int color = 1; color <= totalCells; color++) {
        if (exst[color]) {
            tc += cc[color];
            maxCost = max(maxCost, cc[color]);
        }
    }

    return tc - maxCost;
}

int main() {
    FAST_IO;
    int t;
    cin >> t;

    while (t--) {
        int rows, cols;
        cin >> rows >> cols;
        vi matrix(rows * cols);
        readGrid(rows, cols, matrix);
        cout << computeMoves(rows, cols, matrix) << endl;
    }

    return 0;
}