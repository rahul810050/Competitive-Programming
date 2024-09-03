#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        vector<pair<int, int>> players(16);
        for (int i = 0; i < 16; ++i) {
            cin >> players[i].first;
            players[i].second = i;
        }

        sort(players.begin(), players.end());

        vector<int> results(16);

        for (int i = 0; i < 16; ++i) {
            int matches_won = 0;
            for (int j = i + 1; j < 16; j *= 2) {
                matches_won++;
            }
            results[players[i].second] = matches_won;
        }

        // Output the results
        for (int i = 0; i < 16; ++i) {
            cout << results[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
