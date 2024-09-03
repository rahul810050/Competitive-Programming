#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define maxInteger 1e9

void bfs(int start, const vector<vector<int>>& adj, vector<int>& dis) {
    queue<int> q;
    q.push(start);
    dis[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dis[v] == maxInteger) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int N, Q;
        cin >> N >> Q;

        vi A(N + 1);
        for (int i = 1; i <= N; ++i) {
            cin >> A[i];
        }

        vector<vi> adj(N + 1);
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= A[i] && i + j <= N; ++j) {
                adj[i].push_back(i + j);
            }
        }

        vector<vi> distances(N + 1, vi(N + 1, maxInteger));
        for (int i = 1; i <= N; ++i) {
            bfs(i, adj, distances[i]);
        }

        while (Q--) {
            int X, Y;
            cin >> X >> Y;
            if (distances[X][Y] == maxInteger) {
                cout << -1 << '\n';
            } else {
                cout << distances[X][Y] << '\n';
            }
        }
    }
    return 0;
}
