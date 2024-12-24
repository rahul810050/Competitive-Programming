#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int segmentCount = 0;
        bool foundNonZero = false;

        for (int i = 0; i < n; i++) {
            if (arr[i] != 0 && !foundNonZero) {
                segmentCount++;
                foundNonZero = true;
            } else if (arr[i] == 0) {
                foundNonZero = false;
            }
        }

        cout << min(segmentCount, 2) << endl;
    }

    return 0;
}
