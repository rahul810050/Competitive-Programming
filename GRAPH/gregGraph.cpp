#include <bits/stdc++.h>
using namespace std;
const int N = 510; // safe upper bound

long long dist[N][N];

int main() {
    int n; 
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    vector<int> del_vec(n);
    for (int i = 0; i < n; i++) {
        cin >> del_vec[i];
        del_vec[i]--; // shift to 0-based
    }
    reverse(del_vec.begin(), del_vec.end());

    vector<long long> ans;
    vector<bool> added(n, false);

    for (int k = 0; k < n; k++) {
        int vk = del_vec[k];
        added[vk] = true;

        // Floyd update considering vk
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][vk] + dist[vk][j]);
            }
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (!added[i]) continue;
            for (int j = 0; j < n; j++) {
                if (!added[j]) continue;
                sum += dist[i][j];
            }
        }
        ans.push_back(sum);
    }

    reverse(ans.begin(), ans.end());
    for (auto x : ans) cout << x << " ";
    cout << "\n";
}
