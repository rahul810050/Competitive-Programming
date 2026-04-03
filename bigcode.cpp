#include <bits/stdc++.h>
using namespace std;

long long solve(int n, int m, vector<int> &a, vector<int> &b, vector<long long> &lim, vector<long long> &rat) {
    vector<vector<pair<int, long long>>> add(m);
    for (int i = 0; i < n; i++) {
        add[a[i]].push_back({b[i], lim[i]});
    }

    priority_queue<pair<int, long long>> pq;
    vector<long long> end_add(m + 1, 0);

    long long cur = 0;
    long long ans = 0;

    for (int i = 0; i < m; i++) {
        cur -= end_add[i];

        for (auto p : add[i]) {
            pq.push(p);
        }

        while (!pq.empty() && pq.top().first < i) {
            pq.pop();
        }

        if (cur < rat[i]) {
            long long need = rat[i] - cur;

            while (need > 0) {
                while (!pq.empty() && pq.top().first < i) {
                    pq.pop();
                }

                if (pq.empty()) {
                    return -1;
                }

                auto top = pq.top();
                pq.pop();

                int r = top.first;
                long long cnt = top.second;
                long long take = min(need, cnt);

                need -= take;
                cur += take;
                ans += take;

                if (r + 1 <= m) {
                    end_add[r + 1] += take;
                }

                cnt -= take;
                if (cnt > 0) {
                    pq.push({r, cnt});
                }
            }
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;
    cin >> m;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    vector<long long> lim(n), rat(m);
    for (int i = 0; i < n; i++) {
        cin >> lim[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> rat[i];
    }

    cout << solve(n, m, a, b, lim, rat) << '\n';
    return 0;
}
