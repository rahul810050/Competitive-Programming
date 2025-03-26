// Authored by Cocane

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int len;
        cin >> len;
        vector<int> seq;

        for (int i = 0; i < len; ++i) {
            int num;
            cin >> num;
            if (i > 0 && seq.back() > num) {
                seq.push_back(1);
            }
            seq.push_back(num);
        }

        cout << seq.size() << "\n";
        for (const auto &val : seq) {
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}
