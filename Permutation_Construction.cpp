#include <iostream>
#include <vector>

using namespace std;

void solve(int N) {
    vector<int> permutation;
    if (N == 2) {
        permutation = {1, 2};
    } else {
        permutation.push_back(1);
        for (int i = 2; i <= N; ++i) {
            if (i % 2 == 0) {
                permutation.insert(permutation.begin() + 1, i);
            } else {
                permutation.push_back(i);
            }
        }
    }
    
    for (int num : permutation) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        solve(N);
    }

    return 0;
}
