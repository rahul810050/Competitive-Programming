#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<vector<int>> a(n, vector<int>(m));

    // Input the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    vector<pair<int, int>> path;
    int r = 0, c = 0;
    path.push_back({r, c});

    // Parse the moves
    for (char move : s) {
        if (move == 'D') {
            r++;
        } else { // Assuming the only other move is 'R'
            c++;
        }
        path.push_back({r, c});
    }

    // Process the path and fix the matrix
    for (size_t k = 0; k < path.size(); ++k) {
        int r = path[k].first, c = path[k].second;

        if (k < path.size() - 1) {
            int next_r = path[k + 1].first, next_c = path[k + 1].second;

            if (next_r > r) { // Moving Down, fix the current row
                int row_sum = 0;
                for (int j = 0; j < m; ++j) {
                    row_sum += a[r][j];
                }
                a[r][c] = row_sum - a[r][c];
            } else { // Moving Right, fix the current column
                int col_sum = 0;
                for (int i = 0; i < n; ++i) {
                    col_sum += a[i][c];
                }
                a[r][c] = col_sum - a[r][c];
            }
        } else { // At the last position
            int col_sum = 0;
            for (int i = 0; i < n; ++i) {
                col_sum += a[i][c];
            }
            a[r][c] = col_sum - a[r][c];
        }
    }

    // Output the modified matrix
    for (const auto& row : a) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << "\n";
    }
}

int main() {
	long long t;
	cin>>t;
	while (t--)
	{
		solve();
	}
	
    
    return 0;
}
