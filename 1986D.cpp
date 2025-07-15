#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

void connectedVertex(int **arr, int n) {
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (arr[i][j]) adj[i].push_back(j);

    vector<bool> visited(n), ap(n);
    vector<int> disc(n), low(n), parent(n, -1);
    int t = 0;
    function<void(int)> dfs = [&](int u) {
        visited[u] = true;
        disc[u] = low[u] = ++t;
        int children = 0;
        for (int v : adj[u]) {
            if (!visited[v]) {
                children++;
                parent[v] = u;
                dfs(v);
                low[u] = min(low[u], low[v]);
                if (parent[u] == -1 && children > 1) ap[u] = true;
                if (parent[u] != -1 && low[v] >= disc[u]) ap[u] = true;
            } else if (v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }
        }
    };
    for (int i = 0; i < n; i++)
        if (!visited[i]) dfs(i);

    vector<bool> isB(n);
    for (int u = 0; u < n; u++)
        if (ap[u])
            for (int v : adj[u])
                if (!ap[v])
                    isB[v] = true;

    vector<int> res;
    for (int i = 0; i < n; i++)
        if (isB[i])
            res.push_back(i);
    sort(res.begin(), res.end());

    for (int i = 0; i < (int)res.size(); i++) {
        if (i) cout << ' ';
        cout << res[i];
    }
    cout << '\n';
}

int main() {
    int n;
    cin >> n;
    int **arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    connectedVertex(arr, n);
    return 0;
}
