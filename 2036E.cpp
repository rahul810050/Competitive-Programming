#include <bits/stdc++.h>
using namespace std;

void process() {
    int t_row, to_col, q;
    cin >> t_row >> to_col >> q;
    
    vector<vector<int>> val(to_col + 1, vector<int>(1));

    for (int i = 1; i <= t_row; i++) {
        for (int j = 1; j <= to_col; j++) {
            int temp;
            cin >> temp;
            temp = temp | val[j].back();
            val[j].push_back(temp);
        }
    }

    while (q--) {
        int cndtion;
        cin >> cndtion;

        vector<pair<int, int>> lc, g_con;

        while (cndtion--) {
            char compa;
            int r_index, c_val;
            cin >> r_index >> compa >> c_val;

            if (compa == '<') 
                lc.push_back(make_pair(r_index, c_val));
            else 
                g_con.push_back(make_pair(r_index, c_val));
        }

        int curr = 1;

        for (size_t i = 0; i < g_con.size(); i++) {
            int r_index = g_con[i].first;
            int c_val = g_con[i].second;

            auto it = upper_bound(val[r_index].begin(), val[r_index].end(), c_val);
            curr = max(curr, int(it - val[r_index].begin()));
        }

        if (curr > t_row) {
            cout << -1 << endl;
            continue;
        }

        bool cFail = false;

        for (size_t i = 0; i < lc.size(); i++) {
            int r_index = lc[i].first;
            int c_val = lc[i].second;

            if (val[r_index][curr] >= c_val) 
                cFail = true;
        }

        cout << (cFail ? -1 : curr) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--)
        process();

    return 0;
}
