#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
static const int E = 50000;

struct Edge {
    int w, u, v;
    bool operator<(Edge const &o) const { return w > o.w; }
};

struct CmpMin {
    bool operator()(Edge const &a, Edge const &b) const {
        return a.w > b.w;
    }
};

long long total;
int N, K;
int arr[MAXN][MAXN];
vector<Edge> edges;
vector<long long> prefix;
vector<char> used;
long long best_cov;

void dfs(int idx, int placed, long long cov) {
    if (placed == K) {
        best_cov = max(best_cov, cov);
        return;
    }
    int rem = K - placed;
    if (idx + rem > (int)edges.size()) return;
    long long bound = cov + (prefix[idx + rem - 1] - (idx ? prefix[idx - 1] : 0LL));
    if (bound <= best_cov) return;
    auto &e = edges[idx];
    if (!used[e.u] && !used[e.v]) {
        used[e.u] = used[e.v] = 1;
        dfs(idx + 1, placed + 1, cov + e.w);
        used[e.u] = used[e.v] = 0;
    }
    dfs(idx + 1, placed, cov);
}

void sumOfVisibleCells(int n, int k, int a[][MAXN]) {
    N = n; K = k;
    total = 0;
    priority_queue<Edge, vector<Edge>, CmpMin> pq;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            total += a[i][j];
            int id = i * N + j;
            if (j + 1 < N) {
                Edge e{a[i][j] + a[i][j + 1], id, id + 1};
                if ((int)pq.size() < E) pq.push(e);
                else if (e.w > pq.top().w) {
                    pq.pop();
                    pq.push(e);
                }
            }
            if (i + 1 < N) {
                Edge e{a[i][j] + a[i + 1][j], id, id + N};
                if ((int)pq.size() < E) pq.push(e);
                else if (e.w > pq.top().w) {
                    pq.pop();
                    pq.push(e);
                }
            }
        }
    }
    edges.reserve(pq.size());
    while (!pq.empty()) {
        edges.push_back(pq.top());
        pq.pop();
    }
    sort(edges.begin(), edges.end());
    prefix.resize(edges.size());
    for (int i = 0; i < (int)edges.size(); i++) {
        prefix[i] = edges[i].w + (i ? prefix[i - 1] : 0LL);
    }
    used.assign(N * N, 0);
    best_cov = 0;
    dfs(0, 0, 0LL);
    cout << (total - best_cov);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    sumOfVisibleCells(n, k, arr);
    return 0;
}
